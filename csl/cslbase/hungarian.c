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

// The version here has been adapted by A C Norman (October 2015) for use
// in creating matchings for use in a "cuckoo hashing" scheme that sets up
// hash tables for static data.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hungarian.h"
#include "cuckoo.h"

#define INF (0x7FFFFFFF)
#define BIG (0x10000000)
#define verbose (0)

#define hungarian_test_alloc(X)                              \
  do { if ((void *)(X) == NULL)                              \
       printf("Out of memory in %s, (%s, line %d).\n",       \
              __FUNCTION__, __FILE__, __LINE__); } while (0)

void hungarian_print_matrix(int** C, int rows, int cols) {
  int i,j;
  fprintf(stderr , "\n");
  for(i=0; i<rows; i++) {
    printf(" [");
    for(j=0; j<cols; j++)
      printf("%3d ",C[i][j]==BIG ? -1 : C[i][j]);
    printf("]\n");
  }
  printf("\n");
}

void hungarian_print_byte_matrix(char** C, int rows, int cols) {
  int i,j;
  fprintf(stderr , "\n");
  for(i=0; i<rows; i++) {
    printf(" [");
    for(j=0; j<cols; j++)
      printf("%d ",C[i][j]);
    printf("]\n");
  }
  printf("\n");
}

void hungarian_print_assignment(hungarian_problem_t* p) {
  hungarian_print_byte_matrix(p->assignment, p->num_rows, p->num_cols) ;
}

void hungarian_print_costmatrix(hungarian_problem_t* p) {
  hungarian_print_matrix(p->cost, p->num_rows, p->num_cols) ;
}

void hungarian_print_status(hungarian_problem_t* p) {
  fprintf(stderr,"cost:\n");
  hungarian_print_costmatrix(p);
  fprintf(stderr,"assignment:\n");
  hungarian_print_assignment(p);
}

int hungarian_imax(int a, int b) {
  return (a<b)?b:a;
}

int hungarian_init(hungarian_problem_t* p, int** cost_matrix,
                   int rows, int cols, int mode) {

  int i,j, org_cols, org_rows;
  int max_cost;
  max_cost = 0;
  
  org_cols = cols;
  org_rows = rows;

  // is the number of cols  not equal to number of rows ? 
  // if yes, expand with 0-cols / 0-cols
  rows = hungarian_imax(cols, rows);
  cols = rows;
  
  p->num_rows = rows;
  p->num_cols = cols;

  p->cost = (int**)calloc(rows,sizeof(int*));
  hungarian_test_alloc(p->cost);
  p->assignment = (char**)calloc(rows,sizeof(char*));
  hungarian_test_alloc(p->assignment);

  for(i=0; i<p->num_rows; i++) {
    p->cost[i] = (int*)calloc(cols,sizeof(int));
    hungarian_test_alloc(p->cost[i]);
    p->assignment[i] = (char*)calloc(cols,sizeof(char));
    hungarian_test_alloc(p->assignment[i]);
    for(j=0; j<p->num_cols; j++) {
      p->cost[i][j] =  (i < org_rows && j < org_cols) ? cost_matrix[i][j] : 0;
      p->assignment[i][j] = HUNGARIAN_NOT_ASSIGNED;

      if (max_cost < p->cost[i][j])
	max_cost = p->cost[i][j];
    }
  }


  if (mode == HUNGARIAN_MODE_MAXIMIZE_UTIL) {
    for(i=0; i<p->num_rows; i++) {
      for(j=0; j<p->num_cols; j++) {
	p->cost[i][j] =  max_cost - p->cost[i][j];
      }
    }
  }
  else if (mode == HUNGARIAN_MODE_MINIMIZE_COST) {
    // nothing to do
  }
  else 
    fprintf(stderr,"%s: unknown mode. Mode was set to HUNGARIAN_MODE_MINIMIZE_COST !\n", __FUNCTION__);
  
  return rows;
}


void hungarian_free(hungarian_problem_t* p) {
  int i;
  for(i=0; i<p->num_rows; i++) {
    free(p->cost[i]);
    free(p->assignment[i]);
  }
  free(p->cost);
  free(p->assignment);
  p->cost = NULL;
  p->assignment = NULL;
}



