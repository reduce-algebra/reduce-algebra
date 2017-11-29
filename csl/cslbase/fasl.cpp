// fasl.cpp                                Copyright (C) 1990-2017 Codemist

//
// Binary file support for faster loading of precompiled code etc.
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

#ifdef WIN32
#include <windows.h>
#else
#ifndef EMBEDDED
#include <dlfcn.h>
#endif
#endif

// I need to explain the operations that happen on FASL files as regards
// preservation of source code. This describes a post-2016 implementation
// which has been simplified and rationalised compared with earlier versions.
//
// The starting point for the complication is that the compiler
// arranges that if the variable !*savedef is set when it compiles
// something then the original source is saved under a '!*savedef
// tag on the property list of the name of the function concerned. For
// simple in-store compilation this happens immediately. For compilation
// into a FASL file the definition is written into the file, but whether
// it is instated onto the property list depends on the circumstances
// associated with loading the module.
//
// When load!-module is used to load the code this extra information
// is ignored.
//
// There is however a scheme that can load !*savedef properties without
// processing and of the other parts of the FASL file. This is the function
// load!-source.
// Neither random executable things nor compiled code get loaded by this. A
// particular thing to note is that if the compiled module was such that
// normal loading of it with load!-module led to subsidiary modules being
// loaded then this will not happen with load!-source. Thus to load all
// the modules making up a package involves finding out some other way what
// they are. I am expecting it will be rather more common to want to load
// all the source for everything that is available, and that can be
// achieved using
//   for each lib in input!-libraries do
//      for each mod in library!-members lib do load!-source mod;
// (or just use library!-members() without an argument to scan the first or
// only available library). But using load!-source without an argument
// achieves essentially just this. Well actually there are extra complications
// which mean that MOST people should use load!-source without an argument!
// In general it will be possible to have a number of read-only image files
// present together with at most one read-write one. The (Lisp) variable
// input!-libraries contains a list of rather abstract objects giving
// each library in the order that they will be searched when looking for
// a module to load. The variable output!-library is either nil (if no
// writable library is present) or is one of the libraries in the
// input!-libraries list. When load!-module (or load!-source or of course
// load!-selected!-source) loads a module it always does so from the first
// library that contains a module with the given name. Thus an image file
// that is earlier in the search order can make one that comes later. There
// is (at present????) no provision for loading modules from later in the
// search order.
// library!-members lists the modules present in a specified library. So
// if this is done for several libraries some module names may end up listed
// several times, but every time the module name is used only the first
// instance of that module will be accessed. For load!-source it will not
// matter if a module is scanned several times since the same !*savedef
// information will be instated and because I can be careful and only add
// mention of any given module once to the source record.
//
// The simple case "load!-source mod" loads all !*savedef information in the
// given module. Clearly if it is called repeatedly and several modules are
// scanned the !*savedef information present at the end will be the last
// version loaded. In addition to setting up !*savedef properties the
// load!-source function also records, for each function, which module
// it was found in. This ends up as as load!-source property for the name
// of the function, and will be a list of the names of modules in which
// a definition was found. This scheme is intended to be useful for cross-
// referencing style code that tracks down where in the source some function
// is defined. It is also there so that it is possible to identify cases
// where the same name is used for functions present in several modules. This
// shows up when (at the end of a sequence of uses of load!-source) some names
// have load!-source properties with multiple entries.
// The return value of load!-source is a list of the functions whose source
// has just been loaded.
//
// A second function "load!-selected!-source mod" is available for selective
// loading of !*savedef information.
// In this case !*savedef information is read from the module, but only
// saved for the user if a checksum computed on it matches an integer value
// present as a load!-selected!-source property of its name of if the
// load!-selected!-source property is something else non-nil (typically t).
// The checksum is calculated using md5 but then truncated to 60 bits so
// there is some (small) possibility of an unwanted definition ending up
// loaded. The load!-source propery-list entry will be set up for all
// functions, not just for the ones where checksums match and so not only
// can this be used to detect any cases of hash collisions, but it provides
// a way to collect just this source module information.
//
// load!-source and load!-selected!-source scan all available modules if
// they are called without an argument, and this will often be the most
// convenient way to use them.
//
// Note that the above is a change from previous behaviour which inspected
// variables !*savedef and load!-source at load-time to decide what to do.
// I hope it is cleaner and simpler, and by virtue of this block of comments
// it is certainly better documented!
//
// Uses with the build of Reduce:
//   The bootstrap build of Reduce has !*savedef set while it compiles the
//   code. This puts saved definitions in the FASL files and they will be
//   present at build time, but they do not get loaded by load!_module.
//
//   The "make profile" option in the Makefile measures which functions are
//   most heavily used. The measurements it records include an ordered
//   list of functions and then a checksum of the associated !*savedef
//   information using the same scheme that load!-selected will. This is
//   done so that if two modules each define a function called (say) foo
//   and profile information about each of these gets generated it will be
//   possible to distinguish between them.
//
//   The procedure that compiled from Reduce (ie Lisp) into C++ picks up
//   checksum information from the profile records and uses
//   load!-selected!-source to recover just the matching Lisp source.
//   It converts that into C++ and inserts the checksum into tables as part
//   of that C++ code. When the (final) version of Reduce is compiling
//   itself and it finds a defininition of some function (again suppose
//   it is called foo), it checks if it has a compiled-in C++ function
//   with the same name and the same checksum, and if so it ignores the
//   new definition. This leaves the C++ version to be used. If a newer
//   version of the Reduce sources provide an updated or changed definition
//   then with very high probability the new checksum will not match the
//   one associated with the C++ code, and this will lead to the newer
//   definition being compiled into bytecodes for use. So source changes
//   in Reduce may over time degrade the number of functions where faster
//   C++ versions of functions are used.
//
//   Code used via scripts/clash.sh uses load!-selected!-source
//   with no checksum on property lists. This just loads the information
//   about which modules functions are defined in. It is then possible
//   to identify and report cases where there are multiple versions of
//   functions with the same name present somewher in Reduce.
//   Given that Reduce can not check for this at build time an analysis
//   tool like this can help detect potential problem clashes or opportunities
//   to bring functions to a common place where they are available to all
//   packages that might benefit from them.
//
//   Planned future code for global type-checking of Reduce will use
//   load!-source to gain access to all the source code in a spirit of
//   what other programming systems call "reflection" but that Lisp has
//   pretty much been able to take for granted since the 1960s. In a similar
//   style future cross-referencing code might plausibly work based on
//   !*savedef information rather than by scanning source files. In general
//   tools for code analysis and improvement may find use for all of this. 
//
//   If a debugging tool wanted to recover the source version of just a single
//   function it could set the load!-selected!-source property of the function
//   name to T and call load!-selected!-source - thus recovering the !*savedef
//   information for just that name without needing a checksum in advance.
//
// So here is a go at a summary:
//   load!-module     Loads code and loads any savedef entries present.
//   load!-source     Loads all savedefs and sets function location info.
//   load!-selected!-source
//                    As load!-source but ONLY loads the savedef of a
//                    function if the load!-selected!-source property of
//                    the name of the function is either true or it
//                    is an integer matching a checksum of the saved
//                    definition. Even this load!-selected!-source only
//                    recovers selected !*savedef information it loads
//                    function location information for everything.



