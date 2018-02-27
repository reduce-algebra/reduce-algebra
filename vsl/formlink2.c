/*
Copyright (C) Mikhail Tentyukov.
This file is part of FORMLINK interface to the Symbolic Manipulation
System FORM (http://www.nikhef.nl/~form).
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions of modified source code should refer to its origin as
   follows: "This code is based on the source code of FORMLINK interface to
   the Symbolic Manipulation System FORM".
3. Provided this code was used in any form in scientific work that
   leads to publication in a scientific journal, this work should refer
   to the paper M. Tentyukov and J.A.M.Vermaseren "Extension of the
   functionality of the symbolic program FORM by external software",
   cs.SC/0604052
THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY; WITHOUT EVEN
THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
PURPOSE.
*/

/*
  This is the FORMLINK interface which can be used for embedding FORM
  in other applications, see http://www.arxiv.org/abs/cs.SC/0604052
  Appendix D. There are two public functions available, the low-level
  function flnk_do_runcmd() and the high-level (and restricted)
  function flnk_runcmd(), see comments below. The functions return PID
  (Process IDentifier) of  a program starting FORM, or an error code <0.
  In the latter case the error code may be checked by means of the
  macro FLNK_ISERR, see comments in the file flnk_startform.h.

  To compile this module, use the command
  cc -c flnk_startform.c
  this produces the object file flnk_startform.o which can be used
  in order to link programs which uses flnk_runcmd() and
  flnk_do_runcmd() (do not forget to #include "flnk_startform.h" in
  such programs).

  At the end of this file there is the demo program. In order to compile
  it, the macro DEMO_CALC should be defined, see comments below (just
  after the line #ifdef DEMO_CALC).
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

#include "flnk_startform.h"
#include "psl.h"

/*First argument for the function signal:*/
#ifndef INTSIGHANDLER
typedef void (*mysighandler_t)(int);
#else
/* Sometimes, this nonsense may occurs:*/
/*typedef int (*mysighandler_t)(int);*/
#endif

typedef int FLNK_APIPE[2];

/*
 This function converts the second argument (n) into the string representation,
 and returns the pointer to the end of the string str with _added_ string:
*/
static char *addInt2str(char *str, long int n)
{   char buf[21];
    char *c=buf;
    int i;
    buf[0]='\0';
    do
    {   *c++ = '0' + n % 10;
        n /= 10;
    }
    while (n);
    for (i=c-buf-1; !(i<0); i--)*str++=buf[i];
    return str;
}/*addInt2str*/

/*
The default behaviuor of syscalls under non-blocked signals is
changed time to time and depends on the UNIX flavour. Try here to
make some universal wrappers.
*/
/*Wrapper to the read() syscall, to handle possible
  interrupts by unblocked signals:*/
static ssize_t saferead(int fd, char *buf, size_t count)
{   ssize_t res;

    if ( (res=read(fd,buf,count)) <1 )
        /*EOF or read is interrupted by a signal?:*/
        while ( (errno == EINTR)&&(res <1) )
            /*The call was interrupted by  a  signal
              before  any data was read, try again:*/
            res=read(fd,buf,count);
    return (res);
}/*saferead*/

/*Wrapper to the write() syscall, to handle possible
  interrupts by unblocked signals:*/
static ssize_t safewrite(int fd, char *buf, size_t count)
{   ssize_t res;
    /*Is write interrupted by a signal?:*/
    if ( (res=write(fd,buf,count)) <1 )
        while ( (errno == EINTR)&&(res <1) )
            /*The call was interrupted by a signal
              before any data were written, try again:*/
            res=write(fd,buf,count);
    return (res);
}/*safewrite*/

/* Read one (binary) PID from the file descriptor fd:*/
static pid_t readpid(int fd)
{   pid_t tmp;
    if (saferead(fd,(char*)&tmp,sizeof(pid_t))!=sizeof(pid_t))
        return (pid_t)-1;
    return tmp;
}/*readpid*/

