%---+++++++++++++++++++++++++++++++
%---VERSION 1.0 Date: June 4, 2013 
%---+++++++++++++++++++++++++++++++
%---USAGE: 
%---=====
%---This package can be used to compute the real roots of a polynomial 
%---by first isolating them and then approximating them to any desired degree 
%---of accuracy defined by the Reduce global function precision(), 
%---whose default value 12. 
%---To isolate the real roots we use the Vincent-Akritas-Strzebonski (VAS) method.
%---Details on this method can be found in the papers at 
%---http://inf-server.inf.uth.gr/~akritas/publications.htm
%---(the ones numbered 77 and 78 give a general overview).
%---
%---Developement started in the Spring Semester of 2013 in the Computer Algebra II class 
%---at the Department of Electrical and Computer Engineering of the University of Thessaly, Greece.
%---
%---THANKS: To Thomas Sturm for his advise throughout this project and to 
%---Fujio Kako for writing vas_rfind, which allowed us to use the rootfind procedure in algebraic mode.
%---
%---CONTRIBUTORS: Except for Fujio and Alkis all four were students at the University of Thessaly:
%---Fujio Kako (vas_rfind)
%---Tassos Gemptos, H. Poulos, Tassos Koutlis, Spyros Mouratis 
%---Alkis Akritas (vas_realintervals, vas_my_sqrfree, vas_my_sort_numbers, vas_approx_roots, vas_realroots)
%---++++++++++++++++++++++

%---+++++++++++++++++++++++++++++++
%---HOW TO LOAD AND USE THE PACKAGE
%---===============================
%---This package consists of the file VAS.red;
%---in interpreter mode it can be loaded as:
%---
%---in "path_to_this_file/VAS.red"$
%---
%---However, it is best used (faster) if you compile it 
%---and load its fast-load (fasl) binary file VAS.b
%---To create and load the fasl file use the following commands:
%---
%---faslout "VAS";
%---in "path_to_this_file/VAS.red"$
%---faslend;
%---load VAS;   
%---
%---Depending on your OS, you might need to write the path to the file VAS.b. 
%---In MAC-OSX the fasl file lands in the Applications folder; 
%---in Linux systems it lands in the "home" folder. 
%---Either the Terminal window or TeXmacs can be used for this process.
%---
%---MAIN FUNCTIONS OF THIS PACKAGE:
%---To isolate the real roots of p call the function vas_realintervals(p) as follows:
%
%---off rounded;                                              %---optional;
%---intervals : vas_realintervals( p );
%
%---The answer, intervals, is of the form ::
%--- [ [[x1,x2],m1],  [[x3,x4],m2], .. ], where mN is the multiplicity of the root.
%---
%---To approximate ( find the value of) the roots call the function 
%
%---roots := vas_approx_roots(p,intervals); 
%---on rounded; roots; off rounded;                            %---optional;
%
%---vas_approx_roots calls Reduce's rootfind procedure for each interval [x_i,x_j].
%---The precision needed is set by the global function precision(), whose default value is 12.
%---
%---The above procedures are combined into one
%---
    procedure vas_realroots( p); vas_approx_roots(p,vas_realintervals( p)); 
%---
%---CAVEAT1: The user controls precision thru the function precision().
%---However, precision might change by evalf WITHOUT ANY WARNING!! 
%---Hence, the user should watch out for such changes and take advantage of them!!
%---EXAMPLE: The poly defined by the product of two polys (Example 116 from roots.lst)
%---p1:= (10^12x^2-sqrt 2)^2+x^7$ p2:= (10^12x^2+sqrt 2)^2+x^7$ p := p1*p2
%---has two pairs of close roots (two very large and two very small) and to find them 
%---precision has to be set to 34.
%---However, running vas_realroots TWICE, you get the roots without any intervention;
%---of course the first time thru you notice the unusual increase in precision!
%---
%---CAVEAT2: The coefficients of p should be rational numbers; 
%---if they are real and rounded is off (default value), they are first converted to 
%---rational and then the roots are computed. 
%---Symbol constants such as pi, sqrt, sin etc are rejected. 
%---
%---MULTIPLE ROOTS:
%---Unlike Reduce's realroots, in the output list each multiple root appears only once. 
%---The multiplicity of each root is best determined from the output of 
%---vas_realintervals( p ).
%---CAVEAT: Should a root "appear" twice, it does NOT mean that it is a multiple 
%---root; they are two different roots that are very close together and under 
%---the working precision they cannot be differentiated. To differentiate them 
%---adjust precision by calling precision(XX), for integer XX > 0, the increased precision.
%---
%---The output obtained from 
%---
%---roots := vas_realroots(p,intervals); 
%---on rounded; roots; off rounded;                            %---optional;
%---
%---is the same as the one obtained with Reduce's function 
%---
%---roots := realroots( p );
%---
%---NB.  The roots can also be approximated using Reduce's nearestroot function as:
%---
%---roots:=map(~A=> first nearestroot( p, (first first(A)+second first(A))/2),intervals);
%---
%---OR can be handled one at a time!!
%---
%---BUGS
%---I would appreciate hearing about any bugs you encounter; 
%---please send all relevant information to 
%---akritas-at-uth.gr   and/or ag.akritas-at-gmail.com
%---
%---++++++++++++++++++++++

%---++++++++++++++++++++++
%---Available functions in this package:
%---===================================
%---vas_list2poly, vas_variations, vas_poslbdLMQ, vas_posubLMQ, vas_intrv,
%---VAS_Pos_Roots, vas_my_sort, VAS, vas_my_rsolve, vas_formRationalRootIntervals, 
%---vas_my_first, vas_my_rest, vas_combineSublistsOfSameMultiplicity,
%---vas_addMissingSqrfreeFactors, vas_interval_split, vas_interval_overlap,
%---vas_interval_overlap2, vas_changeStyle, vas_my_sort2, vas_interval_sort, 
%---vas_list_linear_factors_raised_mult, vas_content, vas_my_sort_multiplicity, 
%---vas_realintervals, vas_my_sqrfree, vas_my_sort_numbers, vas_rfind,
%---vas_approx_roots (vas_rfind), and vas_approx_roots2 (nearestroot)
%---
%---PLUS ALL THE FUNCTIONS in the sets.red package
%---++++++++++++++++++++++

%---++++++++++++++++++++++
%---Packages required
%---=================
load_package polydiv;      %---to compute quo, rem of polys, divide(p,q)
load_package randpoly;     %---for random poly generation; to test cases
load_package redlog;       %---to compute the squareFree factors of a poly, sqfdec(p)
load_package roots;        %---to approximate the roots nearestroot(p,s)
load_package roots2;       %---to approximate the roots rootfind(p,l,r)
load_package rsolve;       %---to compute the rational roots of a poly, r_solve(p)
%---load_package sets;     %---union needed in various routines; located at the end of this file
%---++++++++++++++++++++++



procedure vas_list2poly(numlist,var);
%---++++++++++++++++++++++
%---converts the number list numList to a univariate poly in variable var 
%---with coefficients the elements of numList
%---++++++++++++++++++++++
begin scalar len, temp;
temp:=0;
len:=length(numlist);
for j:=1 step 1 until len do temp:=temp*var + part(numlist,j);
return temp;
end;

procedure vas_variations(f,var);
%---++++++++++++++++++++++
%---computes the number of sign variations in the sequence of coefficients
%---of a univariate polynomial
%---++++++++++++++++++++++
begin scalar  c, le, v, s, s1;
 v:=0; c:= select (~x neq 0, coeff(f,var));
 le:=length(c);
 if le > 1 then
  begin
   s:=sign(part(c,1)); 
   for j:=1:le-1 do
    begin
     s1:=sign(part(c,j+1));
     if s*s1 < 0 then v:=v+1 ;
     s:=s1;
    end;
  end;
