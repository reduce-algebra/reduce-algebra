%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:ASSOC-LISTS.SL
% Description:  More general associated list objects than primitive assoc-lists.
% Author:       Nancy Kendzierski
% Created:      September 29, 1983
% Modified:     09-Aug-84 18:58:25 (Nancy Kendzierski)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 26-Sep-86 (Leigh Stoller)
%  Added compiletime load of objects.
% 09-Aug-84 18:57:13 (Nancy Kendzierski)
%  Added position-eq, and changed position to use equal instead of eq.
% 11-Jun-84 17:30:02 (Nancy Kendzierski)
%  Corrected use of DELETE to REMOVE-LIST-ELEMENT-BY-POSITION-DESTRUCTIVELY.
% 20-Oct-83 15:51:32  Nancy Kendzierski
%  Added replace-item and fixed(?) nth and pnth.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
(compiletime (load objects))

(defun create-assoc-lists (ls)
  % The ls argument should be a list (possibly nil) of lists to
  % be associated.  If they are not of equal length, nil is returned.
  (let ((alists (make-instance 'assoc-lists)))
    (=> alists initialize ls)
    ))

(defflavor assoc-lists ((als nil)        % Associated lists
			(num-lists 0)    % Number of associated lists         
			(len-lists 0)    % Length of each list
			)
  ()
  (gettable-instance-variables als num-lists len-lists)
  settable-instance-variables
  initable-instance-variables
  )

(defmethod (assoc-lists initialize) (ls)
  (cond ((null ls)
	 (setf als nil)
	 (setf num-lists 0)
	 (setf len-lists 0)
	 self)
	((listp ls)
	 (setf num-lists (length ls))
	 (let ((check-len (length (first ls))))
	   (for (in l ls)
		(do (if (neq (length l) check-len) (exit nil)))
		(finally (setf als ls)
			 (setf len-lists check-len)
			 self)
		)))
	(t nil)
	))

(defmethod (assoc-lists add-list) (l)
  (when (and (listp l) (= (length l) len-lists))
    (setf als (append als (list l)))
    (setf num-lists (add1 num-lists))
    t))

(defmethod (assoc-lists remove-list) (list-index)
  (when (and (numberp list-index)
	     (> list-index 0)
	     (<= list-index num-lists))
    (setf als (remove-list-element-by-position-destructively als list-index))
    (setf num-lists (sub1 num-lists))
    t))

(defmethod (assoc-lists add-element) (elem)
  (when (and (listp elem) (= (length elem) num-lists))
    (setf als (for (in l als)
		   (for i 1 (add1 i))
		   (with new-lists)
		   (do (setf l (append l (list (nth elem i)))))
		   (collect l new-lists)
		   (finally (setf len-lists (add1 len-lists))
			    new-lists)))
    ))

(defmethod (assoc-lists remove-element) (elem)
  (when (and (listp elem) (= (length elem) num-lists))
    (let ((find-index (for (from i 1 len-lists)
			   (with index)
			   (do (setf index
				 (for (from j 1 num-lists)
				      (do (if (equal (nth elem j)
						     (nth (nth als j) i))
					    (exit j)))
				      (finally nil)))
			       (if index (exit index)))
			   (finally nil))))
      (when find-index
	(setf als
	  (for (in l als)
	       (do (setf l (remove-list-element-by-position-destructively
			    l find-index)))
	       (collect l)))
	(setf len-lists (sub1 len-lists))
	t)
      )))

(defmethod (assoc-lists remove-element-by-position) (elem-index)
  (when (and (numberp elem-index)
	     (> elem-index 0)
	     (<= elem-index len-lists))
    (setf als
      (for (in l als)
	   (do (setf l (remove-list-element-by-position-destructively
			l elem-index)))
	   (collect l)))
    (setf len-lists (sub1 len-lists))
    t))  

(defmethod (assoc-lists add-element-lists) (ls)
  (when (and (listp ls)
	     (= (length ls) num-lists)
	     (for (in l ls)
		  (with check-len)
		  (do 
		   (if (not (listp l)) (exit nil))
		   (unless check-len (setf check-len (length l)))
		   (if (neq (length l) check-len) (exit nil)))
		  (finally t)))
    (setf als (for (in l als)
		   (for i 1 (add1 i))
		   (with new-lists)
		   (do (setf l (append l (nth ls i))))
		   (collect l new-lists)
		   (finally (setf len-lists (+ len-lists (length (first ls))))
			    new-lists)))
    ))

(defmethod (assoc-lists position) (item lists-index)
  % Positions are indexed from 1.
  (when (and (numberp lists-index)
	     (> lists-index 0)
	     (<= lists-index num-lists))
    (let ((l (nth als lists-index)))
      (for (for i 1 (add1 i))
	   (in el l)
	   (do (if (equal item el) (exit i)))
	   (finally nil)
	   ))))

(defmethod (assoc-lists position-eq) (item lists-index)
  % Positions are indexed from 1.
  (when (and (numberp lists-index)
	     (> lists-index 0)
	     (<= lists-index num-lists))
    (let ((l (nth als lists-index)))
      (for (for i 1 (add1 i))
	   (in el l)
	   (do (if (eq item el) (exit i)))
	   (finally nil)
	   ))))

(defmethod (assoc-lists nth) (item-index lists-index)
  (when (and (numberp item-index)
	     (> item-index 0)
	     (<= item-index len-lists)
	     (numberp lists-index)
	     (> lists-index 0)
	     (<= lists-index num-lists))
    (nth (nth als lists-index) item-index)))

(defmethod (assoc-lists pnth) (item-index lists-index)
  (when (and (numberp item-index)
	     (> item-index 0)
	     (<= item-index len-lists)
	     (numberp lists-index)
	     (> lists-index 0)
	     (<= lists-index num-lists))
    (pnth (nth als lists-index) item-index)))

(defmethod (assoc-lists list) (lists-index)
  (when (and (numberp lists-index)
	     (> lists-index 0)
	     (<= lists-index num-lists))
    (nth als lists-index)))

(defmethod (assoc-lists assoc) (elem elindex alindex)
  (when (and (numberp elindex)
	     (> elindex 0) (<= elindex num-lists)
	     (numberp alindex)
	     (> alindex 0) (<= alindex num-lists))
    (let ((el (nth als elindex))
	  (al (nth als alindex)))
      (for (in e el)
	   (in a al)
	   (do (if (equal e elem) (exit a)))
	   (finally nil))
      )))

(defmethod (assoc-lists atsoc) (elem elindex alindex)
  (when (and (numberp elindex)
	     (> elindex 0) (<= elindex num-lists)
	     (numberp alindex)
	     (> alindex 0) (<= alindex num-lists))
    (let ((el (nth als elindex))
	  (al (nth als alindex)))
      (for (in e el)
	   (in a al)
	   (do (if (eq e elem) (exit a)))
	   (finally nil))
      )))

(defmethod (assoc-lists replace-item) (item-index lists-index new-item)
  (when (and (numberp item-index)
	     (> item-index 0)
	     (<= item-index len-lists)
	     (numberp lists-index)
	     (> lists-index 0)
	     (<= lists-index num-lists))
    (let ((lst (nth als lists-index)))
      (setf lst
	(append (reverse (pnth (reverse lst) (- (length lst) (- item-index 2))))
		(cons new-item (pnth lst (+ item-index 1)))))
      (setf als (for (in l als)
		     (for i 1 (add1 i))
		     (collect (if (= i lists-index) lst l))
		     )))
    ))

% Also: ass sassoc (need to use apply for these)

(de remove-list-element-by-position-destructively (l index)
  (let ((len (length l)))
    (if (and (> index 0) (<= index len))
      (cond ((= index 1) (cdr l))
	    ((= index len) (RplacD (pnth l (- index 1)) nil) l)
	    (t (let ((tail (pnth l index)))
		 (RplacW tail (cdr tail)) l))
	    )
      (stderror
       (bldmsg
	"Illegal use of REMOVE-LIST-ELEMENT-BY-POSITION-DESTRUCTIVELY: index=%w, list=%w"
			index l)))
    ))