/* Writeone (binary) PID to the file descriptor fd:*/
static pid_t writepid(int fd, pid_t thepid)
{   if (safewrite(fd,(char*)&thepid,sizeof(pid_t))!=sizeof(pid_t))
        return (pid_t)-1;
    return (pid_t)0;
}/*readpid*/

/* Adds the integer fd to the array fifo of length top+1 so that
the array is ascendantly ordered. It is supposed that all 0 -- top-1
elements in the array are already ordered:*/
static void pushDescriptor(int *fifo, int top, int fd)
{   int ins=top-1;
    if ( fifo[ins]<=fd )
        fifo[top]=fd;
    else
    {   /*Find the position:*/
        while ( (ins>=0)&&(fifo[ins]>fd) )ins--;
        /*Move all elements starting from the position to the right:*/
        for (ins++; top>ins; top--)
            fifo[top]=fifo[top-1];
        /*Put the element:*/
        fifo[ins]=fd;
    }
}/*pushDescriptor*/

/* Set the FD_CLOEXEC  flag of desc if value is nonzero,
 or clear the flag if value is 0.
 Return 0 on success, or -1 on error with errno  set. */
static int set_cloexec_flag (int desc, int value)
{   int oldflags = fcntl (desc, F_GETFD, 0);
    /* If reading the flags failed, return error indication now.*/
    if (oldflags < 0)
        return (oldflags);
    /* Set just the flag we want to set. */
    if (value != 0)
        oldflags |= FD_CLOEXEC;
    else
        oldflags &= ~FD_CLOEXEC;
    /* Store modified flag word in the descriptor. */
    return (fcntl(desc, F_SETFD, oldflags));
}/*set_cloexec_flag*/

/*CLose all descriptors greate or equal than startFrom except those
  listed in the ascendantly ordered array usedFd of length top:*/
static void closeAllDescriptors(int startFrom,int *usedFd, int top)
{   int n,maxfd;
    for (n=0; n<top; n++)
    {   maxfd=usedFd[n];
        for (; startFrom<maxfd; startFrom++) /*Close all less than maxfd*/
            close(startFrom);
        startFrom++;/*skip maxfd*/
    }/*for (;startFrom<maxfd;startFrom++)*/
    /*Close all the rest:*/
    maxfd=sysconf(_SC_OPEN_MAX);
    for (; startFrom<maxfd; startFrom++)
        close(startFrom);
}/*closeAllDescriptors*/

/*Closes both pipe descriptors if not -1:*/
static void closepipe(FLNK_APIPE *thepipe)
{   if ( (*thepipe)[0] != -1) close ((*thepipe)[0]);
    if ( (*thepipe)[1] != -1) close ((*thepipe)[1]);
}/*closepipe*/