return v;
end;

procedure vas_poslbdlmq(p,x);
%---++++++++++++++++++++++
%---Implements the Local_Max_Quadratic method (LMQ) to compute a  
%---lower bound on the values of the POSITIVE roots of p(x).      
%---Reference:"Linear and Quadratic Complexity Bounds on the      
%---Values of the Positive Roots of Polynomials"                  
%---by Alkiviadis G. Akritas. Journal of Universal Computer       
%---Science, Vol. 15, No. 3, 523-537, 2009.     
%---
%---PRECISION will be adjusted, if needed, by evalf.                   
%---++++++++++++++++++++++
begin scalar cl, timesused, len, m, n, q, tempmin, tempmininf, tempmax;
 cl := coeff(p,x);
 q := -1;
 tempmax := 0;
 if first cl < 0 then cl:=map(~x => -x,cl);
 len := length cl;
 if len <= 1 then return 0;
 timesused := for j := 1 : len collect (1);

% reduce does not support ops with infinity; 
% hence set tempmin := 10^(number of digits of the max coeff + 1);

tempmininf := 10^( 2*ceiling(evalf(log(max(abs(cl)))/log(10.0))) );

 for m := 2 step 1 until len do
 begin
  if part(cl,m) < 0 then 
   begin
    tempmin := tempmininf;              % reduce does not support ops with infinity
    for n := 1 step 1 until m-1 do
     begin
      if part(cl,n) > 0 then
       begin
        q := evalf((2^(part(timesused,n))*(-part(cl,m)/part(cl,n)))^(1/(m-n)));  
        timesused := part(timesused,n) := part(timesused,n) + 1;
        if q < tempmin then tempmin := q
       end;
     end;
     if tempmax < tempmin then tempmax := tempmin
   end;
 end;
 if tempmax = 0 then return infinity;
 if tempmax = tempmininf then return 0;          %  for wilkinson polys as in maxima??
 if 2^(-ceiling(evalf(logb(tempmax,2)))) < 1.e-16 then return 0;
 return 2^(-ceiling(evalf(logb(tempmax,2))))        
end;

procedure vas_posublmq(p,x);
%---++++++++++++++++++++++
%---Implements the Local_Max_Quadratic method (LMQ) to compute a  
%---lower bound on the values of the POSITIVE roots of p(x).      
%---Reference:"Linear and Quadratic Complexity Bounds on the      
%---Values of the Positive Roots of Polynomials"                  
%---by Alkiviadis G. Akritas. Journal of Universal Computer       
%---Science, Vol. 15, No. 3, 523-537, 2009. 
%---
%---PRECISION will be adjusted, if needed, by evalf.                      
%---++++++++++++++++++++++
begin scalar cl, timesused, len, m, n, q, tempmin, tempmininf, tempmax;
cl := coeff(p,x);
cl := reverse(cl);
q := -1;
tempmax := 0;
if first cl < 0 then cl:=map(~x => -x,cl);
cl := reverse(cl);
len := length(cl);
if len <= 1 then return 0;
timesused := for j := 1 : len collect (1);

% reduce does not support ops with infinity; 
% hence set tempmin := 10^(twice the number of digits of the max coeff + 1);
tempmininf := 10^( 2*ceiling(evalf(log(max(abs(cl)))/log(10.0))) + 1 );   

for m := len step -1 until 2 do
begin
 if part(cl,m-1) < 0 then
  begin
   tempmin := tempmininf;           % reduce does not support ops with infinity
   for n := len+1 step -1 until m+1 do
    begin
     if part(cl,n-1) > 0 then
      begin
       q := evalf((2^(part(timesused,n-1))*(-part(cl,m-1)/part(cl,n-1)))^(1/(n-m)));
       timesused := part(timesused,n-1) := part(timesused,n-1) + 1;
       if q < tempmin then tempmin := q
      end;
    end;
    if tempmax < tempmin then tempmax := tempmin
  end;
end;
return ceiling(evalf((65/64)*tempmax))
end;

procedure vas_intrv(a,b);
%---++++++++++++++++++++++
%--Orders a, b
%---++++++++++++++++++++++
begin
if (a > b) then return {b,a}
else return {a,b}
end;

procedure vas_pos_roots(p, x, ap, bp, cp, dp);
%---++++++++++++++++++++++
%---This algorithm implements the Vincent-Akritas-Strzebnski method for the 
%---isolation of the real roots of polynomials.
%---The steps below correspond to the steps described in the reference:
%---
%---Reference:	"A Comparative Study of Two Real Root Isolation Methods" 
%---by Alkiviadis G. Akritas and Adam W. Strzebonski. 
%---Nonlinear Analysis: Modelling and Control, Vol. 10, No. 4, 297-304, 2005.
%---++++++++++++++++++++++
begin scalar a, b, c, d, a1, b1, c1, d1, a2, b2, c2, d2, att, bt, ct ,
dt, f, g, f1, f2, ft, intervalstobeprocessed, lb, n, rootisolationintervals, r,
ub, v, v1, v2, vt, xx, yy;

 intervalstobeprocessed := list();
 rootisolationintervals := list();
 f := p;
 v := vas_variations(f, x);
 ub := vas_posublmq(f, x);

% comment step 1;
 if (v = 0) then return rootisolationintervals;
 if (v = 1) then return rootisolationintervals := vas_intrv(0, ap*ub) . rootisolationintervals;

%-------------------------------------------------------
%---Do the Chinese trick No. 2 in case v==2 ; 29-01-2013 
%-------------------------------------------------------

 if ( (v = 2) and (sign(sub(x=0, f))*sign(sub(x=1, f)) < 0) ) then
 begin
   rootisolationintervals := vas_intrv(ap*1, ap*ub) . rootisolationintervals;
   rootisolationintervals := vas_intrv(0, ap*1) . rootisolationintervals;
%---CANNOT use "return rootIsolationIntervals" 
%---within begin-end block  So, used "go to label".
  go to label
 end;
 intervalstobeprocessed := {ap, bp, cp, dp, f, v} . intervalstobeprocessed;

% comment step 2;
%---in maxima you cannot go to a label outside the while block so we had to use if; in reduce we can use while.
%---label: if (intervalsToBeProcessed neq {}) then

label: while intervalstobeprocessed neq {} do
 begin
   g := first intervalstobeprocessed;
   a := part(g,1);
   b := part(g,2);
   c := part(g,3);
   d := part(g,4);
   f := part(g,5);
   v := part(g,6);
   intervalstobeprocessed := rest intervalstobeprocessed;
   if (lcof(f,x) < 0) then f := (-1)*f;  %---positive lcof
   %-------------------------------------------------------
   %---Do the Chinese trick No. 2 in case v==2 ; 29-01-2013 
   %-------------------------------------------------------
   if ( (v = 2) and (sign(sub(x=0, f))*sign(sub(x=1, f)) < 0) ) then
   begin
     rootisolationintervals := append(rootisolationintervals,{vas_intrv((a+b)/(c+d), b/d)});
     ub := vas_posublmq(f,x);
     rootisolationintervals := append(rootisolationintervals,{vas_intrv((a+b)/(c+d), (a*ub+b)/(c*ub+d))});
     go to label
   end;

% comment step 3;
  lb := vas_poslbdlmq(f,x);

