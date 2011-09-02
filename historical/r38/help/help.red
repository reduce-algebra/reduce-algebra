module help;  % REDUCE help system entry for PSL based REDUCE.
 
  % Author: Herbert Melenk   February 1993

  % This code is highly system dependent

exports '(help);

compiletime flag('(help help1),'lose);   

%------------------------------ DOS part ----------------------------

compiletime if 'dos member lispsystem!* then remflag('(help),'lose);

compiletime fluid '!*!*windows;

%  (compiletime (load include))
%  (compiletime (include "C:/psl/kernel/dos386/windows/psllcall.h"))

compiletime define!-constant(win!-help,23);
compiletime global '(win!-help);


symbolic procedure help!-show(file,topic);
   if !*!*windows=1 then
     << 
      if topic then 
	psll!-call(1,strbase strinf bldmsg("%w",topic),0,win!-help)
	  else
	psll!-call(0,0,0,win!-help);
     >>  
       else
    begin   
      if not filep cdr file then
	rederr bldmsg("help data file >%w< not found",file);
      if car file neq 'H then return help!-browse cdr file;
      file := cdr file;
      system bldmsg("%w\help\help -f %w %w",
		     getenv "reduce",file, topic or " ");
    end;

symbolic procedure help!-browse file;
   system bldmsg("type %w |more ",file);

compiletime flag('(help!-show help!-browse),'lose);

%------------------ UNIX part ---------------------------------------

compiletime if 'unix member lispsystem!* then 
       remflag('(help!-show help1),'lose);

compiletime global '(help_command);
compiletime flag('(help1),'internalentry);

symbolic procedure help!-show(file,topic);
  begin scalar x;
     if not filep cdr file then
	rederr bldmsg("help data file >%w< not found",file);
     if car file neq 'H then return help!-browse cdr file;
     file := cdr file;
     x:= topic or " ";
     if not stringp help_command then
       begin scalar !*mode; 
	  !*mode := 'symbolic;
	  errorset('(infile "$reduce/redhelp.rc"),nil,nil); 
	  errorset('(infile "$HOME/redhelp.rc"),nil,nil); 
	  errorset('(infile "redhelp.rc"),nil,nil); 
       end;
     if stringp help_command then
       return <<system bldmsg("%w %w %w",help_command,file,x);>>;
	     % Try to find help server.   
     help1(help_command := "xinfo -file ",file,x)
      or
     help1(help_command := "info -f ",file,x)
      or
     help1(help_command := 
	   "$reduce/help/help -f ",file,x)
      or
     rederr "don't know how to start help support";
  end;

symbolic procedure help1(c,f,x); 0=system bldmsg("%w %w %w",f,c,x);

symbolic procedure help!-browse file;
   system bldmsg("more %w",file);

compiletime flag('(help!-show help1),'lose);

%------------------ COMMON part -------------------------------------

% transform the package information

fluid '(help!-packages!*);

symbolic procedure help!-mkfile u;
    bldmsg("%w/%w",getenv "reduce",u);

symbolic procedure help!-files();
   begin scalar file,type,of;
     file := open(help!-mkfile "help/helpdir.info",'input);
     of := rds file;
     while (type:=read()) neq !$eof!$ do
     << read();   %% don't need package name  
       help!-packages!*:=
	  (read () . type . help!-mkfile read()) .
	    help!-packages!*;
     >>;
     rds of;
     close file;
   end;
     
symbolic procedure help u;
  begin scalar file,topic,package,w;
   if null help!-packages!* then help!-files();
   if null car u then u:=nil;
   for each x in u do 
    if (w:=assoc(x,help!-packages!*)) then 
     <<file:=cdr w;package:=x>>;
   if package then u:=delete(package,u)
     else <<w:=assoc(package:='redref,help!-packages!*);
	    if w then file:=cdr w>>;
   if u then topic := car u;
   if null file then rederr "cannot localize help file";
   help!-show(file,topic)
  end;

% define as REDUCE statement

if getd ' help then
<< put('help,'stat,'rlis); flag('(help),'go)>>;

endmodule;

end;

