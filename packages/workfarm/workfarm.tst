% A simple workfarm intended to show how one can be set up and used.

lisp;
on echo,time;
% Note that the Reduce "on time" facility only measures time in the
% main process, so it does not report based on what goes on in the
% forked work. So here I provide something that reports on elapsed time.

% The CSL function timeofday() returns a pair of (second . microsoconds)
% since 1 January 1970. Here I turn that into just incremental milliseconds.

fluid '(basetime);
basetime := timeofday()$
basetime := (1000000*car basetime + cdr basetime)/1000$

symbolic procedure elapsed();
  begin
    scalar tt := timeofday();
    return (1000000*car tt + cdr tt)/1000 - basetime
  end;

% Here is a function where its sole purpose is to be busy for a while.
% I want tha various tasks to use amounts of time that do not
% increase directly with k so that they will terminated in
% an "interesting" order, so the calculation mod 41 is a crude scheme
% for scrambling how much work is done when an argument k=1,2,... is
% provided. 

symbolic procedure work k;
  begin
    scalar r := 0, n := remainder(314159*k, 41);
    for i := 1:30000*n+k do r := r + expt(i, 5);
    return list(k, r)
  end;

% Now to create a new task and start it off doing some work with
% input k....

symbolic procedure startwork k;
  begin
    scalar task := open!-fork();           % Create a "fork".
    send!-to!-fork(task, list('work, k));  % Send it a request.
    return task                            % Return its handle.
  end;

% I may like to know how many CPUs I have. I will set myself a target
% of completing 50 instances of the work-packet.

fluid '(count started wanted);
count := cpu!-count();
started := 0;
wanted := 50;


% Create a number of tasks related to the number of available CPUs

fluid '(tasks);
tasks := for i := 1:count collect startwork(started := started+1)$

% Report how long the initial task creation process took.
list("tasks started at ", elapsed());

% Most likely here none of the tasks will be ready. But display that
% info to show that I can. The list here will have t for any task that
% has completed and nil for one that has not.

for each v in tasks collect fork!-ready v;

% Scan the list of tasks to see if any have completed. Return nil
% if all are still hard at work or otherwise a handle for one that
% has a result ready for me.

symbolic procedure find!-ready tasks;
  if null tasks then nil
  else if fork!-ready car tasks then car tasks
  else find!-ready cdr tasks; 

% Building on the above find a ready task. If one is not yet available
% wait 5ms and try again. My choice of 5ms is based on a HOPE that
% the busy-waiting it amounts to will not consume too many resources while
% the latency it potentially adds will not be orders of magnitude worse than
% the latencies inherent in the communication and synchromization that has
% to go on anyway. It probably ought to be a time keyed to the performance
% of the system I am running on. 
%
% I arrange that if at any time I have to wait for some long time (specified
% by longstop!-time) I give up.

fluid '(longstop!-time);
longstop!-time := 10000; % 10 seconds

symbolic procedure get!-ready tasks;
  begin
    scalar selected := nil, waiting := 0;
    while null (selected := find!-ready tasks) do <<
      sleep 5;
      waiting := waiting + 5;
      if waiting > longstop!-time then <<
        for each v in tasks do close!-fork v;  % Kill all tasks!
        error(1, "exceeded longstop-time") >> >>;
    return selected
  end;

fluid '(result_count);
result_count := 0;

while tasks do
  begin
    scalar selected, r;
% Find a task that has completed, busy-waiting (well polling every 5ms)
% until there is one. 
    selected := get!-ready tasks;
% Retrieve the result from the selected task and then terminate it.
    r := get!-from!-fork selected;
    optterpri();
    princ "task done at ";
    prin elapsed();
    princ "  result is ";
    print r;
% When a task completes I checl if there is more to do. If so I send the
% next work-packet to the fork that just finished and make that the last
% item in the list of tasks so that I will check all others for completion
% before it. If I do not have any more to do I will just close down the
% fork that just finished.
    tasks := delete(selected, tasks);
% The first few times I find somehing that has finished I will display
% information about which others (if any) are done.
    if tasks and (result_count := result_count+1) < 4 then <<
      princ "Completion state:";
      for each v in tasks do <<
        princ " ";
        prin fork!-ready v >>;
      terpri() >>;
    if started < wanted then <<
      send!-to!-fork(selected, list('work, started := started+1));
      tasks := append(tasks, list selected) >>
    else close!-fork selected;
  end;

list("all done at", elapsed());

quit;
