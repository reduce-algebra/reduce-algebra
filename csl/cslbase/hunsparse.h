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

// Modified by ACN for a spare representation.

#ifndef HUNGARIAN_H
#define HUNGARIAN_H

#ifdef __cplusplus
extern "C" {
#endif
  
#define HUNGARIAN_NOT_ASSIGNED 0 
#define HUNGARIAN_ASSIGNED 1

#define HUNGARIAN_MODE_MINIMIZE_COST   0
#define HUNGARIAN_MODE_MAXIMIZE_UTIL 1


typedef struct __edge
{
  struct __edge *next_in_row;   // Chain across current row.
  struct __edge *next_in_col;   // Chain down current column.
  int row;                      // Row number of this entry.
  int col;                      // Column number of this entry.
  int cost;                     // Cost associated with the edge.
  char assigned;                // Is the edge assigned?
} edge_t; 

typedef struct {
  int num_rows;
  int num_cols;
  edge_t* by_rows;
  edge_t* by_columns;
} hungarian_problem_t;

/** This method initialize the hungarian_problem structure and init 
 *  the  cost matrices (missing lines or columns are filled with 0).
 *  It returns the size of the quadratic(!) assignment matrix. **/
int hungarian_init(hungarian_problem_t* p, 
		   edge_t* cost_matrix,  // ???????
		   int rows, 
		   int cols, 
		   int mode);
  
/** Free the memory allocated by init. **/
void hungarian_free(hungarian_problem_t* p);

/** This method computes the optimal assignment. **/
void hungarian_solve(hungarian_problem_t* p);

/** Print the computed optimal assignment. **/
void hungarian_print_assignment(hungarian_problem_t* p);

/** Print the cost matrix. **/
void hungarian_print_costmatrix(hungarian_problem_t* p);

/** Print cost matrix and assignment matrix. **/
void hungarian_print_status(hungarian_problem_t* p);

#ifdef __cplusplus
}
#endif

#endif