bool fasl_output_file = false;  // An output file is open?

#ifdef COMMON
static char package_name[256];
#endif

char *trim_module_name(char *name, size_t *lenp)
{   size_t len = *lenp, len1;
    len1 = len - 1;
//
// Firstly I will decrease the length of the string if there is a "."
// towards the end.
//
    while (len1 > 0 && name[len1] != '.')
    {   if (name[len1] == '/' || name[len1] == '\\')
        {   len1 = len;
            break;
        }
        len1--;
    }
    if (len1 > 0) len = len1;
//
// Now I will try to remove any prefix that ends in "/" or "\".
// Through all this I will attempt to leave SOMETHING over from "silly"
// inputs such as ".....", but exactly what happens in such cases does not
// bother me much!
//
    len1 = len - 1;
    while (len1 > 0 && name[len1] != '/' &&
           name[len1] != '\\' && name[len1] != '.') len1--;
    if (len1 > 0 && len1 < len-2)
    {   len1++;
        name += len1;
        len -= len1;
    }
    *lenp = len;
    return name;
}

LispObject Lcopy_module(LispObject env, LispObject file)
//
// copy-module will ensure that the output PDS contains a copy of
// the module that is named. There is no provision for copying
// startup banner data - that must be set up by hand.
//
{   Header h;
    size_t len;
    char *modname;
    if (file == nil) Icopy(NULL, 0);
    else
    {   if (symbolp(file))
        {   file = get_pname(file);
            h = vechdr(file);
        }
        else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
            aerror("copy-module");
        len = length_of_byteheader(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
        modname = trim_module_name(modname, &len);
#endif
        Icopy(modname, len);
    }
    return onevalue(nil);
}

LispObject Ldelete_module(LispObject env, LispObject file)
//
// delete-module deletes the named module from the output PDS, supposing it
// was there to begin with.  (delete-module nil) deletes any help data.
//
{   Header h;
    size_t len;
    char *modname;
    if (file == nil) Idelete(NULL, 0);
    else
    {   if (symbolp(file))
        {   file = get_pname(file);
            h = vechdr(file);
        }
        else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
            aerror("delete-module");
        len = length_of_byteheader(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
        modname = trim_module_name(modname, &len);
#endif
        Idelete(modname, (int)len);
    }
    return onevalue(nil);
}

LispObject Lbanner(LispObject env, LispObject info)
//
// (startup!-banner nil)      returns the current banner info (nil if none)
// (startup!-banner "string") sets new info
// (startup!-banner "")       deletes any that there is.
//
{   Header h;
    int i;
    int32_t len;
    char *name;
    if (info == nil)
    {   char b[64];
        if (Iopen_banner(0)) return onevalue(nil);
        for (i=0; i<64; i++)
            b[i] = (char)Igetc();
        IcloseInput();
        info = make_string(b);
        validate_string(info);
        return onevalue(info);
    }
    if (symbolp(info))
    {   info = get_pname(info);
        h = vechdr(info);
    }
    else if (!is_vector(info) || !is_string_header(h = vechdr(info)))
        aerror("banner");
    len = length_of_byteheader(h) - CELL;
    name = (char *)info + CELL - TAG_VECTOR;
    if (len == 0) Iopen_banner(-2); // delete banner info
    else
    {
//
// The following writes to the current output image. Well that is not
// always nice, and in particular I do not want "just" updating the banner
// to create an image file that had otherwise been in "pending" state. So
// the implementation of Iopen_banner(-1) will report failure in that
// case rather than creating a fresh image file.
//
        if (Iopen_banner(-1)) return onevalue(nil);
        if (len > 63) len = 63;
// Write banner uncompressed.
        for (i=0; i<64; i++) Iputc(i >= len ? 0 : name[i]);
        IcloseOutput();
    }
    return onevalue(lisp_true);
}

LispObject Llist_modules(LispObject env)
//
// display information about available modules
//
{   Ilist();
    return onevalue(nil);
}

LispObject Lwritable_libraryp(LispObject env, LispObject file)
//
// This tests if a library handle refers to a writable file.
//
{   int i;
    directory *d;
    if ((file & 0xffff) != SPID_LIBRARY) return onevalue(nil);
    i = (file >> 20) & 0xfff;
    d = fasl_files[i];
    i = d->h.updated;
    return onevalue(Lispify_predicate(i & D_WRITE_OK));
}

#ifdef DEBUG_FASL

static void IputcDebug(int c, int line)
{   Iputc(c);
    trace_printf("Iputc(%d/%x/%s: %d %.8x %.8x)\n", c, c, fasl_code(c),
                 line, C_stack, nil);
}

#define Iputc(c) IputcDebug(c, __LINE__)

#endif


LispObject Lmodule_exists(LispObject env, LispObject file)
{   char filename[LONGEST_LEGAL_FILENAME], tt[32];
    Header h;
    size_t len;
    size_t size;
    char *modname;
    memset(filename, 0, sizeof(filename));
    if (symbolp(file))
    {   file = get_pname(file);
        h = vechdr(file);
    }
    else if (!is_vector(file) ||!is_string_header(h = vechdr(file)))
        aerror("modulep");
    len = length_of_byteheader(h) - CELL;
    modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
    modname = trim_module_name(modname, &len);
#endif
    if (Imodulep(modname, (int)len, tt, &size, filename))
        return onevalue(nil);
    tt[24] = 0;
    file = make_string(tt);
    return onevalue(file);
}

LispObject Lstart_module(LispObject env, LispObject name)
//
// This must be called before write-module - it sets up everything
// for writing a (compressed) FASL file.  Calling with a nil argument
// closes the current fasl file, otherwise the arg is the name of
// a file to open.  It is not intended that ordinary programmers call
// this function - it is for use from within the compiler.
// As a special bit of magic the name passed can be a Lisp stream, in
// which case the module data will be written to it.
//
{
    if (name == nil)
    {   def_finish();   // flush out and of compressed data.
        if (fasl_output_file)
        {   int k = (int)Ioutsize() & 0x3;
//
// Here I arrange that all FASL modules will end up being a multiple of
// 4 bytes long.  "WHY?"  Well I once suffered from a machine that was not
// very good at supporting odd-length data transfers (the suggestion I
// collected is that it MAY be because I had an early version of an 80386 CPU
// chip installed). The padding up here is not very painful and may avoid
// some painful trouble on my machine (and hence maybe on some other ones).
// The machine concerned is a PC and the chip and 80386, just in case you
// wondered.  Zortech technical support were very helpful trying to
// track down the crashes I was having - even had they provided a software
// work-around in their code at some time I should leave this code and comment
// in CSL.
// Note (June 1992) I now have a computer with a newer CPU chip in it and
// the problem mentioned above does not arise - but it still seems reasonable
// to keep modules a multiple of 4 bytes long.
// Note (October 1995) Well, now I have a Pentium rather than a 386, and
// my previous 80486 system has gone down the feeding chain to replace the
// old and dodgy 80386. So sometime within the next year or so I will
// remove this comment, but still leave modules padded to multiples of
// 4 bytes since maybe I would introduce more bugs removing that than I would
// save.
// (January 1999) This little essay continues to entertain me. The 386 system
// happens to be around Cambridge again as a "relic" having been discarded as
// too old-fashioned and slow by pretty well everybody! Gosh how machines
// change during the life-time of a piece of software!
// (March 2001) "early 386" bug hah. Gosh that was slow by today's standards.
// (May 2010) !!!!!!!
// (July 2017) The early 1990s now represent a rather different world. But
// I still like this story.
//
            while (k != 3) k++, Iputc(0);
            IcloseOutput();
            fasl_output_file = false;
            fasl_stream = nil;
            if (verbos_flag & 2)
            {   freshline_trace();
#ifdef COMMON
                trace_printf(";; FASLEND\n");
#else
                trace_printf("+++ FASLEND\n");
#endif
            }
            return onevalue(lisp_true);
        }
        else return onevalue(nil);
    }
    else if (is_stream(name))
    {   fasl_stream = name;
        fasl_output_file = true;
        Iopen_to_stdout();
        def_init();
        return onevalue(lisp_true);
    }
    else
    {   char filename[LONGEST_LEGAL_FILENAME];
        char *modname;
        size_t len;
        Header h;
        memset(filename, 0, sizeof(filename));
#ifdef COMMON
        if (complex_stringp(name))
        {   name = simplify_string(name);
            h = vechdr(name);
        }
        else
#endif
            if (symbolp(name))
            {   name = get_pname(name);
                h = vechdr(name);
            }
            else if (!(is_vector(name))) aerror("start-module");
            else if (!is_string_header(h = vechdr(name)))
                aerror("start-module");
        len = length_of_byteheader(h) - CELL;
        modname = (char *)name + CELL - TAG_VECTOR;
//
// Here I will play jolly games! The name as passed in to start-module will
// be allowed to be a fairly general file-name. If there is a suffix of the
// form ".xxx" on the end I will strip that off. If there is a directory-
// style component before that (as signalled by having a "/" or a "\" or
// another "." within the name) I will trim that off too. So the input
// string "/home/xxx/something.fsl" (say) would be treated exactly as if
// it had been just "something".
//
        modname = trim_module_name(modname, &len);
        if (len >= sizeof(filename)) len = sizeof(filename);
        if (Iopen(modname, len, IOPEN_OUT, filename))
        {   err_printf("Failed to open \"%s\"\n", filename);
            return onevalue(nil);
        }
        fasl_output_file = true;
        def_init();
        return onevalue(lisp_true);
    }
}

// This is the function used by the commpiler to write stuff into a FASL
// file. The first argument will be executable code (a PROGN expression
// with everything from the compiled file in it) and the second will be
// a list of pairs ((name definition) ...) for !*savedef purposes.

//
// (set-help-file "key" "path") puts an extra help file on the cwin
// HELP menu. If "path" is NIL then the item specified by "key" is
// removed. If "key" is NIL then all user-inserted items are removed.
//

LispObject Lset_help_file(LispObject env, LispObject a, LispObject b)
{   const char *w;
    char *aa, *bb = NULL;
    size_t lena, lenb;
    if (a != nil)
    {   w = get_string_data(a, "set-help-file", lena);
        aa = (char *)malloc(lena+1);
        if (aa == NULL) aerror("set-help-file");
        memcpy(aa, w, lena);
        aa[lena] = 0;
    }
    else
    {   aa = NULL;
        b = nil;
    }
    if (b != nil)
    {   w = get_string_data(b, "set-help-file", lenb);
        bb = (char *)malloc(lenb+1);
        if (bb == NULL) aerror("set-help-file");
        memcpy(bb, w, lenb);
        bb[lenb] = 0;
    }
    fwin_set_help_file(aa, bb);
    return onevalue(nil);
}

char prompt_string[MAX_PROMPT_LENGTH];

LispObject Lsetpchar(LispObject env, LispObject a)
{   LispObject old = prompt_thing;
    prompt_thing = a;
    escaped_printing = escape_nolinebreak;
    set_stream_write_fn(lisp_work_stream, count_character);
    memory_print_buffer[0] = 0;
    set_stream_write_other(lisp_work_stream, write_action_list);
    stream_byte_pos(lisp_work_stream) = 0;
    stream_char_pos(lisp_work_stream) = 0;
    active_stream = lisp_work_stream;
    push(old);
    internal_prin(a, 0);
    pop(old);
    memcpy(prompt_string, memory_print_buffer, MAX_PROMPT_LENGTH);
    prompt_string[MAX_PROMPT_LENGTH-1] = 0;
    fwin_set_prompt(prompt_string);
    return onevalue(old);
}

// end of fasl.cpp
