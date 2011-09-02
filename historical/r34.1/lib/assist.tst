% Tests of Assist Package version 1.1 .
% Valid only with REDUCE 3.4
% DATE : 15 September 1991.
% Author: H. Caprasse <u214001@bliulg11.bitnet>.
%                     <u214001@vm1.ulg.ac.be>
%---------------------------------------------------------------------
load assist;
showtime;
% 1. TESTS OF THE SWITCH CONTROL FUNCTIONS :
;
switches;
switchorg;
switches;
;
if !*mcd then "the switch mcd is on";
if !*gcd then "the switch gcd is on";
;
% A new switch :
!*distribute;
%
% 2. THE "LIST" MANIPULATION FACILITIES" :
;
% generation of a new list
;
 t1:=mklist(4);

 for i:=1:4 do t1:= (t1.i:=mkid(a,i));
;
%   notice that part(t1,i) has become t1.i. as also shown  here :
;
t1.1;
t1:=(t1.1).t1;

% MKLIST does NEVER destroy anything
;
mklist(t1,3);
mklist(t1,10);

% 3. THE DEFINITION OF A BAG
;
% The atom "BAG" is an available (and reserved) name for a BAG envelope
% it is an OPERATOR. In what follows we mostly use it but we insist that
% ANY identifier (there are a few exceptions) may be used.
;
aa:=bag(x,1,"A");
% It is easy to construct NEW bag-like objects
;
putbag bg1,bg2;

% now one can verify that
;
aa:=bg1(x,y**2);
% is a bag by BAGP
;
if bagp aa then "this is a bag";
;
% One can erase the bag property of bg2 by the command
;
clearbag bg2;
;
% baglistp works in the same way for either a LIST OR a BAG
;
if baglistp aa then "this is a bag or list";
if baglistp list(x) then "this is a bag or list";
;
% Use of the DISPLAYFLAG command that we shall illustrate below is
% another way.
% "LIST" MAY NOT be a bag.
on errcont;
% The command below gives an error message:
;
putbag list;
% LISTS may be transformed to BAGS and vice versa
off errcont;
;
kernlist(aa);
listbag(list x,bg1);
%
%
% 4. BASIC MANIPULATION FUNCTIONS WORKING FOR BOTH STRUCTURES :
;
% define:
;
ab:=bag(x1,x2,x3);
al:=list(y1,y2,y3);
% We illustrate how the elementary functions do work DIFFERENTLY
;
first ab;  third ab;  first al;
last ab; last al;
% The subsequent one do act in the SAME way;
rest ab; rest al;
belast ab; belast al;
;
% depth determines if the depth of the list is uniform.
% when it is, it gives its deepness as an integer.
;
depth al; depth bg1(ab);
% It is very convenient to define the PICKUP function PART(x,n) by . :
;
ab.1; al.3;
on errcont;
ab.4;
off errcont;
% For bags, it is possible to avoid an error message when one
% has an index out of range using "first", "second" and "third".
% For instance:
;
second second ab;
% This is coherent because the envelope of a bag always remains.
;
size ab; length al;
remove(ab,3);
delete(y2,al);
reverse al;
member(x3,ab); % notice the output.
;
al:=list(x**2,x**2,y1,y2,y3);
;
elmult(x**2,al);
position(y3,al);
;
repfirst(xx,al);
represt(xx,ab);
insert(x,al,3);
insert( b,ab,2);
insert(ab,ab,1);
substitute (new,y1,al);
;
% Function that acts on TWO lists or bags :
;
append(ab,al);
append(al,ab);
;
% Association list or bag may be constructed and thoroughly used
;
l:=list(a1,a2,a3,a4);
b:=bg1(x1,x2,x3);
% PAIR is the CONSTRUCTOR of the ASSOCIATION LIST or BAG.
al:=pair(list(1,2,3,4),l);
ab:=pair(bg1(1,2,3),b);
;
% A BOOLEAN function abaglistp to test if it is an association
;
if abaglistp bag(bag(1,2)) then "it is an associated bag";
;
% Values associated to the keys can be extracted
% first occurence ONLY.
;
asfirst(1,al);
asfirst(3,ab);
;
assecond(a1,al);
assecond(x3,ab);
;
aslast(z,list(list(x1,x2,x3),list(y1,y2,z)));
asrest(list(x2,x3),list(list(x1,x2,x3),list(y1,y2,z)));
;


% All occurences.
asflist(x,bg1(bg1(x,a1,a2),bg1(x,b1,b2)));
asslist(a1,list(list(x,a1,a2),list(x,a1,b2),list(x,y,z)));
restaslist(bag(a1,x),bg1(bag(x,a1,a2),bag(a1,x,b2),bag(x,y,z)));
restaslist(list(a1,x),bag(bag(x,a1,a2),bag(a1,x,b2),bag(x,y,z)));

