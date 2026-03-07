// winsupport.cpp                               Copyright (C) 2026 Codemist

// $Id: winsupport.cpp 5728 2021-03-13 14:54:03Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

// Code that needs <windows.h>, separated out into this file because
// <windows.h> clashes with some of the Cygwin header files that I have
// included generally.

#include "config.h"

#ifdef WIN32

#include "log.h"
#include "machine.h"
#include "threadloc.h"
#include "mymutex.h"

#if HAVE_LIBWX
#include "wxfwin.h"
#else
#include "fwin.h"
#endif

#include "termed.h"
#include "bitmaps.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "proc.h"
#include "stream.h"
#include "syscsl.h"
#include "lispthrow.h"

#include <cstdio>
#include <cstring>
#include <cstddef>
#include <cstdint>

#include <windows.h>
#include <winsock.h>
#include <process.h>

HANDLE gnuplot_process = 0;
HWND gnuplot_handle = 0;
bool gnuplotActive = false;

class GnuplotClass
{
public:
    GnuplotClass()
    {   gnuplotActive = false;
    }
    ~GnuplotClass()
    {   if (gnuplotActive)
            TerminateProcess(gnuplot_process, 0);
    }
};

#include "winsupport.h"

namespace CSL_LISP
{

using namespace FX;

extern struct NilBlock myNilBlock;
inline LispObject& lisp_true = myNilBlock.Ilisp_true;

void win32_stacklimit(uintptr_t &stacklimit)
{   HMODULE h = GetModuleHandle(nullptr); // For current executable
    if (h != nullptr)
    {   IMAGE_DOS_HEADER *dh = (IMAGE_DOS_HEADER*)h;
        IMAGE_NT_HEADERS *NTh =
            (IMAGE_NT_HEADERS*)((BYTE*)dh + dh->e_lfanew);
        int64_t maxStackSize =
            (int64_t)NTh->OptionalHeader.SizeOfStackReserve;
// If the limit recovered above is under 200K I will pretend it is
// just plain wrong and increase it to that. The effect may be that I
// end up with an untidy stack overflow but at least I get closer to
// using all the space that I have.
        if (maxStackSize < 200*1024) maxStackSize = 200*1024;
// I also assume that any figure over 20 Mbytes is a mess so ignore it
        if (maxStackSize <= 20*1024*1024)
        {   // I try to give myself 64K spare...
            stacklimit = C_stackBase - maxStackSize + 0x10000;
        }
    }
}

size_t getMemorySize()
{   MEMORYSTATUSEX s;
    s.dwLength = sizeof(s);
    GlobalMemoryStatusEx(&s);
    return s.ullTotalPhys;
}

int windowsGetPid()
{   return _getpid();
}

static char error_name[32];

const char *WSAErrName(int i)
{   switch (i)
    {   default:                 std::snprintf(error_name, sizeof(error_name),
                                              "Socket error %d", i);
                                 return error_name;
        case WSAEINTR:           return "WSAEINTR";
        case WSAEBADF:           return "WSAEBADF";
        case WSAEACCES:          return "WSAEACCES";
#ifdef WSAEDISCON
        case WSAEDISCON:         return "WSAEDISCON";
#endif
        case WSAEFAULT:          return "WSAEFAULT";
        case WSAEINVAL:          return "WSAEINVAL";
        case WSAEMFILE:          return "WSAEMFILE";
        case WSAEWOULDBLOCK:     return "WSAEWOULDBLOCK";
        case WSAEINPROGRESS:     return "WSAEINPROGRESS";
        case WSAEALREADY:        return "WSAEALREADY";
        case WSAENOTSOCK:        return "WSAENOTSOCK";
        case WSAEDESTADDRREQ:    return "WSAEDESTADDRREQ";
        case WSAEMSGSIZE:        return "WSAEMSGSIZE";
        case WSAEPROTOTYPE:      return "WSAEPROTOTYPE";
        case WSAENOPROTOOPT:     return "WSAENOPROTOOPT";
        case WSAEPROTONOSUPPORT: return "WSAEPROTONOSUPPORT";
        case WSAESOCKTNOSUPPORT: return "WSAESOCKTNOSUPPORT";
        case WSAEOPNOTSUPP:      return "WSAEOPNOTSUPP";
        case WSAEPFNOSUPPORT:    return "WSAEPFNOSUPPORT";
        case WSAEAFNOSUPPORT:    return "WSAEAFNOSUPPORT";
        case WSAEADDRINUSE:      return "WSAEADDRINUSE";
        case WSAEADDRNOTAVAIL:   return "WSAEADDRNOTAVAIL";
        case WSAENETDOWN:        return "WSAENETDOWN";
        case WSAENETUNREACH:     return "WSAENETUNREACH";
        case WSAENETRESET:       return "WSAENETRESET";
        case WSAECONNABORTED:    return "WSAECONNABORTED";
        case WSAECONNRESET:      return "WSAECONNRESET";
        case WSAENOBUFS:         return "WSAENOBUFS";
        case WSAEISCONN:         return "WSAEISCONN";
        case WSAENOTCONN:        return "WSAENOTCONN";
        case WSAESHUTDOWN:       return "WSAESHUTDOWN";
        case WSAETOOMANYREFS:    return "WSAETOOMANYREFS";
        case WSAETIMEDOUT:       return "WSAETIMEDOUT";
        case WSAECONNREFUSED:    return "WSAECONNREFUSED";
        case WSAELOOP:           return "WSAELOOP";
        case WSAENAMETOOLONG:    return "WSAENAMETOOLONG";
        case WSAEHOSTDOWN:       return "WSAEHOSTDOWN";
        case WSAEHOSTUNREACH:    return "WSAEHOSTUNREACH";
        case WSASYSNOTREADY:     return "WSASYSNOTREADY";
        case WSAVERNOTSUPPORTED: return "WSAVERNOTSUPPORTED";
        case WSANOTINITIALISED:  return "WSANOTINITIALISED";
        case WSAHOST_NOT_FOUND:  return "WSAHOST_NOT_FOUND";
        case WSATRY_AGAIN:       return "WSATRY_AGAIN";
        case WSANO_RECOVERY:     return "WSANO_RECOVERY";
        case WSANO_DATA:         return "WSANO_DATA";
    }
}

int windowsPrepareSockets()
{
#ifdef SOCKETS
// Under Windows the socket stuff is not automatically active, so some
// system calls have to be made at the start of a run. I demand a
// Winsock 1.1, and fail if that is not available.
    WSADATA wsadata;
    int i = WSAStartup(MAKEWORD(1,1), &wsadata);
    if (i != 0) return i;   /* Failed to start winsock for some reason */;
    if (LOBYTE(wsadata.wVersion) != 1 ||
        HIBYTE(wsadata.wVersion) != 1)
    {   WSACleanup();
        return 1;      // Version 1.1 of winsock needed
    }
#endif
    return 0;
}

static GnuplotClass gnuplotAlive;

BOOL CALLBACK find_text(HWND h, LPARAM)
{   char buffer[24];
    GetClassName(h, buffer, 20);
    if (std::strcmp(buffer, "wgnuplot_text") != 0) return TRUE;
    gnuplot_handle = h;
    return FALSE;
}

FILE *windowsFindGnuplot(const char *command, const char *direction)
{   int i = 0;
// The following test would trigger if the string "wgnuplot.exe" was present
// within the path even if it was not the final component. I think that at
// present I will take the view that anybody who finds themselves hurt because
// of that has only themselves to blame.
    if (std::strstr(command, "wgnuplot.exe") != nullptr)
    {   HWND parent = 0;
// Win32 would rather I used the following long-winded version, which provides
// a pile of generality that is irrelevant here!
        STARTUPINFO startup;
        PROCESS_INFORMATION process;
        char c1[LONGEST_LEGAL_FILENAME];
        std::clock_t t0, t1;
        std::memset(&startup, 0, sizeof(STARTUPINFO));
        startup.cb = sizeof(startup);
        startup.lpReserved = nullptr;
        startup.lpDesktop = nullptr;
        startup.lpTitle = nullptr;
        startup.dwFlags = STARTF_USESHOWWINDOW;
        startup.wShowWindow = SW_SHOWMINIMIZED;
        startup.cbReserved2 = 0;
        startup.lpReserved2 = nullptr;
        std::strncpy(c1, command, sizeof(c1));
        c1[sizeof(c1)-1] = 0;
        if (!CreateProcess(nullptr, c1, nullptr, nullptr, FALSE,
                           0, nullptr, nullptr, &startup, &process))
            return nullptr;
        gnuplot_process = process.hProcess;
        gnuplotActive = true;
        gnuplot_handle = 0;
        t0 = std::clock();
        for (i=0; i<25; i++)  // Give it 5 seconds to appear
        {   parent = FindWindow((LPSTR)"wgnuplot_parent",
                                (LPSTR)"gnuplot");
            if (parent != 0) break;
            t0 += CLOCKS_PER_SEC/5;
            while ((t1 = std::clock()) < t0) ; // a busy-wait here
            t0 = t1;
        }
        if (parent != 0)
        {   for (i=0; i<10; i++)   // 2 more seconds for the child
            {   EnumChildWindows(parent, find_text, 0);
                if (gnuplot_handle != 0) break;
                t0 += CLOCKS_PER_SEC/5;
                while ((t1 = std::clock()) < t0) ; // busy-wait
                t0 = t1;
            }
        }
        // special handle for the gnuplot pipe
        return reinterpret_cast<std::FILE *>(-1);
    }
    return _popen(command, direction);
}

#ifdef HAVE_PUTC_UNLOCKED
#define PUTC(x, y) putc_unlocked((x), (y))
#elif defined HAVE__PUTC_NOLOCK
#define PUTC(x, y) _putc_nolock((x), (y))
#else
#define PUTC(x, y) putc((x), (y))
#endif // unlocked putc variants with or without initial "_"


int my_pipe_putc(int c, std::FILE *f)
{   if (f == (std::FILE *)(-1))
    {   if (gnuplot_handle == 0) return EOF;
        if (c == '\n') c = '\r';
        SendMessage(gnuplot_handle, WM_CHAR, c, 1L);
        return c;
    }
    else return PUTC(c, f);
}

int my_pipe_flush(std::FILE *f)
{
    if (f == (std::FILE *)(-1)) return 0;
    return std::fflush(f);
}

void my_pclose(std::FILE *stream)
{
    if (stream == (std::FILE *)(-1))
    {   SendMessage(gnuplot_handle, WM_CHAR, 'q', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'u', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'i', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 't', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, '\r', 1L);
        return;
    }
    _pclose(stream);
}

int windowsFindGnuplot1(char *name)
{   HKEY keyhandle;
// I need to use RegQueryValueEx here rather than RegGetValue if I am to
// support 32-bit Windows XP. Note that buffer overflow in the path to
// gnuplot could leave an unterminated string, but that should not happen
// here.
    DWORD length = LONGEST_LEGAL_FILENAME, type;
    LONG r = RegOpenKeyEx(
                 HKEY_LOCAL_MACHINE,
                 "Software\\Microsoft\\Windows\\CurrentVersion\\"
                     "App Paths\\gnuplot.exe",
                 0,
                 KEY_QUERY_VALUE,
                 &keyhandle);
    if (r == ERROR_SUCCESS)
    {   r = RegQueryValueEx(keyhandle,
                            nullptr,
                            nullptr,
                            (LPDWORD)&type,
                            (LPBYTE)name,
                            (LPDWORD)&length);
        name[LONGEST_LEGAL_FILENAME-1] = 0;
        if (r == ERROR_SUCCESS) return 1;
    }
    return 0;
}

size_t windowsGetTempPath(size_t n, char *s)
{   return GetTempPath(n, s);
}

LispObject Lopen_foreign_library(LispObject env, LispObject name)
{   SingleValued fn;
    HANDLE a;
    LispObject r;
    char libname[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    char *w2, *w1 = nullptr;
    std::memset(libname, 0, sizeof(libname));
    w = get_string_data(name, "find-foreign-library", len);
    if (len > sizeof(libname)-5) len = sizeof(libname)-5;
    std::snprintf(libname, sizeof(libname), "%.*s", static_cast<int>(len), w);
    for (w2=libname; *w2!=0; w2++)
        if (w1==nullptr && *w2 == '.') w1 = w2;
        else if (*w2 == '/' || *w2 == '\\') w1 = nullptr;
// Now of w1 is not nullptr it identifies a suffix ".xxx" where there is no
// "/" or "\\" in the string xxx. A suffix such as ".so.1.3.2" is reported as
// a whole despite the embedded dots.
// On Windows if no suffix is provided a ".dll" will be appended, while
// on other systems ".so" is used.
    if (w1 == nullptr) std::strcat(libname, ".dll");
    for (w1=libname; *w1!=0; w1++)
        if (*w1 == '/') *w1 = '\\';
// For now I will leave the trace print of the library name here, since
// it should only appear once per run so ought not to cause over-much grief.
// eventually I will remove it!
#ifdef DEBUG
    std::printf("open-library Windows %s\n", libname);
#endif
    a = LoadLibrary(libname);
    if (a == 0)
    {
#ifdef DEBUG
        DWORD err = GetLastError();
        char errbuf[80];
// The printf calls here to report errors will not be useful in some
// windowed contexts, so I will need to rework them in due course.
        std::printf("Error code %ld = %lx\n", static_cast<long>(err),
                    static_cast<long>(err));
        err = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
                            FORMAT_MESSAGE_IGNORE_INSERTS,
                            nullptr, err, 0, errbuf, 80, nullptr);
        if (err != 0) std::printf("%s", errbuf);
#endif
        return nil;
    }
    r = encapsulate_pointer(reinterpret_cast<void *>(a));
    return r;
}

// (setq entrypoint (find!-foreign!-function "fname" libobject))
// Using a library opened by open!-foreign!-library look up an entrypoint
// for a function called "fname". If one can not be found return nil.

LispObject Lfind_foreign_function(LispObject env, LispObject name,
                                  LispObject lib)
{   SingleValued fn;
    LispObject r;
    void *b;
    const char *w;
    char sname[100];
    size_t len = 0;
    HMODULE a;
    if (Lencapsulatedp(nil, lib) == nil)
        return aerror("find-foreign-function");
    a = (HMODULE)extract_pointer(lib);
    w = get_string_data(name, "find-foreign-function", len);
    if (len > sizeof(sname)-2) len = sizeof(sname)-2;
    std::snprintf(sname, sizeof(sname), "%.*s", static_cast<int>(len), w);
//=== #ifdef __CYGWIN__
//===     printf("name to look up = %s\r\n", sname);
//=== #else
//===     printf("name to look up = %s\n", sname);
//=== #endif
#ifdef EMBEDDED
    b = nullptr;
#else
    b = reinterpret_cast<void *>(GetProcAddress(a, sname));
#endif
    if (b == nullptr) return nil;
    r = encapsulate_pointer(b);
// Observe that the result is an encapsulated pointer to the entrypoint of the
// function that you are interested in.
    return r;
}

// On Windows this version takes the trouble to avoid letting the
// application that you are running pop up a visible console window.

LispObject Lsilent_system(LispObject env, LispObject a)
{   SingleValued fn;
    char cmd[LONGEST_LEGAL_FILENAME];
#ifdef SHELL_EXECUTE
    char args[LONGEST_LEGAL_FILENAME];
#endif
    Header h;
    std::memset(cmd, 0, sizeof(cmd));
#ifdef SHELL_EXECUTE
    std::memset(args, 0, sizeof(args));
#endif
    if (a == nil)            // enquire if command processor is available
        return lisp_true; // always is on Windows!
    ensure_screen();
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        h = vechdr(a);
    }
    else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        return aerror1("system", a);
    ensure_screen();
    size_t len = length_of_byteheader(h) - CELL;
    std::memcpy(cmd, reinterpret_cast<char *>(a) + (CELL-TAG_VECTOR),
                (size_t)len);
    cmd[len] = 0;
#ifdef SHELL_EXECUTE
// ShellExecute works for me and allows me to launch an application with
// its console hidden - but it does not give an opportunity to wait until
// the command that was executed has completed. I will leave this code
// here for now since I may find I want to re-use it (eg for opening
// documents). But the code below that explicitly creates a process is
// what I really need here.
    size_t i = 0;
    while (cmd[i]!=' ' && cmd[i]!=0) i++;
    if (cmd[i]==0) args[0] = 0;
    else
    {   cmd[i] = 0;
        std::strcpy(args, &cmd[i+1]);
    }
    int rc = ShellExecute(nullptr,
                          "open",
                          cmd,
                          args,
                          ".",
                          SW_HIDE);
    ensure_screen();
    return fixnum_of_int(rc);
#else
    {   STARTUPINFO startup;
        PROCESS_INFORMATION process;
        DWORD rc;
        std::memset(&startup, 0, sizeof(startup));
        startup.cb = sizeof(startup);
        startup.dwFlags = STARTF_USESHOWWINDOW;
        startup.wShowWindow = SW_HIDE;
        std::memset(&process, 0, sizeof(process));
        if (!CreateProcess(nullptr, cmd, nullptr, nullptr, FALSE,
                           CREATE_NEW_CONSOLE,
                           nullptr, nullptr, &startup, &process))
        {   return nil;
        }
        WaitForSingleObject(process.hProcess, INFINITE);
// If I fail to retrieve a true exit code I will return the value 1000. This
// is pretty arbitrary, but I expect 0 to denote success and 1000 to be an
// unusual "genuine" return code
        if (!GetExitCodeProcess(process.hProcess, &rc)) rc = 1000;
        CloseHandle(process.hProcess);
        CloseHandle(process.hThread);
        ensure_screen();
        return fixnum_of_int(rc);
    }
#endif
}


