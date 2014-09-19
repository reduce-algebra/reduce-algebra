/*
 * this is installsysc.c
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysconfig.h>

#define PATHNAME_OF_THE_SYSTEMCALL   "./mycflush"

main()
{
  int id;
  struct cfg_load cl;

/*
 *  build data structure for sysconfig
 */
  cl.path = PATHNAME_OF_THE_SYSTEMCALL;
  cl.libpath = NULL;

  /*
   * add the systemcall
   */
  if( (id = sysconfig(SYS_KLOAD, &cl, sizeof(struct cfg_load))) != 0) {
    perror("sysconfig");
    exit(1);
  }

  fprintf(stderr, "kmid= %d\n", cl.kmid);
  fprintf(stdout, "%d", cl.kmid);
}

