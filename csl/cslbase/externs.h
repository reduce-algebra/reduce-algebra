// externs.h                               Copyright (C) Codemist 1989-2022

//
//   Main batch of extern declarations.
//
//

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

#ifndef header_externs_h
#define header_externs_h 1

// Note that the Windows version exports a number of symbols, as listed
// in a ".def" file. In order for there to be a match between the symbol
// names in the object files and the names in the .def file it is vital
// that all those things be declared with C linkage and hence un-mangled
// names. Perhaps I need some strategy that lets me gain the extra security
// of C++ linkage for everything else... but that is for the future.

#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif

extern void** pages;
extern void** heap_pages;
extern void** vheap_pages;

extern void** new_heap_pages;
extern void** new_vheap_pages;

extern void* allocate_page(const char* why);

extern size_t pages_count, heap_pages_count, vheap_pages_count;

extern size_t new_heap_pages_count, new_vheap_pages_count;

extern LispObject* list_bases[];
extern const char* list_names[];
extern LispObject* nilsegment;
extern LispObject* stacksegment;
extern int32_t stack_segsize;  // measured in units of one CSL page
extern double max_store_size;

extern bool restartp;

// This version of the directory structure can cope with up to 2047
// modules in any single library. It can also cope with a directory
// being mapped onto an operating-system directory rather than my own
// sub-structure packed within a file.

#define IMAGE_FORMAT_VERSION       '5'

#define DIRECTORY_SIZE              8    // Initial directory size

typedef struct _directory_header
{   char C, S, L, version;  // Identification: spells CSL or CCL.
    unsigned char dirext,   // Extra bits for dirused, dirsize, this is
             // so that in effect dirsize & dirused can be
             // 12 bits wide.
             dirsize,  // Number of directory entries provided.
             dirused,  // Number currently in use.
             updated;  // In need of compaction & other flags.
    char eof[4];            // fseek/ftell location of end of file.
    // Does this assume no fiules > 4G?
} directory_header;

typedef struct _directory_entry
{   char data[44];
//
//  char newline;                * Makes file easier to read as a text file! *
//  char name[12];               * blank padded to 12 characters             *
//                               * but with special rules for root image etc *
//  char date[24];
//  char position[4];            * Machine byte-order insensitive format     *
//  char size[3];                * Ditto                                     *
//
} directory_entry;

//
// I use these macros rather than just the structure definition shown above
// so that the behaviour of the code is not sensitive to attempts by a C
// compiler to align things for me.  Think C 5.0 on the Macintosh (and
// probably many other C compilers) put padder bytes in the original
// structure to give word-alignment.
//
#define D_newline     data[0]
#define D_name        data[1]
#define D_space       data[12]
#define D_date        data[13]
#define D_position    data[37]
#define D_size        data[41]

#define name_size     12
#define date_size     24

//
// The limit set here to the length of the name of a directory should only
// have an effect on cosmetics not functionality.
//
#define DIRNAME_LENGTH  256
#define NEWLINE_CHAR    0x0a

//
// The D_newline location in a directory originally held a newline,
// because doing so resulted in image files being a little bit easier
// to interpret when looked at with a simple text editor. But then
// it turned out that the C value `\n' was not the same on all computers,
// and so I used a literal hex value 0x0a instead, expecting it to
// be the same as '\n' on "most" systems.
//

typedef struct directory
{   directory_header h;
    std::FILE* f;
    const char* full_filename;    // nullptr unless native directory
// It is unexpectedly and unpleasantly the case that the "filename"
// field here must be the last one before the array of directory
// entries. This is because in the case where an image file is
// left pending at startup the structure is extended, overlapping where the
// directory entries will end up, to hold a full-length file name not merely
// one truncated to DIRNAME_LENGTH. I do not use a string here because
// I use a naive process of writing the bytes of a directory to disc when
// I create an image file, and I can not have any reasonable expectations on
// what string would look like.
    char filename[DIRNAME_LENGTH];
    directory_entry d[1];   // Will usually have many more entries
} directory;

#ifdef COMMON
#  define MIDDLE_INITIAL   'C'
#else
#  define MIDDLE_INITIAL   'S'
#endif

inline int get_dirused(directory &d)
{   return d.h.dirused + ((d.h.dirext & 0x0f)<<8);
}