LispObject Lgetpid(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(windowsGetPid());
}

bool sockets_ready = false;

int ensure_sockets_ready()
{   if (!sockets_ready)
    {   if (windowsPrepareSockets() != 0) return 1;
        sockets_ready = true;
    }
    return 0;
}

#ifdef SOCKETS

#include "sockhdr.h"

#define SOCKET_BUFFER_SIZE 256

// A stream attached to a socket is represented by putting the socket handle
// into the field that would otherwise hold a FILE. The stream_read_data
// field then holds a string. The first 4 characters of this contain
// two packed integers saying how much buffered data is available,
// and then there is just a chunk of buffered text.

int char_from_socket(LispObject stream)
{   int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {   LispObject w = stream_read_data(stream);
        int32_t sb_data = ielt32(w, 0);
        int sb_start = sb_data & 0xffff, sb_end = (sb_data >> 16) & 0xffff;
// Note use of ucelt in the next line even if char is a signed type. This
// is because getc() etc are expected to return an UNSIGNED char cast to
// an int.
        if (sb_start != sb_end) ch = ucelt(w, sb_start++);
        else
        {   ch = recv((SOCKET)(intptr_t)(FILE *)stream_file(stream),
                      reinterpret_cast<char *>(&celt(w, 4)), SOCKET_BUFFER_SIZE, 0);
            if (ch == 0) return EOF;
            if (ch == SOCKET_ERROR)
            {   err_printf("socket read error (%s)\n",
                           WSAErrName(WSAGetLastError()));
                return EOF;
            }
            sb_start = 5;
            sb_end = ch + 4;
            ch = ucelt(w, 4);
        }
        sb_data = sb_start | (sb_end << 16);
        ielt32(w, 0) = sb_data;
        return ch;
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

// Seek and tell will be just quiet no-ops on socket streams.

int32_t read_action_socket(int32_t op, LispObject f)
{   if (op < -1) return 0;
    else if (op <= 0xff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                if ((FILE *)stream_file(f) == nullptr) op = 0;
                else
                    op = closesocket(
                             (SOCKET)(intptr_t)(FILE *)stream_file(f));
                stream_read_fn(f) = char_from_illegal;
                stream_read_other(f) = read_action_illegal;
                stream_file(f) = nullptr;
                stream_read_data(f) = nil;
                return op;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            default:
                return 0;
        }
}


int fetch_response(char *buffer, LispObject r)
{   size_t i;
    for (i = 0; i<LONGEST_LEGAL_FILENAME; i++)
    {   int ch = char_from_socket(r);
        if (ch == EOF) return 1;
        buffer[i] = static_cast<char>(ch);
        if (ch == 0x0a)
        {   buffer[i] = 0;
// The keys returned at the start of a response line are supposed to be
// case insensitive, so I fold things to lower case right here.
            for (i=0; buffer[i]!=0 && buffer[i]!=' '; i++)
                buffer[i] = static_cast<char>(std::tolower(static_cast<unsigned char>
                                              (buffer[i])));
            return 0;
        }
    }
    return 1; // fail if response was over-long
}

LispObject Lopen_url(LispObject env, LispObject url)
{   SingleValued fn;
    char filename[LONGEST_LEGAL_FILENAME],
    filename1[LONGEST_LEGAL_FILENAME], *p;
    const char *user, *pass, *proto, *hostaddr, *port, *path;
    size_t  nuser, npass, nproto, nhostaddr, nport, npath;
    size_t len = 0;
    struct hostent *host;
    unsigned long int hostnum;
    SOCKET s;
    size_t i;
    int retcode, retry_count=0;
    LispObject r;
    const char *w = get_string_data(url, "open-url", len);
    std::memset(filename, 0, sizeof(filename));
    std::memset(filename1, 0, sizeof(filename1));

start_again:

    if (len >= sizeof(filename)) len = sizeof(filename)-1;
    std::memcpy(filename, w, len);
    filename[len] = 0;
// I want to parse the URL. I leave the result as a collection of
// pointers (usually to the start of text within the URL itself, but
// sometimes elsewhere, together with lengths of the substrings as found.
    user = pass = proto = hostaddr = port = path = " ";
    nuser = npass = nproto = nhostaddr = nport = npath = 0;
    p = filename;
// If the start of the URL is of the form "xyz:" with xyz alphanumeric
// then that is a protocol name, and I will force it into lower case.
    for (i=0; i<len; i++)
        if (!std::isalnum(static_cast<unsigned char>(p[i]))) break;
    if (p[i] == ':')
    {   char *oldp = p;
        proto = p;
        nproto = i;   // Could still be zero!
        p += i+1;
        len -= i+1;
        for (i=0; i<nproto; i++)
            oldp[i] = static_cast<char>(std::tolower(static_cast<unsigned char>
                                        (oldp[i])));
    }
// After any protocol specification I may have a host name, introduced
// by "//".
    if (p[0] == '/' && p[1] == '/')
    {   p += 2;
        len -= 2;
// If the URL (sans protocol) contains a "@" then I will take it to be
// in the form
//      user:password@hostaddr/...
// and will split the user bit off. This will be particularly used in the
// case of FTP requests. The password will be allowed to contain ":" and
// "@" characters. Furthermore I will also allow the password to be
// enclosed in quote marks ("), although since I scan for the "@" from
// the right and for the ":" from the left these are not needed at all,
// so if I notice them here all I have to do is to discard them!
        for (i=len; i>0; i--)
            if (p[i-1] == '@') break;
        if (i > 0)
        {   i--;
            user = p;
            p += i+1;
            len -= i+1;
            while (user[nuser] != ':' && user[nuser] != '@') nuser++;
            if (user[nuser] == ':')
            {   pass = user+nuser+1;
                npass = i - nuser - 1;
                if (pass[0] == '"' && pass[npass-1] == '"')
                    pass++, npass -= 2;
            }
        }
// Now what is left is a host, port number and path, written as
//     hostaddr:port/... but note that the "/" should be treated as
// part of the path-name.
        hostaddr = p;
        for (;;)
        {   switch (hostaddr[nhostaddr])
        {       default:
                    nhostaddr++;
                    continue;
                case '/':
                    p += nhostaddr;
                    len -= nhostaddr;
                    break;
                case 0: len = 0;
                    break;
                case ':':        // port number given
                    port = hostaddr+nhostaddr+1;
                    for (;;)
                    {   switch (port[nport])
                    {       default:
                                nport++;
                                continue;
                            case '/':
                                p += nhostaddr + nport + 1;
                                len -= nhostaddr + nport + 1;
                                break;
                            case 0: len = 0;
                                break;
                        }
                        break;
                    }
                    break;
            }
            break;
        }
    }
    path = p;
    npath = len;
    if (npath == 0) path = "/", npath = 1;  // Default path
// If a protocol was not explicitly given I will try to deduce one from the
// start of the name of the hostaddr. Failing that I will just use a default.
    if (nproto == 0)
    {   if (std::strncmp(hostaddr, "www.", 4) == 0 ||
            std::strncmp(hostaddr, "wwwcgi.", 7) == 0)
        {   proto = "http";
            nproto = 4;
        }
        else
        {   proto = "ftp";
            nproto = 3;
        }
    }
// If the user gave an explicit port number I will try to use it. If the
// port was not numeric I ignore it and drop down to trying to use
// a default port based on the selected protocol.
    if (nport != 0)
    {   int w;
        std::memcpy(filename1, port, nport);
        filename1[nport] = 0;
        if (std::sscanf(filename1, "%d", &w) == 1) nport = w;
        else nport = 0;
    }
    if (nport == 0)
    {   if (nproto == 3 && std::memcmp(proto, "ftp", 3) == 0) nport = 21;
        else if (nproto == 4 &&
                 std::memcmp(proto, "http", 4) == 0) nport = 80;
// Elsewhere I have code that can call on an external "scp" program to support
// a secure-fetch scheme, but I will NOT include that here.
        else return aerror("Unknown protocol");
    }
// If no host-name was given then the object concerned is on the
// local machine. This is a funny case maybe, but I will just chain
// through and open it as an ordinary file (without regard to
// protocol etc).
    if (nhostaddr == 0)
    {   FILE *file = open_file(filename1, path, static_cast<size_t>(npath), "r",
                                    nullptr);
        if (file == nullptr) return nil;
        r = make_stream_handle();
        errexit();
        stream_type(r) = url;
        stream_file(r) = file;
        stream_read_fn(r) = char_from_file;
        stream_read_other(r) = read_action_file;
        return r;
    }
    if (nproto == 3 && std::strcmp(proto, "ftp") == 0 && nuser == 0)
    {   user = "anonymous";
        nuser = std::strlen(user);
        if (npass == 0)
        {   pass = "acn1@cam.ac.uk";
            npass = std::strlen(pass);
        }
    }
#ifdef DEBUG
// The trace print here is not needed in the long term but certainly
// helps while I am doing initial tests.
    trace_printf(
        "User <%.*s> Pass <%.*s> Proto <%.*s>\n"
        "Host <%.*s> Port <%d> Path <%.*s>\n",
        nuser, user, npass, pass, nproto, proto,
        nhostaddr, hostaddr, nport, npath, path);
#endif
    if (ensure_sockets_ready() != 0) return nil;
    std::memcpy(filename1, hostaddr, nhostaddr);
    filename1[nhostaddr] = 0;
// I try to accept either "." form or named host specifications
    hostnum = inet_addr(filename1);
    if (hostnum == INADDR_NONE)
    {   host = gethostbyname(filename1);
        if (host != nullptr)
            hostnum = ((struct in_addr *)host->h_addr)->s_addr;
    }
    if (hostnum == INADDR_NONE)
    {   err_printf("Host not found (%s)\n",
                   WSAErrName(WSAGetLastError()));
        return nil;
    }
    s = socket(PF_INET, SOCK_STREAM, 0);  // Make a new socket
    {   struct sockaddr_in sockin;
        std::memset(&sockin, 0, sizeof(sockin));
        sockin.sin_family = AF_INET;
        sockin.sin_port = htons(nport);
        sockin.sin_addr.s_addr = hostnum;
// Because there can be quite tedious delays in network fetches I will
// log that I am trying to make contact.
        trace_printf("Contacting %.*s...\n", nhostaddr, hostaddr);
        ensure_screen();
        if (connect(s, (struct sockaddr *)&sockin,
                    sizeof(sockin)) == SOCKET_ERROR)
        {   err_printf("connect failed %s\n", WSAErrName(WSAGetLastError()));
            closesocket(s);
            return nil;
        }
        trace_printf("Connection created\n");
    }
    std::snprintf(filename1, sizeof(filename1),
                  "GET %.*s HTTP/1.0\x0d\x0a\x0d\x0a",
                  static_cast<int>(npath), path);

// MD addition from webcore.c
    i = std::strlen(filename1);
// Certainly if the Web server I am accessing is the one that comes as
// standard with Windows NT I need to reassure it that I want the document
// returned to me WHATEVER its media type is. If I do not add in the
// line "Accept: *|*" the GET request will only allow me to fetch simple
// text (?)
// Note that above I write "*|*" where I only really mean a "/" in the
// middle but where C comment conventions intrude!
    std::snprintf(&filename1[i], 20, "Accept: */*\x0d\x0a\x0d\x0a");

    if (send(s, filename1, std::strlen(filename1), 0) == SOCKET_ERROR)
    {   err_printf("Send error (%s)\n", WSAErrName(WSAGetLastError()));
        closesocket(s);
        return nil;
    }

    r = make_stream_handle();
    errexit();
    stream_type(r) = url;
    url = get_basic_vector(TAG_VECTOR, TYPE_STRING_4,
                           CELL+4+SOCKET_BUFFER_SIZE);
    errexit();
    ielt32(url, 0) = 0;
    stream_read_data(r) = url;
    stream_file(r) = (FILE *)(intptr_t)s;
    stream_read_fn(r) = char_from_socket;
    stream_read_other(r) = read_action_socket;

// Now fetch the status line.
    if (fetch_response(filename1, r))
    {   err_printf("Error fetching status line from the server\n");
        Lclose(env,r);
        return nil;
    }

// I check if the first line returned is in the form "HTTP/n.n nnn " and if
// it is not I assume that I have reached an HTTP/0.9 server and all the
// text that comes back will be the body.
    {   int major, minor;
// I will not worry much about just which version of HTTP the system reports
// that it is using, provided it says something! I expect to see the return
// code as a three digit number. I verify that it is in the range 0 to 999 but
// do not check for (and thus reject) illegal responses such as 0000200.
        if (std::sscanf(filename1,
                        "http/%d.%d %d", &major, &minor, &retcode) != 3 ||
            retcode < 0 || retcode > 999)
        {   err_printf("Bad protocol specification returned\n");
            err_printf(filename1); // So I can see what did come back
            Lclose(env,r);
            return nil;
        }
    }
// In this code I treat all unexpected responses as errors and I do not
// attempt to continue. This is sometimes going to be overly pessimistic
// and RFC1945 tells me that I should treat unidentified codes as the
// n00 variant thereupon.
    switch (retcode)
{       default:retcode = 0;
            break;
        case 200:
            break;   // A success code for GET requests
        case 301:        // Redirection request
        case 302:
            do
            {   if (fetch_response(filename1, r))
                {   err_printf("Unexpected response from the server\n");
                    retcode = 0;
                    break;
                }
                if (filename1[0] == 0)
                {   err_printf("Document has moved, but I can not trace it\n");
                    retcode = 0;
                    break;
                }
            }
            while (std::memcmp(filename1, "location: ", 10) != 0);
            if (retcode == 0) break;
// At present I take a somewhat simplistic view of redirection, and just
// look for the first alternative URL and start my entire unpicking
// process afresh from there.
            for (i = 10; filename1[i] == ' '; i++);
            w = &filename1[i];
            while (filename1[i]!=' ' && filename1[i]!=0) i++;
            filename1[i] = 0;
            len = std::strlen(w);
            closesocket(s);
            if (++retry_count > 5)
            {   err_printf("Apparent loop in redirection information\n");
                retcode = 0;
                break;
            }
            goto start_again;
            break;
        case 401:
            err_printf("Authorisation required for this access\n");
            retcode = 0;
            break;
        case 404:
            err_printf("Object not found\n");
            retcode = 0;
            break;
    }

    if (retcode == 0)
    {   Lclose(env,r);
        return nil;
    }

// Skip further information returned by the server until a line containing
// just the end-of-line marker is fetched
    do
    {   for (i = 0; i < LONGEST_LEGAL_FILENAME; i++)
        {   int ch = char_from_socket(r);
            if (ch == EOF)
            {   err_printf("Error fetching additional info from the server\n");
                Lclose(env,r);
                return nil;
            }
            if (ch == 0x0a) break;
        }
    } while (i > 1);

    return r;
}

#endif // SOCKETS

unsigned long windowsThreadId()
{   return GetCurrentThreadId();
}

unsigned long windowsProcessId()
{   return GetCurrentProcessId();
}

// On Windows I can query the page that the address is within, and accept
// it if there is read/write access and if it is not a guard page.

bool valid_address(void *pointer)
{   MEMORY_BASIC_INFORMATION mbi = {0};
    if (::VirtualQuery(pointer, &mbi, sizeof(mbi)))
    {   if (mbi.State != MEM_COMMIT) return false;
        // check the page is not a guard page
        if (mbi.Protect & (PAGE_GUARD|PAGE_NOACCESS)) return false;
        return ((mbi.Protect & (PAGE_NOACCESS)) == 0);
    }
    return false;  // ::VirtualQuery failed.
}

} // end namespace

#elif defined __CYGWIN__

// The aim here is to avoid use of the Microsoft versions of printf and
// friends and (hence) allow g++ to parse and check format strings reliably.
#ifndef __USE_MINGW_ANSI_STDIO
#define __USE_MINGW_ANSI_STDIO 1
#endif

#include <cstddef>

inline constexpr size_t LONGEST_LEGAL_FILENAME = 1024;


#include <winsock.h>
#include <process.h>
#include <windows.h>

#include <cstring>
#include <cstdio>

#include "winsupport.h"

namespace CSL_LISP
{

int windowsFindGnuplot2(char *name)
{   HKEY keyhandle;
// I need to use RegQueryValueEx here rather than RegGetValue if I am to
// support 32-bit Windows XP. Note that buffer overflow in the path to
// gnuplot could leave an unterminated string, but that should not happen
// here.
    DWORD length = LONGEST_LEGAL_FILENAME, type;
    int ll, i;
    LONG r = RegOpenKeyEx(
                 HKEY_LOCAL_MACHINE,
                 "Software\\Microsoft\\Windows\\CurrentVersion\\"
                     "App Paths\\wgnuplot.exe",
                 0,
                 KEY_QUERY_VALUE,
                 &keyhandle);
    if (r == ERROR_SUCCESS)
    {   r = RegQueryValueEx(keyhandle,
                            nullptr,
                            nullptr,
                            (LPDWORD)&type,
                            (LPBYTE)name,
                            (LPDWORD)&length);
        name[LONGEST_LEGAL_FILENAME-1] = 0;
        if (r == ERROR_SUCCESS)
        {
// Now I have a further delight. The path I have just identified is a
// Windows one, but I need to convert it into a Cygwin-style one. It
// should start "x:\" with a drive name so I map that onto "/cygdrive/x/"
// and convert every "\" to a "/". The code here is rather grotty with the
// numeric "magic offsets" and the use of snprintf followed by patching
// up after the terminating null from that, but it is at least concise.
            ll = std::strlen(name);
            for (i=ll; i>=0; i--)
                name[i+9] = name[i]=='\\' ? '/' : name[i];
            std::snprintf(name, 40, "/cygdrive/%c", name[0]);
            name[11] = '/';
            return 1;
        }
    }
    return 0;
}

size_t windowsGetTempPath(size_t n, char *s)
{   return GetTempPath(n, s);
}



} // end namespace

#endif // CYGWIN, WIN32

// end of winsupport.cpp