% comment step 4;
  if (lb > 16) then
  begin
    f := sub(x=lb*x,f);
    a := lb*a;
    c := lb*c;
    lb := 1
  end;

% comment step 5;
  if (lb >= 1) then
  begin
    f := sub(x=lb+x,f);
    b := lb*a + b;
    d := lb*c + d;
    if (sub(x=0,f) = 0) then
    begin
      rootisolationintervals := append(rootisolationintervals,{{b/d, b/d}});
      f := f/x
    end;
    v := vas_variations(f,x);
    if (v = 0) then go to label;
    if (v = 1) then
    begin
      if (c neq 0) 
         then rootisolationintervals := append(rootisolationintervals, {vas_intrv(a/c,b/d)})
         else rootisolationintervals := append(rootisolationintervals, {vas_intrv(b,b+a*vas_posublmq(p,x))}); 
      go to label
    end
  end;

% comment step 6;
  f1 := sub(x = x + 1, f);
  a1 := a;
  b1 := a + b;
  c1 := c;
  d1 := c + d;
  r := 0;
  if (sub(x = 0, f1) = 0) then
  begin
    rootisolationintervals := append(rootisolationintervals, {{b1/d1, b1/d1}});
    f1 := f1 / x;
    r := 1
  end;
  v1 := vas_variations(f1, x);
  v2 := v - v1 - r;
  a2 := b;
  b2 := a + b;
  c2 := d;
  d2 := c + d;
 
% comment step 7;
  if ( v2 > 1 ) then 
  begin
    f2 := sub(x = x + 1, vas_list2poly(coeff(f,x),x));
    if ( sub(x = 0, f2) = 0 ) then f2 := f2 / x;
    v2 := vas_variations(f2, x)
  end;

% comment step 8;
  if ( v1 < v2 ) then
  begin
    att := a1; bt := b1; ct := c1; dt := d1; ft := f1; vt := v1;
    a1 := a2; b1 := b2; c1 := c2; d1 := d2; f1 := f2; v1 := v2;
    a2 := att; b2 := bt; c2 := ct; d2 := dt; f2 := ft; v2 := vt
  end;

% comment step 9;
  if (v1 = 0) then go to label;
  if (v1 = 1) 
     then 
     begin 
       if ( c1 neq 0 ) 
          then rootisolationintervals := append(rootisolationintervals, {vas_intrv(a1/c1, b1/d1)})
          else rootisolationintervals := append(rootisolationintervals, {vas_intrv(b1, b1 + a1 * vas_posublmq(f1,x))})
     end 
     else intervalstobeprocessed := {a1, b1, c1, d1, f1, v1} . intervalstobeprocessed;

% comment step 10;
  if (v2 = 0) then go to label;
  if (v2 = 1) 
     then 
     begin
       if (c2 neq 0) 
          then rootisolationintervals := append(rootisolationintervals, {vas_intrv(a2/c2, b2/d2)})
          else rootisolationintervals := append(rootisolationintervals, {vas_intrv(b2, b2 + a2 * vas_posublmq(f2, x))})
     end
     else intervalstobeprocessed := {a2, b2, c2, d2, f2, v2} . intervalstobeprocessed;
   go to label
 end;                           %---ends the big if loop
return vas_my_sort(rootisolationintervals);
end;

procedure vas_my_sort(intervallist);
%---++++++++++++++++++++++
%---Uses bubble sort to sort the root isolation intervals in VAS_Pos_Roots above
%---The intervals are of the form {{a, b}, {a1,b1}, ..}
%---++++++++++++++++++++++
begin scalar flag, n, label, len, loop, a, b, c, d, rootisolationintervals,
temp1, temp2;
rootisolationintervals:=intervallist;
len:=length(rootisolationintervals);
if len = 0 or len = 1 then return rootisolationintervals;
loop := len - 1;

label: flag:=0;
n:=1;
while n <= loop do
begin 
  a:=part(part(rootisolationintervals,n),2);
  b:=part(part(rootisolationintervals,n+1),2);
  if a = b then
  begin
    c:=part(part(rootisolationintervals,n),1);
    d:=part(part(rootisolationintervals,n+1),1);
    if a < b then check:=0 else check:=1;
  end;
  if a neq b then 
  begin
    if a < b then check:=0 else check:=1;
  end;

% COMMENT if check = 1 then sorting is needed;

  if check = 1 then 
  begin
    temp1:=part(rootisolationintervals,n);
    temp2:=part(rootisolationintervals,n+1);
    rootisolationintervals:=part(rootisolationintervals,n):=temp2;
    rootisolationintervals:=part(rootisolationintervals,n+1):=temp1;
    flag:=1;
  end;
 
  n:=n+1;
end;

%---the last elements are sorted
loop := loop -1;              
if flag = 1 then go to label;
return rootisolationintervals
end;

procedure vas(p,x);
%---++++++++++++++++++++++
%---Calls VAS_Pos_Roots to compute the positive and negative roots 
%---and forms the list of isolating intervals of a poly WITHOUT multiple roots.
%---It also checks if 0 is a root.                       
%---++++++++++++++++++++++
begin scalar a, a1, apot, len, len0, len1, len2, f, ff, k, pp,temp,temp2;

pp:= (-1)^deg(p,x)*sub(x=-x,p);

%---isolate the positive roots
a:= vas_pos_roots(p,x,1,0,0,1);
len:=length(a);

%---isolate the negative roots
if p = pp 
then     %---copy the list a and change signs; reduce cannot negate a list
begin
  a1:={};
  for i:=1 : len do a1:=append(a1,{vas_intrv(-part(part(a,i),1),-part(part(a,i),2))});
  a1:=reverse(a1)
end
else a1:= vas_pos_roots(pp,x,-1,0,0,1);

apot:={};
k:=1;
len0 := length(a1);
len1 := len0+length(a);
len2 := len1+1;

if sub(x=0,p) = 0 then
begin
  apot:= for i:=1 : len2 collect({0});
  while k <= len0 do
  begin
    apot:=part(apot,k):=part(a1,k);
    k:=k+1
  end;
  apot:=part(apot,k):={0,0};  %---add the interval {0,0} for the root 0
  k:=k+1;
  while k <= len2 do
  begin
    apot:=part(apot,k):=part(a,(k-length(a1)-1));
    k:=k+1
  end
end
else
begin
  apot := for i:=1 : len1 collect({0});
  while k <= len0 do
  begin
    apot:=part(apot,k):=part(a1,k);
    k:=k+1
  end;
  while k <= len1 do
  begin
    apot:=part(apot,k):=part(a,k-length(a1));
    k:=k+1
  end
end;

return apot

end;

procedure vas_my_rsolve(p);
%---++++++++++++++++++++++
%---Calls r_solve to compute the rational roots in the form {x=r1, x=r2, ...}
%---and forms the list {r1, r2, ...}                      
%---++++++++++++++++++++++
begin;
return for each x in r_solve(p) collect rhs(x);
end;

procedure vas_formrationalrootintervals(p);
%---++++++++++++++++++++++
%---Compute the rational roots for each square free poly and 
%---output a list of the form {{{{a,a},..}, m1}, {{{b,b},..}, m2}, ..}, where mI is the multiplicity
%---++++++++++++++++++++++
begin scalar list_sqrfree_factors_plus_multiplicity,
list_of_rationalroots_plusmultiplicity_perfactor, roots2interval;

%COMMENT Form the list of the square free polys along with their multiplicity;
list_sqrfree_factors_plus_multiplicity:=sqfdec(p);