inline int get_dirsize(directory &d)
{   return d.h.dirsize + ((d.h.dirext & 0xf0)<<4);
}

//
// Flags for the UPDATED field
//

#define D_WRITE_OK  1
#define D_UPDATED   2
#define D_COMPACT   4
#define D_PENDING   8

extern char* mystrdup(const char* s);

class stringBool
{
public:
    string key;
    bool flag;
    stringBool(string k, bool f)
    {   key = k;
        flag = f;
    }
};

class stringBoolString
{
public:
    string key;
    bool flag;
    string data;
    stringBoolString(string k, bool f, string d)
    {   key = k;
        flag = f;
        data = d;
    }
};

class faslFileRecord
{
public:
    bool inUse;
    const char* name;
    directory* dir;
    bool isOutput;
    faslFileRecord(const char* n, bool o)
    {   inUse = true;
        name = n;
        dir = nullptr;
        isOutput = o;
    }
    ~faslFileRecord()
    {   if (dir != nullptr) delete [] reinterpret_cast<char*>(dir);
    }
};

extern std::vector<stringBoolString> symbolsToDefine;
extern std::vector<stringBoolString> stringsToDefine;
extern std::vector<string> stringsToEvaluate;
extern std::vector<faslFileRecord> fasl_files;

extern char* big_chunk_start;
extern char* big_chunk_end;

extern LispObject multiplication_buffer;

#if defined CONSERVATIVE && defined GENERATIONAL
extern void write_barrier(LispObject* p, LispObject q);
#else // !CONSERVATIVE
inline void write_barrier(LispObject* p, LispObject q)
{  *p = q;
}
#endif // !CONSERVATIVE

extern std::mutex debug_lock;
extern const char* debug_file;
extern int debug_line;

extern void DebugTrace();
extern void DebugTrace(int i);
extern void DebugTrace(const char* msg);
extern void DebugTrace(const char* fmt, int i);
extern const char* decodeObject(LispObject a);

// This is a macro that sets some global variables because I want Tr()
// without arguments to be valid, and until C++2a it seems impossible to
// combine __VA_ARGS__ with anything else because of fussiness about commas.

#define Tr(...)                                        \
   {   std::lock_guard<std::mutex> lk(debug_lock);     \
       debug_file = __FILE__;                          \
       debug_line = __LINE__;                          \
       DebugTrace(__VA_ARGS__);                        \
   }

#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5

extern volatile char stack_contents_temp;
extern uintptr_t C_stackLimit;

#ifdef CHECK_STACK
extern int check_stack(const char* file, int line);
extern void show_stack();

inline void if_check_stack()
{   if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("stack overflow");
    }
}
#else
inline void if_check_stack()
{   const char* _p_ = reinterpret_cast<const char*>(&_p_);
    if (reinterpret_cast<uintptr_t>(_p_) < C_stackLimit)
    {   if (C_stackLimit > 1024*1024) C_stackLimit -= 1024*1024;
        aerror("stack overflow");
    }
}
#endif

//
// Extra debugging help...
//

#ifdef DEBUG

extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char* data, const char* file, int line);
extern void debug_record_int_raw(const char* s, int n,
                                 const char* file, int line);
extern void debug_show_trail_raw(const char* msg, const char* file, int line);

#define debug_record(data)     debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record((const char* )&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)

#define debug_assert(x) \
  if (!(x)) { debug_show_trail("Assertion failed"); my_exit(); }

#else

#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)

#define debug_assert(x)

#endif

#define first_nil_offset         50     // GC collector marks from here up

//
// A vector of 50 words is used by the interpreter when preparing args
// for functions and when handling multiple values.
//

#define work_0_offset           250

// Garbage collector marks up to but not including last_nil_offset
#define last_nil_offset         301

//
// NIL_SEGMENT_SIZE must be over-large by enough to allow for
// space lost while rounding nil up to be a multiple of 8. Also in the
// Common Lisp case I need to give myself a spare word BEFORE the place
// where nil points. I also want this to be an even multiple of the
// size of LispObject.
//
#define NIL_SEGMENT_SIZE \
    (((1 + last_nil_offset) & ~1) * sizeof(LispObject) + 32)