/*The following function initializes opened channels.
Upon startup, FORM sends its PID in ASCII decimal format with an
appended newline character to the descriptor writable end of each the
channel descriptor and then FORM will wait for the answer from the
readable channel descriptor.  The answer must be two comma-separated
integers in ASCII decimal format followed by a newline character. The
first integer corresponds to the FORM PID while the second one is the
parent process PID.  If the answer is not obtained after some timeout,
or if it is not correct (i.e. it is not a list of two integers or the
first integer is not the FORM PID) then FORM fails.
  The function returns the FORM pid (which may differ from chldpid!)
of error code < 0.
*/
static INLINE
int initFrm(int nchannels, int *fdwrite, int *fdread, pid_t chldpid)
{   char chldpidtxt[22];/*FORM pid as ASCII decimal with trailing \n*/
    /*Comma-separated FORM pid and my pid as ASCII decimal with trailing \n:*/
    char bothpidtxt[45];
    int bothpidlen;/*The length of bothpidtxt*/
    fd_set rfds;
    struct timeval tv;
    int i,flags,nrep;
    pid_t formPID=0;
    long int fpid=(long int)chldpid,mypid= (long int)getpid();
    char buf[22];

    printf("%ld,%ld\n",fpid,mypid);

    sprintf(chldpidtxt,"%ld\n",fpid);
    sprintf(bothpidtxt,"%ld,%ld\n",fpid,mypid);

    bothpidlen=strlen(bothpidtxt);

    for (i=0; i<nchannels; i++)
    {   /*wait PID from FORM:*/
        /* Watch fdread[i] to see when it has input:*/
        nrep=5;/*only (5-1) interruptions from non-blocked signals*/
        do
        {   FD_ZERO(&rfds);
            FD_SET(fdread[i], &rfds);
            /* Wait up to timeout. */
            /*FLNK_TIMEOUT is in millisecs.*/
            tv.tv_sec = FLNK_TIMEOUT/1000;
            tv.tv_usec = (FLNK_TIMEOUT % 1000)*1000;
            nrep--;

            switch(select(fdread[i]+1, &rfds, NULL, NULL, &tv))
            {   case -1:
                    if ((nrep == 0)||( errno != EINTR) )
                    {   perror("select()");
                        return FLNK_INITERR;
                    }/*else -- A non blocked signal was caught, just repeat*/
                    break;
                case 0:/*timeout*/
                    return FLNK_INITTMERR;
                default:
                    /*read from FORM its PID:*/
                    nrep=saferead(fdread[i], buf, 21);
                    if ( (nrep<2)||(nrep>20)||(buf[nrep-1]!='\n') )
                        return FLNK_INITERR;

                    buf[nrep]='\0';
                    /*compare obtained PID with what we know:*/
                    if (strcmp(buf,chldpidtxt)!=0)
                    {   char *b;
                        /*The FORM PID is not necessarily coincide with
                          chldpid! Supposre, we start FORM from a script, of
                          inn a subshell...*/

                        /*Check the validity of the PID:*/
                        if (formPID != 0) /*There cannot be two different PIDs!*/
                            return FLNK_INITPIDERR;

                        fpid=strtol(buf, &b, 10);
                        if (
                            (fpid<2)||
                            (b==buf)||/*buf is not a number*/
                            (*b!='\n')||/*number is not terminated by \n*/
                            kill((pid_t)fpid,0)/*there is no such PID*/
                        )
                            return FLNK_INITERR;

                        /*And now reset FORM PID:*/
                        sprintf(chldpidtxt,"%ld\n",fpid);
                        sprintf(bothpidtxt,"%ld,%ld\n",fpid,mypid);
                        formPID=(pid_t)fpid;
                    }/*if (strcmp(buf,chldpidtxt)!=0)*/
                    nrep=0;

                    /*Send the reply (bothpidtxt):*/
                    /* make the descriptor non-blocking:*/
                    flags = fcntl(fdwrite[i], F_GETFL,0);/*First, save the original mode*/
                    /*Add O_NONBLOCK:*/
                    fcntl(fdwrite[i],F_SETFL, flags | O_NONBLOCK);
                    /*write bothpidtxt to fdwrite[i]*/
                    if (safewrite(fdwrite[i],bothpidtxt,bothpidlen)!=bothpidlen)
                        return FLNK_INITERR;
                    /*restore the flags:*/
                    fcntl(fdwrite[i],F_SETFL, flags);
            }/*switch*/
        }
        while (nrep);
    }/*for (i=0; i<nchannels;i++)*/

    if (formPID == 0)
        formPID=chldpid;

    return formPID;
}/*initFrm*/

/*
   The function creates "nchannels" communication channels and starts a command
   "cmd" providing it these channels.
   The function opens nchannels*2 pipes and executes a command "cmd" passing
   corresponding descriptors as a comma separated list of (r,w) pairs (in ASCII
   decimal format) via a command line argument replacing arg[nopt] by this list.
   arg[] is a NULL-terminated array of cmd arguments. The other ends of pipes
   are placed into arrays fdread and fdwrite so that for the channel # the main
   program reads from the descriptor fdread[#] and writs to the descriptor
   fdwrite[#]. Both arrays fdread and fdwrite must be allocated for nchannels
   integers. The argument arg[nopt] is just replaced by the list without
   any cleanup.
      Example:
       cmd="./form",argv={"form","-pipe",NULL,NULL},
       nopt=2,
       nchannels=2.
     The function creates nchannels*2=4 pipes.
     Lets us suppose the first pipe was created with the descriptors 5,6;
     the second pipe has the descriptors 7,8;
     the third pipe has the descriptors 9,10
     and the fourth pipe has the descriptors 11,12.
     The function executes the command:
        form -pipe 5,8,9,12
     and returns in the
        array fdread the following:
        {7,11}
        array fwrite the following:
        {6,10};
     the zero channel:
       the program "form" reads from 5 and writes to 8 while
       the main program  reads from 7 and writes to 6;
     the first channel:
       the program "form" reads from 9 and writes to 12 while
       the main program  reads from 11 and writes to 10.
   All unuised descriptors except of first "fdstart" (usually three
   "standard" stdin, stdout and stderr) are closed before execute
   the specified command.
   The function returns PID of the started command, or -1*/