%COMMENT If p is a rational numbers sqfdec returns {}, the empty set;
if (list_sqrfree_factors_plus_multiplicity = {}) then return({{{},1}}); 

%COMMENT For each square free poly compute its rational roots;
list_of_rationalroots_plusmultiplicity_perfactor :=
for each xx in list_sqrfree_factors_plus_multiplicity collect  
  append({vas_my_rsolve(part(xx,1))},{part(xx,2)});

%COMMENT Form the interval for each rational root along with the multiplicity;
roots2intervals:= for each yy in list_of_rationalroots_plusmultiplicity_perfactor
collect {for each xx in first(yy) collect {xx,xx}, first(rest(yy)) };

%COMMENT sort the intervals;
return(for each xx in roots2intervals collect
append({vas_my_sort(first(xx))},{second(xx)}))

end;

procedure vas_my_first(alist);
%---++++++++++++++++++++++
%---Reduce crashes on first([]) so tests are needed before advancing pointers
%---++++++++++++++++++++++

begin scalar mylist;
  mylist:={};
  if alist neq {} then mylist := first alist;
  return mylist;
end;

procedure vas_my_rest(alist);
%---++++++++++++++++++++++
%---Reduce crashes on rest([]) so tests are needed before advancing pointers
%---++++++++++++++++++++++

begin scalar mylist;
  mylist:={};
  if alist neq {} then mylist := rest alist;
  return mylist;
end;

procedure vas_combinesublistsofsamemultiplicity(intervalslist);
%---++++++++++++++++++++++
%---The input list is ORDERED according to multiplicity!
%---
%---This function merges sublists of roots (in the intervalsLIST) having the same
%---multiplicity. That is, if the input is of the form 
%---
%---{{{{-2,-2}},1},{{{5,5}},2},{{{6,6}},3},{{{4,0},{5/4,3/2},{3/2,2}},3},{{{2,2}},4}}
%--- 
%---where the sublist {{{6,6}},3} is due to a rational root, then the output is
%--- 
%---{{{{-2,2}},1},{{{5,5}},2},{{{4,0},{5/4,3/2},{3/2,2},{6,6}},3},{{{2,2}},4}} 
%---
%---NOTICE THAT NO MORE THAN 2 LISTS CAN HAVE SAME MULTIPLICITY
%---++++++++++++++++++++++

begin  scalar intervalsliste, intervalslistp, rootintervalssamemultiplicity,
temp;
  
  intervalslistp := intervalslist;
  intervalsliste := vas_my_first(intervalslistp);
  intervalslistp := vas_my_rest(intervalslistp);
  rootintervalssamemultiplicity := {};

  while (intervalsliste neq {} and intervalslistp neq {}) do
  begin
         %---  COMMENT multiplicities match;
    if ( vas_my_first(vas_my_rest(intervalsliste)) = vas_my_first(vas_my_rest(vas_my_first(intervalslistp))) ) then
    begin
      temp := union(vas_my_first(intervalsliste) , vas_my_first(vas_my_first(intervalslistp)));
      temp:= vas_my_sort temp;
      rootintervalssamemultiplicity := append(rootintervalssamemultiplicity,
            {{temp, vas_my_first(vas_my_rest(intervalsliste))}});
      intervalslistp := vas_my_rest(intervalslistp); 
      intervalsliste := vas_my_first(intervalslistp);
      intervalslistp := vas_my_rest(intervalslistp);  
    end
          %---  COMMENT multiplicities differ;
    else 
    begin
      rootintervalssamemultiplicity := append(rootintervalssamemultiplicity,
            {intervalsliste});
      intervalsliste := vas_my_first(intervalslistp);
      intervalslistp := vas_my_rest(intervalslistp); 
    end;
  end;
  if (intervalsliste neq {}) then
    rootintervalssamemultiplicity := append(rootintervalssamemultiplicity,
          {intervalsliste});
  return rootintervalssamemultiplicity
end;


procedure vas_addmissingsqrfreefactors(pol,allintervals);
%---++++++++++++++++++++++
%---make sure list pol has the same length as list  allIntervals; 
%---pol is a list of the form {{sqrfree_factor, m}, ...} whereas 
%---allIntervals is a list of the form { {{ {a,b},...}, m}, ... }
%---REASON: a rational root {{a,a}, m} does NOT have the corresponding factor in pol,
%---so we insert in the form {x-a, m}.
%---++++++++++++++++++++++

begin scalar pol2, pole,  polp, allintervalse, allintervalsp;

if ( length(pol) = length(allintervals) ) then return pol;

pol2:=list();
polp:=pol;
allintervalsp:=allintervals;

pole:=vas_my_first(polp);
polp:=vas_my_rest(polp);
allintervalse:=vas_my_first(allintervalsp);
allintervalsp:=vas_my_rest(allintervalsp);

while ( allintervalse neq {} ) do      %---ONLY one test is better!!!
begin
   if ( vas_my_first(vas_my_rest(allintervalse)) = vas_my_first(vas_my_rest(pole)) ) then
   begin
      pol2:=append(pol2,{pole});
      pole:=vas_my_first(polp);
      polp:=vas_my_rest(polp);
      allintervalse:=vas_my_first(allintervalsp);
      allintervalsp:=vas_my_rest(allintervalsp);
   end

%  if vas_my_first(vas_my_rest(allIntervalsE)) neq vas_my_first(vas_my_rest(polE)) then
   else
   begin
      pol2:=append(pol2, {{x - vas_my_first(vas_my_first(vas_my_first(allintervalse))), 
                            vas_my_first(vas_my_rest(allintervalse))}});
      allintervalse:=vas_my_first(allintervalsp);
      allintervalsp:=vas_my_rest(allintervalsp);
   end;
end;

return pol2

end;

procedure vas_interval_split(p1,a1);
%---++++++++++++++++++++++
%---shortens the interval a1 containing a root of p1 so that 
%---there will be no overlap between a1 and other intervals
%---++++++++++++++++++++++

begin scalar a,b;
a:= a1;

if (( sub(x=part(a,1),p1) * sub(x=((part(a,1)+part(a,2))/2),p1)) < 0) then
begin
  temp:= (part(a,1) + part(a,2))/2;
  a:=part(a,2):=temp;
end;

if ( sub(x=((part(a,1)+part(a,2))/2),p1) = 0 ) then
begin
  temp:= (part(a,1) + part(a,2))/2;
  a:=part(a,2):=temp;
  a:=part(a,1):=temp;
end;

if ((sub(x=part(a,2),p1) * sub(x=((part(a,1)+part(a,2))/2),p1)) < 0 ) then
begin
  temp:= (part(a,1) + part(a,2))/2;
  a:=part(a,1):=temp;
end;

return a
end;

procedure vas_interval_overlap(pol,apot);
%---++++++++++++++++++++++
%---Sample input: 
%---pol:   {{x^3-7*x+7,1},{x-2,2},{x+3,3}}
%---apot:  {{{{-4,0},{5/4,3/2},{3/2,2}},1},{{{2,2}},2},{{{-3,-3}},3}}

%---Sample Output:
%---{{{{-7/2,-3},{5/4,3/2},{3/2,2}},1},{{{2,2}},2},{{{-3,-3}},3}}

