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
//    fork!-ready(handle)
//        return T if the process concerned will be able to return a
//        value, or nil if it is still working (or if it has crashed).
//    get!-from!-fork(handle)
//        If fork!-ready returned T then this returns immediatly with
//        a result returned from the process. Otherwise it waits until
//        one becomes available, and eg if the process misbehaves or
//        has crashed or just takes a very long time to produce a
//        response this can cause aribitrary amounts of delay.
//    send!-fork!-reply(value)
//        This generates the material that get!-from!-fork() retrieves, as
//        discussed earlier.
//    close!-fork(handle)
//        Whether or not the process has finished its work this cancels
//        it and releases its resources. This should always be used when
//        the task that the fork was set up to handle has been completed,
//        but can be used earlier if local computation shows that there
//        is no need to get a result from it.
//
// It is suggested that the number of forks created should be limited to
// around the number of CPU cores of the processor being used. Also
// each fork uses memory - when first created this will share with the
// memory of the main process, but over time and if there are N forks
// in play this could occupy almost N times as much memory as any
// single one.


#include "headers.h"

LispObject Lcpu_count()
{   return fixnum_of_int(4);
}

#if defined WIN32 || !defined ENABLE_FORKS

LispObject Lopen_fork(LispObject env)
{   return nil;             // Always reports that it failed to open the fork.
}

LispObject Lsend_to_fork(LispObject env, LispObject handle, LispObject value)
{   return nil;
}

LispObject Lfork_ready(LispObject env, LispObject handle)
{   return nil;
}

LispObject Lget_from_fork(LispObject env, LispObject handle)
{   return nil;
}

LispObject Lsend_fork_reply(LispObject env, LispObject handle)
{   return nil;
}

LispObject Lclose_fork(LispObject env, LispObject handle)
{   return nil;
}

int32_t write_action_fork(int32_t op, LispObject f)
{   return 0;
}

int32_t char_to_fork(int c, LispObject stream)
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
{   return is_stream(handle) && stream_read_fn(handle) == char_from_fork;
}

LispObject Lopen_fork(LispObject env)
{   LispObject r = make_stream_handle();
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
    pid_t pid = fork();
    if (pid == 0)
    {
// Here is the child process.
// It can close the pipe-ends that are not relevant to it.
        close(fork_pipes_from[read_end]);
        close(fork_pipes_to[write_end]);
        stream_file(r) = reinterpret_cast<FILE*>(fork_pipes_to[read_end]);
        stream_extra(r) = fork_pipes_from[write_end];
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
        karatsuba_parallel = 0x7fffffff;
// (2) For a GUI run there are threads that might be involved in updating
//     the screen and handing mouse and keyboard events. For a console
//     mode version the keyboard would be being watched by a thread. I
//     do not want them to get re-created because the child process should
//     not participate in interaction with the user. I note that there is
//     a messy issue if the user sends an interrupt to the parent thread
//     while it has children - that could disrupt the flow of synchronization
//     between them all. I am going to ignore that matter for the moment!



// Now a loop providing service...
        for (;;)
        {   void* addr;
            if (read(fork_pipes_to[read_end], &addr, sizeof(addr)) !=
                    sizeof(addr) ||
                addr == nullptr) break;
            uint64_t d = 0x1234567876543210U;
            if (write(fork_pipes_from[write_end], &d, sizeof(d)) != sizeof(d))
                stdout_printf("write failure\n");;
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
    stream_file(r) = reinterpret_cast<FILE*>(fork_pipes_from[read_end]);
    stream_extra(r) = fork_pipes_to[write_end];
   return r;
}

LispObject Lsend_to_fork(LispObject env, LispObject handle, LispObject value)
{   return nil;
}

LispObject Lfork_ready(LispObject env, LispObject handle)
{   return lisp_true;
}

LispObject Lget_from_fork(LispObject env, LispObject handle)
{   return nil;
}

LispObject Lsend_fork_reply(LispObject env, LispObject handle)
{   return nil;
}

LispObject Lclose_fork(LispObject env, LispObject handle)
{   if (!is_fork(handle)) return aerror1("close-fork", handle);
// For the 2-way pipes that communicate with a forked process I will make
// WRITE_CLOSE or READ_CLOSE shut down everything. I do not need to do
// both.
    other_write_action(WRITE_CLOSE, handle);   
    return nil;
}

//uint64_t get_from_fork(void* addr)
//{
//    if (fork_pipes_to[write_end] == 0 ||
//        fork_pipes_from[read_end] == 0) return 0; // service not available.
//    if (write(fork_pipes_to[write_end], &addr, sizeof(addr)) != sizeof(addr))
//        return 0;
//    uint64_t data;
//    if (read(fork_pipes_from[read_end], &data, sizeof(data)) != sizeof(data))
//        return 0;
//    return data;
//}

int32_t write_action_fork(int32_t op, LispObject f)
{   int32_t w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                close(reinterpret_cast<intptr_t>(stream_file(f)));
                close(reinterpret_cast<intptr_t>(stream_extra(f)));
                stream_write_fn(f) = char_to_illegal;
                stream_write_other(f) = write_action_illegal;
                stream_read_fn(f) = char_from_illegal;
                stream_read_other(f) = read_action_illegal;
                stream_file(f) = nullptr;
                stream_extra(f) = 0;
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
{   if (c == '\n' || c == '\f')
        stream_byte_pos(stream) = stream_char_pos(stream) = 0;
    else if (c == '\t')
    {   stream_byte_pos(stream)++;
        stream_char_pos(stream) = (static_cast<int>(stream_char_pos(
                                       stream)) + 8) & ~7;
    }
    else if ((c & 0xc0) == 0x80) stream_byte_pos(stream)++;
    else
    {   stream_byte_pos(stream)++;
        stream_char_pos(stream)++;
    }
    int h = stream_extra(stream);
    if (write(h, &c, 1) != 1) return 1;
    return 0;   // indicate success
}

int char_from_fork(LispObject stream)
{   int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {   ch = 0;
        int h = reinterpret_cast<intptr_t>(stream_file(stream));
        if (read(h, &ch, 1) != 1)
            ch = EOF;
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

int32_t read_action_fork(int32_t op, LispObject f)
{   if (op < -1) return 1;
    else if (op <= 0xffff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                close(reinterpret_cast<intptr_t>(stream_file(f)));
                close(reinterpret_cast<intptr_t>(stream_extra(f)));
                stream_read_fn(f) = char_from_illegal;
                stream_read_other(f) = read_action_illegal;
                stream_write_fn(f) = char_to_illegal;
                stream_write_other(f) = write_action_illegal;
                stream_file(f) = nullptr;
                stream_extra(f) = 0;
                return 0;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
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

setup_type const forks_setup[] =
{   DEF_0("open_fork",        Lopen_fork),
    DEF_2("send-to-fork",     Lsend_to_fork),
    DEF_1("fork-ready",       Lfork_ready),
    DEF_1("get-from-fork",    Lget_from_fork),
    DEF_1("send-fork-reply",  Lsend_fork_reply),
    DEF_1("close-fork",       Lclose_fork),
    {nullptr,                 nullptr, nullptr, nullptr, nullptr, nullptr}
};


// end of forks.cpp
