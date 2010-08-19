/*
 * mpipack.c
 *
 * Packing stuff into buffers for cross-PE communication 
 */
 
/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/



/* Signature: 3a7dc850 24-May-2008 */


#ifndef header_mpipack_h
#define header_mpipack_h


/* Code to pack a Lisp cons-structure into a linear buffer and retrieve it. */

/* These are the calls to do it; think of them as
 *       void pack_object(Lisp_Object a);
 *   and Lisp_Object unpack_object(); 
 */

#define pack_object(a) (mpi_pack_buffer = 0, \
			mpi_pack_position = 0, \
			mpi_pack_size = 0, \
			pack_cell(a) )

/* Once a message has been packed, it may be sent using mpi_pack_buffer and 
 * mpi_pack_position as the "buf" and "count" fields, and MPI_PACKED as the
 * Datatype.
 */


/* mpi_pack_buffer should be set to the recieve buffer before calling this. */
#define unpack_object() (mpi_pack_position = 0, unpack_cell())




/* There must be a buffer to put them in.
 * It will grow by MPI_BUFFER_BLOCK bytes at a time, as needed.
 */
static char* mpi_pack_buffer = 0;
static int mpi_pack_size = 0;
#define MPI_BUFFER_BLOCK 1024

/* position marker for MPI_(Un)Pack */
static int mpi_pack_position = 0;


/* THE REST OF THIS FILE IS PRIVATE */

/* Function to check the size of the buffer, and grow it if necessary.
 * check_buffer(n) will make sure that there are n free bytes in the buffer.
 */
static void default_check_buffer(int n)
{
  if (mpi_pack_size - mpi_pack_position < n){
    mpi_pack_size += MPI_BUFFER_BLOCK;
    mpi_pack_buffer = (char*)realloc( mpi_pack_buffer, mpi_pack_size);
    if (mpi_pack_buffer == 0) aerror0("Not enough memory for MPI buffer.");
  }
}
static char* mpi_buffer_bottom;
static int mpi_pack_offset;
static int mpi_real_size;
static void scatter_check_buffer(int n)
{
  if (mpi_real_size - ( (mpi_pack_buffer - mpi_buffer_bottom) + 
			mpi_pack_position ) < n) {
    mpi_real_size += MPI_BUFFER_BLOCK;
    mpi_pack_size += MPI_BUFFER_BLOCK;
    mpi_buffer_bottom = (char*)realloc( mpi_buffer_bottom, mpi_real_size);
    if (mpi_buffer_bottom == 0) aerror0("Not enough memory for MPI buffer.");
    mpi_pack_buffer = mpi_buffer_bottom + mpi_pack_offset;
  }
}


typedef void buffptr(int);
static buffptr *check_buffer = default_check_buffer;

/* MPI insists on using pointers everywhere, so here are things to point at. */
static char mpi_packing_symbols[] = {' ', '(', ')', '.', ','};
static Lisp_Object mpi_pack_number;
static char mpi_pack_char;

/* The MPI function calls for packing */

/* Think of this as void pack_32bit(Lisp_Object),but it actually returns int */
/* The name is to remind one that the size is fixed for now. It would be
 * better to conditionally define a type of either MPI_LONG or MPI_LONG_LONG
 * depending on the size of Lisp objects. This may happen eventually.
 */
#define pack_32bit(n) (check_buffer(4), \
		       MPI_Pack(&(n), 1, MPI_UNSIGNED_LONG, \
				mpi_pack_buffer, mpi_pack_size, \
				&mpi_pack_position, MPI_COMM_WORLD) )