%---Cases intervals overlap: Let p1 have a root in ]a, b[ 
%---                         and p2 have a root in ]c, d[. 

%---The intervals ]a, b[ and ]c, d[ overlap if::

%---1. a<=c &&  b<=d && b>c
%---OR
%---2. a>=c && b>=d && d>a
%---OR
%---3. a<c && b>d
%---OR
%---4. a>c && b<d
%---++++++++++++++++++++++

begin scalar kk,ll,jj,pp;

for kk := 1 : length(apot) do
begin
   for ll := 1 : length(part(apot,kk,1)) do
   begin
      for jj := kk+1 : length(apot) do
      begin
         for pp := 1 : length(part(apot,jj,1)) do
         begin
            while ( part(apot,kk,1,ll,1) <=  part(apot,jj,1,pp,1) and 
                        part(apot,kk,1,ll,2)  <=  part(apot,jj,1,pp,2) and
                        part(apot,kk,1,ll,2)  >  part(apot,jj,1,pp,1) ) or
                       ( part(apot,kk,1,ll,1) >= part(apot,jj,1,pp,1) and
                        part(apot,kk,1,ll,2)  >= part(apot,jj,1,pp,2) and
                        part(apot,jj,1,pp,2)  >  part(apot,kk,1,ll,1) ) or
                       ( part(apot,kk,1,ll,1) <  part(apot,jj,1,pp,1) and
                        part(apot,kk,1,ll,2)  >  part(apot,jj,1,pp,2) ) or
                       ( part(apot,kk,1,ll,1) >  part(apot,jj,1,pp,1) and
                        part(apot,kk,1,ll,2)  <  part(apot,jj,1,pp,2) ) do
            begin
              apot:=part(apot,kk,1,ll) := vas_interval_split(part(pol,kk,1),part(apot,kk,1,ll));
              apot:=part(apot,jj,1,pp) := vas_interval_split(part(pol,jj,1),part(apot,jj,1,pp));
           end;
        end;
     end;
  end;
end;

return apot

end;

procedure vas_interval_overlap2(pol, apot);
%---++++++++++++++++++++++
%---a modification of the original vas_interval_overlap to handle 
%---overlaps within intervals of roots of same multiplicity

%---Sample input: 
%---pol:   {{x^3-7*x+7,1},{x-2,2},{x+3,3}}
%---apot:  {{{{-2,-2},{-4,0},{5/4,3/2},{3/2,2}},1},{{{2,2}},2},{{{-3,-3}},3}}

%---Sample Output:
%---{{{{-2,-2},{-4,-2},{5/4,3/2},{3/2,2}},1},{{{2,2}},2},{{{-3,-3}},3}}

%---Cases intervals overlap: Let p1 have a root in ]a, b[ 
%---                         and p2 have a root in ]c, d[. 

%---The intervals ]a, b[ and ]c, d[ overlap if::

%---1. a<=c &&  b<=d && b>c
%---OR
%---2. a>=c && b>=d && d>a
%---OR
%---3. a<c && b>d
%---OR
%---4. a>c && b<d 
%---++++++++++++++++++++++

begin scalar kk, ll, jj, pp;
   for kk := 1 : length(apot) do
   begin
      for ll := 1 : length(part(apot,kk,1)) do
      begin
         for pp := ll+1 : length(part(apot,kk,1)) do
         begin
            while ( part(apot,kk,1,ll,1) <= part(apot,kk,1,pp,1) and 
                       part(apot,kk,1,ll,2) <= part(apot,kk,1,pp,2) and
                       part(apot,kk,1,ll,2) > part(apot,kk,1,pp,1) ) or
                       ( part(apot,kk,1,ll,1) >= part(apot,kk,1,pp,1) and
                       part(apot,kk,1,ll,2) >= part(apot,kk,1,pp,2) and
                       part(apot,kk,1,pp,2) > part(apot,kk,1,ll,1) ) or
                      ( part(apot,kk,1,ll,1) < part(apot,kk,1,pp,1) and
                      part(apot,kk,1,ll,2) > part(apot,kk,1,pp,2) ) or
                      ( part(apot,kk,1,ll,1) > part(apot,kk,1,pp,1) and
                      part(apot,kk,1,ll,2) < part(apot,kk,1,pp,2) ) do
            begin
               if part(apot,kk,1,ll,1) neq part(apot,kk,1,ll,2) then
                     apot:=part(apot,kk,1,ll):=vas_interval_split(part(pol,kk,1),part(apot,kk,1,ll));
               if part(apot,kk,1,pp,1) neq part(apot,kk,1,pp,2) then
                     apot:=part(apot,kk,1,pp):=vas_interval_split(part(pol,kk,1),part(apot,kk,1,pp));
            end;
         end;
      end;
   end;

return apot

end;

procedure vas_changestyle(apot);
%---++++++++++++++++++++++
%---change slightly the format of apot, which in the input is of the form
%---{{{{a1,b1},{a2,b2},...{ak,bk}},m1},{{{,},{,},...{,}},m2},...}
%---and make it so that now EACH interval is, associated with its root multiplicity
%---i.e. { {{a1,b1},m1},{{a2,b2},m1}...{{ak,bk},m1}},{{{,},m2},{{,},m2}...{{,},m2}},...}

%---Sample input: {{{{-2,-2},{-7/2,-3},{5/4,3/2},{3/2,2}},1},{{{2,2}},2},{{{-3,-3}},3}}

%---Sample output: { {{-2,-2},1},{{-7/2,-3},1},{{5/4,3/2},1},{{3/2,2},1},{{2,2},2},{{-3,-3},3} }
%---++++++++++++++++++++++

begin
   apot2 := {};
   for i:=1:length(apot) do
   begin
      for j := 1 : length(part(apot,i,1)) do
      begin
         apot2 := append(apot2, {{part(apot,i,1,j),part(apot,i,2)}});
      end;
   end;

return apot2

end;

procedure vas_interval_sort(apot);
%---++++++++++++++++++++++
%---prepares list for output
%---++++++++++++++++++++++

begin scalar apot2, j, sorted_set;
   
if apot = {} then return {};
apot2 := vas_changestyle(apot);

COMMENT union_SET := {};
COMMENT for j:=1:length(apot2) do union_SET := union(union_SET, part(apot2,j));

sorted_set := vas_my_sort2(apot2);

return sorted_set;

end;


procedure vas_my_sort2(apot2);
%---++++++++++++++++++++++
%---sorts intervals of the form: 
%---{ {{-2,-2},1},{{-7/2,-3},1},{{5/4,3/2},1},{{3/2,2},1},{{2,2},2},{{-3,-3},3} }
%---++++++++++++++++++++++

begin scalar temp;
 for i := 1 : length(apot2)-1 do
 begin
   for j := i+1 : length(apot2) do
   begin
     if part(apot2,j,1,1) < part(apot2,i,1,1) then
     begin
       temp := part(apot2,i);
       apot2 := part(apot2,i) := part(apot2,j);
       apot2 := part(apot2,j) := temp;
     end;
   end;
 end;
return apot2;
end;

procedure vas_content(p,x);
%---++++++++++++++++++++++
%---computes the content of p
%---++++++++++++++++++++++

begin scalar p_list,j,temp;
  p_list:=coeff(p,x);
  temp:=part(p_list,1);
  for j:=2 : length(p_list) do
  begin
    temp:=gcd(temp,part(p_list,j));
  end;
return temp;
end;

procedure vas_list_linear_factors_raised_mult(rationalrootsintervals);
%---++++++++++++++++++++++
%---the input is a list of intervals of the form { {{},1}, { {{3,3},{5,5}}, 2 } }
%---computes a list of the corresponding linear factors raised to their multiplicity
%---i.e. {x^2-6x+9, x^2-10x+25}
%---
%---++++++++++++++++++++++

