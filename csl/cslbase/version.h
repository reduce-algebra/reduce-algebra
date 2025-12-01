// version.h                               Copyright (C) 1990-2025 Codemist

#ifndef header_version_h
#define header_version_h 1

// $Id$


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

// Rather than having a simple version I will cause my script
// (scripts/commit.sh) that is used to update the subversion repository to
// update the revision number here.

// What follows arranges that I can extract information from the "$Id"
// record that subersion updates on check-in.

#include <cstdio>

#define VERSION_ID "$Id: version.h 7210 2025-12-01 09:34:11Z reduce $"

namespace CSL_LISP
{

// Extract the revision number.

inline constexpr int REVISION = []() constexpr {
    const char* d = &VERSION_ID[0];
    while (*d != ' ') d++;      // Skip past "$Id"
    d++;
    while (*d != ' ') d++;      // Skip past name of file
    d++;                        // Now pointing at revision number
    int v = 0, ch = 0;
    while ((ch = *d++) >= '0' && ch <= '9') v = 10*v + (ch-'0');
    return v;
    }();

// The initial data here is just to show the intended format and
// it gets updated to proper values during system initialization.

inline char version_date[16] = "05-Nov-1605";
inline char version_date_and_time[32] = "Mon Nov 11 11:11:00 1918\n";


// Now code that exists to get version_date and version_date_and_time
// synchronized with VERSION_ID. This works by having an inline variable
// that will be initialized before main() is called.


inline constexpr unsigned int get_integer(const char* s, int width)
{   unsigned int r = 0;
    while (width-- != 0)
    {   int ch = *s++;
        if (ch < '0' || ch > '9') return 0;
        r = 10*r + (ch - '0');
    }
    return r;
}

// Decode day of week - from cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
// and attributed to sakamoto@sm.sony.co.jp (Tomohiko Sakamoto) on comp.lang.c
// on March 10th, 1993

inline constexpr int day_of_week(int m, int d,int y)
{   y -= m<3;
    return (y+y/4-y/100+y/400+"-bed=pen+mad."[m]+d)%7;
}

inline bool initialize_version_date()
{
    const char* v = &VERSION_ID[0];
// Format:         "$Id: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxfilename revision yyyy-mm-dd hh:mm:ss..."
    while (*v != ' ') v++;      // Skip past "$Id"
    v++;
    while (*v != ' ') v++;      // Skip past name of file
    v++;                        // Now pointing at revision number
    while (*v != ' ') v++;      // Skip past revision number
    v++;                        // Now pointing at start of date
    unsigned int year = get_integer(v, 4);
    unsigned int month = get_integer(v+5, 2);
    unsigned int dayofmonth = get_integer(v+8, 2);
    unsigned int hour = get_integer(v+11, 2);
    unsigned int minute = get_integer(v+14, 2);
    unsigned int second = get_integer(v+17, 2);
    static const char* monthname[] =
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    static const char* weekday[] =
    {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
// First:              "18-Aug-2023"
    std::snprintf(version_date, 12, "%2u-%s-%u",
                  dayofmonth, monthname[month-1], year);
// Now:                "Fri Aug 18 16:52:29 2023\n"
    unsigned int dayindex = day_of_week(month, dayofmonth, year);
    std::snprintf(version_date_and_time, 25,
        "%s %s %2u %02u:%02u:%02u %u",
        weekday[dayindex], monthname[month-1], dayofmonth,
        hour, minute, second, year);
    return true;
}

inline bool version_date_initialized = initialize_version_date();

} // end namespace

#endif // header_version_h

// end of version.h
