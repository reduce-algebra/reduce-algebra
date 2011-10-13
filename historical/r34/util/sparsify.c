/* Sparsify.c 
   J.H. Davenport 21.5.89
   usage: "sparsify filename"
   The file-name had better not be a symbolic link,
   but this isn't checked for.
   Modification: JHD 25.7.89: set owner (where possible)
   modification times, permission status etc. 
   Modification: JHD 16.10.89: fix a SUNos 4 feature for files whose
   last block is precisely null
*/

#define BSIZE 8192
#ifdef hpux
#include <fcntl.h>
/* This will give us O_RDONLY and friends on HPUX */
#include <utime.h>
struct utimbuf hpux_utime;
#endif
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
long lseek();
char *malloc();
/* Really should look it up: could be something different, but it
   doesn't really matter */
int buf[BSIZE/4]; /* So can use word operations */
main(argc,argv)
int argc;
char **argv;
{ int ifile,ofile,ilen,ans,seeking;
  long lans;
  char *oname;
  struct stat statbuf;
  if (argc != 2)
    { printf("Usage: sparsify filename\n");
      exit(-1);
    }
  ifile=open(argv[1],O_RDONLY);
  if (ifile<0)
    { perror("File couldn't be opened\n");
      exit(ifile);
    }
  oname=malloc((ilen=strlen(argv[1]))+3);
  strcpy(oname,argv[1]);
  oname[ilen]='.';
  oname[ilen+1]='z';
  oname[ilen+2]='\0';
  ofile=open(oname,O_WRONLY|O_CREAT|O_EXCL,0755);
  if (ofile<0)
    { perror("Output file couldn't be opened\n");
      exit(ifile);
    }
  seeking=0;
  while ((ilen=read(ifile,(char *)buf,BSIZE))==BSIZE)
    if (allzeros())
      { lans=lseek(ofile,(long)BSIZE,L_INCR);
	if(lans<0)
	  { perror("Lseek failed\n");
	    tidyup(oname);
	  }
	seeking=1;
      }
    else
      { ans=write(ofile,(char *)buf,BSIZE);
	if (ans != BSIZE)
	  { perror("Write failed\n");
	    tidyup(oname);
	  }
	seeking=0;
      }
  if (ilen > 0)
    { ans=write(ofile,(char *)buf,ilen);
      if (ans != ilen)
	{ perror("Write failed\n");
	  tidyup(oname);
	}
    }
  else if (seeking)
    { lans=lseek(ofile,-(long)BSIZE,L_INCR);
      if(lans<0)
	{ perror("Lseek failed\n");
	              tidyup(oname);
	}
      ans=write(ofile,(char *)buf,BSIZE);
      if (ans != BSIZE)
	{ perror("Write failed\n");
	  tidyup(oname);
	  }
    }
  ilen=fstat(ifile,&statbuf);
  if (ilen < 0)
    { perror("Fstat failed\n");
      tidyup(oname);
    }
  ilen=fchmod(ofile,statbuf.st_mode);
  if (ilen < 0)
    { perror("Attempt to chmod failed\n");
      tidyup(oname);
    }
  if (geteuid())
    { if (statbuf.st_uid != geteuid())
        printf("Can't reset owner/group\n");
    }
  else {
    ilen=fchown(ofile,statbuf.st_uid,statbuf.st_gid);
    if (ilen < 0)
      { perror("Chown failed\n");
	tidyup(oname);
      }
  }
#ifdef hpux
  /* So it's hpux  */
  hpux_utime.actime=statbuf.st_atime;
  hpux_utime.modtime=statbuf.st_mtime;
  ilen=utime(oname,&hpux_utime);
#else
  /* so it's a sun, or maybe an apollo */
  ilen=utimes(oname,&statbuf.st_atime);
#endif
  if (ilen < 0)
    { perror("Attempt to set times failed\n");
            tidyup(oname);
    }
  ilen=unlink(argv[1]);
  if (ilen<0)
    { perror("Unlink for old file failed\n");
      printf("Tidy up by hand!\n");
      exit(-1);
    }
  ilen=link(oname,argv[1]);
  if (ilen!= 0)
    { perror("Rename failed\n");
      printf("Tidy up by hand!\n");
      exit(-1);
    }
  ilen=unlink(oname);
  if (ilen<0)
    { perror("Unlink for temporary file failed\n");
      printf("Tidy up by hand!\n");
      exit(-1);
    }
  exit(0);
}

tidyup(oname)
char *oname;
{ int ilen;
  ilen=unlink(oname);
  if (ilen<0)
    { perror("Unlink for temporary file failedwhile tidying up\n");
      printf("Tidy up by hand!\n");
      exit(-1);
    }
}

allzeros()
{ int i;
  for(i=0;i<BSIZE/4;i++)
    if(buf[i])
      return 0;
  return 1;
}
