// version.h                               Copyright (C) 1990-2023 Codemist

#ifndef header_version_h
#define header_version_h 1

// $Id$


/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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

//#define REVISION 6594

// What follows arranges that I can extract information from the "$Id"
// record that subersion updates on check-in.

#include <cstdio>

#define VERSION_ID "$Id$"

// Extract the revision number.

inline constexpr int REVISION = [](){
    const char* d = VERSION_ID+15;
    int v = 0, ch;
    while ((ch = *d++) >= '0' && ch <= '9') v = 10*v + ch - '0';
    return v;
    }();

// This returns eg "18-Aug-2023"

inline const char* version_date()
{   static char date_string[12];
    const char* v = VERSION_ID;
    int yyyy, mm, dd;
// Format:         "$Id: xxxxversion.h nnn yyyy-mm-dd hh:mm:ss..."
    if (std::sscanf(v, "%*s  %*s       %*s %d-%d-%d",
                                         &yyyy, &mm, &dd) != 3)
        return "unknown-date";
    const char* month[] =
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::snprintf(date_string, 10, "%02d-%s-%d", dd, month[mm-1], yyyy);
    return date_string;
}

// This one returns eg "Fri Aug 18 16:52:29 2023"


// Decode fay of week - from cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
// and attributed to sakamoto@sm.sony.co.jp (Tomohiko Sakamoto) on comp.lang.c
// on March 10th, 1993

inline int day_of_week(int m, int d,int y)
{   y-=m<3;
    return (y+y/4-y/100+y/400+"-bed=pen+mad."[m]+d)%7;
}

inline const char* version_date_and_time()
{   static char date_and_time_string[25];
    const char* v = VERSION_ID;
    int yyyy, mm, dd, day;
    int hour, minute, second;
// Format:         "$Id: xxxxversion.h nnn yyyy-mm-dd hh:mm:ss..."
    if (std::sscanf(v, "%*s  %*s       %*s %d-%d-%d %d:%d:%d",
                                         &yyyy, &mm, &dd,
                                         &hour, &minute, &second) != 6)
        return "unknown-date";
    const char* month[] =
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    const char* weekday[] =
    {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    day = day_of_week(mm, dd, yyyy);
    std::snprintf(date_and_time_string, 25,
        "%s %s %02d %02d:%02d:%02d %d",
        weekday[day], month[mm-1], dd, hour, minute, second, yyyy);
    return date_and_time_string;
}

#endif // header_version_h

// end of version.h
