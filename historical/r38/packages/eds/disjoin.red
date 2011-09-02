module disjoin;

% Convert a variety to a disjoint union of sub-coframings

% Author: David Hartley

fluid '(!*edsverbose !*edsdebug !*arbvars !*varopt !*groebopt
        !*solveinconsistent depl!* cfrmcrd!* cfrmrsx!* xvars!*
	!*edssloppy !*edsdisjoint);


Comment.  The edsdisjoin routines decompose a solution returned by
eds*solve into a disjoint union of solutions (rmaps).  The operations
intersection and difference are somewhat slow, so the whole process is
only performed automatically if the switch edsdisjoint is on.

endcomment;


symbolic operator disjoin;
symbolic procedure disjoin u;
   (makelist foreach rm in
      edsdisjoin(foreach s in getrlist u collect !*a2rmap s) collect
	 !*rmap2a rm) where !*edsdisjoint = t;


symbolic procedure edsdisjoin u;
   % u:list of rmap -> edsdisjoin:list of rmap
   if !*edsdisjoint then reverse edsdisjoin1(u,{}) else u;


symbolic procedure edsdisjoin1(u,v);
   % u,v:list of rmap -> edsdisjoin1:list of rmap
   % rmaps in v are disjoint already.
   if null u then v
   else edsdisjoin1(cdr u,edsdisjoin2(car u,v));


symbolic procedure edsdisjoin2(x,v);
   % x:rmap, v:list of rmap -> edsdisjoin2:list of rmap
   % rmaps in v are disjoint already.
   if null v then {x}
   else 
      begin scalar y,z;
      y := car v;
      return 
         if z := rmapintersection(x,y) then
            append(rmapdifference(y,x),
            append(z,edsdisjoin1(rmapdifference(x,y),cdr v)))
         else
            y . edsdisjoin2(x,cdr v);
   end;


symbolic procedure rmapintersection(x,y);
   % x,y:rmap -> rmapintersection:list of rmap
   begin scalar lhx,xl,z,rsx,rsy,mx,my;
   % First a simple check which may save us going into solve
   rsy := pullbackrsx(cadr y,car x);
   if 0 member rsy then return nil;
   rsx := pullbackrsx(cadr x,car y);
   if 0 member rsx then return nil;
   % Now just pile everything together and resolve
   return rmapeval {append(car x,car y),append(rsx,rsy)};
   end;


symbolic procedure rmapdifference(x,z);
   % x,z:rmap -> rmapdifference:list of rmap
   % NO LONGER assumes z is a sub-coframing of x
   begin scalar m;
   m := foreach s in car z join 
	   if s := numr subsq(subtrsq(simp!* car s,simp!* cdr s),car x)
	     then rmapeval {car x,addrsx(s,cadr x)};
   m := append(m,
        foreach s in cadr z join
           rmapeval {(0 . s) . car x,cadr x});
   return edsdisjoin purge m;
   end;


symbolic procedure rmapeval x;
   % x:rmap -> rmapeval:list of rmap
   % Resolve a badly formed rmap into a disjoint list of rmaps.
   % The map part of x may include equations expr=expr.
   begin scalar xl,vl;
   % First resolve map part, solving for lhs variables where possible
   vl := purge foreach s in car x collect car s;
   vl := {intersection(cfrmcrd!*,vl),setdiff(cfrmcrd!*,vl)};
   xl := foreach s in car x collect
           subtrsq(simp!* car s,simp!* cdr s);
   return foreach s in edssolvegraded(xl,vl,cadr x) collect
      if car s then cdr s
      else
      << lprim "Could not resolve decomposition entirely";
         {foreach q in cdr s collect 0 . mk!*sq q,cadr x} >>;
   end;
   
endmodule;

end;
