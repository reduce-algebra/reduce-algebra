module ftr;  % Various utilities for working with files and modules.

% Author: Anthony C. Hearn.

% NOTE: This module uses Standard Lisp global *RAISE as a fluid.

% This module supports several applications of file-transform.
% Currently we have:

% make-dist-files:

% module_file_split:

% downcase_file:

% trunc:


create!-package('(ftr),'(util));

fluid '(!*echo !*downcase !*upcase current!-char!* previous!-char!*
        member!-channel!* old!-channel!*);

global '(!*raise charassoc!*);

global '(dir!*);  % output directory name.

% global '(dirchar!*);

switch downcase,upcase;

dir!* := "";   % default.

% dirchar!* := "/";


% ***** utility functions *****.

symbolic procedure s!-match(u,v);
   % Returns true if list of characters u begins with same characters
   % (regardless of case) as lower case string v.
   s!-match1(u,explode2 v);

symbolic procedure s!-match1(u,v);
   null v
      or u and (car u eq car v
		   or red!-uppercasep car u
		      and red!-char!-downcase car u eq car v)
	 and s!-match1(cdr u,cdr v);

symbolic procedure reverse!-chars!-to!-string u;
   compress('!" . reversip('!" . u));

symbolic procedure red!-lowercasep u;
   u memq '(!a !b !c !d !e !f !g !h !i !j !k !l !m !n !o !p !q !r !s
	    !t !u !v !w !x !y !z);

symbolic procedure red!-uppercasep u;
   u memq '(!A !B !C !D !E !F !G !H !I !J !K !L !M !N !O !P !Q !R !S !T
	    !U !V !W !X !Y !Z);

symbolic procedure red!-char!-downcase u;
   (if x then cdr x else u) where x = atsoc(u,charassoc!*);

