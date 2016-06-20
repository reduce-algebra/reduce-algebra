off echo$
%*******************************************************************%
%                                                                   %
%                     S S T O O L S . T S T                         %
%                     ---------------------                         %
%                                                                   %
%  Authors: Thomas Wolf, Eberhard Schruefer                         %
%  Date:    2016                                                    %
%                                                                   %
%                                                                   %
%  The statement lisp(print_:=nil); suppresses output of the        %
%  computation. To see details of it do lisp(print_:=50).           %
%                                                                   %
%*******************************************************************%

load sstools,crack$

depend  {f,b},s$ 

off nat$ off gc$

lisp<<
 terpri()$
 write"The sole purpose of this file is to facilitate checking that the"$
 terpri()$
 write"used version of SSTOOLS works correctly. A description of the"$
 terpri()$
 write"syntax can be currently found in the online tutorial at"$
 terpri()$
 write"https://lie.ac.brocku.ca/crack/susy/."$
 terpri()$
 write"That tutorial explains all calculations below."$
 terpri()$
 terpri()$
 write"To verify the correctness of SSTOOLS check once the correctness of"$
 terpri()$
 write"all commands in sstools.tst and then run it and check whether all"$
 terpri()$
 write"printed relations are identities."$
 terpri()$
>>$

write"Initial test"$
write"b(1)*df(f(1),x)*d(1,f(1))-d(1,f(1))*b(1)*df(f(1),x) = 0 = ",
      b(1)*df(f(1),x)*d(1,f(1))-d(1,f(1))*b(1)*df(f(1),x);

write"Rules for powers"$
write"f(1)**2 = 0 = ",
      f(1)**2;
lisp<<terpri()$write"b(1)**3=">>$
                     b(1)**3;
lisp<<terpri()$write"df(b(1),x)**2=">>$
                     df(b(1),x)**2;
lisp<<terpri()$write"d(1,f(1))**2=">>$
                     d(1,f(1))**2;
write"d(1,b(1))**2 = 0 = ",
      d(1,b(1))**2;
lisp<<terpri()$write"df(b(1),t)**2=">>$
                     df(b(1),t)**2;

write"f(i) become constant:"$
write"nodepend f,x,t,s"$
      nodepend f,x,t,s$
write"df(f(1),x) = 0 = ",
      df(f(1),x);
write"f(i) depend again on x,t,s:"$
write"depend f,x,t,s"$
      depend f,x,t,s$
lisp<<terpri()$write"df(f(1),x)=">>$
                     df(f(1),x);

write"Normal bosonic derivatives"$
lisp<<terpri()$write"df(b(1),t)**2=">>$
                     df(b(1),t)**2; 
lisp<<terpri()$write"df(b(1),s)**2=">>$
                     df(b(1),s)**2; 

write"Now s changes parity:"$
write"on  s_changes_parity"$
      on  s_changes_parity$ 
write"df(b(1),s)**2 = 0 = ",
      df(b(1),s)**2;
write"df(b(1),s)*df(b(1),s) = 0 = ",
      df(b(1),s)*df(b(1),s)$
lisp<<terpri()$write"df(f(1),s)*df(f(1),s) = "$
      terpri()$                              write"df(f(1),s)**2 = ">>$
                     df(f(1),s)*df(f(1),s);

write"Now s does NOT change parity:"$
write"off s_changes_parity"$
      off s_changes_parity$ 
lisp<<terpri()$write"df(b(1),s)*df(b(1),s) = "$
      terpri()$                              write"df(b(1),s)**2 = ">>$
                     df(b(1),s)*df(b(1),s);
write"df(f(1),s)*df(f(1),s) = 0 = ",
      df(f(1),s)*df(f(1),s);
write"df(f(1),s)**2 = 0 = ",
      df(f(1),s)**2;

write"Commutator of derivatives:"$
write"df(df(b(1),s),t)-df(df(b(1),t),s) = 0 = ",
      df(df(b(1),s),t)-df(df(b(1),t),s);

write"df(df(f(1),s),t)-df(df(f(1),t),s) = 0 = ",
      df(df(f(1),s),t)-df(df(f(1),t),s);

write"Now s changes parity:"$ 
write"on  s_changes_parity"$
      on  s_changes_parity$
