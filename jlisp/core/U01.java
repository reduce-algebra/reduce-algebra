package uk.co.codemist.jlisp.core;

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                      A C Norman *
 *                            also contributions from Vijay Chauhan, 2002 *
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

// U01.java

// Each built-in function is created wrapped in a class
// that is derived from BuiltinFunction.

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.BigInteger;

class U01 extends Uxx
{
    public U01()
    {   builtins = new Object[][]
        {
            {"u01-sample",                  new U01_sampleFn()},
            {"addf",                        new J_addf()}
        };
        System.out.printf("Count on %s = %d%n", toString(), builtins.length); // @@@
    }


class U01_sampleFn extends BuiltinFunction
{
    public LispObject op0()
    {
        return Jlisp.nil;
    }
    public LispObject op1(LispObject arg1)
    {
        return arg1;
    }
    public LispObject op2(LispObject arg1, LispObject arg2) throws ResourceException
    {
        return arg1;
    }
    public LispObject opn(LispObject [] args) throws ResourceException
    {
        int n = args.length;
        if (n == 0) return Jlisp.nil;
        else return args[0];
    }
}

class J_addf extends BuiltinFunction
{

public LispObject op2(LispObject u_arg, LispObject v_arg) throws Exception
{
  if (!inited) initialiseMe();
  LispObject top_return = jnil;
  LispObject g0860 = jnil;
  LispObject g0862_loc = jnil;
  LispObject g0863_loc = jnil;
int goto_g0861 = 0;
for(;;)
{
switch(goto_g0861)
{
case 0:
  goto_g0861 += 1;
case 1:
  LispObject g0864 = jnil;
  LispObject g0865 = u_arg == jnil ? jtrue : jnil;
if (g0865 != jnil)
{
  g0863_loc = v_arg;
  goto_g0861 = 2;
  continue;
}
else
{
  LispObject g0866 = v_arg == jnil ? jtrue : jnil;
if (g0866 != jnil)
{
  g0863_loc = u_arg;
  goto_g0861 = 2;
  continue;
}
else
{
  LispObject g0867 = jnil;
  LispObject g0868 = u_arg.atom ? jtrue : jnil;
if (g0868 != jnil)
{
  g0867 = g0868;
}
else
{
  LispObject g0869 = u_arg.car;
  LispObject g0870 = g0869.atom ? jtrue : jnil;
if (g0870 != jnil)
{
  g0867 = g0870;
}
}
if (g0867 != jnil)
{
  LispObject g0872 = ((Symbol)g0871).fn.op2(u_arg, v_arg);
  g0863_loc = g0872;
  goto_g0861 = 2;
  continue;
}
else
{
  LispObject g0873 = jnil;
  LispObject g0874 = v_arg.atom ? jtrue : jnil;
if (g0874 != jnil)
{
  g0873 = g0874;
}
else
{
  LispObject g0875 = v_arg.car;
  LispObject g0876 = g0875.atom ? jtrue : jnil;
if (g0876 != jnil)
{
  g0873 = g0876;
}
}
if (g0873 != jnil)
{
  LispObject g0877 = ((Symbol)g0871).fn.op2(v_arg, u_arg);
  g0863_loc = g0877;
  goto_g0861 = 2;
  continue;
}
else
{
  LispObject g0878 = u_arg.car.car;
  LispObject g0879 = v_arg.car.car;
  LispObject g0880 = g0878.lispequals(g0879) ? jtrue : jnil;
if (g0880 != jnil)
{
  LispObject g0881 = u_arg.car.cdr;
  LispObject g0882 = v_arg.car.cdr;
  LispObject g0883 = this.op2(g0881, g0882);
  g0863_loc = g0883;
  LispObject g0884 = jnil;
  LispObject g0885 = g0863_loc == jnil ? jtrue : jnil;
  LispObject g0886 = g0885 == jnil ? jtrue : jnil;
if (g0886 != jnil)
{
  LispObject g0887 = u_arg.car.car;
  LispObject g0888 = new Cons(g0887, g0863_loc);
  LispObject g0889 = new Cons(g0888, g0862_loc);
  g0862_loc = g0889;
  g0884 = g0862_loc;
}
  LispObject g0890 = u_arg.cdr;
  u_arg = g0890;
  LispObject g0891 = v_arg.cdr;
  v_arg = g0891;
  LispObject g0892 = v_arg;
  g0864 = g0892;
}
else
{
  LispObject g0893 = u_arg.car.car;
  LispObject g0894 = v_arg.car.car;
  LispObject g0896 = ((Symbol)g0895).fn.op2(g0893, g0894);
if (g0896 != jnil)
{
  LispObject g0897 = u_arg.car;
  LispObject g0898 = new Cons(g0897, g0862_loc);
  g0862_loc = g0898;
  LispObject g0899 = u_arg.cdr;
  u_arg = g0899;
  LispObject g0900 = u_arg;
  g0864 = g0900;
}
else
{
  LispObject g0901 = v_arg.car;
  LispObject g0902 = new Cons(g0901, g0862_loc);
  g0862_loc = g0902;
  LispObject g0903 = v_arg.cdr;
  v_arg = g0903;
  LispObject g0904 = v_arg;
  g0864 = g0904;
}
}
}
}
}
}
  goto_g0861 = 1;
  continue;
case 2:
  LispObject g0905 = jnil;
int goto_g0906 = 0;
for(;;)
{
switch(goto_g0906)
{
case 0:
  goto_g0906 += 1;
case 1:
  LispObject g0907 = jnil;
  LispObject g0908 = g0862_loc == jnil ? jtrue : jnil;
if (g0908 != jnil)
{
  g0905 = jnil;
  goto_g0906 = 2;
  continue;
}
  LispObject g0909 = g0862_loc.cdr;
  u_arg = g0909;
  LispObject g0911 = ((Symbol)g0910).fn.op2(g0862_loc, g0863_loc);
  g0863_loc = g0862_loc;
  g0862_loc = u_arg;
  LispObject g0912 = g0862_loc;
  goto_g0906 = 1;
  continue;
case 2:
  break;
}
break;
}
  g0860 = g0863_loc;
  goto_g0861 = 3;
  continue;
case 3:
  break;
}
break;
}
  top_return = g0860;
  return top_return;
}

private void initialiseMe()
{
  g0871 = Symbol.intern("addd");
  g0913 = Symbol.intern("addf");
  g0895 = Symbol.intern("ordpp");
  g0910 = Symbol.intern("rplacd");
  jnil = Jlisp.nil;
  jtrue = Jlisp.lispTrue;
  inited = true;
}

private LispObject jnil = null;
private LispObject jtrue = null;
private LispObject g0871 = null;
private LispObject g0913 = null;
private LispObject g0895 = null;
private LispObject g0910 = null;
}




}

// end of U01.java

