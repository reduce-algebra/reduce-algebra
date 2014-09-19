/*
 *
 * This is mycflush.c
 * (contains the systemcall to be added to /unix )
 *
 */

#include <sys/types.h>
#include <sys/vmuser.h>

/*
 *  exported symbol: mycflush
 *  vm_cflush can only be called in kernel mode
 */
int mycflush(caddr_t eaddr, int nbytes)
{
  vm_cflush(eaddr, nbytes);
  return(0);
}