write"df(df(b(1),s),t)-df(df(b(1),t),s) = 0 = ",
      df(df(b(1),s),t)-df(df(b(1),t),s);
write"df(df(f(1),s),t)-df(df(f(1),t),s) = 0 = ",
      df(df(f(1),s),t)-df(df(f(1),t),s);
lisp<<terpri()$write"d(1,df(b(1),s))-df(d(1,b(1)),s) = "$
      terpri()$                                     write"2*d(1,df(b(1),s)) = ">>$
                     d(1,df(b(1),s))-df(d(1,b(1)),s);
lisp<<terpri()$write"d(1,df(f(1),s))-df(d(1,f(1)),s) = "$
      terpri()$                                     write"2*d(1,df(f(1),s)) = ">>$
                     d(1,df(f(1),s))-df(d(1,f(1)),s);
write"d(1,df(b(1),t))-df(d(1,b(1)),t) = 0 = ",
      d(1,df(b(1),t))-df(d(1,b(1)),t);
write"d(1,df(f(1),t))-df(d(1,f(1)),t) = 0 = ",
      d(1,df(f(1),t))-df(d(1,f(1)),t);

write"Now t changes parity as well:"$ 
write"on  t_changes_parity"$
      on  t_changes_parity$
lisp<<terpri()$write"df(df(b(1),s),t)-df(df(b(1),t),s) = "$
      terpri()$                                       write"2*df(b(1),s,t) = ">>$
                     df(df(b(1),s),t)-df(df(b(1),t),s);
lisp<<terpri()$write"df(df(f(1),s),t)-df(df(f(1),t),s) = "$
      terpri()$                                       write"2*df(f(1),s,t) = ">>$
                     df(df(f(1),s),t)-df(df(f(1),t),s);

write"Now s,t do not change parity anymore:"$
write"off s_changes_parity"$
      off s_changes_parity$
write"off t_changes_parity"$
      off t_changes_parity$

write"Commutator relations:"$
write"f(1)*f(2)+f(2)*f(1) = 0 = ",
      f(1)*f(2)+f(2)*f(1);
lisp<<terpri()$write"b(1)*f(2)+f(2)*b(1) = "$
      terpri()$                              write"2*f(2)*b(1) = ">>$
                     b(1)*f(2)+f(2)*b(1);
lisp<<terpri()$write"b(1)*b(2)+b(2)*b(1) = "$
      terpri()$                              write"2*b(2)*b(1)=">>$
                     b(1)*b(2)+b(2)*b(1);
write"d(1,b(1))*d(1,b(1)) = 0 = ",
      d(1,b(1))*d(1,b(1));

write"Rules for d(i,..):"$ 
lisp<<terpri()$write"df(b(1),x)=">>$d(1,d(1,b(1)));
lisp<<terpri()$write"df(f(1),x)=">>$d(1,d(1,f(1)));
write"d(1,d(2,f(1)))+d(2,d(1,f(1))) = 0 = ",
      d(1,d(2,f(1)))+d(2,d(1,f(1)));
write"d(1,d(2,b(1)))+d(2,d(1,b(1))) = 0 = ",
      d(1,d(2,b(1)))+d(2,d(1,b(1)));
lisp<<terpri()$write"d(1,-f(1)) = "$
      terpri()$                     write" - d(1,f(1)) = ">>$
                     d(1,-f(1));
write"d(1,a) = 0 = ",d(1,a);
write"d(1,f(1)**3) = 0 = ",d(1,f(1)**3);
lisp<<terpri()$write"d(1,u*f(1)+f(2)/v) = "$
      terpri()$                         write"(d(1,f(2)) + d(1,f(1))*u*v)/v = ">>$
                     d(1,u*f(1)+f(2)/v);

lisp<<terpri()$write"df(d(1,f(1)),x) = "$
      terpri()$                         write"d(1,df(f(1),x)) = ">>$
                     df(d(1,f(1)),x);
lisp<<terpri()$write"df(d(1,f(1)),t) = "$
      terpri()$                         write"d(1,df(f(1),t)) = ">>$
                     df(d(1,f(1)),t);
lisp<<terpri()$write"d(1,f(1))**2 = "$
      terpri()$                         write"d(1,f(1))**2 = ">>$
                     d(1,f(1))**2;
