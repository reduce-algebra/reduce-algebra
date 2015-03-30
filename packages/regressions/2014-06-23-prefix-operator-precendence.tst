
load_package sets;

COMMENT longer linelength so that differences in prettyprinter margins do not show ;
lisp linelength 100;

on defn;

--b;

--a*b;

--a*--b;

a ^ - b * c ;

a / - b / c ;

a ^ - b + c ;

a ^ (- b) * c ;

- a * b ;

-b*-c;

a * b^-2 * c^3 ;

a intersection union b intersection c;

a intersection (union b) intersection c;

a union intersection b union c;

a union (intersection b) union c;

aa(1,4):=4*(u4(n+1)-u4(n))/ht+(p*c**2*(u2(m+2)-u2(m-2)+u2(m+1,k+1)+
         u2(m+1,k-1)-u2(m-1,k+1)-u2(m-1,k-1))+w*(u4(m+2)-
         u4(m-2)+u4(m+1,k+1)+u4(m+1,k-1)-u4(m-1,k+1)-u4(m-1,k-1))+
         +p*c**2*(u3(m+1,k+1)+u3(m-1,k+1)-u3(m+1,k-1)-
         u3(m-1,k-1)+u3(k+2)-u3(k-2))+v*(u4(m+1,k+1)+u4(m-1,k+1)-
         u4(m+1,k-1)-u4(m-1,k-1)+u4(k+2)-u4(k-2)))/hx+ht*
         (2*w**2*(-u4(m+2)+2*u4(m)-u4(m-2))+4*w*p*c**2*(-u2(m+2)+
         2*u2(m)-u2(m-2))+2*c**2*(-u4(m+2)+2*u4(m)-u4(m-2))+
         4*p*v*c**2*(-u3(k+2)+2*u3(k)-u3(k-2))+2*c**2*(-u4(k+2)+
         2*u4(k)-u4(k-2))+2*v**2*(-u4(k+2)+2*u4(k)-u4(k-2))+
         4*p*v*c**2*(-u2(m+1,k+1)+u2(m+1,k-1)+u2(m-1,k+1)-
         u2(m-1,k-1))+4*w*p*c**2*(-u3(m+1,k+1)+u3(m+1,k-1)+
         u3(m-1,k+1)-u3(m-1,k-1))+4*w*v*(-u4(m+1,k+1)+
         u4(m+1,k-1)+u4(m-1,k+1)-u4(m-1,k-1)))/hx/hx$

off defn;

end;

