% Small test of the character metrics table data.

lisp;
on comp;

in "charmetrics.red"$

<<
  for i := id2int '!e:id2int '!m do
    begin
      if not lookupchar(get('General, 'font_number), i) then
        printc "Lookup failed"
      else print list(i, c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo);
    end;
  lookupchar(get('General, 'font_number), id2int '!f);
  princ "Kern info for f-i is "; print lookupkernadjustment id2int '!i;
  princ "Ligature for f-i is "; print lookupligature id2int '!i;
  princ "Kern info for f-l is "; print lookupkernadjustment id2int '!l;
  princ "Ligature for f-l is "; print lookupligature id2int '!l;
  nil >>;


end;