write"d(1,b(1))**2 = 0 = ",
      d(1,b(1))**2;

write"Now t changes parity:"$
write"on  t_changes_parity"$ 
      on  t_changes_parity$ 
lisp<<terpri()$write"df(d(1,f(1)),t) = "$
      terpri()$                          write" - d(1,df(f(1),t)) = ">>$
                     df(d(1,f(1)),t);

write"Now t does NOT change parity:"$
write"off t_changes_parity"$
      off t_changes_parity$
lisp<<terpri()$write"d(1,b(1)**3) = "$
      terpri()$                          write"3*d(1,b(1))*b(1)**2=">>$
                     d(1,b(1)**3);

write"Product rule for df(..,x):"$

write"Now t changes parity:"$
write"on  t_changes_parity"$
      on  t_changes_parity$
lisp<<terpri()$write"df(f(1)*b(1),t) = "$terpri()$write"b(1)*df(f(1),t) - f(1)*df(b(1),t) = ">>$
                     df(f(1)*b(1),t);
lisp<<terpri()$write"df(b(1)*f(1),t) = "$terpri()$write"b(1)*df(f(1),t) - f(1)*df(b(1),t) = ">>$
                     df(b(1)*f(1),t);
lisp<<terpri()$write"df(f(1)*f(2),t) = "$terpri()$write"f(2)*df(f(1),t) - f(1)*df(f(2),t) = ">>$
                     df(f(1)*f(2),t);
lisp<<terpri()$write"df(f(2)*f(1),t) = "$terpri()$write" - f(2)*df(f(1),t) + f(1)*df(f(2),t) = ">>$
                     df(f(2)*f(1),t);

write"From now on t does NOT change parity:"$
write"off t_changes_parity"$
      off t_changes_parity$
lisp<<terpri()$write"df(f(1)*b(1),t) = "$terpri()$write"b(1)*df(f(1),t) + f(1)*df(b(1),t) = ">>$
                     df(f(1)*b(1),t);
lisp<<terpri()$write"df(b(1)*f(1),t) = "$terpri()$write"b(1)*df(f(1),t) + f(1)*df(b(1),t) = ">>$
                     df(b(1)*f(1),t);
lisp<<terpri()$write"df(f(1)*f(2),t) = "$terpri()$write" - f(2)*df(f(1),t) + f(1)*df(f(2),t)=">>$
                     df(f(1)*f(2),t);
lisp<<terpri()$write"df(f(2)*f(1),t) = "$terpri()$write"f(2)*df(f(1),t) - f(1)*df(f(2),t)=">>$
                     df(f(2)*f(1),t);

write"Product rule for d(i,..):"$
lisp<<terpri()$write"d(1,f(1)*b(1)) = "$terpri()$write"d(1,b(1))*f(1) + d(1,f(1))*b(1) = ">>$
                     d(1,f(1)*b(1));
lisp<<terpri()$write"d(1,b(1)*f(1)) = "$terpri()$write"d(1,b(1))*f(1) + d(1,f(1))*b(1) = ">>$
                     d(1,b(1)*f(1));
lisp<<terpri()$write"d(1,f(1)*f(2)) = "$terpri()$write" - d(1,f(2))*f(1) + d(1,f(1))*f(2) = ">>$
                     d(1,f(1)*f(2));
lisp<<terpri()$write"d(1,f(2)*f(1)) = "$terpri()$write"d(1,f(2))*f(1) - d(1,f(1))*f(2) = ">>$
                     d(1,f(2)*f(1));
lisp<<terpri()$write"d(1,b(1)*b(2)) = "$terpri()$write"d(1,b(2))*b(1) + d(1,b(1))*b(2) = ">>$
                     d(1,b(1)*b(2));

write"Further combined tests"$
lisp<<terpri()$write"d(1,d(1,d(2,b(1)))**2) = "$
      terpri()$write"2*d(2,df(b(1),x))*d(1,d(2,b(1))) = ">>$
                     d(1,d(1,d(2,b(1)))**2);
write" - d(2,b(1))*d(1,d(2,b(1))) + d(1,d(2,b(1)))*d(2,b(1)) = 0 = ",
       - d(2,b(1))*d(1,d(2,b(1))) + d(1,d(2,b(1)))*d(2,b(1));
