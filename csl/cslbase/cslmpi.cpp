// cslmpi.cpp                                       Copyright (C) 1997-2022

//
// Interfaces for mpi from CSL. The bulk of this code was written by
// M O Seymour (1997-98) who has released it for inclusion as part of
// this Lisp system.
//

// I have left this using malloc/free rather than new/delete since it is
// self-contained and the memory allocated does not get passed out to
// other parts of CSL.

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#include "headers.h"


// Note VERY WELL....
// I have not even compiled this code at all recently, though I made
// significant changed to it to adjust for calling conventions. Anybody
// trying to use it should expect to need to make adjustments and
// corrections.  ACN August 2017.


#ifdef USE_MPI

#include "mpipack.c"

inline LispObject get_fix_arg(LispObject& v, const char *fun_name)
{   if (!is_fixnum(v)) return aerror1(fun_name, v)
        v = int_of_fixnum(v);
}


/************************ Environmental functions *******************/

// Returns process rank
// (mpi_comm_rank comm)
//
// For now, I assume that comm will fit into a fixnum.
// This appears to be the case with MPICH (values in the hundreds),
// but assumptions like this should not be made.
//
static LispObject Lmpi_comm_rank(LispObject, LispObject comm)
{   SingleValued fn;
    int rank;
    static char fun_name[] = "mpi_comm_rank";
    if (!is_fixnum(comm)) return aerror1(fun_name, v)
        MPI_Comm_rank(int_of_fixnum(comm),&rank);
    return fixnum_of_int(rank);
}

// returns size of communicator
// (mpi_comm_size comm)
//
// Same assumption about comm.
static LispObject Lmpi_comm_size(LispObject, LispObject comm)
{   SingleValued fn;
    int size;
    static char fun_name[] = "mpi_comm_size";
    if (!is_fixnum(comm)) return aerror1(fun_name, v);
    MPI_Comm_size(int_of_fixnum(comm),&size);
    return fixnum_of_int(size);
}

/********************** Blocking point-to-point functions *************/

// Standard blocking send
// (mpi_send message dest tag comm)
// returns nil.
//
//  Same assumption about comm.
static LispObject Lmpi_send(LispObject env, LispObject message,
                            LispObject dest,
                            LispObject tag, LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_send";

    get_fix_arg(dest, fun_name);
    get_fix_arg(tag, fun_name);
    if (cdr(comm) != nil) return aerror("too many args for mpi-send");
    comm = car(comm);
    get_fix_arg(comm, fun_name);

    pack_object(message);
    MPI_Send(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
             dest, tag, comm);
    std::free(mpi_pack_buffer);
    return nil;
}

// Standard blocking receive
// (mpi_recv source tag comm)
// returns (message (source tag error)).
//
static LispObject Lmpi_recv(LispObject, LispObject source,
                            LispObject tag, LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_recv";

    MPI_Status status;
    LispObject Lstatus;
    std::va_list a;

    get_fix_arg(source, fun_name);
    get_fix_arg(tag, fun_name);
    get_fix_arg(comm, fun_name);

    MPI_Probe(source, tag, comm, &status);
    MPI_Get_count(&status, MPI_PACKED, &mpi_pack_size);
    mpi_pack_buffer = reinterpret_cast<char*>(std::malloc(mpi_pack_size));

    MPI_Recv(mpi_pack_buffer, mpi_pack_size, MPI_PACKED,
             source, tag, comm, &status);

    // The only relevant status things are the 3 public fields, so I'll
    // stick them in a list and return them as the 2nd value
    //
    LispObject r = unpack_object();
    THREADID;
    Save save(threadId, r);
    std::free(mpi_pack_buffer);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));
    errexit();
    save.restore(r);
    return list2(r, Lstatus);
}