%********
% Mapping functions can be used with bags through
;
on errcont;
;
for each j in list(list(a),list(c)) join j;
for each j in list(bg1(a),bg1(b)) collect first j;
off errcont;
;
% The FOR EACH .. IN .. statement requires a LIST-LIKE object.;
;
% There are functions available for manipulating bags or lists
% as sets. (they exist in the symbolic mode).
;
ts:=mkset list(a1,a1,a,2,2);
;
% Again a boolean function to test the SET property
;
if setp ts then "this is a SET";
;
union(ts,ts);
diffset(ts,list(a1,a));
diffset(list(a1,a),ts);
symdiff(ts,ts);
intersect(listbag(ts,set1),listbag(ts,set2));


% 5. MISCELLANEOUS GENERAL PURPOSE FUNCTIONS :
;
clear a1,a2,a3,a,x,y,z,x1,x2,op;
%
% DETECTION OF A GIVEN VARIABLE IN A GIVEN SET
;
detidnum aa;
detidnum a10;
detidnum a1b2z34;
% A list of a finite number of randomly chosen integers can be
% generated:
%
randomlist(3,10);
%
combnum(8,3);
permutations(bag(a1,a2,a3));
combinations({a1,a2,a3},2);
;
% The "depend" command can be  traced and made EXPLICIT :
;
depatom a;
depend a,x,y;
depatom a;
% The second use of DEPEND
;
depend op,x,y,z;
implicit op;
explicit op;
depend y,zz;
explicit op;
aa:=implicit op;
% The ENTIRE dependence of OP becomes "IMPLICIT"
;
df(aa,y);
% These two last functions work properly ONLY when the command "DEPEND"
%involves ATOMIC  quantities.
;
% Detection of variables a given function depends on is possible
;
funcvar(x+y);
funcvar(sin log(x+y));
;
% Variables on which an expression depends :
%
funcvar(sin pi);
funcvar(x+e+i);
%
% CONSTANT and RESERVED identifiers are recognize and not taken
% as variables.
%
% Now we illustrate functions that give, display or erase
%            a "FLAG" or a "PROPERTY" :
;
% It is possible to give "flags" in the algebraic mode;
%
putflag(list(a1,a2),fl1,t);
putflag(list(a1,a2),fl2,t);
displayflag a1;
% to clear ALL flags created for a1 :
;
clearflag a1,a2;
displayflag a2;
putprop(x1,propname,value,t);
displayprop(x1,prop);
displayprop(x1,propname);
% To clear ONE property
;
putprop(x1,propname,value,0);
displayprop(x1,propname);
%
%
% 6. FUNCTIONS TO CONTROL THE ENVIRONMENT :
;
% Algebraic ATOMS detection
;
alatomp z;
z:=s1;
alatomp z;
% Algebraic KERNEL detection
;
alkernp z;
alkernp log sin r;
% PRECEDENCE detection
;
precp(difference,plus);
precp(plus,difference);
precp(times,.);
precp(.,times);
% STRING detection
;
if stringp x then "this is a string";
if stringp "this is a string" then "this is a string";
;
;
% A function which detects the dependence of u with respect
%to the ATOM or KERNEL v at ANY LEVEL
;
depvarp(log(sin(x+cos(1/acos rr))),rr);
;
operator op;
symmetric op;
op(x,y)-op(y,x);
remsym op;
op(x,y)-op(y,x);
;
clear y,x,u,v;
korder y,x,u,v;
korderlist;
;
for all x,y such that nordp(x,y) let op(x,y)=x+y;
op(a,b);
op(b,a);
clear op;
% DISPLAY and CLEARING of user's objects of various types entered
% to the console. Only TOP LEVEL assignments are considered up to now.
% The following statements must be made INTERACTIVELY. We put them
% as COMMENTS for the user to experiment with them. We do this because
% in a fresh environment all outputs are nil.
;
% THIS PART OF THE TEST SHOULD BE REALIZED INTERACTIVELY.
% SEE THE ** ASSIST LOG **  FILE .
%clear a1,a2,aa,ar,br,mm,m1,m2,f,tv;
%a1:=a2:=1;
%show scalars;
%x**2;
%saveas res;
%show scalars;
%aa:=list(a);
%show lists;
%array ar(2),br(3,3);
%show arrays;
%load matr$
%matrix mm; matrix m1(2,2); m2:=mat((1,1));
%show matrices;
%vector v1,v2;
%show vectors;
%load excalc; pform f=1; tvector tv;
%show vectors;
%show forms;
%show all;
%suppress vectors;
%show vectors;
%suppress all
%show all;
clear op;
operator op;
op(x,y,z);
clearop op;
clearfunctions abs,tan;
;
% THIS FUNCTION MUST BE USED WITH CARE !!"!!!
;

