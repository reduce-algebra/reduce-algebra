/* FXReduceMenus.cpp                    Copyright (C) 2014 Codemist Ltd */


/* $Id$ */


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



// Menu items for use with Reduce
// The format is that each line has a series of fields separated by "@".
// The ordering is:
//
//  (1)  The top-level menu to be used, e.g. "Calculus" or "algebra" etc.
//  (2)  The name of the menu entry within that drop-down menu, eg "limit".
//  (3)  Text to appear as the heading in the dialog box.
//  (4)  A number n being the number of fields in the dialog box that will
//       be displayed (as a digit character).
//  (5) to (5+n-1) Initial contents to be placed in each field in the dialog
//      box. For instance for indefinite integration there will be two fields
//     and they will have initial contents "ws" and "x" so that the default
//     behaviour will be to integrate the current expression with respect to x.
//     Each field will be prefixed with its label and then a ":", so for
//     instance there might be
//     menu@submenu@dialog-box-heading@1@label:default@reduce-code@@
//  (5+n) A template for the Reduce commands or expression to be used. This
//     can include use of "$1", "$2" etc to refer to the text from each line
//     that had been left in the dialog box.
// All bets are off if the user leaves malformed text in any box - such as
// mismatched parentheses, oddly places escape characters or basically
// anything that means that simple textual substitution into the template
// will cause trouble.

const char *reduceMenus[] =
{
    "Calculus@differentiate@differentiate@"
        "3@expression:ws@variable:x@n-times:1@"
        "df($1,$2,$3);",
    "Calculus@integrate@indefinite integration@"
        "2@expression:ws@variable:x@"
        "int($1,$2);",
    "Calculus@definite integration@definite integration@"
        "4@expression:ws@variable:x@from:0@to:1@"
        "int($1,$2,$3,$4);",
    "Calculus@numeric integrate@numeric integration@"
        "4@expression:ws@variable:x@from:0.0@to:1.0@"
        "load_package numeric; num_int($1,$2=($3 .. $4));",
    "Calculus@differential equation@"
        "ordinary differential equation@"
        "3@equation:df(y,x)=y@dep var:y@indep var:x@"
        "odesolve($1,$2,$3);",
    "Calculus@differential equation (numeric)@"
        "ordinary differential equation (numeric)@"
        "6@equation:ws@def var:y@initial cond:1@indep var:x@from:0@to:1@"
        "load_package numeric; num_odesolve($1,$2=$3,$4=($5 .. $6));",
    "Calculus@stationary value@stationary value@"
        "2@expression:ws@variable:x@"
        "solve(df($1,$2)=0,$2)",
    "Calculus@evaluate at@evaluate at@"
        "3@expression:ws@variable:x@value:0@"
        "sub($2=$3,$1);",
    "Calculus@limit@limit@"
        "3@expression:ws@variable:x@value:infinity@"
        "limit($1,$2,$3);",
    "Calculus@Taylor Series@Taylor Series (taylor)@"
        "4@expression:ws@variable:x@about:0@order:7@"
        "taylor($1,$2,$3,$4);",
    "Calculus@Power Series@Power Series (tps)@"
        "3@expression:ws@variable:x@about:0@"
        "load_package tps; ps($1,$2,$3);",
    "Calculus@Laplace transform@Laplace transform@"
        "3@expression:ws@current var:s@new var:t@"
        "load_package laplace; laplace($1,$2,$3);",
    "Calculus@Inverse Laplace transform@Inverse Laplace transform@"
        "3@expression:ws@current var:t@new var:s@"
        "load_package laplace; invlap($1,$2,$3);",
    "Calculus@Z transform@Z transform@"
        "3@exprn in terms of n:ws@n:n@var:z@"
        "load_package ztrans; ztrans($1,$2,$3);",

// End of Calculus section

    "Algebra@substitute@substitute@"
        "3@expression:ws@var:x@replacement:0@"
        "sub($2=$3,$1);",
    "Algebra@solve@solve@"
        "2@equation:ws@var:x@"
        "solve({$1},{$2});",
    "Algebra@numeric solution to 1 equation@numeric solution to 1 equation@"
        "3@equation:ws@val:x@guess:1.0@"
        "load_package numeric; num_solve($1,$2=$3);",
    "Algebra@real roots of polynomial@real roots of polynomial@"
        "1@equation:ws@"
        "realroots($1);",
    "Algebra@factorize@factorize@"
        "1@polynomial:ws@"
        "factorize($1);",
    "Algebra@greatest common divisor@greatest common divisor@"
        "2@p1:ws@p2:1@"
        "gcd($1,$2);",
    "Algebra@least common multiplier@least common multiplier@"
        "2@p1:ws@p2:1@"
        "lcm($1,$2);",
    "Algebra@degree@degree@"
        "2@poly:ws$var:x$"
        "deg($1,$2);",
    "Algebra@coefficient@coefficient@"
        "2@poly:ws$var:x$"
        "coeff($1,$2);",
    "Algebra@partial fractions@partial fractions@"
        "2@exprn:ws@var:x@"
        "pf($1,$2);",
    "Algebra@continued fraction@continued fraction@"
        "3@exprn:ws@var:x@terms:5@"
        "load_package rataprx;cfrac($1,$2,$3);",
    "Algebra@numeric continued fraction@numeric continued fraction@"
        "2@number:ws@terms:5@"
        "load_package rataprx;cfrac($1,$2);",
    "Algebra@sin(x)^2 -> sin(2x)@sin(x)^2 -> sin(2x)@"
        "1@exprn:ws@"
        "trigsimp($1,combine);",
    "Algebra@sin(2x) -> sin(x)^2@sin(2x) -> sin(x)^2@"
        "1@exprn:ws@"
        "trigsimp($1,expand);",
    "Algebra@trig -> exponential@trig -> exponential@"
        "1@exprn:ws@"
        "trigsimp($1,expon);",
    "Algebra@exponential -> trig@exponential -> trig@"
        "1@exprn:ws@"
        "trigsimp($1,trig);",
    "Algebra@sum series@sum series c@"
        "3@expr:ws@var:$i@nterms:5@"
        "sum($1,$2,$3);",

// End of Algebra section

    "Matrix@transpose@transpose@"
        "1@mat:ws@"
        "tp($1);",
    "Matrix@inverse@inverse@"
        "1@mat:ws@"
        "($1)^(-1);",
    "Matrix@rank@rank@"
        "1@mat:ws@"
        "rank($1);",
    "Matrix@trace@trace@"
        "1@mat:ws@"
        "trace($1);",
    "Matrix@nullspace@nullspace@"
        "1@mat:ws@"
        "nullspace($1);",
    "Matrix@determinant@determinant@"
        "1@mat:ws@"
        "det($1);",
    "Matrix@eigenvectors and values@eigenvectors and values@"
        "2@mat:ws@var:lam@"
        "mateigen($1,$2);",

// End of Matrix section

    "Graphs@plot@plot@"
        "4@function:ws@var:x@from:0@to:5@"
        "plot($1,$2=($3 .. $4));",
    "Graphs@3D plot@3D plot@"
        "7@function:ws@var1:x@from:0@to:5@var2:y@from:0@to:5@"
        "plot($1,$2=($3 .. $4),$5=($6 .. $7));",

// End of Graphs section

    (const char *)0
};

// end of FXReduceMenus.cpp
