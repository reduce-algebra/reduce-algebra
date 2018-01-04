To keep things as simple as possible, work with the files in

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r33/

Try to get boot.sl to work first. Then I can try to build REDUCE 3.3!

dbuild.sl orchestrates building REDUCE. It inputs boot.sl, prolog.red,
rlisp.red, rend.red (in that order) to build RLISP, then continues to
build REDUCE.

For now, I have edited boot.sl to replace % with ; and to add \ where
necessary. (But a better approach might be as suggested below.)  This
slightly modified boot.sl seems to work with simple input of the form

(begin2)
a_simple_form;
end;

Now try to process rlisp.red, initially interactively via a SL
interaction buffer.

Consider using the newnam facility early. It might be better than
using advise and may be the only way to handle arrayp.

Also, consider regarding ! as only RLISP read syntax and not including
it in symbols. Edit boot.sl to replace ! with \ (and % with ;).

Could solve the function clash problem by implementing SL in
upper-case and using the raise flag.

PROGRESS
========

Processing rlisp.red modules. Must do this incrementally, since later
code relies on earlier code!

1. module -- OK. But note that you can't read this module twice. I
think that the rlis declaration for keyword `module' prevents a second
attempt to define procedure `module'!

2. newtok -- OK

3. support -- crashes Emacs! Functions arrayp, >=, <= are already
defined in Emacs Lisp. I have edited the file so that arrayp is
redefined using newnam. Later, I need to move this into prolog.red and
flag arrayp 'lose. This is supported by boot.sl. Elisp versions of >=
and <= are probably OK. Definitions commented out for now but later
should also flag 'lose. Now OK.

Note that tabs as white space can lead to "Symbol’s function
definition is void: !\", at least during the boot process. Consider
fixing this later if tabs are not handled correctly by rlisp.red.

4. slfns -- error max-lisp-eval-depth exceeded processing the list of
SL functions!  Default is 800. Try increasing to 2000. This may lead
to Emacs crashing! Not large enough. Just comment out this module for
now; I don't think it is necessary.

5. superv -- OK

6. tok -- redefines some functions in boot.sl! This causes trouble.  OK
to rread. Defining scan fails! Invalid function: (quote comment).
Part of procedure scan is in upper case, which is not processed
correctly. I need to solve the issue of character case properly, but
for now just downcase the offending code. Now OK.

7. xread -- OK
8. lpri -- OK
9. parser -- OK

10. block -- OK. I can now process all of rlisp.red in one go down to
the end of this module.

11. form -- identity already defined in elisp with one argument. Code
edited to define identity!* and use newnam.

Error defining form; probably in form1.

form1 starts like this:

(lambda
  (u vars mode)
  (block
   ((x . scalar)
	(y . scalar))
   (cond ...)))

What is block? This probably isn't working:

putd('block,'macro,
 '(lambda (u) (cons 'prog
                 (cons (mapcar (cadr u) (function car)) (cddr u)))));

The problem is that Standard Lisp macros are nospread and so take a
single parameter that gets the list of arguments. So I need to
redefine putd to take a &rest parameter. Standard Lisp macros also get
their names as their first argument, so I need to build this into the
macro body.

Revised putd and getd (and dm) to handle macros properly (I hope). Now
OK.

12. proc -- OK
13. forstat -- OK

14. loops -- defining symbolic macro procedure while causes Lisp
nesting exceeds ‘max-lisp-eval-depth’. repeat and while are already
defined in Emacs Lisp, so rename them to repeat!* and while!*. Now OK.

15. write -- OK
16. smacro -- OK
17. infix -- OK
18. where -- OK

19. list -- problem in definition of rappend and rcons, which causes
problems reading following module. Skip this module for now.

20. array -- renamed listp to listp!*. Now OK
21. switch -- OK
22. io -- OK
23. inter -- OK
[end of file rlisp.red]
