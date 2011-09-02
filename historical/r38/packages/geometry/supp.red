%###############################################################
%
% FILE:    supp.red
% AUTHOR:  graebe
% CREATED: 2/2002
% PURPOSE: Interface for the extended GEO syntax to Reduce
% VERSION: $Id: supp.red,v 1.1 2002/12/26 16:27:22 compalg Exp $

algebraic procedure geo_simplify u; u;
algebraic procedure geo_normal u; u;
algebraic procedure geo_subs(a,b,c); sub(a=b,c);

algebraic procedure geo_gbasis(polys,vars); 
  begin 
  setring(vars,{},lex); 
  setideal(uhu,polys); 
  return gbasis uhu;
  end;

algebraic procedure geo_groebfactor(polys,vars,nondeg); 
  begin 
  setring(vars,{},lex); 
  return groebfactor(polys,nondeg);
  end;

algebraic procedure geo_normalf(p,polys,vars); 
  begin 
  setring(vars,{},lex); 
  return p mod polys;
  end;

algebraic procedure geo_eliminate(polys,vars,elivars); 
  begin 
  setring(vars,{},lex); 
  return eliminate(polys,elivars);
  end;

algebraic procedure geo_solve(polys,vars); 
  solve(polys,vars);

algebraic procedure geo_solveconstrained(polys,vars,nondegs); 
  begin scalar u;
  setring(vars,{},lex); 
  u:=groebfactor(polys,nondegs);
  return for each x in u join solve(x,vars);
  end;

algebraic procedure geo_eval(con,sol); 
  for each x in sol collect sub(x,con);

end;


