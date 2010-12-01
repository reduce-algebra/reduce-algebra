s/ main/ psl_main/g
s/^main:/psl_main:/g
s/\*jumphugo %rax/jmp  \*%rax/g
s/cmp \$215/cmpq $215/g

