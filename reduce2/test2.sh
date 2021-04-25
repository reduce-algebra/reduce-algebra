#! /bin/bash

time csl -w -i reduce2.img -l test2.log <<'XX'
(enable!-errorset 3 3) % for CSL this makes it impossible for
                       % errorset to disable diagnostics and make
                       % unwinding silent. Sometimes useful for
                       % debugging.
(mkop 'f)
(mkop 'gp)
(mkop 'g)
(begin)
                                                                                
COMMENT SOME EXAMPLES OF THE  F O R  STATEMENT;                                 
                                                                                
COMMENT SUMMING THE SQUARES OF THE EVEN POSITIVE INTEGERS                       
      THROUGH 50;                                                               
                                                                                
FOR I:=2 STEP 2 UNTIL 50 SUM I**2;                                              
                                                                                
COMMENT TO SET  XXX  TO THE FACTORIAL OF 10;                                      
                                                                                
XXX := FOR I:=1:10 PRODUCT I;                                                     
                                                                                
COMMENT ALTERNATIVELY, WE COULD SET THE ELEMENTS A(I) OF THE                    
      ARRAY  A  TO THE FACTORIAL OF I BY THE STATEMENTS;                        
                                                                                
ARRAY A(10);                                                                    
A(0):=1$                                                                        
FOR I:=1:10 DO A(I):=I*A(I-1);                                                  
                                                                                
COMMENT THE ABOVE VERSION OF THE F O R STATEMENT DOES NOT RETURN AN             
      ALGEBRAIC VALUE, BUT WE CAN NOW USE THESE ARRAY ELEMENTS                  
      AS FACTORIALS IN EXPRESSIONS, E. G.;                                      
                                                                                
1+A(5);                                                                         
                                                                                
COMMENT WE COULD HAVE PRINTED THE VALUES OF EACH A(I)                           
      AS THEY WERE COMPUTED BY REPLACING THE F O R STATEMENT BY;                
                                                                                
FOR I:=1:10 DO WRITE A(I):= I*A(I-1);                                           
                                                                                
COMMENT ANOTHER WAY TO USE FACTORIALS WOULD BE TO INTRODUCE AN                  
OPERATOR  FAC  BY AN INTEGER PROCEDURE AS FOLLOWS;                              
                                                                                
INTEGER PROCEDURE FAC (N);                                                      
   BEGIN INTEGER M,N;                                                           
      M:=1;                                                                     
    L1:      IF N=0 THEN RETURN M;                                              
      M:=M*N;                                                                   
      N:=N-1;                                                                   
      GO TO L1                                                                  
   END;                                                                         
                                                                                
COMMENT WE CAN NOW USE  FAC  AS AN OPERATOR IN EXPRESSIONS,                     
E. G. ;                                                                         
                                                                                
Z**2+FAC(4)-2*FAC 2*Y;                                                          
                                                                                
COMMENT NOTE IN THE ABOVE EXAMPLE THAT THE PARENTHESES AROUND                   
THE ARGUMENTS OF  FAC  MAY BE OMITTED SINCE  FAC  IS A UNARY OPERATOR;          
                                                                                
COMMENT THE FOLLOWING EXAMPLES ILLUSTRATE THE SOLUTION OF SOME                  
      COMPLETE PROBLEMS;                                                        
                                                                                
COMMENT THE F AND G SERIES (REF  SCONZO, P., LESCHACK, A. R. AND                
         TOBEY, R. G., ASTRONOMICAL JOURNAL, VOL 70 (MAY 1965);                 
                                                                                
SCALAR F1,F2,G1,G2;                                                             
                                                                                
DEPS:= -SIG*(MU+2*EPS)$                                                         
DMU:= -3*MU*SIG$                                                                
DSIG:= EPS-2*SIG**2$                                                            
F1:= 1$                                                                         
G1:= 0$                                                                         
                                                                                
FOR I:= 1:8 DO                                                                  
 BEGIN                                                                          
   F2:= -MU*G1 + DEPS*DF(F1,EPS) + DMU*DF(F1,MU) + DSIG*DF(F1,SIG)$             
   WRITE "F(",I,") := ",F2;                                                     
   G2:= F1 + DEPS*DF(G1,EPS) + DMU*DF(G1,MU) + DSIG*DF(G1,SIG)$                 
   WRITE "G(",I,") := ",G2;                                                     
   F1:=F2$                                                                      
   G1:=G2                                                                       
  END;                                                                          
                                                                                
COMMENT A PROBLEM IN FOURIER ANALYSIS;                                          
                                                                                
FOR ALL X,Y LET COS(X)*COS(Y)= (COS(X+Y)+COS(X-Y))/2,                           
            COS(X)*SIN(Y)= (SIN(X+Y)-SIN(X-Y))/2,                               
            SIN(X)*SIN(Y)= (COS(X-Y)-COS(X+Y))/2;                               
FACTOR COS,SIN;                                                                 
ON LIST;                                                                        
(A1*COS(WT)+ A3*COS(3*WT)+ B1*SIN(WT)+ B3*SIN(3*WT))**3;                        
                                                                                
COMMENT END OF FOURIER ANALYSIS EXAMPLE ;                                       
                                                                                
OFF LIST;                                                                       
FOR ALL X,Y CLEAR COS X*COS Y,COS X*SIN Y,SIN X*SIN Y;                          
COMMENT LEAVING SUCH REPLACEMENTS ACTIVE WOULD SLOW DOWN                        
        SUBSEQUENT COMPUTATION;                                                 
                                                                                
COMMENT AN EXAMPLE USING THE MATRIX FACILITY;                                   
                                                                                
MATRIX XX,YY;                                                                   
                                                                                
LET XX= MAT((A11,A12),(A21,A22)),                                               
   YY= MAT((Y1),(Y2));                                                          
                                                                                
2*DET XX - 3*XXX;                                                                 
                                                                                
COMMENT @@@@@ ZZ:= SOLVE (XX,YY);                                                             
                                                                                
1/XX**2;                                                                        
                                                                                
COMMENT END OF MATRIX EXAMPLES;                                                 
                                                                                
COMMENT THE FOLLOWING EXAMPLES WILL FAIL UNLESS THE FUNCTIONS                   
        NEEDED FOR PROBLEMS IN HIGH ENERGY PHYSICS HAVE BEEN LOADED;            
                                                                                
COMMENT A PHYSICS EXAMPLE;                                                      
ON DIV; COMMENT THIS GIVES US OUTPUT IN SAME FORM AS BJORKEN AND DRELL;         
MASS KI= 0, KF= 0, PI= M, PF= M; VECTOR EI,EF;                                  
MSHELL KI,KF,PI,PF;                                                             
LET PI.EI= 0, PI.EF= 0, PI.PF= M**2+KI.KF, PI.KI= M*K,PI.KF=                    
    M*KP, PF.EI= -KF.EI, PF.EF= KI.EF, PF.KI= M*KP, PF.KF=                      
    M*K, KI.EI= 0, KI.KF= M*(K-KP), KF.EF= 0, EI.EI= -1, EF.EF=                 
    -1;                                                                         
FOR ALL P LET GP(P)= G(L,P)+M;                                                  
COMMENT THIS IS JUST TO SAVE US A LOT OF WRITING;                               
GP(PF)*(G(L,EF,EI,KI)/(2*KI.PI) + G(L,EI,EF,KF)/(2*KF.PI))                      
  * GP(PI)*(G(L,KI,EI,EF)/(2*KI.PI) + G(L,KF,EF,EI)/(2*KF.PI)) $                
WRITE "THE COMPTON CROSS-SECTION IS ",!*ANS;                                 
COMMENT END OF FIRST PHYSICS EXAMPLE;                                           
                                                                                
OFF DIV;                                                                        
                                                                                
COMMENT ANOTHER PHYSICS EXAMPLE;                                                
FACTOR MM,P1.P3;                                                                
INDEX X1,Y1,Z;                                                                  
MASS P1=MM,P2=MM,P3= MM,P4= MM,K1=0;                                            
MSHELL P1,P2,P3,P4,K1;                                                          
VECTOR Q1,Q2;                                                                   
FOR ALL P LET GA(P)=G(LA,P)+MM, GB(P)= G(LB,P)+MM;                              
GA(-P2)*G(LA,X1)*GA(-P4)*G(LA,Y1)* (GB(P3)*G(LB,X1)*GB(Q1)                      
    *G(LB,Z)*GB(P1)*G(LB,Y1)*GB(Q2)*G(LB,Z)   +   GB(P3)                        
    *G(LB,Z)*GB(Q2)*G(LB,X1)*GB(P1)*G(LB,Z)*GB(Q1)*G(LB,Y1))$                   
LET Q1=P1-K1, Q2=P3+K1;                                                         
COMMENT IT IS USUALLY FASTER TO MAKE SUCH SUBSTITUTIONS AFTER ALL               
        TRACE ALGEBRA IS DONE;                                                  
WRITE "CXN = ",!*ANS;                                                           
                                                                                
COMMENT END OF SECOND PHYSICS EXAMPLE;                                          
                                                                                
                                                                                
COMMENT THE FOLLOWING RATHER LONG PROGRAM IS A COMPLETE ROUTINE FOR             
CALCULATING THE RICCI SCALAR. IT WAS DEVELOPED IN COLLABORATION WITH            
DAVID BARTON AND JOHN FITCH;                                                    
                                                                                
COMMENT FIRST WE INHIBIT DIAGNOSTIC MESSAGE PRINTING AND THE PRINTING OF        
      ZERO ELEMENTS OF ARRAYS;                                                  
                                                                                
OFF MSG$ ON NERO$                                                               
                                                                                
COMMENT HERE WE INTRODUCE THE COVARIANT AND CONTRAVARIANT METRICS;              
                                                                                
ARRAY GG(3,3),H(3,3),X(3)$                                                      
FOR I:=0:3 DO FOR J:=0:3 DO GG(I,J):=H(I,J):=0$                                 
GG(0,0):=E**(Q1(X(1)))$                                                         
GG(1,1):=-E**(P1(X(1)))$                                                        
GG(2,2):=-X(1)**2$                                                              
GG(3,3):=-X(1)**2*SIN(X(2))**2$                                                 
FOR I:=0:3 DO  H(I,I):=1/GG(I,I)$                                               
                                                                                
IF I UNEQ J LET DF(P1(X(I)),X(J))=0, DF(Q1(X(I)),X(J))=0;                       
                                                                                
COMMENT GENERATE CHRISTOFFEL SYMBOLS AND STORE IN ARRAYS                        
      CS1 AND CS2;                                                              
                                                                                
ARRAY CS1(3,3,3)$                                                               
FOR I:=0:3 DO  FOR J:=I:3                                                       
   DO  FOR K:=0:3 DO                                                            
       CS1(J,I,K) := CS1(I,J,K):=(DF(GG(I,K),X(J))+DF(GG(J,K),X(I))             
       -DF(GG(I,J),X(K)))/2$                                                    
                                                                                
                                                                                
ARRAY CS2(3,3,3)$                                                               
FOR I:= 0:3 DO  FOR J:=I:3                                                      
   DO  FOR K:=0:3  DO                                                           
      CS2(J,I,K):= CS2(I,J,K) := FOR P := 0:3                                   
            SUM H(K,P)*CS1(I,J,P)$                                              
                                                                                
COMMENT NOW CALCULATE THE DERIVATIVES OF THE CHRISTOFFEL SYMBOLS                
      AND STORE IN DC2(I,J,K,L);                                                
                                                                                
ARRAY DC2(3,3,3,3)$                                                             
FOR I:=0:3 DO  FOR J:=I:3 DO  FOR K:=0:3 DO  FOR L:=0:3 DO                      
    DC2(J,I,K,L) :=   DC2(I,J,K,L):=DF(CS2(I,J,K),X(L))$                        
                                                                                
COMMENT NOW STORE THE SUMS OF PRODUCTS OF THE CS2 IN SPCS2;                     
                                                                                
ARRAY SPCS2(3,3,3,3)$                                                           
FOR I:=0:3 DO  FOR J:=I:3 DO  FOR K:=0:3 DO  FOR L:=0:3 DO                      
      SPCS2(J,I,K,L) := SPCS2(I,J,K,L) := FOR P := 0:3                          
                        SUM CS2(P,L,K)*CS2(I,J,P)$                              
                                                                                
COMMENT NOW COMPUTE THE RIEMANN TENSOR AND STORE IN R(I,J,K,L);                 
                                                                                
ARRAY R(3,3,3,3)$                                                               
FOR I:=0:3 DO   FOR J:=I+1:3 DO                                                 
FOR K:=I:3 DO                                                                   
FOR L:=K+1:IF K=I THEN J ELSE 3 DO                                              
  BEGIN                                                                         
      R(J,I,L,K) := R(I,J,K,L) := FOR Q := 0:3                                  
            SUM GG(I,Q)*(DC2(K,J,Q,L)-DC2(J,L,Q,K)                              
                  +SPCS2(K,J,Q,L)-SPCS2(L,J,Q,K))$                              
      R(I,J,L,K) := R(J,I,K,L) := -R(I,J,K,L)$                                  
      IF I=K AND J =L THEN GO TO A$                                             
      R(K,L,I,J) := R(L,K,J,I) := R(I,J,K,L)$                                   
      R(L,K,I,J) := R(K,L,J,I) := -R(I,J,K,L)$                                  
 A: END$                                                                        
                                                                                
COMMENT NOW COMPUTE AND PRINT THE RICCI TENSOR;                                 
                                                                                
ARRAY RICCI(3,3)$                                                               
FOR I:=0:3 DO FOR J:=0:3 DO                                                     
 WRITE RICCI(J,I) := RICCI(I,J) := FOR P := 0:3 SUM FOR Q := 0:3 SUM            
                              H(P,Q)*R(Q,I,P,J);                                
                                                                                
COMMENT FINALLY COMPUTE AND PRINT THE RICCI SCALAR;                             
                                                                                
R := FOR I:= 0:3 SUM FOR J:= 0:3 SUM H(I,J)*RICCI(I,J);                         
                                                                                
END OF RICCI TENSOR AND SCALAR CALCULATION;                                     
                                                                                
COMMENT END OF ALL EXAMPLES; END;                                               
                                                                                
                                                                                
XX
