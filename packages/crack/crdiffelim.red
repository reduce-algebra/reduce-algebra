module interface_diffelim$

% Simple interface to call DiffElim. 

% Author: Eberhard Schruefer, December 2009, April 2010

% Requires DiffElim-1.1.

% Exchange of data between REDUCE and DiffElim is done via 
% temporary files. These temporary files will be deleted when
% the call of diffelim succeeded.

% From the symbolic mode of REDUCE the main procedure is call_diffelim.
% The function call_diffelim takes 4 arguments. The first argument
% is a list of standard quotients (the input equations).  The second
% argument is either nil or a list of lists containing kernel names for
% assigning a ranking (this generates the Janet list for DiffElim).
% The third argument is either nil or the "N" list (of standard quotients).
% The fourth argument controls the number of reduction steps DiffElim
% performs. It is either an integer or nil, where nil signals to
% run until the final result is computed.
% The result of call_diffelim is a six element list. The first five elements
% are either a list of standard quotients or nil. The sixth element is
% a number. These correspond to the values of G, OT, N, U, B and nSP. 
% Whereas G, OT, U, B are lists of equations, N is a list of inequalities,
% i.e. of expressions not vanishing identically. See the DiffElim documents 
% for further information.
%
% Access from algebraic mode is via the function diffelim. The arguments
% to the function and the result have an analogous meaning. The fourth
% argument of diffelim, however, is optional. If not present DiffElim runs
% until final.
%
% The amount of information DiffElim prints can be controlled by the
% statement 'diffelimverbosity <integer>;'. If the integer is greater
% than zero, the information is written/appended to a file named
% DiffElimIn.tmp.log . This file is not removed by a call to call_diffelim.
%
% Function dependency has to be given by the statement depend. Explicit
% arguments given in brackets do not work.
%
% The location of the DiffElim binary has to be defined in the environment
% variable DiffElimCall of your shell.

% BSDlicense: *****************************************************************
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

fluid '(!*allfac !*nat depl!* !*msg !*int semic!* !*echo !*diffelimverbosity!*
        eqname_)$