symbolic procedure string!-upcase u;
   begin scalar z;
      if not stringp u then u := '!" . append(explode2 u,'(!"))
       else u := explode u;
      for each x in u do z := red!-char!-upcase x . z;
      return compress reverse z
   end;

symbolic procedure red!-char!-upcase u;
   (if x then car x else u) where x = rassoc(u,charassoc!*);


% ***** functions for manipulating regular REDUCE module files *****.

symbolic procedure module_file_split u;
   file!-transform(u,function module!-file!-split1);

symbolic procedure module!-file!-split1;
   begin scalar x,!*raise;
      while not errorp (x := errorset!*('(uread),t))
	    and (x := car x) neq !$eof!$
	    and x neq 'END!; do
	 if x neq 'MODULE then rerror(ftr,1,"Invalid module format")
          else begin scalar ochan,oldochan,y;
	     y := xread t;   % Should be module name.
	     ochan:= open(concat(dir!*,concat(mkfil y,".red")),'output);
             oldochan := wrs ochan;
	     prin2 "module "; prin2 y; prin2 ";";
             read!-module();
	     wrs oldochan;
	     close ochan
            end
   end;

symbolic procedure uread;
   begin scalar !*raise; !*raise := t; return read() end;

symbolic procedure read!-module;
   begin integer eolcount; scalar x,y;
      eolcount := 0;
   a: if errorp (x := errorset!*('(readch),t))
         or (x := car x) = !$eof!$ 
         or eolcount > 20
	then rerror(ftr,2,"Invalid module format")
       else if x = !$eol!$ then eolcount := eolcount+1
       else eolcount := 0;
      prin2 x;
      if x memq '(!e !E)
         then if y = '(L U D O M D N E)
		  or y = '(!l !u !d !o !m !d !n !e)
		then <<prin2 readch();
		       terpri();
		       terpri();
		       prin2t "end;";
		       return nil>>
               else y := list x
	else if x memq '(N D M O U L !n !d !m !o !u !l)
	 then y := x . y
        else y := nil;
     go to a 
   end;

symbolic procedure make!-dist!-files u;
   % Makes a set of distribution files from the list of packages u.
   % Setting u to packages* in $rsrc/build/packages.red makes complete
   % set.
   for each x in u do make_dist_file x;

symbolic procedure make_dist_file x;
   begin scalar !*downcase,!*echo,!*int,!*lower,msg,!*raise,ochan,
		oldochan,v;
      !*downcase := t;
      v := concat(string!-downcase x,".red");
      prin2 "Creating ";
      prin2 v;
      prin2t " ...";
      ochan := open(mkfil v,'output);
      oldochan := wrs ochan;
      evload list x;   % To get package list.
      v := get(x,'package);
      if null v then v := list x;
      for each j in v do
	 file!-transform(module2file(j,x),function write_module);
      prin2t if !*downcase then "end;" else "END;";
      wrs oldochan;
      close ochan
   end;

symbolic procedure module2file(u,v);
   % Converts the module u to a fully rooted file name with v the
   % package name, assuming files exist on $rsrc followed by path
   % defined by package given by associate of u in modules!*.
   begin scalar x;
      x := "$reduce/src/";
      for each j in get(v,'path) do
%        x := concat(x,concat(string!-downcase j,dirchar!*));
	 x := concat(x,concat(string!-downcase j,"/"));
      return concat(x,concat(string!-downcase u,".red"))
   end;

symbolic procedure write_module;
   begin scalar x; repeat (x := write!-line nil) until x eq 'done end;

symbolic procedure write!-line bool;
   begin integer countr; scalar x,y;
      countr := 0;
      % EOF kludge.
      while (x := readline()) = "" and countr<10 do countr := countr+1;
      if countr=10 then return 'done
       else if countr>0 then for i:=1:countr do terpri();
      y := explode2 x;
      if null bool and s!-match(y,"endmodule;")
%        or bool and s!-match(x,"end;")
	then <<prin2t if !*upcase then string!-upcase x
		       else if !*downcase then string!-downcase x
		       else x;
	       if null bool then <<terpri(); terpri()>>;
	       return 'done>>;
      x := y;
  a:  if null x then return terpri();
      y := car x;
  b:  if y = '!% then return <<for each j in x do prin2 j; terpri()>>
       else if y = '!"
	then <<prin2 y;
	       x := write!-until(cdr x,'(!"))>>
       else if y = '!!
	then <<prin2 y;
	       x := cdr x;
	       if null x then rerror(ftr,3,"Missing character after !");
	       prin2 car x>>
       else if s!-match(x,"comment")
	then <<if !*upcase then prin2 "COMMENT" else prin2 "comment";
	       for j := 1:7 do x := cdr x;
	       x := write!-until(x,'(!; !$))>>
       else if y = '!  then
	  <<countr := 1;
	    while (x := cdr x) and (y := car x) = '!  do
	       countr := countr + 1;
	    if null x then return terpri();   % Trailing blanks.
	    for i:=1:countr do prin2 " ";
	    go to b>>
       else <<prin2 if !*upcase and red!-lowercasep y
		      then red!-char!-upcase y
		     else if !*downcase and red!-uppercasep y
		      then red!-char!-downcase y
		     else y>>;
      x := cdr x;
      go to a
   end;

symbolic procedure write!-until(x,u);
   begin scalar y;
 a:   if null x
	then <<terpri();
	       x := explode2 readline(); go to a>>;
      y := car x;
      prin2 y;
      if y memq u then return x;
      x := cdr x;
      go to a
   end;


% ***** Converting a file to lower case *****.

symbolic procedure downcase_file u;
   % Convert file named u to lower case version.
   begin scalar ochan,oldochan,!*downcase,!*echo,!*int,!*raise;
      prin2t "*** Output is in file 'output'";
      !*downcase := t;
      ochan := open("output",'output);
      oldochan := wrs ochan;
      file!-transform(u,function write!-file);
      wrs oldochan;
      close ochan
   end;

symbolic procedure write!-file;
   begin scalar x;
      repeat (x := write!-line t) until x eq 'done end;


% ***** truncating a file to 80 characters *****.

symbolic procedure trunc u;
   % Truncate a file to 80 characters.
   <<lprim "output is in file 'output'";
     file!-transform(u,function read!-trunc)>>;

symbolic procedure read!-trunc;
   begin integer count;
	 scalar !*echo,!*int,!*raise,bool,ochan,oldochan,x;
      oldochan := wrs (ochan := open("output",'output));
      while (x := readch()) neq !$eof!$ do
	 if x eq !$eol!$ then <<bool := nil; count := 0; terpri()>>
	  else if null bool
	   then <<prin2 x; bool := (count := count+1)>79>>;
      write oldochan;
      close ochan
   end;

endmodule;

end;

% The material in the rest of this file is obsolete.

% ***** Functions for manipulating files on the HP 9836 *****.

symbolic procedure merge!-9836!-files u;
   % merges a list of 9836 files into a Cambridge format file v
   % corresponding to a UNIX directory.
   % Files are separated by the string "./ ADD NAME= <file name>.
   % Last file is terminated by "./ ENDUP".
   begin scalar ochan,oldochan,!*echo,!*int,!*raise;
      ochan := open(mkfil u,'output);
      oldochan := wrs ochan;
      for each x in get(u,'file!-list) do 
         begin scalar y;
            if null(y := get(u,'alias)) then y := u;
            y := mkfilename(x,y);
            prin2 "./ ADD NAME=";
            if atom x then prin2t string!-upcase x
             else <<prin2 string!-upcase car x;
                    prin2 "."; 
                    prin2t string!-upcase cdr x>>;
            file!-transform(y,function writefile)
         end;
      prin2t "./ ENDUP";
      wrs oldochan;
      close ochan
   end;

symbolic procedure mkfilename(u,v);
   begin
      if atom u then u := u  . "red";
      return concat(string!-downcase v,
                    concat(":",concat(string!-downcase car u,
				      concat(".",
					     string!-downcase cdr u))))
   end;

symbolic procedure writefile;
   begin scalar countr,x;
      countr := 0;
      repeat 
       <<x := readline();
        if x = "" then countr := countr+1
	 else <<if countr>0
		  then <<for i:=1:countr do terpri(); countr := 0>>;
                prin2t x>>>>
       until countr = 10;
   end;

% ***** functions for manipulating Cambridge PDS files *****.

% To use the first function, connect to the directory where you want the
% modules written, and then say

%    file!-transform("<source file>",
%                    function split!-cambridge!-format);

symbolic smacro procedure read!-ch(); current!-char!* := readch();

symbolic procedure split!-cambridge!-format;
   % splits a file in Cambridge PDS format with ./ ADD records preceding
   % each member into constituent components.
   begin scalar x,!*echo,!*raise;
      while not((x := read!-ch()) eq !$eof!$) do
	 if not previous!-char!*
	   then if x eq '!. and readch() eq '!/
		   then begin!-new!-cambridge!-member()
		  else rerror(ftr,4,
			      "File has incorrect format in first line")
	  else if previous!-char!* eq !$eol!$ and x eq '!.
		then if read!-ch() eq '!/
		       then begin!-new!-cambridge!-member()
		 else rerror(ftr,5,
			    "File has unmatched period in first column")
	  else <<prin2 x; previous!-char!* := x>>;
      close!-cambridge!-member()
   end;

symbolic procedure begin!-new!-cambridge!-member;
   begin scalar x,y,z;
      if member!-channel!* then close!-cambridge!-member();
      z := readline();
      x := cdr explode z;
      previous!-char!* := !$eol!$;
      if not ( x := matched2(x,'(!  A D D !  N A M E !=)))
	then <<terpri(); prin2 "Ignoring line ./"; prin2 z; terpri();
	       return nil>>;
      x := car x;
      while cdr x do
	 <<y := (if red!-uppercasep car x then red!-char!-downcase car x
		  else if car x eq '!$ then '!@
		else car x) . y;
	   x := cdr x>>;
      y := reverse!-chars!-to!-string y;
      terpri();
      prin2 "Processing module "; prin2 y; prin2t " ...";
      y := concat(y,".red");
      member!-channel!* := open(y,'output);
      old!-channel!* := wrs member!-channel!*
   end;

symbolic procedure matched2(u,v);
   if null v then list u
    else if null u then nil
    else car u eq car v and matched2(cdr u,cdr v);

symbolic procedure close!-cambridge!-member;
   if not member!-channel!* then nil
    else <<close member!-channel!*; wrs old!-channel!*;
	   member!-channel!* := old!-channel!* := nil>>;

symbolic procedure merge!-cambridge!-format(u,v);
   % merges a list of files u into Cambridge PDS format file v
   % with ./ ADD records preceding each member.
   begin scalar ochan,oldochan,!*echo,!*raise;
      ochan := open(mkfil v,'output);
      oldochan := wrs ochan;
      for each x in u do write!-cambridge!-member x;
      prin2t "./ ENDUP";
      wrs oldochan;
      close ochan
   end;

symbolic procedure write!-cambridge!-member u;
   begin scalar y;
      u := explode2 u;
      for each x in u do y := red!-char!-downcase x . y;
      y := concat(reverse!-chars!-to!-string y,".red");   %file name.
      y := concat(dir!*,y);
      prin2 "./ ADD NAME=";
      if eqcar(u,'!@) then u := '!$ . cdr u;
      for each x in u do prin2 x;
      terpri();
      file!-transform(y,function print!-cambridge!-file)
   end;

symbolic procedure print!-cambridge!-file;
   begin scalar x;
      while not((x := readch()) eq !$eof!$) do
%        if x eq '![ then prin2 string 0                 % PSL dependent
%        else if x eq '!] then prin2 string 4 else       % PSL dependent
	 prin2 x
   end;


% ***** and to manipulate a message from Cambridge *****.
% Note this code is PSL dependent.

symbolic procedure cambs!-msg u;
   <<lprim "output is in file 'output'";
     file!-transform(u,function read!-cambridge!-message)>>;

symbolic procedure read!-cambridge!-message;
   begin scalar !*echo,!*int,!*raise,ochan,oldochan,x;
      oldochan := wrs (ochan := open("output",'output));
      while (x := readch()) neq !$eof!$ do
	 if x eq intern string 13                     % PSL dependent
	   then if readch() neq intern string 11      % PSL dependent
		  then rerror(ftr,8,"missing ^L after ^M")
		 else terpri()
	  else prin2 x;
      wrs oldochan;
      close ochan
   end;


% ***** functions for manipulating mfe document files *****.

symbolic procedure mfe!-6to8bit(u,v);
   % converts six-bit file u into eight-bit file v.
   begin scalar ochan,oldochan;
      oldochan := wrs (ochan := open(v,'output));
      file!-transform(u,function mfe!-6to8bit1);
      wrs oldochan;
      close ochan
   end;

symbolic procedure mfe!-6to8bit1;
   begin scalar oll,x,y;
      oll := linelength 100;
      while (x := readch()) neq !$eof!$ do
	 if x eq '!^
	   then if red!-uppercasep(y := readch()) then prin2 y
		 else if y eq '![ then '!{
		 else if y eq '!] then '!}
		 else <<prin2 x; prin2 y>>
	  else if x eq '!&
	   then if (y := readch()) eq '!& then prin2 y
		 else if y eq 'e
			 and readch() eq 'p and readch() eq 'x
		  then prin2 '!!
		 else if y eq 'v
			 and (y := readch()) and readch() eq 'x
		  then prin2 y
		 else if y eq 'f
			 and readch() eq 'u and readch() eq 'x
		  then prin2 '!|
		 else if y eq 'i then prin2 "\&i"
		 else rerror(ftr,9,"Invalid character after &")
	  else if x eq '!$ then prin2 "\$"
	  else if x eq '!% then prin2 "\%"
	  else if red!-uppercasep x then prin2 red!-char!-downcase x
	  else prin2 x;
      linelength oll
   end;

symbolic procedure mfe!-8to6bit(u,v);
   % converts eight-bit file u into six-bit file v.
   begin scalar ochan,oldochan;
      oldochan := wrs (ochan := open(v,'output));
      file!-transform(u,function mfe!-8to6bit1);
      wrs oldochan;
      close ochan
   end;

symbolic procedure mfe!-8to6bit1;
   begin scalar !*raise,oll,x;
      oll := linelength 160;
      while (x := readch()) neq !$eof!$ do
	 if x eq '!& then prin2 "&&"
	  else if x eq '!\ then prin2 readch()
	  else if x eq '!! then prin2 "&EPX"
	  else if x eq '!$ then prin2 "&V$X"
	  else if x eq '!% then prin2 "&V%X"
	  else if x eq '!| then prin2 "$FUX"
	  else if x eq '!{ then prin2 "^["
	  else if x eq '!} then prin2 "^]"
	  else if red!-uppercasep x then <<prin2 '!^; prin2 x>>
	  else if red!-lowercasep x then prin2 red!-char!-upcase x
	  else prin2 x;
      linelength oll
   end;

