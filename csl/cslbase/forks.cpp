// forks.cpp                                    Copyright (C) 2025 Codemist


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

// The code here is intended to support a style of use of multiprocessor
// computation. The function "open-fork()" creates a secondary Lisp
// environment that is a clone of the existing one, so all current
// datastructures and values are present in it and do not need to
// be transmitted. Then "send-to-fork()" makes it possible to send
// a command to that task, and "get-from-fork()" can retrieve a result.
// Very limited asynchronous usage is supported in that "fork-read()"
// can check if "get-from-fork()" would need to block waiting for a reply,
// and "close!-fork()" can terminate the secondary Lisp either tidily
// after a result has been returned or even while it is still at work.
// No request can be sent before the previous ones's result has been
// collected.
// It will be reasonable to have a number of forks broadly in line with
// the number of cores provided by the current CPU. There can also be
// limits because each fork created will use up whatever amount of memory
// its workings demand.
// As regards performance there are a number of things to be aware of:
// (.) Creating a new process is expected to be cheaper than starting up
//     a whole fresh Reduce from scratch but will take long enough that
//     it will not make sense to do if just to execute some rather small
//     sub-calculation.
// (.) Each of send-to-fork() and get-from-fork() involve synchronization
//     between independent processes and hence non-trivial operating
//     system activity. This means there is an inherent latency associated
//     with passing work from one process to another.
// (.) send-to-fork() and get-from-fork() have to convert their arguments
//     from Lisp-style data into a stream of bytes for transmission. Ie they
//     perform serialization. The result will be that large amounts of
//     data may take a while to transmit. The transmission scheme used
//     can cope with cyclic and reentrant structures (which involved the
//     need for a pre-pass to identify any such) but otherwise captures
//     information as if it was first sent to a file using print() then
//     recovered using read().
// If the granularity of parallelism is large enough and if the amount of
// data that needs to be transmitted is modest there can still be scope for
// speedup. In cases where the spawned task needs especially bulky input
// it may be useful to set that data up in Lisp variables and then do a
// fresh open-fork() so that the created process has direct access to it.
// The balance between that and having a long-term work farm and shipping
// full details of fresh tasks to a basic image using send-to-fork() will
// be a metter of judgment and tuning of the application code! 


// The functions provided are:
//
//    count := cpu!-count()
//        Report the number of cores provided by the CPU of the current
//        machine. Note that on non-heterogeneous machines some of these
//        may be "performance" and some may be "efficiency" cores and
//        fine details regarding that will not be provided.
//    handle := open!-fork()
//        Create a new process and return a handle that can be used to
//        communicate with it. Returns nil on failure.
//    send!-to!-fork(handle, value)
//        Send the indicated value (a list structure that should not
//        have loops in it) to the process identified by the handle.
//        [my intention is that the valus is passed to eval() and
//        that calls to send!-fork!-reply(value) sends that value back to
//        the parent. That protocol means that a task set up by
//        send!-to!-fork() can pass back a sequence of values where
//        there may be a delay between each. However it means that the
//        main process needs to understand when it has collected all those
//        values, because a further use of send!-to!-fork() would stall
//        unless all returned values had been retrieved. General attempts
//        by the fork task to generate output eg using print() or in
//        the form of system messages such as garbage collector reports
//        will have no effect much as if stdout has been redirected to
//        /dev/null. Save that probably as a debugging tool I may arrange
//        that such output is sent to a file whose name is keyed to the
//        process number of the task in use.
//    first!-fork(handle-list)
//    first!-fork(handle-list, millisecond_timeout)
//        The first form blocks until at least one of the tasks in
//        handle-list has some output that could be read, and then
//        rwturns that handle.
//        The second will try to find a task that has available data but
//        if there are none within the timeout it will return nil.
//        The timeout can be zero, and in that case use with a list of
//        length 1 provides a non-blocking test as to whether the specified
//        task is ready.
//    get!-from!-fork(handle)
//        This reads data from the given task, blocking if none is
//        immediately available. If you need to have a timeout then
//        you should have used first-fork() to hope for a data within
//        your time limit so that get!-from!-fork() is only called when
//        it is known that it will not block.
//    send!-fork!-reply(value)
//        This generates the material that get!-from!-fork() retrieves, as
//        discussed earlier.
//    close!-fork(handle)
//        Whether or not the process has finished its work this cancels
//        it and releases its resources. This should always be used when
//        the task that the fork was set up to handle has been completed,
//        but can be used earlier if local computation shows that there
//        is no need to get a result from it. It destroys the sub process
//        with extreme prejudice.
//
// It is suggested that the number of forks created should be limited to
// around the number of CPU cores of the processor being used. Also
// each fork uses memory - when first created this will share with the
// memory of the main process, but over time and if there are N forks
// in play this could occupy almost N times as much memory as any
// single one.

