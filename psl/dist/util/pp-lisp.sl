%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PP-LISP.SL
% Description:  Prettyprinter
% Author:       Alan Foster, Hewlett-Packard Corp.
% Created:      11-Oct-84
% Modified:     22-Feb-85 09:25:09 (Alan Foster)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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

% 25-Aug-88 (Julian Padget)
% Local variable "stack" changed to "stk" to avoid binding of global variable.

(bothtimes
  (progn
   (global
    '(*stream*  % a buffer used by the function scan to store tokens it has already seen
      *size*  % a buffer used to store the length associated with each token stored in the
              % stream buffer
      *right*  % the index which marks the right end of the buffer
      *right_total*  % the number of spaces needed to print all elements of the buffer from
                     % stream [1] through stream [right]
      *left*  % the index which marks the left end of the buffer
      *left_total*  % the number of spaces needed to print all elements of the buffer from
                    % stream [1] through stream [left]
      *array_size*  % the dimension of the stream and size buffers, a value three times the
                    % line width is sufficient
      *line_width*  % the length of an output line
      *cannot_fit*  % the length assigned to a token once it has been determined that
                    % the token will not fit on the current line of output
      *space*  % the number of spaces left on the current line of output
      *xblank*  % right bracket tokens must always be followed by a blank token, when this
                % convention is not met a blank token is inserted into the stream, the value
                % of this identifier is the blank which is inserted
      *function_names*
      *maxdepth*
      *maxlength*
      *comment*
      *source*
      *sink*))

   (fluid 
    '(*scan_stack*  % the stack used within the function scan
      *print_stack*  % the stack used within the output function pprint
      *tokens*
      *control*
      *calls*))))