begin scalar y, y2, y3, y4, j, k, listrationalfactors, rr;
  listrationalfactorsraisedmult:=list();
  y2:=rationalrootsintervals;
  for j:=1 : length(rationalrootsintervals) do
  begin
    y:=vas_my_first(y2);
    y4:=vas_my_first(y);
    for k:=1 : length(vas_my_first(y)) do
    begin
      y3:=vas_my_first(y4);
      y4:=vas_my_rest(y4);
      rr:=vas_my_first(y3);
      listrationalfactorsraisedmult:= append(listrationalfactorsraisedmult, 
          {(x-rr)^(vas_my_first(vas_my_rest(y)))}); 
    end;
    y2:=vas_my_rest(y2);
  end;
return listrationalfactorsraisedmult;
end;

procedure vas_my_sort_multiplicity(allintervals);
%---++++++++++++++++++++++
%---input:{{{{3,3}},1},{{{2,2}},2},{{{-4,0},{5/4,3/2},{3/2,2}},1}}
%---output:{{{{3,3}},1},{{{-4,0},{5/4,3/2},{3/2,2}},1},{{{2,2}},2}}
%---++++++++++++++++++++++

begin scalar temp,i,j;
  for i := 1 : length(allintervals)-1 do  
  begin
    for j := i+1 : length(allintervals) do
    begin
      if part(allintervals,j,2) < part(allintervals,i,2) then 
      begin 
        temp := part(allintervals,i);
        allintervals := part(allintervals,i) := part(allintervals,j);
        allintervals := part(allintervals,j) := temp;
      end;
    end;
  end;
return allintervals;
end;

procedure vas_realintervals(pt);
%---++++++++++++++++++++++
%---Implements the Vincent-Akritas-Strzebonski method for the 
%---isolation of the IRRATIONAL roots of polynomials with integer 
%---coefficients. The RATIONAL roots are computed with the function 
%---r_solve of the package resolve of Reduce and are removed from the original poly.
%---
%---Returns a list of the isolation intervals of ALL the roots 
%---along with their multiplicity.
%---
%---Reference:	"A Comparative Study of Two Real Root Isolation Methods" 
%---by Alkiviadis G. Akritas and Adam W. Strzebonski. 
%---Nonlinear Analysis: Modelling and Control, Vol. 10, No. 4, 297-304, 2005.
%---
%---Comments:: This way our function vas_interval_split does NOT have to deal 
%---with intervals of the form
%---{a, a} and {a, b}, where a is a rational root.
%---That is, we know for sure that the end-points will NOT be roots of the poly
%---and can easily evaluate pt at them!
%---++++++++++++++++++++++

begin scalar p1,k,p,j,pol,poly,listrationalfactors,
irrationalrootsintervals, rationalrootsintervals, productrationalfactors,
allintervals, rationalrootsonly, i, prod, temp;

% comment take care of rounded;

if lisp !*rounded then rounded_was_on := t 
 else rounded_was_on := nil;

off rounded;

% comment constants;

if mainvar(pt) = 0 then return {};  

% comment check for valid input; 

temp:=coeff( pt, mainvar ( pt ) );
temp:=map(mainvar, temp);
temp:=map(~x => if (x eq 0) then 1 else 0 ,temp);
prod:=1; for each x in temp do prod:=x*prod ; 
if (prod eq 0) then  return(vas_realintervals_invalid_poly!_input_poly_should_have_one_variable_and_rational_coefficients) ;

% comment initialize;
% comment rationalRootsONLY=1 means there are ONLY rational roots;

productrationalfactors:=1;
rationalrootsonly:=0;

% comment change poly variable to x, so that it works for polys in ANY variable;

p:=vas_list2poly(reverse(coeff(pt,mainvar(pt))),x);

% comment take the numerator if poly = (x-a/b)*(x-c/d)* etc *(x-y/z);

p:=num( p );

% comment with positive leading coefficient;

if ( lcof(p,x) < 0 ) then p:=(-1)*p;

% comment remove the content for smaller coefficients; 

p:=p/vas_content(p,x);

% comment find the rational roots and form their "isolating intervals" {{{a, a}, m}, etc };

rationalrootsintervals:= vas_formrationalrootintervals( p );

% comment Form the product of the factors with rational roots and divide it out of the poly;

if length(rationalrootsintervals) > 1 or (
(length(rationalrootsintervals) =1) and (length(part(rationalrootsintervals,1,1))
neq 0) ) then 
begin
  listrationalfactors:=vas_list_linear_factors_raised_mult(rationalrootsintervals);
  productrationalfactors:=for i:=1 step 1 until length(listrationalfactors) product part(listrationalfactors,i) 
end else rationalrootsintervals:={};

productrationalfactors:=num(productrationalfactors);
poly := first(divide(p,productrationalfactors));
poly := poly/vas_content(poly,x);

% comment If poly =1, all roots are rational. Set rationalRootsONLY to 1;

if poly = 1 then
begin
   poly := p;
   irrationalrootsintervals := list();
   rationalrootsonly := 1;
end;

% comment rationalRootsONLY=0 means we have irrational roots to be isolated using VAS;


if rationalrootsonly = 0 then
begin
   pol :=sqfdec(poly);
   irrationalrootsintervals:= for i:=1 : length(pol) collect({0});
   for k:=1 :length(pol) do
   begin
     irrationalrootsintervals := part(irrationalrootsintervals,k):= {vas(part(pol,k,1),x),
          part(pol,k,2)};
   end;
end;

% comment merge the intervals for the rational and irrational roots;

allintervals:= union (rationalrootsintervals, irrationalrootsintervals);

% comment sort them according to multiplicity;

allintervals:= vas_my_sort_multiplicity(allintervals);

% comment If rationalRootsONLY=0, combine sublists of same multiplicity (to conform to structure of pol);
% comment allIntervals is now of the form {{{{a,b},{},..},m}, etc }; 
% comment Moreover, a rational root {{a,a}, m} does NOT have the corresponding factor in pol, so we insert in it the factor {x-a, m};

if rationalrootsonly = 0 then
begin
     allintervals:=vas_combinesublistsofsamemultiplicity(allintervals);
    pol:=vas_addmissingsqrfreefactors(pol,allintervals);
end;
if rationalrootsonly neq 0 then pol:=sqfdec(poly);

% comment If rationalRootsONLY=0, make sure there is no interval overlap within a given multiplicity and among different multiplicities;

if rationalrootsonly = 0 then 
begin
    allintervals:= vas_interval_overlap2(pol,allintervals);
    allintervals:=vas_interval_overlap(pol,allintervals);
end;


% comment sort intervals;
allintervals:=vas_interval_sort(allintervals);

% comment take care of rounded;
if not rounded_was_on then off rounded else on rounded;

return allintervals;

end;




procedure vas_my_sqrfree(p);
%---++++++++++++++++++++++
%---Returns the product of the square free factors all taken to the power 1.
%---The poly obtained this way is used in bzero. The case of p=integers (including p = 0) 
%---is handled by vas_realintervals
%---++++++++++++++++++++++

begin scalar flist;
  flist:=map(~xx=>first(xx),sqfdec( p ));  
return for i:=1 step 1 until length(flist) product part(flist,i);
end;

procedure vas_my_sort_numbers(listnumbers);
%---++++++++++++++++++++++
%---sorts a list of real numbers 
%---++++++++++++++++++++++

begin scalar temp,i,j; 
 for i := 1 : length(listnumbers)-1 do 
 begin 
   for j :=i+1 : length(listnumbers) do 
   begin 
     if part(listnumbers,j) < part(listnumbers,i) then 
     begin 
       temp := part(listnumbers,i); 
       listnumbers := part(listnumbers,i) := part(listnumbers,j); 
       listnumbers := part(listnumbers,j) := temp; 
     end; 
   end; 
 end; 
