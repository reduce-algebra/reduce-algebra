module xcolor;

%----------------------------------------------------------------------
% File:      xcolor.red
% Purpose:   Evaluation of colour factor for SU(n) gauge group
% Author:    A.Kryukov
% E-address: kryukov@npi.msu.su
% Vertion:   4.2.1
% Release:   Aug. 17, 1994
%----------------------------------------------------------------------
% Revision: 10/03/91  Start
%           17/08/94  RemoveG2
%           11/03/91  Split3GV
%           11/03/91  Exist3GV, ExistQGV
%           12/03/91  Put's and so on
%           14/03/91  CError
%           15/03/91  ChkCG
%           19/03/91  Color1
%           19/03/91  ZCoefP
%           17/08/94  RemoveG1
%----------------------------------------------------------------------

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


%----------------------------------------------------------------------
%                         xColor package.
%----------------------------------------------------------------------

  imports addsq,multsq,negsq,quotsq,exptsq$
  exports color0$

create!-package('(xcolor cface),'(contrib physics));

%----------------------------------------------------------------------
%
% Structure definitions.
% ----------------------
%
% c-grpah ::= (v1 v2 ...), where vK - vertex.
% c0-graph::= (sq . c-graph), where sq - standard quotient.
% vertex  ::= (vtype e1 e2 e3), where eI is name of corresponding edge.
% vtype   ::= G3|QG|QX, G3 - three gluon vertex type,
%                       QG - quark-gluon vertex type,
%                       GX - quark-gluon vertex type with free gluon
%                            (not yet implemented).
% If vtype = G3 then e1,e2,e3 are gluons.Its order is clock.
% If vtype = QG then e1 is in-quark, e2 is out-quark and e3 is a gluon.
%----------------------------------------------------------------------
%
% Example:
% --------
%             e1
%        ----->------
%       /            \
%       |     e2     |
%    v1 *............* v2  <=> c0=((1 . 1) (QG e3 e1 e2) (QG e1 e3 e2))
%       |            |
%       \     e3     /
%        ----->------
%
% Here: ----->----- quark,
%       ........... gluon.
%----------------------------------------------------------------------
%
%                   Transformation rules.
%                   ---------------------
%        (see: A.Kryukov & A.Rodionov
%              Program "COLOR" for computing the group-theoretic
%              weight of Feynman diagrams in non-abelian gauge theories.
%              Comp. Phys. Comm., 48(1988),327-334)
%
%        :                  (       :                    :        )
%        :            1     (       :                    :        )
%        :         = ---    (       *         -          *        )  (9)
%        :            A     (      / \                  / \       )
%   .....*.....             ( ....*-<-*....        ....*->-*....  )
%
%   --<--*--<--             ( -<--     --<-            --<--      )
%        :                  (     \   /          1                )
%        :         =  A     (      | |        - ---               ) (10)
%        :                  (     /   \          n                )
%   --<--*--<--             ( -<--     --<-            --<--      )
%
% Here: n - order of SU(n) group,
%       A - normalization factor. Sp(TiTj) = A*Delta(i,j).           (3)
%
%----------------------------------------------------------------------

%----------------------- Selector/Constructor -------------------------

symbolic inline procedure getcoef g0$ car g0$
symbolic inline procedure getvl g0$ cdr g0$

symbolic inline procedure putcoef(g0,c)$ rplaca(g0,c)$
symbolic inline procedure putvl(g0,vl)$ rplacd(g0,vl)$

symbolic inline procedure gettv v$ car v$
symbolic inline procedure gete1 v$ cadr v$
symbolic inline procedure gete2 v$ caddr v$
symbolic inline procedure gete3 v$ cadddr v$
symbolic inline procedure getinq v$ gete1 v$
symbolic inline procedure getoutq v$ gete2 v$

symbolic inline procedure puttv(v,tv)$ rplaca(v,tv)$
symbolic inline procedure pute1(v,e)$ rplaca(cdr v,e)$
symbolic inline procedure pute2(v,e)$ rplaca(cddr v,e)$
symbolic inline procedure pute3(v,e)$ rplaca(cdddr v,e)$
symbolic inline procedure putinq(v,e)$ pute1(v,e)$
symbolic inline procedure putoutq(v,e)$ pute2(v,e)$

