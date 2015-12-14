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

// Adjusted by A C Norman to make the code more compatible with a sparse
// version that it is being morphed into. This involves creating a problem
// and then specifying edges one at a time rather than all in a single
// (potentially huge) dense matrix.

#ifndef HUNGARIAN_H
#define HUNGARIAN_H

#define HUNGARIAN_NOT_ASSIGNED 0
#define HUNGARIAN_ASSIGNED 1

typedef struct
{   int num_rows;
    int num_cols;
    int** cost;
    char** assignment;
} hungarian_problem_t;

//* This method initialize the hungarian_problem structure.
// After calling it use hungarian_edge to insert edges.
//*
int hungarian_init(hungarian_problem_t* p,
                   int rows,
                   int cols,
                   int edges);

//* Add an edge to a problem. *
void hungarian_edge(hungarian_problem_t* p, int u, int v, int cost);

//* Free the memory allocated by init. *
void hungarian_free(hungarian_problem_t* p);

//* This method computes the optimal assignment. *
void hungarian_solve(hungarian_problem_t* p);

//* Print the computed optimal assignment. *
void hungarian_print_assignment(hungarian_problem_t* p);

//* Print the cost matrix. *
void hungarian_print_costmatrix(hungarian_problem_t* p);

//* Print cost matrix and assignment matrix. *
void hungarian_print_status(hungarian_problem_t* p);

#endif