/* The functions to flatten the list structures, according to a simple grammar*/
static void pack_list(Lisp_Object a); 			      
static void pack_cell(Lisp_Object a);
static void pack_atom(Lisp_Object a)
{
  if (is_fixnum(a)) pack_32bit(a);
  else if (is_bfloat(a)) {
    Header* h = &flthdr(a);
    if (type_of_header(*h) == TYPE_DOUBLE_FLOAT){
      pack_32bit(*h);
      check_buffer(sizeof(double));
      MPI_Pack( double_float(addr(h)), 1, MPI_DOUBLE, 
		mpi_pack_buffer, mpi_pack_size, 
		&mpi_pack_position, MPI_COMM_WORLD);
    }
    else err_printf("Unsupported float type %x\n",type_of_header(*h));
  }
  else if (is_numbers(a)) {
    Header* h = &numhdr(a);
    int size = length_of_header(*h) - sizeof(Header);
    if (type_of_header(*h) == TYPE_BIGNUM){
      pack_32bit(*h);
      /* Bignums are arrays of 32-bit things; we'll have to pack them
	 as such to avoid byte-ordering problems. */
      check_buffer(size);
      MPI_Pack(h+1, size >> 2, MPI_UNSIGNED_LONG, 
	       mpi_pack_buffer, mpi_pack_size,  &mpi_pack_position, 
	       MPI_COMM_WORLD);
    }
    else err_printf("Unsupported number type %x\n",type_of_header(*h));
  }
  else if (is_vector(a)) {
    Header* h = &vechdr(a);
    switch(type_of_header(*h)){
    case TYPE_STRING:
      pack_32bit(*h);
      {
	int size = length_of_header(*h) - sizeof(Header);
	check_buffer(size);
	MPI_Pack(h+1, size, MPI_CHAR, 
		 mpi_pack_buffer, mpi_pack_size, 
		 &mpi_pack_position, MPI_COMM_WORLD);
      }
      break;
    case TYPE_SIMPLE_VEC: case TYPE_ARRAY: case TYPE_STRUCTURE:
      pack_32bit(*h);
      {
	int i;
	for (i = 0; i < (length_of_header(*h)>>2) - 1; ++i)
	  pack_cell(elt(a,i));
      }
      break;
    default:
      err_printf("Unsupported vector type %x\n",type_of_header(*h));
    }
  }
  else if (is_symbol(a)) {
    Symbol_Head* h = (Symbol_Head*)( (char*)a-TAG_SYMBOL);
    Header My_Head = TYPE_SYMBOL;
    pack_32bit(My_Head);
    pack_atom(h->pname); /* This is a string. */
  }

  else err_printf("Unsupported type %d\n",a & TAG_BITS);
}

/* again, think of   void pack_xxxx(void); (but actually returning int) */
#define pack_space() ( check_buffer(1), \
                       MPI_Pack(mpi_packing_symbols, 1, MPI_CHAR, \
			        mpi_pack_buffer, mpi_pack_size, \
			        &mpi_pack_position, MPI_COMM_WORLD) )
#define pack_open()  ( check_buffer(1), \
                       MPI_Pack(mpi_packing_symbols+1, 1, MPI_CHAR, \
			        mpi_pack_buffer, mpi_pack_size, \
			        &mpi_pack_position, MPI_COMM_WORLD) )
#define pack_close() ( check_buffer(1), \
                       MPI_Pack(mpi_packing_symbols+2, 1, MPI_CHAR, \
			        mpi_pack_buffer, mpi_pack_size, \
			        &mpi_pack_position, MPI_COMM_WORLD) )
#define pack_dot()   ( check_buffer(1), \
                       MPI_Pack(mpi_packing_symbols+3, 1, MPI_CHAR, \
			        mpi_pack_buffer, mpi_pack_size, \
			        &mpi_pack_position, MPI_COMM_WORLD) )
#define pack_comma() ( check_buffer(1), \
                       MPI_Pack(mpi_packing_symbols+4, 1, MPI_CHAR, \
			        mpi_pack_buffer, mpi_pack_size, \
			        &mpi_pack_position, MPI_COMM_WORLD) )
     
static void pack_cell(Lisp_Object a)
{
  /* In Common mode, consp needs nil defined. I don't want to
   * clutter the stack with unnecessary variables, so I don't
   * define it in CSL mode.
   */
#ifdef COMMON
  Lisp_Object nil = C_nil;
#endif
  if (consp(a)) pack_open(), pack_cell(qcar(a)), pack_list(qcdr(a));
  else pack_space(), pack_atom(a);
}

