%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:PRINTF.SL                                              
% Description:  Formatted print routine                                    
% Author:       Eric Benson                                                
% Created:      27 August 1981                                             
% Modified:     29-Oct-84 09:10:42 (Vicki O'Day)
% Mode:         Lisp                                                       
% Package:                                                                 
% Status:       Experimental (Do Not Distribute)                           
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.        
% (c) Copyright 1981, University of Utah                                   
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:                                                               
%
% 02-Mar-84 09:20:52 (Jim Ambras/CRC)                                      
%  Corrected file header.                                                  
% 24-Feb-84 15:42:09 (Nancy Kendzierski)                                   
%  Added "format" arguments to errorprintf and bldmsg, since they were     
%  supposed to be able to handle as manya arguments as PSL could pass ...  
% 06-Jan-84 17:10:01 (Tim Tillson)                                         
%  Un-rlisp'ed Sam's D-register model version                              
% 4-Nov-83 Sam Sands                                                       
%  Removed 15th parameter for D register model                             
% 17-Sep-82 16:01:01, BENSON                                               
%  Added ChannelPrintF                                                     
% 3-May-82 10:45:11, BENSON                                                
%  %L prints nothing for NIL                                               
% 23-Feb-82 21:40:31, BENSON                                               
%  Added %x for hex                                                        
% 1-Dec-81 16:11:11, BENSON                                                
%  Changed to cause error for unknown character                            
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (copyd '*jumpon '*xjumpon))
(compiletime (load io-decls token-decls))

(compiletime
  (flag '(printf1 printf2) 'iinternalfunction))

(fluid '(formatforprintf* in* out*))

% First, lambda-bind FormatForPrintF!*                                     
% That's a no-no in the multiple environment model, since lambda
% binding causes heap grabbage, hence the dynamic extent trick with
% the so-called fluid
(de printf (formatforprintf a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13)
  % scs
  (let ((saveformatforprintf* formatforprintf*))
    (setq formatforprintf* formatforprintf)
    (unwind-protect
      (printf1 formatforprintf* a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13))
      (setq formatforprintf* saveformatforprintf*)))

% scs                                                                      
% Then, push all the registers on the stack and set up a pointer to them   

(lap '((*entry printf1 expr 15)
       (*alloc 60)
        (*move (reg 2) (indexed (reg st) 128))
        (*move (reg 3) (indexed (reg st) 124))
        (*move (reg 4) (indexed (reg st) 120)) 
        (*move (reg 5) (indexed (reg st) 116))
        (*move (reg 6) (indexed (reg st) 112))
        (*move (reg 7) (indexed (reg st) 108))
        (*move (reg 8) (indexed (reg st) 104))
        (*move (reg 9) (indexed (reg st) 100))
        (*move (reg 10) (indexed (reg st) 96))
        (*move (reg 11) (indexed (reg st) 92))
        (*move (reg 12) (indexed (reg st) 88))
        (*move (reg 13) (indexed (reg st) 84))
        (*move (reg 14) (indexed (reg st) 80))
        (*move (reg 15) (indexed (reg st) 76))
       (*wplus3 (reg 1) (reg st) 128)
       %  scs
       (*call printf2)
       (*exit 60)))

