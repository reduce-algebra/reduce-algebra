%**********************************************************************
module crackpvm$
%**********************************************************************
%  Procedures to support parallel computing on PVM 
%  Authors: Thomas Wolf and Winfried Neun 2002, 2006

% BSDlicense: *****************************************************************
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

symbolic fluid '(loaddirectories!* loadextensions!* !*lower unixargs!* 
                 options!*)$                             % for crload()

!#if (memq 'csl lispsystem!*)
symbolic procedure pwd$ bldmsg("%w/",getenv "PWD")$
!#endif  

% symbolic fluid '(lock_)$
% lock_ := gtwarray 4$     % see /usr/include/sys/fnctl.h

% symbolic procedure mklockstruct(lock)$
% << wputv(lock,0,lshift (1,32)); % 64 bits
%    wputv(lock,1,0);
%    wputv(lock,2,lshift (512,32));
%    wputv(lock,3,0);
% >>$

% lisp mklockstruct(lock_)$

% symbolic procedure proczaehler0(file,action)$  % Winfried's version
% % 'file' is the counter file which must already exist.
% % 'action' = 'plus, 'minus or 'init (to set counter to 0)
% begin scalar fd,fl,zahl,chn;
%  if not filestatus(file,nil) then <<
%   write"file does not exist at START"$terpri()$fd:=termread()
%  >>$
%  wputv(lock_,0,lshift (1,32));         % f_unlck
%  fd := Linux_open (file,O_RDWR);
%  if (fd < 0) then error(4711," with_lock: File cannot be opened");
%  fl := fcntl(fd,7,lock_);              % 7 = F_SETLKW
%  if (fl < 0) then error(4711," with_lock: File cannot be locked");
%
%  chn := open(file,'input);
%  zahl := channelread(chn);
%  close chn;
%  chn := open("/tmp/outfile",'output);
%  if action='plus then  channelwriteinteger(chn,zahl+1);
%  if action='minus then channelwriteinteger(chn,zahl-1);
%  if action='init then  channelwriteinteger(chn,0);
%  close chn;
%  system bldmsg("cp /tmp/outfile %p" , file);
%
%  wputv(lock_,0,lshift (2,32)); % f_unlck
%  fl := fcntl(fd,6,lock_); % 7 = F_SETLK
%  if (fl < 0) then error(4711," with_lock: File cannot be unlocked");
%  fd := Linux_close fd;
%  if (fd < 0) then error(4711," with_lock: File cannot be closed");
%
% end$

symbolic procedure proczaehler(file,action)$  % Sergey's version
begin scalar fl,fpid,!*echo,semic!*;

 fpid := bldmsg("%s.%w",file,getpid());
 
 if action='init then backup_:=0
                 else <<
  fl:=1;
  repeat <<
   fl := system bldmsg ("mv %s %s",file,fpid)$
   if fl neq 0 then system"sleep 1"
  >> until fl=0;
  %we have successfully renamed the file
  semic!*:='!$;
  in fpid 
 >>$

 if (action neq 'init) and (not numberp backup_) then <<
  write"pwd = ",pwd()$terpri()$
  write"***** ERROR: file ",process_counter," does not contain a number: "$
  write backup_$terpri()$
  error(1000,"We stop now!")
 >>$
 if backup_<0 then <<
  write"pwd = ",pwd()$terpri()$
  write"***** ERROR: file ",process_counter," contains a number <0 : "$
  write backup_$terpri()$
  error(1001,"We stop now!")
 >>$
 out fpid;
 if action='plus  then write "lisp (backup_ := ",backup_+1,")$ end$";
 if action='minus then write "lisp (backup_ := ",backup_-1,")$ end$";
 if action='init  then write "lisp (backup_ := ",0,")$ end$";
 shut fpid;
 fl:=1;
 repeat <<
  fl := system bldmsg ("mv %s %s",fpid,file);
  if fl neq 0 then system"sleep 1"
 >> until fl=0;

end$

symbolic procedure ini_check_of_parallel_crack$
if paracrack_initialized then t else
begin scalar os$ 

 if reducerc_initialized neq 13112006 then return <<
  write"##### To run this parallelization, a certain file .reducerc has to be"$
  terpri()$
  write"##### placed in your home directory! This file comes with all crack"$
  terpri()$
  write"##### files. To see it under unix do:  ls -a  . If it is not in your"$
  terpri()$
  write"##### CRACK directory you can download it together with the latest"$
  terpri()$
  write"##### version of CRACK from ",crack_download_add,"crack.tar.gz "$
  terpri()$
  write"##### or as a single file ",crack_download_add,".reducerc "$
  terpri()$
  write"##### and afterwards copy it into your home directory and restart REDUCE."$
  terpri()$
  nil
 >>$

 % Check for unix
 if memq('linux     ,lispsystem!*) or 
    memq('unix      ,lispsystem!*) or 
    memq('linux!-gnu,lispsystem!*) then os := 'linux;
 if os neq 'linux then <<
  write"### WARNING:"$ terpri()$
  write"Currently only the operating system linux is supported."$
  write"Parallel execution on your ",os," system may not be possible."$terpri()$
 >>$

 % Create file process_counter for counting processes if it does not exist yet
 % and initialize to zero in that case.
 if not filep process_counter then proczaehler(process_counter,'init)$  

 % verify the end of each run?
 change_prompt_to ""$ 
 write"Shall each parallel process ask for verification at the end? (y/n) "$
 repeat os:=termread() until (os='y) or (os='n)$
 verify_end_of_parallel_run:=if os='y then t else nil$
 restore_interactive_prompt()$ 
 return (paracrack_initialized:=t)
end$

symbolic procedure pvm_activate$
if getd('pvm_mytid) then pvm_able:=t
                    else pvm_able:=nil$

symbolic procedure pvm_active$
if pvm_able then t else <<
 terpri()$write"PVM is either not active on this computer"$
 terpri()$write"or interactively switched off. Try 'vp'."$
 terpri()$
 nil
>>$

%symbolic procedure pvm_try$
%if pvm_able and (read_proczaehler()<max_proc_no) then t
%                                                 else nil$

symbolic procedure crload()$
% find the path from where crack.b was loaded
begin scalar found, u, ld, le;
 ld := loaddirectories!*;
 le := loadextensions!*;
 u  := 'crack;
 (while ld and not found do <<
   le := loadextensions!*;
   while le and not found do <<
    if filep (bldmsg("%w%w%w" ,first ld, u,car first le)) then
    found:= bldmsg("%w%w", first ld, u) % Found is function to apply
                                                          else
    le := rest le; 
   >>;
   ld := rest ld; 
  >>) where !*lower := t;
 return found
end$

symbolic procedure crack_load_cmd$
% Determines the path of the first load of CRACK. This is to be used in automatic
% further loads of CRACK in parallel computations
if null crack_load_command then 
begin scalar h,s,found$
 h:=options!*;
 while h and not found do <<
  s:=reverse explode car h;
  if (length s >  4) and (car s = 'l) and (cadr s = 'l) and (caddr s = 'a) and 
     (cadddr s = 'r) and (car cddddr s = 'c) then found:=t else 
  if (length s >  4) and (car s = 'k) and (cadr s = 'c) and (caddr s = 'a) and 
     (cadddr s = 'r) and (car cddddr s = 'c) then found:=t else
  if (length s >  4) and (car s = 'l) and (cadr s = 's) and (caddr s = 'p) and 
     (cadddr s = 'r) and (car cddddr s = 'c) then found:=t else
  if (length s >  4) and (car s = 'l) and (cadr s = 's) and (caddr s = 'c) and 
     (cadddr s = 'r) and (car cddddr s = 'c) 
  then found:=t 
  else h:=cdr h
 >>$
 crack_load_command:=
 if found and (length s > 4) then bldmsg("%w",car h)
                             else <<
  %write"##### REQUIRED INPUT: #####"$terpri()$
  write"The directory from where the package CRACK was loaded can not be found."$terpri()$
  write"Reasons can be that"$terpri()$
  write"- a file ~./reducerc is missing which should initialize the variable options!*"$terpri()$
  write"- CSL-Reduce is running and when starting Reduce the file .reducerc does not"$terpri()$
  write"  initialize the variable options!*,"$terpri()$
  write"- CRACK was not loaded with one of the files crack.b, crpsl.b, crcsl.b, crall.b ."$terpri()$
  write"To continue, please enter the loading command of CRACK, "$terpri()$
  write"for example, ""~/red/src6/crall""  : "$
  change_prompt_to " "$  
  h:=termread()$
  restore_interactive_prompt()$ 
  bldmsg("%w",h)
 >>
end$

symbolic procedure reduce_call_cmd$
% Determines the path of the first load of CRACK. This is to be used in automatic
% further loads of CRACK in parallel computations
if null reduce_call then <<

!#if (memq 'psl lispsystem!*)
  % comment:   unixargs!*;   looks like:
  % ["/usr/local/reduce37d/lisp/psl/linux/psl/bpsl" "-td" "22000000" "-f" 
  %  "/usr/local/reduce37d/lisp/psl/linux/red/reduce.img"]

  if null unixargs!* or (size unixargs!* < 4) then <<
   write"The variable unixargs!* has less than 5 arguments:"$terpri()$
   write"unixargs!* = ",unixargs!*$ terpri()$
   write"and does therefore not specify properly the command"$terpri()$
   write"with which this session was invoked."$terpri()$
  >>                                          else <<
   reduce_call:=""$
   for n:=0:4 do setq(reduce_call,bldmsg("%w %w",reduce_call,getv(unixargs!*,n)))
  >>$
!#endif  

  if null reduce_call then <<
    write"For calling REDUCE the program needs to know the calling command."$terpri()$
    write"Please input this call. Examples:"$terpri()$terpri()$

    write"PSL-REDUCE on Eee: "$terpri()$
    write"""/home/thomas/reduce-algebra/trunk/scripts/../pslbuild/i686-unknown-ubuntu10.04/psl/bpsl -td 16000000 -f /home/thomas/reduce-algebra/trunk/scripts/../pslbuild/i686-unknown-ubuntu10.04/red/reduce.img"""$terpri()$terpri()$

    write"CSL-REDUCE on Eee: "$terpri()$
    write"""/home/thomas/reduce-algebra/trunk/bin/redcsl -w -i /home/thomas/reduce-algebra/trunk/cslbuild/i686-unknown-ubuntu10.04-nogui/csl/reduce.img -o /home/thomas/red/src6/cr32.img"""$terpri()$terpri()$

    write"PSL-REDUCE on sente: "$terpri()$
    write"""/homes/reduce/reduce-algebra/trunk/bin/redpsl -td 200"""$terpri()$terpri()$

    write"CSL-REDUCE on sente: "$terpri()$
    write"""/homes/reduce/reduce-algebra/trunk/bin/redcsl -w -i /homes/reduce/reduce-algebra/trunk/cslbuild/i686-unknown-suse11.4/csl/reduce.img -o ~/red/src6/cr32.img"""$terpri()$terpri()$

    write"CSL-REDUCE on lie: "$terpri()$
    write"""/homes/reduce/reduce-algebra/trunk/bin/redcsl -w -i /homes/reduce/reduce-algebra/trunk/cslbuild/x86_64-unknown-rh6.3-nogui/csl/reduce.img -o ~/red/src6/cr64.img"""$terpri()$terpri()$

    change_prompt_to ""$
    reduce_call:=termread()$
    restore_interactive_prompt()$
    reduce_call:=bldmsg("%w",reduce_call)$
  >>
>>$

% symbolic procedure inc_session$
% begin scalar sess$
%  setq(sess,bldmsg("%w%w",session_,"processes"));
%  lock sess;
%  in sess;
%  backup_:=add1 backup_;
%  out sess;
%  write "off echo$backup_:=",backup_,"$ end$"$
%  terpri()$
%  shut sess;
%  unlock sess;
% end$

symbolic procedure read_proczaehler$
begin scalar fl,fpid,!*echo,semic!*;
 fpid := bldmsg("%s.%w",process_counter,getpid());
 fl:=1;
 repeat << 
  fl := system bldmsg ("cp %s %s",process_counter,fpid);
  if fl neq 0 then system"sleep 1"
 >> until fl=0;
 
% while not fd do <<
%  fd := filestatus(process_counter,nil);
%  if not fd then sleep 1
%  else << fl := system bldmsg ("cp %s %s",process_counter,fpid);
%	  fd := if fl = 0 then t else nil; 
%	  if fd then fd := filestatus(fpid,nil);
%       >>
% >>;

% zaef:=open(fpid,'input);
% zae:=channelread(zaef);
% close(zaef);

 semic!*:='!$;in fpid$

 system bldmsg ("rm %s",fpid);
 if not fixp backup_ then backup_:=1000000$
 return backup_
end$

% fluid '(backup_)$

%symbolic procedure install_pass_on(x,y,z);
%begin scalar !*comp;   putd(x,y,z); end$
%
%lisp install_pass_on( 'pass_on_switches, 'expr,
%     '(lambda (!*!*s!*!*) (mapobl (function (lambda
%(x) (cond ((flagp x (quote switch)) ((lambda (xx) (progn
%(setq xx (intern (compress (append (explode (quote !*))
%(explode x))))) (cond ((boundp xx) (remote_call!* !*!*s!*!*
%(quote onoff) (list x (eval xx)) 0))))) 0))))))))$

%symbolic procedure pass_on_switches(backup_)$
%mapobl function(lambda(x);
%if flagp(x,'switch) then
%  << xx := intern compress append(explode '!*,explode x);
%     if boundp xx then
%         remote_call!*(backup_,'onoff,{x,eval xx},0) >> where xx :=0)$

%symbolic procedure pass_on_switches$
% mapobl function(lambda(x);
% if flagp(x,'switch) then
%    << xx := intern compress append(explode '!*,explode x);
%       if boundp xx then
%           remote_call!*(backup_,'onoff,{x,eval xx},0) >> where xx :=0)$

%symbolic procedure pass_on_switches(s)$
%begin
% mapobl function(lambda(x);
% if flagp(x,'switch) then
%    << xx := intern compress append(explode '!*,explode x);
%       if boundp xx then
%           remote_call!*(s,'onoff,{x,eval xx},0) >> where xx :=0)$
%end$

symbolic procedure add_session(pdes,forg,para_mode)$
% symbolic fluid variables that matter: !*iconic, inter_para_mode
begin scalar s,ss,h,current_dir,startup,p,id$   % ,crpath$

 %----- generating the file name of current data
 ss:=level_string(session_)$
 current_dir:=if para_case_dir neq "" then para_case_dir
                                      else pwd()$
 setq(h,bldmsg("%w%w%w",current_dir,ss,"tmp"));
 % In the new process the input file is not opened, so eqn_input
 % should there be nil:
 s:=eqn_input$ 
 if eqn_input='done then <<equations_file:="";eqn_no:=0>>$ 
 % otherwise the new process will try to start reading the file 
 % equations_file until equation eqn_no but this file should not 
 % be read and does even not exist anymore
 eqn_input:=nil$  

 %----- prepare crack load command (before backup_to_file() 
 %      to pass on crack_load_command
 crack_load_cmd()$ % assigning crack_load_command if not already done
 if crack_load_command="not found" then return <<
  shut startup$ 
  s:=bldmsg("rm %w",startup)$
  system s$
  write"##### This parallelization could not be started as the call of crack"$
  terpri()$
  write"##### could not be found. Please have at the start of your computation"$
  terpri()$
  write"##### a line     load ""path/crack""$         with suitable path, if"$
  terpri()$
  write"##### necessary  load ""./crack""$ when loaded from active directory."$
  terpri()$
  nil   
 >>$

 reduce_call_cmd()$

 backup_to_file(pdes,forg,h);
 eqn_input:=s$
 %!*iconic:=nil$  %t;  %not !*batch_mode;
 % =t --> only an icon opens, =nil --> a window opens
 
 %----- prepare startup file name
 setq(startup,bldmsg("%w%w%w",current_dir,ss,"sup"));

 %----- prepare startup file
 out startup$ 
 write"lisp$"$    terpri()$
% write"off int$"$ terpri()$
 %----- if started under screen then check whether environment 
 %      variable reduce is assigned
 if nil then
 if para_mode=2 then <<
  write"if null getenv ""reduce"" then <<"$  terpri()$
  write" write""##### To start REDUCE automatically in a new screen window""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write" write""##### the environment variable   reduce   must be assigned""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write" write""##### the name of the REDUCE directory. For a bash shell this""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write" write""##### could be done by adding once a line like""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write" write""##### export reduce=/home/twolf/newreduce""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write" write""##### For a c shell the line would be like this""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write" write""##### setenv reduce /home/twolf/newreduce""$"$ terpri()$
  write" terpri()$"$  terpri()$
  write">>$"$         terpri()$
 >>$
 %----- print the new level
 write"write"" Session-level: ",ss," ""$terpri()$"$        terpri()$
 %----- change directory
% write "cd """,current_dir,"""$"$                          terpri()$
 %----- if necessary, switch off int (when reading equations from a file)
 if null !*int then <<write"off int$"$                     terpri()>>$
 if      !*gc  then <<write"on gc$"$                       terpri()>>$
 %----- load Crack
 write"load_package """,crack_load_command,""" $"$          terpri()$
%write"load debug$"$   terpri()$ 
 %----- read in a file setting up the problem
 if crack_ini_file then <<
  % write"err_catch_readin(""",crack_ini_file,""",algebraic)$"$terpri()$
  write"load """,crack_ini_file,"""$"$                      terpri()$
 >>$
 %----- specify what crack should load (and do)
 p:=linelength(500)$ % so that filenames are printed on one line
 write"old_history:='(rb "$terpri()$
 if !*batch_mode then write"""",h,""")$"
                 else write"""",h,""" s)$"$terpri()$
 linelength(p)$
 write"off batch_mode$"$                                    terpri()$
 %----- start Crack
 write"crackshell()$"$                                      terpri()$
 %----- decrement the number of generated processes
 write"proczaehler(""",process_counter,""",'minus)$"$       terpri()$
 if % null !*iconic 
    verify_end_of_parallel_run then << % ask whether computation was ok.
  write"write""Is the computation ok and can the input files be deleted?""$"$ 
  terpri()$
  write"terpri()$"$terpri()$
  write"write""Please input Y/N : ""$"$                     terpri()$
  write"change_prompt_to """"$"$                            terpri()$ 

  write"if 'y=termread() then <<"$ terpri()$
  %----- remove the data file showing that the computation is completed
  write"  system ""rm ",h,"""$"$                            terpri()$
  write"  system ""rm ",startup,"""$"$                      terpri()$
  write">> else <<"$terpri()$
  write"  write""Files ",h,", ",startup," will not be deleted.""$"$ terpri()$
  write"  system""sleep 5""$ "$                             terpri()$
  write">>$"$
 >>               else <<
  %----- remove the data file showing that the computation is completed
  write"system ""rm ",h,"""$"$                              terpri()$
  write"system ""rm ",startup,"""$"$                        terpri()$
 >>$
 %----- close the REDUCE session when crackshell() finished
 write"eval '(bye)$"$                                       terpri()$
 write"end$"$                                               terpri()$
 shut startup$

 %----- start new process
 if para_mode=1 then 
 if !*iconic then setq(s,bldmsg("cd %w;xterm -iconic -e ""%w -d pre_read_=%w"" &",current_dir,reduce_call,startup)) 
             else setq(s,bldmsg("cd %w;xterm -e ""%w -d pre_read_=%w"" &",current_dir,reduce_call,startup)) 
                else 
 if para_mode=2 then setq(s,bldmsg("screen -h 10000 %w -d pre_read_=%w",reduce_call,startup)) else 
                                           % scroll back ability of 10000 lines
 if para_mode=3 then setq(s,bldmsg("sqsub -o %w%wout -e %w%werr -t %w -d pre_read_=%w",
                                   current_dir,ss,current_dir,ss,reduce_call,startup));

 % -t for test queue, 
 % -o %w%wout specfies output-message-file, 
 % -e %w%werr specfies error-message-file
 % -q twolf for twolf queue

 % if the *out files get too large and if errors are not produced by REDUCE if it crashes
 % then if para_mode=3 then    
 %   bldmsg("tail -n 200 %w%wout > %w%wtail",current_dir,ss,current_dir,ss) 
 %   bldmsg("rm %w%wout",current_dir,ss) 

 %----- increment the counter of reduce processes
 proczaehler(process_counter,'plus)$

 if para_mode=3 then <<
  p := pipe!-open(s,'input);
  id:=""$
  repeat <<
   h:=channelreadchar(p);
   if (h>47) and (h<58) then id:=bldmsg("%w%w",id,int2id h)
  >> until h=4;
  close p;
  % write"process id=",id$terpri()$
 >>             else system s$  %##### collecting process id for xterm, screen ?

 %----- print the new level
 write" A process for case ",ss," has been started."$
 terpri()$

% return ###### process ID

end$

symbolic procedure add_process(processes,pdes,forg)$
% symbolic fluid variables that matter: !*iconic
begin scalar s,ss,h,current_dir$
 %----- start PVM if it is not already started
 system"pvm"$

 %----- passing on the current status
 ss:=level_string(session_)$
 current_dir:=if para_case_dir neq "" then para_case_dir
                                      else pwd()$
 setq(h,bldmsg("%w%w%w",current_dir,ss,"tmp"));
 % In the new proxess the input file is not opened, so eqn_input
 % should there be nil.
 s:=eqn_input$ eqn_input:=nil$
 backup_to_file(pdes,forg,h);
 eqn_input:=s$
 %!*iconic:=nil$  %t;  %not !*batch_mode;
 % =t --> only an icon opens, =nil --> a window opens

 %----- start new process
 s:=remote_process("");
 processes:=cons(s,processes);

 %----- update the counting of processes
 % system "/home/twolf/proczaehler plus"$
 proczaehler(process_counter,'plus)$

 %----- print the new level
 remote_write(s,{'list,"Process id: ",s," level: ",ss});
 terpri()$write"A process with id no ",s," has been started."$

 %----- change directory
 remote_call!*(s,'cd,{current_dir},0)$

 %----- if necessary, switch off int (when reading equations from a file)
 if null !*int then remote_call!*(s, 'onoff,{'int,nil},0);
 if !*gc then remote_call!*(s, 'onoff,{'gc,t},0);

 %----- load crack
 crack_load_cmd()$
 if crack_load_command="not found" then return <<
  write"##### This parallelization could not be started as the call of crack"$
  terpri()$
  write"##### could not be found. Please have at the start of your computation"$
  terpri()$
  write"##### a line     load ""path/crack""$         with suitable path, if"$
  terpri()$
  write"##### necessary  load ""./crack""$ when loaded from active directory."$
  terpri()$
  remote_call!*(s,'exitlisp,{'list},0)$
  nil
 >>$
 remote_call!*(s,'load_package,{{crack_load_command}},0)$

 %----- read in a file setting up the problem
 if crack_ini_file then 
 remote_call!*(s,'err_catch_readin,{crack_ini_file,'algebraic},0)$

 %----- copy all switch settings
% backup_:=s$
% pass_on_switches(backup_)$

% mapobl function(lambda(x);
% if flagp(x,'switch) then
%    << xx := intern compress append(explode '!*,explode x);
%       if boundp xx then
%           remote_call!*(s,'onoff,{x,eval xx},0) >> where xx :=0)$

 %----- specify what crack should load (and do)
 remote_call!*(s,'set,{'old_history,{'rb,h}},0);

 %----- start Crack
 remote_call(s,'crackshell,{'list},0)$

 %----- if interactive then not instant closure of window
 %----- when computation is finished to inspect the result
 %----- so wait for 1000 sec.
 if null !*iconic then remote_call!*(s,'system,{"sleep 1000"},0);

 %----- close the REDUCE session when crackshell() finished
 % remote_call!*(s,'system,{"/home/twolf/proczaehler minus"},0)$
 proczaehler(process_counter,'minus)$

%lisp<<if not pairp

 remote_call!*(s,'system,{bldmsg("%w%w","rm ",h)},0)$

% for debugging:
%if null !*iconic then remote_call!*(s,'system,{"sleep 1000"},0);

 remote_call!*(s,'exitlisp,{'list},0)$ % or remote_call!*(s,'exitlisp,{},0)$ (?)

 return processes
end$

symbolic procedure drop_process(processes)$
begin scalar s$
  terpri()$write"The following processes had been activated in this order: "$
  listprint(reverse processes)$
  terpri()$write"To kill ALL remote processes that have been"$
  terpri()$write"generated by this process enter -1,"$
  terpri()$write"to kill a single process enter its process id: "$
  change_prompt_to ""$ 
  s:=termread()$
  restore_interactive_prompt()$
  if s=-1 then <<
    processes:=nil;
    % system "/home/twolf/proczaehler init"
    proczaehler(process_counter,'init)$
  >>      else <<
    processes:=delete(s,processes);
    % system "/home/twolf/proczaehler minus"
    proczaehler(process_counter,'minus)$
  >>$
  remote_kill(s);
  return processes
end$

%symbolic procedure remote_crackmain(pdes,forg)$
symbolic procedure crackmain_if_possible_remote(pdes,forg)$

if collect_sol or
   null auto_para_mode or
   (read_proczaehler() geq max_proc_no) then <<
 if collect_sol and auto_para_mode then <<
   write"Currently is collect_sol=t. Therefore parallel case"$terpri()$
   write"solving is not enabled because solutions would not"$terpri()$
   write"be collected even though auto_para_mode<>nil."$terpri()$
   write"Therefore, either set collect_sol to nil using"$terpri()$
   write"'as {collect_sol,nil};' or disable parallelism with 'dp' ."$
   terpri()$
 >>;
 if null batch_mode_sub then !*batch_mode:=nil$ 
 crackmain(pdes,forg) 
>>                                      else
begin scalar processes,s;

 % Feature: As currently nothing is passed back, variables
 % in pass_back, like history_ or size_hist or sol_list
 % have a limited meaning in the mother process.

 if null batch_mode_sub then !*batch_mode:=nil$ 
 if auto_para_mode<4 then add_session(pdes,forg,auto_para_mode)        % non-PVM
                     else processes:=add_process(processes,pdes,forg)$ % PVM
 %----- changes done at the end of crackmain(), e.g. delete property lists
 finish_level(0)$ % 0 solutions as # of solutions is unknown
 drop_all_pdes(pdes)$
 for each s in forg do
 if pairp s then setprop(cadr s,nil)
            else setprop(     s,nil)$
end$

endmodule$

end$

tr proczaehler
tr ini_check_of_parallel_crack
tr pvm_activate
tr pvm_active
tr crload
tr crack_load_cmd
tr read_proczaehler
tr add_session
tr add_process
tr drop_process
tr crackmain_if_possible_remote
