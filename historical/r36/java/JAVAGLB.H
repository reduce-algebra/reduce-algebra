/* javaglb.h:  Copyright (C) Codemist Ltd., 1996.                       */

extern int debugging;
 
extern void jsyserr(char *fmt, ...);
extern void jdebug(char *fmt, ...);
extern void *jmalloc(unsigned32 n);
extern void *jfree(void *p);
extern ClassFile *rdClassFile(char *name);
extern ClassFile *rdClassFILE1(FILE *file, char *name);
extern void javaint(ClassFile *);
extern void javadecode(unsigned8 *code, unsigned32 len, Cp_Info *cp, unsigned32 cplen);
extern char *jdecodeopname(unsigned32 op);
extern ClassFile java_PrintStream;

/* end of javaglb.h */