// Standard blocking simultaneous send and receive
// (mpi_sendrecv send_message dest send_tag source recv_tag comm)
// returns (recv_message (source recv_tag error))
//
// THERE IS A LIMIT OF 1024 BYTES FOR THE RECEIVE BUFFER (sorry.)
// THIS WILL BE REMOVED ASAP.
//
static LispObject Lmpi_sendrecv(LispObject, LispObject s_mess,
                                LispObject dest,
                                LispObject tag, LispObject a4up)
{   SingleValued fn;
    static char fun_name[] = "mpi_sendrecv";

    MPI_Status status;
    LispObject Lstatus;
    LispObject s_mess;
    int r_tag, source, comm;
    char r_buffer[1024];

    get_fix_arg(dest, fun_name);
    get_fix_arg(s_tag, fun_name);
    source = car(a4up);
    a4up = cdr(a4up);
    get_fix_arg(source);
    if (a4up == nil) return aerror("not enough arguments for mpi_sendrecv");
    r_tag = car(a4up);
    a4up = cdr(a4up);
    get_fix_arg(r_tag);
    if (a4up == nil) return aerror("not enough arguments for mpi_sendrecv");
    com = car(a4up);
    a4up = cdr(a4up);
    get_fix_arg(comm);
    if (a4up != nil) return aerror("too many arguments for mpi_sendrecv");

    pack_object(s_mess);
    MPI_Sendrecv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                 dest, s_tag,
                 r_buffer, 1024, MPI_PACKED,
                 source, r_tag, comm, &status);
    std::free(mpi_pack_buffer);
    mpi_pack_buffer = r_buffer;
    LispObject r = unpack_object();
    THREADID;
    Save save(threadId, r);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));
    errexit();
    save.restore(r);
    return list2(r, Lstatus);
}

/************** Non-Blocking point-to-point functions ***********/

// Standard non-blocking send post
// (mpi_isend message dest tag comm)
// returns request handle
//
static LispObject Lmpi_isend(LispObject, LispObject message,
                             LispObject dest,
                             LispObject tag, LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_isend";

    LispObject message, request;
    int dest, tag, comm;

    // For now, we assume type MPI_Request to be 32 bits.
    request = Lmkvect32(nil,fixnum_of_int(2));

    get_fix_arg(dest, fun_name);
    get_fix_arg(tag, fun_name);
    if (cdr(comm) != nil) return aerror("too many args for mpi_isend");
    comm = car(comm);
    get_fix_arg(comm, fun_name);

    pack_object(message);
    MPI_Isend(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
              dest, tag, comm,  (MPI_Request*)&elt(request,0));
    elt(request,1) = static_cast<int>(mpi_pack_buffer);
    return request;
}

// Standard non-blocking receive post
// (mpi_irecv source tag comm)
// returns request handle
//
// I actually cheat horribly by not posting the request at all (at least
// not via MPI), but rather create my own "dummy" request structure.
// Then, to complete the request, I MPI_(I)Probe for a matching message,
// and receive it if it is there.
// This is unsatisfactory since the operation is only non-blocking until the
// first lump of the message arrives; for a long message, there may by
// a lot of latency after this.
//
struct dummy_request
{   int source;
    int tag;
    int comm;
};

static LispObject Lmpi_irecv(LispObject, LispObject aource,
                             LispObject tag, LispObject comm
{   SingleValued fn;
    static char fun_name[] = "mpi_irecv";

    LispObject request;
    char* buffer;

    // For now, we assume type MPI_Request to be 32 bits.
    request = Lmkvect32(nil,fixnum_of_int(2));

    get_fix_arg(source, fun_name);
    get_fix_arg(tag, fun_name);
    get_fix_arg(comm, fun_name);

    elt(request,1) = 0; // There is no buffer yet
    elt(request,0) = static_cast<int>(std::malloc(sizeof(struct dummy_request)));
    ((struct dummy_request*)elt(request,0))->source = source;
    ((struct dummy_request*)elt(request,0))->tag = tag;
    ((struct dummy_request*)elt(request,0))->comm = comm;

    return request;
}

// Wait to complete operation, and deallocate buffer.
// (mpi_wait request)
// for send, returns nil
// for recv, returns (message (source tag error))
//
static LispObject Lmpi_wait(LispObject env, LispObject request)
{   SingleValued fn;
    MPI_Status status;
    LispObject message, Lstatus;
    if ( !(is_vector(request) &&
           type_of_header(vechdr(request)) == TYPE_VEC32 &&
           length_of_header(vechdr(request)) == 3*CELL) )
        return aerror1("mpi_wait",request);
    if ( elt(request,1))
    {   status.MPI_ERROR = MPI_UNDEFINED;
        mpi_pack_buffer = reinterpret_cast<void*>(elt(request,1));
        MPI_Wait( (MPI_Request*)&elt(request,0), &status);
        if (status.MPI_ERROR == MPI_UNDEFINED)        // i.e. send request
        {   std::free(mpi_pack_buffer);
            return nil;
        }
        else     // old-style receive
        {   LispObject r = unpack_object();
            THREADID;
            Save save(threadId, r);
            std::free(mpi_pack_buffer);
            Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                            fixnum_of_int(status.MPI_TAG),
                            fixnum_of_int(status.MPI_ERROR));
            errexit();
            save.restore(r);
            return list2(r, Lstatus);
        }
    }
    else       // new-style receive
    {   int source = ((struct dummy_request*)elt(request,0))->source,
                tag = ((struct dummy_request*)elt(request,0))->tag,
                comm = ((struct dummy_request*)elt(request,0))->comm;
        MPI_Probe(source, tag, comm, &status);
        std::free((struct dummy_request*)elt(request,0));
        MPI_Get_count(&status, MPI_PACKED, &mpi_pack_size);
        mpi_pack_buffer = reinterpret_cast<char*>(std::malloc(mpi_pack_size));

        MPI_Recv(mpi_pack_buffer, mpi_pack_size, MPI_PACKED,
                 source, tag, comm, &status);

        // The only relevant status things are the 3 public fields, so I'll
        // stick them in a list and return them as the 2nd value
        //
        LispObject r = unpack_object());
        THREADID;
        Save save(threadId, r);
        std::free(mpi_pack_buffer);
        Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                        fixnum_of_int(status.MPI_TAG),
                        fixnum_of_int(status.MPI_ERROR));
        errexit();
        save.restore(r);
        return list2(r, Lstatus);
    }
}


