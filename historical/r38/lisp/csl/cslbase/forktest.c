/*
 * This file is NOT part of CSL. It is a test file used while testing
 * development of support for any hypothetical future concurrency schemes.
 */

#include <sys/types.h>
#include <unistd.h>
#ifdef WIN32
#define SIGKILL 9
#else
#include <sys/wait.h>
#endif
#include <signal.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

volatile int a = 0;

void worry(int n)
{
    int i, j;
    for (j=0; j<100; j++)
        for (i=0; i<10000000*n; i++) a++;
}

int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pidx, pidy;
    int status;
    pid1 = fork();
    if (pid1 < 0)
    {   printf("Fork 1 failed\n");
    }
    else if (pid1 == 0)
    {   /* TASK 1 */
        printf("Task 1 starting\n");
        worry(argc+5);
        printf("Task 1 has had %d seconds\n", argc+5);
        exit(0);
    }
    else
    {   printf("Task 1 has pid %d\n", pid1);
        pid2 = fork();
        if (pid2 < 0)
        {   printf("Fork 2 failed\n");
            kill(pid1, SIGKILL);
            waitpid(pid1, &status, 0);
            printf("Task 1 killed\n");
        }
        else if (pid2 == 0)
        {   /* TASK 2 */
            printf("Task 2 starting\n");
            worry(7);
            printf("Task 2 has had 7 seconds\n");
            exit(0);
        }
        else
        {   printf("Task 2 has pid %d\n", pid2);
            pidx = wait(&status);
            printf("First signal was from task %d\n", pidx);
            if (!WIFEXITED(status))
            {   printf("Task did not exit cleanly\n");
                kill(pid1, SIGKILL);
                kill(pid2, SIGKILL);
                waitpid(pid1, &status, 0);
                waitpid(pid2, &status, 0);
                printf("Both tasks now dead\n");
            }
            pidy = pidx == pid1 ? pid2 : pid1;
            kill(pidy, SIGKILL);
            waitpid(pidy, &status, 0);
            printf("Other task (%d) now dead\n", pidy);
        }
    }
    printf("All done\n");
    return 0;
}