void hungarian_solve(hungarian_problem_t* p)
{
  int i, j, m, n, k, l, s, t, q, unmatched, cost;
  int* col_mate;
  int* row_mate;
  int* parent_row;
  int* unchosen_row;
  int* row_dec;
  int* col_inc;
  int* slack;
  int* slack_row;

  cost=0;
  m =p->num_rows;
  n =p->num_cols;

  col_mate = (int*)calloc(p->num_rows,sizeof(int));
  hungarian_test_alloc(col_mate);
  unchosen_row = (int*)calloc(p->num_rows,sizeof(int));
  hungarian_test_alloc(unchosen_row);
  row_dec  = (int*)calloc(p->num_rows,sizeof(int));
  hungarian_test_alloc(row_dec);
  slack_row  = (int*)calloc(p->num_rows,sizeof(int));
  hungarian_test_alloc(slack_row);

  row_mate = (int*)calloc(p->num_cols,sizeof(int));
  hungarian_test_alloc(row_mate);
  parent_row = (int*)calloc(p->num_cols,sizeof(int));
  hungarian_test_alloc(parent_row);
  col_inc = (int*)calloc(p->num_cols,sizeof(int));
  hungarian_test_alloc(col_inc);
  slack = (int*)calloc(p->num_cols,sizeof(int));
  hungarian_test_alloc(slack);

  for (i=0;i<p->num_rows;i++) {
    col_mate[i]=0;
    unchosen_row[i]=0;
    row_dec[i]=0;
    slack_row[i]=0;
  }
  for (j=0;j<p->num_cols;j++) {
    row_mate[j]=0;
    parent_row[j] = 0;
    col_inc[j]=0;
    slack[j]=0;
  }

  for (i=0;i<p->num_rows;++i)
    for (j=0;j<p->num_cols;++j)
      p->assignment[i][j]=HUNGARIAN_NOT_ASSIGNED;

  // Begin subtract column minima in order to start with lots of zeroes 12
  if (verbose)
    printf("Using heuristic\n");
  for (l=0;l<n;l++)
    {
      s=p->cost[0][l];
      for (k=1;k<m;k++) 
	if (p->cost[k][l]<s)
	  s=p->cost[k][l];
      cost+=s;
      if (s!=0)
  // I might like to leave entries that are INF unchanged here?
	for (k=0;k<m;k++)
	  p->cost[k][l]-=s;
    }
  // End subtract column minima in order to start with lots of zeroes 12

  // Begin initial state 16
  t=0;
  for (l=0;l<n;l++)
    {
      row_mate[l]= -1;
      parent_row[l]= -1;
      col_inc[l]=0;
      slack[l]=INF;
    }
  for (k=0;k<m;k++)
    {
      s=p->cost[k][0];
      for (l=1;l<n;l++)
	if (p->cost[k][l]<s)
	  s=p->cost[k][l];
      row_dec[k]=s;
      for (l=0;l<n;l++)
	if (s==p->cost[k][l] && row_mate[l]<0)
	  {
	    col_mate[k]=l;
	    row_mate[l]=k;
	    if (verbose)
	      printf("matching col %d==row %d\n",l,k);
	    goto row_done;
	  }
      col_mate[k]= -1;
      if (verbose)
	printf("node %d: unmatched row %d\n",t,k);
      unchosen_row[t++]=k;
    row_done:
      ;
    }
  // End initial state 16
 
  // Begin Hungarian algorithm 18
  if (t==0)
    goto done;
  unmatched=t;
  while (1)
    {
      if (verbose)
	printf("Matched %d rows.\n",m-t);
      q=0;
      while (1)
	{
	  while (q<t)
	    {
	      // Begin explore node q of the forest 19
	      {
		k=unchosen_row[q];
		s=row_dec[k];
		for (l=0;l<n;l++)
		  if (slack[l])
		    {
		      int del;
		      del=p->cost[k][l]-s+col_inc[l];
		      if (del<slack[l])
			{
			  if (del==0)
			    {
			      if (row_mate[l]<0)
				goto breakthru;
			      slack[l]=0;
			      parent_row[l]=k;
			      if (verbose)
				printf("node %d: row %d==col %d--row %d\n",
				       t,row_mate[l],l,k);
			      unchosen_row[t++]=row_mate[l];
			    }
			  else
			    {
			      slack[l]=del;
			      slack_row[l]=k;
			    }
			}
		    }
	      }
	      // End explore node q of the forest 19
	      q++;
	    }
 
	  // Begin introduce a new zero into the matrix 21
	  s=INF;
	  for (l=0;l<n;l++)
	    if (slack[l] && slack[l]<s)
	      s=slack[l];
	  for (q=0;q<t;q++)
	    row_dec[unchosen_row[q]]+=s;
	  for (l=0;l<n;l++)
	    if (slack[l])
	      {
		slack[l]-=s;
		if (slack[l]==0)
		  {
		    // Begin look at a new zero 22
		    k=slack_row[l];
		    if (verbose)
		      printf(
			     "Decreasing uncovered elements by %d produces zero at [%d,%d]\n",
			     s,k,l);
		    if (row_mate[l]<0)
		      {
			for (j=l+1;j<n;j++)
			  if (slack[j]==0)
			    col_inc[j]+=s;
			goto breakthru;
		      }
		    else
		      {
			parent_row[l]=k;
			if (verbose)
			  printf("node %d: row %d==col %d--row %d\n",t,row_mate[l],l,k);
			unchosen_row[t++]=row_mate[l];
		      }
		    // End look at a new zero 22
		  }
	      }
	    else
	      col_inc[l]+=s;
	  // End introduce a new zero into the matrix 21
	}
    breakthru:
      // Begin update the matching 20
      if (verbose)
	printf("Breakthrough at node %d of %d!\n",q,t);
      while (1)
	{
	  j=col_mate[k];
	  col_mate[k]=l;
	  row_mate[l]=k;
	  if (verbose)
	    printf("rematching col %d==row %d\n",l,k);
	  if (j<0)
	    break;
	  k=parent_row[j];
	  l=j;
	}
      // End update the matching 20
      if (--unmatched==0)
	goto done;
      // Begin get ready for another stage 17
      t=0;
      for (l=0;l<n;l++)
	{
	  parent_row[l]= -1;
	  slack[l]=INF;
	}
      for (k=0;k<m;k++)
	if (col_mate[k]<0)
	  {
	    if (verbose)
	      printf("node %d: unmatched row %d\n",t,k);
	    unchosen_row[t++]=k;
	  }
      // End get ready for another stage 17
    }
 done:

  // Begin doublecheck the solution 23
  for (k=0;k<m;k++)
    for (l=0;l<n;l++)
      if (p->cost[k][l]<row_dec[k]-col_inc[l])
      { printf("Error detected line %d\n", __LINE__);
	exit(0);
      }
  for (k=0;k<m;k++)
    {
      l=col_mate[k];
      if (l<0 || p->cost[k][l]!=row_dec[k]-col_inc[l])
      { printf("Error detected line %d\n", __LINE__);
	exit(0);
      }
    }
  k=0;
  for (l=0;l<n;l++)
    if (col_inc[l])
      k++;
  if (k>m)
  { printf("Error detected line %d\n", __LINE__);
    exit(0);
  }
  // End doublecheck the solution 23
  // End Hungarian algorithm 18

  for (i=0;i<m;++i)
    {
      p->assignment[i][col_mate[i]]=HUNGARIAN_ASSIGNED;
      /*TRACE("%d - %d\n", i, col_mate[i]);*/
    }
  for (k=0;k<m;++k)
    {
      for (l=0;l<n;++l)
	{
	  /*TRACE("%d ",p->cost[k][l]-row_dec[k]+col_inc[l]);*/
  // I might like to leave entries that are INF unchanged here?
	  p->cost[k][l]=p->cost[k][l]-row_dec[k]+col_inc[l];
	}
      /*TRACE("\n");*/
    }
  for (i=0;i<m;i++)
    cost+=row_dec[i];
  for (i=0;i<n;i++)
    cost-=col_inc[i];
  if (verbose)
    printf("Cost is %d\n",cost);


  free(slack);
  free(col_inc);
  free(parent_row);
  free(row_mate);
  free(slack_row);
  free(row_dec);
  free(unchosen_row);
  free(col_mate);
}