symbolic procedure call_diffelim(u,v,n,l)$
   begin scalar res,tmpf,tmpff,ichan,oldichan,semic,!*msg,!*int,
                xtrnlcall,sl;

     % Check the installation of DiffElim
     % DiffElim is distributed together with Crack and is called by 
     % 'crack-directory'/DiffElim-1.1/DiffElim
     % This has to be done >after< loading crack because the
     % global variable options!*; does store the crack call command
     % only after crack is loaded and that is needed to find the 
     % directory name where crack and thus DiffElim-1.1/DiffElim
     % is stored.
     if null xtrnlcall then <<
      % set the environment variable DiffElimCall
      if null crack_load_command then crack_load_cmd()$
      sl:=compress reverse cons('!",cddddr cdddr reverse explode 
                                              crack_load_command)$
      if sl then xtrnlcall := bldmsg("%w/DiffElim-1.1/DiffElim",sl)$
     >>$

     if null xtrnlcall then rederr("DiffElim can not be found.",t,t);
     %<<
     % write "The environment variable DiffElimCall is not set.";
     % terpri()$
     % rederr "Stop due to error.";
     %>>$
     if null filep xtrnlcall then 
     rederr({"No file ",xtrnlcall,
             " was found. Probably DiffElim is not installed.",
             " This should have been distributed with CRACK."},t,t);
     %<<
     % write "No file ",xtrnlcall,
     %       " was found. Probably DiffElim is not installed.",
     %       " This should have been distributed with CRACK.";
     % terpri()$
     % rederr("Stop due to error.")
     %>>$

     % Give it a try. If it crashes, the system is still in a good state.
     system bldmsg("%w%w%w",xtrnlcall," --help",
                   if getenv "windir" then " > NUL"
                                      else " > /dev/null");
     tmpf:=if getenv "windir" then "DiffElimIn.tmp" else
           bldmsg("%w%w%w","/tmp/DiffElimIn_",level_string(session_),"tmp");
     out tmpf;
     sl := gen_diffelim_input(u,n,v)$
     shut tmpf;     
     if sl then unmkallfunstrs sl;
     xtrnlcall := bldmsg("%w%w%w",xtrnlcall," -f ",tmpf);
     if l then xtrnlcall := bldmsg("%w%w%w",xtrnlcall," -haltiter ",l);
     if !*diffelimverbosity!*
      then xtrnlcall := bldmsg("%w%w%w%w%w%w",xtrnlcall," -displaylvl ",
                                 !*diffelimverbosity!*," >> ",tmpf,".log")
      else xtrnlcall := bldmsg("%w%w",xtrnlcall,
                               if getenv "windir" then " > NUL"
                                else " > /dev/null");
     if getenv "windir" then system(bldmsg("%w%w","dos2unix ",tmpf));

     % call to do computation
     system(xtrnlcall);

     % add to generated file the line "end$"
     tmpff := bldmsg("%w%w",tmpf,".final");
     system(bldmsg("%w%w","echo end$ >> ",tmpff));

     % reading results from DiffElim:
     ichan := open(mkfil!* tmpff,'input);
     oldichan := rds ichan;
     semic := semic!*;
     if sl then unargfuns sl;
     res := read_diffelim_output();
     rds oldichan;
     close ichan;
     semic!* := semic;     
     if sl then clear_unargfuns sl;
%     system(bldmsg("%w%w",if getenv "windir" then "del "
%                           else "rm -f ",tmpf));
%     system(bldmsg("%w%w",if getenv "windir" then "del "
%                           else "rm -f ",tmpff));
     return res
   end$

symbolic procedure diffelimverbosity n$
   begin scalar x;
     x := reval car n;
     if null numberp x then rederr({x," not a number"},t,t)$
     %<<
     % write x," not a number"; terpri()$
     % rederr "Stop due to error."
     %>>$
     !*diffelimverbosity!* := if x = 0 then nil else x; 
   end$

put('diffelimverbosity,'stat,'rlis)$
     
symbolic procedure gen_diffelim_input(u,n,v)$
   begin scalar !*allfac,!*nat,dfprintfn_saved,
                exptprtch_saved,v1,sl,depls;
     dfprintfn_saved := get('df,'prifn);
     put('df,'prifn,'df_diffelim_format);
     exptprtch_saved := get('expt,'prtch);
     put('expt,'prtch,'!^);
     maprin "V := [ ";
     terpri!* t;
     depls := depl!*; 
     f: v1 := explode caar depls;
        if null (eqname_p v1 or 
                 car lastpair v1 = '_)
           then maprin car depls else <<depls := cdr depls; go to f>>;
     depls := cdr depls;
     if null depls then go to h;
     g: v1 := explode caar depls;
        if null (eqname_p v1 or car lastpair v1 = '_)
           then <<maprin ","; terpri!* t; maprin car depls>>;
        if depls := cdr depls then go to g;
     h: maprin " ];";
     sl := mkallfunstrs();
     terpri!* t;
     maprin "U := [ ";
     terpri!* t;
     a: sqprint car u; 
        if u := cdr u then <<maprin ","; terpri!* t; go to a>>
         else maprin " ];";
     terpri!* t;
     if null n then go to j;
     maprin "N := [ ";
     terpri!* t;
     cn: sqprint car n;
         if n := cdr n then <<maprin ","; terpri!* t; go to cn>>
          else maprin " ];";
     j: if null v then go to b;
     terpri!* t;
     maprin "Janet := [[";
     d: v1 := car v;
        c: maprin if atom car v1 then car v1 else caar v1;
        if v1 := cdr v1 
           then <<maprin ","; go to c>>
         else if v := cdr v 
           then <<maprin "],["; go to d>>
         else maprin "]];";
     b: terpri!* t;
     put('df,'prifn,dfprintfn_saved);
     put('expt,'prtch,exptprtch_saved);
     return sl
   end$

symbolic procedure eqname_p u$
   eqname_p0(u,explode eqname_)$

symbolic procedure eqname_p0(u,v)$
   if null v then t
    else if null atom u and car u eq car v then eqname_p0(cdr u, cdr v)
    else nil$

symbolic procedure df_diffelim_format u$
   begin scalar x,y,v;
     v := caddr u;
     x := y := {"Diff",%if atom cadr u then assoc(cadr u,depl!*) %sort the list?
                  %else 
                  cadr u,v := caddr u};
     u := cdddr u;
     if null u then return maprin x;
     y := cddr x;
     a: if numberp car u
          then for n := 2:car u do %x := {"Diff",x,v}
                                   y := cdr rplacd(y,v . nil)
         else %x := {"Diff",x,v := car u};
              y := cdr rplacd(y,(v := car u) . nil);
        if u := cdr u then go to a;
     return maprin x
   end$

symbolic procedure read_diffelim_output()$
   begin scalar x,y,z,g,ot,n,u,b,nsp,!*echo;
     put('diff,'newnam,'diffelimdiff); %avoid name clash.
     a: x := scan(); 
        scan();
        y := if (z := scan()) eq '!*lsqbkt!*
                then xreaddiffelimlist()
              else <<scan(); z>>;
        if x eq 'v then nil
         else if x eq 'g then g := y
         else if x eq 'ot then ot := y
         else if x eq 'n then n := y
         else if x eq 'u then u := y
         else if x eq 'b then b := y
         else if x eq 'nsp then nsp := y
         else rederr("unknown result in DiffElim",t,t);
         %<<write "unknown result in DiffElim";terpri()$
         %       rederr("Stop due to error.")
         %>>;
        if null(nxtsym!* eq 'end) then go to a;
     scan(); 
     scan();
     remprop('diff,'newnam);
     put('diffelimdiff,'simpfn,'simpdiffelimdiff);
     if g then g := for each j in g collect simp j;
     if ot then ot := for each j in ot collect simp j;
     if n then n := for each j in n collect simp j;
     if u then u := for each j in u collect simp j;
     if b then b := for each j in b collect simp j;
     nsp := if nsp then nsp else 0; 
     remprop('diffelimdiff,'simpfn);
     return {g,ot,n,u,b,nsp}
   end$

symbolic procedure simpdiffelimdiff u$
   begin scalar w;
     return if (w := assoc(caar u,depl!*))
               and null setdiff(cdr w,cdar u)
              then simp('df . caar u . cdr u)
             else simp('df . u)
   end$
  
symbolic procedure xreaddiffelimlist$
   % Expects a list of expressions enclosed by [, ].
   % Adaption of xreadlist.
   begin scalar cursym,delim,lst;
        if scan() eq '!*rsqbkt!* 
          then <<scan();
                 return nil>>;
    a:  lst := aconc(lst,xread1 'group);
        cursym := cursym!*;
        if cursym eq '!*semicol!*
          then symerr("Syntax error: semicolon in list",nil)
         else if scan() eq '!*rsqbkt!* and cursym eq '!*comma!*
          then symerr("Syntax error: invalid comma in list",nil);
        if cursym eq '!*rsqbkt!*
          then return lst
         else if null delim then delim := cursym;
        go to a
   end$

symbolic procedure mkallfunstrs$
   begin scalar ix,x,s,depls,fnsl;
     if null depl!* then return nil;
     depls := depl!*;
     b: x := car depls;
        ix := x;
        s := bldmsg("%p%w",car x,"()");
        fnsl := ({car ix} . get(car ix,'oldnam)) . fnsl;
        put(car ix,'oldnam,s);
        depls := cdr depls;
        if depls then go to b;
    return fnsl
   end$

symbolic procedure unmkallfunstrs u$
   for each j in u do
     if cdr j then put(caar j,'oldnam,cdr j)
      else remprop(caar j,'oldnam)$

symbolic procedure unargfuns u$
   for each j in u do setk(car j,aeval caar j)$

symbolic procedure clear_unargfuns u$
   for each j in u do <<%let2(car j,nil,nil,nil);
                        remprop(caar j,'simpfn);
                        remprop(caar j,'klist);
                        remprop(caar j,'kvalue)>>$
  
symbolic procedure diff_elim u$
   begin scalar x,y,z,n,res;
     if null(getrtype(x := aeval car u) eq 'list) then typerr(x,"list");
     if null(getrtype(y := reval cadr u) eq 'list) then typerr(y,"list");
     if null(getrtype(n := reval caddr u) eq 'list) then typerr(n,"list");
     z := if cdddr u then reval cadddr u;
     if z and null numberp z then 
     rederr("Fourth argument must be a number",t,t);
     %<<
     % write "Fourth argument must be a number"; terpri()$
     % rederr("Stop due to error.")
     %>>;
     res := call_diffelim(for each j in cdr x collect simp j,
                          if null cdr y then nil 
                           else for each j in cdr y collect cdr j,
                          if null cdr n then nil
                           else for each j in cdr n collect simp j,
                          z);
     return {'list,'list . for each j in car res collect mk!*sq j,
                   'list . if null cadr res then nil 
                            else for each j in cadr res collect mk!*sq j,
                   'list . if null caddr res then nil
                            else for each j in caddr res collect mk!*sq j,
                   'list . if null cadddr res then nil
                            else for each j in cadddr res collect mk!*sq j,
                   'list . if null car cddddr res then nil
                            else for each j in car cddddr res collect mk!*sq j,
                   cadr cddddr res}
   end$

put('diffelim,'psopfn,'diff_elim)$


     
     
endmodule$

end$

tr call_diffelim
tr diffelimverbosity
tr gen_diffelim_input
tr eqname_p
tr eqname_p0
tr df_diffelim_format
tr read_diffelim_output
tr simpdiffelimdiff
tr xreaddiffelimlist
tr mkallfunstrs
tr unmkallfunstrs
tr unargfuns
tr clear_unargfuns
tr diff_elim
tr crack_load_cmd