pid_t flnk_do_runcmd(
    /*--Input parameters:--*/
    int nchannels,/*number of i/o cahnnels*/
    int ttymode,/*0 - nothing,
                 &1 - stdin</dev/null
                 &2 - stdout>/dev/null
                 &4 - stderr>/dev/null
                 &8 - daemonizeing
                 &16 - setsid()*/
    char *cmd,/*filename to execute*/
    char *argv[],/*arguments, argv[0] is the name of the started process*/
    int nopt,/*if >0, order number of the option to be replaced by pipe info*/
    char *envnam,/* if not NULL, export the pipe info into this env. variable*/
    int fdstart,/*How many standard descriptors are opened?
                 (usually 3 -- stdin, stdout and stderr*/
    /*--Output parameters:--*/
    int *fdread,/*array of read descriptors*/
    int *fdwrite,/*array of write descriptors*/
    int *formPID/*if !NULL, FORM PID obtained during initialization*/
)
{   int i, ret;
    FLNK_APIPE *fdin=NULL, *fdout=NULL,/*arrays of input-output pipes*/
                fdsig= {-1,-1}; /*Signal pipe*/
    pid_t childpid=(pid_t)-1,fatherchildpid = (pid_t)0;
    mysighandler_t oldPIPE=NULL;

    ret=FLINK_ALLOCERR;

    fdin=malloc(sizeof(FLNK_APIPE)*nchannels);

    if (fdin==NULL)
        goto fail_flnk_do_runcmd;
    /*For possible rollback:*/
    for (i=0; i<nchannels; i++)
        fdin[i][0]=fdin[i][1]=-1;

    fdout=malloc(sizeof(FLNK_APIPE)*nchannels);
    if (fdout==NULL)
        goto fail_flnk_do_runcmd;
    /*For possible rollback:*/
    for (i=0; i<nchannels; i++)
        fdout[i][0]=fdout[i][1]=-1;

    ret=FLINK_PIPEERR;

    /*Att! The order of pipe() calls is important! Do not change the order:
      pipe(fdsig), pipe(fdin), pipe(fdout)!*/
    /*This pipe will be used by a child to tell the father if fail:*/
    if (pipe(fdsig)!=0)
        goto fail_flnk_do_runcmd;
    /*Without daemonizing, the father expects failure readig this pipe
      since close-on-exec flag will be set.
      With deamonizing, the (grand)father expects the (grand)child
      PID from this pipe, or <0  if the (grand)child
      fails on exec().*/

    for (i=0; i<nchannels; i++)
        if (  /* Open  pipes for input-output:*/
            (pipe(fdin[i])!=0)
            ||(pipe(fdout[i])!=0)
        )
            goto fail_flnk_do_runcmd;

    if ((childpid = fork()) == -1)
    {   perror("fork");
        ret=FLINK_FORKEERR;
        goto fail_flnk_do_runcmd;
    }

    if (childpid == 0) /*Child.*/
    {   int *fifo, top=0;
        char *bufin=NULL,*args=NULL;/*bufin will be a comma-separated list of
                          descriptors, args is a working pointer*/
        /*
          To be thread safely, we can't rely on ascendant order of opened
          file descriptors. So we put each of descriptor we have to
          preserve into the array fifo. But first we have to allocate fifo.
        */
        /*
          Note, allocated arrays will never be freed since this process
          either exec()'ed or exited in this function.
        */
        if (
            ( (args=bufin=malloc(nchannels*2*21)) ==NULL )
            /* 64/Log_2[10] = 19.3, so 21 (20+'\0' or ',') is
             enough forever for a single argument.*/
            ||( (fifo=malloc((nchannels*2+2)*sizeof(int))) ==NULL)
            /*The fifo size -- fdin[i][0]+fdout[i][1]+fdsig[0]+fdsig[1]*/
        )
        {   /*Signal to the parent process:*/
            writepid(fdsig[1],FLINK_ALLOCERR);
            _exit(1);/*The child, just exit, not return*/
        }

        /*Mark descriptors which will NOT be closed:*/
        pushDescriptor(fifo,top++,fdsig[1]);

        /*Process all channel descriptors which will be passeed to
          FORM:*/
        for (i=0; i<nchannels; i++)
        {   /*This is extra, files have no close-on-exec flag by
             default, but just to be on the safe side clean it:*/
            set_cloexec_flag(fdin[i][0], 0);
            set_cloexec_flag(fdout[i][1], 0);

            /*Mark descriptors which will NOT be closed:*/
            pushDescriptor(fifo,top++,fdin[i][0]);
            pushDescriptor(fifo,top++,fdout[i][1]);

            /*build the argument list:*/
            /*add 'r' descriptor to the list:*/
            args=addInt2str(args,fdin[i][0]);
            *args++=',';
            /*add 'w' descriptor to the list:*/
            args=addInt2str(args,fdout[i][1]);
            *args++=',';
        }/*for (i=0; i<nchannels;i++)*/

        *--args='\0';/*terminate the string overridding the latest ','*/
        /*Now in bufin there is the comma-separated list of descriptors
          to be pased to FORM. Store the list:*/
        if (nopt>0)
            argv[nopt]=bufin;
        if (envnam!=NULL)
            setenv(envnam,bufin,1);

        /*Close all descriptors except those listed in fifo:*/
        closeAllDescriptors(fdstart,fifo, top);

        if (ttymode & 1) /* stdin </dev/null*/
        {   if (close(0) == 0)
                open("/dev/null",O_RDONLY);
        }/*if (ttymode & 1)*/
        if (ttymode & 2) /* stdout > /dev/null*/
        {   if (close(1) == 0 )
                open("/dev/null",O_WRONLY);
        }/*if (ttymode & 2)*/
        if (ttymode & 4) /* stder > /dev/null*/
        {   if (close(2) == 0 )
                open("/dev/null",O_WRONLY);
        }/*if (ttymode & 4)*/

        if ( ttymode & 16 )/* create a session and sets the process group ID */
            setsid();

        if (set_cloexec_flag (fdsig[1], 1)!=0) /*Error?*/
        {   /*Signal to parent:*/
            writepid(fdsig[1],FLINK_PIPEERR);
            _exit(1);
        }

        if ( ttymode & 8 ) /*Daemonize*/
        {   int fdsig2[2];/*To check exec() success*/
            if (
                pipe(fdsig2)||
                (set_cloexec_flag (fdsig2[1], 1)!=0)
            )
            {   /*Error?*/
                /*Signal to parent:*/
                writepid(fdsig[1],FLINK_DAEMONERR|FLINK_PIPEERR);
                _exit(1);
            }
            set_cloexec_flag (fdsig2[0], 1);
            switch(childpid=fork())
            {   case 0:/*grandchild*/
                    /*Execute external command:*/
                    execvp(cmd, argv);
                    /* Control can  reach this point only on error!*/
                    writepid(fdsig2[1],(pid_t)-2);
                    break;
                case -1:
                    /* Control can  reach this point only on error!*/
                    /*Inform the father about the failure*/
                    writepid(fdsig[1],FLINK_DAEMONERR|FLINK_FORKEERR);
                    _exit(1);/*The child, just exit, not return*/
                default:/*Son of his father*/
                    close(fdsig2[1]);
                    /*Ignore SIGPIPE (up to the end of the process):*/
                    signal(SIGPIPE,SIG_IGN);

                    /*Wait on read() while the granchild close the pipe
                      (on success) or send -2 (if exec() fails).*/
                    /*There are two possibilities:
                       -1 -- this is ok, the pipe was closed on exec,
                       the program was successfully executed;
                       -2 -- something is wrong, exec failed since the
                       grandchild sends -2 after exec.
                    */
                    if ( readpid(fdsig2[0]) != (pid_t)-1 )/*something is wrong*/
                        writepid(fdsig[1],FLINK_DAEMONERR|FLINK_EXECEERR);
                    else/*ok, send PID of the granchild to the father:*/
                        writepid(fdsig[1],childpid);
                    /*Die and free the life space for the grandchild:*/
                    _exit(0);/*The child, just exit, not return*/
            }/*switch(childpid=fork())*/
        }
        else  /*if ( ttymode & 8 )*/
        {   execvp(cmd, argv);
            /* Control can  reach this point only on error!*/
            writepid(fdsig[1],FLINK_EXECEERR);
            _exit(2);/*The child, just exit, not return*/
        }/*if ( ttymode & 8 )...else*/
    }
    else  /* The (grand)father*/
    {   close(fdsig[1]);
        /*To prevent closing fdsig in rollback after
          goto fail_flnk_do_runcmd:*/
        fdsig[1]=-1;
        for (i=0; i<nchannels; i++)
        {   /*No rollback here -- what could be the reason?:*/
            close(fdin[i][0]);
            close(fdout[i][1]);
            fdread[i]=fdout[i][0];
            fdwrite[i]=fdin[i][1];
        }/*for (i=0; i<nchannels;i++)*/

        free(fdin); fdin=NULL;
        free(fdout); fdout=NULL;
        /* Temporary ignore this signal:*/
        /* if compiler fails here, try to change the definition of
           mysighandler_t on the beginning of this file
           (just define INTSIGHANDLER)*/
        oldPIPE=signal(SIGPIPE,SIG_IGN);

        if ( ttymode & 8 ) /*Daemonize*/
        {   /*Read the grandchild PID from the son.*/
            fatherchildpid=childpid;
            if (  (childpid=readpid(fdsig[0]))<0  )
            {   /*Daemoniization process fails for some reasons!*/
                ret=childpid;
                childpid=fatherchildpid;/*for rollback*/
                goto fail_flnk_do_runcmd;
            }
        }
        else
        {   /*fdsig[1] should be closed on exec and this read operation
              must fail on success:*/
            ret=readpid(fdsig[0]);
            if ( ret != (pid_t)-1 )
                goto fail_flnk_do_runcmd;
        }/*if ( ttymode & 8 ) ... else*/

    }/*The (grand)father*/

    /*Here can be ONLY the father*/
    close(fdsig[0]);
    /*To prevent closing fdsig in rollback after goto fail_flnk_do_runcmd:*/
    fdsig[0]=-1;

    if ( ttymode & 8 )/*Daemonize*/
        /*Wait while the father of a grandchild dies:*/
        waitpid(fatherchildpid,&i,0);

    if ( (ret=initFrm(nchannels,fdwrite,fdread,childpid))<0)
        goto fail_flnk_do_runcmd;

    if (formPID!=NULL)
        *formPID=ret;

    /*Restore the signal:*/
    signal(SIGPIPE,oldPIPE);

    return(childpid);/*The normal return. The father must return here.*/

    /*rollback:*/
fail_flnk_do_runcmd:

    if (oldPIPE!=NULL)/*restore the signal:*/
        signal(SIGPIPE,oldPIPE);

    closepipe(&fdsig);
    if (fdout)
    {   for (i=0; i<nchannels; i++)
            closepipe(fdout+i);
        free(fdout);
    }
    if (fdin)
    {   for (i=0; i<nchannels; i++)
            closepipe(fdin+i);
        free(fdin);
    }

    if (childpid>0)
    {   for (i=0; i<nchannels; i++)
        {   close(fdread[i]);
            close(fdwrite[i]);
        }/*for (i=0; i<nchannels;i++)*/

        kill(childpid,SIGKILL);
        waitpid(childpid,fdsig,0);
    }/*if (childpid>0)*/

    if (formPID!=NULL)
        *formPID=0;

    return ret;

}/*flnk_do_runcmd*/

