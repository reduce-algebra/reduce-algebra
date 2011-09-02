on latex;
(a+b)**5\(a-b)**4;
x:=(a+b)**3$
DEPEND a,c;
DF(x,c,2);
DEFID al,NAME=alpha;
DEFID be,NAME=beta;
SIN al**2+COS al**2=1;
SIN(al+be)=SIN al*COS be+COS al*SIN be;
OFF LASIMP,VERBATIM;
DEFID u,FONT=bold,ACCENT=tilde;
DEFID f,FONT=bold;
DEFID d,NAME=Delta;
DEFINDEX u(UP,DOWN,DOWN),f(UP),i(DOWN);
PDF(u e,t)+c*PDF(u e,x,2)+b*PDF(u i,x)=f e;
(u(e,j+1,k)-u(e,j,k))\ d t +c*(u(e,j,k+1)-2*u(e,j,k)+u(e,j,
k-1))\d(x)**2+ b*(u(i,j,k+1/2)-u(i,j,k-1/2))\d x=f e;
ON VERBATIM;
PRODUCT(k=1,2*n+1,f(2*i k+1)\(i(2*k+1)-1));
INT(u(e,j,k,x)*f(e,x),x);
SUM(i=0,n,SQRT u(e,i));
OFF LATEX;
end;
