val script = ref "test.sml"

fun merk f  =  if f <> "" then script := f ^ ".sml" else ()

val system = OS.Process.system
val isSuccess = OS.Process.isSuccess

fun edit fileName  =
(  system ("cp " ^ fileName ^ " @tmp");
   system ("vi " ^ fileName);
   if isSuccess (system ("cmp -s @tmp " ^ fileName)) then use fileName else ()
)

fun U f  =  ( merk f;  use  (!script) )

fun E f  =  ( merk f;  edit (!script) )

fun A ()  =  edit "all.sml"