static int parseline(char **argv, char *cmd)
{   int n=0,nopt=0;
    while (*cmd != '\0')
    {   for (; (*cmd <= ' ') && (*cmd != '\0') ; cmd++)
            ;
        if (*cmd != '\0')
        {   argv[n]=cmd;
            while (*++cmd > ' ');
            if (*cmd != '\0')
                *cmd++ = '\0';
            if ( (nopt==0) && (strcmp(argv[n],"-pipe")==0) )
                argv[nopt=++n]=NULL;
            n++;
        }/*if (*cmd != '\0')*/
    }/*while (*cmd != '\0')*/
    argv[n]=NULL;
    if (n==0)return -1;
    return nopt;
}/*parseline*/

/*The high-level wrapper to flnk_do_runcmd(). Creates one preset
  channel and starts a command "cmd" providing it this channel.
  The output of the running command can be received from the stream
  freceive, the input can be send by the stream fsend. The buffering
  mode of these streams is DEFAULT one provided by stdio, i.e.,
  after the data are sent to fsend, fflush(fsend); is needed.
    If cmd containes the token -pipe, then the descriptor list
  will be inserted after this token, otherwise, the environment
  variable FORM_PIPES with this list will be exported.
    If daemonize == 0, the command is started directly in the
  current process group and its stahdard input, output and error
  streams are kept as they are. If daemonize != 0, the command
  is started in a new session without the leader, it is passed
  to the init process and its stahdard input, output and error
  streams are redirected to /dev/null.
*/
pid_t flnk_runcmd(
    FILE **freceive,/*get from running program*/
    FILE **fsend,/*send to running program*/
    int daemonize,/*0 - not, !=0 - yes*/
    char *cmd/*command to execute, may contain '-pipe'; if not,
               FORM_PIPES environment variable will be used*/
)
{   pid_t pid;
    int fdread, fdwrite, nopt;
    char *envname,**argvc;

    if (cmd==NULL)return FLINK_INVCMD;

    /*Temporarily use nopt and envname to detouch cmd and allocate argvc.*/
    nopt=strlen(cmd);
    if ( (envname=malloc(nopt+1))==NULL )
        return FLINK_ALLOCERR;
    cmd=strcpy(envname,cmd);/*detouch cmd*/
    /*Number of options can't be more than the length of a line:*/
    argvc=malloc( (nopt+2)*sizeof(char*) );
    if (argvc == NULL)
    {   free(cmd);
        return FLINK_ALLOCERR;
    }
    nopt=parseline(argvc,cmd);
    if (nopt<0)
    {   free(cmd);
        free(argvc);
        return FLINK_INVCMD;
    }
    if (nopt == 0)
        envname=FORM_PIPES;
    else
        envname=NULL;

    pid=flnk_do_runcmd(1, (daemonize)?(1|2|4|8|16):0,
                       argvc[0],argvc,nopt,envname,3,&fdread, &fdwrite,NULL);

    free(cmd);
    free(argvc);

    if (pid>0)
    {   *freceive=fdopen(fdread,"r");
        *fsend=fdopen(fdwrite,"w");
        if (  ( (*freceive)==NULL )||( (*fsend)==NULL )  )
        {   kill(pid,SIGKILL);
            waitpid(pid,&fdread,0);
            pid=FLNK_DOPENERR;
        }/*if (  ( (*freceive)==NULL )||( (*fsend)==NULL )  )*/
    }/*if (pid>0)*/
    return pid;
}/*flnk_runcmd*/


