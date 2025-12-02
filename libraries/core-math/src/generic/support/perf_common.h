/* Performance of mathematical functions.

Copyright (c) 2022 Stéphane Glondu, Inria.

This file is part of the CORE-MATH project
(https://core-math.gitlabpages.inria.fr/).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;

#ifdef WITH_ERRNO
/* without this, Newlib says: undefined reference to `__errno' */
int errno;
int* __errno () { return &errno; }
#endif

#ifdef __aarch64__
/* Replacement for __rdtsc builtin. Contributed by Tue Ly, under
   MIT license. */
inline uint64_t __rdtsc(void) {
  uint64_t clock_counter, clock_freq;

  asm volatile ("isb; mrs %0, cntvct_el0" : "=r" (clock_counter));
  asm volatile ("mrs %0, cntfrq_el0" : "=r" (clock_freq));

  return clock_counter * (1000000000 / clock_freq);
}
#elif defined __powerpc64__
# if defined __GLIBC__ && (__GLIBC__ > 2 && __GLIBC_MINOR__ > 16)
#  include <sys/platform/ppc.h>
#  define __get_clock_freq() __ppc_get_timebase_freq()
# else
/* It should be a good approximation for most POWER processors.  */
#  define __get_clock_freq() 512000000
# endif
uint64_t __rdtsc(void) {
  uint64_t clock_counter, clock_freq;
  asm volatile ("lwsync; mfspr %0,268" : "=r" (clock_counter));
  clock_freq = __get_clock_freq ();

  return clock_counter * (1000000000 / clock_freq);
}
#endif

int
main (int argc, char *argv[])
{
  int count = 1000000, repeat = 1;
  int reference = 0, latency = 0, show_rdtsc = 0;
  function_type_under_test *p_function_under_test = &cr_function_under_test;
  char *file = NULL;

  while (argc >= 2)
    {
      if (strcmp (argv[1], "--rndn") == 0)
        {
          rnd = 0;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rndz") == 0)
        {
          rnd = 1;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rndu") == 0)
        {
          rnd = 2;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rndd") == 0)
        {
          rnd = 3;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--reference") == 0)
        {
          reference = 1;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--latency") == 0)
        {
          latency = 1;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rdtsc") == 0)
        {
          show_rdtsc = 1;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--libc") == 0)
        {
          p_function_under_test = &function_under_test;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--file") == 0)
        {
          argc --;
          argv ++;
          file = argv[1];
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--count") == 0)
        {
          argc --;
          argv ++;
          count = atoi(argv[1]);
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--repeat") == 0)
        {
          argc --;
          argv ++;
          repeat = atoi(argv[1]);
          argc --;
          argv ++;
        }
      else
        {
          fprintf (stderr, "Error, unknown option %s\n", argv[1]);
          exit (1);
        }
    }

  if (file == NULL) {
    fprintf(stderr, "--file <file> is mandatory\n");
    fflush(stderr);
    exit(2);
  }

  fesetround(rnd1[rnd]);
  if (reference) {
    int fd = open(file, O_CREAT | O_RDWR, 00644);
    if (fd < 0) {
      perror("open");
      exit(3);
    }
    if (ftruncate(fd, count * SAMPLE_SIZE) < 0) {
      perror("ftruncate");
      exit(3);
    }
    TYPE_UNDER_TEST *randoms = mmap(NULL, count * SAMPLE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (randoms == MAP_FAILED) {
      perror("mmap");
      exit(3);
    }
#ifdef CORE_MATH_BIVARIATE
    for (int i = 0; i < count; i++) {
      randoms[2*i+0] = random_under_test_0();
      randoms[2*i+1] = random_under_test_1();
    }
#else
    for (int i = 0; i < count; i++) {
      randoms[i] = random_under_test();
    }
#endif
    msync(randoms, count * SAMPLE_SIZE, MS_SYNC);
    munmap(randoms, count * SAMPLE_SIZE);
    close(fd);
  } else {
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
      perror("open");
      exit(3);
    }
    TYPE_UNDER_TEST *mmaped_randoms = mmap(NULL, count * SAMPLE_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (mmaped_randoms == MAP_FAILED) {
      perror("mmap");
      exit(3);
    }
    TYPE_UNDER_TEST *randoms = malloc(count * SAMPLE_SIZE);
    if (randoms == NULL) {
      perror("malloc");
      exit(3);
    }
    memcpy(randoms, mmaped_randoms, count * SAMPLE_SIZE);
    uint64_t start = __rdtsc();
    if (latency) {
      for (int r = 0; r < repeat; r++) {
        TYPE_UNDER_TEST accu = 0;
        for (int i = 0; i < count; i++) {
          CALL_LATENCY(accu, i);
        }
      }
    } else {
      for (int r = 0; r < repeat; r++) {
        for (int i = 0; i < count; i++) {
          CALL_THROUGHPUT(i);
        }
      }
    }
    uint64_t stop = __rdtsc();
    if (show_rdtsc) {
      printf("%.3f\n", (double) (stop - start) / (repeat * count));
    }
    munmap(mmaped_randoms, count * sizeof(TYPE_UNDER_TEST));
    close(fd);
  }

  return 0;
}
