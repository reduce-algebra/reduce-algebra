// winsupport.cpp                               Copyright (C) 2021 Codemist

// $Id: winsupport.cpp 5728 2021-03-13 14:54:03Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

#define LONGEST_LEGAL_FILENAME 1024

#ifdef WIN32

#include <cstdio>
#include <cstring>

#include "winsupport.h"

void win32_stacklimit(uintptr_t &C_stacklimit)
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
            C_stackLimit = (uintptr_t)C_stackBase - maxStackSize + 0x10000;
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
    {   default:                 std::sprintf(error_name,
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
    return 0;
}

HANDLE gnuplot_process = 0;
HWND gnuplot_handle = 0;
bool gnuplotActive = false;

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
#else
#ifdef HAVE__PUTC_NOLOCK
#define PUTC(x, y) _putc_nolock((x), (y))
#else
#define PUTC(x, y) putc((x), (y))
#endif
#endif


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

uint64_t read_clock()
{   FILETIME t0, t1, t2, t3;
    if (GetProcessTimes(GetCurrentProcess(), &t0, &t1, &t2, &t3) == 0)
        return 0;
// The 4 times are: CreationTime, ExitTime, KernelTime, UserTime
    ULARGE_INTEGER ul;
// Times are returned in FILETIME format so I need to convert to an arithmetic
// type that I can use.
    ul.LowPart = t3.dwLowDateTime;
    ul.HighPart = t3.dwHighDateTime;
    uint64_t n = ul.QuadPart;
// Times are returned in units of 100ns, so I divide by 10 to get
// microseconds.
    return n/10;
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

// On Windows I can query the page that the address is within, and accept
// it if there is read/write access and if it is not a guard page.

bool valid_address(void *pointer)
{   MEMORY_BASIC_INFORMATION mbi = {0};
    if (::VirtualQuery(pointer, &mbi, sizeof(mbi)))
    {   // check the page is not a guard page
        if (mbi.Protect & (PAGE_GUARD|PAGE_NOACCESS)) return false;
        return ((mbi.Protect & (PAGE_READWRITE|PAGE_EXECUTE_READWRITE)) != 0);
    }
    return false;  // ::VirtualQuery failed.
}

#elif defined __CYGWIN__

// The aim here is to avoid use of the Microsoft versions of printf and
// friends and (hence) allow g++ to parse and check format strings reliably.
#define __USE_MINGW_ANSI_STDIO 1

#include <winsock.h>
#include <process.h>
#include <windows.h>

#include <cstring>
#include <cstdio>

#include "winsupport.h"

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
// numeric "magic offsets" and the use of sprintf followed by patching
// up after the terminating null from that, but it is at least concise.
            ll = std::strlen(name);
            for (i=ll; i>=0; i--)
                name[i+9] = name[i]=='\\' ? '/' : name[i];
            std::sprintf(name, "/cygdrive/%c", name[0]);
            name[11] = '/';
            return 1;
        }
    }
    return 0;
}

size_t windowsGetTempPath(size_t n, char *s)
{   return GetTempPath(n, s);
}

#endif // Windows & Cygwin

// end of winsupport.cpp