/*
This simple demo is an algebraic "calculator" based on embedded FORM.
To compile it, one can use the following command line:
cc -o demo_calc -DDEMO_CALC flnk_startform.c
The executable file demo_calc must appear in the current directory.
Simply start it:
./demo_calc
and enter something like
(a+b)^100

If the error occures:
Error executing program
this means the program cannot start the FORM executable, correct the path
FORMPATH.

If the error occures:
Initialization error
this means the program starts the old FORM executable, which has no external
interface. The interface used in this demo appears in FORM 3.2

To quit the program, press ctrl-d
*/

/*
This simple demo is rather useless, it is only to demonstrate of how
flnk_runcmd() could be used, and also how to handle errors.
*/

/*
The program reads line by line from the keyboard. Each line is parsed
in order to pick up identifiers. Identifiers are started by a letter
and are formed by letters and digits. All ID's are assumed to be just
symbols.

Each identifier is sent to FORM as
s ID;
Then the string (without trailing newline or ';') is sent to FORM as
l tempExpr = <the string>;\n
and the module is ended by the .sort instruction. In the next module
the expression is sent back to the program and dropped, all symbols
are discarded by the .store instruction. The program prints the answer
and reads the next line from the keyboard.

If the program fails reading the answer, it simply restarts FORM.

The program creates the temporary file "tmp.frm" (the name could be
changed by changing the macro TMPFRMNAME) with the following FORM
program:

   #setexternal `PIPE1_'
   #do i=1,1
   #fromexternal
   #toexternal "%e\n", tempExpr
   .store
   #redefine i "0"
   #enddo

E.g., if the user enters such a line:
(a1+a2+b)^23
the following two  modules will be executed:

    s a1;
    s a2;
    s b;
    drop tempExpr;
    l tempExpr = (a1+a2+b)^23;
    .sort
    #toexternal "%e\n", tempExpr
    .store

*/

