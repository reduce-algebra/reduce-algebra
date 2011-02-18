%
% vjacn.red
%


%
% NOTE VERY WELL
%
% This compiler, which maps Lisp into Java bytecodes, is NOT certified as
% perfect and NOT guaranteed complete. It is NOT integrated in with the
% bulk of Jlisp and certainly not with the way Jlisp can build Reduce. But it
% may well be very valuable as a starting point (and quite close to a
% completion point, since much of it works quite well!) for somebody who
% wants to put effort into getting it fully alive.
%            Arthur Norman. February 2011


% Author: Vijay Chauhan and Arthur Norman          Copyright 2002-2011

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%



lisp;


on echo;

% The following gives the Java internal codings for all the
% JVM opcodes.

deflist('(
    (NOP             0x00)
    (ACONST_NULL     0x01)
    (ICONST_M1       0x02)
    (ICONST_0        0x03)
    (ICONST_1        0x04)
    (ICONST_2        0x05)
    (ICONST_3        0x06)
    (ICONST_4        0x07)
    (ICONST_5        0x08)
    (LCONST_0        0x09)
    (LCONST_1        0x0a)
    (FCONST_0        0x0b)
    (FCONST_1        0x0c)
    (FCONST_2        0x0d)
    (DCONST_0        0x0e)
    (DCONST_1        0x0f)
    (BIPUSH          0x10)
    (SIPUSH          0x11)
    (LDC             0x12)
    (LDC_W           0x13)
    (LDC2_W          0x14)
    (ILOAD           0x15)
    (LLOAD           0x16)
    (FLOAD           0x17)
    (DLOAD           0x18)
    (ALOAD           0x19)
    (ILOAD_0         0x1a)
    (ILOAD_1         0x1b)
    (ILOAD_2         0x1c)
    (ILOAD_3         0x1d)
    (LLOAD_0         0x1e)
    (LLOAD_1         0x1f)
    (LLOAD_2         0x20)
    (LLOAD_3         0x21)
    (FLOAD_0         0x22)
    (FLOAD_1         0x23)
    (FLOAD_2         0x24)
    (FLOAD_3         0x25)
    (DLOAD_0         0x26)
    (DLOAD_1         0x27)
    (DLOAD_2         0x28)
    (DLOAD_3         0x29)
    (ALOAD_0         0x2a)
    (ALOAD_1         0x2b)
    (ALOAD_2         0x2c)
    (ALOAD_3         0x2d)
    (IALOAD          0x2e)
    (LALOAD          0x2f)
    (FALOAD          0x30)
    (DALOAD          0x31)
    (AALOAD          0x32)
    (BALOAD          0x33)
    (CALOAD          0x34)
    (SALOAD          0x35)
    (ISTORE          0x36)
    (LSTORE          0x37)
    (FSTORE          0x38)
    (DSTORE          0x39)
    (ASTORE          0x3a)
    (ISTORE_0        0x3b)
    (ISTORE_1        0x3c)
    (ISTORE_2        0x3d)
    (ISTORE_3        0x3e)
    (LSTORE_0        0x3f)
    (LSTORE_1        0x40)
    (LSTORE_2        0x41)
    (LSTORE_3        0x42)
    (FSTORE_0        0x43)
    (FSTORE_1        0x44)
    (FSTORE_2        0x45)
    (FSTORE_3        0x46)
    (DSTORE_0        0x47)
    (DSTORE_1        0x48)
    (DSTORE_2        0x49)
    (DSTORE_3        0x4a)
    (ASTORE_0        0x4b)
    (ASTORE_1        0x4c)
    (ASTORE_2        0x4d)
    (ASTORE_3        0x4e)
    (IASTORE         0x4f)
    (LASTORE         0x50)
    (FASTORE         0x51)
    (DASTORE         0x52)
    (AASTORE         0x53)
    (BASTORE         0x54)
    (CASTORE         0x55)
    (SASTORE         0x56)
    (POP             0x57)
    (POP2            0x58)
    (DUP             0x59)
    (DUP_X1          0x5a)
    (DUP_X2          0x5b)
    (DUP2            0x5c)
    (DUP2_X1         0x5d)
    (DUP2_X2         0x5e)
    (SWAP            0x5f)
    (IADD            0x60)
    (LADD            0x61)
    (FADD            0x62)
    (DADD            0x63)
    (ISUB            0x64)
    (LSUB            0x65)
    (FSUB            0x66)
    (DSUB            0x67)
    (IMUL            0x68)
    (LMUL            0x69)
    (FMUL            0x6a)
    (DMUL            0x6b)
    (IDIV            0x6c)
    (LDIV            0x6d)
    (FDIV            0x6e)
    (DDIV            0x6f)
    (IREM            0x70)
    (LREM            0x71)
    (FREM            0x72)
    (DREM            0x73)
    (INEG            0x74)
    (LNEG            0x75)
    (FNEG            0x76)
    (DNEG            0x77)
    (ISHL            0x78)
    (LSHL            0x79)
    (ISHR            0x7a)
    (LSHR            0x7b)
    (IUSHR           0x7c)
    (LUSHR           0x7d)
    (IAND            0x7e)
    (LAND            0x7f)
    (IOR             0x80)
    (LOR             0x81)
    (IXOR            0x82)
    (LXOR            0x83)
    (IINC            0x84)
    (I2L             0x85)
    (I2F             0x86)
    (I2D             0x87)
    (L2I             0x88)
    (L2F             0x89)
    (L2D             0x8a)
    (F2I             0x8b)
    (F2L             0x8c)
    (F2D             0x8d)
    (D2I             0x8e)
    (D2L             0x8f)
    (D2F             0x90)
    (I2B             0x91)
    (I2C             0x92)
    (I2S             0x93)
    (LCMP            0x94)
    (FCMPL           0x95)
    (FCMPG           0x96)
    (DCMPL           0x97)
    (DCMPG           0x98)
    (IFEQ            0x99)
    (IFNE            0x9a)
    (IFLT            0x9b)
    (IFGE            0x9c)
    (IFGT            0x9d)
    (IFLE            0x9e)
    (IF_ICMPEQ       0x9f)
    (IF_ICMPNE       0xa0)
    (IF_ICMPLT       0xa1)
    (IF_ICMPGE       0xa2)
    (IF_ICMPGT       0xa3)
    (IF_ICMPLE       0xa4)
    (IF_ACMPEQ       0xa5)
    (IF_ACMPNE       0xa6)
    (GOTO            0xa7)
    (JSR             0xa8)
    (RET             0xa9)
    (TABLESWITCH     0xaa)
    (LOOKUPSWITCH    0xab)
    (IRETURN         0xac)
    (LRETURN         0xad)
    (FRETURN         0xae)
    (DRETURN         0xaf)
    (ARETURN         0xb0)
    (RETURN          0xb1)
    (GETSTATIC       0xb2)
    (PUTSTATIC       0xb3)
    (GETFIELD        0xb4)
    (PUTFIELD        0xb5)
    (INVOKEVIRTUAL   0xb6)
    (INVOKESPECIAL   0xb7)
    (INVOKESTATIC    0xb8)
    (INVOKEINTERFACE 0xb9)
    (NEW             0xbb)
    (NEWARRAY        0xbc)
    (ANEWARRAY       0xbd)
    (ARRAYLENGTH     0xbe)
    (ATHROW          0xbf)
    (CHECKCAST       0xc0)
    (INSTANCEOF      0xc1)
    (MONITORENTER    0xc2)
    (MONITOREXIT     0xc3)
    (WIDE            0xc4)
    (MULTIANEWARRAY  0xc5)
    (IFNULL          0xc6)
    (IFNONNULL       0xc7)
    (GOTO_W          0xc8)
    (JSR_W           0xc9)
    (BREAKPOINT      0xca)
    (RET_W           0xd1)
    (IMPDEP1         0xfe)
    (IMPDEP2         0xff)
   ), 'javaop)$