//////////////////////////////////////////////////////////////////////////
// what follows has been added by ACN... ... ...

// Now an adapter that takes my hashing problem and maps it onto the
// calls needed here. The input is a set of keys, a table size and two
// parameters that control details of the hashing. It then has the hash
// table it is tryng to create, which it fills in if it can find a perfect
// way to do so.

// This tries to insert all the keys in "items" into the hash-table "table"
// and it returns a non-zero result if it succeeds.

int **adjacency_matrix = NULL;

uint32_t hungarian_insert_all(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    uint32_t *table,
    int table_size,
    uint32_t modulus2,
    uint32_t offset2,
    uint32_t target_merit)
{
    int i, j, k, size;
    hungarian_problem_t p;
    adjacency_matrix = (int **)calloc(table_size, sizeof(int *));
    hungarian_test_alloc(adjacency_matrix);
    for (i=0; i<table_size; i++)
    {   adjacency_matrix[i] = (int *)calloc(item_count, sizeof(int));
        hungarian_test_alloc(adjacency_matrix[i]);
        for (j=0; j<item_count; j++)
          adjacency_matrix[i][j] = BIG;
    }
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        int imp = (*importance)(key);
        switch (imp)
        {
    default:
            adjacency_matrix[h1][i] = 0;
            adjacency_matrix[h2][i] = 1;
            adjacency_matrix[h3][i] = 2;
            break;
    case CUCKOO_IMPORTANT:
            adjacency_matrix[h1][i] = 0;
            adjacency_matrix[h2][i] = 10;
            break;
    case CUCKOO_VITAL:
            adjacency_matrix[h1][i] = 0;
            break;
        }
    }
    size = hungarian_init(&p,
                          adjacency_matrix,
                          table_size,
                          item_count,
                          HUNGARIAN_MODE_MINIMIZE_COST);
    hungarian_solve(&p);
