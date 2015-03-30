module oc_simple_read;

% Author: Rainer Schöpf 

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


global '(!$eof!$ !$eol!$);

fluid '(ocparse!:curline);

symbolic procedure oc_readch;
   begin scalar c;
     c := readch();
     if c eq !$eof!$ then error(99,"EOF")
      else if c eq !$eol!$ then ocparse!:curline := ocparse!:curline + 1;
     return c
   end;

symbolic procedure white_line l;
   if null l then t
    else seprp car l and white_line cdr l;

symbolic procedure ltrim l;
  <<while l and seprp car l do l := cdr l; l>>;

symbolic procedure rtrim l; reverse ltrim reverse l;

symbolic procedure trim_whitespace l;
   reverse ltrim reverse ltrim l;

symbolic procedure read_to_char x;
   begin scalar c,l;
     while not((c := oc_readch()) eq x) or (c eq !$eof!$) do l := c . l;
     if c eq x then l := c . l;
     return reversip l;
   end;

symbolic procedure read_line;
   read_to_char !$eol!$;

symbolic procedure read_to_semicolon;
   read_to_char '!;;

symbolic procedure read_to_par flagc;
   % reads until empty line found
   % returns list of lines if flagc is not set
   % returns concatenation of lines (with character flagc inserted)
   %  if flagc is set
   begin scalar b,l;
     while not null (l := get_line_contents()) do
       if flagc then b := append(b, flagc . l) else b := l . b;
     return if flagc then b else reversip b
   end;

symbolic procedure split_at_char(l,c);
   % splits list of characters l at char c into individual lists
   begin scalar result,col;
     while l do <<
       if car l eq c then <<result := reversip col . result; col := nil>>
        else col := car l . col;
       l := cdr l>>;
     return reversip result
   end;

symbolic procedure join_lines (b,c);
  % join list of lines b, inserting character c
  if null b then nil
   else if null cdr b then car b
   else begin scalar result;
      b := reverse b;
      result := car b;
      while (b := cdr b) do result := append(car b, c . result);
      return result
    end;

putd('empty_line_checker,'expr,compile_regex "^\s*$");

%putd('whitespace_remover,'expr,compile_regex "\s*(\S.*\S|\S)\s*");
putd('whitespace_remover,'expr,compile_regex "\s*(\S(.*\S)?)\s*");

symbolic procedure remove_whitespace l;
   <<whitespace_remover l;
     extract_group(l,1)>>;

symbolic procedure get_line_contents;
   <<if empty_line_checker line then nil
      else <<remove_whitespace line;
             extract_group(line,1)>>>>
     where line := read_line();

symbolic procedure get_line_contents;
   begin scalar x;
     x := errorset!* ('(trim_whitespace (read_line)),!*backtrace);
     return if errorp x then nil else car x
   end;


endmodule;

module ocparse;

global '(!*oc!-parse!-actions!*);

!*oc!-parse!-actions!* := '(
   (name . read_name)
   (title . read_title)
   (constants . read_constants)
   (parameters . read_parameters)
   (dynamic_variables . read_dvars)
   (control_variables . read_cvars)
   (time_variable . read_time_var)
   (abbreviations . read_abbrevs)
   (differential_equations . read_dgls)
   (functional . read_funct)
   (boundaries . read_bounds)
   (boundary_conditions . read_bconds)
   (COMMENT . skip_comment)
   (restrictions . read_restr)
   (end_point_is_free . free_rhs)
   (target_language . read_targetlang)
);

fluid '(!*trocparse);

switch trocparse;

global '(ocparse!:errcount);

ocparse!:errcount := 0;

global '(ocparse!:idpattern ocparse!:numberpattern);

ocparse!:idpattern := "[a-zA-Z]\w*";
ocparse!:numberpattern := "[+-]?\d*(\.\d*)?([Ee][+-]?\d+)?";

global '(!*oc!-parse!-abbrevs!*
         !*oc!-parse!-functional!*
	 !*oc!-parse!-dgls!*
         !*oc!-parse!-name!*
         !*oc!-parse!-title!*
         !*oc!-parse!-restrictions!*
         !*oc!-parse!-boundaries!*
         !*oc!-parse!-bconds!*
         !*oc!-parse!-rhs!-is!-free!*
         !*oc!-parse!-targetlang!*
         !*oc!-parse!-timevar!*
);


putd('constant_matcher,'expr,
     compile_regex {"^(",ocparse!:idpattern,")\s*:?=?\s*(",
                    ocparse!:numberpattern,");?$"});

putd('variable_matcher,'expr,
     compile_regex {"^(",ocparse!:idpattern,");?$"});