return listnumbers; 
end;


procedure xapply(f,lst);
lisp(f . cdr(lst))$

symbolic operator vas_rfind;

symbolic procedure vas_rfind(p, l, h);
%---++++++++++++++++++++++
%---by Fujio Kako to use rootfind in algebraic mode;
%---inputs are a poly and the endpoints of an interval.
%---output: the rut contained in the interval {l, h}.
%---++++++++++++++++++++++
begin scalar j, pr, res;
 pr:=precision(0);
 rootacc!#!# := pr;
 acc!# := pr;
 rprec!#:=pr;
 !*bftag:=t;  % make computations in bigfloat mode;
 j:=cons(cons(num l, den l), cons(num h, den h));
 p:=!*q2f simp p;
 p:=gffinit p;
 p:=mkinteg p;
	% integer coefficient of poly;
 !*intp := fillz p;
	% fill zero terms;
p:=foreach l in p collect cons(car l , i2bf!: cdr l);
	% convert coefficients of poly into bigfloat;
 res := rootfind(p, j);
 return res;
end;

procedure vas_approx_roots(p,rootintervalspoly);
%---++++++++++++++++++++++
%---Uses Reduce's procedure rootfind (thru its interface vas_rfind) to approximate the real roots 
%---given rootIntervals, their list of isolation intervals .
%---
%---Computes the real roots in the corresponding intervals.
%---++++++++++++++++++++++

begin scalar  irratrootintervals, irratroots, listrationalfactors, pp, ratpoly, 
ratrootintervals, rootintervals, ratroots, rootslist;

% comment store value of rounded;

if lisp !*rounded then rounded_was_on := t 
 else rounded_was_on := nil;

% comment empty list or constant p;

if rootintervalspoly = {} or mainvar(p) = 0 then return {};

% comment check for valid input; 

temp:=coeff( p, mainvar ( p ) );
temp:=map(mainvar, temp);
temp:=map(~x => if (x eq 0) then 1 else 0 ,temp);
prod:=1; for each x in temp do prod:=x*prod ; 
if (prod eq 0) then  return(vas_approx_roots_invalid_poly!_input_poly_should_have_one_variable_and_rational_coefficients) ;

% comment initialize;

rootintervals:=rootintervalspoly;
off rounded;


% comment change poly variable to x, so that it works for polys in ANY variable;

pp:=vas_list2poly(reverse(coeff(p,mainvar(p))),x);

% comment take the numerator if poly = (x-a/b)*(x-c/d)* etc *(x-y/z);

pp:=num( pp );

% comment with positive leading coefficient;

if ( lcof(pp,x) < 0 ) then pp:=(-1)*pp;

% comment remove the content for smaller coefficients; 

pp:=pp/vas_content(pp,x);

% comment compute the product of the square free factors ALL raised to the power 1;

pp:=vas_my_sqrfree(pp);

% comment compute the rational roots and remove their product from pp;

ratrootintervals:=for i:=1 step 1 until length(rootintervals) collect 
if first(first(part(rootintervals,i)))=second(first(part(rootintervals,i))) 
then first(part(rootintervals,i)) else {};

ratrootintervals:=union(ratrootintervals);
if length(ratrootintervals)=1 and first ratrootintervals ={} then ratrootintervals:={};

if ratrootintervals neq {} then ratrootintervals:= select(~xx=> xx neq {},ratrootintervals);

ratroots:= map(~xx =>  first(xx) ,ratrootintervals);

listrationalfactors:= map(~xx => den(xx)*(x-xx) , ratroots);

ratpoly:=for i:=1 step 1 until length(listrationalfactors) product
part(listrationalfactors,i);

pp := first(divide(pp,ratpoly));
pp:=pp/vas_content(pp,x);

if pp=1 then 
begin
  rootslist:=vas_my_sort_numbers( evalf ( ratroots ) );
  go to label;
end;

% comment compute the irrational root intervals and approximate the corresponding roots ;

irratrootintervals:=for i:=1 step 1 until length(rootintervals) collect if
first(first(part(rootintervals,i))) neq second(first(part(rootintervals,i)))
then part(rootintervals,i) else {};

irratrootintervals:=union(irratrootintervals);

if length(irratrootintervals)=1 and first irratrootintervals ={} then irratrootintervals:={};

if irratrootintervals neq {} then irratrootintervals:= select(~xx=> xx neq {},irratrootintervals);

irratrootintervals:=for i:=1 step 1 until length(irratrootintervals) collect
first(part(irratrootintervals,i));

% comment The precision is that defined by evalf in vas_poslbdLMQ and vas_posubLMQ ;

irratroots:=for i:=1 step 1 until length(irratrootintervals) collect 
vas_rfind(pp, first( part(irratrootintervals,i)), second(
part(irratrootintervals,i)) );

% comment merge the two lists of roots and sort the resulting one;
 
rootslist:=  union(irratroots, ratroots  );

rootslist:=vas_my_sort_numbers(rootslist);

% comment exit ;

label:
rootslist:=map(xx => mainvar(p)=xx,rootslist);

% comment RE-store value of rounded;
if not rounded_was_on then off rounded;

return rootslist;


end;




%---+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
%+++++++++++++++++++++++ sets.red package +++++++++++++++++++++++++
%---+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


module sets;  % Operators for basic set theory.

%% Author: F.J.Wright@Maths.QMW.ac.uk.
%% Date: 20 Feb 1994.

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


%% WARNING: This module patches mk!*sq.

%% To do:
%% Improve symbolic set-Boolean analysis.
%% Rationalize the coding?

%% A nice illustration of fancy maths printing in the graphics mode
%% of PSL-REDUCE under MS-Windows and X, but it works properly only with
%% interface versions compiled from sources dated after 14 Feb 1994.

%% Defines the set-valued infix operators (with synonyms):
%%   union, intersection (intersect), setdiff (minus, \),
%% and the Boolean-valued infix operators:
%%   member, subset_eq, subset, set_eq.
%% Arguments may be algebraic-mode lists representing explicit sets,
%% or identifiers representing symbolic sets, or set-valued expressions.
%% Lists are converted to sets by deleting any duplicate elements, and
%% sets are sorted into a canonical ordering before being returned.
%% This can also be done explicitly by applying the unary operator
%% mkset.  The set-valued operators may remain symbolic, but
%% REDUCE does not currently support this concept for Boolean-valued
%% operators, and so neither does this package (although it could).
%% Set-theoretic simplifications are performed, but probably not fully.

%% A naive power set procedure is included as an algebraic example
%% in the test file (sets.tst).


%% A proposed new coding style:
deflist('((local scalar)), 'newnam);
%% (DEFLIST used because flagged eval -- PUT does not work during
%% faslout!)

%% One good reason not to use `\' in place of `!' ?
newtok '((!\) setdiff);
%% NOTE that this works in graphics mode under Windows or X PSL-REDUCE
%% ONLY with versions compiled from sources dated after 14 Feb 1994.
%% The following statement should really be in fmprint.red:
put('setdiff, 'fancy!-infix!-symbol, "\backslash");

%% A set is sorted before it is returned for purely cosmetic reasons,
%% except that together with duplicate elimination this makes the repre-
%% sentation canonical and so list equality can be used as set equality.

create!-package('(sets),'(contrib misc));

symbolic smacro procedure sort!-set l;
   sort(l, function set!-ordp);