write"An assignment:"$
write"df(f(1),s):=d(1,b(1))"$ 
      df(f(1),s):=d(1,b(1))$ 
lisp<<terpri()$write"df(f(1),x,s) = "$terpri()$write"d(1,df(b(1),x)) = ">>$
                     df(f(1),x,s);
write"Clearing that assignment:"$
write"clear df(f(1),s)"$
      clear df(f(1),s)$
lisp<<terpri()$write"df(f(1),s)=">>$
                     df(f(1),s);

write"Now check of a LET-rule:"$
write"rule:={f(1) => 1}$ let rule"$
      rule:={f(1) => 1}$ let rule$
write"df(f(1),x) = 0 = ",df(f(1),x);
write"Now clearing the LET-rule:"$
write"clearrules rule"$
      clearrules rule$

write"d(1,b(1))-d(first {1},b(1)) = 0 = ",
      d(1,b(1))-d(first {1},b(1));

write"Now theta and ff are defined as fermions:"$
write"fermion theta,ff"$
      fermion theta,ff$
write"df(theta(1),theta(1)) = 1 = ",
      df(theta(1),theta(1));
write"df(theta(1),theta(2)) = 0 = ",
      df(theta(1),theta(2));
write"df(theta(1)*theta(2),theta(1)) = theta(2) = ",
      df(theta(1)*theta(2),theta(1));
write"df(theta(1)*theta(2),theta(2)) = - theta(1) = ",
      df(theta(1)*theta(2),theta(2));
write"df(theta(1)*ff(1,0),theta(1)) = ff(1,0) = ",
      df(theta(1)*ff(1,0),theta(1));
write"df(ff(1,0)*theta(2),theta(2)) = - ff(1,0)=",
      df(ff(1,0)*theta(2),theta(2));

write"Now a test that the function is_fermionic() works correctly:"$
if is_fermionic(b(1)*b(2)) then write"nil=  t" else write"nil=nil"$
if is_fermionic(b(1)*f(2)) then write"  t=  t" else write"  t=nil"$
if is_fermionic(f(1)*f(2)) then write"nil=  t" else write"nil=nil"$

write"Coefficient test:"$
lisp<<
terpri()$
write"coeffn(D(1,b(1))*D(1,df(b(2),x,2)),"$       terpri()$
write"                 D(1,df(b(2),x,2)), 1) = "$ terpri()$ 
                                            write" - d(1,b(1))=">>$
      coeffn(D(1,b(1))*D(1,df(b(2),x,2)),
                       D(1,df(b(2),x,2)), 1);    

write"Matrix computation:"$
write"mat(( - f(2)*f(1),0),(0,0))"$  lisp write "="$ 
      mat((f(1)*f(2),0), (0, 0));    lisp write "="$ 
      mat((1,0), (0,0))*f(1)*f(2);   lisp write "="$ 
      f(1)*f(2)*mat((1,0), (0,0));

aa := f(1)*mat((1,0),(0,0))$
lisp<<terpri()$write"aa:=f(1)*mat((1,0),(0,0)) = "$
      terpri()$write"mat((f(1),0),(0,0))">>$
                     aa;
lisp<<terpri()$write"f(2)*aa = "$terpri()$write"mat((f(2)*f(1),0),(0,0))">>$
                     f(2)*aa;        lisp write "= - aa*f(2) ="$ 
                                                   - aa*f(2);
clear aa$

lisp<<terpri()$terpri()$
 write"-----------------------------------------------------"$
 terpri()$terpri()$
 write"To check the correctness of the following computations "$terpri()$
 write"one needs to compare the output with the file sstools.rlg ."$
 terpri()$
>>$

write"#####################################################"$

write"Tests related to symmetry computations:"$ 

write"====================================================="$
write"1. Symmetry computation"$
ssym(1,4,5,{2},{2},{},{},{},{})$ 
clear_session_files()$

% About using  merge_sol()$ and print_all_sol()$ to merge 
% and print all solutions please see the interactive tutorial

write"====================================================="$
write"2. Symmetry computation"$
ssym(1,4,5,{2},{2},
     {df(f(1),t)=df(f(1),x)*b(1)*p9,
      df(b(1),t)=df(b(1),x)*b(1)*p9 + df(f(1),x)*f(1)*p4},
     {},{},{})$ 