// Test for completion, deallocate buffer if so
// (mpi_test request)
// for send, returns flag
// for recv, returns nil or (message (source tag error))
//
static LispObject Lmpi_test(LispObject env, LispObject request)
{   SingleValued fn;
    MPI_Status status;
    LispObject message, Lstatus;
    int flag;
    if ( !(is_vector(request) &&
           type_of_header(vechdr(request)) == TYPE_VEC32 &&
           length_of_header(vechdr(request)) == 3*CELL) )
        return aerror1("mpi_wait",request);
    if (elt(request,1))
    {   status.MPI_ERROR = MPI_UNDEFINED;
        mpi_pack_buffer = reinterpret_cast<void*>(elt(request,1));
        MPI_Test( (MPI_Request*)&elt(request,0), &flag, &status);
        if (!flag) return nil;
        if (status.MPI_ERROR == MPI_UNDEFINED)        // send request
        {   std::free(mpi_pack_buffer);
            return Lispify_predicate(YES);
        }
        else    // old-style receive
        {   LispObject r = unpack_object();
            THREADID;
            Save save(threadId, r);
            std::free(mpi_pack_buffer);
            Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                            fixnum_of_int(status.MPI_TAG),
                            fixnum_of_int(status.MPI_ERROR));
            errexit();
            save.restore(r);
            return list2(r, Lstatus);
        }
    }
    else          // new-style receive
    {   int source = ((struct dummy_request*)elt(request,0))->source,
                tag = ((struct dummy_request*)elt(request,0))->tag,
                comm = ((struct dummy_request*)elt(request,0))->comm,   flag;
        MPI_Iprobe(source, tag, comm, &flag, &status);

        if (!flag) return nil;

        std::free((struct dummy_request*)elt(request,0));
        MPI_Get_count(&status, MPI_PACKED, &mpi_pack_size);
        mpi_pack_buffer = reinterpret_cast<char*>(std::malloc(mpi_pack_size));

        MPI_Recv(mpi_pack_buffer, mpi_pack_size, MPI_PACKED,
                 source, tag, comm, &status);

        // The only relevant status things are the 3 public fields, so I'll
        // stick them in a list and return them as the 2nd value
        //
        LispObject r = unpack_object();
        THREADID;
        Save save(threadId, r);
        std::free(mpi_pack_buffer);
        Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                        fixnum_of_int(status.MPI_TAG),
                        fixnum_of_int(status.MPI_ERROR));
        errexit();
        save.restore(r);
        return list2(r, Lstatus);
    }
}

/************** Probe functions *******************/
// Non-blocking probe
// (mpi_iprobe source tag comm)
// returns (flag (source tag error))
//
static LispObject Lmpi_iprobe(LispObject, LispObject source,
                              LispObject tag,
                              LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "impi_probe";

    MPI_Status status;
    int flag;
    LispObject Lstatus;
    get_fix_arg(source, fun_name);
    get_fix_arg(tag, fun_name);
    get_fix_arg(comm, fun_name);

    MPI_Iprobe(source, tag, comm, &flag, &status);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));
    return list2(Lispify_predicate(flag), Lstatus);
}

