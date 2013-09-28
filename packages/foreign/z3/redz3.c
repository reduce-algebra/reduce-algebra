/* ----------------------------------------------------------------------
   $Id$
   ----------------------------------------------------------------------
   (c) 2013 M. Kosta, T. Sturm
   ----------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <z3.h>
#include <inttypes.h>

static Z3_ast *Args = NULL;
static unsigned int Argn = 0; 
static unsigned int ArgsIdx = 0;

int64_t redz3_parse_smtlib2_string(int64_t ctx, const char *str) {
  return (int64_t)Z3_parse_smtlib2_string((Z3_context)ctx, (Z3_string)str, 0, 0, 0, 0, 0, 0);
}

void redz3_prin2Ast(int64_t ctx, int64_t ast) {
  printf("%s", Z3_ast_to_string((Z3_context)ctx, (Z3_ast)ast));
}

int64_t redz3_mkInt(int64_t ctx, int64_t v) {
  Z3_sort ty = Z3_mk_int_sort((Z3_context)ctx);
  return (int64_t)Z3_mk_int((Z3_context)ctx, (int)v, ty);
}

int64_t redz3_mkIntVar(int64_t ctx, const char * name) {
  Z3_sort ty = Z3_mk_int_sort((Z3_context)ctx);
  Z3_symbol s = Z3_mk_string_symbol((Z3_context)ctx, name);
  return (int64_t)Z3_mk_const((Z3_context)ctx, s, ty);
}

void redz3_initArgs(int32_t argn) {
  Args = (Z3_ast *)malloc(argn * sizeof(Z3_ast));
  Argn = (unsigned int)argn;
  ArgsIdx = 0;
}

void redz3_cleanupArgs(void) {
  if (Args == NULL) {
    fprintf(stderr, "WARNING: redz3_cleanupArgs called with uninitialized Args - ignoring\n");
    return;
  }
  free(Args);
  Args = NULL;
  Argn = 0;
  ArgsIdx = 0;
}

void redz3_pushToArgs(int64_t arg) {
  Args[ArgsIdx++] = (Z3_ast)arg;
}

int64_t redz3_mkAppWithArgs(int64_t ctx, const char *op) {
  // Arithmetic operators:
  if (strcmp(op, "plus") == 0)
    return (int64_t)Z3_mk_add((Z3_context)ctx, Argn, Args);
  if (strcmp(op, "minus") == 0) {
    if (Argn == 1) {
      return (int64_t)Z3_mk_unary_minus((Z3_context)ctx, Args[0]);
    }
    return (int64_t)Z3_mk_sub((Z3_context)ctx, Argn, Args);
  }
  if (strcmp(op, "times") == 0)
    return (int64_t)Z3_mk_mul((Z3_context)ctx, Argn, Args);
  if (strcmp(op, "mod") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: mod has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_mod((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "div") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: div has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_div((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "power") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: power has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_power((Z3_context)ctx, Args[0], Args[1]);
  }
  // Relations:
  if (strcmp(op, "neq") == 0)  // (distinct x y) is equivalent to (not (= x y))
    return (int64_t)Z3_mk_distinct((Z3_context)ctx, Argn, Args);
    //return (int64_t)Z3_mk_not((Z3_context)ctx, Z3_mk_eq((Z3_context)ctx, Args[0], Args[1]));
  if (strcmp(op, "equal") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: equal has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_eq((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "geq") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: geq has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_ge((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "leq") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: leq has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_le((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "greaterp") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: greaterp has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_gt((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "lessp") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: lessp has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_lt((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "cong") == 0) {
    if (Argn != 3) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: cong has to have exactly 3 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_eq((Z3_context)ctx, Args[1], Z3_mk_mod((Z3_context)ctx, Args[0], Args[2]));
  }
  if (strcmp(op, "ncong") == 0) {
    if (Argn != 3) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: ncong has to have exactly 3 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_not((Z3_context)ctx, Z3_mk_eq((Z3_context)ctx, Args[1], Z3_mk_mod((Z3_context)ctx, Args[0], Args[2])));
  }
  // Logical connectives:
  if (strcmp(op, "true") == 0) {
    if (Argn != 0) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: true has to have no arguments\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_true((Z3_context)ctx);
  }
  if (strcmp(op, "false") == 0) {
    if (Argn != 0) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: false has to have no arguments\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_false((Z3_context)ctx);
  }
  if (strcmp(op, "not") == 0) {
    if (Argn != 1) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: equiv has to have exactly 1 arg\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_not((Z3_context)ctx, Args[0]);
  }
  if (strcmp(op, "and") == 0)
    return (int64_t)Z3_mk_and((Z3_context)ctx, Argn, Args);
  if (strcmp(op, "or") == 0)
    return (int64_t)Z3_mk_or((Z3_context)ctx, Argn, Args);
  if (strcmp(op, "impl") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: impl has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_implies((Z3_context)ctx, Args[0], Args[1]);
  }
  if (strcmp(op, "equiv") == 0) {
    if (Argn != 2) {
      fprintf(stderr, "error in redz3_mkAppWithArgs: equiv has to have exactly 2 args\n", op);
      exit(1);
    }
    return (int64_t)Z3_mk_iff((Z3_context)ctx, Args[0], Args[1]);
  }
  fprintf(stderr, "error in redz3_mkAppWithArgs: unknown operator %s\n", op);
  exit(1);
}