// Next I will extract the assignment found and put it in my hash table.
// While I am about it I will collect some statistics.
    int nvital = 0;
    int nimportant1 = 0, nimportant2 = 0;
    int nstandard1 = 0, nstandard2 = 0, nstandard3 = 0;
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        int imp = (*importance)(key);
        switch (imp)
        {
    case CUCKOO_VITAL:
            if (p.assignment[h1][i])
            {   table[h1] = key;
                nvital++;
                break;
            }
            else return (uint32_t)(-1);
    case CUCKOO_IMPORTANT:
            if (p.assignment[h1][i])
            {   table[h1] = key;
                nimportant1++;
                break;
            }
            else if (p.assignment[h2][i])
            {   table[h2] = key;
                nimportant2++;
                break;
            }
            else return (uint32_t)(-1);
    case CUCKOO_STANDARD:
            if (p.assignment[h1][i])
            {   table[h1] = key;
                nstandard1++;
                break;
            }
            else if (p.assignment[h2][i])
            {   table[h2] = key;
                nstandard2++;
                break;
            }
            else if (p.assignment[h3][i])
            {   table[h3] = key;
                nstandard3++;
                break;
            }
            else return (uint32_t)(-1);
        }
    }
    double avimportant =
       (nimportant1+2.0*nimportant2)/(nimportant1+nimportant2);
    double avstandard =
       (nstandard1+2.0*nstandard2+3.0*nstandard3)/
       (nstandard1+nstandard2+nstandard3);
// I weight IMPORTANT things as 4 times as relevant as STANDARD ones when it
// comes to an eventual figure of merit.
    uint32_t merit = (uint32_t)(10000.0*(0.8*avimportant + 0.2*avstandard));
// But I will also compute an average that shows the expected number of
// probes if all keys are accessed with equal probability.
    double average =
       (nvital + nimportant1 + 2.0*nimportant2 +
        nstandard1 + 2.0*nstandard2 + 3.0*nstandard3) / item_count;
    if (merit < target_merit)
    {   printf("\ntable_size = %u modulus2 = %u offset2 = %u occupancy %.2f\n",
               table_size, modulus2, offset2,
               (100.0*item_count)/table_size);
        if (nvital != 0)
            printf("VITAL:     %u      1.0 average probes\n", nvital);
        if (nimportant1!=0 || nimportant2 != 0)
            printf("IMPORTANT: %u %u   %.2f average probes\n",
                nimportant1, nimportant2, avimportant);
        if (nstandard1!=0 || nstandard2 != 0)
            printf("STANDARD:  %u %u %u  %.2f average probes\n",
                nstandard1, nstandard2, nstandard3, avstandard);
        printf("Figure of merit = %u flat average = %.2f\n", merit, average);
    }
    hungarian_free(&p);
    for (i=0; i<table_size; i++)
        free(adjacency_matrix[i]);
    free(adjacency_matrix);
#if DEBUG
// Now in a spirit of neurosis I will check whether everything can be
// looked up happily...
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        if (key == table[h1] ||
            key == table[h2] ||
            key == table[h3]) continue;
        printf("Key %u/%x not found in table\n", key, key);
        printf("%u %u %u\n", table_size, modulus2, offset2);
        for (i=0; i<table_size; i++)
            printf("%u: %u\n", i, table[i]);
        exit(1);
    }
#endif
    return merit;
}

