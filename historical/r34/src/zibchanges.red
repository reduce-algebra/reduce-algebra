module ZIBchanges;

Comment Some useful changes for a little speedup from ZIB Berlin;

symbolic procedure update!-pline(x,y,pline);
   % Adjusts origin of expression in pline by (x,y).
   if x=0 and y=0 then pline
    else for each j in pline collect
            (((caaar j #+ x) . (cdaar j #+ x)) . (cdar j #+ y)) . cdr j;


symbolic procedure putpline w;
   begin
      if posn!* #+ cdar w > linelength nil #- spare!* then terpri!* t;
      pline!* :=
         append(update!-pline(posn!* #- orig!*, ycoord!*, caar w),
                pline!*);
      posn!* := posn!* #+ cdar w;
      ymin!* := min(ymin!*, cadr w #+ ycoord!*);
      ymax!* := max(ymax!*, cddr w #+ ycoord!*)
  end;

% to be continued ...

endmodule;

end;
