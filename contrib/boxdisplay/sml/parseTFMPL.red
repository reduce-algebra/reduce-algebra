lisp;

set!-print!-precision 50;

symbolic procedure parse_tfm_file(infile, outfile, skewchar);
  begin
    scalar tfm;
    tfm := read!-s!-from!-file infile;
    outfile := open(outfile, 'output);
    outfile := wrs outfile;
    parse_tfm(tfm, skewchar);
    close wrs outfile
  end;

symbolic procedure read!-s!-from!-file ff;
  begin
    scalar a, r;
    a := open(ff, 'input);   
    a := rds a;              
    r := read();             
    close rds a;             
    return r                 
  end;

fluid '(skew);
symbolic procedure parse_tfm (tfm, skewchar);
  begin
    scalar skew; 
    skew := skewchar;
    while (caar tfm) neq 'CHARACTER do tfm := cdr tfm;
    for each char in tfm do <<
      if ((car char) neq 'CHARACTER) or ((cadr char) neq 'O) then error(0,0);
      princ "C"; print caddr char;
      for each prop in cdddr char do parse_prop prop >>;  
    printc "E"
  end;

symbolic procedure parse_prop prop; 
  begin
    scalar type;
    type := car prop;
    if type = 'CHARWD or type = 'CHARHT or type = 'CHARDP or type = 'CHARIC then parse_simple_prop prop
    else if type = 'NEXTLARGER then parse_larger_prop prop
    else if type = 'VARCHAR then for each vprop in cdr prop do parse_varchar_prop vprop
    else if type = 'COMMENT then for each cprop in cdr prop do parse_comment_prop cprop
    else error(0,0)
  end;

symbolic procedure parse_simple_prop prop;
  begin
    if ((cadr prop) neq 'R) or ((length prop) neq 3) then error(0,0);
    if      car prop = 'CHARWD then princ "W" 
    else if car prop = 'CHARHT then princ "H"
    else if car prop = 'CHARDP then princ "D"
    else if car prop = 'CHARIC then princ "I";
    print caddr prop
  end;

symbolic procedure parse_larger_prop prop;
  if ((cadr prop) neq 'O) or ((length prop) neq 3) then error(0,0) 
  else << princ "L"; print caddr prop >>;

symbolic procedure parse_varchar_prop prop;
  begin
    scalar type;
    type := car prop;
    if      type = 'TOP then princ "T"
    else if type = 'REP then princ "R"
    else if type = 'MID then princ "M"
    else if type = 'BOT then princ "B"
    else error(0,type);
    if (cadr prop) neq 'O then error(0,0);
    print caddr prop 
  end;

symbolic procedure parse_comment_prop prop;
  begin
    scalar type;
    type := car prop;
    if      type = 'LIG then return nil
    else if type = 'KRN then parse_kern_prop prop
    else error(0,0)
  end;

symbolic procedure parse_kern_prop prop;
  if ((cadr prop) neq 'O) or ((cadddr prop) neq 'R) then error(0,0)
  else if (caddr prop) neq skew then nil
  else << princ "S"; print cadddr cdr prop >>; 


