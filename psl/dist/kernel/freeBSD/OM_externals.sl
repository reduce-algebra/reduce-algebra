%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:EXTERNALS.SL
% Description:  Definitions of OpenMath foreign language functions
% Author:       Winfried Neun, ZIB , taken from Stephane Dalmas' C binding
% Created:      1-Nov-97
% Mode:         Lisp
% Package:      
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
(off r2i)

%%(external-function !O!Mmake!Context  (name))   
%%(external-function !O!Mnamed!Context  (context))   
%%(external-function !O!Mcontext!Name  (context))   
%%(external-function !O!Mmake!Symbol  (context name))   
%%(external-function !O!Msymbol!Context  (symbol))   
%%(external-function !O!Msymbol!Name   (name))   

(external-function !O!Mmake!Device   (ii !O!MIO))
(external-function !O!Mclose!Device   (!O!MIO))

(external-function !O!Mget!Device!Encoding (dev))
(external-function !O!Mset!Device!Encoding (dev encoding))

(external-function !O!Mmake!I!O!File (file))
(external-function !O!Mmake!I!O!Fd    (fd))

(external-function !O!Mmake!Conn (n))
(external-function !O!Mconn!In (conn))
(external-function !O!Mconn!Out(conn))

%% (external-function !O!Mdevice!Fd (dev))

(external-function !O!Mconn!T!C!P     (conn machine port))
(external-function !O!Mconn!Unix      (conn file))
(external-function !O!Mbind!T!C!P     (conn port))
(external-function !O!Mbind!Unix      (conn file))

(external-function !O!M!launch!Env (conn machine command env))
(external-function !O!M!launch (conn machine command ))
(external-function !O!M!serve!Client  (conn ))
(external-function !O!Mconn!Close (conn))

(external-function !O!Mput!Int32 (dev n))
(external-function !O!Mput!Big!Int (dev str len sign format))
(external-function !O!Mput!Float64 (dev f))
(external-function !O!Mput!Byte!Array (dev str len))
(external-function !O!Mput!String (dev str))
(external-function !O!Mput!Var (dev name))
(external-function !O!Mput!Symbol (dev cd symb))
(external-function !O!Mput!String!N (dev str len))
(external-function !O!Mput!Var!N (dev name len))
(external-function !O!Mput!Symbol!N (dev cd cdlen name nlen))
(external-function !O!Mput!App (dev))
(external-function !O!Mput!End!App (dev))
(external-function !O!Mput!Attr (dev))
(external-function !O!Mput!End!Attr (dev))
(external-function !O!Mput!Atp (dev))
(external-function !O!Mput!End!Atp (dev))
(external-function !O!Mput!Error (dev))
(external-function !O!Mput!End!Error (dev))

(external-function !O!Mput!Object (dev))
(external-function !O!Mput!End!Object (dev))

(external-function !O!Mget!Object (dev))
(external-function !O!Mget!End!Object (dev))

(external-function !O!Mget!Length (dev len))
(external-function !O!Mget!Symbol!Length (dev clen nlen))

(external-function !O!Mget!Type (dev typ))

(external-function !O!Mget!Int32 (dev buf))
(external-function !O!Mget!Big!Int (dev str len sign format))
(external-function !O!Mget!Big!Int!N (dev str len sign format))
(external-function !O!Mget!Float64 (dev buff))
(external-function !O!Mget!Byte!Array (dev str len))
(external-function !O!Mget!Byte!Array!N (dev str len))
(external-function !O!Mget!String (dev str))
(external-function !O!Mget!String!N (dev str len))
(external-function !O!Mget!Var (dev str ))
(external-function !O!Mget!Var!N (dev str len))
(external-function !O!Mget!Symbol (dev cd name ))
(external-function !O!Mget!Symbol!N (dev cd cdlen name namelen))
(external-function !O!Mget!App (dev))
(external-function !O!Mget!End!App (dev))
(external-function !O!Mget!Attr (dev))
(external-function !O!Mget!End!Attr (dev))
(external-function !O!Mget!Atp (dev))
(external-function !O!Mget!End!Atp (dev))
(external-function !O!Mget!Error (dev))
(external-function !O!Mget!End!Error (dev))


(external-function !O!Mput!Comment (dev comment))
(external-function !O!Mget!Comment (dev comment))
(external-function !O!Mput!Comment!N (dev comment len))
(external-function !O!Mget!Comment!N (dev comment len))

(external-function !O!Mbegin!Object (dev))
(external-function !O!Mend!Object (dev))

(external-function !O!Mset!Verbosity!Level (level))

(external-function !O!Mignore!Comment (dev set))

(on r2i)