symbolic procedure set!-ordp(u, v);
   %% Ordp alone (as used by ordn to implement symmetry) looks strange.
   %% This seems like a reasonable compromise.
   if numberp u and numberp v then u < v else ordp(u, v);


%% Set-valued operators:
%% ====================
infix union, intersection, setdiff;
put('intersect, 'newnam, 'intersection);
put('minus, 'newnam, 'setdiff);         % cf. Maple!
precedence setdiff, -;
precedence union, setdiff;
precedence intersection, union;

%% Must be simpfns for let rules to be applicable.
put('union, 'simpfn, 'simpunion);
put('intersection, 'simpfn, 'simpintersection);
put('setdiff, 'simpfn, 'simpsetdiff);

flag('(union intersection), 'nary);     % associativity
put('union, 'unary, 'union);            % for completeness
put('intersection, 'unary, 'intersection);
listargp union, intersection;           % necessary for unary case
%% Symmetry is normally implemented by simpiden, which is not
%% used here and the symmetry is implemented explicitly,
%% but the symmetric flag is also used when applying let rules.
flag('(union intersection), 'symmetric); % commutativity

%% Intersection distributes over union, which is implemented
%% as a rule list at the end of this file.

global '(empty_set);  symbolic(empty_set := '(list));

%% Below ordn sorts for symmetry as in simpiden for symmetric operators

symbolic procedure simpunion args;
   %% x union {} = x, union x = x
   !*kk2q(if car r eq 'union
      then if cdr(r := delete(empty_set, cdr r))
         then 'union . ordn r else car r
      else r)
   where r = applysetop('union, args);

symbolic procedure simpintersection args;
   %% x intersect {} = {}, intersection x = x
   !*kk2q(if car r eq 'intersection
      then if empty_set member(r := cdr r) then empty_set
         else if cdr r then 'intersection . ordn r else car r
      else r)
   where r = applysetop('intersection, args);

symbolic procedure simpsetdiff args;
   %% x setdiff x = {} setdiff x = {}, x setdiff {} = x.
   !*kk2q(if car r eq 'setdiff
      then if cadr r = caddr r or cadr r = empty_set then empty_set
         else if caddr r = empty_set then cadr r else r
      else r)
   where r = applysetop('setdiff, args);

%% The following mechanism allows unevaluated operators to remain
%% symbolic and supports n-ary union and intersection.

%% Allow set-valued expressions as sets:
flag('(union, intersection, setdiff), 'setvalued);

symbolic procedure applysetop(setop, args);
   %% Apply binary Lisp-level set functions to pairs of explicit
   %% set args and collect symbolic args:
   begin local set_arg, sym_args, setdiff_args;
      set_arg := 0;                    % cannot use nil as initial value
      setdiff_args := for each u in args collect
      %% reval form makes handling kernels and sorting easier:
         if eqcar(u := reval u, 'list) then
            << u := delete!-dups cdr u;
               set_arg := if set_arg = 0 then u
                  else apply2(setop, set_arg, u);
               make!-set u >>
         else if idp u or (pairp u and flagp(car u, 'setvalued)) then
            %% Implement idempotency for union and intersection:
            << if not(u member sym_args)
                 then sym_args := u . sym_args; u >>
         %% else typerr(if eqcar(u,'!*sq) then prepsq cadr u
         %%              else u,"set");
         else typerr(u, "set");         % u was reval'ed
      return if sym_args then
         setop . if setop eq 'setdiff then setdiff_args else
            if set_arg = 0 then sym_args
             else make!-set set_arg . sym_args
      else aeval make!-set set_arg      % aeval NEEDED for consistency
   end;

symbolic operator mkset;

symbolic procedure mkset rlist;
   %% Make a set from an algebraic-mode list:
   make!-set delete!-dups getrlist rlist;

%% The function list2set is already defined in PSL
%% to remove duplicates and PARTIALLY sort,
%% but it is not defined in the REDUCE sources.

symbolic procedure make!-set l;
   makelist sort!-set l;

symbolic procedure delete!-dups l;
   if l then
      if car l member cdr l then delete!-dups(cdr l)
      else car l . delete!-dups(cdr l);


%% Boolean-valued operators:
%% ========================
infix subset_eq, subset, set_eq;        % member already declared
precedence subset_eq, <;
precedence subset, subset_eq;
precedence set_eq, =;

put('member, 'boolfn, 'evalmember);
put('subset_eq, 'boolfn, 'evalsubset_eq);
put('subset, 'boolfn, 'evalsubset);
put('set_eq, 'boolfn, 'evalset_eq);

%% Boolfns get their arguments aeval'd automatically.

symbolic procedure evalmember(el, rlist);
   %% Special case -- only applicable to explicit lists.
   member(el, getrlist rlist);

symbolic procedure evalsubset_eq(u, v);
   (if atom r then r else apply(function equal, r) or evalsymsubset r)
      where r = evalsetbool('subset_eq, u, v);

put('subset_eq, 'setboolfn, function subsetp);

symbolic procedure evalsubset(u, v);
   (if atom r then r else evalsymsubset r)
      where r = evalsetbool('subset, u, v);

put('subset, 'setboolfn, function subsetneqp);

symbolic procedure subsetneqp(u, v);
   subsetp(u,v) and not subsetp(v,u);

symbolic procedure evalsymsubset args;
   %% This analysis assumes symbolic sets are non-empty, otherwise
   %% the relation may be equality rather than strict inclusion.
   %% Could or should this analysis be extended?
   ((eqcar(v, 'union) and u member cdr v) or
    (eqcar(u, 'intersection) and v member cdr u) or
    (eqcar(u, 'setdiff) and
       (cadr u = v or (eqcar(v, 'union) and cadr u member cdr v))))
      where u = car args, v = cadr args;

%% Set equality can use list equality provided the representation
%% is canonical (duplicate-free and ordered).  The following set
%% equality predicate is independent of set implementation,
%% and implements precisely the formal mathematical definition.

symbolic procedure evalset_eq(u, v);
   (if atom r then r else apply(function equal, r))
      where r = evalsetbool('set_eq, u, v);

put('set_eq, 'setboolfn, function setequal);

symbolic procedure setequal(u, v);
   subsetp(u,v) and subsetp(v,u);

symbolic procedure evalsetbool(setbool, u, v);
   begin local r, set_args, sym_args;
      r := for each el in {u, v} collect
         if eqcar(el, 'list) then
            << set_args := t;  cdr el >>
         %% reval form makes handling kernels easier:
         else if idp(el := reval el) or
               (pairp el and flagp(car el, 'setvalued)) then
            << sym_args := t;  el >>
         else typerr(el, "set");        % el was reval'ed
      return if set_args then
         if sym_args then               % RedErr
            msgpri("Cannot evaluate", {setbool, reval u, reval v},
               "as Boolean-valued set expression", nil, t)
         else apply(get(setbool,'setboolfn), r)
      else r
   end;


%% Boolean evaluation operator:
%% ===========================
%% Nothing to do with sets, but useful for testing Boolean operators:

symbolic operator evalb;                % cf. Maple
symbolic procedure evalb condition;
   if eval formbool(condition, nil, 'algebraic) then 'true else 'false;

flag('(evalb), 'noval);  % because evalb evals its argument itself

%% Note that this does not work - it generates the wrong code:
%% algebraic procedure evalb condition;
%%    if condition then true else false;


%% Set simplification rules:
%% ========================

algebraic;

set_distribution_rule := {~x intersection (~y union ~z) =>
   (x intersection y) union (x intersection z)};

endmodule;

end;

