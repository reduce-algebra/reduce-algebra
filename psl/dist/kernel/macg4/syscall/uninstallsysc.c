/* 
 * this is uninstallsysc.c
 * to unload a systemcall:
 *      uninstallsysc <kmid>
 */

#include <stdio.h>

#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysconfig.h>
#include <sys/sysmacros.h>
#include <sys/device.h>

#define PATHNAME_OF_THE_SYSTEMCALL   "./mycflush"

main(int argc, char **argv)
{
  int id;
  struct cfg_load cl;

  if(argc != 2){
    fprintf(stderr, "usage:\n\t%s <n>\n", argv[0]);
    exit(1);
  }


  cl.path = PATHNAME_OF_THE_SYSTEMCALL;

  cl.libpath = NULL;

  if( (id = sysconfig(SYS_QUERYLOAD, &cl, sizeof(struct cfg_load))) != 0) {
    perror("sysconfig");
    exit(1);
  }

  fprintf(stderr, "kmid= %d still existing\n", cl.kmid);

  cl.path = NULL;
  cl.libpath = NULL;
  cl.kmid = atoi(argv[1]);

  fprintf(stderr, "unloading kmid= %d\n", cl.kmid);

  if( (id = sysconfig(SYS_KULOAD, &cl, sizeof(struct cfg_load))) != 0) {
    perror("sysconfig");
    exit(1);
  }

  fprintf(stderr, "kmid= %d unloaded\n", cl.kmid);
}


