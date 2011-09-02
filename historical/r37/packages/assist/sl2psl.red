module sl2psl; % Definitions of functions in PSL but not SL.

% Some of these are already in the standard REDUCE now.

deflist('((fixp 1) (numberp 1) (floatp 1) (evenp 1) (oddp 1)
          (stringp 1) (idp 1) (ordp 2) (nordp 2) (equal 2)
                              (geq 2) (leq 2)),'number!-of!-args);

%symbolic procedure lastcar l;
% if atom l then l else
% if atom cdr l then car l else car lastpair cdr l;

symbolic procedure lconc(l1,l2);
% Both arguments are lists l1 is a list of the type
% ((a b c ... f) f)
% Useful for concatenating lists from right to left without copying.
% l1 may be nil to start with.
% REQUIRED FOR FUTURE RELEASE
 if null l1 then rplacd(list l2,lastpair l2) else
 if null car l1 then rplacd(rplaca(l1,l2),l2) else
 <<rplacd(cdr l1 ,l2); rplacd(l1, lastpair l2)>>;

symbolic procedure tconc(l,elm);
 <<elm:=cons(elm,nil);
   if null l then nconc(list elm,elm) else
   if null car l then  rplacd(rplaca(l,elm),elm) else
    <<rplacd(cdr l,elm);rplacd(l,elm)>>
 >>;

symbolic procedure adjoin(elm,st);
 % elm is any object, st is a set.
 if member(elm,st) then st else cons(elm,st);

symbolic procedure list2set u;
% Eliminates redundant elements .
% Replaces !:mkset u of the old ASSIST package.
 if null u then nil else if member(car u,cdr u) then list2set cdr u
 else car u . list2set cdr u;


symbolic procedure delqip1(elm,l);
 if not atom cdr l then
   if elm eq cadr l then rplacd(l,cddr l) else
    delqip1(elm,cdr l);

symbolic procedure delqip(elm,l);
 % Deletes elm from l without copying l.
 % This is the good definition given by Arthur Norman.
 % Used in the function SYMMETRIZE.
 if atom l then l else
 if elm eq car l then cdr l else
        <<delqip1(elm,l);l>>;

endmodule;

end;