// Blocking probe
// (mpi_probe source tag comm)
// returns (source tag error)
//
static LispObject Lmpi_probe(LispObject, LispObject source,
                             LispObject tag,
                             LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_probe";

    MPI_Status status;
    int source, tag, comm;
    LispObject Lstatus;
    get_fix_arg(source, fun_name);
    get_fix_arg(tag, fun_name);
    get_fix_arg(comm, fun_name);

    MPI_Probe(source, tag, comm, &status);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));
    return Lstatus;
}

/************** Collective Communications *********/

// Barrier; blocks until all processes have called
// (mpi_barrier comm)
// returns nil
//
static LispObject Lmpi_barrier(LispObject env, LispObject comm)
{   SingleValued fn;
    int rank;
    static char fun_name[] = "mpi_barrier";
    if (!is_fixnum(comm)) return aerror1(fun_name, v);
    MPI_Barrier(int_of_fixnum(comm));
    return nil;
}

// Broadcast; sends buffer of root to buffers of others.
// (mpi_bcast message root comm)  [message ignored if not root]
// returns message
//
static LispObject Lmpi_bcast(LispObject, LispObject message,
                             LispObject root, LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_bcast";

    int rank;
    get_arg(message, fun_name);
    get_fix_arg(root, fun_name);
    get_fix_arg(comm, fun_name);

    MPI_Comm_rank(comm,&rank);
    if (rank == root)
    {   pack_object(message);
        MPI_Bcast(&mpi_pack_position, 1, MPI_LONG, root, comm);
        MPI_Bcast(mpi_pack_buffer, mpi_pack_position, MPI_PACKED, root, comm);
        std::free(mpi_pack_buffer);
    }
    else
    {   MPI_Bcast(&mpi_pack_size, 1, MPI_LONG, root, comm);
        mpi_pack_buffer = reinterpret_cast<char*>(std::malloc(mpi_pack_size));
        MPI_Bcast(mpi_pack_buffer, mpi_pack_size, MPI_PACKED, root, comm);
        message = unpack_object();
        std::free(mpi_pack_buffer);
    }
    return message;
}

// Gather: root receives messages from others.
// (mpi_gather message root comm)
// returns vector of messages if root, else nil.
//
static LispObject Lmpi_gather(LispObject, LispObject message,
                              LispObject root,
                              LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_gather";

    int rank;
    get_arg(message, fun_name);
    get_fix_arg(root, fun_name);
    get_fix_arg(comm, fun_name);

    MPI_Comm_rank(comm,&rank);
    pack_object(message);
    if (rank == root)
    {   int commsize, count;
        int *recvcounts, *displs;
        char *recvbuffer;

        MPI_Comm_size(comm,&commsize);
        recvcounts = reinterpret_cast<int*>(std::calloc(commsize,
                     sizeof(int)));
        displs = reinterpret_cast<int*>(std::calloc(commsize+1, sizeof(int)));
        MPI_Gather(&mpi_pack_position, 1, MPI_LONG,
                   recvcounts, 1, MPI_LONG, root, comm);

        displs[0] = 0;
        for (count = 0; count < commsize; ++count)
            displs[count+1] = displs[count] + recvcounts[count];

        recvbuffer = reinterpret_cast<char*>(std::malloc(displs[commsize]));

        MPI_Gatherv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                    recvbuffer, recvcounts, displs, MPI_PACKED, root, comm);
        std::free(mpi_pack_buffer);

        message = Lmkvect(nil, fixnum_of_int(commsize-1));
        for (count = 0; count < commsize; ++count)
        {   mpi_pack_buffer = recvbuffer + displs[count];
            mpi_pack_size = recvcounts[count];
            elt(message, count) = unpack_object();
        }
        std::free(recvbuffer); std::free(recvcounts); std::free(displs);
    }
    else
    {   MPI_Gather(&mpi_pack_position, 1, MPI_LONG, 0, 0, MPI_LONG, root,
                   comm);
        MPI_Gatherv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                    0,0,0,MPI_PACKED, root, comm);
        std::free(mpi_pack_buffer);
        message = nil;
    }
    return message;
}

