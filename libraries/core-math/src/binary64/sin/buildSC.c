/* build table SC[] with entries x in [0,1/8] near multiples of 1/8/N
   such that sin2pi(x) and cos2pi(x) have accuracy 53+k bits */

#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

#define N 256 // length of the table

static void
doit (int k)
{
  double SC[N][3];
  int remains = N;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
  for (int i = 0; i < N; i++)
    {
      mpfr_t x, y, s, c, ss, cc;
      mpfr_init2 (x, 53);
      mpfr_init2 (y, 53);
      mpfr_init2 (s, 53 + k);
      mpfr_init2 (c, 53 + k);
      mpfr_init2 (ss, 53);
      mpfr_init2 (cc, 53);
      double xi = (double) i / (double) (8 * N);
      mpfr_set_d (x, xi, MPFR_RNDN);
      mpfr_set_d (y, xi, MPFR_RNDN);
      mpfr_nextabove (y);
      while (1)
        {
          mpfr_sinu (s, x, 1, MPFR_RNDN);
          mpfr_set (ss, s, MPFR_RNDN);
          if (mpfr_cmp (s, ss) == 0)
            {
              mpfr_cosu (c, x, 1, MPFR_RNDN);
              mpfr_set (cc, c, MPFR_RNDN);
              if (mpfr_cmp (c, cc) == 0)
                break;
            }
          mpfr_nextbelow (x);
          mpfr_sinu (s, y, 1, MPFR_RNDN);
          mpfr_set (ss, s, MPFR_RNDN);
          if (mpfr_cmp (s, ss) == 0)
            {
              mpfr_cosu (c, y, 1, MPFR_RNDN);
              mpfr_set (cc, c, MPFR_RNDN);
              if (mpfr_cmp (c, cc) == 0)
                {
                  mpfr_set (x, y, MPFR_RNDN);
                  break;
                }
            }
          mpfr_nextabove (y);
        }
      SC[i][0] = mpfr_get_d (x, MPFR_RNDN) - xi;
      SC[i][1] = mpfr_get_d (ss, MPFR_RNDN);
      SC[i][2] = mpfr_get_d (cc, MPFR_RNDN);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
      {
        remains --;
        printf ("i=%d done, remains %d values\n", i, remains);
        fflush (stdout);
      }
              
      mpfr_clear (x);
      mpfr_clear (y);
      mpfr_clear (s);
      mpfr_clear (c);
      mpfr_clear (ss);
      mpfr_clear (cc);
    }
  
  /* output for sin.c */
  printf ("static const double SC[%d][3] = {\n", N);
  for (int i = 0; i < N; i++)
    printf ("   {%la, %la, %la}, /* %d */\n", SC[i][0], SC[i][1], SC[i][2], i);
  printf ("};\n");

  /* output for sin.sage */
  printf ("\nSC=[\n");
  for (int i = 0; i < N; i++)
    printf ("   (\"%la\", \"%la\", \"%la\"),\n", SC[i][0], SC[i][1], SC[i][2]);
  printf ("]\n");
}

int
main (int argc, char *argv[])
{
  int k = atoi (argv[1]);
  doit (k);
  return 0;
}
