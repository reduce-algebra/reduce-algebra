#! /bin/bash

# source this file to set up emscripten options

CATCHERS="main,bytestream_interpret1,lisp_main,setupArgs,cslstart,\
fwin_main,read_eval_print,Lrdf4,apply_lambda,block_fn,catch_fn.letstar_fn,\
prog_fn,tagbody_fn,unwind_protect_fn,errorset3,resource_limit7,bytecoded_1,\
bytecoded_2,bytecoded_3,bytecoded_4up,byteopt,change_directory,\
create_directory,execute_lisp_function,allocateSegment,set_up_variables,\
wait_for_char,eval,macroexpand_1,progn_fn,subst,substq,subla,sublis,Igetc,\
execute_lisp_function1,write_result,Lparallel,PROC_load_package,\
PROC_set_switch,PROC_push_symbol,PROC_push_string,PROC_push_small_integer,\
PROC_push_big_integer,PROC-push_floating,PROC_make_function_call,PROC_load,\
PROC_dup,PROC_simplify,PROC_lisp_eval,PROC_make_printable,prin_to_terminal,\
prin_to_stdout,prin_to_error,prin_to_trace,prinhex_to_trace,prin_to_debug,\
prin_to_query,raw_char_from_terminal,raw_char_from_file,Lrdf4,error,cerror,\
interrupted,aerror,aerror0,aerror1,aerror2,aerror3"

# Use of these two breaks things! I wonder if the names passed in
# CATCHERS need to be mangled? Or if I have missed some critical ones.
# But on the4 web I see EXCEPTION_CATCHING_WHITELIST and also mention of
# need for name mangling...
# Also does having a destructor for a locally declared object that must
# be called on unwinding interact here, as in RAII stuff. If so I have
# yet more functions to tag. 
#  -s DISABLE_EXCEPTION_CATCHING=2 \
#  -s EXCEPTION_CATCHING_ALLOWED=[$CATCHERS] \

EMFLAGS="\
  -s ABORTING_MALLOC=1 \
  -s ASSERTIONS=1 \
  -s DISABLE_EXCEPTION_CATCHING=0 \
  -s EXIT_RUNTIME=1 \
  -s MALLOC="dlmalloc" \
  -s INITIAL_MEMORY=1024mb \
  -s SAFE_HEAP=0 \
  -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
  -s USE_ZLIB=1 \
  -s USE_CLOSURE_COMPILER=1 \
  -flto"

# -s ALLOW_MEMORY_GROWTH=0 \
# -s TOTAL_STACK=5mb \

# The following are others to consider or experiment with:

# -s WASM_BIGINT=1
# -s EMULATE_FUNCTION_POINTER_CASTS=1
# -s SUPPORT_LONGJMP=1
# -s USE_PTHREADS=1
# -s PTHREAD_POOL_SIZE=nnn
# -s DEFAULT_PTHREAD_STACK_SIZE=nnn

# end if options