fluid '(!*oc!-parse!-constants!*
        !*oc!-parse!-parameters!*
        !*oc!-parse!-dynamic!-variables!*
        !*oc!-parse!-control!-variables!*
);

symbolic procedure reset_oc_parser;
   <<ocparse!:errcount := 0;
     !*oc!-parse!-abbrevs!* := nil;
     !*oc!-parse!-functional!* := nil;
     !*oc!-parse!-dgls!* := nil;
     !*oc!-parse!-name!* := nil;
     !*oc!-parse!-title!* := nil;
     !*oc!-parse!-restrictions!* := nil;
     !*oc!-parse!-boundaries!* := nil;
     !*oc!-parse!-bconds!* := nil;
     !*oc!-parse!-rhs!-is!-free!* := 0;
     !*oc!-parse!-targetlang!* := 'c;
     !*oc!-parse!-timevar!* := nil;
     !*oc!-parse!-constants!* := nil;
     !*oc!-parse!-parameters!* := nil;
     !*oc!-parse!-dynamic!-variables!* := nil;
     !*oc!-parse!-control!-variables!* := nil>>;

symbolic procedure defined_constant cst;
   atsoc(cst,!*oc!-parse!-constants!*);

symbolic procedure register_constant(cst,value);
   !*oc!-parse!-constants!* := (cst . value) . !*oc!-parse!-constants!*;

symbolic procedure get_constant cst;
   (if x then cdr x else nil) where x := atsoc(cst,!*oc!-parse!-constants!*);

symbolic procedure defined_parameter p;
   atsoc(p,!*oc!-parse!-parameters!*);

symbolic procedure register_parameter(cst,value);
   !*oc!-parse!-parameters!* := (cst . value) . !*oc!-parse!-parameters!*;

symbolic procedure get_parameter cst;
   (if x then cdr x else nil) where x := atsoc(cst,!*oc!-parse!-parameters!*);

symbolic procedure defined_variable var;
   var member !*oc!-parse!-dynamic!-variables!*;

symbolic procedure register_variable var;
   !*oc!-parse!-dynamic!-variables!* := var . !*oc!-parse!-dynamic!-variables!*;

symbolic procedure defined_control var;
   var member !*oc!-parse!-control!-variables!*;

symbolic procedure register_control var;
   !*oc!-parse!-control!-variables!* := var . !*oc!-parse!-control!-variables!*;


symbolic procedure defined_time_var;
   !*oc!-parse!-timevar!*;

symbolic procedure register_time_var var;
   !*oc!-parse!-timevar!* := var;


