%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           openmath.sl
% Description:    Interface for an OpenMath prototype
% Author:         Winfried Neun , ZIB Berlin
% Created:        1-July 1996
% Status:         Experimental (Do Not Distribute)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
(dm enum (l)
  (prog (cnt res)
    (setq cnt -1)
    (mapc (cdr l) (function (lambda (x) (list 'define-constant x cnt)
              (setq cnt (add1 cnt)) 
	      (setq res (cons (list 'define-constant x cnt) res)))))
    (return (cons 'progn res))))
)

(enum OM_ENCOD_BIN  OM_ENCOD_SGML )

(enum   OM_TYPE_INT OM_TYPE_FLOAT64 OM_TYPE_BYTEARRAY OM_TYPE_STRING 
	OM_TYPE_SYMBOL OM_TYPE_VAR OM_TYPE_ATTRIBUTED OM_TYPE_APP
	OM_TYPE_COMMAND OM_TYPE_ERROR OM_TYPE_ENDAPP OM_TYPE_ENDCOMMAND
	OM_TYPE_ENDERROR  OM_TYPE_UNKNOWN )

% predicates

(ds OMcontextp (con) (eqcar con 'OMcontext))
(ds OMsymbolp  (con) (eqcar con 'OMsymbol))
(ds OMdevicep  (con) (eqcar con 'OMdevice))
(ds OMconnp    (con) (eqcar con 'OMconn))

(de OMmakeContext (str)
 (cons  'OMcontext (!O!Mmake!Context (strbase (strinf
			(if (idp str) (id2string str) str))))))

(de OMnamedContext (con) t)

(de OMcontextName(con)
 (if (omcontextp con)
   (importforeignstring (!O!Mcontext!Name (cdr con)))
   (error " no OMcontext" con)))

(de OMmakeSymbol (cont str )
 (cons 'OMsymbol (!O!Mmake!Symbol (if (omcontextp cont) (cdr cont)
				 (error " no context" cont))
		 		(strbase (strinf (if (idp str)
					(id2string str) str))))))

(de OMsymbolContext (sy)
 (if (OMsymbolp sy)
   (cons 'OMcontext (!O!Msymbol!Context (cdr sy)))
   (error " no OMsymbol" sy )))

(de OMsymbolName (sy)
 (if (OMsymbolp sy)
   (importforeignstring (!O!Msymbol!Name (cdr sy)))
   (error " no OMsymbol" sy )))


(de OMmakeDevice (enc IO) (cons 'OMdevice (!O!Mmake!Device enc IO)))

(de OMmakeConn (n)
	(cons 'OMconn (!O!Mmake!Conn n)))

(de OMconnTCP (conn str port)
    (if (OMconnp conn)
	 (!O!Mconn!T!C!P (cdr conn)
	     (strbase (strinf (if (idp str) (id2string str) str))) port)
	(error (list  " no OMconn:" conn))))

(de OMconnUnix (conn str )
        (!O!Mconn!Unix (if (omconnp conn) (cdr conn)
                                 (error (list " no OMconn" conn)))
                   (strbase (strinf (if (idp str) (id2string str) str)))))

(de OMbindTCP (conn nnn )
        (!O!Mbind!T!C!P (if (omconnp conn) (cdr conn)
                                 (error (list " no OMconn" conn))) nnn))

(de OMbindUnix (conn str )
        (!O!Mbind!Unix (if (omconnp conn) (cdr conn)
                                 (error (list " no OMconn" conn)))
                   (strbase (strinf (if (idp str) (id2string str) str)))))

(de OMputInt32 (dev n)
  (if (and (OMdevicep dev) (fixp n))
	(!O!MPut!Int32 (cdr dev) (int2sys n))
   (error "OMputInt32" (cons dev n))))

(de OMputFLoat64 (dev n)
  (if (and (OMdevicep dev) (floatp n))
        (!O!MPUT!Float64 (cdr dev) (floatbase (fltinf n)))
   (error "OMputFLoat64" (cons dev n))))

(de OMputByteArray (dev n)
  (if (and (OMdevicep dev) (atom n))
        (!O!MPUT!Byte!Array (cdr dev) (vecbase (vecinf n)))
   (error "OMputByteArray" (cons dev n))))

(de OMputString (dev n)
  (if (and (OMdevicep dev) (stringp n))
        (!O!MPUT!String (cdr dev) (strbase (strinf n)))
   (error "OMputString" (cons dev n))))

(de OMputVar (dev n)
  (if (and (OMdevicep dev) (stringp n))
        (!O!MPUT!Var (cdr dev) (strbase (strinf n)))
   (error "OMputVar" (cons dev n))))

(de OMputSymbol (dev n)
  (if (and (OMdevicep dev) (OMSymbolp n))
        (!O!MPUT!Symbol (cdr dev) (cdr n))
   (error "OMputSYmbol" (cons dev n))))

(de OMputApp (dev)
  (if (OMdevicep dev) (!O!MPUT!App (cdr dev))
   (error "OMputApp" dev )))

(de OMputEndApp (dev)
  (if (OMdevicep dev) (!O!MPUT!End!App (cdr dev))
   (error "OMputEndApp" dev )))

(de OMputAttrib (dev)
  (if (OMdevicep dev) (!O!MPUT!Attrib (cdr dev))
   (error "OMputAttrib" dev )))

(de OMputEndAttrib (dev)
  (if (OMdevicep dev) (!O!MPUT!End!Attrib (cdr dev))
   (error "OMputEndAttrib" dev )))

(de OMputCommand (dev)
  (if (OMdevicep dev) (!O!Mput!Command (cdr dev))
   (error "OMputCommand" dev )))

(de OMputEndCommand (dev)
  (if (OMdevicep dev) (!O!Mput!End!Command (cdr dev))
   (error "OMputEndCommand" dev )))

(de OMputError (dev)
  (if (OMdevicep dev) (!O!MPUT!Error (cdr dev))
   (error "OMputError" dev )))

(de OMputEndError (dev)
  (if (OMdevicep dev) (!O!MPUT!End!Error (cdr dev))
   (error "OMputEndError" dev )))

%%%%%%%%%%%

(de OMgetApp  (dev)
  (if (OMdevicep dev) (!O!Mget!App (cdr dev))
   (error "OMgetApp" dev )))

(de OMgetEndApp  (dev)
  (if (OMdevicep dev) (!O!Mget!End!App (cdr dev))
   (error "OMgetEndApp" dev )))

(de OMgetCommand (dev)
  (if (OMdevicep dev) (!O!Mget!Command (cdr dev))
   (error "OMgetCommand" dev )))

(de OMgetEndCommand (dev)
  (if (OMdevicep dev) (!O!Mget!End!Command (cdr dev))
   (error "OMgetEndCommand" dev )))

(de OMgetError (dev)
  (if (OMdevicep dev) (!O!Mget!Error (cdr dev))
   (error "OMgetError" dev )))

(de OMgetEndError (dev)
  (if (OMdevicep dev) (!O!Mget!End!Error (cdr dev))
   (error "OMgetEndError" dev )))

(de OMgetType (dev)
  (if (OMdevicep dev) (!O!Mget!Type (cdr dev))
   (error "OMgetType" dev )))

(de OMgetLength (dev)
  (if (OMdevicep dev) (!O!Mget!Length (cdr dev))
   (error "OMgetLength" dev )))

(de OMgetInt32 (dev)
  (if (OMdevicep dev) 
	(progn (!O!Mget!Int32 (cdr dev) onewordbuffer)
		(cons 'OMint32 (wgetv onewordbuffer 0)))
   (error "OMgetInt32" dev )))

(de OMgetFloat64 (dev)
  (if (OMdevicep dev) 
     (let ((ff (gtfltn)))
	(!O!Mget!Float64 (cdr dev) (floatbase ff))
	(cons 'OMfloat64 (mkfltn ff)))
   (error "OMgetFloat64" dev )))

(de OMgetByteArray (dev)
  (if (OMdevicep dev) (cons 'OMByteArray (!O!Mget!Byte!Array (cdr dev)))
   (error "OMgetByteArray" dev )))

(de OMgetString (dev)
  (if (OMdevicep dev) 
     (let ((ll (!O!Mget!Length (cdr dev))) ss)
	(setq ss (gtstr ll))
	(!O!Mget!String (cdr dev) (strbase ss))
	(cons 'OMString (mkstr ss)))
   (error "OMgetString" dev )))

(de OMgetVar (dev)
  (if (OMdevicep dev) (cons 'OMVAR (!O!Mget!Var (cdr dev)))
   (error "OMgetVar" dev )))

(de OMgetSymbol (dev)
  (if (OMdevicep dev) (cons 'OMsymbol (!O!Mget!Symbol (cdr dev)))
   (error "OMgetSymbol" dev )))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Applications
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%writing

(fluid '(currentidevice!* currentodevice!* currentcontext!*
	 onewordbuffer))

(de psl_symbol_to_OM_symbol (id)
  (let ((OMs (get id 'OMsymbol)))
      (if OMs OMs
           (setq OMs (OMmakeSymbol currentcontext!* id))
	   (put 'id 'OMsymbol OMs)
           OMs)
))

(de psl_to_OM (form)
 (cond ((pairp form) (OMputCommand currentodevice!*)
            (OMputSymbol currentodevice!*
			 (psl_symbol_to_OM_symbol (car form)))
	    (mapc (cdr form) (function psl_to_OM1))
	    (OMputEndCommand currentodevice!*))
      (t (print (list "non list form found:" form))))  
 NIL)

(de psl_to_OM1 (form)

 (cond	((idp form) (OMputSymbol currentodevice!*
				 (psl_symbol_to_OM_symbol form)))
	((fixp form) (OMputInt32  currentodevice!* form))
	((floatp  form) (OMputInt32 currentodevice!* form))
        ((stringp form) (OMputString currentodevice!* form))
        ((pairp form) (psl_to_OM form))
	(t (error "unknown item for ps_to OM:" form))))

% reading

(de OM_to_psl1 (dev)
   (let ((aa NIL) typ)
           (while (and (not (eq  typ 'OM_TYPE_ENDCOMMAND))
           		(not (eq  typ 'OM_TYPE_ENDApp)))
		(setq aa (cons (setq typ (OM_to_psl dev)) aa)))
         (reverse (cdr aa))))

(de OM_to_psl (dev)
 (let (aa typ)
  (setq typ (OmgetType dev))
  (cond ((eq typ OM_TYPE_INT)          (OMgetInt32 dev))
	((eq typ  OM_TYPE_FLOAT64)     (OMgetFloat64 dev))
	((eq typ  OM_TYPE_BYTEARRAY 2) (OMgetBytearray dev))
	((eq typ  OM_TYPE_STRING)      (OMgetString dev))
	((eq typ  OM_TYPE_SYMBOL)      (OMgetSymbol dev))
	%(eq typ  OM_TYPE_VAR 5)
	%(eq typ  OM_TYPE_ATTRIBUTED 6)
	((eq typ  OM_TYPE_APP 7)      (OMgetApp dev)  (OM_to_psl1 dev))
	((eq typ  OM_TYPE_COMMAND)    (OMgetCommand dev)
					 (OM_to_psl1 dev))
	%(eq typ  OM_TYPE_ERROR 9)
	((eq typ  OM_TYPE_ENDAPP 10)  (OMgetEndApp dev) 'OM_TYPE_ENDApp)
	((eq typ  OM_TYPE_ENDCOMMAND) (OMgetEndCommand dev)
					 'OM_TYPE_ENDCOMMAND)
	%(eq typ  OM_TYPE_ENDERROR 12)
       (t (error (list "read type from OM: " typ))))))