// Ha ha - Windows does not support fork() so the "easy" way of doing this
// is not available, but in due course I think I can nevertheless support
// it. Albeit at a the cost that starting up a new process will have fairly
// severe overhead.
// I can identify the file that I am executing from and create a fresh
// process running the same thing but with an adjusted set of command-line
// options, and I can cause the next process to inherit handles to a pipe
// from the current task. The magic new command line option then instructs
// the new process to load its heap image not from a file with a name
// such as "reduce.img" but using data that it receives down the pipe.
// I can then do a large fraction of what preserve() would do to transmit
// a complete copy of the current heap down my end of that pipe, and if
// I am a bit careful I think I can do that without damaging my current
// context. Then the created task just goes into a listen loop much as if
// it had been created uding fork(). The full heap copy with all the fuss
// of a serialization scheme that allows the reloading task to be using
// a different memory map is a huge overhead as compared against the
// copy-on-write model that fork() uses, but the end effect should be
// similar enough.
// I will not implement this until and unless the simpler scheme works
// and has been found generally useful!


#include "headers.h"

#if defined WIN32 || !defined ENABLE_FORKS

LispObject Lopen_fork(LispObject env)
{   SingleValued fn;
    return nil;             // Always reports that it failed to open the fork.
}

LispObject Lsend_to_fork(LispObject env, LispObject handle, LispObject value)
{   SingleValued fn;
    return nil;
}

LispObject Lfirst_fork(LispObject env, LispObject handles)
{   SingleValued fn;
    return nil;
}

LispObject Lfirst_fork(LispObject env, LispObject handles, LispObject tt)
{   SingleValued fn;
    return nil;
}

LispObject Lget_from_fork(LispObject env, LispObject handle)
{   SingleValued fn;
    return nil;
}

LispObject Lsend_fork_reply(LispObject env, LispObject value)
{   SingleValued fn;
    return nil;
}

LispObject Lclose_fork(LispObject env, LispObject handle)
{   SingleValued fn;
    return nil;
}

int32_t write_action_fork(int32_t op, LispObject f)
{   return 0;
}

int32_t char_to_fork(int c, LispObject stream)
{   return 0;
}

int32_t char_to_nowhere(int c, LispObject stream)
{   return 0;
}

int char_from_fork(LispObject stream)
{   return EOF;
}

int32_t read_action_fork(int32_t op, LispObject f)
{   return 0;
}

#else // WIN32, ENABLE_FORKS

// This is the top-level framework for fork support. It creates a copy of
// the current process and provides a pipe that allows for communication
// with it.

// I will hand back information about the process I create in the form
// of a Lisp stream. That will mean that it provides character read and write
// operations in much the same style as other forms of stream. The structure
// will require space for two "int" fields that will hold handles for the
// two pipes. I will overlay those on the "file" and "spare" slots in the existing
// stream structure. That leaves all the other fields available to serve their
// current purpose!


static constexpr int read_end = 0;
static constexpr int write_end = 1;

bool is_fork(LispObject handle)
{   return is_stream(handle) &&
           stream_read_fn(handle) == char_from_fork;
}

using namespace std;