symbolic procedure read_file(name);
   begin scalar fh; integer ocparse!:curline;
     fh := rds open(name,'input);
     while not errorp errorset!*('(read_file1),!*backtrace) do nil;
     rds fh
   end;

symbolic procedure read_file1;
   begin scalar key,p;
     key := read_keyword();
     if !*trocparse then <<prin2 "Key read: "; prin2 key; terpri()>>;
     p := assoc(key,!*oc!-parse!-actions!*);
     if null p then <<
       lprim {"Unrecognized keyword", key};
       ocparse!:errcount := ocparse!:errcount + 1>>
      else apply(cdr p,nil);
   end;

symbolic procedure read_keyword;
   begin scalar l;
     repeat l := trim_whitespace read_line() until l;
     return intern compress l
   end;

symbolic procedure read_name;
   !*oc!-parse!-name!* := read_line();

symbolic procedure read_title;
   !*oc!-parse!-title!* := read_to_par nil;

symbolic procedure read_constants;
   begin scalar line,const;
     while (line := read_line()) and not empty_line_checker line and
           remove_whitespace line do <<
       line := extract_group(line,1);
       const :=  parse_constant line;
       if const then <<
         if defined_constant car const
           then lprim {"You try to redefine constant", car const, "(value:",
                       get_constant car const, ") as", cdr const, "!"}
          else register_constant(car const, cdr const)>>>>;
   end;

symbolic procedure parse_constant line;
   if not constant_matcher line then <<
     lprim {"Invalid constant specification; line is question was:", line};
     ocparse!:errcount := ocparse!:errcount + 1;
     nil>>
    else (compress extract_group(line,1) . compress extract_group(line,2));

     
symbolic procedure read_parameters;
   begin scalar line,param;
     while (line := read_line()) and not empty_line_checker line and
           remove_whitespace line do <<
       line := extract_group(line,1);
       param :=  parse_parameter line;
       if param then <<
         if defined_parameter car param
           then lprim {"You try to redefine parameter", car param, "(value:",
                       get_parameter car param, ") as", cdr param, "!"}
          else register_parameter(car param, cdr param)>>>>;
   end;

symbolic procedure parse_parameter line;
   if not constant_matcher line then <<
     lprim {"Invalid parameter specification; line is question was:", line};
     ocparse!:errcount := ocparse!:errcount + 1;
     nil>>
    else begin scalar g1,g2;
      g1 := compress extract_group(line,1);
      g2 := extract_group(line,2);
      return if null g2 then g1 . g2 else g1 . compress g2
     end;
     

symbolic procedure read_dvars;
   begin scalar line,var;
     while (line := get_line_contents()) do <<
       var := parse_variable line;
       if var then <<
         if defined_variable var
           then lprim {"You try to redefine dynamic variable", var, "!"}
          else register_variable var>>>>;
   end;

symbolic procedure read_cvars;
   begin scalar line,var;
     while (line := get_line_contents()) do <<
       var := parse_variable line;
       if var then <<
         if defined_control var
           then lprim {"You try to redefine control variable", var, "!"}
          else register_control var>>>>;
   end;

symbolic procedure parse_variable line;
   if not variable_matcher line then <<
     lprim {"Invalid variable specification; line in question was:", line};
     ocparse!:errcount := ocparse!:errcount + 1;
     nil>>
    else compress extract_group(line,1);


symbolic procedure read_time_var;
   begin scalar line,var;
     line := get_line_contents();
     var := parse_variable line;
     if var then <<
       if defined_time_var()
         then lprim {"You try to redefine time variable", var, "!"}
        else register_time_var var>>;
     while (line := get_line_contents()) do
       lprim "Garbage following definition of time variable!";
   end;


symbolic procedure read_abbrevs;
   !*oc!-parse!-abbrevs!* :=
     for each ab in split_at_char (read_to_par '! ,'!;) collect ltrim ab;


symbolic procedure read_dgls;
   begin scalar bl;
     bl := read_to_par '! ;
     bl := split_at_char(bl,'!;);
     for each dgl in bl do parse_dgl dgl;
   end;

putd('dgl_matcher1,'expr,
     compile_regex {"^(",ocparse!:idpattern,")\s*:?=?\s*(.+)$"});

putd('dgl_matcher2,'expr,
     compile_regex {"^[dD][oO][tT]\s*\(\s*(",ocparse!:idpattern,
                    ")\s*\)\s*:?=?\s*(.+)$"});

symbolic procedure parse_dgl dgl;
   <<                
   dgl := ltrim dgl;
   if dgl_matcher2 dgl
     then define_dgl(compress extract_group(dgl,1), extract_group(dgl,2))
    else if dgl_matcher1 dgl 
     then define_dgl(compress extract_group(dgl,1), extract_group(dgl,2))
   else <<
     lprim ("Invalid differential equation:" . dgl);
     ocparse!:errcount := ocparse!:errcount + 1;
     nil>>>>;

symbolic procedure define_dgl (var, clis);
   if assoc(var,!*oc!-parse!-dgls!*)
     then << lprim {"Differential equation for variable", var, "already defined!"};
     ocparse!:errcount := ocparse!:errcount + 1;
     nil>>
    else !*oc!-parse!-dgls!* := (var . clis) . !*oc!-parse!-dgls!*;

symbolic procedure read_funct;
   if !*oc!-parse!-functional!* then <<
     lprim {"I have already read the definition of your functional!"};
     ocparse!:errcount := ocparse!:errcount + 1;
     nil>>
    else !*oc!-parse!-functional!* := car split_at_char(read_to_par '! ,'!;);


symbolic procedure read_bounds;
   begin scalar b;
     b := split_at_char (ltrim read_to_par '! ,'!;);
     if length b = 3 and null caddr b then b := {car b, cadr b};
     if !*oc!-parse!-boundaries!* then <<
       lprim "I've already read a boundary definition -- ignoring this one.";
       ocparse!:errcount := ocparse!:errcount + 1>>
      else if length b neq 2 then <<
       lprim "Huh? How many boundaries do you have? -- ignoring this one.";
       ocparse!:errcount := ocparse!:errcount + 1>>
      else !*oc!-parse!-boundaries!* := car b . cadr b
   end;


symbolic procedure read_bconds;
   !*oc!-parse!-bconds!* := split_at_char (read_to_par '! ,'!;);


symbolic procedure skip_comment;
   read_to_par nil;


symbolic procedure read_restr;
   !*oc!-parse!-restrictions!* := split_at_char(read_to_par '! ,'!;);


symbolic procedure free_rhs;
   !*oc!-parse!-rhs!-is!-free!* := 1;

symbolic procedure read_timevar;
   !*oc!-parse!-timevar!* := parse_variable trim_whitespace read_line();

symbolic procedure read_targetlang;
   !*oc!-parse!-targetlang!* := parse_variable trim_whitespace read_line();


symbolic procedure do_output;
   <<output_preamble();
     if !*oc!-parse!-name!* then output_name();
     if !*oc!-parse!-title!* then output_title();
     output_abbrevs();
     output_consts();
     output_params();
     output_time_var();
     output_dvars();
     output_cvars();
     output_restrictions();
     output_bounds();
     output_bconds();
     output_funct();
     output_dgls();
     output_rhs_isfree();
     output_targetlang();
     output_oc_call();
     output_postamble()>>;

symbolic procedure output_preamble;
   nil;

symbolic procedure output_name;
   <<prin1 'set_name;
     prin2 "(";
     for each c in trim_whitespace !*oc!-parse!-name!* do prin2 c;
     prin2 ");";
     terpri(); terpri()>>;

symbolic procedure output_title;
   nil;

symbolic procedure output_abbrevs;
   for each l in !*oc!-parse!-abbrevs!* do <<
     prin1 'define_abbreviation;
     prin2 "(";
     for each c in l do princ c;
     prin2 ");";
     terpri(); terpri()>>;

symbolic procedure output_consts;
   for each pp in !*oc!-parse!-constants!* do <<
     writepri (mkquote {'define_constant, car pp, cdr pp},'first);
     writepri(''!;,'last)>>;

symbolic procedure output_params;
   for each pp in !*oc!-parse!-parameters!* do <<
     writepri (mkquote if null cdr pp then {'define_parameter, car pp}
                 else {'define_parameter, car pp, cdr pp},'first);
     writepri(''!;,'last)>>;


symbolic procedure output_time_var;
   <<writepri(mkquote {'define_time_variable,!*oc!-parse!-timevar!*},'first);
     writepri(''!;,'last)>>;

symbolic procedure output_dvars;
   <<writepri(mkquote {'define_dynamic_variables,
      'list . !*oc!-parse!-dynamic!-variables!*},'first);
     writepri(''!;,'last)>>;


symbolic procedure output_cvars;
   <<writepri(mkquote {'define_control_variables,
              'list . !*oc!-parse!-control!-variables!*},'first);
     writepri(''!;,'last)>>;

symbolic procedure output_restrictions;
   for each r in !*oc!-parse!-restrictions!* do <<
     prin1 'assume;
     prin2 "(";
     for each c in r do princ c;
     prin2 ");";
     terpri(); terpri()>>;


symbolic procedure output_bounds;
   <<prin1 'define_boundaries;
     prin2 "(";
     for each c in car !*oc!-parse!-boundaries!* do princ c;
     prin2 ",";
     for each c in cdr !*oc!-parse!-boundaries!* do princ c;
     prin2 ");";
     terpri(); terpri()>>;

symbolic procedure output_bconds;
   for each bc in !*oc!-parse!-bconds!* do <<
     prin1 'define_bc;
     prin2 "(";
     for each c in ltrim bc do princ c;
     prin2 ");";
     terpri(); terpri()>>;

symbolic procedure output_funct;
   <<prin1 'define_functional;
     prin2 "(";
     for each c in !*oc!-parse!-functional!* do princ c;
     prin2 ");";
     terpri(); terpri()>>;

symbolic procedure output_dgls;
   for each pp in !*oc!-parse!-dgls!* do <<
     prin2 "define_differential_equation(";
     prin1 car pp;
     princ ",";
     for each c in cdr pp do princ c;
     prin2 ");";
     terpri(); terpri()>>;

symbolic procedure output_rhs_isfree;
   <<writepri(mkquote {'set_right_bd_free, !*oc!-parse!-rhs!-is!-free!*},'first);
     writepri(''!;,'last)>>;

symbolic procedure output_targetlang;
   <<writepri(mkquote {'set_target_language, !*oc!-parse!-targetlang!*},'first);
     writepri(''!;,'last)>>;

symbolic procedure output_oc_call;
   nil;

symbolic procedure output_postamble;
   <<prin2 ";end;"; terpri()>>;


symbolic procedure process_file(ifile,ofile);
   <<reset_oc_parser();
     read_file ifile;
     if ocparse!:errcount > 0 then
       lprim {"There were", ocparse!:errcount, "errors. No output."}
      else <<out ofile;
             do_output();
             shut ofile>>>>;

endmodule;

end;