static void pack_list(Lisp_Object a)
{
#ifdef COMMON
  Lisp_Object nil = C_nil;
#endif
  if (consp(a)) pack_comma(), pack_cell(qcar(a)), pack_list(qcdr(a));
  else if (a == C_nil) pack_close();
  else pack_dot(), pack_atom(a);
}

/* Now unpacking... */
/* The MPI calls */
/* Think of these as   char unpack_char(); Lisp_Object unpack_32bit(); */ 
#define unpack_char() (MPI_Unpack(mpi_pack_buffer, mpi_pack_size, \
				  &mpi_pack_position, &mpi_pack_char, 1, \
				  MPI_CHAR, MPI_COMM_WORLD), \
		       mpi_pack_char)

#define unpack_32bit() (MPI_Unpack(mpi_pack_buffer, mpi_pack_size, \
				   &mpi_pack_position, &mpi_pack_number, 1, \
				   MPI_UNSIGNED_LONG, MPI_COMM_WORLD), \
			mpi_pack_number)			   

/* The functions to parse the linear buffer */ 
static Lisp_Object unpack_list(void);
static Lisp_Object unpack_cell(void);
static Lisp_Object unpack_atom()
{ 
  Lisp_Object a = unpack_32bit();
  if (is_fixnum(a)) return a;
  
  switch (type_of_header(a)){
    int size;
  case TYPE_DOUBLE_FLOAT:
    size = length_of_header(a);
    a = getvector(TAG_BOXFLOAT,TYPE_DOUBLE_FLOAT,size);
    MPI_Unpack(mpi_pack_buffer, mpi_pack_size, &mpi_pack_position,
               double_float_addr(a),
	       1, MPI_DOUBLE, MPI_COMM_WORLD);
    return a;

  case TYPE_BIGNUM:
    size = length_of_header(a);
    a = getvector(TAG_NUMBERS,type_of_header(a),size);
    MPI_Unpack(mpi_pack_buffer,mpi_pack_size,&mpi_pack_position,
	       (char*)a - TAG_NUMBERS + CELL,
	       (size - sizeof(Header))>>2, MPI_UNSIGNED_LONG, MPI_COMM_WORLD);
    return a;
  
  case TYPE_STRING:
    size = length_of_header(a);
    a = getvector(TAG_VECTOR,TYPE_STRING,size);
    MPI_Unpack(mpi_pack_buffer, mpi_pack_size, &mpi_pack_position,
	       (char*)a - TAG_VECTOR + CELL,
	       size - sizeof(Header), MPI_CHAR, MPI_COMM_WORLD);
    return a;
  
  case TYPE_SIMPLE_VEC: case TYPE_ARRAY: case TYPE_STRUCTURE:
    size = length_of_header(a);
    push(getvector(TAG_VECTOR,type_of_header(a),size));
    {
      int i; 
      for (i=0; i<(size>>2)-1; ++i) elt(*stack,i) = unpack_cell();
      if (!(i&1)) elt(*stack,i) = C_nil;
    }
    return my_pop();

  case TYPE_SYMBOL:
    {
      Lisp_Object nil = C_nil;
      a = unpack_atom();  /* Name in a string */
      return iintern(a, length_of_header(vechdr(a))-CELL, CP, 0);
    }   
  default:
    err_printf("Unknown header type %d", type_of_header(a));
  }
}


static Lisp_Object unpack_cell(void)
{
  switch (unpack_char()){
  case ' ': return unpack_atom();
  case '(': return unpack_list();
  default : {err_printf("Syntax error in message.\n"); return C_nil;}
  }
}

static Lisp_Object unpack_list(void)
{
  push(unpack_cell());
  switch (unpack_char()){
  case ')': return cons(my_pop(),C_nil);
  case '.': {Lisp_Object tail = unpack_atom(); return cons(my_pop(), tail);}
  case ',': {Lisp_Object tail = unpack_list(); return cons(my_pop(), tail);}
  default : {err_printf("Syntax error in message.\n"); return (my_pop());}
  }
}

#endif


/* end of mpipack.c */