LispObject Lsend_fork_reply(LispObject env, LispObject value)
{   SingleValued fn;
    LispObject handle = qvalue(fork_parent);
    if (!is_fork(handle))
    {   pid_printf("Not a fork handle in send_fork_reply");
        return aerror1("send-fork-reply needs to be in child fork", handle);
    }
    Lprint_2(nil, value, handle);
    int h = stream_write_fd(handle);
    static char c[4] = {0x1b, 0, 0, 0};
    if (write(h, &c[0], 1) != 1)
    {   pid_printf("failed to write ESC in send_fork_reply");
        return aerror("Failed to write terminating ESC");
    }
    return nil;
}

#ifdef __linux__
#include <sys/prctl.h>
#include <signal.h>
#endif // __linux__

LispObject Lopen_fork(LispObject env)
{   SingleValued fn;
    LispObject r = make_stream_handle();
    errexit();
    stream_type(r) = make_string("fork handle");
    int fork_pipes_to[2] = {0, 0};
    int fork_pipes_from[2] = {0, 0};
    if (pipe(fork_pipes_to) == -1) return nil;
    if (pipe(fork_pipes_from) == -1)
    {   close(fork_pipes_to[0]);
        close(fork_pipes_to[1]);
        return nil;
    }
    stream_read_fn(r) =  char_from_fork;
    stream_read_other(r) = read_action_fork;
    stream_write_fn(r) = char_to_fork;
    stream_write_other(r) = write_action_fork;
    stream_line_length(r) = 0;
    stream_pushed_char(r) = NOT_CHAR;
    Lflush(nil);
    pid_t before_fork = getpid();
    pid_t pid = fork();
    if (pid == 0)
    {
#ifdef __linux__
// If I am on Linux I can ensure that the child task terminates if the
// parent one does. On my first attempt to put this in it seemed to cause
// breakage, so I need to understand more! 
//      int r = prctl(PR_SET_PDEATHSIG, SIGTERM);
//      if (r == -1 || getppid() != before_fork) exit(1);
#endif // __linux__
// Here is the child process. The first thing I will do will be to
// get the helper threads for Karatsuba multiplication established again.
#ifdef ARITHLIB
        permitParallel = false;
#else // ARITHLIB
        karatsuba_parallel = 0x7fffffff;
#endif //ARITHLIB
// I do not want it to be able to generate any output!
        stream_write_fn(lisp_work_stream) = char_to_nowhere;
        stream_write_fn(lisp_terminal_io) = char_to_nowhere;
        stream_write_fn(lisp_standard_output) = char_to_nowhere;
        stream_write_fn(lisp_standard_input) = char_to_nowhere;
        stream_write_fn(lisp_error_output) = char_to_nowhere;
        stream_write_fn(lisp_trace_output) = char_to_nowhere;
        stream_write_fn(lisp_debug_io) = char_to_nowhere;
        stream_write_fn(lisp_query_io) = char_to_nowhere;
// It can close the pipe-ends that are not relevant to it.
        close(fork_pipes_from[read_end]);
        close(fork_pipes_to[write_end]);
        set_stream_read_fd(r, fork_pipes_to[read_end]);
        set_stream_write_fd(r, fork_pipes_from[write_end]);
        stream_pid(r) = 0;
        qvalue(fork_parent) = r;
// When a process forks all its threads will continue happily on the parent
// but the versions in the child will not. Here I have the following
// threads that I can worry about:
// (1) Karatsuba. I must re-create the threads in the child process, or
//     set things so that parallel-Karatsuba is never attempted. Note that
//     none of the arithmetic-related threads can be doing anything at all
//     exciting when open!-fork is called. The simpler thing to do will be
//     to disable all attempts to use parallel Karstsuba, so that is what
//     I do here.
// (2) For a GUI run there are threads that might be involved in updating
//     the screen and handing mouse and keyboard events. For a console
//     mode version the keyboard would be being watched by a thread. I
//     do not want them to get re-created because the child process should
//     not participate in interaction with the user. I note that there is
//     a messy issue if the user sends an interrupt to the parent thread
//     while it has children - that could disrupt the flow of synchronization
//     between them all. I am going to ignore that matter for the moment!
//
// Now a loop providing service...
        Lrds(nil, qvalue(fork_parent));
        Lwrs(nil, qvalue(fork_parent));
        qvalue(echo_symbol) = nil;
        for (;;)
        {   LispObject w = Lread(nil);
            if (w == eof_symbol) break;            // on EOF give up.
            Lsend_fork_reply(nil, Leval(nil, w));
        }
        close(fork_pipes_from[write_end]);
        close(fork_pipes_to[read_end]);
// When there is no more to do I use quick_exit because by doing that I
// do not need to worry about tidying up anything, and I really would hate
// it if some destructor in the child process performed file operations in
// the name of clean termination and messed things up for the parent.
        quick_exit(0);
    }
    else if (pid < 0)
    {
// This is the case if fork() fails - I close pipes and set things so
// that attempts to use them become boring.
        close(fork_pipes_from[read_end]);
        close(fork_pipes_from[write_end]);
        close(fork_pipes_to[read_end]);
        close(fork_pipes_to[write_end]);
        return nil;
    }
// Here is where the parent process has successfully forked, so it closes
// the pipe-ends that it will not be using. And then it can use oldMem()
// to retrieve data from the saved state.
    close(fork_pipes_from[write_end]);
    close(fork_pipes_to[read_end]);
    set_stream_read_fd(r, fork_pipes_from[read_end]);
    set_stream_write_fd(r, fork_pipes_to[write_end]);
    stream_pid(r) = pid;
// Here I return the stread handle that should let me access the fork. I
// do this rather than putting it into a fixed location because I may end
// up forking multiple sub-processes.
    return r;
}