% 7. NEW POLYNOMIAL MANIPUKLATION FACILITIES
%
%
clear x,y,z;
% To see the internal representation :
%
off pri;
;
pol:=(x+2*y+3*z**2)**3;
;
% Notice the recursive form.
;
pold:=distribute pol;
;
% Now it is in a distributive form.
;
% Terms and reductums may be extracted individually :
on distribute;
polp:=pol$
leadterm (pold);
pold:=redexpr pold;
leadterm pold;
;
off distribute;
polp:=pol$
leadterm polp;
polp:=redexpr polp;
leadterm polp;
;
% "leadterm" and "redexpr" extract the leading term and reductum of a
% polynomial respectively WITHOUT specifying the variable.
% The default ordering is then assumed.
% They work both for the distributive and recursive representations.
%
% The function "monom" puts in a list all monoms of a multivariate
% polynomial.
monom polp;
% "lowestdeg" extracts the smallest power of a given indeterminate
% in a polynomial:
lowestdeg(pol,z);
;
on pri;
;
divpol(pol,x+2*y+3*z**2);
% This function gives the quotient AND the remainder directly inside a
% list.
;
% 8. MANIPUKLATIONS OF SOME ELEMENTARY TRANSCENDENTAL FUNCTIONS

trig:=((sin x)**2+(cos x)**2)**4;
trigreduce trig;
trig:=sin (5x);
trigexpand trig;
trigreduce ws;
trigexpand sin(x+y+z);
;
% The same functions exist for hyperbolic functions:
;
hypreduce (sinh x **2 -cosh x **2);
;
% For expressions containing log's. Expansion in terms of sums,
% differences, .. is given by "logplus" while concatenation is given
% by the function "concsumlog".
;
clear a,b;
pluslog log(a*log(x**b));
concsumlog((2*log x + a*b*log(x*y)+1)/(3*x**2*log(y)));
% Though these functions do use substitution rules, these are
% active only during the time they actually do their work.


%  9. VECTOR CALCULUS OPERATIONS
;
clear u1,u2,v1,v2,v3,v4,w3,w4;
u1:=list(v1,v2,v3,v4);
u2:=bag(w1,w2,w3,w4);
%
sumvect(u1,u2);
minvect(u2,u1);
scalvect(u1,u2);
crossvect(rest u1,rest u2);
mpvect(rest u1,rest u2, minvect(rest u1,rest u2));
scalvect(crossvect(rest u1,rest u2),minvect(rest u1,rest u2));
;
% 10. NEW OPERATIONS ON MATRICES
;
clear m,mm,b,b1,bb,cc,a,b,c,d;
matrix mm(2,2);
baglmat(bag(bag(a1,a2)),m);
m;
on errcont;
;
baglmat(bag(bag(a1),bag(a2)),m);
off errcont;
%    **** i.e. it cannot redefine the matrix! in order
%         to avoid accidental redefinition of an already given matrix;

clear m; baglmat(bag(bag(a1),bag(a2)),m);
m;
on errcont;
baglmat(bag(bag(a1),bag(a2)),bag);
off errcont;
% Right since a bag-like object cannot become a matrix.
coercemat(m,op);
coercemat(m,list);
;
on nero;
unitmat b1(2);
matrix b(2,2);
b:=mat((r1,r2),(s1,s2));
b1;b;
mkidm(b,1);
% Allows to relate matrices already defined.
;
% Convenient to replace or get a matrix element inside a procedure :
%
seteltmat(b,newelt,2,2);
geteltmat(b,2,1);
%
b:=matsubr(b,bag(1,2),2);
% It gives automatically a new matrix with the second row substituted.
;
submat(b,1,2);
% What is left when row 1 and column 2 are taken off the matrix.
bb:=mat((1+i,-i),(-1+i,-i));
cc:=matsubc(bb,bag(1,2),2);
% Second column substituted.
cc:=tp matsubc(bb,bag(1,2),2);
matextr(bb, bag,1);
% First row extracted and placed in a bag.
matextc(bb,list,2);
% Second column  extracted and placed in a bag.
;
hconcmat(bb,cc);
vconcmat(bb,cc);
% Horizontal an vertical concatenations.
;
tpmat(bb,bb);
% Tensor product.
%
% It is an INFIX operation :
bb tpmat bb;
;
clear hbb;
hermat(bb,hbb);
% id hbb changed to a matrix id and assigned to the hermitian matrix
% of bb.
;
showtime;
end;
