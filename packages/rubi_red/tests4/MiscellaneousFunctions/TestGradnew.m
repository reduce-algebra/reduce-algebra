(* File TestGrad includes 2381 integrals  
    V3.5: done: 2264 (95.1 %), generically return: 117 (4.9 %) -date 980104
    V3.0: done: 2215 (93 %), generically return: 166 (7 %)
          Linux 3.0 (April 25, 1997) Linux (June 3, 1998)
      MemoryInUse[]     4983316  4972.13 Sec 5236.29 Sec 


 *)

(*
  2359 (1787 + 436 ellip +123 spec + 13 bug) indefinite integrals of Grad & 
  Ryz book (p.57-285, 626-678) are here. 436 integrals are elliptic integrals
  from the chapter with definite integrals. 123 integrals are indefinite
  integrals from special functions.

  All of these 2359 integrals you can find also in 3 files:
(* 
 Now we have 2359+10 integrals = 175 GENER + 2194 can
*)
 TestGrad (2359) = TestGradMade (942=937+4Bug+1Lost) + TestGradCan2 (1182) +
                   TestGradGen (221+1) + TestGradBug (13 Can = 10 Made+3 Bug?) 

End October: 39,9322 % Made + 50.106 % Can + 9.41077 % Gen + 0.551081 % Bug

2369 = TestGradMade (942) + TestGradCan2 (1236) +
                   TestGradGen (178) + TestGradBug (13) =
     39.7636 % + 52.1739 % + 7.51372 % + 0.548755 %

2369-178 = 2191 = TestGradMade (942) + TestGradCan2 (1236) +
                  TestGradBug (13) = 
                  42.9941 % + 56.4126 % + 0.593336 %



11 November: 942-13+523+10 + 1182-523-145 + 222 + 13-10+13+145
11 November: 1462 + 514 + 222 + 161
              61.9754 % + 21.7889 % + 9.41077 % + 6.82493 %

20 December: 2359 = TestGradMade (942=937+4Bug+1Lost) + TestGradCan2 (1182) +
                   TestGradGen (221+1) + TestGradBug (13 Can = 10 Made+3 Bug?)

20 December:2359 = 221 Gen + (937+1+10+947+9) Made + (211) Can + (4+2+16+1) Bug
               = 221 Gen + 1904 Made + 211 Can + 23 Bug        
             = 9.36838 % Gen + 80.7122 % Made + 8.94447 % Can + 0.974989 % Bug

25 January: 2359 = TestGradMade (942) + TestGradCan2 (1182=1032+148 Ret+
                   2 Num Bug) + TestGradGen (221+1 Made) + TestGradBug(13 Can = 
                   12 Made+1 Ret) =
                   1987 Made + 149 Ret + 221 Gen + 2 Num Bug
               84.2306 % Made + 6.31624 % Ret + 9.36838 % Gen 0.0847817 % Bug

27 January 2358 = TestGradMade (942) + TestGradCan2 (1182=1014+161 Ret+
                   7 Num Bug) + TestGradGen (221+1 Made) + TestGradBug(13 Can = 
                   12 Made+1 Ret) =
                   1969 Made + 162 Ret + 221 Gen + 7 Num Bug
               83.9301 % Made + 6.90537 % Ret + 9.42029 % Gen 0.29838 % Bug

28 January 2359 = 2012 were evaluated correctly                     85.2904 %
                   345 - return = 219 (very general expressions)    14.6248 %
                                   95 (from special functions)      
                                   28 (Alexei's problems)
                                    3 (Oleg's & Alexei's problems)
                     2 - Numerical bugs                              0.0847 %

15 February 2359 =2060 were evaluated correctly                     87.3251 %
                   297 - return = 222 (very general expressions)    12.5901 %
                                   44 (from special functions)      
                                   28 (Alexei's problems)
                                    3 (Oleg's & Alexei's problems)
                     2 - Numerical bugs                              0.0847 %

15 February 2369 =2081 were evaluated correctly                     87.3251 %
                   286 - return = 222 (very general expressions)    12.5901 %
                                   40 (from special functions)      
                                   21 (Alexei's problems)
                                    3 (Oleg's & Alexei's problems)
                     2 - Numerical bugs       

to add 77 integrals: 3.26409 % 

 Limit = 2140 (90.7164 %) = 2180 (92.412 %)
  Now we have 94.0187 % 

179 Generical type

   (2359-95-221)/1987 = 97.2589 % 

20-27 March 2369 =2139 were evaluated correctly                     90.2913 %
                   227 - return = 178 (very general expressions)     7.51372 %
                                   34 (from special functions)      
                                    5 (made need to ad)
                                   10 (Oleg's & Alexei's problems)
                     2 - Numerical bugs 
                     1 - gives message  

10 April 2369 = 2150 were evaluated correctly                     90.7556 %
                 217 - return = 178 (very general expressions)     7.51372 %
                                 34 (from special functions)      
                                  5 (Oleg's & Alexei's problems)
                   2 - Numerical bugs  
 2191 = 2150 + 2 + 32 + (2+5)
2359+10
175 - Gen 
(********************************)
After 11 November: 942-13+523+10+13+145+73 + 1182-523-73-145 + 222 +
                  13-10+13+145-13-145

After 11 November: 1693 + 441 + 222 + 3
              71.7677 % + 18.6944 % + 9.41077 % + 0.127173 % 

After 11 November: 942-13+523+10+13+145+73+69 + 1182-523-73-145-69 + 222 +
                  13-10+13+145-13-145

After 11 November: 1762 + 372 + 222 + 3
              74.6927 % + 15.7694 % + 9.41077 % + 0.127173 % 

942-13+523+10+13+145+73+32+23+8+13+33+25+57+33 +
  1182-523-73-145-224+
   222+3  = 1917+217+222+3

 81.2632 % + 9.19881 % + 9.41077 % + 0.127173 % 

After 11 November: 1693+191 + 441-191 + 222 + 3

TestGradMade contains ONLY integrals that System can evaluate.
TestGradCan2 contains ONLY integrals that System can not evaluate BUT I know 
  how to make evaluation in future.
TestGradGen contains ONLY integrals that System can not evaluate and it is
 inpossible to make the evaluation without special restrictions on parameters.
*)
(*****************************************************************************)
(*                          Rational functions                               *)
(*****************************************************************************)
(*
Test={
(* 2.103 *)
{(x-a)^(-b),x},
{(x-a)^(-1),x},
{(M x+N) (A+2 B x+C x^2)^(-p),x},       (* Gen *)
{(A+2 B x+C x^2)^(-1),x}, 
{(M x+N) (A+2 B x+C x^2)^(-1),x},
(*2.110*)
{x^n (a+b x^k)^m,x},                    (* Ret2.2 *)                                         
(*2.111*)
{(a+b x)^m,x},
{x^n (a+b x)^(-m),x},                   (* Ret2.2 *)                                           
{x^(m-1) (a+b x)^(-m),x},               (* Ret2.2 *)                                                      
{x^n (a+b x)^(-1),x},                   (* Ret2.2 *)                                            
{x^n (a+b x)^(-2),x},                   (* Ret2.2 *)                                    
(*2.112*)
{x (a+b x)^(-1),x}, 
{x^2 (a+b x)^(-1),x}, 
(*2.113*)
{(a+b x)^(-2),x},
{x (a+b x)^(-2),x},
{x^2 (a+b x)^(-2),x},  
(*2.114*)
{(a+b x)^(-3),x},
{x (a+b x)^(-3),x},
{x^2 (a+b x)^(-3),x},  
{x^3 (a+b x)^(-3),x},  
(*2.115*)
{(a+b x)^(-4),x},
{x (a+b x)^(-4),x},
{x^2 (a+b x)^(-4),x},  
{x^3 (a+b x)^(-4),x}, 
(*2.116*)
{(a+b x)^(-5),x},
{x (a+b x)^(-5),x},
{x^2 (a+b x)^(-5),x},  
{x^3 (a+b x)^(-5),x},  
(*2.117*)
{(a+b x)^(-m),x},                                        
{(a+b x)^(-m),x},
{x^(-1) (a+b x)^(-m),x},                (* Ret2.2 *)                                        
{x^(-n) (a+b x)^(-1),x},                (* Ret2.2 *)                                       
(*2.118*)
{x^(-1) (a+b x)^(-1),x},                               
{x^(-2) (a+b x)^(-1),x}, 
{x^(-3) (a+b x)^(-1),x}, 
(*2.119*)
{x^(-1) (a+b x)^(-2),x},    
{x^(-2) (a+b x)^(-2),x}, 
{x^(-3) (a+b x)^(-2),x}, 
(*2.121*)
{x^(-1) (a+b x)^(-3),x},    
{x^(-2) (a+b x)^(-3),x}, 
{x^(-3) (a+b x)^(-3),x}, 
(*2.122*)
{x^(-1) (a+b x)^(-4),x},    
{x^(-2) (a+b x)^(-4),x}, 
{x^(-3) (a+b x)^(-4),x}, 
(*2.123*)
{x^(-1) (a+b x)^(-5),x},    
{x^(-2) (a+b x)^(-5),x}, 
{x^(-3) (a+b x)^(-5),x},
(*2.124*)
{(a+b x^2)^(-1),x},  
{x (a+b x^2)^(-m),x},    
(*2.125*)
{x (a+b x^3)^(-m),x},                   (* Ret2.2 *)                                      
{x^n (a+b x^3)^(-m),x},                 (* Ret2.2 *)                                    
(*2.126*)
{(a+b x^3)^(-1),x},  
{x (a+b x^3)^(-1),x},
{x^2 (a+b x^3)^(-1),x},
{x^3 (a+b x^3)^(-1),x},    
{x^4 (a+b x^3)^(-1),x},  
(*2.127*)
{(a+b x^3)^(-2),x},  
{x (a+b x^3)^(-2),x},
{x^2 (a+b x^3)^(-2),x},
{x^3 (a+b x^3)^(-2),x},    
(*2.128*)
{x^(-n) (a+b x^3)^(-m),x},              (* Ret2.2 *)                                    
(*2.129*)
{x^(-1) (a+b x^3)^(-1),x},
{x^(-2) (a+b x^3)^(-1),x},
{x^(-3) (a+b x^3)^(-1),x},
(*2.131*)
{x^(-1) (a+b x^3)^(-2),x},
{x^(-2) (a+b x^3)^(-2),x},
{x^(-3) (a+b x^3)^(-2),x},
(*2.132*)
{(a+b x^4)^(-1),x},
{x (a+b x^4)^(-1),x},
{x^2 (a+b x^4)^(-1),x},
{x^3 (a+b x^4)^(-1),x},
(*2.133*)
{x^n (a+b x^4)^(-m),x},                 (* Ret2.2 *)                                   
(*2.134*)
{(a+b x^4)^(-2),x},
{x (a+b x^4)^(-2),x},
{x^2 (a+b x^4)^(-2),x},
{x^3 (a+b x^4)^(-2),x},
(*2.135*)
{x^(-n) (a+b x^4)^(-m),x},              (* Ret2.2 *)                                     
{x^(-1) (a+b x^4)^(-m),x},              (* Ret2.2 *)                                 
(*2.136*)
{x^(-1) (a+b x^4)^(-1),x},
{x^(-2) (a+b x^4)^(-1),x},
(*2.141*)
{(1+x)^(-1),x},
{(1+x^2)^(-1),x},
{(1+x^3)^(-1),x},
{(1+x^4)^(-1),x},                                               
(*2.142*)
{(1+x^n)^(-1),x},                       (* Ret2.2 *)                                        
(*2.143*)
{(1-x)^(-1),x},
{(1-x^2)^(-1),x},
{(1-x^3)^(-1),x},
{(1-x^4)^(-1),x},
(*2.144*)
{(1-x^n)^(-1),x},                       (* Ret2.2 *)                                               
(*2.145*)
{x (1+x)^(-1),x},
{x (1+x^2)^(-1),x},
{x (1+x^3)^(-1),x},
{x (1+x^4)^(-1),x},
{x (1-x)^(-1),x},
{x (1-x^2)^(-1),x},
{x (1-x^3)^(-1),x},
{x (1-x^4)^(-1),x},
(*2.146*)
{x^(m-1) (1+x^(2 n))^(-1),x},           (* Ret2.2 *)                               
{x^(m-1) (1+x^(2 n+1))^(-1),x},         (* Rec or Memory Fault 2.2 *)                              
{x^(m-1) (1-x^(2 n))^(-1),x},           (* Ret2.2 *)               
{x^(m-1) (1-x^(2 n+1))^(-1),x},         (* Rec or Memory Fault 2.2 *)                              
(*2.147*)
{x^m (1-x^(2 n))^(-1),x},               (* Ret2.2 *)                                    
{x^m (1+x^2)^(-n),x},                   (* Ret2.2 *)                                        
{x^m (1+x^2)^(-1),x},                   (* Ret2.2 *)                                         
{x^m (1-x^2)^(-n),x},                   (* Ret2.2 *)                                          
{x^m (1-x^2)^(-1),x},                   (* Ret2.2 *)                                         
(*2.148*)
{x^(-m) (1+x^2)^(-n),x},                (* Ret2.2 *)                                     
{x^(-1) (1+x^2)^(-n),x},                (* Ret2.2 *)                                     
{x^(-1) (1+x^2)^(-1),x},
{x^(-m) (1+x^2)^(-1),x},                (* Ret2.2 *)                                     
{(1+x^2)^(-n),x},                       (* Ret2.2 *)                                        
(*2.149*)
{x^(-m) (1-x^2)^(-n),x},                (* Ret2.2 *)                                  
{x^(-1) (1-x^2)^(-n),x},                (* Ret2.2 *)                                     
{x^(-1) (1-x^2)^(-1),x},
{(1-x^2)^(-n),x},                       (* Ret2.2 *)                                    
(*2.151*)
{(a+b x)^n (c+d x)^m,x},                (* Ret2.2 *)
(*2.152*)                              
{(a+b x) (c+d x)^(-1),x},
(*2.153*)
{(a+b x)^(-n) (c+d x)^m,x},             (* Ret2.2 *)                                    
(*2.154*)
{(a+b x)^(-1) (c+d x)^(-1),x},                            
(*2.155*)
{(a+b x)^(-n) (c+d x)^(-m),x},          (* Ret2.2 *)                                    
(*2.156*)
{x (a+b x)^(-1) (c+d x)^(-1),x},                          
(*2.160*)
{x^(m-1) (a+b x^k+c x^(2 k))^n,x},      (* GEN *)
(*2.161*)
{(a+b x^2+c x^4)^(-1),x},               (* Ret2.2 *)                                      
{x (a+b x^2+c x^4)^(-1),x},             (* Ret2.2 *)                                      
{x^2 (a+b x^2+c x^4)^(-1),x},           (* Ret2.2 *)                                     
{(a+b x^2+c x^4)^(-2),x},               (* Ret2.2 *)                  
{(a+b x^2+c x^4)^(-n),x},              (* GEN *)  
{x^(-m) (a+b x^2+c x^4)^(-n),x},       (* GEN *)  
(*2.171*)
{x^(m+1) (a+b x+c x^2)^n,x},           (* GEN *) 
{(a+b x+c x^2)^(-n-1),x},               (* Ret2.2 *)                                   
(*2.172*)
{(a+b x+c x^2)^(-1),x},
(*2.173*)
{(a+b x+c x^2)^(-2),x},
{(a+b x+c x^2)^(-3),x},
(*2.174*)
{x^m (a+b x+c x^2)^(-n),x},       (* GEN *)
{x^(2n-1) (a+b x+c x^2)^(-n),x},  (* GEN *) 
(*2.175*)
{x (a+b x+c x^2)^(-1),x},
{x (a+b x+c x^2)^(-2),x},
{x (a+b x+c x^2)^(-3),x},
{x^2 (a+b x+c x^2)^(-1),x},
{x^2 (a+b x+c x^2)^(-2),x},
{x^2 (a+b x+c x^2)^(-3),x},
{x^3 (a+b x+c x^2)^(-1),x},
{x^3 (a+b x+c x^2)^(-2),x},
{x^3 (a+b x+c x^2)^(-3),x},
(*2.176*)
{x^(-m) (a+b x+c x^2)^(-n),x},    (* GEN *) 
(*2.177*)
{x^(-1) (a+b x+c x^2)^(-1),x},
{x^(-1) (a+b x+c x^2)^(-2),x},
{x^(-1) (a+b x+c x^2)^(-3),x},
{x^(-2) (a+b x+c x^2)^(-1),x},
{x^(-2) (a+b x+c x^2)^(-2),x},
{x^(-2) (a+b x+c x^2)^(-3),x},
{x^(-3) (a+b x+c x^2)^(-1),x},
{x^(-3) (a+b x+c x^2)^(-2),x},
{x^(-3) (a+b x+c x^2)^(-3),x},
(*2.18*)
{(d+e x)^m (a+b x+c x^2)^n,x},       (* GEN *)  
{(d+e x)^(-m) (a+b x+c x^2)^n,x},    (* GEN *) 
{(d+e x)^m (a+b x+c x^2)^(-n),x},    (* GEN *)  
{(d+e x)^(-m) (a+b x+c x^2)^(-n),x}, (* GEN *) 
{(d+e x)^(-1) (a+b x+c x^2)^(-1),x},                           
(*****************************************************************************)
(*                         Algebraic functions                               *)
(*****************************************************************************)
(*2.211*)
{x^(-1/2) (a+b x)^(-1),x},
(*2.212*)
{x^(m+1/2) (a+b x)^(-1),x},             (* Ret2.2 *)                                    
(*2.213*)
{x^(1/2) (a+b x)^(-1),x},
{x^(3/2) (a+b x)^(-1),x},
{x^(5/2) (a+b x)^(-1),x},
{x^(-1/2) (a+b x)^(-2),x},
{x^(1/2) (a+b x)^(-2),x},
{x^(3/2) (a+b x)^(-2),x},
{x^(5/2) (a+b x)^(-2),x},
{x^(-1/2) (a+b x)^(-3),x},
{x^(1/2) (a+b x)^(-3),x},
{x^(3/2) (a+b x)^(-3),x},
{x^(5/2) (a+b x)^(-3),x},
(*2.214*)
{x^(-1/2) (a+b x^2)^(-1),x},
(*2.215*)
{x^(1/2) (a+b x^2)^(-1),x},
(*2.216*)
{x^(3/2) (a+b x^2)^(-1),x},
{x^(5/2) (a+b x^2)^(-1),x},
{x^(-1/2) (a+b x^2)^(-2),x},
{x^(1/2) (a+b x^2)^(-2),x},
{x^(3/2) (a+b x^2)^(-2),x},
{x^(5/2) (a+b x^2)^(-2),x},
{x^(-1/2) (a+b x^2)^(-3),x},
{x^(1/2) (a+b x^2)^(-3),x},
{x^(3/2) (a+b x^2)^(-3),x},
{x^(5/2) (a+b x^2)^(-3),x},
(*2.220*)
{x^n (a+b x)^r,x},                      (* Ret2.2 *)                                                           
(*2.222*)
{(a+b x)^(-1/2),x},
{x (a+b x)^(-1/2),x},
{x^2 (a+b x)^(-1/2),x},
(*2.223*)
{(a+b x)^(-3/2),x},
{x (a+b x)^(-3/2),x},
{x^2 (a+b x)^(-3/2),x},
{((a+b x)^3)^(-1/2),x},
{x ((a+b x)^3)^(-1/2),x},
{x^2 ((a+b x)^3)^(-1/2),x},
(*2.224*)
{x^(-n) (a+b x)^(m-1/2),x},             (* Ret2.2 *)                                     
{x^(-1) (a+b x)^(m-1/2),x},             (* Ret2.2 *)                                       
{x^(-1) (a+b x)^(-1/2),x},
(*2.225*)
{x^(-1) (a+b x)^(1/2),x},
{x^(-2) (a+b x)^(1/2),x},
{x^(-3) (a+b x)^(1/2),x},
(*2.226*)
{x^(-1) (a+b x)^(3/2),x},
{x^(-2) (a+b x)^(3/2),x},
{x^(-3) (a+b x)^(3/2),x},
{x^(-1) ((a+b x)^3)^(1/2),x},
{x^(-2) ((a+b x)^3)^(1/2),x},
{x^(-3) ((a+b x)^3)^(1/2),x},
(*2.227*)
{x^(-1) (a+b x)^(-m-1/2),x},            (* Ret2.2 *)                                        
(*2.228*)
{x^(-2) (a+b x)^(-1/2),x},
{x^(-3) (a+b x)^(-1/2),x},
(*2.229*)
{x^(-1) (a+b x)^(-3/2),x},
{x^(-2) (a+b x)^(-3/2),x},
{x^(-3) (a+b x)^(-3/2),x},
{x^(-1) ((a+b x)^3)^(-1/2),x},
{x^(-2) ((a+b x)^3)^(-1/2),x},
{x^(-3) ((a+b x)^3)^(-1/2),x},
(*2.231*)
{x^n (a+b x)^r,x},                      (* Ret2.2 *)                                            
{x^(-m) (a+b x)^(n-2/3),x},             (* Ret2.2 *)                                                
{x^(-1) (a+b x)^(n-2/3),x},             (* Ret2.2 *)
{x^n ((a+b x)^(3m+1))^(1/3),x},                                                                
{x^n ((a+b x)^(3m+2))^(-1/3),x},          
{x^n ((a+b x)^(3m+2))^(1/3),x},       
{x^n ((a+b x)^(3m+1))^(-1/3),x},  
{x^(-m) ((a+b x)^2)^(-1/3) (a+b x)^n,x},
{x^(-1) ((a+b x)^2)^(-1/3) (a+b x)^n,x},
{x^(-1) ((a+b x)^2)^(-1/3) (a+b x)^(-n),x},
{x^(-1) (x^2)^(-1/3) (a+b x)^n,x},        
{x^(-m) (a+b x)^(n-2/3),x},             (* Ret2.2 *)                                                
{x^(-1) (a+b x)^(n-2/3),x},             (* Ret2.2 *)            
(*2.232*)
{x^(-1) (a+b x)^(-2/3),x},              (* Ret2.2 *)                                          
{x^(-1) ((a+b x)^2)^(-1/3),x},          (* Ret2.2 *)                                                  
(*2.233*)
{x^(-1) (a+b x)^(1/3),x},               (* Ret2.2 *)                                            
{x^(-2) (a+b x)^(1/3),x},               (* Ret2.2 *)                                    
{x^(-3) (a+b x)^(1/3),x},               (* Ret2.2 *)                                       
{x^(-2) (a+b x)^(-2/3),x},              (* Ret2.2 *)                                      
{x^(-3) (a+b x)^(-2/3),x},              (* Ret2.2 *)                                        
{x^(-2) ((a+b x)^2)^(-1/3),x},          (* Ret2.2 *)                                                                
{x^(-3) ((a+b x)^2)^(-1/3),x},          (* Ret2.2 *)                                                                   
(*2.234*)
{x^(-m) (a+b x)^(n-1/3),x},             (* Ret2.2 *)                                     
{x^(-1) (a+b x)^(n-1/3),x},             (* Ret2.2 *)                                   
{x^(-1) (a+b x)^(-n-1/3),x},            (* Ret2.2 *)                            
(*2.235*)
{x^(-1) (a+b x)^(-1/3),x},              (* Ret2.2 *)                                 
(*2.236*)
{x^(-1) (a+b x)^(2/3),x},               (* Ret2.2 *)                                     
{x^(-2) (a+b x)^(2/3),x},               (* Ret2.2 *)                                        
{x^(-3) (a+b x)^(2/3),x},               (* Ret2.2 *)                                     
{x^(-2) (a+b x)^(-1/3),x},              (* Ret2.2 *)                                       
{x^(-3) (a+b x)^(-1/3),x},              (* Ret2.2 *)                             
{x^(-1) ((a+b x)^2)^(1/3),x},           (* Ret2.2 *)                                                               
{x^(-2) ((a+b x)^2)^(1/3),x},           (* Ret2.2 *)                                                              
{x^(-3) ((a+b x)^2)^(1/3),x},           (* Ret2.2 *)                                                         
(*2.241*)
{(c+d x)^n (a+b x)^(m-1/2),x},          (* Ret2.2 *)                               
(*2.242*)
{(c+d x) (a+b x)^(-1/2),x},
{(c+d x)^2 (a+b x)^(-1/2),x},
{(c+d x)^3 (a+b x)^(-1/2),x},
{(c+d x) (a+b x)^(1/2),x},
{(c+d x)^2 (a+b x)^(1/2),x},
{(c+d x)^3 (a+b x)^(1/2),x},
{(c+d x) (a+b x)^(3/2),x},
{(c+d x)^2 (a+b x)^(3/2),x},
{(c+d x)^3 (a+b x)^(3/2),x},
{(c+d x) (a+b x)^(5/2),x},
{(c+d x)^2 (a+b x)^(5/2),x},
{(c+d x)^3 (a+b x)^(5/2),x},
(*2.243*)
{(c+d x)^n (a+b x)^(-m-1/2),x},         (* Ret2.2 *)                           
(*2.244*)
{(c+d x) (a+b x)^(-3/2),x},
{(c+d x)^2 (a+b x)^(-3/2),x},
{(c+d x)^3 (a+b x)^(-3/2),x},
{(c+d x) (a+b x)^(-5/2),x},
{(c+d x)^2 (a+b x)^(-5/2),x},
{(c+d x)^3 (a+b x)^(-5/2),x},
{(c+d x) (a+b x)^(-7/2),x},
{(c+d x)^2 (a+b x)^(-7/2),x},
{(c+d x)^3 (a+b x)^(-7/2),x},
(*2.245*)
{(c+d x)^(-n) (a+b x)^(m-1/2),x},       (* Ret2.2 *)                            
{(c+d x)^(-1) (a+b x)^(m-1/2),x},       (* Ret2.2 *)                          
(*2.246*)
{(c+d x)^(-1) (a+b x)^(-1/2),x},
(*2.247*)
{(c+d x)^(-1) (a+b x)^(-m-1/2),x},      (* Ret2.2 *)                        
(*2.248*)
{(c+d x)^(-1) (a+b x)^(-3/2),x},
{(c+d x)^(-1) (a+b x)^(-5/2),x},
{(c+d x)^(-1) (a+b x)^(-7/2),x},
{(c+d x)^(-2) (a+b x)^(-1/2),x},
{(c+d x)^(-2) (a+b x)^(-3/2),x},
{(c+d x)^(-2) (a+b x)^(-5/2),x},
{(c+d x)^(-2) (a+b x)^(-7/2),x},
{(c+d x)^(-3) (a+b x)^(-1/2),x},
{(c+d x)^(-3) (a+b x)^(-3/2),x},
{(c+d x)^(-3) (a+b x)^(-5/2),x},
{(c+d x)^(-3) (a+b x)^(-7/2),x},
{(c+d x)^(-1) (a+b x)^(1/2),x},
{(c+d x)^(-1) (a+b x)^(3/2),x},
{(c+d x)^(-1) (a+b x)^(5/2),x},
{(c+d x)^(-2) (a+b x)^(1/2),x},
{(c+d x)^(-2) (a+b x)^(3/2),x},
{(c+d x)^(-2) (a+b x)^(5/2),x},
{(c+d x)^(-3) (a+b x)^(1/2),x},
{(c+d x)^(-3) (a+b x)^(3/2),x},
{(c+d x)^(-3) (a+b x)^(5/2),x},
(*2.249*)
{(c+d x)^(-n) (a+b x)^(-m-1/2),x},      (* Ret2.2 *)                                   
{(c+d x)^(-1) (a+b x)^(-m-1/2),x},      (* Ret2.2 *)             
(*2.260*)
{x^m (a+b x+c x^2)^(n+1/2),x},       (* GEN *) 
{(a+b x+c x^2)^(n+1/2),x},              (* Ret2.2 *)                                            
(*2.261*)
{(a+b x+c x^2)^(-1/2),x},
(*2.262*)
{(a+b x+c x^2)^(1/2),x},
{x (a+b x+c x^2)^(1/2),x},
{x^2 (a+b x+c x^2)^(1/2),x},
{x^3 (a+b x+c x^2)^(1/2),x},
{(a+b x+c x^2)^(3/2),x},
{x (a+b x+c x^2)^(3/2),x},
{x^2 (a+b x+c x^2)^(3/2),x},
{x^3 (a+b x+c x^2)^(3/2),x},
{((a+b x+c x^2)^3)^(1/2),x},
{x ((a+b x+c x^2)^3)^(1/2),x},
{x^2 ((a+b x+c x^2)^3)^(1/2),x},
{x^3 ((a+b x+c x^2)^3)^(1/2),x},
(*2.263*)
{x^m (a+b x+c x^2)^(-n-1/2),x},   (* GEN *)  
{x^(2n) (a+b x+c x^2)^(-n-1/2),x},(* GEN *) 
{(a+b x+c x^2)^(-n-1/2),x},             (* Ret2.2 *)                                     
(*2.264*)
{(a+b x+c x^2)^(-1/2),x},
{x (a+b x+c x^2)^(-1/2),x},
{x^2 (a+b x+c x^2)^(-1/2),x},
{x^3 (a+b x+c x^2)^(-1/2),x},
{(a+b x+c x^2)^(-3/2),x},
{x (a+b x+c x^2)^(-3/2),x},
{x^2 (a+b x+c x^2)^(-3/2),x},
{x^3 (a+b x+c x^2)^(-3/2),x},
{((a+b x+c x^2)^3)^(-1/2),x},
{x ((a+b x+c x^2)^3)^(-1/2),x},
{x^2 ((a+b x+c x^2)^3)^(-1/2),x},
{x^3 ((a+b x+c x^2)^3)^(-1/2),x},
(*2.265*)
{x^(-m) (a+b x+c x^2)^(n+1/2),x},       (* GEN *) 
{x^(-1) (a+b x+c x^2)^(n+1/2),x},       (* GEN *) 
{x^(-m) (b x+c x^2)^(n+1/2),x},         (* Ret2.2 *)                                 
(*2.266*)
{x^(-1) (a+b x+c x^2)^(-1/2),x},
(*2.267*)
{x^(-1) (a+b x+c x^2)^(1/2),x},
{x^(-2) (a+b x+c x^2)^(1/2),x},
{x^(-2) (b x+c x^2)^(1/2),x},                  
{x^(-3) (a+b x+c x^2)^(1/2),x},                 
{x^(-3) (b x+c x^2)^(1/2),x},                   
{x^(-1) (a+b x+c x^2)^(3/2),x},
{x^(-2) (a+b x+c x^2)^(3/2),x},
{x^(-2) (b x+c x^2)^(3/2),x},                   
{x^(-3) (a+b x+c x^2)^(3/2),x},
{x^(-3) (b x+c x^2)^(3/2),x},                   
{x^(-1) ((a+b x+c x^2)^3)^(1/2),x},
{x^(-2) ((a+b x+c x^2)^3)^(1/2),x},
{x^(-2) ((b x+c x^2)^3)^(1/2),x},
{x^(-3) ((a+b x+c x^2)^3)^(1/2),x},
{x^(-3) ((b x+c x^2)^3)^(1/2),x},
(*2.268*)
{x^(-m) (a+b x+c x^2)^(-n-1/2),x},(* GEN *) 
{x^(-1) (a+b x+c x^2)^(-n-1/2),x},(* GEN *)

{x^(-m) (b x+c x^2)^(-n-1/2),x},        (* Ret2.2 *)             
(*2.269*)
{x^(-1) (a+b x+c x^2)^(-1/2),x},
{x^(-2) (a+b x+c x^2)^(-1/2),x},
{x^(-2) (b x+c x^2)^(-1/2),x},                 
{x^(-3) (a+b x+c x^2)^(-1/2),x},
{x^(-3) (b x+c x^2)^(-1/2),x},                
{x^(-1) (a+b x+c x^2)^(-3/2),x},
{x^(-1) (b x+c x^2)^(-3/2),x},                 
{x^(-2) (a+b x+c x^2)^(-3/2),x},
{x^(-2) (b x+c x^2)^(-3/2),x},                 
{x^(-3) (a+b x+c x^2)^(-3/2),x},
{x^(-3) (b x+c x^2)^(-3/2),x},                
{x^(-1) ((a+b x+c x^2)^3)^(-1/2),x},
{x^(-1) ((b x+c x^2)^3)^(-1/2),x},
{x^(-2) ((a+b x+c x^2)^3)^(-1/2),x},
{x^(-2) ((b x+c x^2)^3)^(-1/2),x},
{x^(-3) ((a+b x+c x^2)^3)^(-1/2),x},
{x^(-3) ((b x+c x^2)^3)^(-1/2),x},
(*2.271*)
{(a+c x^2)^(5/2),x},
{(a+c x^2)^(3/2),x},
{(a+c x^2)^(1/2),x},
{(a+c x^2)^(-1/2),x},
{(a+c x^2)^(-3/2),x},
{(a+c x^2)^(-n-1/2),x},                 (* Ret2.2 *)                                    
{x (a+c x^2)^(-n-1/2),x},                           
(*2.272*)
{x^2 (a+c x^2)^(3/2),x},
{x^2 (a+c x^2)^(1/2),x},
{x^2 (a+c x^2)^(-1/2),x},
{x^2 (a+c x^2)^(-3/2),x},
{x^2 (a+c x^2)^(-5/2),x},
{x^2 (a+c x^2)^(-n-1/2),x},             (* Ret2.2 *)                                   
{x^3 (a+c x^2)^(-n-1/2),x},
(*2.273*)
{x^4 (a+c x^2)^(3/2),x},
{x^4 (a+c x^2)^(1/2),x},
{x^4 (a+c x^2)^(-1/2),x},
{x^4 (a+c x^2)^(-3/2),x},
{x^4 (a+c x^2)^(-5/2),x},
{x^4 (a+c x^2)^(-7/2),x},
{x^4 (a+c x^2)^(-n-1/2),x},             (* Ret2.2 *)                                           
{x^5 (a+c x^2)^(-n-1/2),x},
(*2.274*)
{x^6 (a+c x^2)^(3/2),x},
{x^6 (a+c x^2)^(1/2),x},
{x^6 (a+c x^2)^(-1/2),x},
{x^6 (a+c x^2)^(-3/2),x},
{x^6 (a+c x^2)^(-5/2),x},
{x^6 (a+c x^2)^(-7/2),x},
{x^6 (a+c x^2)^(-9/2),x},
{x^6 (a+c x^2)^(-n-1/2),x},             (* Ret2.2 *)                  
{x^7 (a+c x^2)^(-n-1/2),x},
(*2.275*)
{x^(-1) (a+c x^2)^(5/2),x},
{x^(-1) (a+c x^2)^(3/2),x},
{x^(-1) (a+c x^2)^(1/2),x},
{x^(-1) (a+c x^2)^(-1/2),x},
{x^(-1) (a+c x^2)^(-n-1/2),x},          (* Ret2.2 *)                                       
{x^(-2) (a+c x^2)^(5/2),x},                 
{x^(-2) (a+c x^2)^(3/2),x},
{x^(-2) (a+c x^2)^(1/2),x},
{x^(-2) (a+c x^2)^(-n-1/2),x},          (* Ret2.2 *)                            
(*2.276*)
{x^(-3) (a+c x^2)^(5/2),x},
{x^(-3) (a+c x^2)^(3/2),x},
{x^(-3) (a+c x^2)^(1/2),x},
{x^(-3) (a+c x^2)^(-1/2),x},
{x^(-3) (a+c x^2)^(-3/2),x},
{x^(-3) (a+c x^2)^(-5/2),x},
{x^(-4) (a+c x^2)^(5/2),x},
{x^(-4) (a+c x^2)^(3/2),x},
{x^(-4) (a+c x^2)^(1/2),x},
{x^(-4) (a+c x^2)^(-n-1/2),x},          (* Ret2.2 *)                                      
(*2.277*)
{x^(-5) (a+c x^2)^(3/2),x},
{x^(-5) (a+c x^2)^(1/2),x},
{x^(-5) (a+c x^2)^(-1/2),x},
{x^(-5) (a+c x^2)^(-3/2),x},
(*2.278*)
{x^(-6) (a+c x^2)^(3/2),x},
{x^(-6) (a+c x^2)^(1/2),x},
{x^(-6) (a+c x^2)^(-1/2),x},
{x^(-6) (a+c x^2)^(-n-1/2),x},          (* Ret2.2 *)                               
(*2.281*)
{(x+p)^(-n) (a+b x+c x^2)^(-1/2),x},  (* GEN *)
(*2.282*)
{(x+p)^(-1) (a+b x+c x^2)^(1/2),x},
{(x+p)^(-1) (x+q)^(-1) (a+b x+c x^2)^(-1/2),x},
{(x+p)^(-1) (x+q)^(-1) (a+b x+c x^2)^(1/2),x},
{(x+p)(x+q)^(-1) (a+b x+c x^2)^(1/2),x},
{(r x+s) (x+p)^(-1) (x+q)^(-1) (a+b x+c x^2)^(-1/2),x},
(*2.283*)
 {(A x+B) (p+a+b x+c x^2)^(-n) (a+b x+c x^2)^(-1/2),x}, 
                                   (* ********* Return GENERICALLY ********* *) (*2.284*)
{(A x+B) (p+a+b x+c x^2)^(-1) (a+b x+c x^2)^(-1/2),x},  
(*2.291*)      
{(1-x^6)^(-1/2),x},                                                     
{(a+b x^2+c x^4+d x^6)^(-1/2),x},       (* Ret2.2 *)                      
{(a+2 b x+c x^2+d x^3)^(1/3),x},  (* GEN *)                
{(a+2 b x+c x^2+d x^3)^(-1/3),x}, (* GEN *) 
{(a+b x+c x^2+d x^3+c x^4+b x^5+a x^6)^(-1/2),x},  (* Ret2.2 *) (* FS hangs *)                               
{(a+b x^2+c x^4+b x^6+a x^8)^(-1/2),x}, (* Ret2.2 *)     (* FS hangs *)                            
{(a+b x^4+c x^8)^(-1/2),x},             (* Ret2.2 *)     (* FS hangs? *)                               
{x (a+b x^2+c x^4)^(-1/4),x},           (* Ret2.2 *)   (* FS hangs? *)                                                                   
{(a+2 b x^2+c x^4)^(-1/4),x},           (* Ret2.2 *)   (* FS hangs? *)                                                                     
(*****************************************************************************)
(*                       Exponential function                                *)
(*****************************************************************************)

(*2.311*)
{Exp[a x],x},
(*2.313*)
{1/(a+b Exp[m x]),x},                                           
{1/(1+Exp[x]),x},
(*2.314*)
{1/(a Exp[m x]+b Exp[-m x]),x},
(*2.315*)
{(a+b Exp[m x])^(-1/2),x},
(*2.321*)
{x^m Exp[a x],x},                       (* Ret2.2 *)                                              
(*2.322*)
{x Exp[a x],x},
{x^2 Exp[a x],x},
{x^3 Exp[a x],x},
(*2.324*)
{x^(-m) Exp[a x],x},                    (* Ret2.2 *)                                                 
(*2.325*)
{x^(-1) Exp[a x],x},
{x^(-2) Exp[a x],x},
{x^(-3) Exp[a x],x},
(*2.326*)
{x Exp[a x]/(1+a x)^2,x},

(*****************************************************************************)
(*                       Hyperbolic functions                                *)
(*****************************************************************************)
(*2.411*)
{Sinh[x]^p Cosh[x]^q,x},                (* Ret2.2 *)                                      
(*2.412*)
{Sinh[x]^p Cosh[x]^(2n),x},             (* Ret2.2 *)                                     
{Sinh[x]^(2m),x},                       (* Ret2.2 *)                                       
{Sinh[x]^(2m+1),x},                     (* Ret2.2 *)                                     
{Sinh[x]^p Cosh[x]^(2n+1),x},           (* Ret2.2 *)                                   
(*2.413*)
{Cosh[x]^p Sinh[x]^(2n),x},             (* Ret2.2 *)                                   
{Cosh[x]^(2m),x},                       (* Ret2.2 *)                                        
{Cosh[x]^(2m+1),x},                     (* Ret2.2 *)                                      
{Cosh[x]^p Sinh[x]^(2n+1),x},           (* Ret2.2 *)                              
(*2.414*)
{Sinh[a x],x},
{Sinh[a x]^2,x},
{Sinh[x]^3,x},
{Sinh[x]^4,x},
{Sinh[x]^5,x},
{Sinh[x]^6,x},
{Sinh[x]^7,x},
{Cosh[a x],x},
{Cosh[a x]^2,x},
{Cosh[x]^3,x},
{Cosh[x]^4,x},
{Cosh[x]^5,x},
{Cosh[x]^6,x},
{Cosh[x]^7,x},
(*2.415*)
{Sinh[a x] Cosh[b x],x},
{Sinh[a x] Cosh[a x],x},
{Sinh[x]^2 Cosh[x],x},
{Sinh[x]^3 Cosh[x],x},
{Sinh[x]^4 Cosh[x],x},
{Sinh[x] Cosh[x]^2,x},
{Sinh[x]^2 Cosh[x]^2,x},
{Sinh[x]^3 Cosh[x]^2,x},
{Sinh[x]^4 Cosh[x]^2,x},
{Sinh[x] Cosh[x]^3,x},
{Sinh[x]^2 Cosh[x]^3,x},
{Sinh[x]^3 Cosh[x]^3,x},
{Sinh[x]^4 Cosh[x]^3,x},
{Sinh[x] Cosh[x]^4,x},
{Sinh[x]^2 Cosh[x]^4,x},
{Sinh[x]^3 Cosh[x]^4,x},
{Sinh[x]^4 Cosh[x]^4,x},
(*2.416*)
{Sinh[x]^p Cosh[x]^(-2 n),x},           (* Ret2.2 *)                                
{Sinh[x]^(-2 m),x},                     (* Ret2.2 *)                                                       
{Sinh[x]^(-2 m-1),x},                   (* Ret2.2 *)                                                  
(*2.417*)
{Sinh[x]^p Cosh[x]^(-2 n-1),x},         (* Ret2.2 *)                                          
{Sinh[x]^(2m+1) Cosh[x]^(-1),x},        (* Ret2.2 *)                                       
{Sinh[x]^(2m) Cosh[x]^(-1),x},          (* Ret2.2 *)                                        
{Sinh[x]^(-2m-1) Cosh[x]^(-1),x},       (* Ret2.2 *)                                   
{Sinh[x]^(-2m) Cosh[x]^(-1),x},         (* Ret2.2 *)                                       
(*2.418*)
{Sinh[x]^(-2 n) Cosh[x]^p,x},           (* Ret2.2 *)                                    
{Cosh[x]^(-2m),x},                      (* Ret2.2 *)                                          
{Cosh[x]^(-2m-1),x},                    (* Ret2.2 *)                                        
(*2.419*)
{Sinh[x]^(-2 n-1) Cosh[x]^p,x},         (* Ret2.2 *)                                        
{Sinh[x]^(-1) Cosh[x]^(2m),x},          (* Ret2.2 *)                                         
{Sinh[x]^(-1) Cosh[x]^(2m+1),x},        (* Ret2.2 *)                                     
{Sinh[x]^(-1) Cosh[x]^(-2m),x},         (* Ret2.2 *)                                     
{Sinh[x]^(-1) Cosh[x]^(-2m-1),x},       (* Ret2.2 *)                                       
(*2.421*)
{Sinh[x]^(2 n+1) Cosh[x]^(-m),x},       (* Ret2.2 *)                                     
{Sinh[x]^(-m) Cosh[x]^(2 n+1),x},       (* Ret2.2 *)                                     
(*2.422*)
{Sinh[x]^(-2 m) Cosh[x]^(-2n),x},       (* Ret2.2 *)                                 
{Sinh[x]^(-2 m-1) Cosh[x]^(-2n-1),x},   (* Ret2.2 *)                               
(*2.423*)
{Sinh[x]^(-1),x},
{Sinh[x]^(-2),x},
{Sinh[x]^(-3),x},
{Sinh[x]^(-4),x},
{Sinh[x]^(-5),x},
{Sinh[x]^(-6),x},
{Sinh[x]^(-7),x},
{Sinh[x]^(-8),x},
{Cosh[x]^(-1),x},
{Cosh[x]^(-2),x},
{Cosh[x]^(-3),x},
{Cosh[x]^(-4),x},
{Cosh[x]^(-5),x},
{Cosh[x]^(-6),x},
{Cosh[x]^(-7),x},
{Cosh[x]^(-8),x},
{Sinh[x] Cosh[x]^(-1),x},
{Sinh[x]^2 Cosh[x]^(-1),x},
{Sinh[x]^3 Cosh[x]^(-1),x},
{Sinh[x]^4 Cosh[x]^(-1),x},
{Sinh[x] Cosh[x]^(-2),x},
{Sinh[x]^2 Cosh[x]^(-2),x},
{Sinh[x]^3 Cosh[x]^(-2),x},
{Sinh[x]^4 Cosh[x]^(-2),x},
{Sinh[x] Cosh[x]^(-3),x},
{Sinh[x]^2 Cosh[x]^(-3),x},
{Sinh[x]^3 Cosh[x]^(-3),x},
{Sinh[x]^4 Cosh[x]^(-3),x},
{Sinh[x] Cosh[x]^(-4),x},
{Sinh[x]^2 Cosh[x]^(-4),x},
{Sinh[x]^3 Cosh[x]^(-4),x},
{Sinh[x]^4 Cosh[x]^(-4),x},
{Cosh[x] Sinh[x]^(-1),x},
{Cosh[x]^2 Sinh[x]^(-1),x},
{Cosh[x]^3 Sinh[x]^(-1),x},
{Cosh[x]^4 Sinh[x]^(-1),x},
{Cosh[x] Sinh[x]^(-2),x},
{Cosh[x]^2 Sinh[x]^(-2),x},
{Cosh[x]^3 Sinh[x]^(-2),x},
{Cosh[x]^4 Sinh[x]^(-2),x},
{Cosh[x] Sinh[x]^(-3),x},
{Cosh[x]^2 Sinh[x]^(-3),x},
{Cosh[x]^3 Sinh[x]^(-3),x},
{Cosh[x]^4 Sinh[x]^(-3),x},
{Cosh[x] Sinh[x]^(-4),x},
{Cosh[x]^2 Sinh[x]^(-4),x},
{Cosh[x]^3 Sinh[x]^(-4),x},
{Cosh[x]^4 Sinh[x]^(-4),x},
{Sinh[x]^(-1) Cosh[x]^(-1),x},
{Sinh[x]^(-1) Cosh[x]^(-2),x},
{Sinh[x]^(-1) Cosh[x]^(-3),x},
{Sinh[x]^(-1) Cosh[x]^(-4),x},
{Sinh[x]^(-2) Cosh[x]^(-1),x},
{Sinh[x]^(-2) Cosh[x]^(-2),x},
{Sinh[x]^(-2) Cosh[x]^(-3),x},
{Sinh[x]^(-2) Cosh[x]^(-4),x},
{Sinh[x]^(-3) Cosh[x]^(-1),x},
{Sinh[x]^(-3) Cosh[x]^(-2),x},
{Sinh[x]^(-3) Cosh[x]^(-3),x},
{Sinh[x]^(-3) Cosh[x]^(-4),x},
{Sinh[x]^(-4) Cosh[x]^(-1),x},
{Sinh[x]^(-4) Cosh[x]^(-2),x},
{Sinh[x]^(-4) Cosh[x]^(-3),x},
{Sinh[x]^(-4) Cosh[x]^(-4),x},
(*2.424*)
{Tanh[x]^p,x},                          (* Ret2.2 *)                                                         
{Coth[x]^p,x},                          (* Ret2.2 *)                                                    
(*2.425*)
{Sinh[a x+b] Sinh[c x+d],x},
{Sinh[a x+b] Cosh[c x+d],x},
{Cosh[a x+b] Cosh[c x+d],x},
{Sinh[a x+b] Sinh[a x+d],x},
{Sinh[a x+b] Cosh[a x+d],x},
{Cosh[a x+b] Cosh[a x+d],x},
(*2.426*)
{Sinh[a x] Sinh[b x] Sinh[c x],x},
{Sinh[a x] Sinh[b x] Cosh[c x],x},
{Sinh[a x] Cosh[b x] Cosh[c x],x},
{Cosh[a x] Cosh[b x] Cosh[c x],x},
(*2.427*)
{Sinh[x]^p Sinh[a x],x},                (* Ret2.2 *)                              
(*2.428*)
{Sinh[x]^p Cosh[a x],x},                (* Ret2.2 *)                             
(*2.429*)
{Cosh[x]^p Sinh[a x],x},                (* Ret2.2 *)                             
(*2.431*)
{Cosh[x]^p Cosh[a x],x},                (* Ret2.2 *)                               
(*2.432*)
{Sinh[(n+1) x] Sinh[x]^(n-1),x},        (* Ret2.2 *)                                                        
{Sinh[(n+1) x] Cosh[x]^(n-1),x},        (* Ret2.2 *)                                                                    
{Cosh[(n+1) x] Sinh[x]^(n-1),x},        (* Ret2.2 *)                                                                   
{Cosh[(n+1) x] Cosh[x]^(n-1),x},        (* Ret2.2 *)                                                                  
(*2.433*)

{Sinh[(2n+1) x] Sinh[x]^(-1),x},        (* Ret2.2 *)                 
{Sinh[2n x] Sinh[x]^(-1),x},            (* Ret2.2 *)                
{Cosh[(2n+1) x] Sinh[x]^(-1),x},        (* Ret2.2 *)              
{Cosh[2n x] Sinh[x]^(-1),x},            (* Ret2.2 *)                
{Sinh[(2n+1) x] Cosh[x]^(-1),x},        (* Ret2.2 *)               
{Sinh[2n x] Cosh[x]^(-1),x},            (* Ret2.2 *)                 
{Cosh[(2n+1) x] Cosh[x]^(-1),x},        (* Ret2.2 *)                 
{Cosh[2n x] Cosh[x]^(-1),x},            (* Ret2.2 *)                  
{Sinh[2 x] Sinh[x]^(-n),x},                 
{Sinh[2 x] Sinh[x]^(-2),x},
{Sinh[2 x] Cosh[x]^(-n),x},                          
{Sinh[2 x] Cosh[x]^(-2),x},
{Cosh[2 x] Sinh[x]^(-1),x},
{Cosh[2 x] Sinh[x]^(-2),x},
{Cosh[2 x] Sinh[x]^(-3),x},
{Cosh[2 x] Cosh[x]^(-1),x},
{Cosh[2 x] Cosh[x]^(-2),x},
{Cosh[2 x] Cosh[x]^(-3),x},
{Sinh[3 x] Sinh[x]^(-1),x},
{Sinh[3 x] Sinh[x]^(-2),x},
{Sinh[3 x] Sinh[x]^(-3),x},
{Sinh[3 x] Cosh[x]^(-n),x},
{Sinh[3 x] Cosh[x]^(-1),x},
{Sinh[3 x] Cosh[x]^(-3),x},
{Cosh[3 x] Sinh[x]^(-n),x},
{Cosh[3 x] Sinh[x]^(-1),x},
{Cosh[3 x] Sinh[x]^(-3),x},
{Cosh[3 x] Cosh[x]^(-1),x},
{Cosh[3 x] Cosh[x]^(-2),x},
{Cosh[3 x] Cosh[x]^(-3),x},
(*2.441*)
{(A+B Sinh[x])(a+b Sinh[x])^(-n),x},(* GEN *) 
{(A+B Sinh[x])(a+b Sinh[x])^(-1),x},
{(a+b Sinh[x])^(-1),x},
(*2.442*)
{(A+B Cosh[x])(a+b Sinh[x])^(-n),x}, (* GEN *)
{(A+B Cosh[x])(a+b Sinh[x])^(-1),x},    (* Ret2.2 *)                                    
(*2.443*)
{(A+B Cosh[x])(a+b Cosh[x])^(-n),x}, (* GEN *)
{(A+B Cosh[x])(a+b Cosh[x])^(-1),x},
{(a+b Cosh[x])^(-1),x},
(*2.444*)
{(Cosh[a]+Cosh[x])^(-1),x},             (* hangs 2.2 *)              
{(Cos[a]+Cosh[x])^(-1),x},              (* hangs? 2.2 *)                      
(*2.445*)
{(A+B Sinh[x])(a+b Cosh[x])^(-n),x},  (* GEN *)
{(A+B Sinh[x])(a+b Cosh[x])^(-1),x},    (* Ret2.2 *)                                
(*2.446*)
{(A+B Cosh[x])(e+Cosh[x])^(-n),x},  (* GEN *) 
{(A+B Cosh[x])(e+Cosh[x])^(-1),x},
(*2.447*)
{Sinh[x] (a Cosh[x]+b Sinh[x])^(-1),x},                       
{Sinh[x] (Cosh[x]+Sinh[x])^(-1),x},
{Sinh[x] (Cosh[x]-Sinh[x])^(-1),x},
(*2.448*)
{Cosh[x] (a Cosh[x]+b Sinh[x])^(-1),x},
{Cosh[x] (Cosh[x]+Sinh[x])^(-1),x},
{Cosh[x] (Cosh[x]-Sinh[x])^(-1),x},
(*2.449*)
{(a Cosh[x]+b Sinh[x])^(-n),x},         (* Ret2.2 *)                                                              
{(a Cosh[x]+b Sinh[x])^(-1),x},
{(Cosh[x]+Sinh[x])^(-1),x},
{(Cosh[x]-Sinh[x])^(-1),x},
(*2.451*)
{(A+B Cosh[x]+C Sinh[x])(a+b Cosh[x]+c Sinh[x])^(-n),x},   (* GEN Appel*) 
{(A+B Cosh[x]+C Sinh[x])(a+b Cosh[x]+c Sinh[x])^(-1),x},  
                                        (* hangs 2.2 *)              
{(A+B Cosh[x]+C Sinh[x])(a+b Cosh[x]+b Sinh[x])^(-1),x}, 
{(A+B Cosh[x]+C Sinh[x])(a+b Cosh[x]-b Sinh[x])^(-1),x},  
{(a+b Cosh[x]+c Sinh[x])^(-1),x},
(*2.452*)
{(A+B Cosh[x]+C Sinh[x])(a1+b1 Cosh[x]+c1 Sinh[x])^(-1)(a+b Cosh[x]+
 c Sinh[x])^(-1),x},                    (* hangs 2.2 *)         (* Bus er FS *)                                    
{(A+Cosh[x]^2+2B Sinh[x] Cosh[x]+C Sinh[x]^2)(a Cosh[x]^2+2b Sinh[x] Cosh[x]+
 c Sinh[x]^2)^(-1),x},                  (* hangs 2.2 *)       (* Bus er FS ? *)                                         
(*2.453*)
{(A+B Sinh[x]) Sinh[x]^(-1)(a+b Sinh[x])^(-1),x},
{(A+B Sinh[x]) Sinh[x]^(-1)(a+b Cosh[x])^(-1),x},  (* Ret2.2 *)                    
{(A+B Sinh[x]) Sinh[x]^(-1)(1+Cosh[x])^(-1),x},
{(A+B Sinh[x]) Sinh[x]^(-1)(1-Cosh[x])^(-1),x},    
(*2.454*)
{(A+B Sinh[x]) Cosh[x]^(-1)(a+b Sinh[x])^(-1),x},
{(A+B Cosh[x]) Sinh[x]^(-1)(a+b Sinh[x])^(-1),x},  (* Ret2.2 *)                  
(*2.455*)
{(A+B Cosh[x]) Sinh[x]^(-1)(a+b Cosh[x])^(-1),x},
{(A+B Cosh[x]) Sinh[x]^(-1)(1+Cosh[x])^(-1),x},              
{(A+B Cosh[x]) Sinh[x]^(-1)(1-Cosh[x])^(-1),x},             
(* 2.456*)
{(A+B Cosh[x]) Cosh[x]^(-1)(a+b Sinh[x])^(-1),x},  (* Ret2.2 *)                           
(*2.457*)
{(A+B Cosh[x]) Cosh[x]^(-1)(a+b Cosh[x])^(-1),x},
(*2.458*)
{(a+b Sinh[x]^2)^(-1),x},
{(a+b Cosh[x]^2)^(-1),x},
{(1+Sinh[x]^2)^(-1),x},
{(1-Sinh[x]^2)^(-1),x},
{(1+Cosh[x]^2)^(-1),x},
{(1-Cosh[x]^2)^(-1),x},
(*2.459*)
{(a+b Sinh[x]^2)^(-2),x},
{(a+b Cosh[x]^2)^(-2),x},
{(a+b Sinh[x]^2)^(-3),x},
{(a+b Cosh[x]^2)^(-3),x},
(*2.461*)
{Tanh[x]^(1/2),x},                                          
{Coth[x]^(1/2),x},                                             
(*2.462*)
{Sinh[x] (a^2+Sinh[x]^2)^(-1/2),x},                                
{Sinh[x] (a^2-Sinh[x]^2)^(-1/2),x},                                     
{Sinh[x] (-a^2+Sinh[x]^2)^(-1/2),x},                                 
{Cosh[x] (a^2+Sinh[x]^2)^(-1/2),x},
{Cosh[x] (a^2-Sinh[x]^2)^(-1/2),x},
{Cosh[x] (-a^2+Sinh[x]^2)^(-1/2),x},
{Sinh[x] (a^2+Cosh[x]^2)^(-1/2),x},
{Sinh[x] (a^2-Cosh[x]^2)^(-1/2),x},
{Sinh[x] (-a^2+Cosh[x]^2)^(-1/2),x},
{Cosh[x] (a^2+Cosh[x]^2)^(-1/2),x},                               
{Cosh[x] (a^2-Cosh[x]^2)^(-1/2),x},                                
{Cosh[x] (-a^2+Cosh[x]^2)^(-1/2),x},                               
{Coth[x] (a+b Sinh[x])^(-1/2),x},                                 
{Tanh[x] (a+b Cosh[x])^(-1/2),x},                                 
(*2.463*)
{Sinh[x] (a+b Cosh[x])^(1/2)(p+q Cosh[x])^(-1),x}, 
{Cosh[x] (a+b Sinh[x])^(1/2)(p+q Sinh[x])^(-1),x}, 
(*2.464*)
{(k^2+(1-k^2) Cosh[x])^(-1/2),x},                                  
{(-k^2+Cosh[x])^(-1/2),x},                                          
{(1-(1-k^2) Cosh[x])^(-1/2),x},                                     
{Sinh[2 a x]^(-1/2),x},                                             
{Sinh[2 a x]^(1/2),x},                                            
{Cosh[2 a x]^2 (1+Sinh[2 a x])^(-2) Sinh[2 a x]^(-1/2),x},     
{(1-Sinh[2 a x]^2)^2 (1+Sinh[2 a x])^(-2) Sinh[2 a x]^(-1/2),x}, 
{(1+Sinh[2 a x])^(-2) Sinh[2 a x]^(1/2),x},                        
{Cosh[2 a x]^(-1/2),x},                                             
{Cosh[2 a x]^(1/2),x},                                         
{Cosh[2 a x]^(-3/2),x},                                           
{(Cosh[2 a x]^3)^(-1/2),x},                                    
{Cosh[2 a x]^(-5/2),x},                                             
{(Cosh[2 a x]^5)^(-1/2),x},                                     
{Sinh[2 a x]^2 Cosh[2 a x]^(-1/2),x},                                   
{Tanh[2 a x]^2 Cosh[2 a x]^(-1/2),x},                                    
{(p^2+(1-p^2) Cosh[2 a x])^(-1) Cosh[2 a x]^(1/2),x},             
{(a+b Sinh[x])^(-1/2),x},                                                
{(a+b Sinh[x])^(1/2),x},                                               
{Cosh[x]^(-2) (a+b Sinh[x])^(1/2),x},                                          
{Cosh[x]^2 (Sqrt[a^2+b^2]+a+b Sinh[x])^(-2) (a+b Sinh[x])^(-1/2),x},
                                                 (* hangs 2.2 *) (* hangs FS *)                                                                
{(Sqrt[a^2+b^2]-a-b Sinh[x])^(-2) (a+b Sinh[x])^(1/2),x},  (* hangs 2.2 *) 
                                                                 (* hangs FS *)  
      
{(a+b Cosh[x])^(-1/2),x},                                              
{(a+b Cosh[x])^(1/2),x},                                             
{Cosh[x] (a+b Cosh[x])^(-1/2),x},                                   
{Tanh[x/2]^2 (a+b Cosh[x])^(-1/2),x},                                 
{Tanh[x/2]^4 (a+b Cosh[x])^(-1/2),x},                               
{(Cosh[x]-1) (a+b Cosh[x])^(-1/2),x},                                
{(Cosh[x]-1)^2 (a+b Cosh[x])^(-1/2),x},                         
{(Cosh[x]+1)^(-1) (a+b Cosh[x])^(1/2),x},                           
{(Cosh[x]+1)^(-1) (a+b Cosh[x])^(-1/2),x},                          
{(Cosh[x]+1)^(-2) (a+b Cosh[x])^(-1/2),x},                           
{(Cosh[x]+1)(1+p^2+(1-p^2) Cosh[x])^(-1) (a+b Cosh[x])^(-1/2),x},(* hangs FS *)

{(a-b Cosh[x])^(-1/2),x},                                          
{(a-b Cosh[x])^(1/2),x},                                           
{Cosh[x] (a-b Cosh[x])^(-1/2),x},                                     
{Cosh[x]^2 (a-b Cosh[x])^(-1/2),x},                                   
{(Cosh[x]+1)(a-b Cosh[x])^(-1/2),x},                           
{Cosh[x]^(-1)(a-b Cosh[x])^(-1/2),x},                              
{(Cosh[x]+1)^(-1)(a-b Cosh[x])^(-1/2),x},                            
{(Cosh[x]+1)^(-2)(a-b Cosh[x])^(-1/2),x},                           
{(a-b-a p^2+b p^2 Cosh[x])^(-1)(a-b Cosh[x])^(-1/2),x},           
{(-a+b Cosh[x])^(-1/2),x},                                           
{(-a+b Cosh[x])^(1/2),x},                                      
{(-a+b Cosh[x])^(-3/2),x},                                        
{((-a+b Cosh[x])^3)^(-1/2),x},                        
{(-a+b Cosh[x])^(-5/2),x},                                          
{((-a+b Cosh[x])^5)^(-1/2),x},                                 
{Cosh[x] (-a+b Cosh[x])^(-1/2),x},                                 
{(Cosh[x]+1) (-a+b Cosh[x])^(-3/2),x},                              
{(Cosh[x]+1) ((-a+b Cosh[x])^3)^(-1/2),x},                                 
{(p^2 b-a+b (1-p^2)Cosh[x])^(-1) (-a+b Cosh[x])^(1/2),x},            
{(-a+b Cosh[x])^(-1/2),x},                                         
{(-a+b Cosh[x])^(1/2),x},                                        
{Coth[x/2]^2 (-a+b Cosh[x])^(-1/2),x},                                  
{(Cosh[x]-1)^(-1) (-a+b Cosh[x])^(1/2),x},                              
{(Cosh[x]-1)^(-1) (-a+b Cosh[x])^(-1/2),x},                               
{(Cosh[x]-1)^(-2) (-a+b Cosh[x])^(-1/2),x},                            
{(Cosh[x]+1)^(-1) (-a+b Cosh[x])^(-1/2),x},                                  
{(Cosh[x]+1)^(-2) (-a+b Cosh[x])^(-1/2),x},                             
{(a Sinh[x]+b Cosh[x])^(-1/2),x},                            
{(a Sinh[x]+b Cosh[x])^(1/2),x},                                 
{(a Sinh[x]+b Cosh[x])^(-3/2),x},                              
{((a Sinh[x]+b Cosh[x])^3)^(-1/2),x},                                                             
{(a Sinh[x]+b Cosh[x])^(-5/2),x},                               (* hangs FS *)                       
{((a Sinh[x]+b Cosh[x])^5)^(-1/2),x},                           (* hangs FS *)                                     
{(Sqrt[b^2-a^2]+a Sinh[x]+b Cosh[x]) (a Sinh[x]+b Cosh[x])^(-3/2),x},
                                        (* Ret2.2 *)            (* hangs FS *)                                                                            
{(Sqrt[b^2-a^2]+a Sinh[x]+b Cosh[x])((a Sinh[x]+b Cosh[x])^3)^(-1/2),x},                                                                                                                                  
(*2.471*)
 {x^r Sinh[x]^p Cosh[x]^q,x},      (* ********* Return GENERICALLY ********* *)     
 {x^n Sinh[x]^(2m),x},             (* ********* Return GENERICALLY ********* *)   
 {x^n Sinh[x]^(2m+1),x},           (* ********* Return GENERICALLY ********* *)   
 {x^n Cosh[x]^(2m),x},             (* ********* Return GENERICALLY ********* *)   
 {x^n Cosh[x]^(2m+1),x},           (* ********* Return GENERICALLY ********* *)

   (*2.472*)
{x^n Sinh[x],x},                        (* Ret2.2 *)                                            
{x^n Cosh[x],x},                        (* Ret2.2 *)                                           
{x Sinh[x],x},
{x^2 Sinh[x],x},
{x Cosh[x],x},           
{x^2 Cosh[x],x}, 
(*2.473*)
{(a+b x) Sinh[k x],x}, 
{(a+b x) Cosh[k x],x},  
{(a+b x)^2 Sinh[k x],x}, 
{(a+b x)^2 Cosh[k x],x},   
{(a+b x)^3 Sinh[k x],x}, 
{(a+b x)^3 Cosh[k x],x},
{(a+b x)^4 Sinh[k x],x}, 
{(a+b x)^4 Cosh[k x],x},      
{(a+b x)^5 Sinh[k x],x}, 
{(a+b x)^5 Cosh[k x],x},     
{(a+b x)^6 Sinh[k x],x}, 
{(a+b x)^6 Cosh[k x],x},
(*2.474*)
{x^n Sinh[x]^2,x},                      (* Ret2.2 *)                                               
{x^n Cosh[x]^2,x},                      (* Ret2.2 *)                                                
{x Sinh[x]^2,x},  
{x^2 Sinh[x]^2,x},   
{x Cosh[x]^2,x},  
{x^2 Cosh[x]^2,x},
{x^n Sinh[x]^3,x},                      (* Ret2.2 *)                                               
{x^n Cosh[x]^3,x},                      (* Ret2.2 *)                                             
{x Sinh[x]^3,x},  
{x^2 Sinh[x]^3,x},      
{x Cosh[x]^3,x},  
{x^2 Cosh[x]^3,x}, 
(*2.475*)
 {x^(-p) Sinh[x]^q,x},             (* ********* Return GENERICALLY ********* *)       
 {x^(-p) Cosh[x]^q,x},             (* ********* Return GENERICALLY ********* *)
{x^(-2n) Sinh[x],x},                    (* Ret2.2 *)                                   
{x^(-2n-1) Sinh[x],x},                  (* Ret2.2 *)                                          
{x^(-2n) Cosh[x],x},                    (* Ret2.2 *)                                            
{x^(-2n-1) Cosh[x],x},                  (* Ret2.2 *)
 {x^(-1) Sinh[x]^(2m),x},          (* ********* Return GENERICALLY ********* *)
 {x^(-1) Sinh[x]^(2m+1),x},        (* ********* Return GENERICALLY ********* *)    
 {x^(-1) Cosh[x]^(2m),x},          (* ********* Return GENERICALLY ********* *)
 {x^(-1) Cosh[x]^(2m+1),x},        (* ********* Return GENERICALLY ********* *)
 {x^(-2) Sinh[x]^(2m),x},          (* ********* Return GENERICALLY ********* *)
 {x^(-2) Sinh[x]^(2m+1),x},        (* ********* Return GENERICALLY ********* *)
 {x^(-2) Cosh[x]^(2m),x},          (* ********* Return GENERICALLY ********* *)
 {x^(-2) Cosh[x]^(2m+1),x},        (* ********* Return GENERICALLY ********* *)
(*2.476*)
{(a+b x)^(-1) Sinh[k x],x},                
{(a+b x)^(-1) Cosh[k x],x},                   
{(a+b x)^(-2) Sinh[k x],x},                
{(a+b x)^(-2) Cosh[k x],x}, 
{(a+b x)^(-3) Sinh[k x],x},                
{(a+b x)^(-3) Cosh[k x],x}, 
{(a+b x)^(-4) Sinh[k x],x},                
{(a+b x)^(-4) Cosh[k x],x}, 
{(a+b x)^(-5) Sinh[k x],x},                
{(a+b x)^(-5) Cosh[k x],x}, 
{(a+b x)^(-6) Sinh[k x],x},               
{(a+b x)^(-6) Cosh[k x],x}, 
(*2.477*)
 {x^p Sinh[x]^(-q),x},             (* ********* Return GENERICALLY ********* *)
 {x^p Cosh[x]^(-q),x},             (* ********* Return GENERICALLY ********* *)
 {x^n Sinh[x]^(-1),x},             (* ********* Return GENERICALLY ********* *)
 {x^n Cosh[x]^(-1),x},             (* ********* Return GENERICALLY ********* *)              
 {x^(-n) Sinh[x]^(-1),x},          (* ********* Return GENERICALLY ********* *)
 {x^(-n) Cosh[x]^(-1),x},          (* ********* Return GENERICALLY ********* *)
 {x^n Sinh[x]^(-2),x},             (* ********* Return GENERICALLY ********* *)
 {x^n Cosh[x]^(-2),x},             (* ********* Return GENERICALLY ********* *)
 {x^(-n) Sinh[x]^(-2),x},          (* ********* Return GENERICALLY ********* *)
 {x^(-n) Cosh[x]^(-2),x},          (* ********* Return GENERICALLY ********* *)
{x Sinh[x]^(-2 n),x},                   (* Ret2.2 *) (* Ret FS *)
{x Sinh[x]^(-1),x},                     (* Ret2.2 *)
{x Cosh[x]^(-1),x},                     (* Ret2.2 *)             
{x Sinh[x]^(1-2 n),x},                  (* Ret2.2 *)  (* Ret FS *)
{x Cosh[x]^(-2 n),x},                   (* Ret2.2 *)  (* Ret FS *)
{x Cosh[x]^(1-2 n),x},                  (* Ret2.2 *)  (* Ret FS *)

{x Sinh[x]^(-1),x},                     (* Ret2.2 *)                                             
{x Cosh[x]^(-1),x},                     (* Ret2.2 *)                                                
{x Sinh[x]^(-2),x}, 
{x Cosh[x]^(-2),x},
{x Sinh[x]^(-3),x},                     (* Ret2.2 *)                                                                               
{x Cosh[x]^(-3),x},                     (* Ret2.2 *)                                               
{x Sinh[x]^(-4),x}, 
{x Cosh[x]^(-4),x},
{x Sinh[x]^(-5),x},                     (* Ret2.2 *)                                                   
{x Cosh[x]^(-5),x},                     (* Ret2.2 *)                                             
(*2.478*) 
 {x^n Cosh[x] (a+b Sinh[x])^(-m),x}, (* ******** Return GENERICALLY ******** *)
 {x^n Cosh[x] (a+b Cosh[x])^(-m),x}, (* ******** Return GENERICALLY ******** *)
{x (1+Cosh[x])^(-1),x},  
{x (1-Cosh[x])^(-1),x}, 
{x Sinh[x] (1+Cosh[x])^(-2),x}, 
{x Sinh[x] (1-Cosh[x])^(-2),x},
{x (Cosh[2 x]-Cos[2 t])^(-1),x},        (* Ret2.2 *)                                                           
{x Cosh[x] (Cosh[2 x]-Cos[2 t])^(-1),x},(* Ret2.2 *)             (* hangs FS *)                                                  
(*2.479*)
 {x^p Sinh[x]^(2m) Cosh[x]^(-n),x},  (* ******** Return GENERICALLY ******** *)
 {x^p Sinh[x]^(2m+1) Cosh[x]^(-n),x},(* ******** Return GENERICALLY ******** *)
 {x^p Sinh[x] Cosh[x]^(-n),x},       (* ******** Return GENERICALLY ******** *)
 {x^p Cosh[x]^(2m) Sinh[x]^(-n),x},  (* ******** Return GENERICALLY ******** *)
 {x^p Cosh[x]^(2m+1) Sinh[x]^(-n),x},(* ******** Return GENERICALLY ******** *)
 {x^p Cosh[x] Sinh[x]^(-n),x},       (* ******** Return GENERICALLY ******** *)
 {x^p Tanh[x],x},                    (* ******** Return GENERICALLY ******** *)
 {x^p Coth[x],x},                    (* ******** Return GENERICALLY ******** *)
{x Cosh[x] Sinh[x]^(-2),x},
{x Sinh[x] Cosh[x]^(-2),x}, 
(*2.481*)
{Exp[a x] Sinh[b x+c],x}, 
{Exp[a x] Cosh[b x+c],x},       
{Exp[a x] Sinh[a x+c],x}, 
{Exp[-a x] Sinh[a x+c],x}, 
{Exp[a x] Cosh[a x+c],x},  
{Exp[-a x] Cosh[a x+c],x}, 
(*2.482*)
{x^p Exp[a x] Sinh[b x],x},             (* Ret2.2 *)                                 
{x^p Exp[a x] Cosh[b x],x},             (* Ret2.2 *)                                 
{x^p Exp[a x] Sinh[a x],x},             (* Ret2.2 *)                                            
{x^p Exp[-a x] Sinh[a x],x},            (* Ret2.2 *)                                  
{x^p Exp[a x] Cosh[a x],x},             (* Ret2.2 *)                                 
(*2.483*)
{x Exp[a x] Sinh[b x],x},    
{x Exp[a x] Cosh[b x],x},
{x^2 Exp[a x] Sinh[b x],x},        
{x^2 Exp[a x] Cosh[b x],x}, 
{x Exp[a x] Sinh[a x],x},
{x Exp[-a x] Sinh[a x],x},   
{x Exp[a x] Cosh[a x],x},   
{x Exp[-a x] Cosh[a x],x},
{x^2 Exp[a x] Sinh[a x],x}, 
{x^2 Exp[-a x] Sinh[a x],x}, 
{x^2 Exp[a x] Cosh[a x],x}, 
(*2.484*)
{x^(-1) Exp[a x] Sinh[b x],x},          (* Ret2.2 *)                                                             
{x^(-1) Exp[a x] Cosh[b x],x},          (* Ret2.2 *)                                                     
{x^(-2) Exp[a x] Sinh[b x],x},          (* Ret2.2 *)                                                             
{x^(-2) Exp[a x] Cosh[b x],x},          (* Ret2.2 *)                                                        
{x^(-1) Exp[a x] Sinh[a x],x},
{x^(-1) Exp[-a x] Sinh[a x],x},
{x^(-1) Exp[a x] Cosh[a x],x},
{x^(-2) Exp[a x] Sinh[a x],x},
{x^(-2) Exp[-a x] Sinh[a x],x},
{x^(-2) Exp[a x] Cosh[a x],x}, 

(*****************************************************************************)
(*                       Trigonomitric functions                             *)
(*****************************************************************************)
(*2.510*)
{Sin[x]^p Cos[x]^q,x},                  (* Ret2.2 *)                                         
(*2.511*)
{Sin[x]^p Cos[x]^(2n),x},               (* Ret2.2 *)                                      
{Sin[x]^(2 l),x},                       (* Ret2.2 *)                                             
{Sin[x]^(2 l+1),x},                     (* Ret2.2 *)                                             
{Sin[x]^p Cos[x]^(2 n+1),x},            (* Ret2.2 *)                                         
(*2.512*)
{Cos[x]^p Sin[x]^(2n),x},               (* Ret2.2 *)                                       
{Cos[x]^(2l),x},                        (* Ret2.2 *)                                                
{Cos[x]^(2l+1),x},                      (* Ret2.2 *)                                                    
{Cos[x]^p Sin[x]^(2n+1),x},             (* Ret2.2 *)                                           
(*2.513*)
{Sin[x]^(2n),x},                        (* Ret2.2 *)                                                 
{Sin[x]^(2n+1),x},                      (* Ret2.2 *)                                                   
{Cos[x]^(2n),x},                        (* Ret2.2 *)                                                     
{Cos[x]^(2n+1),x},                      (* Ret2.2 *)                                          
{Sin[x]^2,x},    
{Sin[x]^3,x},
{Sin[x]^4,x},    
{Sin[x]^5,x}, 
{Sin[x]^6,x},    
{Sin[x]^7,x},
{Cos[x]^2,x},    
{Cos[x]^3,x},
{Cos[x]^4,x},    
{Cos[x]^5,x}, 
{Cos[x]^6,x},    
{Cos[x]^7,x},
{Sin[x] Cos[x]^2,x},
{Sin[x] Cos[x]^3,x},
{Sin[x] Cos[x]^4,x},
{Sin[x]^2 Cos[x],x},
{Sin[x]^2 Cos[x]^2,x},
{Sin[x]^2 Cos[x]^3,x},
{Sin[x]^2 Cos[x]^4,x},
{Sin[x]^3 Cos[x],x},
{Sin[x]^3 Cos[x]^2,x},
{Sin[x]^3 Cos[x]^3,x},
{Sin[x]^3 Cos[x]^4,x},
{Sin[x]^4 Cos[x],x},
{Sin[x]^4 Cos[x]^2,x},
{Sin[x]^4 Cos[x]^3,x},
{Sin[x]^4 Cos[x]^4,x},
(*2.514*)
{Sin[x]^p Cos[x]^(-2 n),x},             (* Ret2.2 *)                                   
(*2.515*)
{Sin[x]^(-2 l),x},                      (* Ret2.2 *)                                           
{Sin[x]^(-2 l-1),x},                    (* Ret2.2 *)                                         
(*2.516*)
{Sin[x]^p Cos[x]^(-2 n-1),x},           (* Ret2.2 *)                                
{Sin[x]^(2 l+1) Cos[x]^(-1),x},         (* Ret2.2 *)                                    
{Sin[x]^(2 l) Cos[x]^(-1),x},           (* Ret2.2 *)                                  
(*2.517*)
{Sin[x]^(-2m-1) Cos[x]^(-1),x},         (* Ret2.2 *)                         
{Sin[x]^(-2m) Cos[x]^(-1),x},           (* Ret2.2 *)                         
(*2.518*)
{Sin[x]^p Cos[x]^(-2),x},               (* Ret2.2 *)                            
{Cos[x]^p Sin[x]^(-2n),x},              (* Ret2.2 *)                                
(*2.519*)
{Cos[x]^(-2l),x},                       (* Ret2.2 *)                                 
{Cos[x]^(-2l-1),x},                     (* Ret2.2 *)                                   
(*2.521*)
{Cos[x]^p Sin[x]^(-2n-1),x},            (* Ret2.2 *)                                  
{Cos[x]^(2l+1) Sin[x]^(-1),x},          (* Ret2.2 *)                                   
{Cos[x]^(2l) Sin[x]^(-1),x},            (* Ret2.2 *)                               
(*2.522*)
{Cos[x]^(-2m-1) Sin[x]^(-1),x},         (* Ret2.2 *)                                 
{Cos[x]^(-2m) Sin[x]^(-1),x},           (* Ret2.2 *)                              
(*2.523*)
{Cos[x]^m Sin[x]^(-2),x},               (* Ret2.2 *)                               
(*2.524*)

{Sin[x]^(2n+1) Cos[x]^(-m),x},          (* Ret2.2 *)                              
{Cos[x]^(2n+1) Sin[x]^(-m),x},          (* Ret2.2 *)                            
(*2.525*)
{Sin[x]^(-2m) Cos[x]^(-2n),x},          (* Ret2.2 *)                             
{Sin[x]^(-2m-1) Cos[x]^(-2n-1),x},      (* Ret2.2 *)                   
(*2.526*)
{Sin[x]^(-1),x},
{Sin[x]^(-2),x},
{Sin[x]^(-3),x},
{Sin[x]^(-4),x},
{Sin[x]^(-5),x},
{Sin[x]^(-6),x},                        
{Sin[x]^(-7),x},
{Sin[x]^(-8),x},
{Cos[x]^(-1),x},
{Cos[x]^(-2),x},
{Cos[x]^(-3),x},
{Cos[x]^(-4),x},
{Cos[x]^(-5),x},
{Cos[x]^(-6),x},
{Cos[x]^(-7),x},
{Cos[x]^(-8),x},
{Sin[x] Cos[x]^(-1),x},
{Sin[x]^2 Cos[x]^(-1),x},
{Sin[x]^3 Cos[x]^(-1),x},
{Sin[x]^4 Cos[x]^(-1),x},
{Sin[x] Cos[x]^(-2),x},
{Sin[x]^2 Cos[x]^(-2),x},
{Sin[x]^3 Cos[x]^(-2),x},
{Sin[x]^4 Cos[x]^(-2),x},
{Sin[x] Cos[x]^(-3),x},
{Sin[x]^2 Cos[x]^(-3),x},
{Sin[x]^3 Cos[x]^(-3),x},
{Sin[x]^4 Cos[x]^(-3),x},
{Sin[x] Cos[x]^(-4),x},
{Sin[x]^2 Cos[x]^(-4),x},
{Sin[x]^3 Cos[x]^(-4),x},
{Sin[x]^4 Cos[x]^(-4),x},
{Cos[x] Sin[x]^(-1),x},
{Cos[x]^2 Sin[x]^(-1),x},
{Cos[x]^3 Sin[x]^(-1),x},
{Cos[x]^4 Sin[x]^(-1),x},
{Cos[x] Sin[x]^(-2),x},
{Cos[x]^2 Sin[x]^(-2),x},
{Cos[x]^3 Sin[x]^(-2),x},
{Cos[x]^4 Sin[x]^(-2),x},
{Cos[x] Sin[x]^(-3),x},
{Cos[x]^2 Sin[x]^(-3),x},
{Cos[x]^3 Sin[x]^(-3),x},
{Cos[x]^4 Sin[x]^(-3),x},
{Cos[x] Sin[x]^(-4),x},
{Cos[x]^2 Sin[x]^(-4),x},
{Cos[x]^3 Sin[x]^(-4),x},
{Cos[x]^4 Sin[x]^(-4),x},
{Sin[x]^(-1) Cos[x]^(-1),x},
{Sin[x]^(-1) Cos[x]^(-2),x},
{Sin[x]^(-1) Cos[x]^(-3),x},
{Sin[x]^(-1) Cos[x]^(-4),x},
{Sin[x]^(-2) Cos[x]^(-1),x},
{Sin[x]^(-2) Cos[x]^(-2),x},
{Sin[x]^(-2) Cos[x]^(-3),x},
{Sin[x]^(-2) Cos[x]^(-4),x},
{Sin[x]^(-3) Cos[x]^(-1),x},
{Sin[x]^(-3) Cos[x]^(-2),x},
{Sin[x]^(-3) Cos[x]^(-3),x},
{Sin[x]^(-3) Cos[x]^(-4),x},
{Sin[x]^(-4) Cos[x]^(-1),x},
{Sin[x]^(-4) Cos[x]^(-2),x},
{Sin[x]^(-4) Cos[x]^(-3),x},
{Sin[x]^(-4) Cos[x]^(-4),x},
(*2.527*)
{Tan[x]^p,x},                           (* Ret2.2 *)                                               
{Tan[x]^(2n+1),x},                      (* Ret2.2 *)                                            
{Tan[x]^(2n),x},                        (* Ret2.2 *)                                            
{Cot[x]^p,x},                           (* Ret2.2 *) 
                                        
{Cot[x]^(2n+1),x},                      (* Ret2.2 *)                                          
{Cot[x]^(2n),x},                        (* Ret2.2 *)                                       
(*2.531*)
{Sin[a x+b],x},
{Cos[a x+b],x},
(*2.532*)
{Sin[a x+b] Sin[c x+d],x},
{Sin[a x+b] Cos[c x+d],x},
{Cos[a x+b] Cos[c x+d],x},
{Sin[a x+b] Sin[a x+d],x},
{Sin[a x+b] Cos[a x+d],x},
{Cos[a x+b] Cos[a x+d],x},
(*2.533*)
{Sin[a x] Cos[b x],x},
{Sin[a x] Sin[b x] Sin[c x],x},
{Sin[a x] Cos[b x] Cos[c x],x},
{Cos[a x] Sin[b x] Sin[c x],x},
{Cos[a x] Cos[b x] Cos[c x],x},
(*2.534*)
{(Cos[p x]+I Sin[p x]) Sin[n x]^(-1),x},(* Ret2.2 *)                                   
{(Cos[p x]+I Sin[p x]) Cos[n x]^(-1),x},(* Ret2.2 *)                                  
(*2.535*)
{Sin[x]^p Sin[a x],x},                  (* Ret2.2 *)                                      
{Sin[x]^p Sin[(2n+1) x],x},             (* Ret2.2 *)                                    
{Sin[x]^p Sin[2n x],x},                 (* Ret2.2 *)                                    
(*2.536*)
{Sin[x]^p Cos[a x],x},                  (* Ret2.2 *)                                      
{Sin[x]^p Cos[(2n+1) x],x},             (* Ret2.2 *)                                    
{Sin[x]^p Cos[2n x],x},                 (* Ret2.2 *)                                     
(*2.537*)
{Cos[x]^p Sin[a x],x},                  (* Ret2.2 *)                                       
{Cos[x]^p Sin[(2n+1) x],x},             (* Ret2.2 *)                                      
{Cos[x]^p Sin[2n x],x},                 (* Ret2.2 *)                                      
(*2.538*)
{Cos[x]^p Cos[a x],x},                  (* Ret2.2 *)                                  
{Cos[x]^p Cos[(2n+1) x],x},             (* Ret2.2 *)                                   
{Cos[x]^p Cos[2n x],x},                 (* Ret2.2 *)                                       
(*2.539*)
{Sin[(2n+1) x] Sin[x]^(-1),x},          (* Ret2.2 *)                                 
{Sin[2n x] Sin[x]^(-1),x},              (* Ret2.2 *)                               
{Cos[(2n+1) x] Sin[x]^(-1),x},          (* Ret2.2 *)                              
{Cos[2n x] Sin[x]^(-1),x},              (* Ret2.2 *)                               
{Sin[(2n+1) x] Cos[x]^(-1),x},          (* Ret2.2 *)                               
{Sin[2n x] Cos[x]^(-1),x},              (* Ret2.2 *)                                
{Cos[(2n+1) x] Cos[x]^(-1),x},          (* Ret2.2 *)                              
{Cos[2n x] Cos[x]^(-1),x},              (* Ret2.2 *)                                 
(*2.541*)
{Sin[(n+1) x] Sin[x]^(n-1),x},          (* Ret2.2 *)                                               
{Sin[(n+1) x] Cos[x]^(n-1),x},          (* Ret2.2 *)                                                       
{Cos[(n+1) x] Sin[x]^(n-1),x},          (* Ret2.2 *)                                                        
{Cos[(n+1) x] Cos[x]^(n-1),x},          (* Ret2.2 *)                                                       
{Sin[(n+1)(Pi/2-x)] Sin[x]^(n-1),x},    (* Ret2.2 *)                                               
{Cos[(n+1)(Pi/2-x)] Sin[x]^(n-1),x},    (* Ret2.2 *)                                            
(*2.542*)
{Sin[2 x] Sin[x]^(-n),x},
{Sin[2 x] Sin[x]^(-2),x},
(*2.543*)
{Sin[2 x] Cos[x]^(-n),x},
{Sin[2 x] Cos[x]^(-2),x},
(*2.544*)
{Cos[2 x] Sin[x]^(-1),x},
{Cos[2 x] Sin[x]^(-2),x},
{Cos[2 x] Sin[x]^(-3),x},
{Cos[2 x] Cos[x]^(-1),x},
{Cos[2 x] Cos[x]^(-2),x},
{Cos[2 x] Cos[x]^(-3),x},
{Sin[3 x] Sin[x]^(-1),x},
{Sin[3 x] Sin[x]^(-2),x},
{Sin[3 x] Sin[x]^(-3),x},
(*2.545*)
{Sin[3 x] Cos[x]^(-n),x},               
{Sin[3 x] Cos[x]^(-1),x},
{Sin[3 x] Cos[x]^(-3),x},
(*2.546*)
{Cos[3 x] Sin[x]^(-n),x},
{Cos[3 x] Sin[x]^(-1),x},
{Cos[3 x] Sin[x]^(-3),x},
(*2.547*)
{Sin[n x] Cos[x]^(-p),x},               (* Ret2.2 *)                                      
{Cos[3 x] Cos[x]^(-1),x},
{Cos[3 x] Cos[x]^(-2),x},
{Cos[3 x] Cos[x]^(-3),x},
(*2.548*)
 {Sin[x]^m Sin[(2 n+1) x]^(-1),x},   (* ******** Return GENERICALLY ******** *)
 {Sin[x]^(2m) Sin[2 n x]^(-1),x},    (* ******** Return GENERICALLY ******** *)
 {Sin[x]^(2m+1) Sin[2 n x]^(-1),x},  (* ******** Return GENERICALLY ******** *)
 {Sin[x]^(2m) Cos[(2 n+1) x]^(-1),x},(* ******** Return GENERICALLY ******** *)
 {Sin[x]^(2m+1) Cos[(2 n+1) x]^(-1),x},(* ****** Return GENERICALLY ******** *)
 {Sin[x]^m Cos[2 n x]^(-1),x},       (* ******** Return GENERICALLY ******** *)
 {Cos[x]^(2m+1) Sin[(2 n+1) x]^(-1),x},(* ****** Return GENERICALLY ******** *)
 {Cos[x]^(2m) Sin[(2 n+1) x]^(-1),x},(* ******** Return GENERICALLY ******** *)
 {Cos[x]^(2m+1) Sin[2 n x]^(-1),x},  (* ******** Return GENERICALLY ******** *)
 {Cos[x]^(2m) Sin[2 n x]^(-1),x},    (* ******** Return GENERICALLY ******** *)
 {Cos[x]^m Sin[n x]^(-1),x},         (* ******** Return GENERICALLY ******** *)
(*2.549*)
{Sin[x^2],x},
{Cos[x^2],x},
{Sin[a x^2+2 b x+c],x},
{Cos[a x^2+2 b x+c],x},
{Sin[Log[x]],x},
{Cos[Log[x]],x},
(*2.551*)
{(A+B Sin[x]) (a+b Sin[x])^(-n),x}, (* GEN *)
{(A+B Sin[x]) (a+b Sin[x])^(-1),x},
{(a+b Sin[x])^(-1),x},
(*2.552*)
{(A+B Cos[x]) (a+b Sin[x])^(-n),x}, (* GEN *)
{(A+B Cos[x]) (a+b Sin[x])^(-1),x},     (* Ret2.2 *)                            {(a+b Sin[x])^(-n),x},              (* GEN *)
(*2.553*)
{(A+B Sin[x]) (a+b Cos[x])^(-n),x}, (* GEN *)
{(A+B Sin[x]) (a+b Cos[x])^(-1),x},     (* Ret2.2 *)                               
{(a+b Cos[x])^(-1),x},
(*2.554*)
{(A+B Cos[x]) (a+b Cos[x])^(-n),x}, (* GEN *)
{(A+B Cos[x]) (a+b Cos[x])^(-1),x},
{(a+b Cos[x])^(-n),x},              (* GEN *)

(*2.555*)
{(A+B Sin[x]) (1+Sin[x])^(-n),x},          (* Ret2.2 *)            
{(A+B Sin[x]) (1-Sin[x])^(-n),x},          (* Ret2.2 *)            
{(A+B Cos[x]) (1+Cos[x])^(-n),x},          (* Ret2.2 *)           
{(A+B Cos[x]) (1-Cos[x])^(-n),x},          (* Ret2.2 *)        
{(A+B Sin[x]) (1+Sin[x])^(-1),x},
{(A+B Sin[x]) (1-Sin[x])^(-1),x},                          
{(A+B Cos[x]) (1+Cos[x])^(-1),x},
{(A+B Cos[x]) (1-Cos[x])^(-1),x},
(*2.556*)
{(1-2 a Cos[x]+a^2)^(-1),x},                                
{(1-a Cos[x]) (1-2 a Cos[x]+a^2)^(-1),x},
(*2.557*)
{(a Cos[x]+b Sin[x])^(-n),x},           (* Ret2.2 *)                                                  
{Sin[x] (a Sin[x]+b Cos[x])^(-1),x},                    
{Cos[x] (a Cos[x]+b Sin[x])^(-1),x},                   
{(a Cos[x]+b Sin[x])^(-1),x},
{(a Cos[x]+b Sin[x])^(-2),x},
(*2.558*)
{(A+B Cos[x]+C Sin[x]) (a+b Cos[x]+c Sin[x])^(-n),x},  (* GEN *)
{(A+B Cos[x]+C Sin[x]) (a+b Cos[x]+c Sin[x])^(-1),x},  (* hangs 2.2 *)        
{(a+b Cos[x]+c Sin[x])^(-n),x},     (* GEN *)
{(a+b Cos[x]+c Sin[x])^(-1),x},
(*2.559*)
{(a+a Cos[x]+c Sin[x])^(-1),x},                                     
{(a (1+Cos[x])+c Sin[x])^(-2),x},                            
{(a1+b1 Cos[x]+c1 Sin[x])^(-1)(a+b Cos[x]+c Sin[x])^(-1),x}, (* hangs 2.2 *)
                                                                (* hangs FS *)                                                                     
{(A Cos[x]^2+2 B Sin[x] Cos[x]+C Sin[x]^2) (a Cos[x]^2+2 b Sin[x] Cos[x]+
  c Sin[x]^2)^(-1),x},                  (* hangs 2.2 *)         (* hangs FS *) 
                                 
(*2.561*)
{(A+B Sin[x]) Sin[x]^(-1) (a+b Sin[x])^(-1),x},
{(A+B Sin[x]) Sin[x]^(-1) (a+b Cos[x])^(-1),x},  (* Ret2.2 *)                      
{(A+B Sin[x]) Sin[x]^(-1) (1+Cos[x])^(-1),x},                                 
{(A+B Sin[x]) Sin[x]^(-1) (1-Cos[x])^(-1),x},
{(A+B Sin[x]) Cos[x]^(-1) (a+b Sin[x])^(-1),x},
{(A+B Sin[x]) Cos[x]^(-1) (1+Sin[x])^(-1),x},     
{(A+B Sin[x]) Cos[x]^(-1) (1-Sin[x])^(-1),x},               
{(A+B Sin[x]) Cos[x]^(-1) (a+b Cos[x])^(-1),x},  (* Ret2.2 *)                      
{(A+B Cos[x]) Sin[x]^(-1) (a+b Sin[x])^(-1),x},                
{(A+B Cos[x]) Sin[x]^(-1) (a+b Cos[x])^(-1),x},
{(A+B Cos[x]) Sin[x]^(-1) (1+Cos[x])^(-1),x},               
{(A+B Cos[x]) Sin[x]^(-1) (1-Cos[x])^(-1),x},                
{(A+B Cos[x]) Cos[x]^(-1) (a+b Sin[x])^(-1),x},                  
{(A+B Sin[x]) Cos[x]^(-1) (1+Sin[x])^(-1),x},    
{(A+B Sin[x]) Cos[x]^(-1) (1-Sin[x])^(-1),x},               
{(A+B Cos[x]) Cos[x]^(-1) (a+b Cos[x])^(-1),x},     
(*2.562*)
{(a+b Sin[x]^2)^(-1),x},
{(a+b Cos[x]^2)^(-1),x},
{(1+Sin[x]^2)^(-1),x},
{(1-Sin[x]^2)^(-1),x},
{(1+Cos[x]^2)^(-1),x},
{(1-Cos[x]^2)^(-1),x},
(*2.563*)
{(a+b Sin[x]^2)^(-2),x},
{(a+b Cos[x]^2)^(-2),x},
{(a+b Sin[x]^2)^(-3),x},
{(a+b Cos[x]^2)^(-3),x},
(*2.564*)
{Tan[x] (1+m^2 Tan[x]^2)^(-1),x},                       
{(Tan[a]-Tan[x]) (Tan[a]+Tan[x])^(-1),x},
{Tan[x] (a+b Tan[x])^(-1),x},                           
{(a+b Tan[x]^2)^(-1),x},
(*2.571*)
{(a+b Sin[x])^(-1/2),x},                                         
{Sin[x] (a+b Sin[x])^(-1/2),x},                                 
{Sin[x]^2 (a+b Sin[x])^(-1/2),x},                    
{(a+b Cos[x])^(-1/2),x},                                        
{(a-b Cos[x])^(-1/2),x},                                        
{Cos[x] (a+b Cos[x])^(-1/2),x},                                   
{Cos[x] (a-b Cos[x])^(-1/2),x},                                  
{Cos[x]^2 (a+b Cos[x])^(-1/2),x},                                
{Cos[x]^2 (a-b Cos[x])^(-1/2),x},                   
(*2.572*)
{Tan[x]^2 (a+b Sin[x])^(-1/2),x},                            
(*2.573*)
{(1-Sin[x])/(1+Sin[x]) (a+b Sin[x])^(-1/2),x},                            
{(1-Cos[x])/(1+Cos[x]) (a+b Cos[x])^(-1/2),x},         
(*2.574*)
{(2-p^2+p^2 Sin[x])^(-1) (a+b Sin[x])^(-1/2),x},               
{(a+b-p^2 b+p^2 b Sin[x])^(-1) (a+b Sin[x])^(-1/2),x},             
{(2-p^2+p^2 Cos[x])^(-1) (a+b Cos[x])^(-1/2),x},                  
{(a+b-p^2 b+p^2 b Cos[x])^(-1) (a+b Cos[x])^(-1/2),x},             
(*2.575*)
{(a+b Sin[x])^(-3/2),x},                                         
{((a+b Sin[x])^3)^(-1/2),x},                                   
{(a+b Sin[x])^(-5/2),x},                                         
{((a+b Sin[x])^5)^(-1/2),x},                                  
{(a+b Cos[x])^(-3/2),x},                                           
{((a+b Cos[x])^3)^(-1/2),x},                                 
{(a-b Cos[x])^(-3/2),x},                                           
{((a-b Cos[x])^3)^(-1/2),x},                                
{(a+b Cos[x])^(-5/2),x},                                           
{((a+b Cos[x])^5)^(-1/2),x},                                    
(*2.576*)
{(a+b Cos[x])^(1/2),x},                                             
{(a-b Cos[x])^(1/2),x},                                            
(*2.577*)
{(1+p Cos[x])^(-1) (a-b Cos[x])^(1/2),x},                            
{((a-b Cos[x])/(1+p Cos[x]))^(1/2),x},                    (* hangs FS *)                                        
{(a-b Cos[x])^(1/2) (1+p Cos[x])^(-1/2),x},               (* hangs FS *)
                
(*2.578*)
{Tan[x](a-b Tan[x]^2)^(-1/2),x},                                                                                 
(*2.580*)
{(a+b Cos[x]+c Sin[x])^(-1/2),x},                             
{(a+b Cos[x]+c Sin[x]+d Cos[x]^2+e Sin[x] Cos[x]+f Sin[x]^2)^(-1/2),x},
                                                (* Ret2.2 *)  (* hangs FS *) 
                                                                 
(*2.581*)
{Sin[x]^m Cos[x]^n (1-k^2 Sin[x]^2)^(r/2),x}, (* GEN *)
{Sin[x]^m Cos[x]^n (1-k^2 Sin[x]^2)^(-3/2),x},(* GEN *)
{Sin[x]^m Cos[x]^n (1-k^2 Sin[x]^2)^(-5/2),x},(* GEN *)
{Sin[x] Cos[x]^n (1-k^2 Sin[x]^2)^(r/2),x},     (* Ret2.2 *)                        
{Sin[x]^m Cos[x] (1-k^2 Sin[x]^2)^(r/2),x},     (* Ret2.2 *)                        
{Sin[x]^3 Cos[x]^n (1-k^2 Sin[x]^2)^(r/2),x},   (* Ret2.2 *)                             
{Sin[x]^m Cos[x]^3 (1-k^2 Sin[x]^2)^(r/2),x},   (* Ret2.2 *)                            
(*2.582*)  
{(1-k^2 Sin[x]^2)^(r/2),x},                   (* GEN *)
{Sin[x]^n (1-k^2 Sin[x]^2)^(-1/2),x},         (* GEN *)
{Cos[x]^n (1-k^2 Sin[x]^2)^(-1/2),x},         (* GEN *)
{Tan[x]^n (1-k^2 Sin[x]^2)^(-1/2),x},         (* GEN *)
{Cot[x]^n (1-k^2 Sin[x]^2)^(-1/2),x},        (* GEN *) 
(*2.583*)
{(1-k^2 Sin[x]^2)^(1/2),x},                                            
{Sin[x] (1-k^2 Sin[x]^2)^(1/2),x},                                    
{Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},
{Sin[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},                     
{Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},
{Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},                                
{Sin[x]^3 (1-k^2 Sin[x]^2)^(1/2),x},                                              
{Sin[x]^2 Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},
{Sin[x] Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},                        
{Cos[x]^3 (1-k^2 Sin[x]^2)^(1/2),x},                                              
{Sin[x]^4 (1-k^2 Sin[x]^2)^(1/2),x},                         
{Sin[x]^3 Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},  
{Sin[x]^2 Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},                      
{Sin[x] Cos[x]^3 (1-k^2 Sin[x]^2)^(1/2),x},                       
{Cos[x]^4 (1-k^2 Sin[x]^2)^(1/2),x},                              
{Sin[x]^5 (1-k^2 Sin[x]^2)^(1/2),x},                              
{Sin[x]^4 Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},
{Sin[x]^3 Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},                      
{Sin[x]^2 Cos[x]^3 (1-k^2 Sin[x]^2)^(1/2),x},                  
{Sin[x] Cos[x]^4 (1-k^2 Sin[x]^2)^(1/2),x},                        
{Cos[x]^5 (1-k^2 Sin[x]^2)^(1/2),x},                               
{(1-k^2 Sin[x]^2)^(3/2),x},                                        
{Sin[x] (1-k^2 Sin[x]^2)^(3/2),x},                                
{Cos[x] (1-k^2 Sin[x]^2)^(3/2),x},
{Sin[x]^2 (1-k^2 Sin[x]^2)^(3/2),x},                               
{Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(3/2),x},
{Cos[x]^2 (1-k^2 Sin[x]^2)^(3/2),x},                          
{Sin[x]^3 (1-k^2 Sin[x]^2)^(3/2),x},                              
{Sin[x]^2 Cos[x] (1-k^2 Sin[x]^2)^(3/2),x},
{Sin[x] Cos[x]^2 (1-k^2 Sin[x]^2)^(3/2),x},                        
{Cos[x]^3 (1-k^2 Sin[x]^2)^(3/2),x},                              
{Sin[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                    
{Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                           
{Sin[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                             
{Sin[x]^(-1) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},            
{Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                          
{Sin[x] Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                      
{Sin[x]^(-1) Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},                
{Sin[x]^(-3) (1-k^2 Sin[x]^2)^(1/2),x},                        
{Sin[x]^(-2) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                   
{Sin[x]^(-1) Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                  
{Cos[x]^(-3) (1-k^2 Sin[x]^2)^(1/2),x},                              
{Sin[x] Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                        
{Sin[x]^(-2) Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},                       
{Sin[x]^2 Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                     
{Sin[x]^(-1) Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},                     
{Sin[x]^(-4) (1-k^2 Sin[x]^2)^(1/2),x},                             
{Sin[x]^(-3) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},         
{Sin[x]^(-2) Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                   
{Sin[x]^(-1) Cos[x]^(-3) (1-k^2 Sin[x]^2)^(1/2),x},         
{Cos[x]^(-4) (1-k^2 Sin[x]^2)^(1/2),x},                             
{Sin[x] Cos[x]^(-3) (1-k^2 Sin[x]^2)^(1/2),x},            
{Sin[x]^(-3) Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},                  
{Sin[x]^2 Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                    
{Sin[x]^(-2) Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},
                     
{Sin[x]^3 Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                (* hangs FS *)        
{Sin[x]^(-1) Cos[x]^3 (1-k^2 Sin[x]^2)^(1/2),x},                (* hangs FS *)
       
{Sin[x]^(-5) (1-k^2 Sin[x]^2)^(1/2),x},                              
{Sin[x]^(-4) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                 
{Sin[x]^(-3) Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                 
{Sin[x]^(-2) Cos[x]^(-3) (1-k^2 Sin[x]^2)^(1/2),x},                     
{Sin[x]^(-1) Cos[x]^(-4) (1-k^2 Sin[x]^2)^(1/2),x},               
{Cos[x]^(-5) (1-k^2 Sin[x]^2)^(1/2),x},                           
{Sin[x] Cos[x]^(-4) (1-k^2 Sin[x]^2)^(1/2),x},
{Sin[x]^(-4) Cos[x] (1-k^2 Sin[x]^2)^(1/2),x},
{Sin[x]^2 Cos[x]^(-3) (1-k^2 Sin[x]^2)^(1/2),x},                    
{Sin[x]^(-3) Cos[x]^2 (1-k^2 Sin[x]^2)^(1/2),x},    
{Sin[x]^3 Cos[x]^(-2) (1-k^2 Sin[x]^2)^(1/2),x},                      
{Sin[x]^(-2) Cos[x]^3 (1-k^2 Sin[x]^2)^(1/2),x},    
{Sin[x]^4 Cos[x]^(-1) (1-k^2 Sin[x]^2)^(1/2),x},                     
{Sin[x]^(-1) Cos[x]^4 (1-k^2 Sin[x]^2)^(1/2),x},                    
(*2.584*)
{(1-k^2 Sin[x]^2)^(-1/2),x},                                          
{Sin[x] (1-k^2 Sin[x]^2)^(-1/2),x},                                 
{Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                                  
{Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                                
{Sin[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                               
{Sin[x]^2 Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x] Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                       
{Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                                 
{Sin[x]^4 (1-k^2 Sin[x]^2)^(-1/2),x},                              
{Sin[x]^3 Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^2 Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                       
{Sin[x] Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                          
{Cos[x]^4 (1-k^2 Sin[x]^2)^(-1/2),x},                                
{Sin[x]^5 (1-k^2 Sin[x]^2)^(-1/2),x},                         
{Sin[x]^4 Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^3 Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                       
{Sin[x]^2 Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                        
{Sin[x] Cos[x]^4 (1-k^2 Sin[x]^2)^(-1/2),x},                          
{Cos[x]^5 (1-k^2 Sin[x]^2)^(-1/2),x},                              
{Sin[x]^6 (1-k^2 Sin[x]^2)^(-1/2),x},                                
{Sin[x]^5 Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^4 Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                      
{Sin[x]^3 Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                      
{Sin[x]^2 Cos[x]^4 (1-k^2 Sin[x]^2)^(-1/2),x},                     
{Sin[x] Cos[x]^5 (1-k^2 Sin[x]^2)^(-1/2),x},                      
{Cos[x]^6 (1-k^2 Sin[x]^2)^(-1/2),x},                              
{Sin[x]^7 (1-k^2 Sin[x]^2)^(-1/2),x},                             
{Sin[x]^6 Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^5 Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                     
{Sin[x]^4 Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                     
{Sin[x]^3 Cos[x]^4 (1-k^2 Sin[x]^2)^(-1/2),x},                  
{Sin[x]^2 Cos[x]^5 (1-k^2 Sin[x]^2)^(-1/2),x},             
{Sin[x] Cos[x]^6 (1-k^2 Sin[x]^2)^(-1/2),x},                    
{Cos[x]^7 (1-k^2 Sin[x]^2)^(-1/2),x},                              
{(1-k^2 Sin[x]^2)^(-3/2),x},                                            
{Sin[x] (1-k^2 Sin[x]^2)^(-3/2),x},
{Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},
{Sin[x]^2 (1-k^2 Sin[x]^2)^(-3/2),x},                              
{Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},
{Cos[x]^2 (1-k^2 Sin[x]^2)^(-3/2),x},                               
{Sin[x]^3 (1-k^2 Sin[x]^2)^(-3/2),x},                              
{Sin[x]^2 Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},
{Sin[x] Cos[x]^2 (1-k^2 Sin[x]^2)^(-3/2),x},                       
{Cos[x]^3 (1-k^2 Sin[x]^2)^(-3/2),x},                               
{Sin[x]^4 (1-k^2 Sin[x]^2)^(-3/2),x},                             
{Sin[x]^3 Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},
{Sin[x]^2 Cos[x]^2 (1-k^2 Sin[x]^2)^(-3/2),x},                    
{Sin[x] Cos[x]^3 (1-k^2 Sin[x]^2)^(-3/2),x},
{Cos[x]^4 (1-k^2 Sin[x]^2)^(-3/2),x},                               
{Sin[x]^5 (1-k^2 Sin[x]^2)^(-3/2),x},                            
{Sin[x]^4 Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},
{Sin[x]^3 Cos[x]^2 (1-k^2 Sin[x]^2)^(-3/2),x},                     
{Sin[x]^2 Cos[x]^3 (1-k^2 Sin[x]^2)^(-3/2),x},                    
{Sin[x] Cos[x]^4 (1-k^2 Sin[x]^2)^(-3/2),x},                         
{Cos[x]^5 (1-k^2 Sin[x]^2)^(-3/2),x},                             
{(1-k^2 Sin[x]^2)^(-5/2),x},                                           
{Sin[x] (1-k^2 Sin[x]^2)^(-5/2),x},
{Cos[x] (1-k^2 Sin[x]^2)^(-5/2),x},
{Sin[x]^2 (1-k^2 Sin[x]^2)^(-5/2),x},                                 
{Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(-5/2),x},
{Cos[x]^2 (1-k^2 Sin[x]^2)^(-5/2),x},                               
{Sin[x]^3 (1-k^2 Sin[x]^2)^(-5/2),x},
{Sin[x]^2 Cos[x] (1-k^2 Sin[x]^2)^(-5/2),x},
{Sin[x] Cos[x]^2 (1-k^2 Sin[x]^2)^(-5/2),x},
{Cos[x]^3 (1-k^2 Sin[x]^2)^(-5/2),x},
{Sin[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                             
{Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                             
{Sin[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                             
{Sin[x]^(-1) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},             
{Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                             
{Sin[x] Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},               
{Sin[x]^(-1) Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},                  
{Sin[x]^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},                   
{Sin[x]^(-2) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},               
{Sin[x]^(-1) Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                 
{Cos[x]^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},                            
{Sin[x] Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^(-2) Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^2 Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                 
{Sin[x]^(-1) Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                      
{Sin[x]^(-4) (1-k^2 Sin[x]^2)^(-1/2),x},                             
{Sin[x]^(-3) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},          
{Sin[x]^(-2) Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                  
{Sin[x]^(-1) Cos[x]^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},            
{Cos[x]^(-4) (1-k^2 Sin[x]^2)^(-1/2),x},                          
{Sin[x] Cos[x]^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},           
{Sin[x]^(-3) Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},                
{Sin[x]^2 Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},              
{Sin[x]^(-2) Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                  
{Sin[x]^3 Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},         (* hangs FS *)       
{Sin[x]^(-1) Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},         (* hangs FS *) 
      
{Sin[x]^(-5) (1-k^2 Sin[x]^2)^(-1/2),x},                           
{Sin[x]^(-4) Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                  
{Sin[x]^(-3) Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                 
{Sin[x]^(-2) Cos[x]^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},                   
{Sin[x]^(-1) Cos[x]^(-4) (1-k^2 Sin[x]^2)^(-1/2),x},               
{Cos[x]^(-5) (1-k^2 Sin[x]^2)^(-1/2),x},                               
{Sin[x] Cos[x]^(-4) (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^(-4) Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^2 Cos[x]^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},                   
{Sin[x]^(-3) Cos[x]^2 (1-k^2 Sin[x]^2)^(-1/2),x},                      
{Sin[x]^3 Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                      
{Sin[x]^(-2) Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                       
{Sin[x]^4 Cos[x]^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                     
{Sin[x]^(-1) Cos[x]^4 (1-k^2 Sin[x]^2)^(-1/2),x},                       
(*2.585*)
 {(a+Sin[x])^(p+3) (1-k^2 Sin[x]^2)^(-1/2),x}, (* *** Return GENERICALLY *** *) {(a+Sin[x]) (1-k^2 Sin[x]^2)^(-1/2),x},                               
{(a+Sin[x])^2 (1-k^2 Sin[x]^2)^(-1/2),x},                  (* hangs FS *)                         
{(a+Sin[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},               (* hangs FS *)            
{Sin[x] (a^2-Sin[x]^2)^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},    (* hangs FS *)                   
(*2.586*)
 {(a+Sin[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},  (* *** Return GENERICALLY *** *)
{(a+Sin[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},               (* hangs FS *)       
{(a+Sin[x])^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},               (* hangs FS *) 
*)
Test={
 {(1+Sin[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},  (* *** Return GENERICALLY *** *)
 {(1-Sin[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},  (* *** Return GENERICALLY *** *)

{(1+Sin[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                            
{(1-Sin[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                        
{(1+Sin[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                       
{(1-Sin[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                         
 {(1+k Sin[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},(* *** Return GENERICALLY *** *)
 {(1-k Sin[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},(* *** Return GENERICALLY *** *)
{(1+k Sin[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                        
{(1-k Sin[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                       
{(1+k Sin[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},   (* Nume 2.2 *)                     
{(1-k Sin[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},   (* Nume 2.2 *)                     
(*2.587*)
 {(b+Cos[x])^(p+3) (1-k^2 Sin[x]^2)^(-1/2),x}, (* *** Return GENERICALLY *** *)
{(b+Cos[x]) (1-k^2 Sin[x]^2)^(-1/2),x},                              
{(b+Cos[x])^2 (1-k^2 Sin[x]^2)^(-1/2),x},                           
{(b+Cos[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                        
{Cos[x] (1-b^2-Sin[x]^2)^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},
(*2.588*)
 {(b+Cos[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},  (* *** Return GENERICALLY *** *)
{(b+Cos[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                 
{(b+Cos[x])^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},                    
(*2.589*)
 {(c+Tan[x])^(p+3) (1-k^2 Sin[x]^2)^(-1/2),x}, (* *** Return GENERICALLY *** *)
{(c+Tan[x]) (1-k^2 Sin[x]^2)^(-1/2),x},                        
{(c+Tan[x])^2 (1-k^2 Sin[x]^2)^(-1/2),x},                      
{(c+Tan[x])^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                     
{Sin[x] Cos[x] (c^2-(1+c^2) Sin[x]^2)^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},
(*2.591*)
 {(c+Tan[x])^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},  (* *** Return GENERICALLY *** *)
{(c+Tan[x])^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},     (* Ret2.2 *)
{(c+Tan[x])^(-3) (1-k^2 Sin[x]^2)^(-1/2),x},                    
(*2.592*)
 {(a+Sin[x]^2)^n (1-k^2 Sin[x]^2)^(-1/2),x},   (* *** Return GENERICALLY *** *)
{(a+Sin[x]^2)^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                  
{Sin[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                           
 {(h+g Sin[x]^2)^(-n) (1-k^2 Sin[x]^2)^(-1/2),x},(* ** Return GENERICALLY ** *)
(*2.593*)
 {(b+Cos[x]^2)^n (1-k^2 Sin[x]^2)^(-1/2),x},   (* *** Return GENERICALLY *** *)
{(b+Cos[x]^2)^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                   
{Cos[x]^(-2) (1-k^2 Sin[x]^2)^(-1/2),x},                            
(*2.594*)
 {(c+Tan[x]^2)^n (1-k^2 Sin[x]^2)^(-1/2),x},   (* *** Return GENERICALLY *** *)
{(c+Tan[x]^2)^(-1) (1-k^2 Sin[x]^2)^(-1/2),x},                 
(*2.595*)
{(1-p^2 Sin[x]^2)^(-1/2),x},                                         
{(1-p^2 Sin[x]^2)^(1/2),x},                                          
{(1-r^2 Sin[x]^2)^(-1) (1-p^2 Sin[x]^2)^(-1/2),x},    
(*2.596*)
{Cos[x]^4 (1-p^2 Sin[x]^2)^(-1/2),x},                                
{Cos[x]^(-2) (1-p^2 Sin[x]^2)^(1/2),x},                              
{(1-p^2 Sin[x]^2)^(-3/2),x},                                        
{((1-p^2 Sin[x]^2)^3)^(-1/2),x},                                    
(*2.597*)
{(1+p^2 Sin[x]^2)^(-1/2),x},                                         
{(1+p^2 Sin[x]^2)^(1/2),x},                                           
{(1+(p^2 -r^2 p^2 -r^2) Sin[x]^2)^(-1)(1+p^2 Sin[x]^2)^(1/2),x},     
{Sin[x] (1+p^2 Sin[x]^2)^(-1/2),x},                                 
{Cos[x] (1+p^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^(-1) (1+p^2 Sin[x]^2)^(-1/2),x},                             
{Cos[x]^(-1) (1+p^2 Sin[x]^2)^(-1/2),x},                               
{Tan[x] (1+p^2 Sin[x]^2)^(-1/2),x},                              
{Cot[x] (1+p^2 Sin[x]^2)^(-1/2),x},                            
(*2.598*)
{Tan[x]^2 (1+p^2 Sin[x]^2)^(-1/2),x},                               
{(1+p^2 Sin[x]^2)^(-3/2),x},                                      
{((1+p^2 Sin[x]^2)^3)^(-1/2),x},                                  
(*2.599*)
{(-1+a^2 Sin[x]^2)^(-1/2),x},                                       
{(-1+a^2 Sin[x]^2)^(1/2),x},                                       
{(1-r^2 Sin[x]^2)^(-1) (-1+a^2 Sin[x]^2)^(-1/2),x},  
{Sin[x] (-1+a^2 Sin[x]^2)^(-1/2),x},                               
{Cos[x] (-1+a^2 Sin[x]^2)^(-1/2),x},
{Sin[x]^(-1) (-1+a^2 Sin[x]^2)^(-1/2),x},                              
{Cos[x]^(-1) (-1+a^2 Sin[x]^2)^(-1/2),x},                         
{Tan[x] (-1+a^2 Sin[x]^2)^(-1/2),x},                 
{Cot[x] (-1+a^2 Sin[x]^2)^(-1/2),x},                          
(*2.611*)
{Sin[x]^2 (-1+a^2 Sin[x]^2)^(-1/2),x},                               
{(-1+a^2 Sin[x]^2)^(-5/2),x},                                       
{((-1+a^2 Sin[x]^2)^5)^(-1/2),x},                                
{Sin[x]^(-1) Cos[x]^(-1) (-1+a^2 Sin[x]^2)^(-1/2),x},            
(*2.612*)
{(1-k^2 Cos[x]^2)^(-1/2),x},                                            
{(1-k^2 Cos[x]^2)^(1/2),x},                                            
(*2.614*)
{(1+p^2 Cos[x]^2)^(-1/2),x},                                         
{(1+p^2 Cos[x]^2)^(1/2),x},                                           
(*2.615*)
{(-1+a^2 Cos[x]^2)^(-1/2),x},                                         
{(-1+a^2 Cos[x]^2)^(1/2),x},                                         
(*2.616*)
{((1-p^2 Sin[x]^2)(1-q^2 Sin[x]^2))^(-1/2),x},                                         
{Tan[x]^2 ((1-p^2 Sin[x]^2)(1-q^2 Sin[x]^2))^(-1/2),x},     (* Ret2.2 *)                                 
{Tan[x]^4 ((1-p^2 Sin[x]^2)(1-q^2 Sin[x]^2))^(-1/2),x},     (* Ret2.2 *)                           
{Sin[x]^2 ((1-p^2 Sin[x]^2)(1-q^2 Sin[x]^2)^3)^(-1/2),x},   (* Ret2.2 *)                      
{Cos[x]^2 ((1-p^2 Sin[x]^2)^3(1-q^2 Sin[x]^2))^(-1/2),x},   (* Ret2.2 *)                           
{Cos[x]^4 ((1-p^2 Sin[x]^2)^5(1-q^2 Sin[x]^2))^(-1/2),x},   (* Ret2.2 *)              
{(1-p^2 Sin[x]^2)^(-1) ((1-q^2 Sin[x]^2)/(1-p^2 Sin[x]^2))^(1/2),x}, 
                                                    (* Ret2.2 *)                                                             
{((1-p^2 Sin[x]^2)/(1-q^2 Sin[x]^2)^3)^(1/2),x},     
{(1+(p^2 r^2-p^2-r^2) Sin[x]^2)^(-1) ((1-p^2 Sin[x]^2)/(1-
  q^2 Sin[x]^2))^(1/2),x},                          (* Ret2.2 *)                                  
(*2.617*)
{(a+b Sin[x]+c Cos[x])^(-1/2),x},                                 
{Sin[x] (a+b Sin[x]+c Cos[x])^(-1/2),x},                         
{(b Cos[x]-c Sin[x]) (a+b Sin[x]+c Cos[x])^(-1/2),x},
{(Sqrt[b^2+c^2]+b Sin[x]+c Cos[x]) (a+b Sin[x]+c Cos[x])^(-1/2),x},                                                                               
{(a+b Sin[x]+c Cos[x])^(1/2),x},                                 
(*2.618*)
{Cos[2 a x]^(-1/2),x},                                             
{Cos[a x]^2 Cos[2 a x]^(-1/2),x},                             
{Cos[a x]^(-2) Cos[2 a x]^(-1/2),x},                           
{Cos[a x]^(-4) Cos[2 a x]^(-1/2),x},                            
{Tan[a x]^2 Cos[2 a x]^(-1/2),x},                              
{Tan[a x]^4 Cos[2 a x]^(-1/2),x},                                       
{(1-2 r^2 Sin[a x]^2)^(-1) Cos[2 a x]^(-1/2),x},               
{Cos[2 a x]^(-3/2),x},                                          
{(Cos[2 a x]^3)^(-1/2),x},                                  
{Sin[a x]^2 Cos[2 a x]^(-3/2),x},                              
{Cos[2 a x]^(-5/2),x},                                                 
{(Cos[2 a x]^5)^(-1/2),x},                                   
{Cos[2 a x]^(1/2),x},                                           
{Cos[a x]^(-2) Cos[2 a x]^(1/2),x},                            
(*2.619*)
{(-Cos[2 a x])^(-1/2),x},                                            
{Cos[a x]^2 (-Cos[2 a x])^(-1/2),x},                             
{Cos[a x]^4 (-Cos[2 a x])^(-1/2),x},                                 
{Sin[a x]^(-2) (-Cos[2 a x])^(-1/2),x},                              
{Sin[a x]^(-4) (-Cos[2 a x])^(-1/2),x},                             
{Cot[a x]^2 (-Cos[2 a x])^(-1/2),x},                                  
{(1-2 r^2 Cos[a x]^2)^(-1) (-Cos[2 a x])^(-1/2),x},                  
{(-Cos[2 a x]^3)^(-1/2),x},                          
{Cos[a x]^2 (-Cos[2 a x]^3)^(-1/2),x},              
{(-Cos[2 a x]^5)^(-1/2),x},                         
{(-Cos[2 a x])^(1/2),x},                                           
(*2.621*)
{Sin[2 a x]^(-1/2),x},                                                 
{Sin[a x] Sin[2 a x]^(-1/2),x},                                 
{Sin[a x] (1+Sin[a x]+Cos[a x])^(-1) Sin[2 a x]^(-1/2),x},        
{Sin[a x] (1-Sin[a x]+Cos[a x])^(-1) Sin[2 a x]^(-1/2),x},        
{(1+Cos[a x]) (1+Sin[a x]+Cos[a x])^(-1) Sin[2 a x]^(-1/2),x},    
{(1+Cos[a x]) (1-Sin[a x]+Cos[a x])^(-1) Sin[2 a x]^(-1/2),x},    
{(1-Sin[a x]+Cos[a x]) (1+Sin[a x]+Cos[a x])^(-1) Sin[2 a x]^(-1/2),x},                                                                           
{(1+Sin[a x]+Cos[a x]) (1+Cos[a x]+(1-2 r^2) Sin[a x])^(-1) *
  Sin[2 a x]^(-1/2),x},                 (* Ret2.2 *)                                                  
(*2.631*)
 {x^r Sin[x]^p Cos[x]^q,x},        (* ********* Return GENERICALLY ********* *)
 {x^m Sin[x]^n,x},                 (* ********* Return GENERICALLY ********* *)
 {x^m Cos[x]^n,x},                 (* ********* Return GENERICALLY ********* *)
(*2.632*)   
{x^(m-1) Sin[b x],x},                   (* Ret2.2 *)                                          
{x^(m-1) Cos[b x],x},                   (* Ret2.2 *)                                          
(*2.633*)
{x^n Sin[a x],x},                       (* Ret2.2 *)                                         
{x^n Cos[a x],x},                       (* Ret2.2 *)                                        
(*2.635*)
{(a+b x) Sin[k x],x},
{(a+b x) Cos[k x],x},
{(a+b x)^2 Sin[k x],x},
{(a+b x)^2 Cos[k x],x},
{(a+b x)^3 Sin[k x],x},
{(a+b x)^3 Cos[k x],x},
{(a+b x)^4 Sin[k x],x},
{(a+b x)^4 Cos[k x],x},
{(a+b x)^5 Sin[k x],x},
{(a+b x)^5 Cos[k x],x},
{(a+b x)^6 Sin[k x],x},
{(a+b x)^6 Cos[k x],x},
(*2.636*)
{x^n Sin[x]^2,x},                       (* Ret2.2 *)                                               
{x^n Cos[x]^2,x},                       (* Ret2.2 *)                                                 
{x Sin[x]^2,x},
{x^2 Sin[x]^2,x},
{x Cos[x]^2,x},
{x^2 Cos[x]^2,x},
(*2.637*)
{x^n Sin[x]^3,x},                       (* Ret2.2 *)                                             
{x^n Cos[x]^3,x},                       (* Ret2.2 *)                                              
{x Sin[x]^3,x},
{x^2 Sin[x]^3,x},
{x Cos[x]^3,x},
{x^2 Cos[x]^3,x},
(*2.638*)
 {x^(-p) Sin[x]^q,x},              (* ********* Return GENERICALLY ********* *)
 {x^(-p) Cos[x]^q,x},              (* ********* Return GENERICALLY ********* *)
{x^(-p) Sin[x],x},                      (* Ret2.2 *)                                             
{x^(-p) Cos[x],x},                      (* Ret2.2 *)                                              
(*2.639*)
{x^(-2n) Sin[x],x},                     (* Ret2.2 *)                                            
{x^(-2n-1) Sin[x],x},                   (* Ret2.2 *)                                            
{x^(-2n) Cos[x],x},                     (* Ret2.2 *)                                         
{x^(-2n-1) Cos[x],x},                   (* Ret2.2 *)                                       
(*2.641*)
{(a+b x)^(-1) Sin[k x],x},
{(a+b x)^(-1) Cos[k x],x},
{(a+b x)^(-2) Sin[k x],x},
{(a+b x)^(-2) Cos[k x],x},
{(a+b x)^(-3) Sin[k x],x},
{(a+b x)^(-3) Cos[k x],x},
{(a+b x)^(-4) Sin[k x],x},
{(a+b x)^(-4) Cos[k x],x},
{(a+b x)^(-5) Sin[k x],x},
{(a+b x)^(-5) Cos[k x],x},
{(a+b x)^(-6) Sin[k x],x},
{(a+b x)^(-6) Cos[k x],x},
(*2.642*)
 {x^(-1) Sin[x]^(2m),x},           (* ********* Return GENERICALLY ********* *)
 {x^(-1) Sin[x]^(2m+1),x},         (* ********* Return GENERICALLY ********* *)
 {x^(-1) Cos[x]^(2m),x},           (* ********* Return GENERICALLY ********* *)
 {x^(-1) Cos[x]^(2m+1),x},         (* ********* Return GENERICALLY ********* *)
 {x^(-2) Sin[x]^(2m),x},           (* ********* Return GENERICALLY ********* *)
 {x^(-2) Sin[x]^(2m+1),x},         (* ********* Return GENERICALLY ********* *)
 {x^(-2) Cos[x]^(2m),x},           (* ********* Return GENERICALLY ********* *)
 {x^(-2) Cos[x]^(2m+1),x},         (* ********* Return GENERICALLY ********* *)
(*2.643*)
 {x^p Sin[x]^(-q),x},              (* ********* Return GENERICALLY ********* *)
 {x^p Cos[x]^(-q),x},              (* ********* Return GENERICALLY ********* *)
 {x^n Sin[x]^(-1),x},              (* ********* Return GENERICALLY ********* *)
 {x^(-n) Sin[x]^(-1),x},           (* ********* Return GENERICALLY ********* *)
 {x^n Cos[x]^(-1),x},              (* ********* Return GENERICALLY ********* *)
 {x^(-n) Cos[x]^(-1),x},           (* ********* Return GENERICALLY ********* *)
 {x^n Sin[x]^(-2),x},              (* ********* Return GENERICALLY ********* *)
 {x^(-n) Sin[x]^(-2),x},           (* ********* Return GENERICALLY ********* *)
 {x^n Cos[x]^(-2),x},              (* ********* Return GENERICALLY ********* *)
 {x^(-n) Cos[x]^(-2),x},           (* ********* Return GENERICALLY ********* *)
(*2.644*)
{x Sin[x]^(-2n),x},                     (* Ret2.2 *)   
{x Sin[x]^(-2n-1),x},                   (* Ret2.2 *)   
{x Cos[x]^(-2n),x},                     (* Ret2.2 *)   
{x Cos[x]^(-2n-1),x},                   (* Ret2.2 *)   
{x Sin[x]^(-1),x},                      (* Ret2.2 *)                                     
{x Cos[x]^(-1),x},                      (* Ret2.2 *)                                           
{x Sin[x]^(-2),x},               
{x Cos[x]^(-2),x},
{x Sin[x]^(-3),x},                      (* Ret2.2 *)                                          
{x Cos[x]^(-3),x},                      (* Ret2.2 *)                                          
{x Sin[x]^(-4),x},               
{x Cos[x]^(-4),x},
{x Sin[x]^(-5),x},                      (* Ret2.2 *)                                       
{x Cos[x]^(-5),x},                      (* Ret2.2 *)                                      
(*2.645*)
 {x^p Sin[x]^(2m) Cos[x]^(-n),x},  (* ********* Return GENERICALLY ********* *)
 {x^p Sin[x]^(2m+1) Cos[x]^(-n),x},(* ********* Return GENERICALLY ********* *)
 {x^p Sin[x] Cos[x]^(-n),x},       (* ********* Return GENERICALLY ********* *)
 {x^p Sin[x]^(-n) Cos[x]^(2m),x},  (* ********* Return GENERICALLY ********* *)
 {x^p Sin[x]^(-n) Cos[x]^(2m+1),x},(* ********* Return GENERICALLY ********* *)
 {x^p Sin[x]^(-n) Cos[x],x},       (* ********* Return GENERICALLY ********* *)
{x Sin[x]^(-2) Cos[x],x},
{x Sin[x] Cos[x]^(-2),x},
(*2.646*)
 {x^p Tan[x],x},                   (* ********* Return GENERICALLY ********* *)
 {x^p Cot[x],x},                   (* ********* Return GENERICALLY ********* *)
{x Tan[x]^2,x},
{x Cot[x]^2,x},
(*2.647*)
 {x^n Cos[x] (a+b Sin[x])^(-m),x}, (* ********* Return GENERICALLY ********* *)
 {x^n Sin[x] (a+b Cos[x])^(-m),x}, (* ********* Return GENERICALLY ********* *)
{x (1+Sin[x])^(-1),x},
{x (1-Sin[x])^(-1),x},
{x (1+Cos[x])^(-1),x},
{x (1-Cos[x])^(-1),x},
{x Cos[x] (1+Sin[x])^(-2),x},
{x Cos[x] (1-Sin[x])^(-2),x},
{x Sin[x] (1+Cos[x])^(-2),x},
{x Sin[x] (1-Cos[x])^(-2),x},
(*2.648*)
{(x+Sin[x]) (1+Cos[x])^(-1),x},
{(x-Sin[x]) (1-Cos[x])^(-1),x},
(*2.649*)
{x^2 ((a x-b) Sin[x]+(a+b x) Cos[x])^(-2),x},
(*2.651*)
{(a+(a x+b) Tan[x])^(-2),x},
(*2.652*)
{x Cos[x+t]^(-1) Cos[x-t]^(-1),x},      (* Ret2.2 *)                                                                               
(*2.653*)
{x^(-1/2) Sin[x],x},
{x^(-1/2) Cos[x],x},
(*2.654*)
{x Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},                    
{x Sin[x]^3 Cos[x] (1-k^2 Sin[x]^2)^(-1/2),x},            
{x Sin[x] Cos[x]^3 (1-k^2 Sin[x]^2)^(-1/2),x},                
{x Sin[x] (1-k^2 Sin[x]^2)^(-3/2),x},                                
{x Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},                                
{x Sin[x] Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},                         
{x Sin[x]^3 Cos[x] (1-k^2 Sin[x]^2)^(-3/2),x},                 
{x Sin[x] Cos[x]^3 (1-k^2 Sin[x]^2)^(-3/2),x},                
(*2.655*)
{x^p Sin[x^2],x},                       (* Ret2.2 *)                                               
{x^p Cos[x^2],x},                       (* Ret2.2 *)                                                
{x Sin[x^2],x},
{x Cos[x^2],x},
{x^2 Sin[x^2],x},
{x^2 Cos[x^2],x},
{x^3 Sin[x^2],x},
{x^3 Cos[x^2],x},
(*2.661*)

{Exp[a x] Sin[x]^p Cos[x]^q,x},   (* GEN *)
(*2.662*)
{Exp[a x] Sin[b x]^n,x},                (* Ret2.2 *)                                         
{Exp[a x] Cos[b x]^n,x},                (* Ret2.2 *)                                        
(*2.663*)
{Exp[a x] Sin[b x],x},
{Exp[a x] Sin[b x]^2,x},
{Exp[a x] Cos[b x],x},
{Exp[a x] Cos[b x]^2,x},
(*2.664*)
{Exp[a x] Sin[b x] Cos[c x],x},
{Exp[a x] Sin[b x]^2 Cos[c x],x},
{Exp[a x] Sin[b x] Cos[c x]^2,x},
(*2.665*)
{Exp[a x] Sin[b x]^(-p),x},             (* Ret2.2 *)                            {Exp[a x] Cos[b x]^(-p),x},             (* Ret2.2 *)                            (*2.666*)
{Exp[a x] Tan[x]^p,x},            (* GEN *)
{Exp[a x] Cot[x]^p,x},            (* GEN *) 

{Exp[a x] Tan[x],x},                    (* Ret2.2 *)                                            
{Exp[a x] Tan[x]^2,x},                  (* Ret2.2 *)                                                
{Exp[a x] Cot[x],x},                    (* Ret2.2 *)                                                 
{Exp[a x] Cot[x]^2,x},                  (* Ret2.2 *)                                               
(*2.667*)
{x^p Exp[a x] Sin[b x],x},              (* Ret2.2 *)                                               
{x^p Exp[a x] Cos[b x],x},              (* Ret2.2 *)                                                
{x Exp[a x] Sin[b x],x},
{x Exp[a x] Cos[b x],x},
{x^2 Exp[a x] Sin[b x],x},
{x^2 Exp[a x] Cos[b x],x},
(*2.671*)
{Sinh[a x+b] Sin[c x+d],x},
{Sinh[a x+b] Cos[c x+d],x},
{Cosh[a x+b] Sin[c x+d],x},
{Cosh[a x+b] Cos[c x+d],x},
(*2.672*)
{Sinh[x] Sin[x],x},
{Sinh[x] Cos[x],x},
{Cosh[x] Sin[x],x},
{Cosh[x] Cos[x],x},
(*2.673*)
 {Sinh[a x+b]^(2m) Sin[c x+d]^(2n),x},     (* ***** Return GENERICALLY ***** *) 
 {Sinh[a x+b]^(2m) Sin[c x+d]^(2n-1),x},   (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m-1) Sin[c x+d]^(2n),x},   (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m) Sin[c x+d]^(2n-1),x},   (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m-1) Sin[c x+d]^(2n),x},   (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m-1) Sin[c x+d]^(2n-1),x}, (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m) Cos[c x+d]^(2n),x},     (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m) Cos[c x+d]^(2n-1),x},   (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m-1) Cos[c x+d]^(2n),x},   (* ***** Return GENERICALLY ***** *)
 {Sinh[a x+b]^(2m-1) Cos[c x+d]^(2n-1),x}, (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m) Sin[c x+d]^(2n),x},     (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m-1) Sin[c x+d]^(2n),x},   (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m) Sin[c x+d]^(2n-1),x},   (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m-1) Sin[c x+d]^(2n-1),x}, (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m) Cos[c x+d]^(2n),x},     (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m-1) Cos[c x+d]^(2n),x},   (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m) Cos[c x+d]^(2n-1),x},   (* ***** Return GENERICALLY ***** *)
 {Cosh[a x+b]^(2m-1) Cos[c x+d]^(2n-1),x}, (* ***** Return GENERICALLY ***** *)
(*2.674*)
{Exp[a x] Sinh[b x] Sin[c x],x},
{Exp[a x] Sinh[b x] Cos[c x],x},
{Exp[a x] Cosh[b x] Sin[c x],x},
{Exp[a x] Cosh[b x] Cos[c x],x},

(*****************************************************************************)
(*               Logarithm and Inverse-Hyperbolic functions                  *)
(*****************************************************************************)
(*2.711*)
{Log[x]^m,x},                           (* Ret2.2 *)                                                   
(*2.721*)
{x^(-1) Log[x]^m,x},
{x^(-1) Log[x]^(-1),x},
(*2.722*)
{x^n Log[x]^m,x},                       (* hangs 2.2 *)                                                 
(*2.723*)
{x^n Log[x],x},
{x^n Log[x]^2,x},
{x^n Log[x]^3,x},
(*2.724*)
{x^n Log[x]^(-m),x},                    (* hangs 2.2 *)                                                
{x^n Log[x]^(-1),x},
(*2.725*)
{(a+b x)^m Log[x],x},                   (* Ret2.2 *)                                                   
(*2.726*)
{(a+b x) Log[x],x},
{(a+b x)^2 Log[x],x},
{(a+b x)^3 Log[x],x},
(*2.727*)
{(a+b x)^(-m) Log[x],x},                (* Ret2.2 *)                                          
{(a+b x)^(-1) Log[x],x},
{(a+b x)^(-2) Log[x],x},
{(a+b x)^(-3) Log[x],x},
{(a+b x)^(-1/2) Log[x],x},
(*2.728*)
{x^m Log[a+b x],x},                     (* Ret2.2 *)                                                
{x^(-1) Log[a+b x],x},
(*2.729*)
{x^m Log[a+b x],x},                     (* Ret2.2 *)                                                                 
{x Log[a+b x],x},
{x^2 Log[a+b x],x},
{x^3 Log[a+b x],x},
(*2.731*)
{x^(2n) Log[x^2+a^2],x},                (* Ret2.2 *)                                                 
(*2.732*)
{x^(2n+1) Log[x^2+a^2],x},              (* Ret2.2 *)                                               
(*2.733*)
{Log[x^2+a^2],x},
{x Log[x^2+a^2],x},
{x^2 Log[x^2+a^2],x},
{x^3 Log[x^2+a^2],x},
{x^4 Log[x^2+a^2],x},
(*2.734*)
{x^(2n) Log[x^2-a^2],x},                (* Ret2.2 *)                                        
(*2.735*)
{x^(2n+1) Log[x^2-a^2],x},              (* Ret2.2 *)                                     
(*2.736*)
{Log[x^2-a^2],x},
{x Log[x^2-a^2],x},
{x^2 Log[x^2-a^2],x},
{x^3 Log[x^2-a^2],x},
{x^4 Log[x^2-a^2],x},
(*2.741*)
{ArcSinh[x/a],x},
{ArcCosh[x/a],x},
{ArcTanh[x/a],x},
{ArcCoth[x/a],x},
(*2.742*)
{x ArcSinh[x/a],x},
{x ArcCosh[x/a],x},
(*****************************************************************************)
(*                       Inverse Trigonometric functions                     *)
(*****************************************************************************)
(*2.811*)
{ArcSin[x/a]^n,x},                      (* Ret2.2 *)                                         
(*2.812*)
{ArcCos[x/a]^n,x},                      (* Ret2.2 *)                                                  
(*2.813*)
{ArcSin[x/a],x},                                      
{ArcSin[x/a]^2,x},
{ArcSin[x/a]^3,x},
(*2.814*)
{ArcCos[x/a],x},
{ArcCos[x/a]^2,x},
{ArcCos[x/a]^3,x},
(*2.821*)
{ArcCsc[x/a],x},
{ArcSec[x/a],x},
(*2.822*)
{ArcTan[x/a],x},
{ArcCot[x/a],x},
(*2.831*)
{x^n ArcSin[x/a],x},                    (* Ret2.2 *)                                     
(*2.832*)
{x^n ArcCos[x/a],x},                    (* Ret2.2 *)                                      
{x^(-1) ArcCos[x],x},                   (* Ret2.2 *)                                                                      
(*2.833*)
{x ArcSin[x/a],x},
{x ArcCos[x/a],x},
(*2.834*)
{x^(-2) ArcSin[x/a],x},
{x^(-2) ArcCos[x/a],x},
(*2.835*)
{(a+b x)^(-2) ArcSin[x],x},
(*2.836*)
{x (1+c x^2)^(-2) ArcSin[x],x},
(*2.837*)
{x (1-x^2)^(-1/2) ArcSin[x],x},
{x^2 (1-x^2)^(-1/2) ArcSin[x],x},
{x^3 (1-x^2)^(-1/2) ArcSin[x],x},
(*2.838*)
{(1-x^2)^(-3/2) ArcSin[x],x},
{((1-x^2)^3)^(-1/2) ArcSin[x],x},                                 
{x (1-x^2)^(-3/2) ArcSin[x],x},
{x ((1-x^2)^3)^(-1/2) ArcSin[x],x},                               
(*2.841*)
{x ArcSec[x/a],x},
{x^2 ArcSec[x/a],x},
{x ArcCsc[x/a],x},
(*2.851*)
{x^n ArcTan[x/a],x},                    (* Ret2.2 *)                                                
(*2.852*)
{x^n ArcCot[x/a],x},                    (* Ret2.2 *)                                                  
{x^(-1) ArcTan[x],x},
{x^(-1) ArcCot[x],x},
(*2.853*)
{x ArcTan[x/a],x},
{x ArcCot[x/a],x},
(*2.854*)
{x^(-2) ArcTan[x/a],x},
(*2.855*)
{(a+b x)^(-2) ArcTan[x],x},                         
(*2.856*)
{x (1+x^2)^(-1) ArcTan[x],x},           (* Ret2.2 *)                                             
{x^2 (1+x^2)^(-1) ArcTan[x],x},
{x^3 (1+x^2)^(-1) ArcTan[x],x},         (* Ret2.2 *)                                             
{x^4 (1+x^2)^(-1) ArcTan[x],x},
(*2.857*)
{(1+x^2)^(-n-1) ArcTan[x],x},           (* Ret2.2 *)           (* Ret FS *)
(*2.858*)
{x (1-x^2)^(-1/2) ArcTan[x],x},
(*2.859*)
{(a+b x^2)^(-3/2) ArcTan[x],x},
{((a+b x^2)^3)^(-1/2) ArcTan[x],x},
(*****************************************************************************)
(* Power and Algebraic functions (from definite integrals 436 RetCan int)    *)
(*****************************************************************************)
(*3.131*)
{((a-x)(b-x)(c-x))^(-1/2),x},                                                                        
{((a-x)(b-x)(x-c))^(-1/2),x},                                         
{((a-x)(x-b)(x-c))^(-1/2),x},                                      
{((x-a)(x-b)(x-c))^(-1/2),x},                                    
(*3.132*)
{x ((a-x)(b-x)(c-x))^(-1/2),x},                                   
{x ((a-x)(b-x)(x-c))^(-1/2),x},                                    
{x ((a-x)(x-b)(x-c))^(-1/2),x},                                    
{x ((x-a)(x-b)(x-c))^(-1/2),x},                                 
(*3.133*)
{((a-x)^3(b-x)(c-x))^(-1/2),x},                        
{((a-x)^3(b-x)(x-c))^(-1/2),x},
{((a-x)^3(x-b)(x-c))^(-1/2),x},
{((x-a)^3(x-b)(x-c))^(-1/2),x},
{((a-x)(b-x)^3(c-x))^(-1/2),x},
{((a-x)(b-x)^3(x-c))^(-1/2),x},
{((a-x)(x-b)^3(x-c))^(-1/2),x},
{((x-a)(x-b)^3(x-c))^(-1/2),x},
{((a-x)(b-x)(c-x)^3)^(-1/2),x},
{((a-x)(b-x)(x-c)^3)^(-1/2),x},
{((a-x)(x-b)(x-c)^3)^(-1/2),x},
{((x-a)(x-b)(x-c)^3)^(-1/2),x},
(*3.134*)
{((a-x)^5(b-x)(c-x))^(-1/2),x},
{((a-x)^5(b-x)(x-c))^(-1/2),x},
{((a-x)^5(x-b)(x-c))^(-1/2),x},
{((x-a)^5(x-b)(x-c))^(-1/2),x},
{((a-x)(b-x)^5(c-x))^(-1/2),x},
{((a-x)(b-x)^5(x-c))^(-1/2),x},
{((a-x)(x-b)^5(x-c))^(-1/2),x},
{((x-a)(x-b)^5(x-c))^(-1/2),x},
{((a-x)(b-x)(c-x)^5)^(-1/2),x},
{((a-x)(b-x)(x-c)^5)^(-1/2),x},
{((a-x)(x-b)(x-c)^5)^(-1/2),x},
{((x-a)(x-b)(x-c)^5)^(-1/2),x},
(*3.135*)
{((a-x)(b-x)^3(c-x)^3)^(-1/2),x},
{((a-x)(x-b)^3(x-c)^3)^(-1/2),x},
{((x-a)(x-b)^3(x-c)^3)^(-1/2),x},
{((a-x)^3(b-x)(c-x)^3)^(-1/2),x},                  
{((a-x)^3(b-x)(x-c)^3)^(-1/2),x},                  
{((a-x)^3(x-b)(x-c)^3)^(-1/2),x},
{((x-a)^3(x-b)(x-c)^3)^(-1/2),x},
{((a-x)^3(b-x)^3(c-x))^(-1/2),x},
{((a-x)^3(b-x)^3(x-c))^(-1/2),x},
{((x-a)^3(x-b)^3(x-c))^(-1/2),x},
(*3.136*)
{((a-x)^3(b-x)^3(c-x)^3)^(-1/2),x},               
{((x-a)^3(x-b)^3(x-c)^3)^(-1/2),x},                
(*3.137*)
{(r-x)^(-1)((a-x)(b-x)(c-x))^(-1/2),x},                                
{(r-x)^(-1)((a-x)(b-x)(x-c))^(-1/2),x},                             
{(x-r)^(-1)((a-x)(x-b)(x-c))^(-1/2),x},                            
{(x-r)^(-1)((x-a)(x-b)(x-c))^(-1/2),x},                          
(*3.138*)
{(x (1-x)(1-k^2 x))^(-1/2),x},                                      
{(x (1-x)(1-k^2+k^2 x))^(-1/2),x},                                 
{(x (1-x)(x-1+k^2))^(-1/2),x},                                     
{(x (1+x)(1+(1-k^2) x))^(-1/2),x},                                
{(x (1+x^2+2 (1-k^2-k^2) x))^(-1/2),x},                          
{(x ((1-k^2)(1+x^2)+2(1+k^2) x))^(-1/2),x},                        
{((x-a) ((x-m)^2+n^2))^(-1/2),x},                                  
{((a-x) ((x-m)^2+n^2))^(-1/2),x},                                  
(*3.139*)
{(1-x^3)^(-1/2),x},                                                  
{(x^3-1)^(-1/2),x},                                                 
{(1-x^3)^(1/2),x},                                                   
{x (1-x^3)^(-1/2),x},                                             
{x^m (1-x^3)^(-1/2),x},                 (* Ret2.2 *)                                                
{x (x^3-1)^(-1/2),x},                                              
{(1-x)^(-1) (1-x^3)^(-1/2),x},                                     
{(x-1)^(-1) (x^3-1)^(-1/2),x},                                     
{(1-x)(1+Sqrt[3]-x)^(-2) (1-x^3)^(-1/2),x},                                                                       
{(x-1)(1+Sqrt[3]-x)^(-2) (x^3-1)^(-1/2),x},                                                                         
{(1-x)(1-Sqrt[3]-x)^(-2) (1-x^3)^(-1/2),x},                       
{(x-1)(1-Sqrt[3]-x)^(-2) (x^3-1)^(-1/2),x},                          
{(x^2+x+1)(1+Sqrt[3]-x)^(-2) (1-x^3)^(-1/2),x},                  
{(x^2+x+1)(-1+Sqrt[3]+x)^(-2) (1-x^3)^(-1/2),x},                   
{(x^2+x+1)(-1+Sqrt[3]+x)^(-2) (x^3-1)^(-1/2),x},                    
{(x^2+x+1)(-1+Sqrt[3]+x)^(-2) (x^3-1)^(-1/2),x},                  
{(x-1)(x^2+x+1)^(-1) (x^3-1)^(-1/2),x},                              
{(1+Sqrt[3]-x)^2 ((1+Sqrt[3]-x)^2-4 Sqrt[3] p^2 (1-x))^(-1)(1-x^3)^(-1/2),x},
                                        (* Ret2.2 *)                                                               
{(1-Sqrt[3]-x)^2 ((1-Sqrt[3]-x)^2-4 Sqrt[3] p^2 (x-1))^(-1)(x^3-1)^(-1/2),x},                                           (* Ret2.2 *)            
(*3.141*)
{((a-x)/((b-x)(c-x)))^(1/2),x},                                     
{((a-x)/((b-x)(x-c)))^(1/2),x},                                      
{((a-x)/((x-b)(x-c)))^(1/2),x},                                    
{((x-a)/((x-b)(x-c)))^(1/2),x},                                    
{((b-x)/((a-x)(c-x)))^(1/2),x},                                    
{((b-x)/((a-x)(x-c)))^(1/2),x},                                   
{((x-b)/((a-x)(x-c)))^(1/2),x},                                     
{((x-b)/((x-a)(x-c)))^(1/2),x},                                    
{((c-x)/((a-x)(b-x)))^(1/2),x},                                     
{((x-c)/((a-x)(b-x)))^(1/2),x},                                     
{((x-c)/((a-x)(x-b)))^(1/2),x},                                    
{((x-c)/((x-a)(x-b)))^(1/2),x},                                      
{((b-x)(c-x)/(a-x))^(1/2),x},                                     
{((b-x)(x-c)/(a-x))^(1/2),x},                                    
{((x-b)(x-c)/(a-x))^(1/2),x},                                         
{((x-b)(x-c)/(a-x))^(1/2),x},                                        
{((x-b)(x-c)/(x-a))^(1/2),x},                                     
{((a-x)(c-x)/(b-x))^(1/2),x},                                      
{((a-x)(x-c)/(b-x))^(1/2),x},                                      
{((a-x)(x-c)/(x-b))^(1/2),x},                                    
{((x-a)(x-c)/(x-b))^(1/2),x},                                       
{((a-x)(b-x)/(c-x))^(1/2),x},                                       
{((a-x)(b-x)/(x-c))^(1/2),x},                                      
{((a-x)(x-b)/(x-c))^(1/2),x},                                      
{((x-a)(x-b)/(x-c))^(1/2),x},                                      
(*3.142*)
{((a-x)/((b-x)(c-x)^3))^(1/2),x},
{((a-x)/((b-x)(x-c)^3))^(1/2),x},
{((a-x)/((x-b)(x-c)^3))^(1/2),x},
{((x-a)/((x-b)(x-c)^3))^(1/2),x},
{((a-x)/((b-x)^3(c-x)))^(1/2),x},
{((a-x)/((b-x)^3(x-c)))^(1/2),x},
{((a-x)/((x-b)^3(x-c)))^(1/2),x},
{((x-a)/((x-b)^3(x-c)))^(1/2),x},
{((b-x)/((a-x)^3(c-x)))^(1/2),x},
{((b-x)/((a-x)^3(x-c)))^(1/2),x},
{((x-b)/((a-x)^3(x-c)))^(1/2),x},
{((x-b)/((x-a)^3(x-c)))^(1/2),x},
{((b-x)/((a-x)(c-x)^3))^(1/2),x},
{((b-x)/((a-x)(x-c)^3))^(1/2),x},
{((x-b)/((a-x)(x-c)^3))^(1/2),x},
{((x-b)/((x-a)(x-c)^3))^(1/2),x},
{((c-x)/((a-x)^3(b-x)))^(1/2),x},
{((x-c)/((a-x)^3(b-x)))^(1/2),x},
{((x-c)/((a-x)^3(x-b)))^(1/2),x},
{((x-c)/((x-a)^3(x-b)))^(1/2),x},
{((c-x)/((a-x)(b-x)^3))^(1/2),x},
{((x-c)/((a-x)(b-x)^3))^(1/2),x},
{((x-c)/((a-x)(x-b)^3))^(1/2),x},
{((x-c)/((x-a)(x-b)^3))^(1/2),x},
(*3.143*)
{(1+x^4)^(1/2),x},                                               
(*3.144*)
{(x (x-1) (x^2-x+1))^(-1/2),x},                                       
{(x^3 (x-1)^3(x^2-x+1))^(-1/2),x},                                   
{(2x-1)^2 (x^3(x-1)^3(x^2-x+1))^(-1/2),x},                                                     
{(x (x-1) (x^2-x+1)^3)^(-1/2),x},   
{(2x-1)^2 (x(x-1)(x^2-x+1)^3)^(-1/2),x},                                 
{(x (x-1)/(x^2-x+1)^3)^(1/2),x},                                             
{(2x-1)^(-2) (x (x-1)/(x^2-x+1))^(1/2),x},                                  
{(2x-1)^(-2) ((x^2-x+1)/(x (x-1)))^(1/2),x},                              
{(2x-1)^(-2) (x (x-1)(x^2-x+1))^(-1/2),x},                                
{(x^5 (x-1)^5 (x^2-x+1))^(-1/2),x},                                       
{(x (x-1) (x^2-x+1)^5)^(-1/2),x},                    
{(2x-1)^(-4) (x (x-1) (x^2-x+1))^(-1/2),x},                       
(*3.145*)
{((x-a)(x-b)((x-m)^2+n^2))^(-1/2),x},                              
{((a-x)(x-b)((x-m)^2+n^2))^(-1/2),x},                                
{(((x-m)^2+n^2)((x-m1)^2+n1^2))^(-1/2),x},                                 
(*3.147*)
{((a-x)(b-x)(c-x)(d-x))^(-1/2),x},                                  
{((a-x)(b-x)(c-x)(x-d))^(-1/2),x},                                
{((a-x)(b-x)(x-c)(x-d))^(-1/2),x},                                 
{((a-x)(x-b)(x-c)(x-d))^(-1/2),x},                              
{((x-a)(x-b)(x-c)(x-d))^(-1/2),x},                                  
(*3.148*)
{x ((a-x)(b-x)(c-x)(d-x))^(-1/2),x},                               
{x ((a-x)(b-x)(c-x)(x-d))^(-1/2),x},                            
{x ((a-x)(b-x)(x-c)(x-d))^(-1/2),x},                               
{x ((a-x)(x-b)(x-c)(x-d))^(-1/2),x},                             
{x ((x-a)(x-b)(x-c)(x-d))^(-1/2),x},                               
(*3.149*)
{x^(-1) ((a-x)(b-x)(c-x)(d-x))^(-1/2),x},                           
{x^(-1) ((a-x)(b-x)(c-x)(x-d))^(-1/2),x},                           
{x^(-1) ((a-x)(b-x)(x-c)(x-d))^(-1/2),x},                          
{x^(-1) ((a-x)(x-b)(x-c)(x-d))^(-1/2),x},                          
{x^(-1) ((x-a)(x-b)(x-c)(x-d))^(-1/2),x},                          
(*3.151*)
{(p-x)^(-1) ((a-x)(b-x)(c-x)(d-x))^(-1/2),x},                       
{(p-x)^(-1) ((a-x)(b-x)(c-x)(x-d))^(-1/2),x},                       
{(p-x)^(-1) ((a-x)(b-x)(x-c)(x-d))^(-1/2),x},                        
{(x-p)^(-1) ((a-x)(x-b)(x-c)(x-d))^(-1/2),x},                     
{(p-x)^(-1) ((a-x)(x-b)(x-c)(x-d))^(-1/2),x},                       
{(p-x)^(-1) ((x-a)(x-b)(x-c)(x-d))^(-1/2),x},                       
(*3.152*)
{((x^2+a^2)(x^2+b^2))^(-1/2),x},                                
{((x^2+a^2)(-x^2+b^2))^(-1/2),x},                                     
{((x^2+a^2)(x^2-b^2))^(-1/2),x},                                    
{((-x^2+a^2)(-x^2+b^2))^(-1/2),x},                                   
{((-x^2+a^2)(x^2-b^2))^(-1/2),x},                                    
{((x^2-a^2)(x^2-b^2))^(-1/2),x},                                   
(*3.153*)
{x^2 ((x^2+a^2)(x^2+b^2))^(-1/2),x},                                
{x^2 ((x^2+a^2)(-x^2+b^2))^(-1/2),x},                                
{x^2 ((x^2+a^2)(x^2-b^2))^(-1/2),x},                                
{x^2 ((-x^2+a^2)(-x^2+b^2))^(-1/2),x},                               
{x^2 ((-x^2+a^2)(x^2-b^2))^(-1/2),x},                              
{x^2 ((x^2-a^2)(x^2-b^2))^(-1/2),x},                                
{x^2 ((1+x^2)(1+k^2 x^2))^(-1/2),x},                              
(*3.154*)
{x^4 ((x^2+a^2)(x^2+b^2))^(-1/2),x},                                
{x^4 ((x^2+a^2)(-x^2+b^2))^(-1/2),x},                                  
{x^4 ((x^2+a^2)(x^2-b^2))^(-1/2),x},                               
{x^4 ((-x^2+a^2)(-x^2+b^2))^(-1/2),x},                               
{x^4 ((-x^2+a^2)(x^2-b^2))^(-1/2),x},                               
{x^4 ((x^2-a^2)(x^2-b^2))^(-1/2),x},                              
(*3.155*)
{((-x^2+a^2)(x^2-b^2))^(1/2),x},                                   
{((x^2-a^2)(x^2-b^2))^(1/2),x},                                       
{((x^2+a^2)(x^2+b^2))^(1/2),x},                                      
{((x^2+a^2)(-x^2+b^2))^(1/2),x},                                      
{((x^2+a^2)(x^2-b^2))^(1/2),x},                                    
{((-x^2+a^2)(-x^2+b^2))^(1/2),x},                                  
{((-x^2+a^2)(x^2-b^2))^(1/2),x},                                   
(*3.156*)
{x^(-2) ((x^2+a^2)(x^2+b^2))^(-1/2),x},                               
{x^(-2) ((x^2+a^2)(-x^2+b^2))^(-1/2),x},                          
{x^(-2) ((x^2+a^2)(x^2-b^2))^(-1/2),x},                              
{x^(-2) ((-x^2+a^2)(-x^2+b^2))^(-1/2),x},                              
{x^(-2) ((-x^2+a^2)(x^2-b^2))^(-1/2),x},                              
{x^(-2) ((x^2-a^2)(x^2-b^2))^(-1/2),x},                                
(*3.157*)
{(p-x^2)^(-1) ((x^2+a^2)(x^2+b^2))^(-1/2),x},                         
{(p-x^2)^(-1) ((x^2+a^2)(-x^2+b^2))^(-1/2),x},                           
{(p-x^2)^(-1) ((x^2+a^2)(x^2-b^2))^(-1/2),x},                          
{(x^2-p)^(-1) ((x^2+a^2)(x^2-b^2))^(-1/2),x},                          
{(p-x^2)^(-1) ((-x^2+a^2)(-x^2+b^2))^(-1/2),x},                    
{(p-x^2)^(-1) ((-x^2+a^2)(x^2-b^2))^(-1/2),x},                      
{(x^2-p)^(-1) ((-x^2+a^2)(x^2-b^2))^(-1/2),x},                         
{(p-x^2)^(-1) ((x^2-a^2)(x^2-b^2))^(-1/2),x},                      
{(x^2-p)^(-1) ((x^2-a^2)(x^2-b^2))^(-1/2),x},                       
(*3.158*)
{((x^2+a^2)(x^2+b^2)^3)^(-1/2),x},                                   
{((x^2+a^2)^3(x^2+b^2))^(-1/2),x},                                    
{((x^2+a^2)^3(-x^2+b^2))^(-1/2),x},                                   
{((x^2+a^2)^3(x^2-b^2))^(-1/2),x},                                  
{((x^2+a^2)(-x^2+b^2)^3)^(-1/2),x},                             
{((x^2+a^2)(x^2-b^2)^3)^(-1/2),x},                                    
{((-x^2+a^2)^3(-x^2+b^2))^(-1/2),x},                                  
{((-x^2+a^2)^3(x^2-b^2))^(-1/2),x},                                   
{((x^2-a^2)^3(x^2-b^2))^(-1/2),x},                                   
{((-x^2+a^2)(-x^2+b^2)^3)^(-1/2),x},                                   
{((-x^2+a^2)(x^2-b^2)^3)^(-1/2),x},                                  
{((x^2-a^2)(x^2-b^2)^3)^(-1/2),x},                                   
(*3.159*)
{x^2 ((x^2+a^2)(x^2+b^2)^3)^(-1/2),x},                              
{x^2 ((x^2+a^2)^3(x^2+b^2))^(-1/2),x},                                
{x^2 ((x^2+a^2)^3(-x^2+b^2))^(-1/2),x},                                
{x^2 ((x^2+a^2)^3(x^2-b^2))^(-1/2),x},                              
{x^2 ((x^2+a^2)(-x^2+b^2)^3)^(-1/2),x},                              
{x^2 ((x^2+a^2)(x^2-b^2)^3)^(-1/2),x},                                  
{x^2 ((-x^2+a^2)^3(-x^2+b^2))^(-1/2),x},                          
{x^2 ((-x^2+a^2)^3(x^2-b^2))^(-1/2),x},                             
{x^2 ((x^2-a^2)^3(x^2-b^2))^(-1/2),x},                               
{x^2 ((-x^2+a^2)(-x^2+b^2)^3)^(-1/2),x},                              
{x^2 ((-x^2+a^2)(x^2-b^2)^3)^(-1/2),x},                            
{x^2 ((x^2-a^2)(x^2-b^2)^3)^(-1/2),x},                               
(*3.161*)
{x^(-4) ((x^2+a^2)(x^2+b^2))^(-1/2),x},                                
{x^(-4) ((x^2+a^2)(-x^2+b^2))^(-1/2),x},                              
{x^(-4) ((x^2+a^2)(x^2-b^2))^(-1/2),x},                             
{x^(-4) ((-x^2+a^2)(-x^2+b^2))^(-1/2),x},                            
{x^(-4) ((-x^2+a^2)(x^2-b^2))^(-1/2),x},                          
{x^(-4) ((x^2-a^2)(x^2-b^2))^(-1/2),x},                                 
(*3.162*)
{((x^2+a^2)^5(x^2+b^2))^(-1/2),x},                                          
{((x^2+a^2)(x^2+b^2)^5)^(-1/2),x},
{((x^2+a^2)^5(-x^2+b^2))^(-1/2),x},
{((x^2+a^2)^5(x^2-b^2))^(-1/2),x},
{((x^2+a^2)(-x^2+b^2)^5)^(-1/2),x},
{((x^2+a^2)(x^2-b^2)^5)^(-1/2),x},
{((-x^2+a^2)(-x^2+b^2)^5)^(-1/2),x},
{((-x^2+a^2)(x^2-b^2)^5)^(-1/2),x},
{((x^2-a^2)(x^2-b^2)^5)^(-1/2),x},
{((-x^2+a^2)^5(-x^2+b^2))^(-1/2),x},
{((-x^2+a^2)^5(x^2-b^2))^(-1/2),x},
{((x^2-a^2)^5(x^2-b^2))^(-1/2),x},
(*3.163*) 
{((x^2+a^2)^3(x^2+b^2)^3)^(-1/2),x},                                 
{((x^2+a^2)^3(-x^2+b^2)^3)^(-1/2),x},                                 
{((x^2+a^2)^3(x^2-b^2)^3)^(-1/2),x},                                 
{((-x^2+a^2)^3(-x^2+b^2)^3)^(-1/2),x},                             
{((x^2-a^2)^3(x^2-b^2)^3)^(-1/2),x},                                 
(*3.164*)
{((x^2+a^2)(x^2+b^2))^(-1/2),x},                                    
{x^2 (x^2-a b)^(-2) ((x^2+a^2)(x^2+b^2))^(-1/2),x},                  
{x^2 (x^2+a b)^(-2) ((x^2+a^2)(x^2+b^2))^(-1/2),x},                  
{x^2 ((x^2+a^2)^3(x^2+b^2)^3)^(-1/2),x},                             
{(x^2-a b)^2 ((x^2+a^2)^3(x^2+b^2)^3)^(-1/2),x},                     
{(x^2+a b)^(-2) ((x^2+a^2)(x^2+b^2))^(1/2),x},                        
{(x^2-a b)^2 (x^2+a b)^(-2) ((x^2+a^2)(x^2+b^2))^(-1/2),x},           
{(x^2+a b)^2 ((x^2+a b)^2-4 p a b x^2)^(-1) ((x^2+a^2)(x^2+b^2))^(-1/2),x},
                                        (* Ret2.2 *)                                                                                                                                    
(*3.165*)
{(x^4+2 b^2 x^2+a^4)^(-1/2),x},                                      
{x^(-2) (x^4+2 b^2 x^2+a^4)^(-1/2),x},                              
{x^2 (x^2+a^2)^(-2) (x^4+2 b^2 x^2+a^4)^(-1/2),x},                  
{x^2 (x^2-a^2)^(-2) (x^4+2 b^2 x^2+a^4)^(-1/2),x},                
{x^2 (x^4+2 b^2 x^2+a^4)^(-3/2),x},                                
{x^2 ((x^4+2 b^2 x^2+a^4)^3)^(-1/2),x},                            
{(x^2-a^2)^2 (x^4+2 b^2 x^2+a^4)^(-3/2),x},                          
{(x^2+a^2)^2 (x^4+2 b^2 x^2+a^4)^(-3/2),x},                       
{(x^2-a^2)^2 ((x^4+2 b^2 x^2+a^4)^3)^(-1/2),x},                      
{(x^2+a^2)^2 ((x^4+2 b^2 x^2+a^4)^3)^(-1/2),x},                     
{(x^2-a^2)^2 (x^2+a^2)^(-2) (x^4+2 b^2 x^2+a^4)^(-1/2),x},        
{(x^2+a^2)^(-2) (x^4+2 b^2 x^2+a^4)^(1/2),x},                       
{(x^2-a^2)^(-2) (x^4+2 b^2 x^2+a^4)^(1/2),x},                         
{(x^2+a^2)^2 ((x^2+a^2)^2-4 a^2 p^2 x^2)^(-1) (x^4+2 b^2 x^2+a^4)^(-1/2),x}, 
                                       (* hangs2.2 *)                                                        
(*3.166*)
{(x^4+1)^(-1/2),x},                                                
{x^(-2) (x^4+1)^(-1/2),x},                                        
{x^2 (x^4+1)^(-3/2),x},                                             
{x^2 (x^2+1)^(-2) (x^4+1)^(-1/2),x},                                 
{x^2 (x^2-1)^(-2) (x^4+1)^(-1/2),x},                               
{(x^2-1)^(-2) (x^4+1)^(1/2),x},                                       
{(x^2-1)^2 (x^2+1)^(-2) (x^4+1)^(-1/2),x},                           
{(x^2+1)^(-2) (x^4+1)^(1/2),x},                                      
{(x^2+1)^2 ((x^2+1)^2-4 p^2 x^2)^(-1) (x^4+1)^(-1/2),x}, 
                                      (* Recur2.2 *)     
{(x^2+x Sqrt[2]+1)(x^2-x Sqrt[2]+1)^(-1) (x^4+1)^(-1/2),x},          
{(1-x)^2 (x^2-x Sqrt[2]+1)^(-1) (x^4+1)^(-1/2),x},                  
{(1+x)^2 (x^2-x Sqrt[2]+1)^(-1) (x^4+1)^(-1/2),x}, 
{(-x^4+1)^(-1/2),x},                                              
{(x^4-1)^(-1/2),x},                                                 
{x^2 (-x^4+1)^(-1/2),x},                                          
{x^2 (x^4-1)^(-1/2),x},                                            
{x^4 (-x^4+1)^(-1/2),x},                                             
{x^4 (x^4-1)^(-1/2),x},                                             
{(x (1+x^3))^(-1/2),x},                                              
{(x (1-x^3))^(-1/2),x},                                             
(*3.167*)
{((d-x)/((a-x)(b-x)(c-x)))^(-1/2),x},
{((x-d)/((a-x)(b-x)(c-x)))^(-1/2),x},
{((x-d)/((a-x)(b-x)(x-c)))^(-1/2),x},
{((x-d)/((a-x)(x-b)(x-c)))^(-1/2),x},
{((x-d)/((x-a)(x-b)(x-c)))^(-1/2),x},
{((c-x)/((a-x)(b-x)(d-x)))^(-1/2),x},
{((c-x)/((a-x)(b-x)(x-d)))^(-1/2),x},
{((x-c)/((a-x)(b-x)(x-d)))^(-1/2),x},
{((x-c)/((a-x)(x-b)(x-d)))^(-1/2),x},
{((x-c)/((x-a)(x-b)(x-d)))^(-1/2),x},
{((b-x)/((a-x)(c-x)(d-x)))^(-1/2),x},
{((b-x)/((a-x)(c-x)(x-d)))^(-1/2),x},
{((b-x)/((a-x)(x-c)(x-d)))^(-1/2),x},
{((x-b)/((a-x)(x-c)(x-d)))^(-1/2),x},
{((x-b)/((x-a)(x-c)(x-d)))^(-1/2),x},
{((a-x)/((b-x)(c-x)(d-x)))^(-1/2),x},
{((a-x)/((b-x)(c-x)(x-d)))^(-1/2),x},
{((a-x)/((b-x)(x-c)(x-d)))^(-1/2),x},
{((a-x)/((x-b)(x-c)(x-d)))^(-1/2),x},
{((x-a)/((x-b)(x-c)(x-d)))^(-1/2),x},
(*3.168*)
{((c-x)/((a-x)(b-x)(x-d)^3))^(-1/2),x},
{((x-c)/((a-x)(b-x)(x-d)^3))^(-1/2),x},
{((x-c)/((a-x)(x-b)(x-d)^3))^(-1/2),x},
{((x-c)/((x-a)(x-b)(x-d)^3))^(-1/2),x},
{((b-x)/((a-x)(c-x)(x-d)^3))^(-1/2),x},
{((b-x)/((a-x)(x-c)(x-d)^3))^(-1/2),x},
{((x-b)/((x-a)(x-c)(x-d)^3))^(-1/2),x},
{((a-x)/((b-x)(c-x)(x-d)^3))^(-1/2),x},
{((a-x)/((b-x)(x-c)(x-d)^3))^(-1/2),x},
{((a-x)/((x-b)(x-c)(x-d)^3))^(-1/2),x},
{((x-a)/((x-b)(x-c)(x-d)^3))^(-1/2),x},
{((d-x)/((a-x)(b-x)(c-x)^3))^(-1/2),x},
{((x-d)/((a-x)(b-x)(c-x)^3))^(-1/2),x},
{((x-d)/((a-x)(b-x)(x-c)^3))^(-1/2),x},
{((x-d)/((a-x)(x-b)(x-c)^3))^(-1/2),x},
{((x-d)/((x-a)(x-b)(x-c)^3))^(-1/2),x},
{((b-x)/((a-x)(c-x)^3(d-x)))^(-1/2),x},
{((b-x)/((a-x)(c-x)^3(x-d)))^(-1/2),x},
{((b-x)/((a-x)(x-c)^3(x-d)))^(-1/2),x},
{((x-b)/((a-x)(x-c)^3(x-d)))^(-1/2),x},
{((x-b)/((x-a)(x-c)^3(x-d)))^(-1/2),x},
{((a-x)/((b-x)(c-x)^3(d-x)))^(-1/2),x},
{((a-x)/((b-x)(c-x)^3(x-d)))^(-1/2),x},
{((a-x)/((b-x)(x-c)^3(x-d)))^(-1/2),x},
{((a-x)/((x-b)(x-c)^3(x-d)))^(-1/2),x},
{((x-a)/((x-b)(x-c)^3(x-d)))^(-1/2),x},
{((d-x)/((a-x)(b-x)^3(c-x)))^(-1/2),x},
{((x-d)/((a-x)(b-x)^3(c-x)))^(-1/2),x},
{((x-d)/((a-x)(b-x)^3(x-c)))^(-1/2),x},
{((x-d)/((a-x)(x-b)^3(x-c)))^(-1/2),x},
{((x-d)/((x-a)(x-b)^3(x-c)))^(-1/2),x},
{((c-x)/((a-x)(b-x)^3(d-x)))^(-1/2),x},
{((c-x)/((a-x)(b-x)^3(x-d)))^(-1/2),x},
{((x-c)/((a-x)(b-x)^3(x-d)))^(-1/2),x},
{((x-c)/((a-x)(x-b)^3(x-d)))^(-1/2),x},
{((x-c)/((x-a)(x-b)^3(x-d)))^(-1/2),x},
{((a-x)/((b-x)^3(c-x)(d-x)))^(-1/2),x},
{((a-x)/((b-x)^3(c-x)(x-d)))^(-1/2),x},
{((a-x)/((b-x)^3(x-c)(x-d)))^(-1/2),x},
{((a-x)/((x-b)^3(x-c)(x-d)))^(-1/2),x},
{((x-a)/((x-b)^3(x-c)(x-d)))^(-1/2),x},
{((d-x)/((a-x)^3(b-x)(c-x)))^(-1/2),x},
{((x-d)/((a-x)^3(b-x)(c-x)))^(-1/2),x},
{((x-d)/((a-x)^3(b-x)(x-c)))^(-1/2),x},
{((x-d)/((a-x)^3(x-b)(x-c)))^(-1/2),x},
{((c-x)/((a-x)^3(b-x)(d-x)))^(-1/2),x},
{((c-x)/((a-x)^3(b-x)(x-d)))^(-1/2),x},
{((x-c)/((a-x)^3(b-x)(x-d)))^(-1/2),x},
{((x-c)/((a-x)^3(x-b)(x-d)))^(-1/2),x},
{((b-x)/((a-x)^3(c-x)(d-x)))^(-1/2),x},
{((b-x)/((a-x)^3(c-x)(x-d)))^(-1/2),x},
{((b-x)/((a-x)^3(x-c)(x-d)))^(-1/2),x},
{((x-b)/((a-x)^3(x-c)(x-d)))^(-1/2),x},
(*3.169*)
{((x^2+a^2)/(x^2+b^2))^(1/2),x},                                   
{((x^2+a^2)/(-x^2+b^2))^(1/2),x},                                   
{((x^2+a^2)/(x^2-b^2))^(1/2),x},                                   
{((-x^2+b^2)/(x^2+a^2))^(1/2),x},                                      
{((x^2-b^2)/(x^2+a^2))^(1/2),x},                                  
{((-x^2+b^2)/(-x^2+a^2))^(1/2),x},                                    
{((x^2-b^2)/(-x^2+a^2))^(1/2),x},                                  
{((x^2-b^2)/(x^2-a^2))^(1/2),x},                                 
{((-x^2+a^2)/(-x^2+b^2))^(1/2),x},                              
{((-x^2+a^2)/(x^2-b^2))^(1/2),x},                               
{((x^2-a^2)/(x^2-b^2))^(1/2),x},                                   
(*3.171*)
{x^(-2) ((x^2+a^2)/(x^2-b^2))^(1/2),x},                           
{x^(-2) ((-x^2+a^2)/(-x^2+b^2))^(1/2),x},                       
{x^(-2) ((-x^2+a^2)/(x^2-b^2))^(1/2),x},                        
{x^(-2) ((x^2-a^2)/(x^2-b^2))^(1/2),x},                           
{x^(-2) ((x^2+a^2)/(x^2+b^2))^(1/2),x},                      
{x^(-2) ((-x^2+b^2)/(x^2+a^2))^(1/2),x},                        
{x^(-2) ((x^2-b^2)/(x^2+a^2))^(1/2),x},                             
{x^(-2) ((x^2+a^2)/(-x^2+b^2))^(1/2),x},                          
{x^(-2) ((x^2-a^2)/(x^2-b^2))^(1/2),x},                           
{x^(-2) ((x^2-b^2)/(-x^2+a^2))^(1/2),x},                         
{x^(-2) ((x^2-b^2)/(x^2-a^2))^(1/2),x},          
(*3.172*)
{((x^2+b^2)/(x^2+a^2)^3)^(1/2),x},                                 
{((-x^2+b^2)/(x^2+a^2)^3)^(1/2),x},                                
{((x^2-b^2)/(x^2+a^2)^3)^(1/2),x},                                 
{((x^2+a^2)/(-x^2+b^2)^3)^(1/2),x},                               
{((x^2+a^2)/(x^2-b^2)^3)^(1/2),x},                            
{((-x^2+b^2)/(a^2-x^2)^3)^(1/2),x},                              
{((x^2-b^2)/(a^2-x^2)^3)^(1/2),x},                                 
{((x^2-b^2)/(-a^2+x^2)^3)^(1/2),x},                                     
{((a^2-x^2)/(-x^2+b^2)^3)^(1/2),x},                              
{((-x^2+a^2)/(x^2-b^2)^3)^(1/2),x},                              
{((x^2-a^2)/(x^2-b^2)^3)^(1/2),x},                                   
(*3.173*)
{x^(-2) ((x^2+1)/(-x^2+1))^(1/2),x},                               
{x^(-2) ((x^2+1)/(x^2-1)^3)^(1/2),x},                                   
(*3.174*)
{(1+(1+Sqrt[3]) x)^(-2) ((1-x+x^2)/(x(1+x)))^(1/2),x},  (* Memoru fault 2.2 *)      
{(1+(-1+Sqrt[3]) x)^(-2) ((1+x+x^2)/(x(1-x)))^(1/2),x}, (* Memoru fault 2.2 *)     
{(1-x+x^2)^(-1) (x(1+x)/(1-x+x^2))^(1/2),x},                                      
{(1+x+x^2)^(-1) (x(1-x)/(1+x+x^2))^(1/2),x},                        
(*3.175*)

{(1+x)^(-1) (x/(1+x^3))^(1/2),x},                                  
{(1-x)^(-1) (x/(1-x^3))^(1/2),x},                                 
(*3.181*)
{((a-x)(x-b))^(-1/4),x},                (* Ret2.2 *)                               
{((x-a)(x-b))^(-1/4),x},                (* Ret2.2 *)                                         
(*3.182*)
{((a-x)(x-b))^(-3/4),x},                (* Ret2.2 *)                                        
{(((a-x)(x-b))^3)^(-1/4),x},            (* Ret2.2 *)                                                          
{((x-a)(x-b))^(-3/4),x},                (* Ret2.2 *)                                        
{(((x-a)(x-b))^3)^(-1/4),x},            (* Ret2.2 *)                                                        
(*3.183*)
{(x^2+1)^(-1/4),x},                     (* Ret2.2 *)                                       
{(-x^2+1)^(-1/4),x},                    (* Ret2.2 *)                                  
{(x^2-1)^(-1/4),x},                     (* Ret2.2 *)                                   
(*3.184*)
{x^2 (-x^2+1)^(-1/4),x},                (* Ret2.2 *)                                             
{x^(-2) (x^2-1)^(-1/4),x},              (* Ret2.2 *)                                          
(*3.185*)
{(x^2+1)^(-3/4),x},                     (* Ret2.2 *)                                                   
{((x^2+1)^3)^(-1/4),x},                 (* Ret2.2 *)                                                                                 
{(-x^2+1)^(-3/4),x},                    (* Ret2.2 *)                                              
{((-x^2+1)^3)^(-1/4),x},                (* Ret2.2 *)                                                                           
{(x^2-1)^(-3/4),x},                     (* Ret2.2 *)                                           
{((x^2-1)^3)^(-1/4),x},                 (* Ret2.2 *)                                                                         
{x^2 (-x^2+1)^(-3/4),x},                (* Ret2.2 *)                                        
{x^2 ((-x^2+1)^3)^(-1/4),x},            (* Ret2.2 *)                                                                   
{(x^2+1)^(-5/4),x},                     (* Ret2.2 *)                                        
{((x^2+1)^5)^(-1/4),x},                 (* Ret2.2 *)                                                                          
{x^2 (x^2+1)^(-5/4),x},                 (* Ret2.2 *)                                    
{x^2 ((x^2+1)^5)^(-1/4),x},             (* Ret2.2 *)                                                                  
{x^2 (x^2+1)^(-7/4),x},                 (* Ret2.2 *)                                               
{x^2 ((x^2+1)^7)^(-1/4),x},             (* Ret2.2 *)                                                                   
(*3.186*)
{(1+Sqrt[x^2+1]) (x^2+1)^(-5/4),x},     (* Ret2.2 *)                                    
{(1+Sqrt[-x^2+1])^(-1) (-x^2+1)^(-1/4),x},         (* Ret2.2 *)   
{(x^2+2 Sqrt[x^2-1])^(-1) (x^2-1)^(-1/4),x},       (* Ret2.2 *)  
{(1-Sqrt[-x^2+1]) (1+Sqrt[-x^2+1])^(-1) (-x^2+1)^(-3/4),x},     
                                                   (* Ret2.2 *)   
{x^2 (x^2+2 Sqrt[x^2-1])^(-1) (x^2-1)^(-3/4),x},   (* Ret2.2 *)   
(*3.194*)
{x^(m-1) (1+b x)^(-v),x},               (* Ret2.2 *)                                            
{x^(m-1) (1+b x)^(-1),x},               (* Ret2.2 *)  
                                         
(*****************************************************************************)
(*                         Special functions (p.626-678)                     *)
(*****************************************************************************)
(*5.111*)
{x^(2p+3) EllipticK[x^2],x},            (* Ret2.2 *)                                                  
{x^(2p+3) EllipticE[x^2],x},            (* Ret2.2 *)                                     
(*5.112*)
{EllipticK[x^2],x},                     (* Ret2.2 *)                                                
{EllipticE[x^2],x},                     (* Ret2.2 *)                                             
{x EllipticK[x^2],x},                   (* Ret2.2 *)                                            
{x EllipticE[x^2],x},                   (* Ret2.2 *)                                           
{x^3 EllipticK[x^2],x},                 (* Ret2.2 *)                                        
{x^3 EllipticE[x^2],x},                 (* Ret2.2 *)                                          
{x^5 EllipticK[x^2],x},                 (* Ret2.2 *)                                            
{x^5 EllipticE[x^2],x},                 (* Ret2.2 *)                                        
{x^(-2) EllipticK[x^2],x},              (* Ret2.2 *)                                       
{x^(-2) EllipticE[x^2],x},              (* Ret2.2 *)                                        
{(1-x^2)^(-1) EllipticE[x^2],x},        (* Ret2.2 *)                                  
{x^(-4) EllipticE[x^2],x},              (* Ret2.2 *)                              
{x (1-x^2)^(-1) EllipticE[x^2],x},      (* Ret2.2 *)                                
(*5.113*)
{x^(-1) (EllipticK[x^2]-EllipticE[x^2]),x},         (* Ret2.2 *)                        
{x^(-1) (EllipticE[x^2]-(1-x^2) EllipticK[x^2]),x}, (* Ret2.2 *)             
{x^(-1) ((1+x^2) EllipticK[x^2]-EllipticE[x^2]),x}, (* Ret2.2 *)         
{x^(-2) (EllipticK[x^2]-EllipticE[x^2]),x},         (* Ret2.2 *)              
{x^(-2)(1-x^2)^(-1) (EllipticE[x^2]-(1-x^2) EllipticK[x^2]),x},  
                                        (* Ret2.2 *)      
{x^(-1)(1-x^2)^(-2) ((1+x^2) EllipticE[x^2]-(1-x^2) EllipticK[x^2]),x}, 
                                        (* Ret2.2 *)              
(*5.114*)
{x EllipticK[x^2] (EllipticE[x^2]-(1-x^2) EllipticK[x^2])^(-2),x},
                                        (* Ret2.2 *)              
(*5.115*)
{x EllipticPi[r,Pi/2,x^2],x},           (* Ret2.2 *)                                  
{x (EllipticK[x^2]-EllipticPi[r,Pi/2,x^2]),x},               (* Ret2.2 *)                     
{x ((1-x^2)^(-1) EllipticE[x^2]+EllipticPi[r,Pi/2,x^2]),x},  (* Ret2.2 *)        
(*5.121*)
{EllipticF[x,k^2] (1-k^2 Sin[x]^2)^(-1/2),x},                       
(*5.122*)
{EllipticE[x,k^2] (1-k^2 Sin[x]^2)^(1/2),x},                       
(*5.123*)
{EllipticF[x,k^2] Sin[x],x},                                                                
{EllipticF[x,k^2] Cos[x],x},                                                        
(*5.124*)
{EllipticE[x,k^2] Sin[x],x},                                                              
{EllipticE[x,k^2] Cos[x],x},                                                           
(*5.125*)
{EllipticPi[a,x,k^2] Sin[x],x},                                                          
{EllipticPi[a,x,k^2] Cos[x],x},                                                          
(*5.126*)
{x EllipticF[a,x^2],x},                 (* Ret2.2 *)                                            
(*5.127*)
{x EllipticE[a,x^2],x},                 (* Ret2.2 *)                                            
(*5.128*)
{x EllipticPi[r,a,x^2],x},              (* Ret2.2 *)                                         
(*5.131*)
 {JacobiSN[x, m]^p,x},             (* ********* Return GENERICALLY ********* *)
 {JacobiCN[x, m]^p,x},             (* ********* Return GENERICALLY ********* *)
 {JacobiDN[x, m]^p,x},             (* ********* Return GENERICALLY ********* *)
(*5.132*)
{JacobiSN[x, m]^(-1),x},               (* Ret2.2 *)          (* BAD FS ret *)           
{JacobiCN[x, m]^(-1),x},               (* Ret2.2 *)          (* BAD FS ret *)             
{JacobiDN[x, m]^(-1),x},               (* Ret2.2 *)          (* BAD FS ret *)           
(*5.133*) 
{JacobiSN[x, m],x},                    (* Ret2.2 *)              
{JacobiCN[x, m],x},                    (* Ret2.2 *)          (* BAD FS ret *)        
{JacobiDN[x, m],x},                    (* Ret2.2 *)               
(*5.134*)
{JacobiSN[x, m]^2,x},                  (* Ret2.2 *)          (* BAD FS ret *)             
{JacobiCN[x, m]^2,x},                  (* Ret2.2 *)          (* BAD FS ret *)           
{JacobiDN[x, m]^2,x},                  (* Ret2.2 *)          (* BAD FS ret *)            
(*5.135*)
{JacobiSN[x, m]/JacobiCN[x, m],x},     (* Ret2.2 *)        (* BAD FS ret *)        
{JacobiSN[x, m]/JacobiDN[x, m],x},     (* Ret2.2 *)        (* BAD FS ret *)       
{JacobiCN[x, m]/JacobiSN[x, m],x},     (* Ret2.2 *)        (* BAD FS ret *)           
{JacobiCN[x, m]/JacobiDN[x, m],x},     (* Ret2.2 *)        (* BAD FS ret *)          
{JacobiDN[x, m]/JacobiCN[x, m],x},     (* Ret2.2 *)        (* BAD FS ret *)           
{JacobiDN[x, m]/JacobiSN[x, m],x},     (* Ret2.2 *)        (* BAD FS ret *)         
(*5.136*)
{JacobiSN[x, m] JacobiCN[x, m],x},     (* Ret2.2 *)               
{JacobiSN[x, m] JacobiDN[x, m],x},     (* Ret2.2 *)              
{JacobiCN[x, m] JacobiDN[x, m],x},     (* Ret2.2 *)               
(*5.137*)
{JacobiSN[x, m] JacobiCN[x, m]^(-2),x}, (* Ret2.2 *)      (* BAD FS ret *)          
{JacobiSN[x, m] JacobiDN[x, m]^(-2),x}, (* Ret2.2 *)      (* BAD FS ret *)          
{JacobiCN[x, m] JacobiSN[x, m]^(-2),x}, (* Ret2.2 *)      (* BAD FS ret *)          
{JacobiCN[x, m] JacobiDN[x, m]^(-2),x}, (* Ret2.2 *)      (* BAD FS ret *)          
{JacobiDN[x, m] JacobiSN[x, m]^(-2),x}, (* Ret2.2 *)      (* BAD FS ret *)          
{JacobiDN[x, m] JacobiCN[x, m]^(-2),x}, (* Ret2.2 *)      (* BAD FS ret *)         
(*5.138*)
{JacobiCN[x, m] JacobiSN[x, m]^(-1) JacobiDN[x, m]^(-1),x},    (* Ret2.2 *) 
                                                           (* BAD FS ret *)              
{JacobiSN[x, m] JacobiCN[x, m]^(-1) JacobiDN[x, m]^(-1),x},    (* Ret2.2 *) 
                                                           (* BAD FS ret *)              
{JacobiDN[x, m] JacobiSN[x, m]^(-1) JacobiCN[x, m]^(-1),x},    (* Ret2.2 *) 
                                                           (* BAD FS ret *)               
(*5.139*)
{JacobiCN[x, m] JacobiDN[x, m] JacobiSN[x, m]^(-1),x},         
{JacobiSN[x, m] JacobiDN[x, m] JacobiCN[x, m]^(-1),x},          
{JacobiSN[x, m] JacobiCN[x, m] JacobiDN[x, m]^(-1),x},       
(*5.141*)
{WeierstrassP[x, {g2, g3}],x},           (* Ret2.2 *)              
{WeierstrassP[x, {g2, g3}]^2,x},         (* Ret2.2 *)              
{WeierstrassP[x, {g2, g3}]^3,x},         (* Ret2.2 *)        (* BAD FS ret *)                                                                    
{(WeierstrassP[x, {g2, g3}]-WeierstrassP[a, {g2, g3}])^(-1),x},       
                                        (* Ret2.2 *)         (* BAD FS ret *)            
 {(a WeierstrassP[x, {g2, g3}]+b)(c WeierstrassP[x, {g2, g3}]+d)^(-1),x},
                                   (* ********* Return GENERICALLY ********* *)

(*5.211*)
{ExpIntegralEi[-b x] ExpIntegralEi[-c x],x},                      
(*5.221*)
 {x^(-n-1) ExpIntegralEi[-a (x+b)],x},(* ******* Return GENERICALLY ******** *)
{x^(-2) ExpIntegralEi[-a (x+b)],x},                                
(*5.231*)
{Exp[x] ExpIntegralEi[-x],x},           (* Numer2.2 *)                                
{Exp[-b x] ExpIntegralEi[-a x],x},  
(*5.31*)
{Cos[a x] CosIntegral[b x],x},          (* Ret2.2 *)                                 
{Sin[a x] CosIntegral[b x],x},          (* Ret2.2 *)                                
(*5.32*)
{Cos[a x] SinIntegral[b x],x},          (* Ret2.2 *)                                 
{Sin[a x] SinIntegral[b x],x},          (* Ret2.2 *)                             
(*5.33*)
{CosIntegral[a x] CosIntegral[b x],x},  
{SinIntegral[a x] SinIntegral[b x],x},
{SinIntegral[a x] CosIntegral[b x],x}, 
(*5.34*)
{x^(-2) SinIntegral[a (x+b)],x},        (* Ret2.2 *)  
{x^(-2) CosIntegral[a (x+b)],x},        (* Ret2.2 *)  
(*5.41*)
{Erf[a x],x}, 
(*5.42*)
{FresnelS[a x],x}, 
(*5.43*)
{FresnelC[a x],x}, 
(*5.51*)
{BesselJ[p,x],x},                       (* Ret2.2 *)                                                      
(*5.52*)
{x^(p+1) BesselJ[p,x],x},               (* Ret2.2 *)                                           
{x^(p+1) BesselY[p,x],x},               (* Ret2.2 *)                                         
{x^(p+1) BesselI[p,x],x},               (* Ret2.2 *)                                       
{x^(p+1) BesselK[p,x],x},               (* Ret2.2 *)                                      
(*5.53*)
{((a^2-b^2) x-(p^2-q^2)/x) BesselJ[p,a x] BesselJ[q,b x],x}, (* Ret2.2 *)
                                                                (* Return FS *)      
{((a^2-b^2) x-(p^2-q^2)/x) BesselJ[p,a x] BesselY[q,b x],x}, (* Ret2.2 *)
                                                                (* Return FS *)    
{((a^2-b^2) x-(p^2-q^2)/x) BesselY[p,a x] BesselY[q,b x],x}, (* Ret2.2 *) 
                                                                (* Return FS *)
 
(*5.54*)
{x BesselJ[p,a x] BesselJ[p,b x],x},    (* Ret2.2 *)                               
{x BesselJ[p,a x] BesselY[p,b x],x},    (* Ret2.2 *)                                       
{x BesselY[p,a x] BesselY[p,b x],x},    (* Ret2.2 *)                                     
{x BesselJ[p,a x]^2,x},                 (* Ret2.2 *)                                           
{x BesselY[p,a x]^2,x},                 (* Ret2.2 *)                                          
{x BesselJ[p,a x] BesselI[p,b x],x},    (* Ret2.2 *)                                          
{x BesselY[p,a x] BesselI[p,b x],x},    (* Ret2.2 *)                                        
{x BesselI[p,a x] BesselI[p,b x],x},    (* Ret2.2 *)                                          
{x BesselY[p,a x] BesselK[p,b x],x},    (* Ret2.2 *)                                          
{x BesselI[p,a x] BesselK[p,b x],x},    (* Ret2.2 *)           (* Ret FS *)                                        
{x BesselK[p,a x] BesselK[p,b x],x},    (* Ret2.2 *)                                      
{x BesselI[p,a x]^2,x},                 (* Ret2.2 *)                                           
{x BesselK[p,a x]^2,x},                 (* Ret2.2 *)                                    
(*5.55*)
{x^(-1) BesselJ[p,a x] BesselJ[q,a x],x}, (* Ret2.2 *)         (* Ret FS *)                                 
{x^(-1) BesselJ[p,a x] BesselY[q,a x],x}, (* Ret2.2 *)         (* Ret FS *)                              
{x^(-1) BesselY[p,a x] BesselY[q,a x],x}, (* Ret2.2 *)         (* Ret FS *)                      
(*5.56*)

{BesselJ[1,x],x},                       (* Ret2.2 *)                                             
{BesselY[1,x],x},                       (* Ret2.2 *)                                                                                     
{BesselI[1,x],x},                       (* Ret2.2 *)                                         
{BesselK[1,x],x},                       (* Ret2.2 *)                                                                                
{x BesselJ[0,x],x},                     (* Ret2.2 *)                                    
{x BesselY[0,x],x},                     (* Ret2.2 *)                                    
{x BesselI[0,x],x},                     (* Ret2.2 *)                                      
{x BesselK[0,x],x},                     (* Ret2.2 *)                                 
(*6.221*)
{ExpIntegralEi[a x],x},
(*6.441*)
{LogGamma[x],x},                  (* GEN *)
{LogGamma[a+x],x},                (* GEN *)
(*6.441*)
{PolyGamma[x],x},
(*6.511*)
{BesselJ[v,x],x},                       (* Ret2.2 *)                                                   
{BesselJ[0,x],x},                       (* Ret2.2 *)                                                  
{BesselJ[1,x],x},                       (* Ret2.2 *)                                                   
{BesselY[v,x],x},                       (* Ret2.2 *)                                                    
{BesselI[v,x],x},                       (* Ret2.2 *)                                                 
(*6.521*)
{x BesselJ[v,l x] BesselK[v,m x],x}}    (* Ret2.2 *) 
                    


Stars = "**************************************************************"
TestFile = "ResTestGradFeb202003"

Needs["NumericalMath`NLimit`"]

Unprotect[$MessageList]

Test2F1[]:=
  Block[{i,input,time,stream,inputSystem,output,outputSystem,
         derivativesrule,listS},
    stream=OpenWrite[TestFile];
    WriteString[stream,"\n",Stars,"\n",
                "*\n",
                "*              Integrals and Series, vol.3\n",           
                "*\n",          
                "*              Authors: A.P.Prudnikov,\n",
                "*                       Yu.A.Brychkov,\n",
                "*                       O.I. Marichev,\n",     
                "*              Pages 468-488\n",
                "*\n",Stars,"\n\n",Stars,
                "\n*\n*              Results of the Testing\n*\n",Stars,"\n\n\n"];
    For[i=1,i<=Length[Test],i++,
        (* Print input. *)
        input=HoldForm[F]/.{F->Test[[i]]}/.{List->Integrate};
        inputSystem=HoldForm[F]/.{F->Test[[i]]}/.{List->Integrate};
       (* Compute output. *)
        $MessageList={};
        {time,output}=Timing[Apply[Integrate,Test[[i]]]];
        (* Numerical comparison of result after differentiation *)
(*
       check= {Abs[N[(D[ExpandAll[output],x]-Test[[i,1]])/.
               {x->Random[Real,{-10, 10}]} /.
               {a->Random[Real,{-10, 10}]}/.{b->Random[Real,{-10, 10}]} /.
               {c->Random[Real,{-10, 10}]}/.{d->Random[Real,{-10, 10}]}/.
               {f->Random[Real,{-10, 10}]}/.{p->Random[Real,{-10, 10}]}/.
               {q->Random[Real,{-10, 10}]}/.{r->Random[Real,{-10, 10}]}/.
               {a1->Random[Real,{-10, 10}]}/.{b1->Random[Real,{-10, 10}]}/.
               {d1->Random[Real,{-10, 10}]}/.{e->Random[Real,{-10, 10}]}/.
               {c1->-Random[Real,{-10, 10}]}/.{k->-Random[Real,{-10, 10}]}/.
               {y->-Random[Real,{-10, 10}]}/.{m->-Random[Real,{-10, 10}]}]],
               BAD};

       check= {Abs[N[(D[output,x]-Test[[i,1]])/.
             {x->Random[]}/.{a->-Random[]}/.
             {b->-Random[]}/.{c->-Random[]}/.{d->-Random[]}/.{f->-Random[]}/.
             {p->-Random[]}/.{q->-Random[]}/.{r->-Random[]}/.
             {a1->-Random[]}/.{b1->-Random[]}/.{d1->-Random[]}/.
             {e->-Random[]}/.{c1->-Random[]}/.{k->-Random[]}/.
             {y->-Random[]}/.{m->-Random[]}/.{M->-Random[]}/.
             {N->-Random[]}/.{A->-Random[]}/.{B->-Random[]}/.
             {C->-Random[]}/.{n->-Random[]}/.{s->-Random[]}/.
             {t->-Random[]}/.{l->-Random[]}/.{c1->-Random[]}/.
             {g->-Random[]}/.{h->-Random[]}/.{u->-Random[]}/.
             {v->-Random[]}/.{n1->-Random[]}/.{m1->-Random[]}]], BAD};
*)

derivativesrule :=
  Derivative[divorders__][func_][fargs__] :>
    Fold[ND[#1,Apply[Sequence,#2]]&, func[fargs],
      Map[{{{fargs}[[#]],{divorders}[[#]]},{fargs}[[#]]/.listS}&,
        Range[Length[{fargs}]]]
        ] /; Length[{divorders}] == Length[{fargs}];
                                                                                
(*
derivativesrule :=
{Derivative[n_Integer][f_][y_]:>
   ND[f[w],{w,n},(y/.listS)] /; NumericQ[f[y/.listS]],
 Derivative[n_Integer,0][f_][y_,z_]:>
   ND[f[w,(z/.listS)],{w,n},(y/.listS)] /; NumericQ[f[(y/.listS),(z/.listS)]],
 Derivative[0,n_Integer][f_][y_,z_]:>
   ND[f[(y/.listS),w],{w,n},(z/.listS)]  /; NumericQ[f[(y/.listS),(z/.listS)]],
 Derivative[n_Integer,0,0][f_][y_,z_,g_]:>          
   ND[f[w,(z/.listS),(g/.listS)],{w,n},(y/.listS)] /;
      NumericQ[f[(y/.listS),(z/.listS),(g/.listS)]],
 Derivative[0,n_Integer,0][f_][y_,z_,g_]:>
   ND[f[(y/.listS),w,(g/.listS)],{w,n},(z/.listS)] /;
      NumericQ[f[(y/.listS),(z/.listS),(g/.listS)]],
 Derivative[0,0,n_Integer][f_][y_,z_,g_]:>
   ND[f[(y/.listS),(z/.listS),w],{w,n},(g/.listS)] /;
      NumericQ[f[(x/.listS),(y/.listS),(g/.listS)]]
};
*)
listS = {x->Random[],a->-Random[],
             b->-Random[],c->-Random[],d->-Random[],f->-Random[],
             p->-Random[],q->-Random[],r->-Random[],
             a1->-Random[],b1->-Random[],d1->-Random[],
             e->-Random[],c1->-Random[],k->-Random[],
             y->-Random[],m->-Random[],M->-Random[],
             N->-Random[],A->-Random[],B->-Random[],
             C->-Random[],n->-Random[],s->-Random[],
             t->-Random[],l->-Random[],c1->-Random[],
             g->-Random[],h->-Random[],u->-Random[],
v->-Random[],n1->-Random[],m1->-Random[],g2->-Random[],g3->-Random[]};
(*
       check= {Abs[N[(D[output,x]-Test[[i,1]])/.derivativesrule/.listS
             ]], BAD};
       If[check[[1]]<10^(-6) && FreeQ[output,Integrate] && FreeQ[output,Sqrt1],
       check=GOOD];  
       check= {FullSimplify[(D[output,x]-Test[[i,1]])], BAD};
       If[FreeQ[output,Integrate] && check[[1]]===0,
       check=GOOD];
 
     
       check= {Abs[N[(D[output,x]-Test[[i,1]])/.listS
                  ]], BAD};
       If[check[[1]]<10^(-6) && FreeQ[output,Integrate],
       check=GOOD];
*) 
       check= If[FreeQ[output,AppellF1],
                 {Abs[N[(D[output,x]-Test[[i,1]])/.listS
                  ]], BAD},
                  {10^(-7),BAD}];
       If[check[[1]]<10^(-6) && FreeQ[output,Integrate],
       check=GOOD];

   If[FreeQ[output,Integrate],
       check=GOOD];    
       
(*          
      check= {Abs[N[(If[Not[FreeQ[output,AppellF1]],
                         Simplify[D[output,x]-Test[[i,1]]],
                         D[output,x]-Test[[i,1]]])/.listS
             ]], BAD};
       If[check[[1]]<10^(-6) && FreeQ[output,Integrate] && FreeQ[output,Sqrt1],
       check=GOOD];
*)
           
      account1=i;
        time1[i]= Block[{},
            List01={};
            AppendTo[List01,time[[1]]];
             List01];  
        bad[i]= Block[{},
           List00={};
            If[FreeQ[check,GOOD] || Not[FreeQ[output,Integrate]],
               AppendTo[List00,i]];
             List00]; 

        (* Print to Mathematica session and TestFile. *)
      TestPrint[$Output,input,time,output,controloutput,
                outputSystem,check,account1];
      TestPrint[TestFile,input,time,output,controloutput,
                outputSystem,check,account1];
    ];
    TimeTable = Table[time1[i][[1]],{i,Length[Test]}];
    TimeTableSystem = Table[time3[i][[1]],{i,Length[Test]}];
    BadTable = Union[Table[If[Length[bad[i]]>0,bad[i][[1]],bad[i]],
               {i,Length[Test]}]];
    GenTime = Apply[Plus,TimeTable] Second;
    Close[TestFile];
]

TestPrint[stream_,input_,time_,output_,controloutput_,
   outputSystem_,check_,account1_]:=
  Block[{},
    WriteString[stream,"\n"];
    WriteString[stream, "  Account : "];
    Write[stream,account1];
    WriteString[stream, "  Input :\n  -----\n\n"];
    WriteString[stream,input,"\n\n" ];
    WriteString[stream, "  Output :\n  ------\n\n"];
    Write[stream,output];
    WriteString[stream, "  Control :\n  ------\n\n"];
    Write[stream,controloutput];
    WriteString[stream,"\n"];
    WriteString[stream, "  Time : "];
    Write[stream,time];
    WriteString[stream,"  Messages :\n"];
    Write[stream,$MessageList];
    WriteString[stream,"  Numerical Check :\n  --------- -----\n\n"];
    Write[stream,check]; 
    WriteString[stream,"  ---------------------------------------------------------\n\n"];
    WriteString[stream, "  OutputSystem :\n  ------------\n\n"];
    Write[stream,outputSystem];
    WriteString[stream,"\n\n"];
    WriteString[stream,Stars,"\n\n"];
]

Test2F1[]
ClearAll[Test2F1,Stars,TestFile]
(*
rpos := Exp[Random[Real, {-10, 10}]];
rr := (2 Random[Integer, {0, 1}] - 1) rpos;
ri := rr I;
rc := rpos Exp[I Random[Real, N[{-Pi, Pi}]]];

ran := Module[{x = Random[Real, {0, 1}]},
                (* you may want to adjust the probabilities here *)
                Which[  x < .2, rpos,
                        x < .5, rr,
                        x < .7, ri,
                        True,   rc]
                ];

RandomTest[e1_, e2_, vars_] :=
    Module[{ne1, ne2, rules},
        rules = Table[vars[[k]] -> ran, {k, Length[vars]}];
        ne1 = N[e1 /. rules];
        ne2 = N[e2 /. rules];
        Abs[N[ne1-ne2]]/(Abs[ne1] + Abs[ne2]) < 0.00000000001
        ]

RandomTest[e1_, e2_, vars_, prec_] :=
    Module[{ne1, ne2, rules},
        rules = Table[vars[[k]] -> SetPrecision[ran, prec], {k, Length[vars]}];
        ne1 = N[e1 /. rules, prec];
        ne2 = N[e2 /. rules, prec];
        Abs[N[ne1-ne2]]/(Abs[ne1] + Abs[ne2]) < 10.^(5-prec)
        ]

(* examples:
        RandomTest[a+b, (a^2-b^2)/(a-b), {a, b}]
        RandomTest[a+b, (a^2-b^2)/(a-b), {a, b}, 50]
        RandomTest[a+b, (a^2-b^2)/(a+b), {a, b}]
*)
   *) 
          