%  scs                                                                     
% Finally, actual printf, with 1 argument, pointer to array of parameters  
(compiletime (put 'memo 'opencode '((lwz (reg 1) (displacement (reg 1) 0)))))

(de printf2 (printfargs)
  %. Formatted print                                                       
  %                                                                        
  % Format is a string, either in the heap or not, whose characters will be
  % written on the currently selected output channel.  The exception to this is
                                                                           
  % that when a % is encountered, the following character is interpreted as a
                                                                           
  % format character, to decide how to print one of the other arguments.  The
                                                                           
  % following format characters are currently supported:                   
  %	%b - blanks; take the next argument as integer and print that many 
  %		blanks                                                     
  %	%c - print the next argument as a single character                 
  %	%d - print the next argument as a decimal integer                  
  %     %e - EVALs the next argument for side-effect -- most useful if the
  %            thing EVALed does some printing                             
  %	%f - fresh-line, print end-of-line char if not at beginning of line
  %	%l - same as %w, except lists are printed without top level parens 
  %	%n - print end-of-line character                                   
  %	%o - print the next argument as an octal integer                   
  %	%p - print the next argument as a Lisp item, using Prin1           
  %     %r - print the next argument as a Lisp item, using ErrPrin (`FOO')
  %	%s - print the next argument as a string                           
  %	%t - tab; take the next argument as an integer and                 
  %		print spaces to that column                                
  %	%w - print the next argument as a Lisp item, using Prin2           
  %	%x - print the next argument as a hexidecimal integer              
  %	%% - print a %                                                     
  %                                                                        
  % If the character is not one of these (either upper or lower case), then an
                                                                           
  % error occurs.                                                          
  %                                                                        
  (prog (uplim i ch upch)
        (setq uplim (strlen (strinf formatforprintf*)))
        (setq i 0)
        (while (wleq i uplim)
          (setq ch (strbyt (strinf formatforprintf*) i))
          (if (wneq ch (char !%))
            (writechar ch)
            (prog nil
                  (setq i (wplus2 i 1))
                  (setq ch (strbyt (strinf formatforprintf*) i))
                  (setq upch (if (lowercasechar ch)
                          (raisechar ch)
                          ch))

                  (case upch 
                        (((char !B)) 
                         (progn (spaces (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !C)) 
                         (progn (writechar (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !D)) 
                         (progn (writesysinteger (memo printfargs) 10)
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !E)) 
                         (progn (eval (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !F)) (when (wgreaterp (posn) 0)
                           (writechar (char eol))))
                        (((char !L)) 
                         (progn (prin2l (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !N)) (writechar (char eol))) 
                        (((char !O)) 
                         (progn (writesysinteger (memo printfargs) 8)
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !X)) 
                         (progn (writesysinteger (memo printfargs) 16)
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !P)) 
                         (progn (prin1 (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !R)) 
                         (progn (errprin (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !S)) 
                         (progn (writestring (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !T)) 
                         (progn (tab (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !W)) 
                         (progn (prin2 (memo printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !%)) (writechar (char !%)))
                        (nil 
                         (stderror 
                          (bldmsg "Unknown character code for PrintF: %r" 
                           (mkid ch)))))))
          (setq i (wplus2 i 1)))))

(de errorprintf (format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13)
  (prog (savechannel)
        (setq savechannel (wrs errout*))
        (when (wgreaterp (wgetv lineposition (intinf errout*)) 0)
          (terpri))
        (printf format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13)
        (when (wgreaterp (wgetv lineposition (intinf errout*)) 0)
          (terpri))
        (wrs savechannel)))

(de tostringwritechar (channel ch)
  % shares TokenBuffer                                                     
  (progn (if (wgeq (wgetv tokenbuffer 0) (wdifference maxtokensize 1))
           (progn (setf (wgetv tokenbuffer 0) 80)
                  % truncate to 80 chars                                   
                  (setf (strbyt tokenbuffer 80) (char null))
                  (stderror 
                   (list '"Buffer overflow while constructing error message:"
                         formatforprintf* '"The truncated result was:" 
                         (copystring (mkstr tokenbuffer)))))
           (progn (setf (wgetv tokenbuffer 0) 
                        (wplus2 (wgetv tokenbuffer 0) 1))
                  (setf (strbyt tokenbuffer (wgetv tokenbuffer 0)) ch)))))

%. Print to string                                                         
(de bldmsg 
  (format arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9 arg10 arg11 arg12 arg13) 
  (prog (tempchannel out*)
        (setf (wgetv lineposition 2) 0)
        (setf (wgetv tokenbuffer 0) -1)
        (setq tempchannel out*)
        (setf out* '2)
        (printf format arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9 arg10 
                arg11 arg12) % jpa arg13
        (setf (strbyt tokenbuffer (wplus2 (wgetv tokenbuffer 0) 1)) 
              (char null))
        (setf out* tempchannel)
        (return (copystring tokenbuffer))))

(de errprin (u)
  %. `Prin1 with quotes'                                                   
  (progn (writechar (char !`))
         (prin1 u)
         (writechar (char !'))))

(de prin2l (itm)
  %. Prin2 without top-level parens                                        
  (cond ((null itm) nil)
        % NIL is (), print nothing                                         
        ((not (pairp itm)) (prin2 itm))
        (t (progn (while (progn (prin2 (car itm))
                                (setq itm (cdr itm))
                                (pairp itm))
                    (channelwriteblankoreol out*))
                  (when itm
                    (channelwriteblankoreol out*)
                    (prin2 itm))))))

(de channelprintf (outc format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12)
  (let ((saveout* out*))
    (setq out* outc)
    (unwind-protect
      (printf format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12)
      (setq out* saveout*))))