// I give myself a margin of SPARE bytes at the end of a page so that I can
// always CONS that amount (even without a garbage collection check) and not
// corrupt anything.  The main use for this is that sometimes I need to
// convert a set of multiple values or of arguments from values on the
// (C-) stack or wherever va_arg() can find them into a list structure, and
// to avoid horrible potential problems with a garbage collection spotting]
// an exception (notably a ^C interrupt), running arbitrary code in an
// exception handler and then continuing, I need to cons those things up
// without any possible GC.  The function cons_no_gc does that, and
// I should then call cons_gc_test() afterwards to regularise the situation.
// 512 bytes here leaves room for 64 conses, and I support at most 50
// (multiple-) values so I hope this is safe.

#define SPARE                   512

// I want my table of addresses here to be 8-byte aligned on 64-bit
// machines...

//            !COMMON  COMMON
//   32-bit    nil       nil
//   64-bit    nil+4     nil


#ifdef CONSERVATIVE
extern uintptr_t heapstart;
extern uintptr_t len;
extern uintptr_t xor_chain;
extern uintptr_t vheapstart;
extern uintptr_t vlen;
extern uintptr_t vxor_chain;

extern bool gcTest;
extern bool gcTrace;

#else // !CONSERVATIVE
extern uintptr_t stackLimit;
#endif // !CONSERVATIVE

extern atomic<uintptr_t> event_flag;

extern intptr_t nwork;

extern unsigned int exit_count;
extern uint64_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;

extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key,rest_key;
extern LispObject char_0_symbol, quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject list_symbol, liststar_symbol, eq_symbol, eql_symbol;
extern LispObject cl_equal_symbol, equal_symbol, equalp_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject go_symbol, cond_symbol;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table, progn_symbol, gcknt_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef_symbol, savedefs_symbol, lose_symbol, comp_symbol;
extern LispObject compiler_symbol, faslvec, tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2, active_stream, current_module;
extern LispObject mv_call_symbol, features_symbol, lisp_package;
#define REHASHVEC_SIZE 1000 // 1000
extern LispObject sys_hash_table, rehash_vec1, rehash_vec2;
extern LispObject help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject startup_symbol, mv_call_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, funcall_symbol, autoload_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, current_function, keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol, expand_def_symbol, allow_key_key;
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;
extern LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
extern LispObject builtin3_symbol, builtin4_symbol;

#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject, int nargs, ...);
extern LispObject om_openStringDev(LispObject, LispObject, LispObject);
extern LispObject om_closeDev(LispObject, LispObject);
extern LispObject om_setDevEncoding(LispObject, LispObject, LispObject);
extern LispObject om_makeConn(LispObject, LispObject);
extern LispObject om_closeConn(LispObject, LispObject);
extern LispObject om_getConnInDevice(LispObject, LispObject);
extern LispObject om_getConnOutDevice(LispObject, LispObject);
extern LispObject om_connectTCP(LispObject, int nargs, ...);
extern LispObject om_bindTCP(LispObject, LispObject, LispObject);
extern LispObject om_putApp(LispObject, LispObject);
extern LispObject om_putEndApp(LispObject, LispObject);
extern LispObject om_putAtp(LispObject, LispObject);
extern LispObject om_putEndAtp(LispObject, LispObject);
extern LispObject om_putAttr(LispObject, LispObject);
extern LispObject om_putEndAttr(LispObject, LispObject);
extern LispObject om_putBind(LispObject, LispObject);
extern LispObject om_putEndBind(LispObject, LispObject);
extern LispObject om_putBVar(LispObject, LispObject);
extern LispObject om_putEndBVar(LispObject, LispObject);
extern LispObject om_putError(LispObject, LispObject);
extern LispObject om_putEndError(LispObject, LispObject);
extern LispObject om_putObject(LispObject, LispObject);
extern LispObject om_putEndObject(LispObject, LispObject);
extern LispObject om_putInt(LispObject, LispObject, LispObject);
extern LispObject om_putFloat(LispObject, LispObject, LispObject);
extern LispObject om_putByteArray(LispObject, LispObject, LispObject);
extern LispObject om_putVar(LispObject, LispObject, LispObject);
extern LispObject om_putString(LispObject, LispObject, LispObject);
extern LispObject om_putSymbol(LispObject, LispObject, LispObject);
extern LispObject om_putSymbol2(LispObject, int nargs, ...);
extern LispObject om_getApp(LispObject, LispObject);
extern LispObject om_getEndApp(LispObject, LispObject);
extern LispObject om_getAtp(LispObject, LispObject);
extern LispObject om_getEndAtp(LispObject, LispObject);
extern LispObject om_getAttr(LispObject, LispObject);
extern LispObject om_getEndAttr(LispObject, LispObject);
extern LispObject om_getBind(LispObject, LispObject);
extern LispObject om_getEndBind(LispObject, LispObject);
extern LispObject om_getBVar(LispObject, LispObject);
extern LispObject om_getEndBVar(LispObject, LispObject);
extern LispObject om_getError(LispObject, LispObject);
extern LispObject om_getEndError(LispObject, LispObject);
extern LispObject om_getObject(LispObject, LispObject);
extern LispObject om_getEndObject(LispObject, LispObject);
extern LispObject om_getInt(LispObject, LispObject);
extern LispObject om_getFloat(LispObject, LispObject);
extern LispObject om_getByteArray(LispObject, LispObject);
extern LispObject om_getVar(LispObject, LispObject);
extern LispObject om_getString(LispObject, LispObject);
extern LispObject om_getSymbol(LispObject, LispObject);
extern LispObject om_getType(LispObject, LispObject);

extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);

extern LispObject om_read(LispObject, LispObject dev);
extern LispObject om_supportsCD(LispObject, LispObject);
extern LispObject om_supportsSymbol(LispObject, LispObject, LispObject);
extern LispObject om_listCDs(LispObject, int nargs, ...);
extern LispObject om_listSymbols(LispObject, LispObject);
extern LispObject om_whichCDs(LispObject, LispObject);
#endif

extern LispObject workbase[51];
#ifdef CONSERVATIVE
extern LispObject ambiguous[10];
#endif // CONSERVATIVE

extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;

#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define mv_4                workbase[4]
#define work_50             workbase[50]

extern void copy_into_nilseg();
extern void copy_out_of_nilseg();

extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char* s, LispObject x);
extern uint64_t hash_equal(LispObject key);

extern char* exit_charvec;

//
// There is no reason to preserve this across restarts etc so making it a
// simple C variable makes it easier for me to initialise it early.
//
extern intptr_t exit_reason;

extern int procstackp;

extern bool garbage_collection_permitted;

extern int csl_argc;
extern const char** csl_argv;
extern bool fasl_output_file;
extern size_t output_directory;

extern LispObject* repeat_heap;
extern size_t repeat_count;

#ifdef BUILTIN_IMAGE
extern const unsigned char* binary_read_filep;
#else
extern std::FILE *binary_read_file;
#endif

extern std::FILE *binary_write_file;

extern uint32_t symbol_sequence;
extern size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
inline unsigned char& boffo_char(int i)
{   return basic_ucelt(boffo, i);
}

extern char** loadable_packages;
extern char** switches;
extern void review_switch_settings();

#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif

extern void report_file(const char* s);

extern int errorset_min, errorset_max;

extern bool force_verbos, force_echo, force_backtrace;
extern bool ignoreLoadTime;
extern bool stop_on_error;
extern uint64_t force_cons, force_vec;

extern int init_flags;

extern const char* standard_directory;

extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern uint64_t reclaim_trigger_count, reclaim_trigger_target;

#ifdef CONSERVATIVE
extern void reclaim(const char* why);
#else // CONSERVATIVE
extern LispObject reclaim(LispObject value_to_return, const char* why,
                          int stg_class, size_t size);
#endif // CONSERVATIVE
extern void use_gchook(LispObject arg);

extern uint64_t force_cons, force_vec;
extern bool next_gc_is_hard;

inline bool cons_forced(size_t n)
{
#ifdef DEBUG
    if (force_cons == 0) return false;
    if (force_cons <= n)
    {   force_cons = 0;
        next_gc_is_hard = true;
        return true;
    }
    force_cons -= n;
#endif
    return false;
}

inline bool vec_forced(size_t n)
{
#ifdef DEBUG
    if (force_vec == 0) return false;
    if (force_vec <= n)
    {   force_vec = 0;
        next_gc_is_hard = true;
        return true;
    }
    force_vec -= n;
#endif
    return false;
}