// Scatter: inverse of gather.
// (mpi_scatter vector_of_messages root comm)  [messages ignored if not root]
// returns message
//
static LispObject Lmpi_scatter(LispObject, LispObject messages,
                               LispObject root,
                               LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_scatter";

    LispObject message;
    int rank;
    std::va_list a;

    get_fix_arg(root, fun_name);
    get_fix_arg(comm, fun_name);

    MPI_Comm_rank(comm,&rank);
    if (rank == root)
    {   int commsize, count, *sendcounts, *displs, recvcount;
        char* recvbuffer;

        MPI_Comm_size(comm,&commsize);
        sendcounts = reinterpret_cast<int*>(std::calloc(commsize,
                     sizeof(int)));
        displs = reinterpret_cast<int*>(std::calloc(commsize+1, sizeof(int)));
        displs[0] = 0;

        // Call private functions in mpi_packing for consecutive packs
        check_buffer = scatter_check_buffer;
        mpi_pack_offset = 0;
        mpi_pack_position = 0;
        mpi_pack_size = 0;
        mpi_buffer_bottom = 0;
        mpi_real_size = 0;
        for (count = 0; count < commsize; ++count)
        {   pack_cell(elt(messages,count));
            sendcounts[count] = mpi_pack_position;
            mpi_pack_size -= mpi_pack_position;
            mpi_pack_offset += mpi_pack_position;
            mpi_pack_buffer += mpi_pack_position;
            displs[count+1] = mpi_pack_offset;
            mpi_pack_position = 0;
        }
        check_buffer = default_check_buffer;
        MPI_Scatter(sendcounts, 1, MPI_LONG, &recvcount, 1, MPI_LONG, root,
                    comm);
        recvbuffer = reinterpret_cast<char*>(std::malloc(recvcount));
        MPI_Scatterv(mpi_buffer_bottom, sendcounts, displs, MPI_PACKED,
                     recvbuffer, recvcount, MPI_PACKED, root, comm);
        std::free(recvbuffer);
        std::free(sendcounts);
        std::free(displs);
        std::free(mpi_buffer_bottom);
        message = elt(messages, root);
    }
    else
    {   MPI_Scatter(0,0,MPI_LONG,&mpi_pack_size,1,MPI_LONG,root,comm);
        mpi_pack_buffer = reinterpret_cast<char*>(std::malloc(mpi_pack_size));
        MPI_Scatterv(0,0,0,MPI_PACKED,
                     mpi_pack_buffer,mpi_pack_size,MPI_PACKED,root,comm);
        message = unpack_object();
        std::free(mpi_pack_buffer);
    }
    return message;
}


// Allgather: just like gather, only everyone gets the result.
// (mpi_allgather message comm)
// returns vector of messages
//
static LispObject Lmpi_allgather(LispObject,
                                 LispObject message,
                                 LispObject comm)
{   SingleValued fn;
    static char fun_name[] = "mpi_gather";
    int commsize, buffersize, count;
    int *recvcounts, *displs;
    char *recvbuffer;

    if (!is_fixnum(comm)) return aerror1(fun_name, v);
    comm = int_of_fixnum(comm);

    pack_object(message);

    MPI_Comm_size(comm,&commsize);
    recvcounts = reinterpret_cast<int*>(std::calloc(commsize,
                 sizeof(int)));
    displs = reinterpret_cast<int*>(std::calloc(commsize+1, sizeof(int)));
    MPI_Allgather(&mpi_pack_position, 1, MPI_LONG, recvcounts, 1,
                  MPI_LONG, comm);

    displs[0] = 0;
    for (count = 0; count < commsize; ++count)
        displs[count+1] = displs[count] + recvcounts[count];

    recvbuffer = reinterpret_cast<char*>(std::malloc(displs[commsize]));

    MPI_Allgatherv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                   recvbuffer, recvcounts, displs, MPI_PACKED, comm);
    std::free(mpi_pack_buffer); std::free(recvcounts); std::free(displs);

    message = Lmkvect(nil, fixnum_of_int(commsize-1));
    for (count = 0; count < commsize; ++count)
    {   mpi_pack_buffer = recvbuffer + displs[count];
        mpi_pack_size = recvcounts[count];
        elt(message, count) = unpack_object();
    }
    std::free(recvbuffer);
    return message;
}

