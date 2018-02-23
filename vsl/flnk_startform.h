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
   to the paper M.~Tentyukov, J.A.M.~Vermaseren "Extension of the
   functionality of the symbolic program FORM by external software",
   cs.SC/0604052
THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY; WITHOUT EVEN
THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
PURPOSE.
*/

/*See comments in the file flnk_startform.c*/

#ifndef FLNK_STARTFORM
#define FLNK_STARTFORM
#ifndef INLINE
#define INLINE inline
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*Error codes: the most significant bits are set, to be negative,
and two less significant bytes are used as a single-bit flag:*/
#define FLINK_ALLOCERR (pid_t)( ((-1)^0xFFFF)|2 )
#define FLINK_PIPEERR (pid_t)( ((-1)^0xFFFF)|4 )
#define FLINK_FORKEERR (pid_t)( ((-1)^0xFFFF)|8 )
#define FLINK_EXECEERR (pid_t)( ((-1)^0xFFFF)|16 )
#define FLINK_DAEMONERR (pid_t)( ((-1)^0xFFFF)|32 )
#define FLNK_DOPENERR (pid_t)( ((-1)^0xFFFF)|64 )
#define FLINK_INVCMD (pid_t)( ((-1)^0xFFFF)|128 )
#define FLNK_INITERR (pid_t)( ((-1)^0xFFFF)|256 )
#define FLNK_INITTMERR (pid_t)( ((-1)^0xFFFF)|512 )
#define FLNK_INITPIDERR (pid_t)( ((-1)^0xFFFF)|1024 )

/*One argument must be a constant representing FLNK error, and
another one is a code returned by flnk_do_runcmd() of flnk_runcmd().
Macro returns TRUE if the returned code contains the corresponding
error:*/
#define FLNK_ISERR(x,y) (((x)<0)&&(y<0)&&(0xFFFF&(x)&(y)))

/*Timeout for the channel initialization, in millisecs:*/
#define FLNK_TIMEOUT 1100

/*Name of the environment variable used to pass a list of
descriptors:*/
#define FORM_PIPES "FORM_PIPES"

/*See comments in flnk_startform.c:*/
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
    int *formPID/*FORM PID obtained during initialization*/
);

/*See comments in flnk_startform.c:*/
pid_t flnk_runcmd(
    FILE **freceive,/*get from running program*/
    FILE **fsend,/*send to running program*/
    int daemonize,/*0 - not, !=0 - yes*/
    char *cmd/*command to execute, may contain '-pipe'; if not,
               FORM_PIPES environment variable will be used*/
);

#ifdef __cplusplus
}
#endif
#endif

/* end of flnk_startform.h */
