% A simple workfarm intended to show how one can be set up and used.

% This sets up a "farm" of processes, where the number created should
% be equal to the number of cores on the CPU being used. If that
% number is N then an initial N tasks are distrubuted across them.

% From there on the system repeatredly waits until the next task
% deliveres a result. If there is more work to be done the next
% packet is send to the CPU that just became idle. Towards the end
% when each task ends the process it had been uding is killed.

% I report timestamps for each event so that it is (perhaps) possible
% to see that calculation are are happening in parallel and perhaps
% possible to get some feeling for overheads.

lisp;
on echo;
% Note that the Reduce "on time" facility can only measures time in the
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
% provided. In any real case this will get replaced by code to something
% useful!

symbolic procedure work k;
  begin
    scalar r := 0, n := remainder(314159*k, 41);
    for i := 1:30000*n+k do r := r + expt(i, 5);
    return list(k, " => ", r)
  end;

% Now to create a new task and start it off doing some work with
% input k....

symbolic procedure startwork k;
  begin
    scalar task := open!-fork();           % Create a "fork".
    send!-to!-fork(task, list('work, k));  % Send it a request.
    princ "==== start work on "; print k;
    return task                            % Return its handle.
  end;

% I may like to know how many CPUs I have. I will set myself a target
% of completing 50 instances of the work-packet.

fluid '(count started wanted);
count := cpu!-count();
if count < 4 then count := 4;   % Try this even if not much point
                                % since this is a DEMO.
started := 0;
wanted := 50;


% Create a number of tasks related to the number of available CPUs
% As I crewate them I set them tasks to start working on. I could
% of course merely create them and seed them with work in a separate
% step if that suited me better.

fluid '(tasks);
tasks := for i := 1:count collect startwork(started := started+1)$

% Report how long the initial task creation process took.
list("tasks started at ", elapsed());

<< princ "task list: "; print tasks >>$

% Most likely here none of the tasks will be ready. But display that
% info to show that I can. The list here will have t for any task that
% has completed and nil for one that has not. Since I am doing this very
% soon after creating the tasks I expect all to say that they are not
% yet complete - so this is mostly to illustrate how to ask the question.

for each v in tasks collect first!-fork(list v, 0);

fluid '(longstop!-time);
longstop!-time := 30000; % 30 seconds

fluid '(result_count);
result_count := 0;       % To make the log file easier to track through.

while tasks do
  begin
    scalar selected, r, tt;
% Find the first task that completes, waiting until there is one. 
    selected := first!-fork(tasks, longstop!-time);
% If first-fork() returned nil that would mean it had timed out without
% observing a ready task - in that situation I will give up.
    if null selected then <<
      for each v in tasks do close!-fork v;
      error(0, "task timed out") >>;
% Retrieve the result from the selected task. Display when it finished and
% its result. And also how long it too between first!-fork() identifying
% and the result being available for use.
    princ "About to try to get from fork "; print selected;
    tt := elapsed();
    r := get!-from!-fork selected;
    tt := elapsed() - tt;
% Because first!-fork() should have identified a task that has results
% ready it should not take long to read the result that it offers.
    optterpri();
    princ "task done at "; prin elapsed();
    princ " after "; print tt;
    princ "      Result is "; printc r;
% When a task completes I check if there is more to do. If so I send the
% next work-packet to the fork that just finished.
% If I do not have any more to do I will just close down the fork that
% just finished.
    if started < wanted then <<
      send!-to!-fork(selected, list('work, started := started+1));
      princ "==== continue with work on "; prin started;
      princ " leaving "; prin length tasks; printc " running" >>
    else <<
      close!-fork selected;
      tasks := delete(selected, tasks);
      princ "==== reducing to "; prin length tasks; printc " running" >>
  end;

list("all done at", elapsed());

quit;
