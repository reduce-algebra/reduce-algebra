module transfns;

algebraic;

algebraic procedure trigexpand wws;
  wws where { sin(~x+~y) => sin(x)*cos(y)+cos(x)*sin(y),
              cos(~x+~y) => cos(x)*cos(y)-sin(x)*sin(y),
              sin((~n)*~x) => sin(x)*cos((n-1)*x)+cos(x)*sin((n-1)*x)
                   when fixp n and n>1,
              cos((~n)*~x) => cos(x)*cos((n-1)*x)-sin(x)*sin((n-1)*x)
                   when fixp n and n>1 };

algebraic procedure hypexpand wws;
  wws where {sinh(~x+~y) => sinh(x)*cosh(y)+cosh(x)*sinh(y),
             cosh(~x+~y) => cosh(x)*cosh(y)+sinh(x)*sinh(y),
           sinh((~n)*~x) => sinh(x)*cosh((n-1)*x)+cosh(x)*sinh((n-1)*x)
                   when fixp n and n>1,
           cosh((~n)*~x) => cosh(x)*cosh((n-1)*x)+sinh(x)*sinh((n-1)*x)
                   when fixp n and n>1 };

operator !#ei!&; !#ei!&(0):=1;

trig!#ei!& := {!#ei!&(~x)**(~n) => !#ei!&(n*x),
               !#ei!&(~x)*!#ei!&(~y) => !#ei!&(x+y)};

let trig!#ei!&;

algebraic procedure trigreduce wws;
        <<wws:=(wws where {cos(~x) => (!#ei!&(x)+!#ei!&(-x))/2,
                           sin(~x) => -i*(!#ei!&(x)-!#ei!&(-x))/2});
          wws:=(wws where {!#ei!&(~x) => cos x +i*sin x})>>;

algebraic procedure hypreduce wws;
        <<wws:=(wws where {cosh(~x) => (!#ei!&(x)+!#ei!&(-x))/2,
                           sinh(~x) => (!#ei!&(x)-!#ei!&(-x))/2});
          wws:=(wws where {!#ei!&(~x) => cosh(x)+sinh(x)})>>;

endmodule;

end;