// All to all scatter/gather.
// (mpi_alltoall vector_of_messages comm)
// returns vector of messages.
//
static LispObject Lmpi_alltoall(LispObject,
                                LispObject smessages, LispObject Lcomm)
{   SingleValued fn;
    static char fun_name[] = "mpi_alltoall";

    LispObject rmessages;
    int rank,comm, commsize, count;
    int *sendcounts, *recvcounts, *sdispls, *rdispls;
    char* recvbuffer;

    if (!is_fixnum(comm)) return aerror1(fun_name, v);
    comm = int_of_fixnum(Lcomm);

    MPI_Comm_size(comm,&commsize);
    sendcounts = reinterpret_cast<int*>(std::calloc(commsize, sizeof(int)));
    recvcounts = reinterpret_cast<int*>(std::calloc(commsize, sizeof(int)));
    sdispls = reinterpret_cast<int*>(std::calloc(commsize+1, sizeof(int)));
    rdispls = reinterpret_cast<int*>(std::calloc(commsize+1, sizeof(int)));

    // Call private functions in mpi_packing for consecutive packs
    check_buffer = scatter_check_buffer;
    mpi_pack_offset = 0;
    mpi_pack_position = 0;
    mpi_pack_size = 0;
    mpi_buffer_bottom = 0;
    mpi_real_size = 0;
    for (count = 0; count < commsize; ++count)
    {   pack_cell(elt(smessages,count));
        sendcounts[count] = mpi_pack_position;
        mpi_pack_size -= mpi_pack_position;
        mpi_pack_offset += mpi_pack_position;
        mpi_pack_buffer += mpi_pack_position;
        sdispls[count+1] = mpi_pack_offset;
        mpi_pack_position = 0;
    }
    check_buffer = default_check_buffer;

    MPI_Comm_rank(comm,&rank);

    MPI_Alltoall(sendcounts, 1, MPI_LONG, recvcounts, 1, MPI_LONG, comm);

    rdispls[0] = 0;
    for (count = 0; count < commsize; ++count)
        rdispls[count+1] = rdispls[count] + recvcounts[count];

    recvbuffer = reinterpret_cast<char*>(std::malloc(rdispls[commsize]));

    MPI_Alltoallv(mpi_buffer_bottom, sendcounts, sdispls, MPI_PACKED,
                  recvbuffer, recvcounts, rdispls, MPI_PACKED, comm);

    std::free(mpi_buffer_bottom); std::free(sendcounts);
    std::free(sdispls);

    rmessages = Lmkvect(nil, fixnum_of_int(commsize-1));
    for (count = 0; count < commsize; ++count)
    {   mpi_pack_buffer = recvbuffer + rdispls[count];
        mpi_pack_size = recvcounts[count];
        elt(rmessages, count) = unpack_object();
    }
    std::free(recvbuffer); std::free(recvcounts); std::free(rdispls);
    return rmessages;
}

#else  // USE_MPI

static LispObject Lmpi_comm_rank(LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_comm_size(LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_send(LispObject, LispObject, LispObject,
                            LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_recv(LispObject, LispObject, LispObject,
                            LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_sendrecv(LispObject, LispObject, LispObject,
                                LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_isend(LispObject, LispObject, LispObject,
                             LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_irecv(LispObject, LispObject, LispObject,
                             LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_wait(LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}


static LispObject Lmpi_test(LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_iprobe(LispObject, LispObject, LispObject,
                              LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_probe(LispObject, LispObject, LispObject,
                             LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_barrier(LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_bcast(LispObject, LispObject, LispObject,
                             LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_gather(LispObject, LispObject, LispObject,
                              LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_scatter(LispObject, LispObject, LispObject,
                               LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}


static LispObject Lmpi_allgather(LispObject,
                                 LispObject,
                                 LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_alltoall(LispObject,
                                LispObject, LispObject)
{   SingleValued fn;
    return aerror0("mpi support not built into this version of CSL");
}

#endif // USE_MPI


setup_type const mpi_setup[] =
{   DEF_1("mpi_comm_rank",    Lmpi_comm_rank),
    DEF_1("mpi_comm_size",    Lmpi_comm_size),
    DEF_4up("mpi_send",       Lmpi_send),
    DEF_3("mpi_recv",         Lmpi_recv),
    DEF_4up("mpi_sendrecv",   Lmpi_sendrecv),
    DEF_4up("mpi_isend",      Lmpi_isend),
    DEF_3("mpi_irecv",        Lmpi_irecv),
    DEF_1("mpi_barrier",      Lmpi_barrier),
    DEF_1("mpi_wait",         Lmpi_wait),
    DEF_1("mpi_test",         Lmpi_test),
    DEF_3("mpi_probe",        Lmpi_probe),
    DEF_3("mpi_iprobe",       Lmpi_iprobe),
    DEF_3("mpi_bcast",        Lmpi_bcast),
    DEF_3("mpi_gather",       Lmpi_gather),
    DEF_2("mpi_allgather",    Lmpi_allgather),
    DEF_3("mpi_scatter",      Lmpi_scatter),
    DEF_2("mpi_alltoall",     Lmpi_alltoall),
    {nullptr,                 nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of cslmpi.cpp