symbolic inline procedure mkg0(c,g0)$ c . g0$

symbolic inline procedure chktv(v,tv)$ gettv v eq tv$
symbolic inline procedure qgvp v$ chktv(v,'qg)$
symbolic inline procedure g3vp v$ chktv(v,'g3)$

symbolic inline procedure zcoefp g0$ null numr getcoef g0$

symbolic inline procedure mkcopyg0 g0$
  %--------------------------------------------------------------------
  % Make a copy of structure g0 without copying coeffitient.
  %--------------------------------------------------------------------
  getcoef g0 . mkcopy getvl g0$

symbolic inline procedure chkhp v$
  %--------------------------------------------------------------------
  % Check headpole.
  %--------------------------------------------------------------------
  %            -->--                     ........
  %           /     \                   :        :
  %          |       |                  :        :
  %   .......*v      | = 0,     ........*v       : = 0
  %          |       |                  :        :
  %           \     /                   :        :
  %            --<--                     ........
  %--------------------------------------------------------------------
  gete1 v eq gete2 v or gete1 v eq gete3 v or gete2 v eq gete3 v$

%----------------------------- Debug ----------------------------------

%symbolic inline procedure DMessage x$
%  << prin2 "====>"$ print x >>$

%----------------------------- Others ---------------------------------

symbolic procedure cerror u$
  %--------------------------------------------------------------------
  % Output error message and interupt evaluation.
  %--------------------------------------------------------------------
  << terpri!* t$
     for each x in "***** xCOLOR:" . u do <<
       prin2!* " "$
       varpri(x,x,nil)
    >>$
    terpri!* t$
    error1()
  >>$

symbolic procedure removev(g0,v)$
  %--------------------------------------------------------------------
  % Remove vertex v from g0.
  % g0 is modified.
  %--------------------------------------------------------------------
  if null g0 then cerror list("Vertex",v,"is absent.")
  else if cadr g0 eq v then rplacd(g0,cddr g0)
  else removev(cdr g0,v)$

symbolic inline procedure existqgv g0$
  %--------------------------------------------------------------------
  % Find quark-gluon vertex in g0.
  % Return quark-gluon vertex or nil.
  %--------------------------------------------------------------------
  assoc('qg,getvl g0)$

symbolic inline procedure exist3gv g0$
  %--------------------------------------------------------------------
  % Find three-gluon vertex in g0.
  % Return three-gluon vertex or nil.
  %--------------------------------------------------------------------
  assoc('g3,getvl g0)$

symbolic procedure mkcopy u$
  %--------------------------------------------------------------------
  % Make a copy of any structures.
  %--------------------------------------------------------------------
  if atom u then u else mkcopy car u . mkcopy cdr u$

symbolic inline procedure revv(v,e)$
  %--------------------------------------------------------------------
  % Revolve v such that e become the first edge.
  % v is modified.
  %--------------------------------------------------------------------
  if null g3vp v or null memq(e,cdr v)
    then cerror list("Edge",e,"is absent in vertex",v)
  else revv0(v,e)$

symbolic procedure revv0(v,e)$
  %--------------------------------------------------------------------
  % Revolve v such that e become the first edge.
  % v is modified.
  %--------------------------------------------------------------------
  if gete1 v eq e then v
  else begin scalar w$
         w := gete1 v$
         pute1(v,gete2 v)$
         pute2(v,gete3 v)$
         pute3(v,w)$
         return revv0(v,e)$
       end$ % RevV0

%------------------------ Global/Fluid --------------------------------

global '(su_order spur_tt n!*!*2!-1)$

su_order := '(3 . 1)$        % default value
spur_tt  := '(1 . 2)$        % default value
n!*!*2!-1:= '(8 . 1)$        % default value

%----------------------------------------------------------------------

symbolic procedure color0 g0$
  %--------------------------------------------------------------------
  % g0 - c-graph.
  % Return colour factor (s.q.).
  %--------------------------------------------------------------------
  if chkcg g0 then
    multsq(afactor g0,color1(mkg0(1 ./ 1,mkcopy g0),nil,nil ./ 1))
  else cerror list "This is impossible!"$

symbolic procedure chkcg g0$
  %--------------------------------------------------------------------
  % Check structure g0.
  % Return t if g0 is ok else output message and interupt program.
  %--------------------------------------------------------------------
  begin scalar x,u,vl,z$
    vl := g0$
    while vl do <<
      x := car vl$
      if gettv x eq 'qg then <<
          if (z:=assoc(getinq x,u)) then
            if cdr z eq 'outq then rplacd(z,'ok)
            else cerror
               list(car z,"can not use as in-quark in vertex",x)
          else u:=(getinq x . 'inq) . u$
          if (z:=assoc(getoutq x,u)) then
            if cdr z eq 'inq then rplacd(z,'ok)
            else cerror
               list(car z,"can not use as out-quark in vertex",x)
          else u:=(getoutq x . 'outq) . u$
          if (z:=assoc(gete3 x,u)) then
            if cdr z eq 'gluon then rplacd(z,'ok)
            else cerror list(car z,"can not use as gluon in vertex",x)
          else u:=(gete3 x . 'gluon) . u$
        >>
      else if gettv x eq 'g3 then <<
          if (z:=assoc(gete1 x,u)) then
            if cdr z eq 'gluon then rplacd(z,'ok)
            else cerror list(car z,"can not use as gluon in vertex",x)
          else u:=(gete1 x . 'gluon) . u$
          if (z:=assoc(gete2 x,u)) then
            if cdr z eq 'gluon then rplacd(z,'ok)
            else cerror list(car z,"can not use as gluon in vertex",x)
          else u:=(gete2 x . 'gluon) . u$
          if (z:=assoc(gete3 x,u)) then
            if cdr z eq 'gluon then rplacd(z,'ok)
            else cerror list(car z,"can not use as gluon in vertex",x)
          else u:=(gete3 x . 'gluon) . u$
        >>
      else cerror list("Invalid type of vertex",x)$
      vl := cdr vl$
    >>$
    while u do <<
      x := car u$
      if null(cdr x eq 'ok) then
        cerror list(car x,"is a free particle. Not yet implemented.")
      else if null idp car x then
        cerror list(car x,"invalid as a name of particle.")
      else u:=cdr u$
    >>$
    return t$  % o.k.
  end$ % ChkCG

symbolic procedure afactor g0$
  %--------------------------------------------------------------------
  % Calculate A-factor of g0:
  % A**(<num. of QG-vert.>+<num. of 3G-vert.>-<num. of free gluons>)/2
  % Return A-factor (s.q.).
  %--------------------------------------------------------------------
  begin scalar n$
    n := 0$
    for each x in g0 do if qgvp x or g3vp x then n := n + 1$
    if remainder(n,2) neq 0 then
      cerror list("Invalid structure of c0-graph.",
        if null g0 then nil
        else if null cdr g0 then car g0
        else 'times . g0)$
    return exptsq(spur_tt,n/2)$
  end$ % AFactor

%symbolic procedure Color1(g0,st,result)$ Color2(g0,st,result)$

symbolic procedure color1(g0,st,result)$
  %--------------------------------------------------------------------
  % g0 - c0-graph,
  % st - stack for still uncalculated graphs,
  % Return results - colour factor (s.q.).
  %--------------------------------------------------------------------
  if zcoefp g0 or null getvl g0 then
    if null st then addsq(getcoef g0,result)
    else color1(car st,cdr st,addsq(getcoef g0,result))
  else begin scalar v$
%
%  Patch from 15/08/93
%
%   if (v:=Exist3GV g0) then <<
%        if ChkHP v then return Color1((nil ./ 1) . nil,st,result)$
%        g0 := Split3GV(g0,v)$
%        return Color1(car g0,cdr g0 . st,result)
%     >>
    if (v:=existqgv g0) then <<
        if chkhp v then return color1((nil ./ 1) . nil,st,result)$
        g0 := removeg(g0,v)$
        return
          color1(car g0
                ,if cdr g0 then (cdr g0 . st) else st
                ,result
                )
      >>
    else if (v:=exist3gv g0) then <<
         if chkhp v then return color1((nil ./ 1) . nil,st,result)$
         g0 := split3gv(g0,v)$
         return color1(car g0,cdr g0 . st,result)
      >>
    else cerror list("Invalid structure of c0-graph."
           ,if null g0 then nil
            else if null cdr g0 then car g0
            else 'times . g0
                    )$
  end$ % Color1

symbolic procedure removeg(g0,v1)$
  %--------------------------------------------------------------------
  % Remove gluon which containe in quark-gluon vertex(v1).
  % Return pair (g1.g2), where g1 and g2 are graphs.
  %--------------------------------------------------------------------
  begin scalar v2$
    v2 := finde(getvl g0,gete3 v1)$
    if car v2 eq v1 then v2 := finde(cdr v2,gete3 v1)$
    if null v2 then cerror list("Free edge",gete3 v1,"in vertex",v1)$
    v2 := car v2$
    if chkhp v2 then return (((nil ./ 1) . nil) . nil)$
    if qgvp v2 then return removeg1(g0,v1,v2)
    else if g3vp v2 then return removeg2(g0,v1,v2)
    else cerror list("Invalid type of vertex",v1)$
  end$ % RemoveG

symbolic procedure finde(vl,e)$
  %--------------------------------------------------------------------
  % Find vertex included edge e in vertex list vl.
  % Return vertex list started by vertex included e or nil.
  %--------------------------------------------------------------------
  if null vl then nil
  else if memq(e,cdar vl) then vl
  else finde(cdr vl,e)$

symbolic procedure removeg1(g0,v1,v2)$
  %--------------------------------------------------------------------
  % Remove gluon between two quark-gluon verticies v1 and v2.
  % Return pair (g1.g2), where g1 and g2 are graphs.
  %--------------------------------------------------------------------
  begin scalar v3,v6,g1,w$
    removev(g0,v1)$
    removev(g0,v2)$
    %------------------------------------------------------------------
    %      --<--
    %     /     \
    %    |       |
    %  v1*.......*v2  =  n**2-1
    %    |       |
    %     \     /
    %      -->--
    %------------------------------------------------------------------
    %DMessage "2. 3j-symbol?"$
    if getinq v1 eq getoutq v2 and getoutq v1 eq getinq v2 then
      return (mkg0(multsq(n!*!*2!-1,getcoef g0),getvl g0) . nil)$
    %------------------------------------------------------------------
    %           v1
    %  v3--<----*--<--                    v3--<----
    %           :     \                            \
    %           :      |                            |
    %           :      |  =  (n**2-1)/n             |
    %           :      |                            |
    %           :     /                            /
    %  v5-->----*-->--                    v5-->----
    %           v2
    %------------------------------------------------------------------
    %DMessage "3. Arc.?"$
    v3 := finde(getvl g0,getoutq v1)$
    if getinq v1 eq getoutq v2 then <<
        if v3 then putinq(car v3,getinq v2)
        else cerror list("Free edge",getoutq v1,"in vertex",v1)$
        return
          (mkg0(multsq(quotsq(n!*!*2!-1,su_order),getcoef g0),getvl g0)
          . nil
          )$
      >>$
    v6 := finde(getvl g0,getoutq v2)$
    if getoutq v1 eq getinq v2 then <<
        if v6 then putinq(car v6,getinq v1)
        else cerror list("Free edge",getoutq v2,"in vertex",v2)$
      return
        (mkg0(multsq(quotsq(n!*!*2!-1,su_order),getcoef g0),getvl g0)
        . nil
        )$
      >>$
    %------------------------------------------------------------------
    %           v1
    %  v3--<--*--<--     v3--<--     --<--v4         v3--<--v4
    %         :                 \   /
    %         :                  | |             1
    %         :       =          | |          - ---            (10')
    %         :                  | |             n
    %         :                 /   \
    %  v5-->--*-->--     v5-->--     -->--v6         v5-->--v6
    %         v2
    %                            (a)                    (b)
    %------------------------------------------------------------------
    %DMessage "4. Common case."$
    if null v3 or null v6 then
      cerror list("Invalid structure of c-graph"
                 ,if null g0 then nil
                  else if null cdr g0 then car g0
                  else 'times . g0
                 )$
    v3 := car v3$
    v6 := car v6$
    putinq(v3,getinq v2)$
    putinq(v6,getinq v1)$
    %------------------------------------------------------------------
    % Diagram (b)
    %------------------------------------------------------------------
    g1 := mkcopyg0 g0$
    w := getvl g1$
    v3 := car member(v3,w)$
    v6 := car member(v6,w)$
    putinq(v3,getinq v1)$
    putinq(v6,getinq v2)$
    %------------------------------------------------------------------
    return
      (g0 . mkg0(multsq(quotsq(('-1 ./ 1),su_order),getcoef g1),w))$
  end$

symbolic procedure removeg2(g0,v1,v2)$
  %--------------------------------------------------------------------
  % Remove gluon between quark-gluon(v1) and three-gluon(v2) verticies.
  % Return pair (g1.g2), where g1 and g2 are graphs.
  %--------------------------------------------------------------------
  begin scalar g1,z,u1,u2$
    v2 := revv(v2,gete3 v1)$
    puttv(v2,'qg)$
    g1 := mkcopyg0 g0$
    u1 := car member(v1,g1)$
    u2 := car member(v2,g1)$
    %------------------------------------------------------------------
    %      2  v2 3              3   v2 3               3   v2 3
    %  v6.....*.....v5       v6..   *......v5      v6...   *.....v5
    %         :                  .  |\                  . /|
    %         :1         =        . | \2       -         . |1
    %         :                    .|  \                / .|
    %  v4-->--*-->--v3       v4-->--*   ->-v3      v4->-   *--->-v3
    %         v1                 1  v1                     v1  2
    %
    %                              (a)                    (b)
    %------------------------------------------------------------------
    %DMessage "2. Common case."$
    z := gete2 v1$
    pute2(v1,gete3 v1)$
    pute3(v1,gete2 v2)$
    pute2(v2,z)$
    %------------------------------------------------------------------
    % Diagram (b)
    %------------------------------------------------------------------
    z := gete1 u1$
    pute1(u1,gete3 u1)$
    pute3(u1,gete2 u2)$
    pute2(u2,gete1 u2)$
    pute1(u2,z)$
    %------------------------------------------------------------------
    return (g0 . mkg0(negsq getcoef g1,getvl g1))$
  end$ % RemoveG2

symbolic procedure split3gv(g0,v1)$
  %--------------------------------------------------------------------
  % Split three-gluon verticies v1 onto three quark-gluon verticies.
  % g0 is modified.
  % Return (g1 . g2), where g1 and g2 are graphs.
  %--------------------------------------------------------------------
  begin scalar v5,v6,g1,z$
    %------------------------------------------------------------------
    %         v2                   v2                  v2
    %         :                    :                   :
    %         :                    :                   :
    %         :          =         *v6       -         *v6        (9')
    %         :                   / \                 / \
    %  v4.....*.....v3       ....*-<-*....       ....*->-*....
    %         v1                 v1  v5              v1  v5
    %
    %                             (a)                 (b)
    %------------------------------------------------------------------
    v5 := list('qg,gensym(),gensym(),gete2 v1)$
    v6 := list('qg,gensym(),getinq v5,gete1 v1)$
    puttv(v1,'qg)$
    pute1(v1,getoutq v5)$
    pute2(v1,getinq v6)$
    putvl(g0,v5 . v6 . getvl g0)$
    %------------------------------------------------------------------
    % Diagram (b)
    %------------------------------------------------------------------
    g1 := mkcopyg0 g0$
    v1 := car member(v1,getvl g1)$
    v5 := car member(v5,getvl g1)$
    v6 := car member(v6,getvl g1)$
    z := getinq v1$
    pute1(v1,getoutq v1)$
    pute2(v1,z)$
    z := getinq v5$
    pute1(v5,getoutq v5)$
    pute2(v5,z)$
    z := getinq v6$
    pute1(v6,getoutq v6)$
    pute2(v6,z)$
    %------------------------------------------------------------------
    return (g0 . mkg0(negsq getcoef g1,getvl g1))$
  end$ % Split3GV

%----------------------------------------------------------------------
endmodule;

end;
