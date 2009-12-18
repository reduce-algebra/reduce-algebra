lisp; % praeludium

input!-case nil;
on comp;

smacro procedure sstrbase (x); wor( x + 4, lshift(1,27)); 

module xbegin1;

define!-constant(TCL_TRACE_WRITES,32);

procedure xbegin1();
   begin scalar interp;
      interp := Tcl_CreateInterp();
      Tcl_Init interp;
      Tk_Init interp;
      prin2t "Nach Initialisierung";
      CreateFrontend interp;
      prin2t "Vor MainLoop";
      Tcl_TraceVar(interp,sstrbase strinf "commandflag",TCL_TRACE_WRITES,
		sstrbase( (inf cdr getd 'ProcessCommand)-4),0); %HACK!!
      Tk_MainLoop();
      prin2t "Nach MainLoop";
      Tcl_DeleteInterp interp
   end;

procedure CreateFrontend(interp);
   Tcl_Eval(interp,sstrbase strinf "
frame .input -relief raised
entry .entry -width 64 -textvariable command -background white
bind .entry <Return> {
   set commandflag 1
   .text insert end ""$commandout\n""
   .text yview end
   .entry delete 0 end
}
pack .entry -side left -fill x -in .input -padx 1m -pady 1m
frame .output
text .text -bd 2 -yscrollcommand "".scroll set"" -background white
scrollbar .scroll -command "".text yview""
pack .text .scroll -side left -fill y -in .output -padx 1m
pack .input .output");

lap '((!*entry ProcessCommand expr 0) % a callback procedure from C!!
	(push (reg ebp))
	(!*move (displacement (reg st) 8) (reg 1))
	(!*move (displacement (reg st) 12) (reg 2))
	(!*move (displacement (reg st) 16) (reg 3))
	(!*move (displacement (reg st) 20) (reg 4))
	(!*move (displacement (reg st) 24) (reg 5))
	(!*link ProcessCommand_lisp expr 5)
	(pop (reg ebp))
	(ret));

fluid '(tclinputbuffer!* globinterp);

procedure ProcessCommand_lisp(dummy,interp,n1,n2,flags);
   begin scalar command,xr;
      command := Tcl_GetVar(interp,sstrbase strinf "command",255);
      command := importforeignstring command;
      wputv(unixstring2(tclinputbuffer!*),0,wgetv(unixstring2(command),0));
      copystringtofrom(tclinputbuffer!*,command);

 %%Tcl_SetVar(interp,sstrbase strinf "commandout", sstrbase strinf "->", 255);
      prin2t command;
      print (xr :=  xread(t));
globinterp := interp;
globliste := nil;
      mathprint (xr := aeval(xr));
 foreach ll in reverse globliste do
  if not (ll = "") then  
 Tcl_SetVar(interp,sstrbase strinf "commandout", sstrbase strinf ll, 255);
globinterp:= nil;
print globliste;
     return 0;
    end;

endmodule;
end;

load helferlein; in "$pxk/test.red"; algebraic;
 << lisp load "lap/tcl-sys-io"; lisp xbegin1()>>;
