on comp;

on lessspace;

load_package smt;

on smtsilent;

lisp procedure setpchar(c);
   promptstring!* := "";

lisp savesystem("REDSMT", "rlsmt", '((smt)));

quit;