(loadtime
 (progn
  (load compiler)     % when a format is defined, its definition will be compiled

  (put '{ 'pp-alias '(< "("))
  (put '} 'pp-alias '([i 0 0] ")" >))
  
  (setq *line_width* 75
        *cannot_fit* (add1 *line_width*)
	*array_size* (* 3 *line_width*)
	*stream* (make-vector *array_size* nil)
	*size* (make-vector *array_size* nil)
	*maxdepth* 10
	*maxlength* 25
	*comment* #/%
	*xblank* [i 0 0]
	*function_names* '(t))))

(dm blank-length (b) `(vector-fetch ,(second b) 1))
(dm blank-offset (b) `(vector-fetch ,(second b) 2))

(de new-depth (n)
  (cond ((null n) *maxdepth*)
	((and (fixp n) (>= n 0)) (setq *maxdepth* n))))

(de new-length (n)
  (cond ((null n) *maxlength*)
	((and (fixp n) (>= n 0)) (setq *maxlength* n))))

(de line-width (width)

% This function is used to set the line width, the dimension of the stream and size
% buffers must be three times the line width.

  (let ((old-width *line_width*))
    (when (and (fixp width) (> width 0))
      (setq *line_width* width
	    *cannot_fit* (add1 width)
	    *array_size* (* 3 width))
      (when (> width old-width)
	(setq *stream* (make-vector *array_size* nil)
	      *size* (make-vector *array_size* nil))))))

(df popbottom (alist)
  (let ((name (first alist)) (stk (eval (first alist))))
    (cond ((null stk) nil)
          ((null (rest stk)) (prog1 (pop stk) (set name nil)))
          (t (do ((fpointer (rest stk) (rest fpointer))
                  (bpointer stk (rest bpointer)))
                 ((null (rest fpointer)) (rplacd bpointer nil) (first fpointer)))))))

(de pp-file (source-file destination-file)

% Top level function for prettyprinting the contents of one file to another. The file names
% are passed as strings, the source file name should be the first argument.

  (let ((old_length))
    (setq *source* nil *sink* nil)
    (unwind-protect
     (progn (vector-store lispscantable* *comment* 11)
	    (put (int2id *comment*) 'lispreadmacro 'read-comment)
	    (setq *source* (open source-file 'input)
     	          *sink* (open destination-file 'output))
	    (setq old_length (channellinelength *sink* (+ *line_width* 10)))
	    (do ((form (channelread *source*) (channelread *source*)))
		((eq form $eof$))
		(scan form 0)
		(channelterpri *sink*)
		(if (not (is-comment form)) (channelterpri *sink*))
		(if (define-form form) (print (second form)))))
     (vector-store lispscantable* *comment* 12)
     (remprop (int2id *comment*) 'lispreadmacro)
     (when *source* (close *source*))
     (when *sink* (channellinelength old_length) (close *sink*)))))

(de define-form (form)
  (memq (first form) '(de df dm dn ds defmethod defflavor defmacro)))

(de pp-form (form)

% Top level function for prettyprinting an object

  (let ((length (linelength (+ *line_width* 10))))
    (unwind-protect
     (progn
      (setq *sink* out*)
      (scan form (posn))
      (terpri))
     (linelength length))))

(df pp-object (alist)

% This function is similar to pp-form except that it accepts additional
% arguments, indentation and sink.

  (unless (null alist)
    (let ((object (eval (first alist)))
	  (destination nil)
	  (indentation 0)
	  (old_length))
      (do ((remaining (rest alist) (rest (rest remaining))))
	  ((null remaining))
	  (cond ((eq (first remaining) ':sink)
		 (setq destination (eval (second remaining))))
		((eq (first remaining) ':indent)
		 (setq indentation (eval (second remaining))))))
      (unwind-protect
       (progn (if destination
		(setq *sink* destination)
		(setq *sink* out*))
	      (setq old_length (channellinelength *sink* (+ *line_width* 10)))
	      (when (>= indentation (channelposn *sink*))
		(channelspaces *sink* (- indentation (channelposn *sink*))))
              (scan object indentation)
	      (channelterpri *sink*))
       (when *sink* (channellinelength *sink* old_length))))))

(de scan (block margin)

% This function successively adds tokens to the right end of the stream buffer.
% The value of status indicates whether or not the current token is within
% a pair of logical brackets. If a blank is found not to be within logical
% brackets then it will be ignored. Associated with each token is a length.
%   string - the length of the string
%   left bracket - the sum of the length of each string and blank in the block
%   right bracket - zero
%   blank - the sum of the length of the blank and the length of the next block
%   comment - the length of a comment is always one greater than the width
%             of a line

  (let* ((status 0)
	 (*scan_stack* nil)
	 (*print_stack* nil)
	 (*tokens* nil)
	 (*control* nil)
	 (result (errset (progn 
			  (dispatch block 1)
			  (setq *space* (- *line_width* margin))
			  (do ((token (receive) (receive)))
			      ((eq token 'eof))
			      (cond ((eq token '<)
				     (setq status (sub1 status)) (block-begin token))
				    ((eq token '>)
				     (setq status (add1 status)) (block-end token))
				    ((and (blank token) (minusp status)) 
				     (break-token token))
				    ((or (is-comment token) (stringp token)) 
				     (string-token token)))))
			 nil)))
    (when (not (pairp result)) 
      (channelprin2 *sink* " *** Aborted ***"))))
  
(de block-begin (token)

% This function is called when a left bracket is received, the left bracket denotes
% the beginning of a logical block. The left bracket is stored at stream [right]
% and -right_total is stored at size [right], when the corresponding right bracket is
% received the size of the block is the sum of size [right] and the current value of
% right_total

  (if (null *scan_stack*) (reset-pointers) (bump-right))
  (vector-store *stream* *right* token)
  (vector-store *size* *right* (minus *right_total*))
  (push *right* *scan_stack*))

(de block-end (token)

% This function is called when a right bracket is received, the right bracket denotes
% the end of a logical block. The top of the stack is either the index of the corresponding
% left bracket, if the block contained no blanks, or the index of the previous blank in
% this block and underneath that the index of the corresponding left bracket.
% In the former case the length associated with the left bracket is computed, in the
% the latter, the length associated with the blank and the left bracket are
% computed.

  (if (null *scan_stack*)
    (pprint token 0)
    (progn (bump-right)
           (vector-store *stream* *right* token)
           (vector-store *size* *right* 0)
           (set-length (first *scan_stack*))
           (if (and (blank (vector-fetch *stream* (pop *scan_stack*)))
                    (not (null *scan_stack*)))
             (set-length (pop *scan_stack*)))
           (if (null *scan_stack*) (advance-left (vector-fetch *stream* *left*)
						 (vector-fetch *size* *left*))))))

(de break-token (token)

% This function is called when a blank is received, the top of the stack contains either
% an index to the start of the block or the index to the previous blank. If the index
% references the previous blank then the length associated with that blank is computed.

  (if (null *scan_stack*)
    (reset-pointers)
    (progn (bump-right)
           (if (blank (vector-fetch *stream* (first *scan_stack*)))
             (set-length (pop *scan_stack*)))))
  (vector-store *stream* *right* token)
  (vector-store *size* *right* (minus *right_total*))
  (push *right* *scan_stack*)
  (setq *right_total* (+ (blank-length token) *right_total*)))

(de string-token (token)

% This function is called when a string or comment is received.

  (let ((length (if (is-comment token) *cannot_fit* (string-length token))))
    (if (null *scan_stack*)
      (pprint token length)
      (progn (bump-right)
             (vector-store *stream* *right* token)
             (vector-store *size* *right* length)
             (setq *right_total* (+ *right_total* length))
             (do ()
                 ((<= (- *right_total* *left_total*) *space*))
                 (vector-store *size* (popbottom *scan_stack*) *cannot_fit*)
                 (advance-left (vector-fetch *stream* *left*)
                               (vector-fetch *size* *left*)))))))

(de advance-left (item length)

% This function is used by the function scan to force ouput from the left of the stream
% buffer. All items at the left of the stream buffer whose lengths have been determined
% are sent to the output routine.

  (if (>= length 0)
    (progn (pprint item length)
           (cond ((blank item) (increment-left (blank-length item)))
                 ((or (stringp item) (is-comment item)) (increment-left length)))
           (if (/= *left* *right*)
             (progn (if (= *left* *array_size*) (setq *left* 1) (setq *left* (add1 *left*)))
                    (advance-left (vector-fetch *stream* *left*)
                                  (vector-fetch *size* *left*)))))))

(de pprint (item length)

% This function implements the output routine, the responses to the five types of
% tokens are
% 
% comment - A recursive call is made, the new item is the string which represents
%           the actual comment, the new length is the space left on the current
%           line of output.
% string - The string is printed and the space left on the current line is decreased by
%          the length of the string.
% left bracket - If the length associated with the token exceeds the space left on
%                the current line then the current indentation is pushed onto the stack,
%                otherwise a special value is pushed onto the stack.
% right bracket - The stack is popped.
% blanks - A comment is always preceded by a blank, the length associated with
%          comments is always one greater than the width of an output line.
%          This has two effects, it inhibits the output routine from printing
%          anything to the right of the comment and the blank is treated as
%          a line break. If there is sufficient space to print the comment
%          then a line break should not be forced. When a blank is received
%          and the length of the comment does not exceed the remaining space
%          the length associated with the blank is set equal to the remaining
%          space.
%   inconsistent - If the length associated with the blank exceeds the space
%                  left on the current line then a new line is begun, the indentation
%                  is determined by the value on the top of the stack and the
%                  offset associated with the blank.
%   consistent - If the top of the stack is not the special value then the
%                block which contains this blank was too large to fit on the
%                current line, since the blank is consistent a new line is begun,
%                note that the length of the blank is ignored.

  (cond ((is-comment item) (pprint (comment-body item) *space*))
        ((stringp item)
         (channelprin2 *sink* item)
         (if (> *space* length)
           (setq *space* (- *space* length))
           (setq *space* 0)))
        ((eq item '<)
         (if (> length *space*) (push *space* *print_stack*) (push -1 *print_stack*)))
        ((eq item '>) (pop *print_stack*))
        ((blank item)
         (if (and (is-comment (next-item))
                  (<= (string-length (comment-body (next-item))) *space*))
           (setq length *space*))
         (cond ((inconsistent-b item) 
                (if (> length *space*) (new-line item) (p-space item)))
               ((consistent-b item)
                (if (= (first *print_stack*) -1) (p-space item) (new-line item)))))))

(de receive ()

% This function passes the next token to the function scan.
%  If the next token to pass is a right bracket and the token following it is
%  not a blank then a blank will be inserted.
%  If the next two tokens to pass are blanks then the first blank is discarded
%  and a recursive call is made to receive.

  (let ((first (first-token))
	(second (second-token)))
    (cond ((and (blank first) (null second))
	   (get-token) 'eof)
	  ((and (eq first '>) (not (blank second)))
	   (prog1 (get-token) (push *xblank* *tokens*)))
	  ((and (blank first) (blank second))
	   (get-token) (receive))
	  (t (get-token)))))

(de get-token () 
  (if (null *tokens*) 'eof (pop *tokens*)))
  
(de first-token ()
  (when (and (null *tokens*)
	     (not (null *control*)))
    (apply (pop *control*) (pop *control*)))
  (if (null *tokens*) nil (first *tokens*)))

(de second-token ()
  (when (and (< (length *tokens*) 2)
	     (not (null *control*)))
    (apply (pop *control*) (pop *control*)))
  (if (< (length *tokens*) 2) nil (second *tokens*)))

(de add-tokens (tokens)
  (setq *tokens* (if (or (is-comment tokens) (not (pairp tokens)))
		   (aconc *tokens* tokens)
		   (nconc *tokens* (copy tokens)))))

(de save-state (arguments function)
  (push arguments *control*)
  (push function *control*))

(de dispatch (item depth)

% This function is responsible for the identification and application of a function
% which will generate a stream of tokens for the lisp object.

  (cond ((object-type item) (apply (find-template-for-instance item) (list item depth)))
        ((atom item) (apply (find-template-for-atom item) (list item depth)))
	 % a maximum depth of zero implies that there will be no restriction on
         % the depth of list structure
        ((and (> *maxdepth* 0) (> depth *maxdepth*)) (add-tokens "#"))
        (t (let ((acopy (if (is-comment item)
			  item
			  (check-length item))))
             (if (has-template acopy)
               (apply (get-template acopy) (list acopy (add1 depth)))
               (default-template acopy (add1 depth)))))))

(de check-length (item)
  (do ((structure item (rest structure))
       (length 0 (add1 length))
       (result nil (aconc result (first structure))))
      ((or (atom structure)
            % a maximum length of zero implies that there will be no restriction
            % on the length of list structure
           (and (> *maxlength* 0) (= length *maxlength*))) 
       (cond ((= length *maxlength*) (aconc result (newid "...")))
             ((null structure) result)
             (t (nconc result (list '!. structure)))))))

(de default-template (item depth)

% This function provides default templates for lists whose first element does not
% identify a format function. In addition to a template which will work for any list
% there are templates provided for lists of single elements and lists whose first element
% is the name of a function.

  (cond ((null (rest item)) (define-tokens '("(" * ")") item depth))
        ((application item) (apply (function apply-template) (list item depth)))
        (t (define-tokens '({ (* [c 1 1]) }) (list item) depth))))

(de application (item)

% Determine if the first element of the list is the name of a function.

  (let ((head (first item)))
    (or (and (pairp head) (eqcar head 'lambda))
	(and (idp head) 
	     (or (not (funboundp head))
		 (memq head *function_names*))))))

(de apply-template (item depth)
  (define-tokens '({ * " " < (* [c 1 0]) > }) (list (first item) (rest item)) depth))

(de has-template (object)
  (let ((item (get (first object) 'pp-format)))
    (and item (required-size item) (>= (length object) (required-size item)))))

(de get-template (object) (function-name (get (first object) 'pp-format)))

(de find-template-for-instance (item)
  (let ((template (get (object-type item) 'pp-format)))
    (if template (function-name template) 'generic-instance-template)))

(de generic-instance-template (item depth)
  (define-tokens (list (bldmsg "%w" item)) () depth))

(de find-template-for-atom (item)
  (function-name (get (get-type item) 'pp-format)))

(de get-type (item)
  (cond ((stringp item) 'string)
        ((numberp item) 'number)
        ((vectorp item) 'vector)
        ((codep item) 'code)
        (t 'symbol)))

(df add-functions (names)
  (setq *function_names* (append names *function_names*)))

(de define-tokens (symbols objects depth)

% This function will merge a list of format symbols with a list of lisp objects
% into a stream of tokens acceptable to the prettyprinter. An auxiliary
% function is used to generate tokens when a repetitive pattern is encountered.

  (cond ((null symbols))
        ((get (first symbols) 'pp-alias)
	 (add-tokens (get (first symbols) 'pp-alias))
	   (define-tokens (rest symbols) objects depth))
        ((constant (first symbols))
	 (add-tokens (first symbols))
	   (define-tokens (rest symbols) objects depth))
	(t (when (pairp (rest symbols))
	     (save-state (list (rest symbols) (rest objects) depth)
			 (function define-tokens)))
	   (if (eq (first symbols) '*)
	     (dispatch (first objects) depth)
	     (unless (null objects)
	       (define-repeat-tokens (first symbols) (first objects) (first symbols) depth))))))

(de define-repeat-tokens (symbols objects pointer depth)

% Generate a list of tokens from the format symbols and the list of objects. It is assumed
% that the list of format symbols consists of constants or the symbol '*'. The first
% argument, symbols, is used for reference, the pointer argument is used to access elements
% of this list. The terminating condition is the occurance of the format symbol '*'
% and an object list which consists of a single element.

  (cond ((get (first symbols) 'pp-alias)
	 (add-tokens (get (first pointer) 'pp-alias))
	 (define-repeat-tokens symbols objects (advance-pointer symbols pointer) depth))
        ((constant (first pointer))
	 (add-tokens (first pointer))
	 (define-repeat-tokens symbols objects (advance-pointer symbols pointer) depth))
	((null (rest objects)) (dispatch (first objects) depth))
	(t (save-state (list symbols (rest objects) (advance-pointer symbols pointer) depth)
		       (function define-repeat-tokens))
	   (dispatch (first objects) depth))))

(de constant (item)

% Format symbols which are considered constants are comments, blanks, brackets and strings

  (or (is-comment item)
      (blank item) 
      (eq item '<)
      (eq item '>)
      (stringp item)))

(de advance-pointer (symbols pointer)

% Advance the pointer within a list of format symbols which are being used repetitively,
% the pointer is moved to the beginning of the list of symbols if it is currently pointing
% at the last element of the symbol list.

  (if (null (rest pointer)) symbols (rest pointer)))

(de next-item ()
  (let ((index (if (= *left* *array_size*) 1 (add1 *left*))))
    (vector-fetch *stream* index)))


(de reset-pointers () 
  (setq *left* (setq *right* (setq *left_total* (setq *right_total* 0)))))

(de bump-right ()
  (if (= *right* *array_size*) (setq *right* 1) (setq *right* (add1 *right*))))

(de increment-left (amount) (setq *left_total* (+ *left_total* amount)))

(de set-length (index)

% Store the size associated with the token in the stream buffer which is located
% by the value of index.

  (vector-store *size* index (+ *right_total* (vector-fetch *size* index))))

(de install-format (symbol name size)
    (put symbol 'pp-format (make-entry name size)))

(de make-entry (name size) (cons name size))

(de required-size (item) (cdr item))

(de function-name (item) (car item))

(de blank (item) (and (vectorp item)
                      (= (vector-size item) 3)
                      (memq (vector-fetch item 0) '(i c))))

(de consistent-b (item) (and (vectorp item)
                             (= (vector-size item) 3)
                             (eq (vector-fetch item 0) 'c)))

(de inconsistent-b (item) (and (vectorp item)
                               (= (vector-size item) 3)
                               (eq (vector-fetch item 0) 'i)))

(de is-comment (form) (and (pairp form) (eq (first form) 'comment)))

(de comment-body (item) (second item))

(de read-comment (channel token)

% Comments are converted to (comment "% ... ").

  (do ((result (id2string token) (string-concat result (string character)))
       (character (channelreadchar channel) (channelreadchar channel)))
      ((or (eq character (char eof)) (eq character (char eol)))
       (list 'comment result))))

(de new-line (item)

% Start a new line, this function is passed a blank token. The correct level of
% indentation is the sum of the indentation stored on the top of the stack and the
% offset defined by the blank.

  (setq *space* (- (first *print_stack*) (blank-offset item)))
  (channelterpri *sink*)
  (channelspaces *sink* (- *line_width* *space*)))

(de p-space (item)

% Print the number of spaces associated with the blank, the number of spaces left on the
% current line is also updated.

  (let ((n (if (> (blank-length item) *space*) *space* (blank-length item))))
    (channelspaces *sink* n)
    (setq *space* (- *space* n))))

(de front (item n)
  (if (not (zerop n)) (cons (first item) (front (rest item) (sub1 n)))))

% The following two functions are provided to enable the user to define formats.

(defmacro template (symbols . objects)
  `(progn (push (function define-tokens) *calls*)
	  (push (list ,symbols (list ,@objects) depth) *calls*)))

(df deformat (form)
  (let ((names (car (first form)))
	(length (cdr (first form)))
	(argument (second form))
	(body (rest (rest form)))
	(name (gensym)))
    (putd name 
	  'expr 
	  `(lambda (,@argument depth)
	     (let ((*calls* nil))
	       ,@body
	       (setq *control* (append (reversip *calls*) *control*))
	       (unless (null *control*)
		 (apply (pop *control*) (pop *control*))))))
    (if (pairp names)
      (for (in key names) (do (install-format key name length)))
      (install-format names name length))))
         
% The following functions define initial formats, if the function deformat were
% used the compiler would be invoked as this module were being loaded.

(de lambda-template (item depth)
  (if (null (second item))
    (define-tokens '({ * [i 1 1] "()" [c 1 1] (* [c 1 1]) })
		   (list (first item) (rest (rest item))))

    (define-tokens '({ * [i 1 1] (* [c 1 1]) })
		   (list (first item) (rest item)))))
    
(de define-template (item depth)
  (if (null (third item))
    (define-tokens '({ * [i 1 1] * [i 1 1] "()" [c 1 1] (* [c 1 1]) })
		   (list (first item) (second item) (rest (rest (rest item)))))
    (define-tokens '({ * [i 1 1] * [i 1 1] (* [c 1 1]) })
		   (list (first item) (second item) (rest (rest item))))))
    
(de definition-template (item depth)
  (define-tokens
   '({ * [i 1 1] "." [i 1 1] * }) 
   (list (first item) (if (eq (second item) 'lambda) (rest item) (third item)))))

(de function-template (item depth)
  (define-tokens '("#'" *) (list (second item))))

(de quote-template (item depth)
  (define-tokens '("'" *) (list (second item))))

(de backquote-template (item depth)
  (define-tokens '("`" *) (list (second item))))

(de unquote-template (item depth)
  (define-tokens '("," *) (list (second item))))

(de unquotel-template (item depth)
  (define-tokens '(",@" *) (list (second item))))

(de string-template (item depth)
  (define-tokens (list (string-concat """" item """")) nil))

(de symbol-template (item depth)
  (define-tokens (list (string-downcase (bldmsg "%p" item))) nil))

(de code-number-template (item depth)
  (define-tokens (list (bldmsg "%w" item)) nil))

(de vector-template (item depth)
  (define-tokens '(< "[" (* [i 1 1]) "]" >) (list (vector2list item))))
  
(de comment-template (item depth)
  (define-tokens (list [i 1 0] item) nil))

(de foreach-template (item depth)
  (define-tokens '({ (* [i 1 0]) [c 1 1] (* [c 1 0]) }) 
		 (list (front item 5) (pnth item 6))))

(de set-template (item depth)
  (define-tokens '({ * " " < (* [i 1 1] * [c 1 0]) > }) 
		 (list (first item) (rest item))))

(de defflavor-template (item depth)
  (define-tokens '({ * [i 1 1] * [c 1 11] (* [c 1 8]) })
		 (list (first item) (second item) (rest (rest item)))))

(de defmethod-template (item depth)
  (define-tokens '({ * [i 1 1] * [i 1 11] (* [c 1 8]) })
		 (list (first item) (second item) (rest (rest item)))))
(loadtime

% Install initial format definitions.

  (progn
   (install-format 'lambda 'lambda-template 3)
   (for (in key '(de df dn dm ds defmacro deflambda defun))
	(do (install-format key 'define-template 4)))
   (for (in key '(expr fexpr nexpr macro))
	(do (install-format key 'definition-template 1)))
   (install-format 'function 'function-template 2)
   (install-format 'quote 'quote-template 2)
   (install-format 'backquote 'backquote-template 2)
   (install-format 'unquote 'unquote-template 2)
   (install-format 'unquotel 'unquotel-template 2)
   (install-format 'string 'string-template nil)
   (install-format 'symbol 'symbol-template nil)
   (for (in key '(code number))
	(do (install-format key 'code-number-template nil)))
   (install-format 'vector 'vector-template nil)
   (install-format 'comment 'comment-template 2)
   (install-format 'foreach 'foreach-template 6)
   (for (in key '(set setq))
	(do (install-format key 'set-template 3)))
   (install-format 'defflavor 'defflavor-template 4)
   (install-format 'defmethod 'defmethod-template 4)))
