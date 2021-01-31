#! /bin/bash

# source this file to set up emscripten options.
# Well "bash" has a "source" command, but in general "sh" will not, so
# it ir probably best to get used to going ". ./emflags.sh"


EMFLAGS="\
  -s ABORTING_MALLOC=1 \
  -s ASSERTIONS=1 \
  -s DISABLE_EXCEPTION_CATCHING=1 \
  -s EXIT_RUNTIME=1 \
  -s MALLOC="dlmalloc" \
  -s INITIAL_MEMORY=1024mb \
  -s SAFE_HEAP=0 \
  -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
  -s USE_ZLIB=1 \
  -s USE_CLOSURE_COMPILER=1 \
  -flto"


# The following are others to consider or experiment with:

# -s ALLOW_MEMORY_GROWTH=0 \
# -s TOTAL_STACK=5mb \
# -s WASM_BIGINT=1
# -s EMULATE_FUNCTION_POINTER_CASTS=1
# -s SUPPORT_LONGJMP=1
# -s USE_PTHREADS=1
# -s PTHREAD_POOL_SIZE=nnn
# -s DEFAULT_PTHREAD_STACK_SIZE=nnn

# end of options
