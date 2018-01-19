s/ main/ _psl_main/g
s/^main:/_psl_main:/g
s/\*jumphugo %rax/jmp  \*%rax/g
s/\*callhugo %rax/call  \*%rax/g
s/cmp \$/cmpq \$/g
s/,@/@/g