clear_session_files()$

lisp put('f,'prifn,nil)$  % from now on more than one fermion 
lisp put('b,'prifn,nil)$  % from now on more than one boson 

write"====================================================="$
write"3. Symmetry computation"$
ssym(1,1,4,{1,1},{1,3,1,3}, 
     {df(f(1),t)=>-2*f(1)*b(1)*p1,  
      df(b(1),t)=>b(1)**2*p1+d(1,f(1))*p2,  
      d(1,b(2)) =>-df(b(1),x)*f(1),  
      df(b(2),t)=>-2*d(1,b(1))*f(1)*b(1)*p1+d(1,df(b(1),t))*f(1)
                  -d(1,f(1))**2*p2/2-d(1,f(1))*b(1)**2*p1
                  +d(1,f(1))*df(b(1),t),
      df(f(2),t)=-2*f(2)*b(1)*p1-2*f(1)*b(3)*p1,  
      df(b(3),t)=2*b(1)*b(3)*p1+d(1,f(2))*p2,  
      d(1,b(4)) =>-df(b(3),x)*f(1)-df(b(1),x)*f(2),  
      df(b(4),t)=>-2*d(1,b(3))*f(1)*b(1)*p1-2*d(1,b(1))*f(2)*b(1)*p1
                  -2*d(1,b(1))*f(1)*b(3)*p1+d(1,df(b(3),t))*f(1) 
                  +d(1,df(b(1),t))*f(2)-d(1,f(1))*d(1,f(2))*p2 
                  -d(1,f(2))*b(1)**2*p1-2*d(1,f(1))*b(3)*b(1)*p1
                  +d(1,f(2))*df(b(1),t)+d(1,f(1))*df(b(3),t)},
     {},{},{});  
clear_session_files()$
write"====================================================="$
write"4. Symmetry computation"$
ssym(1,1,4,{1,1},{1,3,1,3},  
     {df(f(1),t)=>-2*f(1)*b(1)*p1,  
      df(b(1),t)=>b(1)**2*p1+d(1,f(1))*p2,  
      d(1,b(2)) =>-df(b(1),x)*f(1),  
      df(b(2),t)=>-2*d(1,b(1))*f(1)*b(1)*p1+d(1,df(b(1),t))*f(1)
                  -d(1,f(1))**2*p2/2-d(1,f(1))*b(1)**2*p1
                  +d(1,f(1))*df(b(1),t),
      df(f(2),t)=-2*f(2)*b(1)*p1-2*f(1)*b(3)*p1,  
      df(b(3),t)=2*b(1)*b(3)*p1+d(1,f(2))*p2,  
      d(1,b(4)) =>-df(b(3),x)*f(1)-df(b(1),x)*f(2),  
      df(b(4),t)=>-2*d(1,b(3))*f(1)*b(1)*p1-2*d(1,b(1))*f(2)*b(1)*p1
                  -2*d(1,b(1))*f(1)*b(3)*p1+d(1,df(b(3),t))*f(1) 
                  +d(1,df(b(1),t))*f(2)-d(1,f(1))*d(1,f(2))*p2
                  -d(1,f(2))*b(1)**2*p1-2*d(1,f(1))*b(3)*b(1)*p1
                  +d(1,f(2))*df(b(1),t)+d(1,f(1))*df(b(3),t)},
     {},{},{lin});  
clear_session_files()$

write"====================================================="$
write"5. Symmetry computation"$
hom_wei:={{10,{3,3},{2,2}}}$
ssym(1,1,6,{1,1},{1,1},
     {df(f(1),t)=>-2*f(1)*b(1)*p1,
      df(b(1),t)=>b(1)*b(1)*p1+d(1,f(1))*p2,
      df(f(2),t)= - 2*f(2)*b(1)*p1 - 2*f(1)*b(2)*p1,
      df(b(2),t)=2*b(2)*b(1)*p1 + d(1,f(2))*p2},
     {},{},{lin,filter});
clear_session_files()$

let subli$  

df(b(3),t):=2*b(3)*b(1)*p1 + d(1,f(2))*p2$  
df(f(2),t):=- 2*f(2)*b(1)*p1 - 2*f(1)*b(3)*p1$  