cuckoo_parameters hungarian_try_all_hash_functions(
    uint32_t *keys,
    int keycount,
    cuckoo_importance *importance,
    void *hash,
    int hash_item_size,
    int hashsize,
    cuckoo_set_key *set_key)
{
    int i;
    cuckoo_parameters r;
    uint32_t modulus2, offset2, merit;
    uint32_t best_merit = 0x7fffffff, best_modulus2 = 0, best_offset2 = 0;
    uint32_t *table = (uint32_t *)calloc(hashsize, sizeof(uint32_t));
    hungarian_test_alloc(table);
    for (modulus2 = 1; modulus2 < hashsize; modulus2++)
    {   for (offset2 = 0; modulus2+offset2 <= hashsize; offset2++)
        {   if ((merit = hungarian_insert_all(
                keys,
                keycount,
                importance,
                table,
                hashsize,
                modulus2,
                offset2,
                best_merit)) != (uint32_t)(-1))
            {   if (merit < best_merit)
                {   best_modulus2 = modulus2;
                    best_offset2 = offset2;
                    best_merit = merit;
// Each time I get a new best assignment I transcribe it into the main
// official hash-table.
                    for (i=0; i<hashsize; i++)
                        (*set_key)(hash_item_size*i+(char *)hash, table[i]);
                }
            }
        }
    }
    free(table);
    if (best_merit == 0x7fffffff)
    {   r.table_size = (uint32_t)(-1);
        r.modulus2 = r.offset2 = r.merit = 4;
        return r;
    }
    r.table_size = hashsize;
    r.modulus2 = best_modulus2;
    r.offset2 = best_offset2;
    r.merit = best_merit;
    return r;
}

#ifdef TEST

// The code here can be compiled with "TEST" predefined and that will
// set up a small test of its behaviour... and the code for the test can
// also serve as an illustration of how it could be used.

#define PROBSIZE 140
uint32_t keys[PROBSIZE];

#define MAXHASHSIZE 2000
uint32_t hash[MAXHASHSIZE];

int importance(uint32_t key)
{
// I will make around 14% of the keys "important", meaning that they
// have to be accessed in at most two probes. The rest can be allowed
// three probes.
    if ((key % 7) == 3) return CUCKOO_IMPORTANT;
    else return CUCKOO_STANDARD;
}

uint32_t get_key(void *p)
{
    return *(uint32_t *)p;
}

void set_key(void *p, uint32_t k)
{
    *(uint32_t *)p = k;
}

int main(int argc, char *argv[])
{
    int keycount = sizeof(keys)/sizeof(keys[0]);
// SLACK is used here to specify how many vacant slots can be left
// in the hash table.
#define SLACK 7
    int hashsize = keycount+SLACK;
    int i;
    uint32_t modulus2, offset2;
// I set up some (dummy) data to be inserted into the hash table. Just to
// provide something that can be used as an illustration I will use the
// Fibonacci sequence.
    {   uint32_t a = 1, b = 2, c;
        for (i=0; i<keycount; i++)
        {   keys[i] = a;
            c = a + b;
            a = b;
            b = c;
        }
    }
// The next call will systematically try all hash options based on
// what I call modulus2 and offset2, and return (if possible) a hash table
// that is filled so as to minimise the number of probes to retrieve data. It
// will view IMPORTANT data as higher priority.
    cuckoo_parameters r = hungarian_try_all_hash_functions(
        keys,
        keycount,
        importance,
        hash,
        sizeof(hash[0]),
        hashsize,
        set_key);
// It could be that if there is not enough SLACK that a placement is not
// possible, so in that case I will report that and quit.
    if (r.table_size == (uint32_t)(-1))
    {   printf("No solution found\n");
        exit(1);
    }
// Report the success I have had.
    printf("\nOK with size = %u modulus2 = %u offset2 = %u merit = %u\n",
           hashsize, r.modulus2, r.offset2, r.merit);
// Display everything every key and indicate which position it has ended up in
    for (i=0; i<keycount; i++)
    {   uint32_t key = keys[i];
        uint32_t h1 = key % hashsize;
// I access the hash table here using get_key to show how that is used
// in general, because although the tash table entried here are simple
// integers one could have structs with bitfield components or other
// messy schemes that need the abstraction of get_key to handle them
// safely.
        int p1 = get_key(sizeof(hash[0])*h1 + (char *)hash) == key;
        uint32_t h2 = key % r.modulus2 + r.offset2;
        int p2 = get_key(sizeof(hash[0])*h2 + (char *)hash) == key;
        uint32_t h3 = (h1 + h2) % hashsize;
        int p3 = get_key(sizeof(hash[0])*h3 + (char *)hash) == key;
// Each key and the three locations that the key could legally be placed.
        printf("%5u: %10u... %3u%s %3u%s %3u%s\n",
            i, key,
            h1, p1 ? "*" : " ",
            h2, p2 ? "*" : " ",
            h3, p3 ? "*" : " ");
        if (!p1 && !p2 && !p3)
        {   printf("No placement found for key %u\n", key);
            exit(1);
        }
    }
    printf("Done\n");
    return 0;
}

#endif // TEST

// end of hungarian.c
