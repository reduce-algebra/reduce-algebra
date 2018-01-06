#! /bin/bash -v

# Investigate cross-building PSL using a different Lisp as base.


# First make the "vsl" mini-lisp with an option that causes its readee
# to be broadly compatible with PSL. Specifically most punctuation
# characters must be constituents of symbols, and a sequence that starts
# off looking like a number can end up as a symbol if continued with
# characters that are neither whitespace nor brackets (or otherwise special).

# The resulting system is copied to the top-level directory for later use.

make clean
make psl

# Load in (interpreted forms of) the PSL compiler and some associated
# utilities, and checkpoint the result.

script -c "./vsl psl-compiler.lsp -opslcomp.img" psl-compiler.log

# Test it

./vsl -ipslcomp.img <<EOF |& tee test-compiler.log 

(trace '(dfprintfasl))

(setq !*echo t) (setq !*plap t) (setq !*pgwd t)

(setq !*writingasmfile t) (setq !*plap t) (setq !*pgwd t)

(flag '(dskin) 'eval)

(asmout "factorial")

(dskin "factorial.sl")

(asmend)

EOF
