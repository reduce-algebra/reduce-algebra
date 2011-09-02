module unify;   % Main part of unify code.

% Author: Kevin McIsaac.
% Changes by Rainer M. Schoepf 1991.

% The switch semantic, default on, controls use of semantic matching.

fluid '(!*semantic substitution);

switch semantic;

!*semantic := t;

symbolic procedure amatch(r,p,suchl,pmstack);
   if atom r then unify(nil,mval list r,list p,suchl, pmstack)
    else if not(atom p or (car r neq car p)) then
            unify(car r,mval  cdr r, cdr p, suchl, pmstack)
    else if suchp r then amatch(cadr r, p, caddr r . suchl, pmstack)
    else if !*semantic then resume(list('equal,r,p).suchl, pmstack);

symbolic procedure suspend(op,r,p,suchl, pmstack);
   % Process the interrupting operator.
   amatch(car r, car p,suchl,list(op.cdr r,op.cdr p ). pmstack);

symbolic procedure resume(suchl,pmstack);
   % Resume interrupted operator.
   if pmstack then amatch(caar pmstack,cadar pmstack,suchl,cdr pmstack)
    else if chk(suchl) eq t then bsubs substitution;

symbolic procedure unify(op,r,p,suchl,pmstack);
   if null r and null p then resume(suchl,pmstack) % Bottom of arg list.
    else if null(r) then
        <<prin2("UNIFY:pattern over-run for function ");print(op);nil>>
    else if null(p) and not (ident(op ) or mgenp(car r)) then
%       <<prin2("UNIFY:rule over-run for function ");print(op);NIL>>
        nil
    else
      begin scalar mmatch, st, arg, symm, comb, identity,
             mcontract, acontract, expand; integer i, upb;
         if pm!:free(car r) then  suchl := genp(car r).suchl;
         initarg(p);
         while (not(mmatch) and (arg := nextarg(p))) do
            begin
               if not atom(car r)
                 then mmatch := suspend(op,r,arg,suchl, pmstack)
               else if (pm!:free(car r)) then
               begin
                  bind(car r, car arg);
                     if (st := chk suchl) then
                        mmatch := unify(op,mval cdr r,cdr arg,st,
                                        pmstack);
                  unbind(car r);
               end
               else if meq(car r, car arg)
                then mmatch := unify(op,mval cdr r,cdr arg,suchl,
                                     pmstack)
            end;
         return mmatch
       end;

endmodule;

end;