#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4

#define Lispify_predicate(p)  ((p) ? lisp_true : nil)

//
// variables used by the IO system.
//

extern int tty_count;
extern std::FILE* spool_file;
extern char spool_file_name[128];

//
// If there is no more than 100 bytes of data then I will deem
// file compression frivolous.  The compression code assumes that
// it has at least 2 bytes to work on, so do NOT cut this limit down to zero.
// Indeed more than that the limit must be greater than the length of
// the initial header record (112 bytes).
//

#define CODESIZE                0x1000

typedef struct _entry_point0
{   no_args* p;
    const char* s;
} entry_point0;

typedef struct _entry_point1
{   one_arg* p;
    const char* s;
} entry_point1;

typedef struct _entry_point2
{   two_args* p;
    const char* s;
} entry_point2;

typedef struct _entry_point3
{   three_args* p;
    const char* s;
} entry_point3;

typedef struct _entry_point4up
{   fourup_args* p;
    const char* s;
} entry_point4up;

extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4up entries_table4up[];
extern entry_point1 entries_tableio[];

extern const char* linker_type;
extern const char* compiler_command[];
extern const char* import_data[];
extern const char* config_header[];
extern const char* csl_headers[];

extern LispObject encapsulate_pointer(void*);
extern void* extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject, LispObject a);
//typedef void initfn(LispObject*, LispObject**, LispObject*volatile*);

extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);

extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char* s, size_t len);

#define IMAGE_CODE  ((size_t)(-1000))
#define HELP_CODE   ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))

#define IOPEN_OUT       0
#define IOPEN_IN        1

extern bool Iopen(const char* name, size_t len, int dirn,
                  char* expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char* expanded_name, size_t hard,
                      int sixtyfour);
