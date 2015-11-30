module records; % A record package for RLISP using MSTRUCT.

% Author:  Bruce Florman.

% Copyright:  (c) 1989 The RAND Corporation.  All rights reserved.

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
%


% Revision History:
%  01/26/89 BAF -- Added this file header.
%       Sat Apr 24 12:38:32 1993 - Remove non-RLISP'88 functions (first,
%           etc.).

% BothTimes Load MSTRUCT;

%-----------------------------------------------------------------------
%      RECORD Declaration
%-----------------------------------------------------------------------

expr procedure recordstat();
% RECORD <struct-name>
%  { /* <annotation> */ }
%  { WITH <field> := <expression> { , <field> := <expression> }... }
%  { HAS <option> { , <option> }... } ;
   begin scalar f, stat;
      f := flagp('has,'delim);
      flag('(has),'delim);
      stat := errorset('(recordstat1),nil,nil);
      if not f then remflag('(has),'delim);
      if errorp stat then while cursym!* neq '!*semicol!* do scan()
       else return car stat
   end;

expr procedure recordstat1();
   begin scalar structname, annotation, fields, options;
      structname := scan();
      if not idp structname then symerr('record, t);
      if eqcar(scan(), '!*comment!*) then
         <<annotation := cadr cursym!*; scan()>>;
       if cursym!* eq 'with then fields := remcomma xread nil;
       if cursym!* eq 'has then options := remcomma xread nil;
       if cursym!* eq '!*semicol!* then
         return {'record, structname, annotation, fields, options}
       else symerr('record, t)
   end;

put('record,'stat,'recordstat);

expr procedure formrecord(u, vars, mode);
apply(form_function, cdr u)
where form_function =
  function(lambda(record_name, annotation, fields, options);
     begin scalar structspec, fieldspecs, constructor, form;
       structspec := form_structure_specification(record_name, options);
       fieldspecs := form_field_specifications(fields);
       constructor := cdr atsoc('constructor,
                                get_defstruct_options structspec);
       form := {nil};
       tconc(form, 'progn);
      if constructor then
         << tconc(form,
                  {'put, mkquote constructor,
                         '(quote formfn),
                         '(quote form_record_constructor)});
             put(constructor, 'formfn, 'form_record_constructor) >>;
      if annotation then
         tconc(form, {'put, mkquote record_name,
                            '(quote annotation),
                            annotation});
      tconc(form, 'defstruct . structspec . fieldspecs);
      return car form
      end);

put('record, 'formfn, 'formrecord);

expr procedure tconc(ptr,elem);
   % ACONC with pointer to end of list.  Ptr is (list . last CDR of
   % list).  Returns updated Ptr.  Ptr should be initialized to
   % (NIL . NIL) before calling the first time.
   <<elem := list elem;
     if not pairp ptr then elem . elem
      else if null cdr ptr then rplaca(rplacd(ptr,elem),elem)
      else <<rplacd(cdr ptr,elem); rplacd(ptr,elem)>>>>;

expr procedure form_structure_specification(record_name, options);
append(defaults,
       for each entry in options
            collect if atom entry then entry
                    else if eqcar(entry, 'no) and length entry=2 then
                         {cadr entry, nil}
                    else if car entry eq 'equal and length entry=3 then
                         {cadr entry, caddr entry}
                    else error(0, {"Bad RECORD option:", entry}))
     where defaults = {record_name,{'constructor, record_name},
                       'predicate};

expr procedure form_field_specifications field_list;
for each entry in field_list
    join
       if eqcar(entry, 'setq)
         then {{cadr(entry), form1(caddr entry, nil, 'symbolic)}}
        else nil;

expr procedure form_record_constructor(u, vars, mode);
begin scalar constructor, arglist;
  constructor := car u;
  arglist := {nil};
  for each arg in cdr u
    do if eqcar(arg, 'setq) then
           << tconc(arglist, cadr arg);
              tconc(arglist, form1(caddr arg, vars, mode)) >>
       else rederr {arg, "is not a proper initialization form for",
                    constructor};
  return constructor . car arglist;
end;

endmodule;

end;

