

module templt;    %%  GENTRAN Template Processing Routines  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Points:  ProcCTem, ProcFortTem, ProcRatTem
% Moved to separate language modules - JHD December 1987

symbolic$

% User-Accessible Global Variables %
global '(gentranlang!* !$!#)$
fluid '(!*gendecs)$
share gentranlang!*, !$!#$
gentranlang!* := 'fortran$
!$!# := 0$
switch gendecs$

global '(!*space!* !*stdout!* !$eof!$ !$eol!$)$
        % GENTRAN Global Variables      %

!*space!* := '! $

fluid '(!*mode)$


%%                          %%
%% Text Processing Routines %%
%%                          %%

%%                                   %%
%% Template File Active Part Handler %%
%%                                   %%

symbolic procedure procactive;
% active parts:  ;BEGIN; ... ;END; %
% eof markers:   ;END;             %
begin scalar c, buf, mode, och, !*int,!*errcont;
% By turning INT off we avoid some excess blank lines, and avoid trouble
% with END being caught by BEGIN1.  We use !*errcont to recover
% gracefully when an error is caught in the template.
!*errcont := 't;
c := readch();
if c eq 'e then
    if (c := readch()) eq 'n then
        if (c := readch()) eq 'd then
            if (c := readch()) eq '!; then
                return !$eof!$
            else buf := '!;end
        else buf := '!;en
    else buf := '!;e
else if c eq 'b then
    if (c := readch()) eq 'e then
        if (c := readch()) eq 'g then
            if (c := readch()) eq 'i then
                if (c := readch()) eq 'n then
                    if (c := readch()) eq '!; then
                    <<
                        mode := !*mode;
                        !*mode := 'algebraic;
                        och := wrs cdr !*stdout!*;
                        begin1();
                        wrs och;
                        !*mode := mode;
                        linelength 150;
                        return if (c := readch()) eq !$eol!$ 
                                  then readch()
                                  else c
                    >>
                    else buf := '!;begin
                else buf := '!;begi
            else buf := '!;beg
        else buf := '!;be
    else buf := '!;b
else buf := '!;;
pprin2 buf;
return c
end$

endmodule;

end;