extern bool Iwriterootp(char* expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep1(int i, const char* name, size_t len,
                      char* datestamp,
                      size_t* size, char* expanded_name);
extern bool Imodulep(const char* name, size_t len, char* datestamp,
                     size_t* size, char* expanded_name);
extern char* trim_module_name(char* name, size_t* lenp);
extern bool Icopy(const char* name, size_t len);
extern bool Idelete(const char* name, size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int  Igetc();
extern bool Iread(void* buff, size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void* buff, size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int  Zgetc();
extern bool Zread(void* buff, size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void* buff, size_t size);
extern long int Ioutsize();
extern const char* CSLtmpdir();
extern const char* CSLtmpnam(const char* suffix, size_t suffixlen);
extern int Cmkdir(const char* s);
extern char* look_in_lisp_variable(char* o, int prefix);

extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char* data, size_t len);
extern void CSL_MD5_Final(unsigned char* md);
extern bool CSL_MD5_busy;
extern unsigned char* CSL_MD5(unsigned char* data, int n,
                              unsigned char* md);
extern void checksum(LispObject a);

extern void ensure_screen();
extern int window_heading;
[[noreturn]] extern void my_exit();

extern uint64_t base_time;
extern std::chrono::high_resolution_clock::time_point base_walltime;
extern uint64_t gc_time;
extern bool trap_floating_overflow;
extern const volatile char* errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject* , bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
extern void set_up_signal_handlers();
extern int async_interrupt(int a);

extern void record_get(LispObject tag, bool found);

//
// Functions used internally - not to be installed in Lisp function
// cells, but some of these may end up getting called using special
// non-standard conventions when the Lisp compiler has been at work.
//

// Note that some things here are declared to use C rather than C++ linkage.
// These are things that will be exported for use by other applications that
// might arrange to build CSL/Reduce as a DLL and hook into it from outside.
// See impex.def for the list of names where this can happen. I have not tried
// building CSL as a DLL for some while and so I expect that any attempt to
// do so would call for careful review of linkage styles etc!

extern bool        isprime(uint64_t);
extern LispObject  set_up_functions(int restartp);
extern void        get_user_files_checksum(unsigned char* );
extern LispObject  acons(LispObject a, LispObject b, LispObject c);
extern LispObject  ash(LispObject a, LispObject b);
extern LispObject  bytestream_interpret(size_t ppc, LispObject lit,
                                        LispObject* entry_stack);
extern bool        complex_stringp(LispObject a);
extern LispObject  copy_string(LispObject a, size_t n);
extern LispObject  characterify_string(LispObject str);
extern LispObject  freshline_stdout();
extern LispObject  freshline_trace();
extern LispObject  freshline_debug();
extern LispObject  cons(LispObject a, LispObject b);
extern LispObject  cons_no_gc(LispObject a, LispObject b);
extern LispObject  acons_no_gc(LispObject a, LispObject b,
                               LispObject c);
extern LispObject  cons_gc_test(LispObject a);
extern void        convert_fp_rep(void* p, int old_rep, int new_rep, int type);
extern LispObject  eval(LispObject u, LispObject env);
extern uint32_t    Crand();
extern LispObject  Cremainder(LispObject a, LispObject b);
extern void        Csrand(uint64_t a);
extern void        discard(LispObject a);
extern bool        eql_fn(LispObject a, LispObject b);
extern bool        cl_equal_fn(LispObject a, LispObject b);
extern bool        equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool        traced_equal_fn(LispObject a, LispObject b,
                                   const char* , int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void        dump_equals();
#endif
extern bool        equalp(LispObject a, LispObject b);
extern LispObject  apply(LispObject fn, LispObject args,
                         LispObject env,
                         LispObject from);
extern LispObject  apply_lambda(LispObject def, LispObject args,
                                LispObject env, LispObject name);
extern void        deallocate_pages();
extern void        drop_heap_segments();
extern LispObject  gcd(LispObject a, LispObject b);
extern LispObject  get_pname(LispObject a);
extern LispObject  get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject  get_basic_vector(int tag, int type, size_t length);
extern LispObject  get_basic_vector_init(size_t n, LispObject v);
extern LispObject  reduce_basic_vector_size(LispObject v, size_t len);
extern LispObject  get_vector(int tag, int type, size_t length);
extern LispObject  get_vector_init(size_t n, LispObject v);
extern LispObject  reduce_vector_size(LispObject n, size_t length);
extern void        prepare_for_borrowing();

inline void zero_out(void* p)
{
#if 0
// At an earlier stage I explicitly zeroed out pages of memory with the
// view that if things went wrong that would avoid confusion when looking
// at the wreckage. Now is the time to cease putting in that extra
// overhead.
    char* p1 = reinterpret_cast<char* >(
        doubleword_align_up(reinterpret_cast<uintptr_t>(p)));
    std::memset(p1, 0, CSL_PAGE_SIZE);
#endif // 0
}
extern LispObject borrow_basic_vector(int tag, int type, size_t length);
extern LispObject borrow_vector(int tag, int type, size_t length);
extern void       finished_borrowing();
extern uint64_t   hash_lisp_string(LispObject s);
extern bool       geq2(LispObject a, LispObject b);
extern bool       greaterp2(LispObject a, LispObject b);
extern bool       lesseq2(LispObject a, LispObject b);
extern bool       lessp2(LispObject a, LispObject b);
extern LispObject list2(LispObject a, LispObject b);
extern LispObject list2star(LispObject a, LispObject b, LispObject c);
extern LispObject list2starrev(LispObject a, LispObject b, LispObject c);
extern LispObject list3(LispObject a, LispObject b, LispObject c);
extern LispObject list3rev(LispObject a, LispObject b, LispObject c);
extern LispObject list3star(LispObject a, LispObject b,
                            LispObject c, LispObject d);
extern LispObject list4(LispObject a, LispObject b,
                        LispObject c, LispObject d);
extern LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char* b);
extern LispObject make_nstring(const char* b, size_t n);
extern LispObject make_undefined_symbol(const char* s);
extern LispObject make_symbol(char const* s, int restartp,
                              no_args* f0, one_arg* f1, two_args* f2,
                              three_args* f3, fourup_args* f4up);
extern void stdout_printf(const char* fmt, ...);
extern void term_printf(const char* fmt, ...);
extern void err_printf(const char* fmt, ...);
extern void debug_printf(const char* fmt, ...);
extern void trace_printf(const char* fmt, ...);
extern const char* my_getenv(const char* name);
extern LispObject  ncons(LispObject a);
extern LispObject  ndelete(LispObject a, LispObject b);
extern LispObject  negate(LispObject a);
extern LispObject  nreverse(LispObject a);
extern LispObject  nreverse2(LispObject a, LispObject b);
extern std::FILE*  open_file(char* filename,
                             const char* original_name,
                             size_t n, const char* dirn,
                             std::FILE* old_file);
extern LispObject  plus2(LispObject a, LispObject b);
extern void        preserve(const char* msg, size_t len);
extern LispObject prin(LispObject u);
extern void debugprint(LispObject a, int depth=10);
extern void debugprint(const char* s, LispObject a);
extern void debugprint(const char* s);
extern const char* get_string_data(LispObject a, const char* why, size_t &len);
extern LispObject prin_to_stdout(LispObject u);
extern LispObject prin_to_terminal(LispObject u);
extern LispObject prin_to_debug(LispObject u);
extern LispObject prin_to_query(LispObject u);
extern LispObject prin_to_trace(LispObject u);
extern LispObject prinhex_to_trace(const char* msg, LispObject value);
extern LispObject prin_to_error(LispObject u);
extern LispObject loop_print_stdout(LispObject o);
extern LispObject loop_print_terminal(LispObject o);
extern LispObject loop_print_debug(LispObject o);
extern LispObject loop_print_query(LispObject o);
extern LispObject loop_print_trace(LispObject o);
extern LispObject loop_print_error(LispObject o);
extern LispObject internal_prin(LispObject u, int prefix);
extern LispObject  princ(LispObject u);
extern LispObject  print(LispObject u);
extern LispObject  printc(LispObject u);
extern void        print_bignum(LispObject u, bool blankp, int nobreak);
extern void        print_bighexoctbin(LispObject u, int radix, int width,
                                      bool blankp, int nobreak);
extern void        print_newbignum(LispObject u, bool blankp, int nobreak);
extern void        print_newbighexoctbin(LispObject u,
        int radix, int width, bool blankp, int nobreak);
extern LispObject  putprop(LispObject a, LispObject b,
                           LispObject c);
extern LispObject  quot2(LispObject a, LispObject b);
extern LispObject  quotrem2(LispObject a, LispObject b);
extern LispObject  rational(LispObject a);
extern LispObject  read_eval_print(int noisy);
extern void        set_fns(LispObject sym, no_args* f0, one_arg* f1,
                           two_args* f2, three_args* f3, fourup_args* f4up);
extern void        init_heap_segments(double size);
extern void        grab_more_memory(size_t npages);
extern bool        allocate_more_memory();
extern void        setup(int restartp, double storesize);
extern LispObject  set_up_variables(int restart_flag);
extern void        warm_setup();
extern void        write_everything();
extern LispObject  simplify_string(LispObject s);
extern bool        stringp(LispObject a);
extern LispObject  times2(LispObject a, LispObject b);
extern int32_t     thirty_two_bits(LispObject a);
extern uint32_t    thirty_two_bits_unsigned(LispObject a);
extern int64_t     sixty_four_bits(LispObject a);
extern uint64_t    sixty_four_bits_unsigned(LispObject a);

extern uint64_t    crc64(uint64_t crc, const void* buf, size_t size);

#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char* f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) // nothing
#endif

// The next few provide support for multiple values.
// At present I do what may count as the naive thing and every function
// leaves the variable exit_count set to indicate how many results it is
// returning.

inline LispObject onevalue(LispObject r)
{   exit_count = 1;
    return r;
}

inline LispObject nvalues(LispObject r, int n)
{   exit_count = n;
    return r;
}

// If I define an instance of SingleValued at the head of a procedure
// then every exit from it will set exit_count to 1. This would let me
// write just "return x;" rather than "return onevalue(x);".

class SingleValued
{
public:
    SingleValued()
    {}
    ~SingleValued()
    {   exit_count = 1;
    }
};

// If I know how many results some function should deliver (and it is > 1)
// I can use this at the procedure head.

class MultiValued
{
    int n;
public:
    MultiValued(int nn)
    {   n = nn;
    }
    ~MultiValued()
    {   exit_count = n;
    }
};

//
// The function "equal" seems to be pretty critical (certainly for Standard
// Lisp mode and Reduce). So I write out the top-level part of it in-line
// and only call the (messy) function in cases where it might be worth-while.
// For Common Lisp I will presumably look at eql and cl_equal as well.
// The test here says:
//   If a and b are EQ then they are EQUAL,
//   else if a and b have different types they are not EQUAL
//   else if a has type fixnum, odds, sfloat, symbol
//            then they are not EQUAL (those types need to be EQ to be EQUAL)
//   otherwise call equal_fn(a, b) to decide the issue.
//

// If I am using TRACED_EQUAL then the inline function defeats my attempt to
// keep track of where equal() is called from - so I revert to use of a macro.

#ifdef TRACED_EQUAL
#define equal(a, b)                                  \
   ((a == b) ? true :                                \
    ((a & TAG_BITS) != (b & TAG_BITS)) ? false :     \
    (need_more_than_eq(a)) ? equal_fn(a, b) :        \
    false)
#else
inline bool equal(LispObject a, LispObject b)
{   if (a == b) return true;  // This may be bad for (equal NaN NaN) ?
    else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
    else if (need_more_than_eq(a)) return equal_fn(a, b);
    else return false;
}
#endif

#ifdef TRACED_EQUAL
#define cl_equal(a, b)                            \
   ((a == b) ? true :                             \
    ((a & TAG_BITS) != (b & TAG_BITS)) ? false :  \
    (need_more_than_eq(a)) ? cl_equal_fn(a, b) :  \
    false)
#else
inline bool cl_equal(LispObject a, LispObject b)
{   if (a == b) return true;  // This may be bad for (equal NaN NaN) ?
    else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
    else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
    else return false;
}
#endif

inline bool eql(LispObject a, LispObject b)
{   if (a == b) return true;  // This may be bad for (equal NaN NaN) ?
    else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
    else if (need_more_than_eq(a)) return eql_fn(a, b);
    else return false;
}

extern no_args*     no_arg_functions[];
extern one_arg*     one_arg_functions[];
extern two_args*    two_arg_functions[];
extern three_args*  three_arg_functions[];
extern fourup_args* fourup_arg_functions[];

extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool three_arg_traceflags[];
extern bool fourup_arg_traceflags[];

extern const char* no_arg_names[];
extern const char* one_arg_names[];
extern const char* two_arg_names[];
extern const char* three_arg_names[];
extern const char* fourup_arg_names[];


typedef struct setup_type
{   const char* name;
    no_args* zero;
    one_arg* one;
    two_args* two;
    three_args* three;
    fourup_args* fourup;
    int nargs;
} setup_type;

// In many cases a function will take a fixed number of arguments,
// and these will make those cases tidier to express.

#define DEF_0(name, code)   {name, code, G1W0, G2W0, G3W0, G4W0}
#define DEF_1(name, code)   {name, G0W1, code, G2W1, G3W1, G4W1}
#define DEF_2(name, code)   {name, G0W2, G1W2, code, G3W2, G4W2}
#define DEF_3(name, code)   {name, G0W3, G1W3, G2W3, code, G4W3}
#define DEF_4up(name, code) {name, G0W4up, G1W4up, G2W4up, G3W4up, code}

extern setup_type const
arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
              arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
              eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
              lisphash_setup[], print_setup[], read_setup[],
              restart_setup[], mpi_setup[];
#ifdef ARITHLIB
extern setup_type const arith_setup[];
#endif

extern setup_type const
u01_setup[], u02_setup[], u03_setup[], u04_setup[],
          u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
          u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
          u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
          u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
          u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
          u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
          u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
          u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
          u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
          u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
          u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
          u60_setup[];

extern setup_type const* setup_tables[];

#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif

#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif

extern const char* find_image_directory(int argc, const char* argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
                           LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject go_fn(LispObject args, LispObject env);
extern LispObject cond_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);

//
// The variables here are always extern - they never survive in an image
// file.
//
extern LispObject resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;

//
// Flags used to toggle the protection or otherwise of symbols, and
// whether to warn about attempts to redefine them.
//
extern bool symbol_protect_flag, warn_about_protected_symbols;

#ifdef HASH_STATISTICS
extern uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2,
       Nhputtmp;
extern uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif

#ifdef DEBUG
extern size_t intern_count;
extern size_t fullest_package;
extern size_t fullest_hash_table;
#endif

#endif // header_externs_h

// end of externs.h
