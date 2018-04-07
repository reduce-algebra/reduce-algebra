%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: FIND.SL 
% Description:  Start of recognition and search OBLIST functions 
% Author:       M. L. Griss 
% Created:      
% Modified:     05-Dec-83 17:32:05 (Nancy Kendzierski) 
% Package:      Utilities
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 05-Dec-83 17:32:05 (Nancy Kendzierski)
%   Added contents of .BUILD file.
% 02-Dec-83 18:02:16 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 30 Dec 1982, MLG                                                         
%   Move IMPORTS etc to BUILD file                                     
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(imports '(gsort))

(fluid '(collectid!* teststring!*))

(de findprefix (teststring!*)
  %. Scan ObLIST for prefix                                                
  (prog nil
        (setq collectid!* nil)
        (when (idp teststring!*)
          (setq teststring!* (id2string teststring!*)))
        (unless (stringp teststring!*)
          (stderror "Expect String or ID in FindPrefix"))
        (mapobl (function findprefix1))
        (return (idsort collectid!*))))

(de findprefix1 (x)
  (when (isprefixstring teststring!* (id2string x))
    (setq collectid!* (cons x collectid!*))))

(de findsuffix (teststring!*)
  %. Scan ObLIST for prefix                                                
  (prog nil
        (setq collectid!* nil)
        (when (idp teststring!*)
          (setq teststring!* (id2string teststring!*)))
        (unless (stringp teststring!*)
          (stderror "Expect String or ID in FindPrefix"))
        (mapobl (function findsuffix1))
        (return (idsort collectid!*))))

(de findsuffix1 (x)
  (when (issuffixstring teststring!* (id2string x))
    (setq collectid!* (cons x collectid!*))))

(de isprefixstring (s1 s2)
  %. test if exact string prefix                                           
  (prog (l1 l2 l)
        (setq l1 (size s1))
        (setq l2 (size s2))
        (setq l 0)
        (when (greaterp l1 l2)
          (return nil))
   loop
        (unless (eq (indx s1 l) (indx s2 l))
          (return nil))
        (when (greaterp (setq l (add1 l)) l1)
          (return t))
        (go loop)))

(de issuffixstring (s1 s2)
  %. test if exact string prefix                                           
  (prog (l1 l2 l)
        (setq l1 (size s1))
        (setq l2 (size s2))
        (when (greaterp l1 l2)
          (return nil))
   loop
        (unless (eq (indx s1 l1) (indx s2 l2))
          (return nil))
        (when (leq l1 0)
          (return t))
        (setq l1 (difference l1 1))
        (setq l2 (difference l2 1))
        (go loop)))

% More extensive String matcher                                            
(de stringmatch (p s)
  (stringmatch1 p 0 (size p) s 0 (size s)))

(de stringmatch1 (p p1 p2 s s1 s2)
  (prog (c)
   l1
        % test Range                                                       
        (cond ((greaterp p1 p2) (return (if (greaterp s1 s2)
                                   t
                                   nil)))
              ((greaterp s1 s2) (return nil)))
        % test if % something                                              
        (when (eq (setq c (indx p p1)) (char !%))
          (go l3))
   l2
        % exact match                                                      
        (when (eq c (indx s s1))
          (setq p1 (plus p1 1))
          (setq s1 (plus s1 1))
          (go l1))
        (return nil)
   l3
        % special cases                                                    
        (setq p1 (plus p1 1))
        (when (greaterp p1 p2)
          (return (stderror "pattern ran out in % case of StringMatch")))
        (setq c (indx p p1))
        (when (eq c (char !%))
          (go l2))
        (when (eq c (char !?))
          (setq p1 (plus p1 1))
          (setq s1 (plus s1 1))
          (go l1))
        (cond ((eq c (char !*)) % 0 or more vs 1 or more                    
               (return (progn (while (and 
                                      (not 
                                       (setq c 
                                        (stringmatch1 p (plus p1 1) p2 s 
                                         s1 s2)))
                                      (leq s1 s2))
                                (setq s1 (plus s1 1)))
                              c))))
        (return (stderror 
                 (bldmsg " %% %r not known in StringMatch" (int2id c))))))

(de find (teststring!*)
  %. Scan ObLIST for prefix                                                
  (prog nil
        (setq collectid!* nil)
        (when (idp teststring!*)
          (setq teststring!* (id2string teststring!*)))
        (unless (stringp teststring!*)
          (stderror "Expect String or ID in FindPrefix"))
        (mapobl (function findstringmatch))
        (return (idsort collectid!*))))

(de findstringmatch (x)
  (when (stringmatch teststring!* (id2string x))
    (setq collectid!* (cons x collectid!*))))

