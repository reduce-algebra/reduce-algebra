/********************************************************************
 ********************************************************************
 **
 ** libhungarian by Cyrill Stachniss, 2004
 **
 **
 ** Solving the Minimum Assignment Problem using the 
 ** Hungarian Method.
 **
 ** ** This file may be freely copied and distributed! **
 **
 ** Parts of the used code was originally provided by the 
 ** "Stanford GraphGase", but I made changes to this code.
 ** As asked by  the copyright node of the "Stanford GraphGase", 
 ** I hereby proclaim that this file are *NOT* part of the
 ** "Stanford GraphGase" distrubition!
 **
 ** This file is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied 
 ** warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 ** PURPOSE.  
 **
 ********************************************************************
 ********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "hungarian.h"

int** array_to_matrix(int* m, int rows, int cols) {
  int i,j;
  int** r;
  r = (int**)calloc(rows,sizeof(int*));
  for(i=0;i<rows;i++)
  {
    r[i] = (int*)calloc(cols,sizeof(int));
    for(j=0;j<cols;j++)
      r[i][j] = m[i*cols+j];
  }
  return r;
}


int main() {

  hungarian_problem_t p;

  /* an example cost matrix */
  int r[4*3] =  {  100, 1, 1, 
		   100, 2, 2, 
		   1, 0, 0, 
		   0, 2, 0 };
  int** m = array_to_matrix(r,4,3);

  /* initialize the gungarian_problem using the cost matrix*/
  int matrix_size = hungarian_init(&p, m , 4,3, HUNGARIAN_MODE_MINIMIZE_COST) ;

  fprintf(stderr, "assignement matrix has a now a size %d rows and %d columns.\n\n",  matrix_size,matrix_size);

  /* some output */
  fprintf(stderr, "cost-matrix:");
  hungarian_print_costmatrix(&p);

  /* solve the assignement problem */
  hungarian_solve(&p);

  /* some output */
  fprintf(stderr, "assignment:");
  hungarian_print_assignment(&p);

  /* free used memory */
  hungarian_free(&p);

  int idx;
  for (idx=0; idx < 4; idx+=1) {
    free(m[idx]);
  }
  free(m);

  return 0;
}