LispObject Lsend_to_fork(LispObject env, LispObject handle, LispObject value)
{   SingleValued fn;
    Lprint_2(nil, value, handle);
    return nil;
}

LispObject Lget_from_fork(LispObject env, LispObject handle)
{   SingleValued fn;
    if (!is_fork(handle))
    {   pid_printf("not a fork handle in get_from_fork");
        return aerror1("get-from-fork", handle);
    }
    LispObject r = Lread(nil, handle);
// read() may or may not have read a character beyond the expression
// it wanted. Eg after a symbol or number it is liable to have had to
// read a whitspace or punctuation to know when to stop. It may then
// have pushed this character back. At the end of a string it needs to
// verify that theer are not two double-quotes in a row. However when
// it accepts the ")" that terminates s list it does not need to look
// further. So here I cancel and pushed character and then keep reading
// until I find an escape character (U+001b).
    stream_pushed_char(handle) = NOT_CHAR;
    int fd = stream_read_fd(handle);
    char ch[4];
    for (;;)
    {   if (read(fd, &ch[0], 1) != 1)
        {   pid_printf("could not find ESC in get_from_fork");
            return aerror("Failed to get fork data");
        }
        if (ch[0] == 0x1b) break;
    }
    return r;
}

#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>

LispObject Lclose_fork(LispObject env, LispObject handle)
{   SingleValued fn;
    if (!is_fork(handle))
    {   pid_printf("not a fork handle in close_fork");
        return aerror1("close-fork", handle);
    }
    pid_t pid = stream_pid(handle);
    kill(pid, SIGKILL);
    int status;
// This is a simplistic wait for the process to end and does not take
// magic action if (eg) signals intervene.
    waitpid(pid, &status, 0);
    return nil;
}

