%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:PRINTF.SL                                              
% Description:  Formatted print routine                                    
% Author:       Eric Benson                                                
% Created:      27 August 1981                                             
% Modified:     29-Oct-84 09:10:42 (Vicki O'Day)
% Package:                                                                 
% Status:       Open Source: BSD License
%
% (c) Copyright 1982, University of Utah
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:                                                               
%
% 28-May-87 (Leigh Stoller & Harold Carr)
%  Added fluid declarations of in* and out*.
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

(compiletime (load io-decls token-decls))

(compiletime
  (flag '(printf1 printf2) 'iinternalfunction))

(fluid '(in* out*))
(fluid '(formatforprintf*))

% First, lambda-bind FormatForPrintF!*                                     
(de printf (formatforprintf* a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13)
  % scs                                                                    

  (printf1 formatforprintf* a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13))

% scs                                                                      
% Then, push all the registers on the stack and set up a pointer to them   
(lap '((*entry printf1 expr 15)
       (*push (reg 2))
       (*push (reg 3))
       (*push (reg 4))
       (*push (reg 5))
       (*push (reg 6))
       (*push (reg 7))
       (*push (reg 8))
       (*push (reg 9))
       (*push (reg 10))
       (*push (reg 11))
       (*push (reg 12))
       (*push (reg 13))
       (*push (reg 14))
       %   (!*PUSH (reg 15))                     scs                       
       (*loc (reg 1) (frame 13))
       %  scs                                                              
       (*call printf2)
       (*exit 13)))

%  scs                                                                     
% Finally, actual printf, with 1 argument, pointer to array of parameters  
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
                         (progn (spaces (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !C)) 
                         (progn (writechar (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !D)) 
                         (progn (writesysinteger (getmem printfargs) 10)
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !E)) 
                         (progn (eval (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !F)) (when (wgreaterp (posn) 0)
                           (writechar (char eol))))
                        (((char !L)) 
                         (progn (prin2l (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !N)) (writechar (char eol))) 
                        (((char !O)) 
                         (progn (writesysinteger (getmem printfargs) 8)
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !X)) 
                         (progn (writesysinteger (getmem printfargs) 16)
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !P)) 
                         (progn (prin1 (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !R)) 
                         (progn (errprin (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !S)) 
                         (progn (writestring (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !T)) 
                         (progn (tab (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !W)) 
                         (progn (prin2 (getmem printfargs))
                                (setq printfargs 
                                 (loc (wgetv printfargs stackdirection)))))
                        (((char !%)) (writechar (char !%))) 
                        (nil 
                         (stderror 
                          (bldmsg '"Unknown character code for PrintF: %r" 
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
                  (setf (strbyt tokenbuffer (wgetv tokenbuffer 0)) ch)))
))

%. Print to string                                                         
(de bldmsg 
  (format arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9 arg10 arg11 arg12)
             % arg13)  jpa
  (prog (tempchannel out*)
        (setf (wgetv lineposition 2) 0)
        (setf (wgetv tokenbuffer 0) -1)
        (setq tempchannel out*)
        (setf out* '2)
        (printf format arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9 arg10 
                arg11 arg12) % jpa arg13)
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

(de channelprintf (out* format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12)
  %   scs                                                                  
  (printf format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12))

