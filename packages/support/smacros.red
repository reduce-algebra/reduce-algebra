% smacros.red - automatically generated from other source files

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


symbolic smacro procedure !*!*a2i(u,vars); 
   if intexprnp(u,vars) then u else {'ieval,u};


symbolic smacro procedure !*!*s2a(u,vars); u;


symbolic smacro procedure !*!*s2i(u,vars); if fixp u then u else {'!*s2i,u};


symbolic smacro procedure !*i2gi u; cons('!:gi!:,cons(u,0));


symbolic smacro procedure !*i2rn u; cons('!:rn!:,cons(u,1));


symbolic smacro procedure !*n2f u; if zerop u then nil else u;


symbolic smacro procedure !*s2i u; if fixp u then u else typerr(u,"integer");


symbolic smacro procedure !*sqprint u; sqprint cadr u;


symbolic smacro procedure !:gi!:unitconv(u,v); 
   unitconv(u,v,get('!:gi!:,'units));


symbolic smacro procedure !:minusp u; 
   if atom u then minusp u else apply1(get(car u,'minusp),u);


symbolic smacro procedure !:onep u; 
   if atom u then onep u else apply1(get(car u,'onep),u);


symbolic smacro procedure !:rn2rd x; 
   if and(!*roundall,!*rounded) then !*rn2rd x else x;


symbolic smacro procedure abs!: nmbr; 
   if greaterp(cadr nmbr,0) then nmbr
    else cons('!:rd!:,cons(minus cadr nmbr,cddr nmbr));


symbolic smacro procedure absf u; if minusf u then negf u else u;


symbolic smacro procedure aconc(u,v); nconc(u,{v});


symbolic smacro procedure aconc!*(u,v); nconc(u,{v});


symbolic smacro procedure acos!* u; acos!:(u,!:bprec!:);


symbolic smacro procedure addcomment u; setq(cursym!*,u);


symbolic smacro procedure adddm!*(u,v); 
   if null u then v else if null v then u else adddm(u,v);


symbolic smacro procedure algid(u,vars); 
   if or(atsoc(u,vars),flagp(u,'share)) then u else mkquote u;


symbolic smacro procedure algmodep u; 
   and(not atom u,memq(car u,'(aeval aeval!*)));


symbolic smacro procedure applmacro(u,v,w); apply1(u,cons(w,v));


symbolic smacro procedure arbstat; 
   <<lpriw("*****","ARB no longer supported"); symerr('if,t)>>;


symbolic smacro procedure argsofopr u; get(u,'number!-of!-args);


symbolic smacro procedure arraychk u; if null u then 'array else nil;


symbolic smacro procedure arraylength u; cons('list,get(u,'dimension));


symbolic smacro procedure arrayp u; eq(get(u,'rtype),'array);


symbolic smacro procedure asin!* u; asin!:(u,!:bprec!:);


symbolic smacro procedure atan!* u; atan!:(u,!:bprec!:);


symbolic smacro procedure bfdiffer(u,v); 
   if atom u then difference(u,v) else difbf(u,v);


symbolic smacro procedure bfdivide(u,v); 
   if atom u then quotient(u,v) else csl_normbf divide!:(u,v,!:bprec!:);


symbolic smacro procedure bflerrmsg u; error(0,{"Invalid argument to",u});


symbolic smacro procedure bflessp(a,b); 
   if atom a then lessp(a,b) else grpbf(b,a);


symbolic smacro procedure bfplus(u,v); 
   if atom u then plus2(u,v) else plubf(u,v);


symbolic smacro procedure bfprin!: u; bfprin0 u;


symbolic smacro procedure bftimes(u,v); 
   if atom u then times2(u,v) else csl_timbf(u,v);


symbolic smacro procedure bftrim!: v; 
   csl_normbf round!:mt(v,difference(!:bprec!:,3));


symbolic smacro procedure bfzerop!: u; equal(cadr u,0);


symbolic smacro procedure boolvalue!* u; and(u,null equal(u,0));


symbolic smacro procedure breakp u; 
   member(u,'(!< !> !; !: != !) !+ !- !, !' !"));


symbolic smacro procedure bye; <<close!-output!-files(); stop 0>>;


symbolic smacro procedure c!-end; c!-end1 t;


symbolic smacro procedure c!:atomcar x; 
   and(or(eqcar(x,'cons),eqcar(x,'list)),not null cdr x,
       c!:certainlyatom cadr x);


symbolic smacro procedure c!:ccall(fn,args,env); c!:ccall1(fn,args,env);


symbolic smacro procedure c!:ccatch(u,env); error(0,"catch");


symbolic smacro procedure c!:ccompile_let(u,env); error(0,"compiler-let");


symbolic smacro procedure c!:cde(u,env); error(0,"de");


symbolic smacro procedure c!:cdeclare(u,env); error(0,"declare");


symbolic smacro procedure c!:cdefun(u,env); error(0,"defun");


symbolic smacro procedure c!:ceval_when(u,env); error(0,"eval-when");


symbolic smacro procedure c!:cflet(u,env); error(0,"flet");


symbolic smacro procedure c!:clabels(u,env); error(0,"labels");


symbolic smacro procedure c!:clet(x,env); 
   c!:cval(c!:expand!-let(cadr x,cddr x),env);


symbolic smacro procedure c!:clet!*(x,env); 
   c!:cval(c!:expand!-let!*(cadr x,cddr x),env);


symbolic smacro procedure c!:cmacrolet(u,env); error(0,"macrolet");


symbolic smacro procedure c!:cmultiple_value_call(u,env); 
   error(0,"multiple_value_call");


symbolic smacro procedure c!:cmultiple_value_prog1(u,env); 
   error(0,"multiple_value_prog1");


symbolic smacro procedure c!:comassoc x; 
   if or(c!:certainlyatom cadr x,c!:atomkeys caddr x) then cons('atsoc,cdr x)
    else nil;


symbolic smacro procedure c!:comdelete x; 
   if or(c!:certainlyatom cadr x,c!:atomlist caddr x) then cons('deleq,cdr x)
    else nil;


symbolic smacro procedure c!:commember x; 
   if or(c!:certainlyatom cadr x,c!:atomlist caddr x) then cons('memq,cdr x)
    else nil;


symbolic smacro procedure c!:comsublis x; 
   if c!:atomkeys cadr x then cons('subla,cdr x) else nil;


symbolic smacro procedure c!:concat(a,b); 
   compress cons('!",append(explode2 a,append(explode2 b,'(!"))));


symbolic smacro procedure c!:cprog!*(u,env); error(0,"prog*");


symbolic smacro procedure c!:cprogv(u,env); error(0,"progv");


symbolic smacro procedure c!:cspecform(x,env); error(0,{"special form",x});


symbolic smacro procedure c!:ctestnull(x,env,d1,d2); 
   c!:cjumpif(cadr x,env,d2,d1);


symbolic smacro procedure c!:cthe(u,env); c!:cval(caddr u,env);


symbolic smacro procedure c!:cthrow(u,env); error(0,"throw");


symbolic smacro procedure c!:cunwind_protect(u,env); error(0,"unwind_protect");


symbolic smacro procedure c!:has_calls(a,b); 
   begin scalar visited; return c!:has_calls_1(a,b) end;


symbolic smacro procedure c!:insert1(a,b); if memq(a,b) then b else cons(a,b);


symbolic smacro procedure c!:is_fixnum x; 
   and(fixp x,geq(x,minus 134217728),leq(x,134217727));


symbolic smacro procedure c!:locally_bound(x,env); atsoc(x,car env);


symbolic smacro procedure c!:newreg; 
   begin scalar r; 
      setq(r,c!:my_gensym()); 
      setq(registers,cons(r,registers)); 
      return r
   end;


symbolic smacro procedure c!:one_operand op; 
   <<flag({op},'c!:set_r1); 
     flag({op},'c!:read_r3); 
     put(op,'c!:code,function c!:builtin_one)>>;


symbolic smacro procedure c!:outop(a,b,c,d); 
   if current_block
     then setq(current_contents,cons({a,b,c,d},current_contents));


symbolic smacro procedure c!:passoc(op,r1,r2,r3,depth); 
   c!:printf1("    %v = Lassoc(nil, %v, %v);\n",{r1,r2,r3});


symbolic smacro procedure c!:patom(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (consp(%v) ? nil : lisp_true);\n",{r1,r3});


symbolic smacro procedure c!:patsoc(op,r1,r2,r3,depth); 
   c!:printf1("    %v = Latsoc(nil, %v, %v);\n",{r1,r2,r3});


symbolic smacro procedure c!:peq(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (%v == %v ? lisp_true : nil);\n",{r1,r2,r3});


symbolic smacro procedure c!:pequal(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (equal(%v, %v) ? lisp_true : nil);\n",{r1,r2,r3,r2,r3});


symbolic smacro procedure c!:pfixp(op,r1,r2,r3,depth); 
   c!:printf1("    %v = integerp(%v);\n",{r1,r3});


symbolic smacro procedure c!:pfluidbind(op,r1,r2,r3,depth); nil;


symbolic smacro procedure c!:pget(op,r1,r2,r3,depth); 
   c!:printf1("    %v = get(%v, %v);\n",{r1,r2,r3});


symbolic smacro procedure c!:piadd1(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (Lisp_Object)((int32_t)(%v) + 0x10);\n",{r1,r3});


symbolic smacro procedure c!:pidifference(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (Lisp_Object)(int32_t)((int32_t)%v - (int32_t)%v + TAG_F
IXNUM);\n",{r1,r2,r3});


symbolic smacro procedure c!:pifatom(s,depth); c!:printf1("!consp(%v)",{car s});


symbolic smacro procedure c!:pifeq(s,depth); 
   c!:printf1("%v == %v",{car s,cadr s});


symbolic smacro procedure c!:pifequal(s,depth); 
   c!:printf1("equal(%v, %v)",{car s,cadr s,car s,cadr s});


symbolic smacro procedure c!:pifigreaterp(s,depth); 
   c!:printf1("((int32_t)(%v)) > ((int32_t)(%v))",{car s,cadr s});


symbolic smacro procedure c!:pifilessp(s,depth); 
   c!:printf1("((int32_t)(%v)) < ((int32_t)(%v))",{car s,cadr s});


symbolic smacro procedure c!:pifizerop(s,depth); 
   c!:printf1("(%v) == 1",{car s});


symbolic smacro procedure c!:pifnull(s,depth); c!:printf1("%v == nil",{car s});


symbolic smacro procedure c!:pifnumber(s,depth); 
   c!:printf1("is_number(%v)",{car s});


symbolic smacro procedure c!:pifsymbol(s,depth); 
   c!:printf1("symbolp(%v)",{car s});


symbolic smacro procedure c!:pigreaterp(op,r1,r2,r3,depth); 
   c!:printf1("    %v = ((intptr_t)%v > (intptr_t)%v) ? lisp_true : nil;\n",
              {r1,r2,r3});


symbolic smacro procedure c!:pilessp(op,r1,r2,r3,depth); 
   c!:printf1("    %v = ((intptr_t)%v < (intptr_t)%v) ? lisp_true : nil;\n",
              {r1,r2,r3});


symbolic smacro procedure c!:piminus(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (Lisp_Object)(2-((int32_t)(%v)));\n",{r1,r3});


symbolic smacro procedure c!:piminusp(op,r1,r2,r3,depth); 
   c!:printf1("    %v = ((intptr_t)(%v) < 0 ? lisp_true : nil);\n",{r1,r3});


symbolic smacro procedure c!:piplus2(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (Lisp_Object)(int32_t)((int32_t)%v + (int32_t)%v - TAG_F
IXNUM);\n",{r1,r2,r3});


symbolic smacro procedure c!:pisub1(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (Lisp_Object)((int32_t)(%v) - 0x10);\n",{r1,r3});


symbolic smacro procedure c!:pitimes2(op,r1,r2,r3,depth); 
   c!:printf1("    %v = fixnum_of_int((int32_t)(int_of_fixnum(%v) * int_of_fixnu
m(%v)));\n",{r1,r2,r3});


symbolic smacro procedure c!:pldrglob(op,r1,r2,r3,depth); 
   c!:printf1("    %v = qvalue(elt(env, %s)); %</* %c %<*/\n",{r1,r3,r2});


symbolic smacro procedure c!:pmember(op,r1,r2,r3,depth); 
   c!:printf1("    %v = Lmember(nil, %v, %v);\n",{r1,r2,r3});


symbolic smacro procedure c!:pmemq(op,r1,r2,r3,depth); 
   c!:printf1("    %v = Lmemq(nil, %v, %v);\n",{r1,r2,r3});


symbolic smacro procedure c!:pmovk(op,r1,r2,r3,depth); 
   c!:printf1("    %v = elt(env, %s); %</* %c %<*/\n",{r1,r3,r2});


symbolic smacro procedure c!:pmovr(op,r1,r2,r3,depth); 
   c!:printf1("    %v = %v;\n",{r1,r3});


symbolic smacro procedure c!:pnilglob(op,r1,r2,r3,depth); 
   c!:printf1("    qvalue(elt(env, %s)) = nil; %</* %c %<*/\n",{r3,r2});


symbolic smacro procedure c!:pnull(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (%v == nil ? lisp_true : nil);\n",{r1,r3});


symbolic smacro procedure c!:pnumberp(op,r1,r2,r3,depth); 
   c!:printf1("    %v = (is_number(%v) ? lisp_true : nil);\n",{r1,r3});


symbolic smacro procedure c!:pqcar(op,r1,r2,r3,depth); 
   c!:printf1("    %v = qcar(%v);\n",{r1,r3});


symbolic smacro procedure c!:pqcdr(op,r1,r2,r3,depth); 
   c!:printf1("    %v = qcdr(%v);\n",{r1,r3});


symbolic smacro procedure c!:pqgetv(op,r1,r2,r3,depth); 
   <<c!:printf1("    %v = *(Lisp_Object *)((char *)%v + (CELL-TAG_VECTOR) +",
                {r1,r2}); 
     c!:printf1(" ((int32_t)%v/(16/CELL)));\n",{r3})>>;


symbolic smacro procedure c!:pqputv(op,r1,r2,r3,depth); 
   <<c!:printf1("    *(Lisp_Object *)((char *)%v + (CELL-TAG_VECTOR) +",{r2}); 
     c!:printf1(" ((int32_t)%v/(16/CELL))) = %v;\n",{r3,r1})>>;


symbolic smacro procedure c!:preloadenv(op,r1,r2,r3,depth); 
   c!:printf1("    env = stack[%s];\n",{minus reloadenv});


symbolic smacro procedure c!:pstrglob(op,r1,r2,r3,depth); 
   c!:printf1("    qvalue(elt(env, %s)) = %v; %</* %c %<*/\n",{r3,r1,r2});


symbolic smacro procedure c!:small_number x; 
   and(fixp x,geq(x,least_fixnum),leq(x,greatest_fixnum));


symbolic smacro procedure c!:startblock s; 
   <<setq(current_block,s); setq(current_contents,nil)>>;


symbolic smacro procedure c!:valid_fndef(args,body); 
   if or(memq('!&optional,args),memq('!&rest,args)) then nil
    else c!:valid_list body;


symbolic smacro procedure c!:valid_let x; 
   if null x then t
    else if not c!:valid_cond car x then nil else c!:valid_list cdr x;


symbolic smacro procedure c!:valid_prog x; c!:valid_list cdr x;


symbolic smacro procedure c!:valid_quote x; t;


symbolic smacro procedure c!:valid_specform x; nil;


symbolic smacro procedure c_end; 
   begin 
      if null s!:cmod_name then return nil; 
      s!:cend(); 
      setq(dfprint!*,s!:dfprintsave); 
      setq(!*defn,nil); 
      setq(!*comp,cdr s!:cmod_name); 
      setq(s!:cmod_name,nil); 
      return nil
   end;


symbolic smacro procedure cdarx u; cdr carx(u,'cdar);


symbolic smacro procedure cflot x; 
   if floatp x then x else if atom x then float x else bf2flr x;


symbolic smacro procedure chkrn!* u; if !*!*roundbf then u else bf2flck u;


symbolic smacro procedure choose(x,n); quotient(perm(x,n),factorial x);


symbolic smacro procedure clear_source_database; 
   <<setq(!*where_defined!*,mkhash(10,2,1.5)); nil>>;


symbolic smacro procedure clfarg; setq(farglist!*,nil);


symbolic smacro procedure clogsq x; cons(clogf car x,clogf cdr x);


symbolic smacro procedure comfac!-to!-poly u; if null car u then cdr u else {u};


symbolic smacro procedure comm_kernels u; comm_kernels1(u,nil);


symbolic smacro procedure compile!-file!*(fromfile,!&optional,tofile); 
   s!:compile!-file!*(fromfile,tofile,t,t);


symbolic smacro procedure concat(u,v); 
   compress cons('!",append(explode2 u,nconc(explode2 v,{'!"})));


symbolic smacro procedure concat2(u,v); concat(u,v);


symbolic smacro procedure condterpri; 
   and(!*output,!*echo,!*extraecho,
       or(null !*int,ifl!*),null !*defn,null !*demo,terpri());


symbolic smacro procedure conv!:bf2i nmbr; ash1(cadr nmbr,cddr nmbr);


symbolic smacro procedure convertmode(exprn,vars,target,source); 
   convertmode1(form1(exprn,vars,source),vars,target,source);


symbolic smacro procedure convprec!* u; 
   convchk (if atom u then u else cons('!:rd!:,u));


symbolic smacro procedure cos!* u; cos!:(u,!:bprec!:);


symbolic smacro procedure cr2rderr; 
   error(0,"complex to real type conversion requires zero imaginary part");


symbolic smacro procedure crarg!* u; 
   rdatan2!*(cons('!:rd!:,cddr u),cons('!:rd!:,cadr u));


symbolic smacro procedure crlogb!*(u,b); cr!:quotient(crlog!* u,crlog!* b);


symbolic smacro procedure crn!:minusp u; and(equal(caddr u,0),minusp caadr u);


symbolic smacro procedure crn!:onep u; 
   and(equal(car cddr u,0),equal(cadr u,'(1 . 1)));


symbolic smacro procedure crn!:prep u; 
   crnprep1 cons(cons('!:rn!:,cadr u),cons('!:rn!:,cddr u));


symbolic smacro procedure crn!:simp u; cons(cons('!:crn!:,u),1);


symbolic smacro procedure crn!:zerop u; 
   and(equal(car cadr u,0),equal(car cddr u,0));


symbolic smacro procedure crnorm!* u; 
   rdhypot!*(cons('!:rd!:,cadr u),cons('!:rd!:,cddr u));


symbolic smacro procedure crprcd u; 
   (lambda(rl,im); cons(rl,im))(convprec!* cadr u,convprec!* cddr u);


symbolic smacro procedure cutf(u,x,n); if ilessp(n,1) then u else cutf1(u,x,n);


symbolic smacro procedure dated!-gensym u; dated!-name u;


symbolic smacro procedure dcombine!*(u,v,w); 
   if and(atom u,atom v) then apply2(w,u,v) else dcombine(u,v,w);


symbolic smacro procedure decomposef1(f,msg); decomposef2(cons(f,1),msg);


symbolic smacro procedure decomposegensym; 
   compress append('(!! !d !! c !! !.),
                   explode2 setq(decomposegensym!*,plus2(decomposegensym!*,1)));


symbolic smacro procedure decprec2internal p; 
   plus2(ceiling times2(p,log2of10),3);


symbolic smacro procedure deg2rad x; times2(x,pi!/180);


symbolic smacro procedure delcp u; flagp(u,'delchar);


symbolic smacro procedure den u; mk!*sq cons(cdr simp!* u,1);


symbolic smacro procedure deox u; proceox0(car u,'expr,cadr u,caddr u);


symbolic smacro procedure dimension u; get(u,'dimension);


symbolic smacro procedure dmconv0 dmd; 
   setq(dmd!*,
        if null dmd then '!:rn!:
         else if eq(dmd,'!:gi!:) then '!:crn!:
         else dmd);


symbolic smacro procedure dms2deg l; 
   plus2(quotient(plus2(quotient(caddr l,60.0),cadr l),60.0),car l);


symbolic smacro procedure dms2rad!* u; deg2rad!* dms2deg!* u;


symbolic smacro procedure dn!:prin u; bfprin0x(cadr u,cddr u);


symbolic smacro procedure doindex u; setprifn(u,'indexprin);


symbolic smacro procedure donoargs u; setprifn(u,'noargsprin);


symbolic smacro procedure down u; factor1(u,t,'dnl!*);


symbolic smacro procedure downpower(pol,n); downpower1(pol,caaar pol,n);


symbolic smacro procedure dsox u; proceox0(car u,'smacro,cadr u,caddr u);


symbolic smacro procedure e!*; !:e !:bprec!:;


symbolic smacro procedure emtch u; 
   if atom u then u else (lambda x; if x then x else u) opmtch u;


symbolic smacro procedure endstat; 
   begin scalar x; setq(x,cursym!*); comm1 'end; return {x} end;


symbolic smacro procedure eofcheck; 
   and(eq(program!*,!$eof!$),equal(ttype!*,3),setq(eof!*,plus2(eof!*,1)));


symbolic smacro procedure eqexpr u; 
   and(not atom u,flagp(car u,'equalopr),cddr u,null cdddr u);


symbolic smacro procedure eqnerr u; typerr(u,"equation");


symbolic smacro procedure eqnlength u; length cdr u;


symbolic smacro procedure equalreplaceby u; cons('replaceby,u);


symbolic smacro procedure errorp u; or(atom u,cdr u);


symbolic smacro procedure errorset!*(u,v); errorset(u,v,!*backtrace);


symbolic smacro procedure errpri1 u; 
   msgpri("Substitution for",u,"not allowed",nil,t);


symbolic smacro procedure errpri2(u,v); 
   msgpri("Syntax error:",u,"invalid",nil,v);


symbolic smacro procedure evalleq(u,v); not evalgreaterp(u,v);


symbolic smacro procedure evallessp(u,v); evalgreaterp(v,u);


symbolic smacro procedure evalneq(u,v); not evalequal(u,v);


symbolic smacro procedure evalwhereexp u; 
   evalletsub({cdar u,{'aeval,mkquote {'aeval,carx(cdr u,'where)}}},nil);


symbolic smacro procedure exchk u; exchk1(u,nil,nil,nil);


symbolic smacro procedure exp!* u; exp!:(u,!:bprec!:);


symbolic smacro procedure expchk u; if !*exp then u else offexpchk u;


symbolic smacro procedure explodex u; 
   if numberp u then explode u
    else if stringp u then reversip cdr reversip cdr explode u
    else explodex1 explode u;


symbolic smacro procedure exports u; 
   begin setq(exportslist!*,union(u,exportslist!*)) end;


symbolic smacro procedure exppri(u,v); assgnpri(u,nil,v);


symbolic smacro procedure exptchksq u; 
   if null !*combineexpt then u else multsq(exptchk car u,invsq exptchk cdr u);


symbolic smacro procedure exptmod!:(u,n); 
   !*modular2f general!-modular!-expt(cdr u,n);


symbolic smacro procedure expttermp(u,v); 
   if eqcar(u,'expt) then expttermp1(cadr u,v) else expttermp1(u,v);


symbolic smacro procedure fac!-merge(u,v); 
   cons(multf(car u,car v),append(cdr u,cdr v));


symbolic smacro procedure factor u; factor1(u,t,'factors!*);


symbolic smacro procedure factor!-coeffs u; {1,u};


symbolic smacro procedure factorize!-form!-recursion u; fctrf1 u;


symbolic smacro procedure fancy!-begin; {fancy!-pos!*,fancy!-line!*};


symbolic smacro procedure fancy!-condpri0 u; fancy!-condpri(u,0);


symbolic smacro procedure fancy!-end(r,s); 
   <<if equal(r,'failed)
       then <<setq(fancy!-line!*,car s); setq(fancy!-pos!*,cadr s)>>; 
     r>>;


symbolic smacro procedure fancy!-fail(pos,fl); 
   <<setq(overflowed!*,nil); 
     setq(fancy!-pos!*,pos); 
     setq(fancy!-line!*,fl); 
     'failed>>;


symbolic smacro procedure fancy!-last!-symbol; 
   if fancy!-line!* then car fancy!-line!*;


symbolic smacro procedure fancy!-matpri u; fancy!-matpri1(cdr u,nil);


symbolic smacro procedure fancy!-partialdfpri(u,l); 
   fancy!-dfpri0(u,l,'partial!-df);


symbolic smacro procedure fancy!-prin2 u; fancy!-prin2!*(u,nil);


symbolic smacro procedure fancy!-prin2number u; 
   if testing!-width!* then fancy!-prin2!*(u,t)
    else fancy!-prin2number1 (if atom u then explode2 u else u);


symbolic smacro procedure fancy!-print!-function!-arguments u; 
   fancy!-in!-brackets(and(u,{'fancy!-inprint,mkquote '!*comma!*,0,mkquote u}),
                       '!(,'!));


symbolic smacro procedure fancy!-print!-indexlist l; 
   fancy!-print!-indexlist1(l,'!_,nil);


symbolic smacro procedure fancy!-prodpri(u,p); fancy!-sumpri!*(u,p,'prod);


symbolic smacro procedure fancy!-revalpri u; 
   fancy!-maprin0 fancy!-unquote cadr u;


symbolic smacro procedure fancy!-setmatpri(u,v); fancy!-matpri1(cdr v,u);


symbolic smacro procedure fancy!-sqreform u; prepsq!* sqhorner!* cadr u;


symbolic smacro procedure fancy!-sqrtpri u; fancy!-sqrtpri!*(cadr u,2);


symbolic smacro procedure fancy!-sumpri(u,p); fancy!-sumpri!*(u,p,'sum);


symbolic smacro procedure fexpt(x,n); 
   begin scalar w; setq(w,fexpt1(fsplit x,n)); return plus2(car w,cdr w) end;


symbolic smacro procedure fieldp u; and(not atom u,flagp(car u,'field));


symbolic smacro procedure fillin u; if null u then nil else fillin1(u,caar u);


symbolic smacro procedure find!!maxbflexp; 
   <<setq(!!flexperr,t); setq(!!!~xx,expt(2.0,1023)); setq(!!maxbflexp,1022)>>;


symbolic smacro procedure first x; car x;


symbolic smacro procedure flagop u; begin flag(u,'flagop); rlistat u end;


symbolic smacro procedure foprin op; 
   (lambda x; if null x then fprin2!* op else fprin2!* x) get(op,'prtch);


symbolic smacro procedure formclear(u,vars,mode); 
   {'clear,formclear1(cdr u,vars,mode)};


symbolic smacro procedure formcond(u,vars,mode); 
   cons('cond,formcond1(cdr u,vars,mode));


symbolic smacro procedure formlet(u,vars,mode); 
   {'let,formlet1(cdr u,vars,mode)};


symbolic smacro procedure formmatch(u,vars,mode); 
   {'match,formlet1(cdr u,vars,mode)};


symbolic smacro procedure formpatch(u,vars,mode); cons('progn,cdr u);


symbolic smacro procedure formprog(u,vars,mode); 
   make_prog_declares(cadr u,formprog1(cddr u,pairvars(cadr u,vars,mode),mode));


symbolic smacro procedure formprogn(u,vars,mode); 
   cons('progn,formclis(cdr u,vars,mode));


symbolic smacro procedure formrederr(u,vars,mode); 
   {'rederr,formc!*(cadr u,vars,mode)};


symbolic smacro procedure formreturn(u,vars,mode); 
   {'return,formc(cadr u,vars,mode)};


symbolic smacro procedure formsaveas(u,vars,mode); 
   {'saveas,formclear1(cdr u,vars,mode)};


symbolic smacro procedure fourth x; cadddr x;


symbolic smacro procedure freeof(u,v); 
   not or(smember(v,u),member(v,assoc(u,depl!*)));


symbolic smacro procedure fterpri u; 
   <<if and(not equal(posn!*,0),u) then terpri(); setq(posn!*,0)>>;


symbolic smacro procedure gbfdiff(u,v); 
   cons(difbf(car u,car v),difbf(cdr u,cdr v));


symbolic smacro procedure gbfdot(u,v); 
   plubf(csl_timbf(car u,car v),csl_timbf(cdr u,cdr v));


symbolic smacro procedure gbfplus(u,v); 
   cons(plubf(car u,car v),plubf(cdr u,cdr v));


symbolic smacro procedure gbfrsq u; 
   plubf(csl_timbf(car u,car u),csl_timbf(cdr u,cdr u));


symbolic smacro procedure gcdfd(u,v); 
   if flagp(dmode!*,'field) then 1 else gcdfd1(u,v);


symbolic smacro procedure general!-modular!-minus a; 
   if equal(a,0) then a else difference(current!-modulus,a);


symbolic smacro procedure general!-modular!-quotient(a,b); 
   general!-modular!-times(a,general!-modular!-reciprocal b);


symbolic smacro procedure genvar; 
   intern compress append(explode svar,explode setq(scountr,plus2(scountr,1)));


symbolic smacro procedure getinfix u; 
   begin scalar x; return if setq(x,get(u,'prtch)) then x else u end;


symbolic smacro procedure getrtypecar u; getrtype car u;


symbolic smacro procedure gettransferfn(u,v); 
   (lambda x; if x then x else dmoderr(u,v)) get(u,v);


symbolic smacro procedure gffdiff(u,v); 
   cons(difference(car u,car v),difference(cdr u,cdr v));


symbolic smacro procedure gffdot(u,v); 
   plus2(times2(car u,car v),times2(cdr u,cdr v));


symbolic smacro procedure gffmult(r,u); cons(times2(r,car u),times2(r,cdr u));


symbolic smacro procedure gffplus(u,v); 
   cons(plus2(car u,car v),plus2(cdr u,cdr v));


symbolic smacro procedure gffrsq u; 
   plus2(times2(car u,car u),times2(cdr u,cdr u));


symbolic smacro procedure gfminus u; cons(bfminus car u,bfminus cdr u);


symbolic smacro procedure gfplus(u,v); 
   if atom car u then gffplus(u,v) else gbfplus(u,v);


symbolic smacro procedure gfquotient(u,v); 
   if atom car u then gffquot(u,v) else gbfquot(u,v);


symbolic smacro procedure gfrotate u; cons(bfminus cdr u,car u);


symbolic smacro procedure gfrsq u; gfdot(u,u);


symbolic smacro procedure gftimes(u,v); 
   if atom car u then gfftimes(u,v) else gbftimes(u,v);


symbolic smacro procedure giminusp!: u; 
   if equal(cadr u,0) then minusp cddr u else minusp cadr u;


symbolic smacro procedure gintequiv!: u; 
   if equal(cddr u,0) then cadr u else nil;


symbolic smacro procedure gionep!: u; and(equal(cadr u,1),equal(cddr u,0));


symbolic smacro procedure giprim im; if equal(im,1) then 'i else {'times,im,'i};


symbolic smacro procedure gizerop!: u; and(equal(cadr u,0),equal(cddr u,0));


symbolic smacro procedure gostat; 
   begin scalar var; 
      setq(var,if eq(scan(),'to) then scan() else cursym!*); 
      scan(); 
      return {'go,var}
   end;


symbolic smacro procedure gox u; <<prin2ox "go to "; prinox car u>>;


symbolic smacro procedure greaterpcdr(a,b); greaterp(cdr a,cdr b);


symbolic smacro procedure hashtagged!-name(base,value); 
   intern list!-to!-string append(explodec base,cons('!_,s!:stamp md60 value));


symbolic smacro procedure icbrt x; irootn(fix x,3);


symbolic smacro procedure idcompare(u,v); idcomp1(explode2 u,explode2 v);


symbolic smacro procedure identity(u,vars); u;


symbolic smacro procedure igetv(u,v); getv(u,v);


symbolic smacro procedure imports u; 
   begin setq(importslist!*,union(u,importslist!*)) end;


symbolic smacro procedure in u; in_non_empty_list u;


symbolic smacro procedure infinityp u; 
   (lambda x; not or(eq(x,'!-),digit x)) car explode u;


symbolic smacro procedure initrlisp; 
   <<setq(statcounter,0); 
     setq(crbuflis!*,nil); 
     setq(spare!*,0); 
     setq(!*int,t); 
     nil>>;


symbolic smacro procedure intconv x; 
   if or(null dmode!*,memq(dmode!*,'(!:rd!: !:cr!:))) then x
    else apply1(get(dmode!*,'i2d),x);


symbolic smacro procedure internal!-primep n; 
   if greaterp(n,largest!-small!-modulus) then general!-primep n
    else small!-primep n;


symbolic smacro procedure invbf u; csl_normbf divide!:(bfone!*,u,!:bprec!:);


symbolic smacro procedure iputv(u,v,w); putv(u,v,w);


symbolic smacro procedure iroot(n,r); 
   begin scalar tmp; 
      setq(tmp,irootn(n,r)); 
      return if equal(expt(tmp,r),n) then tmp else nil
   end;


symbolic smacro procedure kernels u; kernels1(u,nil);


symbolic smacro procedure labox u; <<prinox car u; prin2ox ": ">>;


symbolic smacro procedure lengthcdr u; length cdr u;


symbolic smacro procedure leq!:(n1,n2); not greaterp!:(n1,n2);


symbolic smacro procedure lessp!:(n1,n2); greaterp!:(n2,n1);


symbolic smacro procedure lesspcar(a,b); lessp(car a,car b);


symbolic smacro procedure lesspcdadr(a,b); lessp(cdadr a,cdadr b);


symbolic smacro procedure lesspcdr(a,b); lessp(cdr a,cdr b);


symbolic smacro procedure lhs u; lhs!-rhs(u,'cadr);


symbolic smacro procedure linfacf u; trykrf(u,'(0 1));


symbolic smacro procedure lispeval u; eval u;


symbolic smacro procedure load!-latest!-patches; load!-patches!-file();


symbolic smacro procedure log!* u; log!:(u,!:bprec!:);


symbolic smacro procedure logarg(a,c); if equal(c,1) then a else {'expt,a,c};


symbolic smacro procedure lprim u; and(!*msg,lpriw("***",u));


symbolic smacro procedure makearbcomplex; 
   begin scalar ans; 
      setq(!!arbint,plus2(!!arbint,1)); 
      setq(ans,car simp!* {'arbcomplex,!!arbint}); 
      return ans
   end;


symbolic smacro procedure makelist u; cons('list,u);


symbolic smacro procedure maprin u; 
   if outputhandler!* then apply2(outputhandler!*,'maprin,u)
    else if not overflowed!* then maprint(u,0);


symbolic smacro procedure mathprint l; <<terpri!* t; maprin l; terpri!* t>>;


symbolic smacro procedure max2!:(a,b); if greaterp!:(a,b) then a else b;


symbolic smacro procedure mchkopt(u,v); 
   (lambda o; if o then mchkopt1(u,v,o)) get(car v,'optional);


symbolic smacro procedure mconv v; <<dmconv0 dmode!*; mconv1 v>>;


symbolic smacro procedure min2!:(a,b); if greaterp!:(a,b) then b else a;


symbolic smacro procedure minus!: nmbr; 
   cons('!:rd!:,cons(minus cadr nmbr,cddr nmbr));


symbolic smacro procedure minusp!: x; 
   and(and(eqcar(x,'!:rd!:),not atom cdr x),lessp(cadr x,0));


symbolic smacro procedure mkabsf0 u; simp {'abs,mk!*sq cons(u,1)};


symbolic smacro procedure mkblock(u,v); cons('rblock,cons(u,v));


symbolic smacro procedure mkcrn(u,v); cons('!:crn!:,cons(u,v));


symbolic smacro procedure mkdcrn u; 
   cons(cons('!:crn!:,cons(cons(0,1),cons(1,1))),1);


symbolic smacro procedure mkdgi u; cons(cons('!:gi!:,cons(0,1)),1);


symbolic smacro procedure mkdmoderr(u,v); 
   {'lambda,'(!*x!*),{'dmoderr,mkquote u,mkquote v}};


symbolic smacro procedure mkexpt(u,n); if equal(n,1) then u else {'expt,u,n};


symbolic smacro procedure mkgi(re,im); cons('!:gi!:,cons(re,im));


symbolic smacro procedure mkprog(u,v); cons('prog,cons(u,v));


symbolic smacro procedure mkround u; if atom u then cons('!:rd!:,u) else u;


symbolic smacro procedure mksetshare(u,v); 
   mksetq(u,{'progn,'(setq alglist!* (cons nil nil)),v});


symbolic smacro procedure mksp(u,p); getpower(fkern u,p);


symbolic smacro procedure mkstrng u; u;


symbolic smacro procedure mktimes u; 
   if null cdr u then car u else cons('times,u);


symbolic smacro procedure mkvar(u,v); u;


symbolic smacro procedure mod!-error u; 
   typerr(u,{"expression mod",current!-modulus});


symbolic smacro procedure moddifference!:(u,v); 
   !*modular2f general!-modular!-difference(cdr u,cdr v);


symbolic smacro procedure moddivide!:(u,v); cons(!*i2mod 0,u);


symbolic smacro procedure modgcd!:(u,v); !*i2mod 1;


symbolic smacro procedure modminusp!: u; 
   if !*balanced_mod then greaterp(times2(2,cdr u),current!-modulus) else nil;


symbolic smacro procedure modonep!: u; equal(cdr u,1);


symbolic smacro procedure modplus!:(u,v); 
   !*modular2f general!-modular!-plus(cdr u,cdr v);


symbolic smacro procedure modprep!: u; cdr u;


symbolic smacro procedure modquotient!:(u,v); 
   !*modular2f general!-modular!-times(cdr u,
                                       general!-modular!-reciprocal cdr v);


symbolic smacro procedure modtimes!:(u,v); 
   !*modular2f general!-modular!-times(cdr u,cdr v);


symbolic smacro procedure modzerop!: u; equal(cdr u,0);


symbolic smacro procedure mprino u; mprino1(u,{0,0});


symbolic smacro procedure multdm!*(u,v); 
   if or(null u,null v) then nil else multdm(u,v);


symbolic smacro procedure multsq!*(u,v); 
   if !*intflag!* then !*multsq(u,v) else multsq(u,v);


symbolic smacro procedure mvar_member(u,v); 
   or(equal(u,v),and(null atom v,arglist_member(u,cdr v)));


symbolic smacro procedure name!-for!-patched!-version(name,extra); 
   if member('psl,lispsystem!*) then gensym1 'g
    else hashtagged!-name(name,extra);


symbolic smacro procedure nconc!*(u,v); nconc(u,v);


symbolic smacro procedure negnumberchk u; 
   if and(eqcar(u,'minus),numberp cadr u) then minus cadr u else u;


symbolic smacro procedure negsq u; cons(negf car u,cdr u);


symbolic smacro procedure newvar u; 
   if not idp u then typerr(u,"free variable")
    else intern compress append(explode '!=,explode u);


symbolic smacro procedure noargsprin u; 
   if or(not !*nat,!*fort) then 'failed
    else <<remember!-args(car u,cdr u); maprin car u>>;


symbolic smacro procedure noncom1 u; <<setq(!*ncmp,t); flag({u},'noncom)>>;


symbolic smacro procedure noncomfp u; and(!*ncmp,noncomfp1 u);


symbolic smacro procedure noncomp u; and(!*ncmp,noncomp1 u);


symbolic smacro procedure noncomp!* u; 
   or(noncomp u,and(eqcar(u,'expt),noncomp cadr u));


symbolic smacro procedure nth(u,n); car pnth(u,n);


symbolic smacro procedure num u; mk!*sq cons(car simp!* u,1);


symbolic smacro procedure oem!-supervisor; print eval read();


symbolic smacro procedure off1 u; onoff(u,nil);


symbolic smacro procedure offindex u; setprifn(u,nil);


symbolic smacro procedure offmoderr(u,y); 
   lpriw("***",{"Failed attempt to turn off",u,"when",y,"is on"});


symbolic smacro procedure offnoargs u; setprifn(u,nil);


symbolic smacro procedure omark u; <<rplacd(buffp,{u}); setq(buffp,cdr buffp)>>;


symbolic smacro procedure omarko u; omark {u,0};


symbolic smacro procedure on1 u; onoff(u,t);


symbolic smacro procedure operatorp u; eq(gettype u,'operator);


symbolic smacro procedure ord2(u,v); if ordp(u,v) then {u,v} else {v,u};


symbolic smacro procedure order!: nmbr; 
   if equal(cadr nmbr,0) then 0
    else plus2(msd abs cadr nmbr,difference(cddr nmbr,1));


symbolic smacro procedure ordopcar(a,b); ordop(car a,car b);


symbolic smacro procedure ordpv(u,v); ordpv1(u,v,minus 1,upbv u,upbv v);


symbolic smacro procedure out u; out_non_empty_list u;


symbolic smacro procedure parterr(u,v); 
   msgpri("Expression",u,"does not have part",v,t);


symbolic smacro procedure parterr2(u,v); 
   <<msgpri("Expression",u,"does not have part",v,nil); 0>>;


symbolic smacro procedure patches!-load!-check(u,v); 
   begin 
      put(u,'patchfn,v); 
      if memq(u,loaded!-packages!*) then install!-patches u
   end;


symbolic smacro procedure pause; 
   if null !*int then nil
    else if eq(key!*,'pause) then pause1 nil
    else pause1 nil;


symbolic smacro procedure pi!*; 
   if greaterp(!:prec!:,1000) then !:bigpi !:bprec!: else !:pi !:bprec!:;


symbolic smacro procedure pi!/2!*; csl_timbf(bfhalf!*,pi!*());


symbolic smacro procedure posintegerp u; and(fixp u,greaterp(u,0));


symbolic smacro procedure positive!-powp u; 
   and(not atom car u,memq(caar u,'(abs norm)));


symbolic smacro procedure powers form; powers0(form,nil);


symbolic smacro procedure praddf(u,v); 
   cons(addf(car u,car v),addf(cdr u,cdr v));


symbolic smacro procedure precmsg pr; 
   if greaterp(pr,!!rdprec)
     then <<msgpri(nil,"precision increased to",pr,nil,nil); precision1(pr,t)>>;


symbolic smacro procedure prepd1 u; 
   if atom u then u else apply1(get(car u,'prepfn),u);


symbolic smacro procedure prepexpt u; if equal(caddr u,1) then cadr u else u;


symbolic smacro procedure prepf u; 
   (lambda x; if null x then 0 else replus x) prepf1(u,nil);


symbolic smacro procedure prepreform u; prepreform1(u,append(ordl!*,factors!*));


symbolic smacro procedure prepsq u; 
   if null car u then 0 else sqform(u,function prepf);


symbolic smacro procedure prepsq!*2 u; replus prepsq!*1(u,1,nil);


symbolic smacro procedure prepsqx u; if !*intstr then prepsq!* u else prepsq u;


symbolic smacro procedure prepsqyy u; 
   if eqcar(u,'!*sq) then prepsqxx cadr u else u;


symbolic smacro procedure prettyprint x; 
   <<superprinm(x,posn()); terpri(); nil>>;


symbolic smacro procedure prim!-part u; quotf1(u,comfac!-to!-poly comfac u);


symbolic smacro procedure prin20x u; 
   if rprifn!* then apply1(rprifn!*,u) else prin2 u;


symbolic smacro procedure prin2t u; <<prin2 u; terpri(); u>>;


symbolic smacro procedure prin2x u; setq(outl!*,cons(u,outl!*));


symbolic smacro procedure princl x; s!:prinl0(x,function princ);


symbolic smacro procedure prinl x; s!:prinl0(x,function prin);


symbolic smacro procedure prinsf u; if null u then prin2!* 0 else xprinf2 u;


symbolic smacro procedure print_format(f,pat); 
   put(car f,'print!-format,cons(cons(cdr f,pat),get(car f,'print!-format)));


symbolic smacro procedure print_precision n; print!-precision n;


symbolic smacro procedure printcl x; <<princl x; terpri(); x>>;


symbolic smacro procedure printl x; <<prinl x; terpri(); x>>;


symbolic smacro procedure printprompt u; nil;


symbolic smacro procedure printsf u; <<prinsf u; terpri!* nil; u>>;


symbolic smacro procedure printsq u; <<terpri!* t; sqprint u; terpri!* u; u>>;


symbolic smacro procedure procstat; procstat1 nil;


symbolic smacro procedure prop x; plist x;


symbolic smacro procedure putc(a,b,c); put(a,b,c);


symbolic smacro procedure quadfacf u; trykrf(u,'(-1 0 1));


symbolic smacro procedure quit; <<close!-output!-files(); stop 0>>;


symbolic smacro procedure quoteequation u; 'equation;


symbolic smacro procedure quotelist u; 'list;


symbolic smacro procedure quotfx(u,v); 
   if or(null !*exp,null !*mcd) then quotf(u,v) else quotfx1(u,v);


symbolic smacro procedure quotodd(p,q); 
   if and(atom p,atom q) then int!-equiv!-chk mkrn(p,q) else lowest!-terms(p,q);


symbolic smacro procedure quotox u; 
   if stringp u then prinox u else <<prin2ox "'"; prinsox car u>>;


symbolic smacro procedure quotsq(u,v); multsq(u,invsq v);


symbolic smacro procedure rad2deg x; times2(x,!180!/pi);


symbolic smacro procedure rad2deg!: x; 
   csl_normbf divide!:(csl_timbf(x,!:180!*),pi!*(),!:bprec!:);


symbolic smacro procedure rad2dms x; deg2dms rad2deg x;


symbolic smacro procedure rad2dms!* u; deg2dms!* rad2deg!* u;


symbolic smacro procedure raddsq(u,n); simpexpt {mk!*sq u,{'quotient,1,n}};


symbolic smacro procedure ratnump!: x; eqcar(x,'!:ratnum!:);


symbolic smacro procedure rd2rn1 n; 
   if atom cdr n then ft2rn1 cdr n else bf2rn1 n;


symbolic smacro procedure rd!:explode u; 
   bfexplode0 bftrim!: (if atom cdr u then fl2bf cdr u else u);


symbolic smacro procedure rd!:minus u; 
   if atom cdr u then cons('!:rd!:,minus cdr u) else minus!: u;


symbolic smacro procedure rd!:minusp u; 
   if atom cdr u then minusp cdr u else minusp!: u;


symbolic smacro procedure rd!:onep u; 
   if atom cdr u then lessp(abs difference(1.0,cdr u),!!fleps1)
    else equal!:(bfone!*,bftrim!: u);


symbolic smacro procedure rd!:prin u; 
   bfprin!: bftrim!: (if atom cdr u then fl2bf cdr u else u);


symbolic smacro procedure rd!:zerop u; 
   if atom cdr u then zerop cdr u else equal(cadr u,0);


symbolic smacro procedure rdacos!* u; 
   (lambda x; mkround (if atom x then acos x else acos!* x)) convprec u;


symbolic smacro procedure rdacosh!* u; 
   (lambda x; mkround (if atom x then acosh x else acosh!* x)) convprec u;


symbolic smacro procedure rdacot!* u; 
   (lambda x; mkround (if atom x then acot x else difbf(pi!/2!*(),atan!* x)))
    convprec u;


symbolic smacro procedure rdacoth!* u; 
   (lambda x; mkround (if atom x then acoth x else atanh!* invbf x)) convprec u;


symbolic smacro procedure rdacsc!* u; 
   (lambda x; mkround (if atom x then acsc x else asin!* invbf x)) convprec u;


symbolic smacro procedure rdasec!* u; 
   (lambda x; 
       mkround (if atom x then asec x else difbf(pi!/2!*(),asin!* invbf x)))
    convprec u;


symbolic smacro procedure rdasin!* u; 
   (lambda x; mkround (if atom x then asin x else asin!* x)) convprec u;


symbolic smacro procedure rdasinh!* u; 
   (lambda x; mkround (if atom x then asinh x else asinh!* x)) convprec u;


symbolic smacro procedure rdatan!* u; 
   (lambda x; mkround (if atom x then atan x else atan!* x)) convprec u;


symbolic smacro procedure rdatanh!* u; 
   (lambda x; mkround (if atom x then atanh x else atanh!* x)) convprec u;


symbolic smacro procedure rdcos!* u; 
   (lambda x; mkround (if atom x then cos x else cos!* x)) convprec u;


symbolic smacro procedure rdcosh!* u; 
   (lambda x; mkround (if atom x then cosh x else cosh!* x)) convprec u;


symbolic smacro procedure rde!*; mkround (if !*!*roundbf then e!*() else !!ee);


symbolic smacro procedure rdhalf!*; if !*!*roundbf then bfhalf!* else 0.5;


symbolic smacro procedure rdlog!* u; 
   (lambda x; mkround (if atom x then log x else log!* x)) convprec u;


symbolic smacro procedure rdlog10!* u; 
   (lambda x; mkround (if atom x then log10 x else logb!*(x,bften!*)))
    convprec u;


symbolic smacro procedure rdnorm!* u; if rd!:minusp u then rd!:minus u else u;


symbolic smacro procedure rdone!*; if !*!*roundbf then bfone!* else 1.0;


symbolic smacro procedure rdpi!*; 
   mkround (if !*!*roundbf then pi!*() else !!pii);


symbolic smacro procedure rdprep1 u; 
   if atom cdr u then u else round!:mt(u,!:bprec!:);


symbolic smacro procedure rdqoterr; error(0,"zero divisor in quotient");


symbolic smacro procedure rdsec!* u; 
   (lambda x; mkround (if atom x then sec x else invbf cos!* x)) convprec u;


symbolic smacro procedure rdsech!* u; 
   (lambda x; mkround (if atom x then sech x else invbf cosh!* x)) convprec u;


symbolic smacro procedure rdsqrt!* u; 
   (lambda x; mkround (if atom x then sqrt x else bfsqrt x)) convprec u;


symbolic smacro procedure rdtwo!*; if !*!*roundbf then bftwo!* else 2.0;


symbolic smacro procedure rdzero!*; if !*!*roundbf then bfz!* else 0.0;


symbolic smacro procedure recursiveerror u; 
   msgpri(nil,u,"improperly defined in terms of itself",nil,t);


symbolic smacro procedure red!-char!-downcase u; 
   (lambda x; if x then cdr x else u) atsoc(u,charassoc!*);


symbolic smacro procedure red!-char!-upcase u; 
   (lambda x; if x then car x else u) rassoc(u,charassoc!*);


symbolic smacro procedure rederr u; 
   begin if not !*protfg then lprie u; error1() end;


symbolic smacro procedure remcomma u; 
   if eqcar(u,'!*comma!*) then cdr u else {u};


symbolic smacro procedure remfac u; factor1(u,nil,'factors!*);


symbolic smacro procedure reordsq u; cons(reorder car u,reorder cdr u);


symbolic smacro procedure rerror(packagename,number,message); 
   <<setq(errmsg!*,message); rederr message>>;


symbolic smacro procedure resetparser; if null !*slin then comm1 t;


symbolic smacro procedure resimpcar u; resimp car u;


symbolic smacro procedure rest x; cdr x;


symbolic smacro procedure revalpri u; maprin eval cadr u;


symbolic smacro procedure revalruletst u; 
   (lambda v; if neq(u,v) then let1 {v} else typerr(u,"rule list")) reval u;


symbolic smacro procedure reversip!* u; reversip u;


symbolic smacro procedure revop1 u; 
   if !*val then cons(car u,revlis cdr u) else u;


symbolic smacro procedure revpr u; cons(cdr u,car u);


symbolic smacro procedure rhs u; lhs!-rhs(u,'caddr);


symbolic smacro procedure rlispmain; lispeval '(begin);


symbolic smacro procedure rlistatp u; member(get(u,'stat),'(endstat rlis));


symbolic smacro procedure rmplus u; if eqcar(u,'plus) then cdr u else {u};


symbolic smacro procedure rmsubs; 
   begin 
      rplaca(!*sqvar!*,nil); 
      setq(!*sqvar!*,{t}); 
      setq(alglist!*,cons(nil,nil))
   end;


symbolic smacro procedure rnchoose!*(x,n); choose(rnfixchk x,rnfixchk n);


symbolic smacro procedure rnfix!* x; quotient(cadr x,cddr x);


symbolic smacro procedure rnilog2!* x; ilog2 rnfix!* x;


symbolic smacro procedure rnirootn!*(x,n); irootn(rnfix!* x,rnfixchk n);


symbolic smacro procedure rnminus!: u; cons(car u,cons(!:minus cadr u,cddr u));


symbolic smacro procedure rnonep!: u; and(equal(cadr u,1),equal(cddr u,1));


symbolic smacro procedure rnperm!*(x,n); perm(rnfixchk x,rnfixchk n);


symbolic smacro procedure rnprin u; 
   <<prin2!* cadr u; prin2!* "/"; prin2!* cddr u>>;


symbolic smacro procedure rnquotient!:(u,v); 
   mkrn(times2(cadr u,cddr v),times2(cddr u,cadr v));


symbolic smacro procedure rntimes!:(u,v); 
   mkrn(times2(cadr u,cadr v),times2(cddr u,cddr v));


symbolic smacro procedure rnzerop!: u; equal(cadr u,0);


symbolic smacro procedure round!* x; if atom cdr x then cdr x else x;


symbolic smacro procedure round2a!* a; if atom a then a else round!* a;


symbolic smacro procedure roundbfoff; 
   setq(!*!*roundbf,greaterp(!!rdprec,!!flprec));


symbolic smacro procedure roundbfon; setq(!*!*roundbf,t);


symbolic smacro procedure rplaca!*(u,v); rplaca(u,v);


symbolic smacro procedure rplacd!*(u,v); rplacd(u,v);


symbolic smacro procedure rread; <<prin2x " '"; rread1()>>;


symbolic smacro procedure rsverr x; 
   rerror('rlisp,13,{x,"is a reserved identifier"});


symbolic smacro procedure rtypepart u; 
   if getrtypecar u then 'yetunknowntype else nil;


symbolic smacro procedure rule_error u; rederr {"error in rule:",u,"illegal"};


symbolic smacro procedure s!:alwayseasy x; t;


symbolic smacro procedure s!:comdeclare(x,env,context); 
   begin if !*pwrds then <<princ "+++ "; prin x; princ " ignored"; terpri()>>
   end;


symbolic smacro procedure s!:comgetv(x,env,context); 
   if !*carcheckflag then s!:comcall(x,env,context)
    else s!:comval(cons('qgetv,cdr x),env,context);


symbolic smacro procedure s!:comiplus(x,env,context); 
   s!:comval(expand(cdr x,'iplus2),env,context);


symbolic smacro procedure s!:comitimes(x,env,context); 
   s!:comval(expand(cdr x,'itimes2),env,context);


symbolic smacro procedure s!:comlet(x,env,context); 
   s!:comval(cons('progn,s!:expand_let(cadr x,cddr x)),env,context);


symbolic smacro procedure s!:complus(x,env,context); 
   s!:comval(expand(cdr x,'plus2),env,context);


symbolic smacro procedure s!:comquote(x,env,context); 
   if leq(context,1) then s!:loadliteral(cadr x,env);


symbolic smacro procedure s!:comreturn(x,env,context); 
   s!:comreturn!-from(cons('return!-from,cons(nil,cdr x)),env,context);


symbolic smacro procedure s!:comspecform(x,env,context); 
   error(0,{"special form",x});


symbolic smacro procedure s!:comthe(x,env,context); 
   s!:comval(caddr x,env,context);


symbolic smacro procedure s!:comtimes(x,env,context); 
   s!:comval(expand(cdr x,'times2),env,context);


symbolic smacro procedure s!:comunless(x,env,context); 
   s!:comwhen(list!*('when,{'not,cadr x},cddr x),env,context);


symbolic smacro procedure s!:cout0 u; s!:cout1(u,nil);


symbolic smacro procedure s!:do!-endtest u; if null u then nil else car u;


symbolic smacro procedure s!:do!-result u; if null u then nil else cdr u;


symbolic smacro procedure s!:easyifarg x; 
   or(null cdr x,and(null cddr x,s!:iseasy cadr x));


symbolic smacro procedure s!:endlist l; setq(pendingrpars,cons(l,pendingrpars));


symbolic smacro procedure s!:eval_to_car_eq_safe x; 
   and(or(eqcar(x,'cons),eqcar(x,'list)),not null cdr x,
       s!:eval_to_eq_safe cadr x);


symbolic smacro procedure s!:eval_to_car_eq_unsafe x; 
   and(or(eqcar(x,'cons),eqcar(x,'list)),not null cdr x,
       s!:eval_to_eq_unsafe cadr x);


symbolic smacro procedure s!:expandblock u; 
   cons(car u,cons(cadr u,s!:fully_macroexpand_list cddr u));


symbolic smacro procedure s!:expanddeclare u; u;


symbolic smacro procedure s!:expandeval!-when u; 
   cons(car u,cons(cadr u,s!:fully_macroexpand_list cddr u));


symbolic smacro procedure s!:expandfletvars b; 
   cons(car b,cons(cadr b,s!:fully_macroexpand_list cddr b));


symbolic smacro procedure s!:expandfunction u; u;


symbolic smacro procedure s!:expandgo u; u;


symbolic smacro procedure s!:expandlabels u; s!:expandflet u;


symbolic smacro procedure s!:expandlet!* u; s!:expandlet u;


symbolic smacro procedure s!:expandmacrolet u; s!:expandflet u;


symbolic smacro procedure s!:expandmv!-call u; 
   cons(car u,cons(cadr u,s!:fully_macroexpand_list cddr u));


symbolic smacro procedure s!:expandprog u; 
   cons(car u,cons(cadr u,s!:fully_macroexpand_list cddr u));


symbolic smacro procedure s!:expandprogv u; 
   cons(car u,cons(cadr u,cons(caddr u,s!:fully_macroexpand_list cadddr u)));


symbolic smacro procedure s!:expandreturn!-from u; 
   cons(car u,cons(cadr u,s!:fully_macroexpand_list cddr u));


symbolic smacro procedure s!:expandtagbody u; s!:fully_macroexpand_list u;


symbolic smacro procedure s!:expandthe u; 
   cons(car u,cons(cadr u,s!:fully_macroexpand_list cddr u));


symbolic smacro procedure s!:explodes x; explode x;


symbolic smacro procedure s!:fslout0 u; s!:fslout1(u,nil);


symbolic smacro procedure s!:negate_jump x; 
   if atom x then get(x,'negjump) else rplaca(x,get(car x,'negjump));


symbolic smacro procedure s!:prinhex1 n; 
   princ schar("0123456789abcdef",logand(n,15));


symbolic smacro procedure s!:prinhex2 n; 
   <<s!:prinhex1 truncate(n,16); s!:prinhex1 n>>;


symbolic smacro procedure s!:prinhex4 n; 
   <<s!:prinhex2 truncate(n,256); s!:prinhex2 n>>;


symbolic smacro procedure s!:quotep x; 
   and(!*quotes,not atom x,equal(car x,'quote),not atom cdr x,null cddr x);


symbolic smacro procedure s!:r2i2when(name,args,b,lab,v); 
   cons(car b,s!:r2i2progn(name,args,cdr b,lab,v));


symbolic smacro procedure s!:r2iwhen(name,args,b,lab,v); 
   cons(car b,s!:r2iprogn(name,args,cdr b,lab,v));


symbolic smacro procedure s!:testneq(neg,x,env,lab); 
   s!:testequal(not neg,cons('equal,cdr x),env,lab);


symbolic smacro procedure s!:testnot(neg,x,env,lab); 
   s!:jumpif(not neg,cadr x,env,lab);


symbolic smacro procedure safe!-putd(name,type,body); 
   if getd name then lprim {"Autoload stub for",name,"not defined"}
    else putd(name,type,body);


symbolic smacro procedure savesession u; preserve 'begin;


symbolic smacro procedure sdl2sq(vd,sdl); 
   if equal(cdr vd,1) then univsdl2sq(caar vd,sdl) else mulvsdl2sq(vd,sdl);


symbolic smacro procedure searchtm term; 
   if or(atom term,atom car term) then nil
    else cons(caar term,searchpl cdr term);


symbolic smacro procedure second x; cadr x;


symbolic smacro procedure set!-modulus p; set!-general!-modulus p;


symbolic smacro procedure set!:const(cnst,l); save!:const(cnst,read!:lnum l);


symbolic smacro procedure setcloc!*; 
   setq(cloc!*,if null ifl!* then nil else cons(car ifl!*,cons(1,curline!*)));


symbolic smacro procedure setifngfl(v,y); 
   <<if not globalp v then fluid {v}; set(v,y)>>;


symbolic smacro procedure sfp u; and(not atom u,not atom car u);


symbolic smacro procedure sfpf u; and(not or(atom u,atom car u),sfp caaar u);


symbolic smacro procedure sgn x; 
   if greaterp(x,0) then 1 else if lessp(x,0) then minus 1 else 0;


symbolic smacro procedure showrulesdfn opr; 
   append(showrulesdfn1 opr,showrulesdfn2 opr);


symbolic smacro procedure shut u; shut_non_empty_list u;


symbolic smacro procedure sign!-of u; 
   (lambda s; and(numberp s,s)) car simp!-sign {u};


symbolic smacro procedure simp!*sq u; 
   if and(cadr u,null !*resimp) then car u else resimp1 car u;


symbolic smacro procedure simpcar u; simp car u;


symbolic smacro procedure simpconj u; conjsq simp!* car u;


symbolic smacro procedure simpexpon u; simpexpon1(u,'simp!*);


symbolic smacro procedure simpmax u; 
   s_simpmaxmin('max,function evalgreaterp,u,nil);


symbolic smacro procedure simpmin u; 
   s_simpmaxmin('min,function evallessp,u,nil);


symbolic smacro procedure sin!* u; sin!:(u,!:bprec!:);


symbolic smacro procedure sinh!* x; 
   (lambda y; csl_timbf(bfhalf!*,difbf(y,invbf y))) exp!* x;


symbolic smacro procedure sinitl u; set(u,eval get(u,'initl));


symbolic smacro procedure sort(l,pred); stable!-sortip(append(l,nil),pred);


symbolic smacro procedure sort!-factors l; sort(l,function orderfactors);


symbolic smacro procedure sortip(l,pred); stable!-sortip(l,pred);


symbolic smacro procedure split!-comfac!-part u; split!-comfac(u,1,1);


symbolic smacro procedure sq_member(u,v); 
   or(sf_member(u,car v),sf_member(u,cdr v));


symbolic smacro procedure sqrt!* u; sqrt!:(u,!:bprec!:);


symbolic smacro procedure ss2sf s; 
   if or(atom s,atom car s) then s else sdl2sq(car s,sdlist cadr xx2lx s);


symbolic smacro procedure stable!-sort(l,pred); 
   stable!-sortip(append(l,nil),pred);


symbolic smacro procedure strangeop u; nil;


symbolic smacro procedure string!-downcase u; 
   compress cons('!",append(explode2lc u,'(!")));


symbolic smacro procedure stringox u; 
   <<prin2ox '!"; prin2ox car u; prin2ox '!">>;


symbolic smacro procedure striptag u; if atom u then u else cdr u;


symbolic smacro procedure subs3f u; subs3f1(u,!*match,t);


symbolic smacro procedure take!-impart u; cons(impartf car u,cdr u);


symbolic smacro procedure take!-realpart u; cons(repartf car u,cdr u);


symbolic smacro procedure tan!* u; tan!:(u,!:bprec!:);


symbolic smacro procedure terminalp; and(!*int,null ifl!*);


symbolic smacro procedure terms u; 
   <<lprim "Please use LENGTH instead"; termsf car simp!* u>>;


symbolic smacro procedure terpri0x; 
   if rterfn!* then lispeval {rterfn!*} else terpri();


symbolic smacro procedure terrlst(x,y); error(0,{x," invalid for ",y});


symbolic smacro procedure test_package m; 
   <<load!-module 'remake; test_a_package {m}; 0>>;


symbolic smacro procedure texmacsp; if getenv "TEXMACS_REDUCE_PATH" then t;


symbolic smacro procedure third x; caddr x;


symbolic smacro procedure tildepri u; <<prin2!* "~"; prin2!* cadr u>>;


symbolic smacro procedure times!:(n1,n2); 
   cons('!:rd!:,cons(times2(cadr n1,cadr n2),plus2(cddr n1,cddr n2)));


symbolic smacro procedure timesi!* u; cr!:times(cri!*(),u);


symbolic smacro procedure timesip x; and(eqcar(x,'times),memq('i,cdr x));


symbolic smacro procedure tm_coloredp ec; eqcar(ec,car tm_bprompt());


symbolic smacro procedure tm_compute!-prompt!-string(count,level); 
   tm_color tm_compute!-prompt!-string!-orig(count,level);


symbolic smacro procedure tm_eprompt; {'!],'!\,'! ,compress {'!!,5}};


symbolic smacro procedure tm_pruneltail(l,l1); 
   reversip tm_prunelhead(reversip l,l1);


symbolic smacro procedure tm_pslp; memq('psl,lispsystem!*);


symbolic smacro procedure tms u; tmsf car simp!* u;


symbolic smacro procedure tmsf!* u; 
   if and(numberp u,equal(abs fix u,1)) then 0 else tmsf u;


symbolic smacro procedure to(u,p); cons(u,p);


symbolic smacro procedure tokbquote; 
   begin 
      setq(crchar!*,readch1()); 
      setq(nxtsym!*,{'backquote,rread()}); 
      setq(ttype!*,3); 
      return nxtsym!*
   end;


symbolic smacro procedure token; token1();


symbolic smacro procedure toknump x; 
   or(numberp x,eqcar(x,'!:dn!:),eqcar(x,'!:int!:));


symbolic smacro procedure tokquote; 
   begin 
      setq(crchar!*,readch1()); 
      setq(nxtsym!*,mkquote rread()); 
      setq(ttype!*,4); 
      return nxtsym!*
   end;


symbolic smacro procedure traceset l; mapc(l,function traceset1);


symbolic smacro procedure treesizep(u,n); equal(treesizep1(u,n),0);


symbolic smacro procedure trimcrrl n; trimcr cadr n;


symbolic smacro procedure tstpolyarg(y,u); 
   and(null !*ratarg,neq(y,1),typerr(prepsq u,"polynomial"));


symbolic smacro procedure univariatep pol; 
   and(not or(atom pol,atom car pol),univariatep1(pol,caaar pol));


symbolic smacro procedure unreval u; 
   if or(atom u,null memq(car u,'(aeval reval))) then u else cadr u;


symbolic smacro procedure untraceset l; mapc(l,function untraceset1);


symbolic smacro procedure up u; factor1(u,t,'upl!*);


symbolic smacro procedure uppower(pol,var,n); 
   if equal(caaar pol,var) then uppower1(pol,var,n) else uppower2(pol,var,n);


symbolic smacro procedure validrule u; 
   (lambda x; if null x then nil else {x}) validrule1 u;


symbolic smacro procedure varname u; 
   if not idp car u then typerr(car u,"identifier") else setq(varnam!*,car u);


symbolic smacro procedure varss(v,d); 
   cons(cons(cons(v,nil),1),cons(cons(cons(cons(d,nil),1),nil),1));


symbolic smacro procedure vv!!!*1e10; setq(vv!!,times2(vv!!,10000000000.0));


symbolic smacro procedure writepri(u,v); assgnpri(eval u,nil,v);


symbolic smacro procedure xprinf(u,flg,w); 
   begin and(flg,prin2!* "("); xprinf2 u; and(flg,prin2!* ")") end;


symbolic smacro procedure xread u; 
   begin 
    a: 
      scan(); 
      if and(!*eoldelimp,eq(cursym!*,'!*semicol!*)) then go to a; 
      return xread1 u
   end;


symbolic smacro procedure xsimp u; expchk simp!* u;


symbolic smacro procedure xxsort l; 
   sort(l,function (lambda(a,b); lessp(termorder(car a,car b),0)));


symbolic smacro procedure yetunknowntypeeval(u,v); 
   reval1(eval!-yetunknowntypeexpr(u,v),v);


symbolic smacro procedure zfactor n; zfactor1(n,t);


symbolic smacro procedure znumrnil u; if znumr u then cons(nil,1) else u;


symbolic smacro procedure !*cr2crn u; 
   mkcrn(realrat trimcrrl u,realrat trimcr cddr u);


symbolic smacro procedure !*crn2rd n; 
   if not equal(car cddr n,0) then cr2rderr() else mkround chkrn!* r2bf cadr n;


symbolic smacro procedure !*crn2rn n; 
   if not equal(car cddr n,0) then cr2rderr() else cons('!:rn!:,cadr n);


symbolic smacro procedure !*ff2a(u,v); 
   (lambda x; if wtl!* then prepsq x else mk!*sq x) cancel cons(u,v);


symbolic smacro procedure !*gi2crn u; mkcrn(cons(cadr u,1),cons(cddr u,1));


symbolic smacro procedure !*i2mod u; !*modular2f general!-modular!-number u;


symbolic smacro procedure !*q2a1(u,v); if null v then mk!*sq u else prepsqxx u;


symbolic smacro procedure !*q2f u; 
   if equal(cdr u,1) then car u else typerr(prepsq u,'polynomial);


symbolic smacro procedure !*q2k u; 
   if kernp u then caaar car u else typerr(prepsq u,'kernel);


symbolic smacro procedure !*rd2crn u; 
   (lambda x; mkcrn(realrat x,cons(0,1))) round!* u;


symbolic smacro procedure !*rn2crn u; mkcrn(cdr u,cons(0,1));


symbolic smacro procedure !*rn2rd u; mkround chkrn!* r2bf cdr u;


symbolic smacro procedure add2inputbuf(u,mode); 
   begin 
      if or(null terminalp(),!*nosave!*) then return nil; 
      setq(inputbuflis!*,cons({statcounter,mode,u},inputbuflis!*))
   end;


symbolic smacro procedure aevalox u; mprino aevalox1 car u;


symbolic smacro procedure arrayeval(u,v); 
   if not atom u then rerror('rlisp,24,"Array arithmetic not defined") else u;


symbolic smacro procedure bfinverse u; 
   if atom u then quotient(1.0,u) else invbf u;


symbolic smacro procedure bfminus u; if atom u then minus u else minus!: u;


symbolic smacro procedure blocktyperr u; 
   rerror('rlisp,8,{u,"invalid except at head of block"});


symbolic smacro procedure bool!-eval u; lispeval u;


symbolic smacro procedure boolvalpri u; maprin cadr u;


symbolic smacro procedure c!:narg(x,env); 
   c!:cval(expand(cdr x,get(car x,'c!:binary_version)),env);


symbolic smacro procedure carx(u,v); 
   if null cdr u then car u
    else rerror('alg,5,{"Wrong number of arguments to",v});


symbolic smacro procedure chars2 u; chars21(u,0);


symbolic smacro procedure command1; 
   begin scan(); setcloc!*(); setq(key!*,cursym!*); return xread1 nil end;


symbolic smacro procedure convprec u; convchk round!* u;


symbolic smacro procedure cosh!* x; 
   (lambda y; csl_timbf(bfhalf!*,plubf(y,invbf y))) exp!* x;


symbolic smacro procedure cracsch!* u; crasinh!* cr!:quotient(i2cr!* 1,u);


symbolic smacro procedure crasec!* u; cracos!* cr!:quotient(i2cr!* 1,u);


symbolic smacro procedure crasech!* u; cracosh!* cr!:quotient(i2cr!* 1,u);


symbolic smacro procedure crasin!* u; cr!:minus timesi!* crasinh!* timesi!* u;


symbolic smacro procedure crcoth!* u; 
   (lambda(x,y); cr!:quotient(cr!:plus(x,y),cr!:differ(x,y)))
   (crexp!* cr!:times(i2cr!* 2,u),i2cr!* 1);


symbolic smacro procedure crcsc!* u; cr!:quotient(i2cr!* 1,crsin!* u);


symbolic smacro procedure crcsch!* u; 
   (lambda y; cr!:quotient(i2cr!* 2,cr!:differ(y,cr!:quotient(i2cr!* 1,y))))
    crexp!* u;


symbolic smacro procedure crsec!* u; cr!:quotient(i2cr!* 1,crcos!* u);


symbolic smacro procedure crsech!* u; 
   (lambda y; cr!:quotient(i2cr!* 2,cr!:plus(y,cr!:quotient(i2cr!* 1,y))))
    crexp!* u;


symbolic smacro procedure crsinh!* u; 
   (lambda y; cr!:times(crhalf!*(),cr!:differ(y,cr!:quotient(i2cr!* 1,y))))
    crexp!* u;


symbolic smacro procedure crtanh!* u; 
   (lambda(x,y); cr!:quotient(cr!:differ(x,y),cr!:plus(x,y)))
   (crexp!* cr!:times(i2cr!* 2,u),i2cr!* 1);


symbolic smacro procedure deg2dms!* u; 
   (lambda x; mklist3!* (if atom x then deg2dms x else deg2dms!: x))
    round2a!* u;


symbolic smacro procedure deg2rad!: x; 
   csl_normbf divide!:(csl_timbf(x,pi!*()),!:180!*,!:bprec!:);


symbolic smacro procedure dmoderr(u,v); 
   rerror('poly,10,
          {"Conversion between",
           get(u,'dname),"and",
           get(v,'dname),"not defined"});


symbolic smacro procedure errach u; 
   begin 
      terpri!* t; 
      lprie "CATASTROPHIC ERROR *****"; 
      printty u; 
      lpriw(" ",nil); 
      rerror('alg,4,
             
         "Please report output and input listing on the sourceforge bug tracker"
)
   end;


symbolic smacro procedure evalgeq(u,v); not evallessp(u,v);


symbolic smacro procedure expread; xread t;


symbolic smacro procedure fancy!-boolvalpri u; fancy!-maprin0 cadr u;


symbolic smacro procedure fancy!-mode u; 
   begin scalar m; 
      setq(m,lispeval u); 
      if eqcar(m,'!*sq) then setq(m,reval m); 
      return m
   end;


symbolic smacro procedure formlog2 sf; 
   cons(cons(mksp({'log,prepf sf},1),1),nil);


symbolic smacro procedure gf2cr!: x; 
   cons('!:cr!:,cons(striptag car x,striptag cdr x));


symbolic smacro procedure gfdiffer(u,v); 
   if atom car u then gffdiff(u,v) else gbfdiff(u,v);


symbolic smacro procedure gfdot(u,v); 
   if atom car u then gffdot(u,v) else gbfdot(u,v);


symbolic smacro procedure gidifference!:(u,v); 
   mkgi(difference(cadr u,cadr v),difference(cddr u,cddr v));


symbolic smacro procedure giplus!:(u,v); 
   mkgi(plus2(cadr u,cadr v),plus2(cddr u,cddr v));


symbolic smacro procedure i2crn!* u; mkcrn(cons(u,1),cons(0,1));


symbolic smacro procedure i2rd!* u; mkround chkint!* u;


symbolic smacro procedure idsort u; sort(u,function idcompare);


symbolic smacro procedure ieval u; !*s2i reval u;


symbolic smacro procedure initreduce; initrlisp();


symbolic smacro procedure isqrt x; 
   if leq(x,0) then terrlst(x,'isqrt) else irootn(fix x,2);


symbolic smacro procedure korder u; 
   <<setq(kord!*,if equal(u,'(nil)) then nil else kernel!-list u); rmsubs()>>;


symbolic smacro procedure lambdox u; 
   begin 
      omark '(m u); 
      setq(curmark,plus2(curmark,1)); 
      procox1('lambda,car u,cadr u)
   end;


symbolic smacro procedure let u; let0 u;


symbolic smacro procedure lispapply(u,v); 
   if null atom u then rerror('rlisp,2,{"Apply called with non-id arg",u})
    else apply(u,v);


symbolic smacro procedure lxsort l; 
   sort(l,function (lambda(a,b); lessp(termorder1(car a,car b),0)));


symbolic smacro procedure mkcr(u,v); cons('!:cr!:,cons(striptag u,striptag v));


symbolic smacro procedure mkfil u; 
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase u;


symbolic smacro procedure mkrootlsq(u,n); 
   if null u then !*d2q 1
    else if null !*reduced then mkrootsq(reval retimes u,n)
    else mkrootlsq1(u,n);


symbolic smacro procedure modcnv u; 
   rerror('poly,13,
          {"Conversion between modular integers and",
           get(car u,'dname),"not defined"});


symbolic smacro procedure noncomdel(u,v); 
   if null noncomp!* u then delete(u,v) else noncomdel1(u,v);


symbolic smacro procedure oblist; 
   sort(s!:oblist1(getv(!*package!*,1),nil),function orderp);


symbolic smacro procedure precision n; 
   <<if or(not numberp n,lessp(n,0))
       then rerror('arith,6,"positive number required"); 
     precision1(n,t)>>;


symbolic smacro procedure prepcadr u; prepsq cadr u;


symbolic smacro procedure quotfxerr(u,v); rederr "exact division failed";


symbolic smacro procedure rad2deg!* u; 
   (lambda x; mkround (if atom x then rad2deg x else rad2deg!: x)) convprec u;


symbolic smacro procedure rd!:prep u; 
   if !*noconvert then rdprep1 u
    else if rd!:onep u then 1
    else if rd!:onep rd!:minus u then minus 1
    else rdprep1 u;


symbolic smacro procedure rdarg!* u; 
   if rd!:minusp u then rdpi!*() else rdzero!*();


symbolic smacro procedure rdcot!* u; 
   (lambda x; mkround (if atom x then cot x else tan!* difbf(pi!/2!*(),x)))
    convprec u;


symbolic smacro procedure rdcsc!* u; 
   (lambda x; mkround (if atom x then csc x else invbf sin!* x)) convprec u;


symbolic smacro procedure rdcsch!* u; 
   (lambda x; mkround (if atom x then csch x else invbf sinh!* x)) convprec u;


symbolic smacro procedure rdsin!* u; 
   (lambda x; mkround (if atom x then sin x else sin!* x)) convprec u;


symbolic smacro procedure rdsinh!* u; 
   (lambda x; mkround (if atom x then sinh x else sinh!* x)) convprec u;


symbolic smacro procedure rdtan!* u; 
   (lambda x; mkround (if atom x then tan x else tan!* x)) convprec u;


symbolic smacro procedure remf(u,v); 
   if null v then rerror('poly,201,"Zero divisor") else cdr qremf(u,v);


symbolic smacro procedure s!:cancel_local_decs w; unfluid w;


symbolic smacro procedure sfchk u; if sfp u then prepf u else u;


symbolic smacro procedure simpdiff u; 
   <<ckpreci!# u; addsq(simpcar u,simpminus cdr u)>>;


symbolic smacro procedure !*a2f u; !*q2f simp!* u;


symbolic smacro procedure !*q2a u; !*q2a1(u,!*nosq);


symbolic smacro procedure !*rd2cr u; 
   (lambda x; mkcr(x,if atom x then 0.0 else bfz!*)) convprec u;


symbolic smacro procedure cr2i!*; mkcr(rdzero!*(),rdtwo!*());


symbolic smacro procedure cr!:minus u; gf2cr!: gfminus crprcd u;


symbolic smacro procedure cr!:prep u; 
   crprep1 cons(rd!:prep cons('!:rd!:,cadr u),rd!:prep cons('!:rd!:,cddr u));


symbolic smacro procedure cr!:simp u; cons(gf2cr!: crprcd u,1);


symbolic smacro procedure cracsc!* u; crasin!* cr!:quotient(i2cr!* 1,u);


symbolic smacro procedure cre!*; mkcr(rde!*(),rdzero!*());


symbolic smacro procedure crhalf!*; mkcr(rdhalf!*(),rdzero!*());


symbolic smacro procedure cri!*; mkcr(rdzero!*(),rdone!*());


symbolic smacro procedure cri!/2; mkcr(rdzero!*(),rdhalf!*());


symbolic smacro procedure crlog!* u; mkcr(rdlog!* crnorm!* u,crarg!* u);


symbolic smacro procedure crone!*; mkcr(rdone!*(),rdzero!*());


symbolic smacro procedure crpi!*; mkcr(rdpi!*(),rdzero!*());


symbolic smacro procedure crr2d!* u; 
   mkcr(rad2deg!* cons('!:rd!:,cadr u),rad2deg!* cons('!:rd!:,cddr u));


symbolic smacro procedure crsqrt!* u; gf2cr!: gfsqrt crprcd u;


symbolic smacro procedure deg2rad!* u; 
   (lambda x; mkround (if atom x then deg2rad x else deg2rad!: x)) convprec u;


symbolic smacro procedure formlog sf; 
   if null cdr sf then formlogterm sf else cons(formlog2 sf,1);


symbolic smacro procedure cracos!* u; 
   cr!:plus(cr!:times(crhalf!*(),crpi!*()),timesi!* crasinh!* timesi!* u);


symbolic smacro procedure cracosh!* u; 
   crlog!* cr!:plus(u,crsqrt!* cr!:differ(cr!:times(u,u),i2cr!* 1));


symbolic smacro procedure cracot!* u; 
   cr!:times(cri!/2(),
             crlog!* cr!:quotient(cr!:differ(u,cri!*()),cr!:plus(cri!*(),u)));


symbolic smacro procedure cracoth!* u; 
   cr!:times(crhalf!*(),
             crlog!* cr!:quotient(cr!:plus(i2cr!* 1,u),cr!:differ(u,i2cr!* 1)));


symbolic smacro procedure cratan!* u; 
   cr!:times(cri!/2(),
             crlog!* cr!:quotient(cr!:plus(cri!*(),u),cr!:differ(cri!*(),u)));


symbolic smacro procedure cratanh!* u; 
   cr!:times(crhalf!*(),
             crlog!* cr!:quotient(cr!:plus(i2cr!* 1,u),cr!:differ(i2cr!* 1,u)));


symbolic smacro procedure crcosh!* u; 
   (lambda y; cr!:times(crhalf!*(),cr!:plus(y,cr!:quotient(i2cr!* 1,y))))
    crexp!* u;


symbolic smacro procedure crd2r!* u; 
   mkcr(deg2rad!* cons('!:rd!:,cadr u),deg2rad!* cons('!:rd!:,cddr u));


symbolic smacro procedure crexpt!*(u,v); 
   if cr!:zerop cr!:differ(v,crhalf!*()) then crsqrt!* u
    else crexp!* cr!:times(v,crlog!* u);


end;

