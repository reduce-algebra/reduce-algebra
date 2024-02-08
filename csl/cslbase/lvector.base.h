// lvector.h                                  Copyright (C) A C Norman 2024

// This is intended to behave much as a C++ "T*" pointer except that it
// performs bound checking if DEBUG is defined at compile-time.

/**************************************************************************
 * Copyright (C) 2024, Codemist.                         A C Norman       *
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

#ifndef __header_lvector_h
#define __header_lvector_h 1

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// BEWARE:                                                         //
// Every thread must start by calling ThreadLocal::initialize().   //
// This applies only on Windows where some special handling of     //
// thread-local values is applied here for performance reasons.    //
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// Overview
//
// There are some classes:
//   stkvector<T>   a vector of n items of type T for stack/static allocation.
//   newvector<T>   a vector as above but synamically allocated (eg heap).
//   vecpointer<T>  a pointer to one of the above.

// This is something like what I want...
//== template <typename T>
//== using stkvector<T> = T[];   used in file of block scope definitions.
//== using newvector<T> = T[];   can create a vector using "new" or
//==                             encapsulate one that already exists/
//== using vecpointer<T> = T*;   pointer to one of these.
// however that can not let me establish locally defined vectors
// of dynamic size, and I want to support declarations such as
//         stkvector<int> myLocalArray(std::atoi(argv[1]));
// to set up a block scope vector where the size is not known at
// compile time. Also following
//         vecpointer<int> p = new int[100];
//  or     vecpointer<int> p = newvector<int>(100);
// this would mean I needed to discard the space explicitly.
// Ordinary code uses
//   T* p = new T[20]; ... ; delete[] p;
// here it is necessary to write
//   vecpointer<T> p = new T[20]; ... ; p.discard();
// because overriding "delete[]" suitably is not possible.
//
// I want sizeof(vecpointer<T>) == sizeof(T*). The size of the stkvector
// object is less important: in raw C++ after "int vec[N];" sizeof(vec)
// will be N*sizeof(int) but rather than supporting that I will provide
// a "size()" method to retrieve that information. And I will view
// stkvector as only suitable for use with a compilation unit or block
// scope declaration. "new stkvector" is not to be allowed.
// However "newvector<T>(N)" mau be used to create an vecpointer to
// a heap-allocated vector of length N and that will be preferred to
// use of "new" directly.
//    ...
// stkvector<T> will need to support
//    creation via a declaration at file or block scope.
//    reclamation of all its space at block exit.
//    convert to vecpointer<T>
//    convert to vecpointer<const T> 
//    a function size() [because sizeof on it will not work]
// T must not be a "const" type.

// vecpointer<T> will need to support
//    a default constuctor that makes an uninitialized pointer.
//    a copy constructor.
//    constructor from nullptr.
//    constructor from a T*.
//    constructor from a T* but with a length specifier.
//    construction from a SizedPointer.
//    constructor from an stkvector<T>.
//    a "discard" function for deleting its contents
//    operator*             indirection
//    operator[]            subscripting
//    operator=
//    operator+(integer)
//    operator-(integer)
//    operator+= and operator-=
//    operator++ and operator--  (pre and post versions of each)
//    operator== and operator!= to compare against a nullptr or
//                              another vecpointer<T>
//    casts into T* and const T*
//
// I will require sizeof(vecpointer<T>) == sizeof(T*). I am going to
// assume all pointer types have the same size which C++ may not
// guarantee by all general-purpose versions arrange.

// In non-DEBUG mode I want the use of vecpointer<T> to map onto the
// use of T* so there is no overhead.
//
// In DEBUG mode when an vecpointer will be a pointer to a heap allocated
// vecpointerInfo strucure that has fields
//     T* data;        reference to underlying data
//     size_t limit;   length of the underlying data in units of T
//     size_t offset;  offset within data that is toi be used   
// Any operation that would leave offset>=limit, offset<0 or would
// attempt to access data outside those bounds will raise an exception.
// If the LPointer<T> is created directly from a T* then if no limit is
// given then SIZE_MAX is used.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class vecpointer;

template <typename T>
class newvector
{
public:
    T* data;
    std::size_t limit;
    newvector(size_t n)
    {   data = static_cast<T*>(new T[n]);
        if (data != nullptr)
        {   std::memset(data, 0x99, n*sizeof(T));
            limit = n;
        }
        else limit = 0;
    }
    newvector(T* v, size_t n)
    {   data = v;
        limit = n;
    }
    operator vecpointer<T>()
    {   return vecpointer<T>(data, limit);
    }
    friend std::ostream & operator << (std::ostream &out, const newvector& a)
    {   out << a.data;
        return out;
    }
};

#ifndef DEBUG

template <typename T>
class vecpointer
{
private:
    T* data;
public:

//    a default constuctor
    vecpointer()
    {   data = nullptr;
    }

//    a copy constructor
    vecpointer(const vecpointer<T>& a)
    {   data = a.data;
    }

//    constructor from nullptr
    vecpointer(std::nullptr_t a)
    {   data = nullptr;
    }

//    constructor from a T*
    vecpointer(T* a)
    {   data = a;
    }

//    constructor from a T* but with a length specifier
    vecpointer(T* a, size_t n)
    {   data = a;
    }

//    setsize() - a no-op in this case.
    void setsize(size_t n)
    {}

//    discard()     for deleting its contents
    void discard()
    {   delete [] data;
        data = nullptr;
    }

//    operator*             indirection
    T& operator*()
    {   return *data;
    }
    T operator*() const
    {   return *data;
    }

//    operator[]            subscripting
    T& operator[](size_t n)
    {   return data[n];
    }
    T operator[](size_t n) const
    {   return data[n];
    }

//    operator=
    vecpointer<T>& operator=(newvector<T>& a)
    {   data = a.data;
        return *this;
    }
    vecpointer<T>& operator=(const vecpointer<T> a)
    {   data = a.data;
        return *this;
    }

//    operator+(integer)
    vecpointer<T> operator+(std::ptrdiff_t n)
    {   return vecpointer<T>(data + n);
    }

//    operator-(integer)
    vecpointer<T> operator-(std::ptrdiff_t n)
    {   return vecpointer<T>(data - n);
    }

//    operator+= and operator-=
    vecpointer<T>& operator+=(std::ptrdiff_t n)
    {   data += n;
        return *this;
    }
    vecpointer<T>& operator-=(std::ptrdiff_t n)
    {   data -= n;
        return *this;
    }

//    operator++ and operator--  (pre and post versions of each)
    vecpointer<T>& operator++()
    {   ++data;
        return *this;
    }
    vecpointer<T>& operator--()
    {   --data;
        return *this;
    }
    vecpointer<T> operator++(int)
    {   return vecpointer<T>(data++);
    }
    vecpointer<T> operator--(int)
    {   return vecpointer<T>(data--);
    }

//    operator== and operator!= to compare against a nullptr or
//                              another vecpointer<T>
    bool operator==(std::nullptr_t a)
    {   return data == nullptr;
    }
    bool operator!=(std::nullptr_t a)
    {   return data != nullptr;
    }
    bool operator==(const vecpointer<T> a)
    {   return data == a.data;
    }
    bool operator!=(const vecpointer<T> a)
    {   return data != a.data;
    }

//    casts into T*
    operator T*()
    {   return data;
    }

    operator void*()
    {   return static_cast<void*>(data);
    }

    operator const void*()
    {   return static_cast<const void*>(data);
    }

    operator vecpointer<const T>()
    {   return vecpointer<const T>(data);
    }

    void show()
    {   if (data == nullptr) std::cout << "empty pointer\n";
        else std::cout << "non-debug pointer "
                       << this << "/" << *this << " holds " << data << "\n";
    }
    void show(const char* s)
    {   std::cout << s << ": ";
        show();
    }
    friend std::ostream & operator << (std::ostream &out, const vecpointer& a)
    {   out << a.data;
        return out;
    }
};

#else // DEBUG 

inline void lvector_assert(bool b)
{   if (b) return;
    std::cerr << "\n+++ Access outside vector bound +++\n";
    std::abort();
}

template <typename T>
class vecpointerData
{
// This is a vector "T* data" with length "limit" where the reference into
// it is "offset" units from the start. So at all times we must have
// 0 <= offset < limit.
public:
    T* data;
    size_t limit;
    size_t offset;

// normal constructor
    vecpointerData(T* d, size_t l, size_t o)
    {   data = d;
        limit = l;
        offset = o;
    }

// null-pointer constructor.
    vecpointerData(std::nullptr_t d, size_t l, size_t o)
    {   data = nullptr;
        limit = l;
        offset = o;
    }
    friend std::ostream & operator << (std::ostream &out, const vecpointerData& a)
    {   out << a.data;
        return out;
    }
};

template <typename T>
class vecpointer
{
private:
    vecpointerData<T>* data;
public:

//    a default constuctor
    vecpointer()
    {   data = new vecpointerData<T>(nullptr, 0, 0);
    }

    ~vecpointer()
    {   if (data != nullptr)
        {   delete data;
            data = nullptr;
        }
    }

//    a copy constructor
    vecpointer(const vecpointer<T>& a)
    {   data = new vecpointerData<T>(a.data->data, a.data->limit, a.data->offset);
    }

//    constructor from nullptr
    vecpointer(std::nullptr_t a)
    {   data = new vecpointerData<T>(nullptr, 0, 0);
    }

//    constructor from a T*
    vecpointer(T* a)
    {   data = new vecpointerData<T>(a, SIZE_MAX, 0);
    }

//    constructor from a T* but with a length specifier
    vecpointer(T* a, size_t n)
    {   data = new vecpointerData<T>(a, n, 0);
    }

//    constructor from a T* but with a length specifier and an offset
    vecpointer(T* a, size_t n, size_t o)
    {   data = new vecpointerData<T>(a, n, o);
    }

//    setsize() - may be useful in debug mode.
    void setsize(size_t n)
    {   data->limit = n;
    }

//    discard()     for deleting its contents
    void discard()
    {   delete [] data;
        data = nullptr;
    }

//    operator*             indirection
    T& operator*()
    {   return data->data[data->offset];
    }
    T operator*() const
    {   return data->data[data->offset];
    }

//    operator[]            subscripting
    T& operator[](size_t n)
    {   size_t nn = n + data->offset;
        lvector_assert(nn < data->limit);
        return data->data[nn];
    }
    T operator[](size_t n) const
    {   size_t nn = n + data->offset;
        lvector_assert(nn < data->limit);
        return data->data[nn];
    }

//    operator=
    vecpointer<T>& operator=(const vecpointer<T> a)
    {   data->data = a.data->data;
        data->limit = a.data->limit;
        data->offset = a.data->offset;
        return *this;
    }

//    operator+(integer)
    vecpointer<T> operator+(std::ptrdiff_t n)
    {   size_t nn = n + data->offset;
        lvector_assert(nn < data->limit);
        return vecpointer<T>(data->data, data->limit, nn);
    }

//    operator-(integer)
    vecpointer<T> operator-(std::ptrdiff_t n)
    {   size_t nn = data->offset - n;
        lvector_assert(nn < data->limit);
        return vecpointer<T>(data->data, data->limit, nn);
    }

//    operator+= and operator-=
    vecpointer<T>& operator+=(std::ptrdiff_t n)
    {   data->offset += n;
        lvector_assert(data->offset < data->limit);
        return *this;
    }
    vecpointer<T>& operator-=(std::ptrdiff_t n)
    {   data->offset -= n;
        lvector_assert(data->offset < data->limit);
        return *this;
    }

//    operator++ and operator--  (pre and post versions of each)
    vecpointer<T>& operator++()
    {   ++data->offset;
        lvector_assert(data->offset < data->limit);
        return *this;
    }
    vecpointer<T>& operator--()
    {   --data->offset;
        lvector_assert(data->offset < data->limit);
        return *this;
    }
    vecpointer<T> operator++(int)
    {   lvector_assert(data->offset+1 < data->limit);
        return vecpointer<T>(data->data, data->limit, data->offset++);
    }
    vecpointer<T> operator--(int)
    {   lvector_assert(data->offset >= 1);
        return vecpointer<T>(data->data, data->limit, data->offset--);
    }

//    operator== and operator!= to compare against a nullptr or
//                              another vecpointer<T>
    bool operator==(std::nullptr_t a)
    {   return data->data == nullptr;
    }
    bool operator!=(std::nullptr_t a)
    {   return data->data != nullptr;
    }
    bool operator==(const vecpointer<T> a)
    {   return data->data == a.data->data &&
               data->offset == a.data->offset;
    }
    bool operator!=(const vecpointer<T> a)
    {   return data->data != a.data->data ||
               data->offset != a.data->offset;
    }

//    casts into T*
    operator T*()
    {   return &data->data[data->offset];
    }

    operator void*()
    {   return static_cast<void*>(&data->data[data->offset]);
    }

    operator const void*()
    {   return static_cast<const void*>(&data->data[data->offset]);
    }

    operator vecpointer<const T>()
    {   return vecpointer<const T>(data->data, data->limit, data->offset);
    }

// show() is really just for debugging.
    void show()
    {   if (data == nullptr) std::cout << "empty pointer\n";
        else
        {   std::cout << "debug pointer " << this << "/" << *this
                      << " holds " << data << "\n";
            std::cout << data->data << " " << data->limit
                      << " " << data->offset << "\n";
        }
    }
    void show(const char* s)
    {   std::cout << s << ": ";
        show();
    }
    friend std::ostream & operator << (std::ostream &out, const vecpointer& a)
    {   out << a.data;
        return out;
    }
};

#endif // DEBUG


//=========================================================================

// Here I want to be able to allocate a vector such that it is
// automatically discarded when it goes out of scope, but I want
// as little overhead as I can manage. I could use std::unique_ptr
// to get the "auto-delete" functionality but I am not fully confident
// that the C++ storage management overheads will be truly small. What
// I do here is I allocate a vector and maintain a record of its size
// and a fringe. If an allocation request will fit I just allocate at the
// fringe. If not I will new "new" to grab a fresh vector that is at least
// twice the size of the existing one and also big enough for the request.
// I must not delete the existing chunk since data within it is still in
// use. So all allocated vectors are places in a "recycleBin" that
// arranges deletion when the program terminates. Because expansion
// allocated new blocks twice the size of a previous one even in the
// worst case will be that these orphaned vectors only take up as much
// space as the current active chunk. This could be viewed as a factor
// of 2 waste - I consider it acceptable.
// When a local vector is done with the fringe gets decreased by its
// size (so I need to have recorded its size). The case fringe==0 when
// deletion is attempted corresponds to discarding a block of memory in
// one of the vectors that are in the recycle bin, and I do not need to
// so anything.
// I allocate in bytes in an "char[]" array so that I only use one pool
// of memory across all types of object allocated, but then there may
// still need to be one pool per thread. I only support allocation
// aligned up to std::max_align_t, so anybody with over-aligned data should
// beware.

// The following structure contains everything a thread needs to manage
// its allocation. So a thread_local instance of it will cope with
// everything I do.

#include <vector>

#include "threadloc.h"

class allocationInfoStruct
{
public:
    char* chunk;
    size_t currentChunkSize;
    size_t fringe;
    std::vector<char*> listOfPointers;
    void discard(char* v) { listOfPointers.push_back(v); }
    ~allocationInfoStruct()
    {   for (auto v:listOfPointers) delete [] v;
    }
};

constexpr inline int TL_allocationInfoPtr=63;
DEFINE_INLINE_THREAD_LOCAL(allocationInfoStruct, allocationInfoPtr)

template <typename T>
class stkvector
{
private:
    size_t oldFringe;
public:
    T* data;
#ifdef DEBUG
    size_t limit;
#endif // DEBUG

// default constructor
    stkvector()
    {   data = nullptr;
#ifdef DEBUG
        limit = 0;
#endif // DEBUG
    }

// Create an stkvector of size n.
    stkvector(size_t n)
    {
#ifdef DEBUG
        limit = n;
#endif // DEBUG
        size_t nbytes = n*sizeof(T);
// Ensure that the block I allocate will have size that is a multiple of
// max_align even if T would be happy with less allignment - so that the
// next allocation will be properly aligned whatever it is.
        if constexpr (alignof(T) < alignof(std::max_align_t))
            nbytes = (nbytes+alignof(std::max_align_t)-1) & -alignof(std::max_align_t);
// If the current chunk does not have anough space I will allocate another
// bigger one.
        if (allocationInfoPtr->fringe+nbytes > allocationInfoPtr->currentChunkSize)
        {   size_t newChunkSize =
                std::max(nbytes, 2*allocationInfoPtr->currentChunkSize);
            allocationInfoPtr->chunk = new char[newChunkSize];
            allocationInfoPtr->currentChunkSize = newChunkSize;
// Arrange that the chunk will eventually be deleted... typically when the
// program terminates but in a thread context when the thread terminates.
            allocationInfoPtr->discard(allocationInfoPtr->chunk);
            allocationInfoPtr->fringe = 0;
        }
        data = reinterpret_cast<T*>(
            allocationInfoPtr->chunk+allocationInfoPtr->fringe);
        oldFringe = allocationInfoPtr->fringe;
        allocationInfoPtr->fringe = oldFringe + nbytes;
#ifdef DEBUG
        std::memset(data, 0x99, nbytes);
        limit = n;
#endif // DEBUG
    }

// new (not permitted)
    void* operator new(std::size_t n) = delete;

// delete (not permitted)
    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;

// destructor
    ~stkvector()
    {
// Note that fringe could be zero if this vector is in an "old"
// chunk. fringe is just used within the current chunk.
        if (allocationInfoPtr->fringe != 0)
            allocationInfoPtr->fringe = oldFringe;
    }

// convert to vecpointer
    operator vecpointer<T>()
    {
#ifdef DEBUG
        return vecpointer<T>(data, limit, 0);
#else // DEBUG
        return vecpointer<T>(data);
#endif // DEBUG
    }
    operator vecpointer<const T>()
    {
#ifdef DEBUG
        return vecpointer<const T>(data, limit, 0);
#else // DEBUG
        return vecpointer<const T>(data);
#endif // DEBUG
    }

    vecpointer<T> operator+(size_t n)
    {
#ifdef DEBUG
        return vecpointer<T>(data, limit, n);
#else // DEBUG
        return vecpointer<T>(data+n);
#endif // DEBUG
    }

// convert to T*
    operator T*()
    {   return data;
    }
    operator const T*()
    {   return data;
    }
    operator void*()
    {   return static_cast<void*>(data);
    }

//    operator[]            subscripting
    T& operator[](size_t n)
    {
#ifdef DEBUG
        lvector_assert(n < limit);
#endif // DEBUG
        return data[n];
    }
    T operator[](size_t n) const
    {
#ifdef DEBUG
        lvector_assert(n < limit);
#endif // DEBUG
        return data[n];
    }

//    operator*            subscripting
    T& operator*()
    {
#ifdef DEBUG
        lvector_assert(limit != 0);
#endif // DEBUG
        return data[0];
    }
    T operator*() const
    {
#ifdef DEBUG
        lvector_assert(limit != 0);
#endif // DEBUG
        return data[0];
    }

// retport size
    size_t size()
    {
#ifdef DEBUG
        return limit;
#else // DEBUG
        return SIZE_MAX;
#endif // DEBUG
    }
    friend std::ostream & operator << (std::ostream &out, const stkvector& a)
    {   out << a.data;
        return out;
    }
};

#endif // __header_lvector_h

// end of lvector.h