b3t:=df(b(3),t)$  
f2t:=df(f(2),t)$  

df(b(3),s):=(1/2*d(1,b(3))*f(1)*b(1)**2*p1*p2 + 4/11*d(1,b(1))*f(2)  
 *b(1)**2*p1*p2 + d(1,b(1))*f(1)*b(3)*b(1)*p1*p2 + 7/22*d(1,f(1))**2 
 *b(3)*p2**2 + 7/11*d(1,f(1))*b(3)*b(1)**2*p1*p2 + 1/4*d(1,f(1))*  
 d(1,b(3))*f(1)*p2**2 + 5/44*d(1,f(1))*d(1,b(1))*f(2)*p2**2 + 1/44*  
 df(b(1),x)*f(2)*f(1)*p2**2 + 1/22*df(f(1),x)*f(2)*b(1)*p2**2  
 + 5/22*df(f(1),x)*f(1)*b(3)*p2**2)/(p1*p2)$  

df(f(2),s):=(1/4*d(1,f(2))*d(1,f(1))*f(1)*p2**2 + 1/2*d(1,f(2))  
 *f(1)*b(1)**2*p1*p2 + 3/44*d(1,f(1))**2*f(2)*p2**2 + 3/22*d(1,f(1)) 
 *f(2)*b(1)**2*p1*p2 + 1/44*df(f(1),x)*f(2)*f(1)*p2**2)/(p1*p2)$  

b3s:=df(b(3),s)$  
f2s:=df(f(2),s)$  

write "ZERO = ",df(b3t,s)-df(b3s,t)$  
write "ZERO = ",df(f2t,s)-df(f2s,t)$  

clearrules subli$ 

write"#####################################################"$
write"Tests related to conservation law computations:"$ 

ssconl(1,4,10,15,{2},{2},
       {df(f(1),t)=df(f(1),x)*b(1)*p9,
        df(b(1),t)=b(1)**3*p3 + d(1,f(1))**2*p2 + df(b(1),x)*b(1)*p9 
                   + df(f(1),x)*f(1)*p4}
      );

write"#####################################################"$
write"Tests related to determining homogeneity weights:"$ 

FindSSWeights(2,2,0,
              {x*df(b(1,1,0),th(1),t)= d(1,d(2,f(2,0,0)))*p5 - 
                                       df(f(1,1,1)*th(1)*th(2),x,2)*p3,
               df(f(2),t)=(df(f(2),x,2)*p3*p5 - df(f(1),x,3)*p3**2)/p5},
              {p3,p5},
              t)$

write"#####################################################"$
write"Tests related to linearizations:"$ 

linearize({df(f(1),t)=df(f(2),x)*b(1)**3*p1 
                      + d(1,f(2))**5*df(f(1),x,2)*p2,
           df(f(2),t)=2*d(1,df(b(1),x))*df(f(2),x,2)*df(f(1),x)*p3 
                      + df(f(1),x,3)*p3**2,
           d(1,d(2,b(1)))=b(1)*d(1,d(2,f(1)))*f(1) },2,1,nil,nil)$

write"#####################################################"$
write"Tests related to generating polynomials:"$ 

GenSSPoly(2,{{{2,3},{2},5}},c,{});

write"#####################################################"$
write"Tests related to Taylor expansions:"$ 

hh := tocoo(2,2,0,
            f(1)*d(1,f(2))+d(2,d(1,DF(f(2),x)))+
            df(f(2),x,2)*p3*p5 - df(f(1),x,3)*p3**2);

write"#####################################################"$
write"Tests related to inverting Taylor expansions:"$ 

tofield(1,1,0,f(1,0)+df(f(1,0),x)+f(1,0)*th(1)*df(f(1,0),x),{});

tofield(1,2,0,f(2,0)*b(1,1) + f(2,0)*th(1)*df(f(1,0),x) + 

        f(1,0) + th(1)*b(2,1)*b(1,1) + th(1)*b(1,1),{}); 

tofield(1,1,0,df(f(1,0),x)+f(1,0)*th(1)*df(f(1,0),x),{});

clear_session_files()$

write"#####################################################"$

showtime;

end;
