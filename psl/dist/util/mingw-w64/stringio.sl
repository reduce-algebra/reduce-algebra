%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:OPEN-CLOSE.SL 
% Title:        File primitives 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     31-May-84 10:46:09 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:IO-DECLS.B 
% Runtime:      
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(de stringopen(string len)

  (prog (filedes)
   (setq filedes (systemopenstring string))
   (setf (wgetv lineposition filedes) 0)
   (setf (wgetv maxline filedes) len)
   (setf (wgetv unreadbuffer filedes) (char null))
   (setf (wgetv readfunction filedes)  'independentreadchar_from_string)
   (setf (wgetv writefunction filedes) 'independentwritechar_to_string)
   (setf (wgetv closefunction filedes) 'independentclosestring)
   (setf (wgetv nextposition  filedes) 0)   % Will be post Incremented
   (setf (wgetv bufferlength  filedes) len)
   (setf (wgetv maxbuffer filedes) len)
   (setf (igetv iobuffer  filedes) (mkstr string))

  (return  filedes)))


(de systemopenstring (string)
 
  %  Mark a a pair of channels as open for a special purpose.
 
  (let ((channel (findfreechannel)))
    (setf (wgetv channelstatus channel) 'channelopenspecial)
    (setf (wgetv channeltable  channel) string)
    channel
    ))
 
(de independentclosestring (channel)

  (testlegalchannel channel)
  (setf (wgetv channeltable channel) 'channelclosed)
  )

(de independentwritechar_to_string (channel chr)

  % Write a character into the buffer.  Actually dump the buffer when the
  % EOL character is found, or when the buffer is full.  This happens
  % immediately upon meeting this condition, not waiting for the
  % next character.  Note, that this places the EOL character into the
  % buffer for machine dependent treatment as CR/LF etc

  (testlegalchannel channel)
  (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
  (setf (strbyt (strinf (igetv iobuffer channel))
                (wgetv nextposition channel))
    chr)
)
(de independentreadchar_from_string (channel)

  % This function will read in a character from the buffer.  It will read
  % the record on buffer length overflow only.  Thus when an EOL character
  % is read, it is processed as any other character, except, if it is the last
  % one, in the record, it will do the read automatically.
  % Note, this will not read the next record until after the final character
  % has been processed.

  (testlegalchannel channel)

  % Pull the next character out of the buffer.

  (let ((chr (strbyt (strinf (igetv iobuffer channel))
                     (wgetv nextposition channel))))
    (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
    (when *echo (writechar chr))
    chr
    ))

(off fast-integers)

lisp; on comp; load "$pl/stringio";

symbolic procedure terpri(); channelprin2(out!*, !$eol!$);
symbolic procedure terpri!*(ttt); nil;
off nat;
symbolic procedure reduceup(x,y,xx,yy);
 << x := mkstr x;
    y := mkstr y;
    rds stringopen (x ,xx);
    wrs stringopen (y ,yy);
    begin1();
    rds nil;
    wrs nil;
 >>;
os_cleanup_hook 17;


