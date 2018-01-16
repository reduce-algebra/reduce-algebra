s/ main/ psl_main/g
s/^main:/psl_main:/g
s/\*jumphugo %rax/jmp  \*%rax/g
s/\*callhugo %rax/callq \*%rax/g
s/cmp \$680/cmpq $680/g
s/cmp \$786433/cmpq $786433/g
s/cmp \$393241/cmpq $393241/g