int32_t write_action_fork(int32_t op, LispObject f)
{   int32_t w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                close(stream_read_fd(f));
                close(stream_write_fd(f));
                stream_write_fn(f) = char_to_illegal;
                stream_write_other(f) = write_action_illegal;
                stream_read_fn(f) = char_from_illegal;
                stream_read_other(f) = read_action_illegal;
                stream_file(f) = nullptr;
                stream_extra(f) = 0;
                stream_pid(f) = 0;
                return 0;
            case WRITE_FLUSH:
                return 0;
            case WRITE_SET_LINELENGTH_DEFAULT:
                op = 80;  // drop through
            case WRITE_SET_LINELENGTH:
                w = stream_line_length(f);
                stream_line_length(f) = op & 0x07ffffff;
                return w;
            case WRITE_SET_COLUMN:
                w = stream_char_pos(f);
                stream_char_pos(f) = op & 0x07ffffff;
                return w;
            case WRITE_GET_INFO:
                switch (op & 0xff)
                {   case WRITE_GET_LINE_LENGTH: return stream_line_length(f);
                    case WRITE_GET_COLUMN:      return stream_char_pos(f);
                    case WRITE_IS_CONSOLE:      return 0;
                    default:return 0;
                }
            default:
                return 0;
        }
}

int32_t char_to_fork(int c, LispObject stream)
{   int h = stream_write_fd(stream);
    if (write(h, &c, 1) != 1) return 1;
    return 0;   // indicate success
}

int32_t char_to_nowhere(int c, LispObject stream)
{   return 0;   // indicate success
}

const size_t max_number_of_forks = 100;

LispObject Lfirst_fork(LispObject env, LispObject handles, LispObject timeout)
{   SingleValued fn;
    struct pollfd fds[max_number_of_forks];
    size_t count = 0;
    LispObject w = handles;
    intptr_t tt = -1;    // non-integer timeout => block for unlimited time.
    if (is_fixnum(timeout)) tt = int_of_fixnum(timeout);
    while (is_cons(w))
    {   LispObject h = car(w);
        w = cdr(w);
        if (!is_fork(h))
        {   pid_printf("not a fork handle in first_fork");
            return aerror1("first-fork", handles);
        }
        fds[count].fd = stream_read_fd(h);
        fds[count].events = POLLIN;
        fds[count].revents = 0;
        count++;
    }
    int r = poll(&fds[0], count, tt);  // Wait for first to respond.
//  for (size_t j=0; j<count; j++)
//      printf("%d:(%d):%x ", (int)j, (int)fds[j].fd, (int)fds[j].revents);
    printf("\n");
    if (r <= 0) return nil;            // None. Must have timed out.
    for (size_t j=0; j<count; j++)
    {   if (fds[j].revents != 0) break;
        handles = cdr(handles);
    }
    return car(handles);
}

LispObject Lfirst_fork(LispObject env, LispObject handles)
{   return Lfirst_fork(env, handles, fixnum_of_int(-1));
}

int char_from_fork(LispObject stream)
{   char ch[4];
    int fd = stream_read_fd(stream);
    if (read(fd, &ch[0], 1) != 1) return EOF;
    else return ch[0];
}

int32_t read_action_fork(int32_t op, LispObject f)
{   if (op < -1) return 1;
    else if (op <= 0xffff) return 1;
    else switch (op)
        {   case READ_CLOSE:
                close(stream_read_fd(f));
                close(stream_write_fd(f));
                stream_read_fn(f) = char_from_illegal;
                stream_read_other(f) = read_action_illegal;
                stream_write_fn(f) = char_to_illegal;
                stream_write_other(f) = write_action_illegal;
                stream_file(f) = nullptr;
                stream_extra(f) = 0;
                stream_pid(f) = 0;
                return 0;
            case READ_FLUSH:
                return 0;
            case READ_TELL:
                return -1;
            case READ_IS_CONSOLE:
                return 0;
            default:
                return 0;
        }
}

#endif // WIN32, ENABLE_FORKS

LispObject Lcpu_count(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(number_of_processors());
}

setup_type const forks_setup[] =
{   DEF_0("cpu-count",        Lcpu_count),
    DEF_0("open-fork",        Lopen_fork),
    DEF_2("send-to-fork",     Lsend_to_fork),
    {"first-fork", G0Wother, Lfirst_fork, Lfirst_fork, G3Wother, G4Wother},
    DEF_1("get-from-fork",    Lget_from_fork),
    DEF_1("send-fork-reply",  Lsend_fork_reply),
    DEF_1("close-fork",       Lclose_fork),
    {nullptr,                 nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of forks.cpp