% Some JVM operations have short-forms for use when their operand is
% especially small.

deflist('(
    (ILOAD           (ILOAD_0 . 3))
    (LLOAD           (LLOAD_0 . 3))
    (FLOAD           (FLOAD_0 . 3))
    (DLOAD           (DLOAD_0 . 3))
    (ALOAD           (ALOAD_0 . 3))
    (ISTORE          (ISTORE_0 . 3))
    (LSTORE          (LSTORE_0 . 3))
    (FSTORE          (FSTORE_0 . 3))
    (DSTORE          (DSTORE_0 . 3))
    (ASTORE          (ASTORE_0 . 3))
    ), 'small_operand);

% Code to pack up JVM instructions and insert them into generated code

global '(!*printbytes !*filebytes);

!*printbytes := 'nil;
!*filebytes  := t;   % so that I can go "javap" to decode them

symbolic procedure setlabel l;
  << if !*printbytes then << princ l; printc ":" >>;
     set!-label l
  >>;

symbolic procedure inst0(op);
  << if !*printbytes then << ttab 6; printc op >>;
     add!-instr(get(op, 'javaop))
  >>;

symbolic procedure inst0d(op, doc);
  << if !*printbytes then <<
        ttab 6; princ op;
        ttab 24; princ "; "; printc doc >>;
     add!-instr(get(op, 'javaop))
  >>;

symbolic procedure inst1(op, arg);
  begin
    scalar w;
    if !*printbytes then << ttab 6; princ op; princ " "; printc arg >>;
    w := get(op, 'small_operand);
    if w and arg >= 0 and arg <= cdr w then
       add!-instr(get(car w, 'javaop) + arg)
    else <<
       add!-instr(get(op, 'javaop));
       add!-instr(arg) >>
  end;

symbolic procedure inst1d(op, arg, doc);
  begin
    scalar w;
    if !*printbytes then <<
       ttab 6; princ op;
       princ " "; princ arg;
       ttab 24; princ "; "; printc doc >>;
    w := get(op, 'small_operand);
    if w and arg >= 0 and arg <= cdr w then
       add!-instr(get(car w, 'javaop) + arg)
    else <<
       add!-instr(get(op, 'javaop));
       add!-instr(arg) >>
  end;

symbolic procedure inst2(op, arg, doc); % e.g. GETSTATIC where arg is SHORT
  << if !*printbytes then <<
         ttab 6; princ op;
         princ " "; princ arg;
         ttab 24; princ "; "; printc doc >>;
     add!-instr!-args(get(op, 'javaop), arg)
  >>;

symbolic procedure inst3(op, arg1, arg2);
  begin
     if !*printbytes then <<
        ttab 6;
        princ op;
        princ " "; princ arg1;
        princ " "; printc arg2 >>;
     add!-instr(get(op, 'javaop));
     add!-instr(arg1);
     add!-instr(arg2)
  end;

symbolic procedure loadint n;
   inst1('ILOAD, n);

symbolic procedure loadref(n, doc);
   inst1d('ALOAD, n, doc);

symbolic procedure storeint n;
   inst1('ISTORE, n);

symbolic procedure storeref(n, doc);
   inst1d('ASTORE, n, doc);

symbolic procedure loadintconstant n;
  begin
    if n >= -1 and n <= 5 then <<
       if !*printbytes then << ttab 6; princ 'ICONST!_; printc n >>;
       add!-instr(get('ICONST_0, 'javaop) + n) >>
    else if n >= -128 and n <= 127 then <<
       if !*printbytes then << ttab 6; princ 'BIPUSH; princ " "; printc n >>;
       add!-instr(get('BIPUSH, 'javaop));
       add!-instr(n) >>
    else <<
       if !*printbytes then << ttab 6; princ 'SIPUSH; princ " "; printc n >>;
       add!-instr!-args(get('SIPUSH, 'javaop), n) >>;
  end;

fluid '(literal_table max_stack max_local next_local current_function);

symbolic procedure vijay_compile name;
  begin
    scalar defn, args, nargs, body, classname, current_function,
           varlocs, next_local, n, xclass, literal_table,
           max_stack, max_local, fluidnames;
    current_function := name;
    defn := getd name;
    if not eqcar(defn, 'expr) then error(1, list(name, "can not be compiled"));
    args := car (defn := cddr defn);
    nargs := length args;
    body := cadr defn;
% The class that is constructed will be given a curious name
% intended to avoid clashes with any existing classes.
    classname := compress('!" . '!C .
       append(explode abs md60(name . args . defn), '(!")));

    make!-java!-class();
    method!-number 2;                % init & method being compiled
    set!-access();
    add!-code();
    add!-exceptions();
    set!-this(classname);   % classname - but this feels WRONG here!
    set!-super("JavaFn");
    make!-init();

    if nargs = 0 then <<
      make!-method("op0", "()LLispObject;")>>
    else if nargs = 1 then <<
      make!-method("op1", "(LLispObject;)LLispObject;")>>
    else if nargs = 2 then <<
      make!-method("op2", "(LLispObject;LLispObject;)LLispObject;")>>
    else <<
      make!-method("opn", "([LLispObject;)LLispObject;")>>;

    if nargs < 3 then next_local := nargs + 1 % next available position
    else next_local := 2;
    max_local := next_local - 1;

    for each v in args do
       if fluidp v then fluidnames := (v . gensym()) . fluidnames
       else if globalp v then
          error(0, list("attempt to bind global as arg", v, current_function));

    if fluidnames then <<
       args := sublis(fluidnames, args);
       body := list list('return, body);
       for each v in fluidnames do
          body := list('setq, car v, cdr v) . body;
       body := 'prog . (for each v in fluidnames collect car v) . body >>;

% varlocs holds a map of variables stored on the stack. The association
% list keys to an integer in the case of vars simply and directly on the
% stack, or a list (n) for one at offset n in a vector at position 0
% on the stack.
    if nargs = 0 then varlocs := nil
    else if nargs = 1 then varlocs := list(car args . 0)
    else if nargs = 2 then varlocs := list(car args . 0, cadr args . 1)
    else <<
      varlocs := nil;
      n := 0;
      for each a in args do <<
        varlocs := (a . list n) . varlocs;
        n := n + 1 >> >>;

    max_stack := 2;

    loadval(body, varlocs, t);

    inst0('ARETURN);

    %set!-stack!-locals(20, max_local+2);  % These are WRONG as yet!  @@@@@@
    set!-stack!-locals(50, max_local+2);  % These are WRONG as yet!  @@@@@@

    finish!-method();
    make!-cp();
    resolve!-all();
    if !*printbytes then print!-cp();
    finish!-class();
    if !*filebytes then
        bytes!-to!-file(); % This could be done so that a copy of the
                           % constructed class-file was left on disc for
                           % inspection or debugging.
    xclass := instance!-from!-bytes();

    n := l2v reverse literal_table;
% The next two lines must be executed very much together. Consider the
% comical case when you are compiling l2v, then if (as one was the case)
% it was not pre-called and its value saved in a variable then really
% messy things happen when it gets called when only half put together in
% compiled form!
    symbol!-set!-definition(name, xclass);
    symbol!-set!-env(name, n);
    return name
  end;

symbolic procedure new_local();
  begin
    scalar r;
    r := next_local;
    if next_local > max_local then max_local := next_local;
    next_local := next_local + 1;
    return r
  end;

symbolic procedure lose_local();
   next_local := next_local-1;

symbolic procedure l2v l;
  begin
    scalar v, n;
    n := length l;
    v := mkvect sub1 n;
    n := 0;
    for each x in l do <<
      putv(v, n, x);
      n := n + 1 >>;
    return v
  end;

symbolic procedure loadval(x, varlocs, context);
   if atom x then loadvalatom(x, varlocs, context)
   else if atom car x then begin
      scalar helper;
      if helper := get(car x, 'vjhelper) then
         return funcall(helper, cdr x, varlocs, context);
      if helper := macro!-function car x then
         return loadval(funcall(helper, x), varlocs, context);
      return loadvalcall(car x, cdr x, varlocs, context) end
   else if eqcar(car x, 'lambda) then
      loadlambda(car x, cdr x, varlocs, context)
   else error(0, list("non-atomic function", car x, current_function));


symbolic procedure loadlambda(l, x, varlocs, context);
  begin
    scalar vars, b, r, oldvarlocs, fluidnames;
    vars := cadr l;
    b := caddr l;
    oldvarlocs := varlocs;
    for each v in vars do <<
       if fluidp v then fluidnames := (v . gensym()) . fluidnames
       else if globalp v then
           error(0, list("attempt to bind fluid/global var in lambda",
                         v, current_function));
       varlocs := (v . new_local()) . varlocs >>;
    varlocs := sublis(fluidnames, varlocs);
    for each v in vars do
       if fluidp v then <<
          loadval(v, nil, t);
          vjstorein(cdr assoc(v, fluidnames), varlocs) >>;
%   if fluidnames then "TRY"
    while vars and x do <<
        loadval(car x, oldvarlocs, context);
        vjstorein(car vars, varlocs); % if fluid goes into fluid version
        vars := cdr vars;
        x := cdr x >>;
    loadval(b, varlocs, context);
%   if fluidnames then "FINALLY"
    if fluidnames then
    for each v in reverse vars do
       if fluidp v then <<
          loadval(cdr assoc(v, fluidnames), varlocs, t);
          vjstorein(v, nil) >>;
    for each v in cadr l do lose_local();
  end;

symbolic procedure load_literal x;
  begin
     scalar w, n;
     w := reverse literal_table;
     n := 0;
     while w and not (x = car w) do <<
        n := n+1;
        w := cdr w >>;
     if null w then <<
        if null literal_table then
           add!-fieldref("FnWithEnv", "env", "[LLispObject;");
        literal_table := x . literal_table >>; % add a new literal
     loadref(0, "this"); % ALOAD_0, ie "this"
     inst2('GETFIELD, lookup!-ref("env"), "env");
     loadintconstant n;
     inst0d('AALOAD, x)
  end;

symbolic procedure loadvalatom(x, varlocs, context);
   if null x then <<
      add!-fieldref("Jlisp", "nil", "LSymbol;");
      inst2('GETSTATIC, lookup!-ref("nil"), "nil") >>
   else if numberp x or stringp x then load_literal x
   else begin
      scalar n, w;
      w := varlocs;
      while w and not eqcar(car w, x) do w := cdr w;
      if null w then <<
         if not (globalp x or fluidp x) then <<
            terpri();
            princ "!!! "; prin x; printc " declared fluid";
            fluid list x >>;
         load_literal x;
         add!-fieldref("LispObject", "car", "LLispObject;");
         inst2('GETFIELD, lookup!-ref("car"), "car") >>
      else if numberp (w := cdar w) then
         loadref(w+1, x)    % The "+1" is because "this" is at location 0
      else <<
         loadref(1, "vec-of-args");
         loadintconstant(car w);
         inst0d('AALOAD, x) >>
    end;

symbolic procedure loadvalcall(fn, args, varlocs, context);
   begin
      scalar w, desc, n;
      load_literal fn;
      add!-class!-info("Symbol");
% This down-cast may be a significant expense. It could, perhaps, be
% avoided by having two literal tables for each function - one containing
% just "Symbol" objects and always used for function calls, the other
% of type LispObject and thus able to cope with more general expressions.
      inst2('CHECKCAST, lookup!-cinfo("Symbol"), "Symbol");
      add!-fieldref("Symbol", "fn", "LLispFunction;");
      inst2('GETFIELD, lookup!-ref("fn"), "fn");
      n := length args;
      if n = 0 then <<
         w := "op0";
         desc := "()LLispObject;" >>
      else if n = 1 then <<
         w := "op1";
         desc := "(LLispObject;)LLispObject;";
         loadval(car args, varlocs, context) >>
      else if n = 2 then <<
         w := "op2";
         desc := "(LLispObject;LLispObject;)LLispObject;";
         loadval(car args, varlocs, context);
         loadval(cadr args, varlocs, context) >>
      else <<
         w := "opn";
         desc := "([LLispObject;)LLispObject;";
         loadintconstant(n);
         add!-class!-info("LispObject");
         inst2('ANEWARRAY, lookup!-cinfo("LispObject"), "LispObject");
% A short essay is called for here. We need a (temporary) vector to assemble
% the args into. If this is kept in a local variable then the type of that
% slot must be the same always, and so I must NEVER re-allocate that stack
% offset for a simple Lisp variable. I can not allocate a single dedicated
% var because nested calls such as
%    f1(a,b,c,d,f2(a,b,c,d,f3(a,b,c,d)))
% will have several little vectors partway active at once. It MAY be better
% to keep the vector on the STACK not in a LOCAL. Then a bunch of
% DUP operations will be needed. Now I think of it that seems easy enough
% to do so I am altering this code to work that way, making this comment
% a historical relic...
%
         n := 0;
         for each a in args do <<
            inst0 'DUP;   % The array as needed by opn()
            loadintconstant(n);
            loadval(a, varlocs, context);
            inst0('AASTORE);
            n := n + 1 >> >>;
      add!-methodref("LispFunction", w, desc);
      inst2('INVOKEVIRTUAL, lookup!-ref(w), w)
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% First deal with "special forms" that NEED special compilation

symbolic procedure vjquote(a, varlocs, context);
   load_literal car a;

put('quote, 'vjhelper, function vjquote);

symbolic procedure vjjumpif(p, varlocs, context, iftrue, dest);
  begin
    scalar l2;
    while eqcar(p, 'null) or eqcar(p, 'not) do <<
       p := cadr p;
       iftrue := not iftrue >>;
%   if (eqcar(p, 'or) and iftrue) or
%      (eqcar(p, 'and) and not iftrue) then <<
%       for each q in cdr p do
%           vjjumpif(q, varlocs, context, iftrue, dest);
%       return nil >>;
%   if (eqcar(p, 'or) and not iftrue) or
%      (eqcar(p, 'and) and iftrue) then <<
%       l2 := gensym();
%       for each q in cdr p do
%           vjjumpif(q, varlocs, context, not iftrue, l2);
%       lookup!-label(dest);
%       inst2('GOTO, 0, dest);
%       setlabel(l2);
%       return nil >>;
    loadval(p, varlocs, context);
    add!-fieldref("Jlisp", "nil", "LSymbol;");
    inst2('GETSTATIC, lookup!-ref("nil"), "nil");
    lookup!-label(dest);
    if iftrue then inst2('IF_ACMPNE, 0, dest)
    else inst2('IF_ACMPEQ, 0, dest); % 0 as default when label not known
  end;

symbolic procedure vjif(a, varlocs, context);
  begin
    scalar p, x, y, l1, l2;
    p := car a;
    x := cadr a;
    y := caddr a;
    l1 := gensym();
    l2 := gensym();
    vjjumpif(p, varlocs, context, nil, l1);
    loadval(x, varlocs, context);
    lookup!-label(l2);
    inst2('GOTO, 0, l2);
    setlabel(l1);
    loadval(y, varlocs, context);
    setlabel(l2)
  end;

put('if, 'vjhelper, function vjif);

%
%  (COND                            IF
%      (predicate1 value1)            predicate1 THEN value1
%      (predicate2 value2)          ELSE IF predicate2 THEN value2
%      (T         default-value))   ELSE (if true then) default-value
%

% Note that some dialects of Lisp permit an "implied progn" where each
% value is shown... I do not support that here.

symbolic procedure vjcond(a, varlocs, context);
  if null a then loadval(nil, varlocs, context)
  else if caar a = 't or caar a = ''t then
      loadval(cadar a, varlocs, context)
  else vjif(list(caar a, cadar a, 'cond . cdr a), varlocs, context);

put('cond, 'vjhelper, function vjcond);

symbolic procedure vjand(a, varlocs, context);
  if null a then loadval(t, varlocs, context)
  else if null cdr a then loadval(car a, varlocs, context)
  else vjif(list(car a, 'and . cdr a, nil), varlocs, context);

put('and, 'vjhelper, function vjand);

symbolic procedure vjor(a, varlocs, context);
  if null a then loadval(nil, varlocs, context)
  else if null cdr a then loadval(car a, varlocs, context)
  else vjif(list(car a, t, 'or . cdr a), varlocs, context);

put('or, 'vjhelper, function vjor);

symbolic procedure vjsetq(a, varlocs, context);
  <<
    loadval(cadr a, varlocs, context);
    inst0('DUP);  % so that the value stored is also available as a result
    vjstorein(car a, varlocs)
  >>;

symbolic procedure vjstorein(x, varlocs);
  begin
    scalar w;
% note how similar this is to loadvalatom
    w := varlocs;
    while w and not eqcar(car w, x) do w := cdr w;
    if null w then <<
       if not (globalp x or fluidp x) then <<
          terpri();
          princ "!!! "; prin x; printc " declared fluid";
          fluid list x >>;
       load_literal x;
       inst0 'SWAP;   % PUTFIELD takes object_ref,value
       add!-fieldref("LispObject", "car", "LLispObject;");
       inst2('PUTFIELD, lookup!-ref("car"), "car") >>
    else if numberp (w := cdar w) then
       storeref(w+1, x)   % The "+1" is because "this" is at location 0
    else <<
       loadref(1, "vec-of-args"); % ALOAD_1
       inst0 'SWAP;
       loadintconstant(car w);
       inst0 'SWAP;   % AASTORE tapes arrayref, index, value
       inst0d('AASTORE, x) >>
  end;

put('setq, 'vjhelper, function vjsetq);

symbolic procedure vjprogn(a, varlocs, context);
  begin
    if null a then return loadval(nil, varlocs, context);
    while a do <<
       loadval(car a, varlocs, context);
       a := cdr a;
       if a then inst0('POP) >>
  end;

put('progn, 'vjhelper, function vjprogn);

fluid '(proglabs retlab);

symbolic procedure vjprog(a, varlocs, context);
  begin
    scalar locals, proglabs, retlab, w, fluidnames;
    locals := car a;
% At present this does not deal with fluid variables being bound. Well to
% be cautious I make it abort on any such attempt!
    for each v in locals do <<
       if fluidp v then fluidnames := (v . gensym()) . fluidnames
       else if globalp v then
           error(0, list("attempt to bind global var in prog", v, current_function));
       varlocs := (v . new_local()) . varlocs >>;
    varlocs := sublis(fluidnames, varlocs);

% save values of any fluid local vars
    for each v in locals do
       if fluidp v then <<
          loadval(v, nil, t); % use varlocs=nil to stress that global val
          vjstorein(cdr assoc(v, fluidnames), varlocs) >>;

% Set all local vars to nil at start
    for each v in locals do <<
        loadvalatom(nil, varlocs, context);
        vjstorein(v, varlocs) >>;

    a := cdr a;
    retlab := gensym();
    for each s in a do if atom s then proglabs := (s . gensym()) . proglabs;

%   if fluidnames then "TRY"

    for each s in a do if atom s then setlabel cdr assoc(s, proglabs)
    else <<
       progloadval(s, varlocs, t);
       inst0 'POP >>;

    loadval(nil, varlocs, context); % default return value
    setlabel retlab;

%   if fluidnames then "FINALLY"
    for each v in reverse locals do
       if fluidp v then <<
          loadval(cdr assoc(v, fluidnames), varlocs, t);
          vjstorein(v, nil) >>; 

    for each v in locals do <<
       lose_local();
       varlocs := cdr varlocs >> % Restore environment
  end;

symbolic procedure progloadval(x, varlocs, context);
  begin
    scalar helper, w;
    if eqcar(x, 'go) then <<
       w := assoc(cadr x, proglabs);
       if null w then error(0, list("label not known", x, current_function));
       lookup!-label(cdr w);
       inst2('GOTO, 0, cdr w) >>
    else if eqcar(x, 'return) then <<
       loadval(cadr x, varlocs, context);
       lookup!-label retlab;
       inst2('GOTO, 0, retlab) >>
    else if eqcar(x, 'progn) then <<
       if null cdr x then loadval(nil, varlocs, context)
       else while (x := cdr x) do <<
          loadval(car x, varlocs, context);
          if cdr x then inst0('POP) >> >>
    else if eqcar(x, 'cond) then
       if null cdr x then loadval(nil, varlocs, context)
       else if member(caadr x, '(t (quote t))) then
           progloadval(cadadr x, varlocs, context)
       else progloadval(list('if, caadr x, cadadr x, 'cond . cddr x),
                        varlocs, context)
    else if eqcar(x, 'if) then begin
       scalar a, p, y1, y2, l1, l2;
       a := cdr x;
       p := car a;
       y1 := cadr a;
       y2 := caddr a;
       l1 := gensym();
       l2 := gensym();
       vjjumpif(p, varlocs, context, nil, l1);
       progloadval(y1, varlocs, context);
       lookup!-label(l2);
       inst2('GOTO, 0, l2);
       setlabel(l1);
       progloadval(y2, varlocs, context);
       setlabel(l2)
    end
    else if helper := macro!-function car x then
       progloadval(funcall(helper, x), varlocs, context)
    else loadval(x, varlocs, context)
  end;

put('prog, 'vjhelper, function vjprog);

symbolic procedure vjgo(a, varlocs, context);
  begin
     error(0, list("go not supported outside prog", current_function))
  end;

put('go, 'vjhelper, function vjgo);

symbolic procedure vjreturn(a, varlocs, context);
  begin
     error(0, list("return not supported outside prog", current_function))
  end;

put('return, 'vjhelper, function vjreturn);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% From here down special compilation is for performance

symbolic procedure vjcar(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-fieldref("LispObject", "car", "LLispObject;");
     inst2('GETFIELD, lookup!-ref("car"), "car")
  >>;

put('car, 'vjhelper, function vjcar);

symbolic procedure vjcdr(a, varlocs, context);
   << loadval(car a, varlocs, context);
      add!-fieldref("LispObject", "cdr", "LLispObject;");
      inst2('GETFIELD, lookup!-ref("cdr"), "car")
   >>;

put('cdr, 'vjhelper, function vjcdr);

symbolic procedure vjcaar(a, varlocs, context);
   loadval(list('car, list('car, car a)), varlocs, context);

put('caar, 'vjhelper, function vjcaar);

symbolic procedure vjcadr(a, varlocs, context);
   loadval(list('car, list('cdr, car a)), varlocs, context);

put('cadr, 'vjhelper, function vjcadr);

symbolic procedure vjcdar(a, varlocs, context);
   loadval(list('cdr, list('car, car a)), varlocs, context);

put('cdar, 'vjhelper, function vjcdar);

symbolic procedure vjcddr(a, varlocs, context);
   loadval(list('cdr, list('cdr, car a)), varlocs, context);

put('cddr, 'vjhelper, function vjcddr);

symbolic procedure vjcaaar(a, varlocs, context);
   loadval(list('car, list('car, list('car, car a))), varlocs, context);

put('caaar, 'vjhelper, function vjcaaar);

symbolic procedure vjcaadr(a, varlocs, context);
   loadval(list('car, list('car, list('cdr, car a))), varlocs, context);

put('caadr, 'vjhelper, function vjcaadr);

symbolic procedure vjcadar(a, varlocs, context);
   loadval(list('car, list('cdr, list('car, car a))), varlocs, context);

put('cadar, 'vjhelper, function vjcadar);

symbolic procedure vjcaddr(a, varlocs, context);
   loadval(list('car, list('cdr, list('cdr, car a))), varlocs, context);

put('caddr, 'vjhelper, function vjcaddr);

symbolic procedure vjcdaar(a, varlocs, context);
   loadval(list('cdr, list('car, list('car, car a))), varlocs, context);

put('cdaar, 'vjhelper, function vjcdaar);

symbolic procedure vjcdadr(a, varlocs, context);
   loadval(list('cdr, list('car, list('cdr, car a))), varlocs, context);

put('cdadr, 'vjhelper, function vjcdadr);

symbolic procedure vjcddar(a, varlocs, context);
   loadval(list('cdr, list('cdr, list('car, car a))), varlocs, context);

put('cddar, 'vjhelper, function vjcddar);

symbolic procedure vjcdddr(a, varlocs, context);
   loadval(list('cdr, list('cdr, list('cdr, car a))), varlocs, context);

put('cdddr, 'vjhelper, function vjcdddr);

symbolic procedure vjcaaaar(a, varlocs, context);
   loadval(list('caar, list('car, list('car, car a))), varlocs, context);

put('caaaar, 'vjhelper, function vjcaaaar);

symbolic procedure vjcaaadr(a, varlocs, context);
   loadval(list('caar, list('car, list('cdr, car a))), varlocs, context);

put('caaadr, 'vjhelper, function vjcaaadr);

symbolic procedure vjcaadar(a, varlocs, context);
   loadval(list('caar, list('cdr, list('car, car a))), varlocs, context);

put('caadar, 'vjhelper, function vjcaadar);

symbolic procedure vjcaaddr(a, varlocs, context);
   loadval(list('caar, list('cdr, list('cdr, car a))), varlocs, context);

put('caaddr, 'vjhelper, function vjcaaddr);

symbolic procedure vjcadaar(a, varlocs, context);
   loadval(list('cadr, list('car, list('car, car a))), varlocs, context);

put('cadaar, 'vjhelper, function vjcadaar);

symbolic procedure vjcadadr(a, varlocs, context);
   loadval(list('cadr, list('car, list('cdr, car a))), varlocs, context);

put('cadadr, 'vjhelper, function vjcadadr);

symbolic procedure vjcaddar(a, varlocs, context);
   loadval(list('cadr, list('cdr, list('car, car a))), varlocs, context);

put('caddar, 'vjhelper, function vjcaddar);

symbolic procedure vjcadddr(a, varlocs, context);
   loadval(list('cadr, list('cdr, list('cdr, car a))), varlocs, context);

put('cadddr, 'vjhelper, function vjcadddr);

symbolic procedure vjcdaaar(a, varlocs, context);
   loadval(list('cdar, list('car, list('car, car a))), varlocs, context);

put('cdaaar, 'vjhelper, function vjcdaaar);

symbolic procedure vjcdaadr(a, varlocs, context);
   loadval(list('cdar, list('car, list('cdr, car a))), varlocs, context);

put('cdaadr, 'vjhelper, function vjcdaadr);

symbolic procedure vjcdadar(a, varlocs, context);
   loadval(list('cdar, list('cdr, list('car, car a))), varlocs, context);

put('cdadar, 'vjhelper, function vjcdadar);

symbolic procedure vjcdaddr(a, varlocs, context);
   loadval(list('cdar, list('cdr, list('cdr, car a))), varlocs, context);

put('cdaddr, 'vjhelper, function vjcdaddr);

symbolic procedure vjcddaar(a, varlocs, context);
   loadval(list('cddr, list('car, list('car, car a))), varlocs, context);

put('cddaar, 'vjhelper, function vjcddaar);

symbolic procedure vjcddadr(a, varlocs, context);
   loadval(list('cddr, list('car, list('cdr, car a))), varlocs, context);

put('cddadr, 'vjhelper, function vjcddadr);

symbolic procedure vjcdddar(a, varlocs, context);
   loadval(list('cddr, list('cdr, list('car, car a))), varlocs, context);

put('cdddar, 'vjhelper, function vjcdddar);

symbolic procedure vjcddddr(a, varlocs, context);
   loadval(list('cddr, list('cdr, list('cdr, car a))), varlocs, context);

put('cddddr, 'vjhelper, function vjcddddr);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic procedure vjcons(a, varlocs, context);
  << add!-class!-info("Cons");
     inst2('NEW, lookup!-cinfo("Cons"), "Cons");
     inst0('DUP);
     loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("Cons", "<init>", "(LLispObject;LLispObject;)V");
     inst2('INVOKESPECIAL, lookup!-ref("<init>"), "<init>")
   >>;

put('cons, 'vjhelper, function vjcons);

symbolic procedure vjacons(a, varlocs, context);
   loadval(list('cons, list('cons, car a, cadr a), caddr a),
           varlocs, context);

put('acons, 'vjhelper, function vjacons);

symbolic procedure vjncons(a, varlocs, context);
   loadval(list('cons, car a, nil), varlocs, context);

put('ncons, 'vjhelper, function vjncons);

symbolic procedure vjlist(a, varlocs, context);
   begin
      scalar newlist, revlist;
      revlist := reverse a;
      newlist := 'nil;
      for each x in revlist do
         newlist := list('cons, x, newlist);
      loadval(newlist, varlocs, context)
   end;

put('list, 'vjhelper, function vjlist);

symbolic procedure vjlist!*(a, varlocs, context);
   begin
      scalar newlist, revlist;
      revlist := reverse a;
      newlist := car revlist;
      for each a in cdr revlist do
         newlist := list('cons, a, newlist);
      loadval(newlist, varlocs, context)
   end;

put('list!*, 'vjhelper, function vjlist!*);

symbolic procedure vjnull(a, varlocs, context);
   begin
      scalar l1, l2;
      l1 := gensym();
      l2 := gensym();
      vjjumpif(car a, varlocs, context, nil, l1);
      loadval(nil, varlocs, context);
      lookup!-label(l2);
      inst2('GOTO, 0, l2);
      setlabel(l1);
      add!-fieldref("Jlisp", "lispTrue", "LSymbol;");
      inst2('GETSTATIC, lookup!-ref("lispTrue"), "lispTrue");
      setlabel(l2)
   end;

put('null, 'vjhelper, function vjnull);
put('not, 'vjhelper, function vjnull);

symbolic procedure vjatom(a, varlocs, context);
   begin
      scalar l1, l2;
      l1 := gensym();
      l2 := gensym();
      loadval(car a, varlocs, context);
      add!-fieldref("LispObject", "atom", "Z");
      inst2('GETFIELD, lookup!-ref("atom"), "atom");
      lookup!-label(l1);
      inst2('IFNE, 0, l1);
      loadval(nil, varlocs, context);
      lookup!-label(l2);
      inst2('GOTO, 0, l2);
      setlabel(l1);
      add!-fieldref("Jlisp", "lispTrue", "LSymbol;");
      inst2('GETSTATIC, lookup!-ref("lispTrue"), "lispTrue");
      setlabel(l2)
   end;

put('atom, 'vjhelper, function vjatom);

symbolic procedure vjconsp(a, varlocs, context);
   begin
      scalar l1, l2;
      l1 := gensym();
      l2 := gensym();
      loadval(car a, varlocs, context);
      add!-fieldref("LispObject", "atom", "Z");
      inst2('GETFIELD, lookup!-ref("atom"), "atom");
      lookup!-label(l1);
      inst2('IFEQ, 0, l1);
      loadval(nil, varlocs, context);
      lookup!-label(l2);
      inst2('GOTO, 0, l2);
      setlabel(l1);
      add!-fieldref("Jlisp", "lispTrue", "LSymbol;");
      inst2('GETSTATIC, lookup!-ref("lispTrue"), "lispTrue");
      setlabel(l2)
   end;

put('consp, 'vjhelper, function vjconsp);

symbolic procedure vjnumberp(a, varlocs, context);
   begin
      scalar l1, l2;
      l1 := gensym();
      l2 := gensym();
      loadval(car a, varlocs, context);
      add!-class!-info("LispNumber");
      inst2('INSTANCEOF, lookup!-cinfo("LispNumber"), "LispNumber");
      lookup!-label(l1);
      inst2('IFNE, 0, l1);
      loadval(nil, varlocs, context);
      lookup!-label(l2);
      inst2('GOTO, 0, l2);
      setlabel(l1);
      add!-fieldref("Jlisp", "lispTrue", "LSymbol;");
      inst2('GETSTATIC, lookup!-ref("lispTrue"), "lispTrue");
      setlabel(l2)
   end;

put('numberp, 'vjhelper, function vjnumberp);


symbolic procedure vjstringp(a, varlocs, context);
   begin
      scalar l1, l2;
      l1 := gensym();
      l2 := gensym();
      loadval(car a, varlocs, context);
      add!-class!-info("LispString");
      inst2('INSTANCEOF, lookup!-cinfo("LispString"), "LispString");
      lookup!-label(l1);
      inst2('IFNE, 0, l1);
      loadval(nil, varlocs, context);
      lookup!-label(l2);
      inst2('GOTO, 0, l2);
      setlabel(l1);
      add!-fieldref("Jlisp", "lispTrue", "LSymbol;");
      inst2('GETSTATIC, lookup!-ref("lispTrue"), "lispTrue");
      setlabel(l2)
   end;

put('stringp, 'vjhelper, function vjstringp);

symbolic procedure vjplus(a, varlocs, context);
  << loadval(car a, varlocs, context);
     for each v in cdr a do <<
        loadval(v, varlocs, context);
        add!-methodref("LispObject", "add", "(LLispObject;)LLispObject;");
        inst2('INVOKEVIRTUAL, lookup!-ref("add"), "add") >>
  >>;

put('plus, 'vjhelper, function vjplus);

symbolic procedure vjdifference(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("LispObject", "subtract", "(LLispObject;)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("subtract"), "subtract");
  >>;

put('difference, 'vjhelper, function vjdifference);

symbolic procedure vjtimes(a, varlocs, context);
  << loadval(car a, varlocs, context);
     for each v in cdr a do <<
        loadval(v, varlocs, context);
        add!-methodref("LispObject", "multiply", "(LLispObject;)LLispObject;");
        inst2('INVOKEVIRTUAL, lookup!-ref("multiply"), "multiply") >>
  >>;

put('times, 'vjhelper, function vjtimes);

symbolic procedure vjdivide(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("LispObject", "quotientAndRemainder", "(LLispObject;)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("quotientAndRemainder"),
                           "quotientAndRemainder");
  >>;

put('divide, 'vjhelper, function vjdivide);

symbolic procedure vjquotient(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("LispObject", "divide", "(LLispObject;)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("divide"), "divide");
  >>;

put('quotient, 'vjhelper, function vjquotient);

symbolic procedure vjremainder(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("LispObject", "remainder", "(LLispObject;)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("remainder"), "remainder");
  >>;

put('remainder, 'vjhelper, function vjremainder);

symbolic procedure vjmod(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("LispObject", "mod", "(LLispObject;)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("mod"), "mod")
  >>;

put('mod, 'vjhelper, function vjmod);

symbolic procedure vjirightshift(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     %return arg1.rightshift(((LispSmallInteger)arg2).value);
     add!-class!-info("LispSmallInteger");
     inst2('CHECKCAST, lookup!-cinfo("LispSmallInteger"), "LispSmallInteger");
     add!-fieldref("LispSmallInteger", "value", "I");
     inst2('GETFIELD, lookup!-ref("value"), "value");
     add!-methodref("LispObject", "rightshift", "(I)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("rightshift"), "rightshift")
  >>;

put('irightshift, 'vjhelper, function vjirightshift);

symbolic procedure vjash(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     %return arg1.ash(((LispSmallInteger)arg2).value);
     add!-class!-info("LispSmallInteger");
     inst2('CHECKCAST, lookup!-cinfo("LispSmallInteger"), "LispSmallInteger");
     add!-fieldref("LispSmallInteger", "value", "I");
     inst2('GETFIELD, lookup!-ref("value"), "value");
     add!-methodref("LispObject", "ash", "(I)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("ash"), "ash")
  >>;

put('ash, 'vjhelper, function vjash);

symbolic procedure vjash1(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     %return arg1.ash1(((LispSmallInteger)arg2).value);
     add!-class!-info("LispSmallInteger");
     inst2('CHECKCAST, lookup!-cinfo("LispSmallInteger"), "LispSmallInteger");
     add!-fieldref("LispSmallInteger", "value", "I");
     inst2('GETFIELD, lookup!-ref("value"), "value");
     add!-methodref("LispObject", "ash1", "(I)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("ash1"), "ash1")
  >>;

put('ash1, 'vjhelper, function vjash1);

symbolic procedure vjmax(a, varlocs, context);
  << loadval(car a, varlocs, context);
     for each v in cdr a do <<
        loadval(v, varlocs, context);
        add!-methodref("LispObject", "max", "(LLispObject;)LLispObject;");
        inst2('INVOKEVIRTUAL, lookup!-ref("max"), "max") >>
  >>;

put('max, 'vjhelper, function vjmax);

symbolic procedure vjmin(a, varlocs, context);
  << loadval(car a, varlocs, context);
     for each v in cdr a do <<
        loadval(v, varlocs, context);
        add!-methodref("LispObject", "min", "(LLispObject;)LLispObject;");
        inst2('INVOKEVIRTUAL, lookup!-ref("min"), "min") >>
  >>;

put('min, 'vjhelper, function vjmin);

symbolic procedure vjexpt(a, varlocs, context);
  << loadval(car a, varlocs, context);
     loadval(cadr a, varlocs, context);
     add!-methodref("LispObject", "expt", "(LLispObject;)LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("expt"), "expt");
  >>;

put('expt, 'vjhelper, function vjexpt);

symbolic procedure vjminus(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "negate", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("negate"), "negate");
  >>;

put('minus, 'vjhelper, function vjminus);

% I think this should be the same as "idp"??? If I leave it
% out from the special-cases here I will get the regular built-in version.
%
% symbolic procedure vjeq!-safe(a, varlocs, context);
%    loadval(nil, varlocs, context);
%
% put('eq!-safe, 'vjhelper, function vjeq!-safe);

symbolic procedure vjadd1(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "add1", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("add1"), "add1");
  >>;

put('add1, 'vjhelper, function vjadd1);

symbolic procedure vjsub1(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "sub1", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("sub1"), "sub1");
  >>;

put('sub1, 'vjhelper, function vjsub1);

symbolic procedure vjabs(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "abs", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("abs"), "abs");
  >>;

put('abs, 'vjhelper, function vjabs);

symbolic procedure vjmsd(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "msd", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("msd"), "msd");
  >>;

put('msd, 'vjhelper, function vjmsd);

symbolic procedure vjlsd(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "lsd", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("lsd"), "lsd");
  >>;

put('lsd, 'vjhelper, function vjlsd);

symbolic procedure vjfloor(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "floor", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("floor"), "floor");
  >>;

put('floor, 'vjhelper, function vjfloor);

symbolic procedure vjceiling(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "ceiling", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("ceiling"), "ceiling");
  >>;

put('ceiling, 'vjhelper, function vjceiling);

symbolic procedure vjround(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "round", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("round"), "round");
  >>;

put('round, 'vjhelper, function vjround);

symbolic procedure vjfix(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "fix", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("fix"), "fix");
  >>;

put('fix, 'vjhelper, function vjfix);

symbolic procedure vjfloat(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "jfloat", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("jfloat"), "jfloat");
  >>;

put('float, 'vjhelper, function vjfloat);

symbolic procedure vjfloatp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "floatp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("floatp"), "floatp");
  >>;

put('floatp, 'vjhelper, function vjfloatp);

symbolic procedure vjfixp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "fixp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("fixp"), "fixp");
  >>;

put('fixp, 'vjhelper, function vjfixp);

symbolic procedure vjintegerp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "integerp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("integerp"), "integerp");
  >>;

put('integerp, 'vjhelper, function vjintegerp);

symbolic procedure vjzerop(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "zerop", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("zerop"), "zerop");
  >>;

put('zerop, 'vjhelper, function vjzerop);

symbolic procedure vjonep(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "onep", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("onep"), "onep");
  >>;

put('onep, 'vjhelper, function vjonep);

symbolic procedure vjminusp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "minusp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("minusp"), "minusp");
  >>;

put('minusp, 'vjhelper, function vjminusp);

symbolic procedure vjplusp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "plusp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("plusp"), "plusp");
  >>;

put('plusp, 'vjhelper, function vjplusp);

symbolic procedure vjevenp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "evenp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("evenp"), "evenp");
  >>;

put('evenp, 'vjhelper, function vjevenp);

symbolic procedure vjoddp(a, varlocs, context);
  << loadval(car a, varlocs, context);
     add!-methodref("LispObject", "oddp", "()LLispObject;");
     inst2('INVOKEVIRTUAL, lookup!-ref("oddp"), "oddp");
  >>;

put('oddp, 'vjhelper, function vjoddp);

symbolic procedure vjplus2(a, varlocs, context);
   loadval('plus . a, varlocs, context);

put('plus2, 'vjhelper, function vjplus2);

symbolic procedure vjtimes2(a, varlocs, context);
   loadval('times . a, varlocs, context);

put('times2, 'vjhelper, function vjtimes2);

symbolic procedure vjmax2(a, varlocs, context);
   loadval('max . a, varlocs, context);

put('max2, 'vjhelper, function vjmax2);

symbolic procedure vjmin2(a, varlocs, context);
   loadval('min . a, varlocs, context);

put('min2, 'vjhelper, function vjmin2);

symbolic procedure vjiadd1(a, varlocs, context);
   loadval('add1 . a, varlocs, context);

put('iadd1, 'vjhelper, function vjiadd1);

symbolic procedure vjisub1(a, varlocs, context);
   loadval('sub1 . a, varlocs, context);

put('isub1, 'vjhelper, function vjisub1);

symbolic procedure vjidifference(a, varlocs, context);
   loadval('difference . a, varlocs, context);

put('idifference, 'vjhelper, function vjidifference);

symbolic procedure vjitimes(a, varlocs, context);
   loadval('times . a, varlocs, context);

put('itimes, 'vjhelper, function vjitimes);

symbolic procedure vjitimes2(a, varlocs, context);
   loadval('times . a, varlocs, context);

put('itimes2, 'vjhelper, function vjitimes2);

symbolic procedure vjimax(a, varlocs, context);
   loadval('max . a, varlocs, context);

put('imax, 'vjhelper, function vjimax);

symbolic procedure vjimin(a, varlocs, context);
   loadval('min . a, varlocs, context);

put('imin, 'vjhelper, function vjimin);

symbolic procedure vjiplus(a, varlocs, context);
   loadval('plus . a, varlocs, context);

put('iplus, 'vjhelper, function vjiplus);

symbolic procedure vjiplus2(a, varlocs, context);
   loadval('plus . a, varlocs, context);

put('iplus2, 'vjhelper, function vjiplus2);

symbolic procedure vjiquotient(a, varlocs, context);
   loadval('quotient . a, varlocs, context);

put('iquotient, 'vjhelper, function vjiquotient);

symbolic procedure vjiremainder(a, varlocs, context);
   loadval('remainder . a, varlocs, context);

put('iremainder, 'vjhelper, function vjiremainder);

symbolic procedure vjizerop(a, varlocs, context);
   loadval('zerop . a, varlocs, context);

put('izerop, 'vjhelper, function vjizerop);

symbolic procedure vjionep(a, varlocs, context);
   loadval('onep . a, varlocs, context);

put('ionep, 'vjhelper, function vjionep);

symbolic procedure vjiminus(a, varlocs, context);
   loadval('minus . a, varlocs, context);

put('iminus, 'vjhelper, function vjiminus);

symbolic procedure vjiminusp(a, varlocs, context);
   loadval('minusp . a, varlocs, context);

put('iminusp, 'vjhelper, function vjiminusp);


% mapcar etc are compiled specially as a fudge to achieve an effect as
% if proper environment-capture was implemented for the functional
% argument (which I do not support at present). Not done (here) for
% Common Lisp since args to mapcar etc are in the other order.

symbolic procedure vjxmap(fn, fn1, args, varlocs, context);
  begin
    scalar carp, var, avar, moveon, l1, r, s, closed;
% if the value of a mapping function is not needed I demote from mapcar to
% mapc or from maplist to map.
    if fn = 'mapc or fn = 'mapcar or fn = 'mapcan then carp := t;
    args := args;
    if atom args then error(0,"bad arguments to map function");
    while eqcar(fn1, 'function) or
          (eqcar(fn1, 'quote) and eqcar(cadr fn1, 'lambda)) do <<
       fn1 := cadr fn1;
       closed := t >>;
% if closed is false I will insert FUNCALL since I am invoking a function
% stored in a variable - NB this means that the word FUNCTION becomes
% essential when using mapping operators - this is because I have built
% a 2-Lisp rather than a 1-Lisp.
    l1 := gensym();
    r := gensym();
    s := gensym();
    var := gensym();
    avar := var;
    if carp then avar := list('car, avar);
% Here if closed is true and fn1 is of the form (lambda (w) ... w ...) where
% the local variable occurs only once in the body, and w is not fluid or
% global (and there had better be no other bindings to wreck scope) then I
% might simplify by doing a textual substitution here rather than a real
% lambda binding. Maybe I should detect such cases in the code that
% compiles the application of lambda expressions?  For now do not bother!
    if closed then fn1 := list(fn1, avar)
    else fn1 := list('funcall, fn1, avar);
    moveon := list('setq, var, list('cdr, var));
    if fn = 'map or fn = 'mapc then fn := sublis(
       list('l1 . l1, 'var . var,
            'fn . fn1, 'args . args, 'moveon . moveon),
       '(prog (var)
             (setq var args)
       l1    (cond
                ((not var) (return nil)))
             fn
             moveon
             (go l1)))
    else if fn = 'maplist or fn = 'mapcar then fn := sublis(
       list('l1 . l1, 'var . var,
            'fn . fn1, 'args . args, 'moveon . moveon, 'r . r),
       '(prog (var r)
             (setq var args)
       l1    (cond
                ((not var) (return (reversip r))))
             (setq r (cons fn r))
             moveon
             (go l1)))
    else fn := sublis(
       list('l1 . l1, 'l2 . gensym(), 'var . var,
            'fn . fn1, 'args . args, 'moveon . moveon,
            'r . gensym(), 's . gensym()),
       '(prog (var r s)
             (setq var args)
             (setq r (setq s (list nil)))
       l1    (cond
                ((not var) (return (cdr r))))
             (rplacd s fn)
       l2    (cond
                ((not (atom (cdr s))) (setq s (cdr s)) (go l2)))
             moveon
             (go l1)));
    loadval(fn, varlocs, context)
  end;

symbolic procedure vjmap(a, varlocs, context);
    vjxmap('map, car a, cadr a, varlocs, context);

symbolic procedure vjmap(a, varlocs, context);
    vjxmap('map, car a, cadr a, varlocs, context);

symbolic procedure vjmaplist(a, varlocs, context);
    vjxmap('maplist, car a, cadr a, varlocs, context);

symbolic procedure vjmapc(a, varlocs, context);
    vjxmap('mapc, car a, cadr a, varlocs, context);

symbolic procedure vjmapcar(a, varlocs, context);
    vjxmap('mapcar, car a, cadr a, varlocs, context);

symbolic procedure vjmapcon(a, varlocs, context);
    vjxmap('mapcon, car a, cadr a, varlocs, context);

symbolic procedure vjmapcan(a, varlocs, context);
    vjxmap('mapcan, car a, cadr a, varlocs, context);

put('map,     'vjhelper, function vjmap);
put('maplist, 'vjhelper, function vjmaplist);
put('mapc,    'vjhelper, function vjmapc);
put('mapcar,  'vjhelper, function vjmapcar);
put('mapcon,  'vjhelper, function vjmapcon);
put('mapcan,  'vjhelper, function vjmapcan);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




symbolic procedure javawhiletrue(p, x, varlocs, context);
  begin
    scalar l1, l2;
    l1 := gensym();
    l2 := gensym();
    lookup!-label(l2);
    inst2('GOTO, 0, l2);
    setlabel(l1);
    loadval(x, varlocs, context);
    setlabel(l2);
    loadval(p, varlocs, context);
    lookup!-label(l1);
    inst2('IFNE, 0, l1) %change to IFEQ for whilefalse
  end;

symbolic procedure javawhilefalse(p, x, varlocs, context);
  begin
    scalar l1, l2;
    l1 := gensym();
    l2 := gensym();
    lookup!-label(l2);
    inst2('GOTO, 0, l2);
    setlabel(l1);
    loadval(x, varlocs, context);
    setlabel(l2);
    loadval(p, varlocs, context);
    lookup!-label(l1);
    inst2('IFEQ, 0, l1)
  end;



end;

% end of vjacn.red