/*Path to the FORM executable file:*/
#define FORMPATH "/home/neun/form/form -pipe"
/*Alternatively, the following variant can be used:*/
/*#define FORMPATH "./form -pipe"*/

char FormCommand [40];

/*The temporary file name:*/
#define TMPFRMNAME "/home/neun/form/tmp.frm"

/*This function demonstrates how one can use the macro FLNK_ISERR
in order to check the error code returned by functions flnk_do_runcmd()
and flnk_runcmd() (note, errors may be OR'ed!):*/

static int errmessage(pid_t errcode)
{   int n=0;
    if (FLNK_ISERR(errcode,FLINK_ALLOCERR))
    {   puts("Memory allocation error");
        n++;
    }
    if (FLNK_ISERR(errcode,FLINK_PIPEERR))
    {   puts("Error processing a pipe");
        n++;
    }
    if (FLNK_ISERR(errcode,FLINK_FORKEERR))
    {   puts("Fork error");
        n++;
    }
    if (FLNK_ISERR(errcode,FLINK_EXECEERR))
    {   puts("Error executing program");
        n++;
    }
    if (FLNK_ISERR(errcode,FLINK_DAEMONERR))
    {   puts("Error during daemonizing");
        n++;
    }
    if (FLNK_ISERR(errcode,FLNK_DOPENERR))
    {   puts("Error opening stream");
        n++;
    }
    if (FLNK_ISERR(errcode,FLINK_INVCMD))
    {   puts("Invalid command");
        n++;
    }
    if (FLNK_ISERR(errcode,FLNK_INITERR))
    {   puts("Initialization error");
        n++;
    }
    if (FLNK_ISERR(errcode,FLNK_INITTMERR))
    {   puts("Timeout");
        n++;
    }
    if (FLNK_ISERR(errcode,FLNK_INITPIDERR))
    {   puts("More than one FORM PID");
        n++;
    }
    return n;
}/*errmessage*/

/*The function just (re)starts FORM:*/
int forminit(FILE **freceive,FILE **fsend)
{   pid_t fpid;
    sprintf(FormCommand,"%s/form/form -pipe %s/form/tmp.frm",
            getenv("reduce"),getenv("reduce"));
    if ( (*freceive) !=NULL)
        fclose(*freceive);
    if ( (*fsend) !=NULL)
        fclose(*fsend);
    *freceive=*fsend=NULL;
    fpid=flnk_runcmd(
             freceive,
             fsend,
             1,/*daemon mode. Try 0, the FORM output will be visible on the screen.*/
             //   FORMPATH" "TMPFRMNAME
             FormCommand
         );
    if (fpid<0)
    {   printf("Total %d errors\n",errmessage(fpid));
        return -1;
    }
    return 0;
}/*forminit*/

/* end of formlink2.c */
