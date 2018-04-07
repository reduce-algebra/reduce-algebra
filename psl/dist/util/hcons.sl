%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:HCONS.SL 
% Description:  Hashing (unique) CONS and associated utilities. 
% Author:       William Galway
% Created:      Wednesday, 2 June 1982 
% Modified:     19 Jan 1984 1441-PST (Brian Beach) 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 28-May-87 (Leigh Stoller & Harold Carr)
%  Added fluid declarations of hash-cons-tables and current-table-number.
% 19 Jan 1984 1441-PST (Brian Beach)
%   Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
(BothTimes       % ?? Compile time may suffice.
  (load useful)
  (load fast-vector))

(fluid '(hash-cons-tables current-table-number))

% Summary of "user level" functions provided:
% (DM Hcons (X) ...)  % Nary hashed cons, right associative.
% (DN Hlist (X) ...)  % Hcons version of "list" function.

% Hcons version of "copy" function.  Note that unlike copy, this is not
% guaranteed to create a new copy of a structure. (In fact, rather the
% opposite.)
% (DE Hcopy (lst) ...)

% (DE Happend (U V) ...) % Hcons version of "append" function.
% (DE Hreverse (U) ...)  % Hcons version of "reverse" function.

% Pairs for property list functions must be created by Hcons.
% Get property of id or pair.
% (DE extended-get (id-or-pair  indicator) ...)
% Put property of id or pair.  Known to setf.
% (DE extended-put (id-or-pair indicator val) ...)


% Number of hash "slots" in table, should be a prime number to get an even
% spread of hits (??).  This package has been written so that it should be
% possible to modify this size at runtime (I hope).  So if the hash-tables
% get too heavily loaded they can be copied to larger ones.
(DefConst hcons-table-size 103)

% Build the two tables (we switch from one to the other on each garbage
% collection.  Note that (MkVect 1) gives TWO locations.
(setf hash-cons-tables (MkVect 1))

(setf (IGetV hash-cons-tables 0)
  (MkVect (sub1 (const hcons-table-size))))

(setf (IGetV hash-cons-tables 1)
  (MkVect (sub1 (const hcons-table-size))))

% current-table-number switches between 0 and one at each garbage
% collection--selecting the current table to use.
(setf current-table-number 0)

(DE next-table-number (table-number)
  (cond
    ((equal table-number 0) 1)
    (T 0)))

% Should really use structs for this, but I'm unsure on the exact details
% of how structs work, and it's very important to understand how much free
% space will be demanded by any routines that are called.
% Anyway, each location in a "hash table" is either NIL, or an "entry",
% where an entry is implemented as a vector of
% [ <dotted-pair>  <property-list-for-pair>  <next-entry-in-chain> ]

% This should be done differently too.
(DefConst entry-size 4)  % The size of an entry in "heap units"??
(DefConst pair-size 2)   % Similarly for pairs.

(DS create-hash-entry ()
  % Create a 3 element vector.
  (MkVect 2))

(DS pair-info (ent)
  (IGetV ent 0))

(DS prop-list-info (ent)
  (IGetV ent 1))

(DS next-entry (ent)
  (IGetV ent 2))

% Finds a location within a "hash table", for a pair (X,Y).
% This version is very simpleminded!
(DS hcons-hash-function (htable X Y)
  (remainder
    % Take absolute value to avoid sign problems with remainder.
    (abs (plus (Sys2Int X) (Sys2Int Y)))
    (add1 (ISizeV htable))))

% Copy entries from one "hash cons table" to another, setting the source
% table to all NILs.  Return the dst-table, as well as copying into it.
% This routine is used to place entries in their new locations after a
% garbage collection.  This routine MUST NOT allocate anything on the heap.
(DE move-hcons-table (src-table  dst-table)
  (prog (dst-index src-entry src-pair nxt-entry)
    (for (from src-index 0 (ISizeV src-table) 1)
      (do
        (progn
          (setf src-entry (IGetV src-table src-index))
          % Use GetV here, until "the bug" in IGetV gets fixed.
          (setf (GetV src-table src-index) NIL)
          (while src-entry
            (progn
                (setf src-pair (pair-info src-entry))
                (setf dst-index
                  (hcons-hash-function
                    dst-table
                    (car src-pair) (cdr src-pair)))
                % Save the next entry in the the chain, and then relink the
                % current entry into its new location.
                (setf nxt-entry (next-entry src-entry))
                (setf (next-entry src-entry)
                  (IGetV dst-table dst-index))
                (setf (IGetV dst-table dst-index) src-entry)
                % Move to next thing in chain.
                (setf src-entry nxt-entry))))))

    (return dst-table)))

% Nary version of hashed cons.
(DM Hcons (X)
  (RobustExpand (cdr X)  'hcons2  NIL))

% Binary "hashed" cons of X and Y, returns pointer to previously
% constructed pair if it can be found in the hash table.
(DE Hcons2 (X Y)
  (prog (hashloc hitchain tmpchain newpair newentry)
    (setf hashloc (hcons-hash-function
                    (IGetV hash-cons-tables current-table-number)
                    X Y))

    % Get chain of entries at the appropriate hash location in the
    % appropriate table.
    (setf hitchain (IGetV
                     (IGetV hash-cons-tables current-table-number)
                     hashloc))

    % Search for a previously constructed pair, if any, with car and cdr
    % equal to X and Y respectively.
    % Note that tmpchain is not a list, but a "chain" of "entries".
    (setf tmpchain hitchain)
    (while (and tmpchain
             % Keep searching unless an exact match is found.
             (not (and
                    % EqN test might be better, so that we handle numbers
                    % intelligently?  Probably have to worry about hash
                    % code also.
                    (eq X (car (setf newpair (pair-info tmpchain))))
                    (eq Y (cdr newpair)))))
      % do
      (setf tmpchain (next-entry tmpchain)))

    (cond
      % If no entry was found, create a new one.
      ((null tmpchain)
        (progn
          % We need enough room for one new pair, plus one new entry.  If
          % there isn't enough room on the heap then collect garbage (and
          % in the process move EVERYTHING around, switch hash tables,
          % etc.)
          (cond
            ((LessP
               (GtHeap NIL)      % Returns free space in heap.
               (plus (const pair-size) (const entry-size)))
              (progn
                (reclaim)
                % Recalculate locations of everything.
                (setf hashloc
                  (hcons-hash-function
                    (IGetV hash-cons-tables current-table-number)
                    X Y))

                % Get chain of entries at the appropriate hash location in
                % the appropriate table.
                (setf hitchain
                  (IGetV
                    (IGetV hash-cons-tables current-table-number)
                    hashloc)))))

          % Allocate the new pair, store information into the appropriate
          % spot in appropriate table.
          (setf newpair (cons X Y))
          (setf newentry (create-hash-entry))

          (setf (pair-info newentry) newpair)
          (setf (prop-list-info newentry) NIL)
          (setf (next-entry newentry) hitchain)
          % Link the new entry into the front of the table.
          (setf
            (IGetV
              (IGetV hash-cons-tables current-table-number)
              hashloc)
            newentry))))

    % Return the pair (either newly constructed, or old).
    (return newpair)))

% "hcons" version of "list" function.
(DN Hlist (X)
  (do-hlist X))

(DE do-hlist (X)
  (cond
    ((null X) NIL)
    (T (hcons (car X) (do-hlist (cdr X))))))

% "hcons" version of copy.  Note that unlike copy, this is not guaranteed
% to create a new copy of a structure. (In fact, rather the opposite.)
(DE Hcopy (lst)
  (cond
    ((not (pairp lst)) lst)
    (T (hcons (hcopy (car lst))  (hcopy (cdr lst))))))

% "hcons" version of Append function.
(DE Happend (U V)
  (cond
    % First arg is NIL, or some other non-pair.
    ((not (PairP U)) V)
    % else ...
    (T (hcons (car U) (Happend (cdr U) V)))))

% Hcons version of Reverse.
(DE Hreverse (U)
  (prog (V)
    (while (PairP U)
      (progn
        (setf V (hcons (car U) V))
        (setf U (cdr U))))
    (return V)))

% Look up and return the entry for a pair, if any.  Return NIL if argument
% is not a pair.
(DE entry-for-pair (p)
  (cond
    ((PairP p)
      (prog (hashloc ent)
        (setf hashloc
          (hcons-hash-function
            (IGetV hash-cons-tables current-table-number)
            (car p) (cdr p)))

        % Look at appropriate spot in hash table.
        (setf ent
          (IGetV (IGetV hash-cons-tables current-table-number) hashloc))
                    
        % Search through chain for p.
        (while (and ent
                 (not (eq (pair-info ent) p)))
          (setf ent (next-entry ent)))

        % Return the entry, or NIL if none found.
        (return ent)))))

% Get a property for a pair or identifier.  Only pairs stored in the hash
% table have properties.
(DE extended-get (id-or-pair  indicator)
  (cond
    ((IdP id-or-pair) (get id-or-pair indicator))

    ((PairP id-or-pair)
      (prog (proplist prop-pair)
        (setf proplist (pair-property-list id-or-pair))
        (setf prop-pair (atsoc indicator proplist))
        (return
          (cond
            ((PairP prop-pair) (cdr prop-pair))))))))

% Put function for pairs and identifiers.  Only pairs in the hash table can
% be  given properties.  (We are very sloppy about case when pair isn't in
% table, but hopefully the code won't blow up.)  "val" is returned in all
% cases.
(DE extended-put (id-or-pair indicator val)
  (cond
    ((IdP id-or-pair) (put id-or-pair indicator val))

    ((PairP id-or-pair)
      (prog (proplist prop-pair)
        (setf proplist (pair-property-list id-or-pair))
        % Get the information (if any) stored under the indicator.
        (setf prop-pair (Atsoc indicator proplist))
        (cond
          % Modify the information under the indicator, if any.
          ((PairP prop-pair)
            (setf (cdr prop-pair) val))

          % Otherwise (nothing found under indicator), create new
          % (indicator . value) pair.
          (T
            (progn
              % Note use of cons, not Hcons, WHICH IS RIGHT? (I think cons.)
              (setf prop-pair (cons indicator val))
              % Tack new (indicator . value) pair onto property list, and
              % store in entry for the pair who's property list is being
              % hacked.
              (set-pair-property-list
                id-or-pair (cons prop-pair proplist)))))

        % We return the value even if the pair isn't in the hash table.
        (return val)))))

(PUT 'extended-get 'assign-op 'extended-put)
(FLAG '(extended-get) 'SETF-SAFE)

% Return the "property list" associated with a pair.
(DE pair-property-list (p)
  (prog (ent)
    (setf ent (entry-for-pair p))
    (return
      (cond
        (ent (prop-list-info ent))
        (T NIL)))))

% Set the "property list" cell for a pair, return the new "property list".
(DE set-pair-property-list (p val)
  (prog (ent)
    (setf ent (entry-for-pair p))
    (return
      (cond
        (ent (setf (prop-list-info ent) val))
        (T NIL)))))

% We redefine the garbage collector so that it rebuilds the hash table
% after garbage collection has moved everything.
(putd 'original-!%Reclaim (car (getd '!%Reclaim)) (cdr (getd '!%Reclaim)))

% New version of !%reclaim--shuffles stuff in cons tables after collecting
% garbage.
(DE !%Reclaim ()
  (prog1
    (original-!%Reclaim)

    % Move the old table to the new one, shuffling everything into its
    % correct position.
    (move-hcons-table
      % Would use IGetV, but there appears to be a bug preventing it from
      % working.
      % Source
      (GetV hash-cons-tables current-table-number)
      % Destination
      (GetV hash-cons-tables
          (next-table-number current-table-number)))

    % Point to new "current-table".
    (setf current-table-number
      (next-table-number current-table-number))))
