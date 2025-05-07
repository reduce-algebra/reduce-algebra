s/main/psl_main/g
s/\*jumphugo %eax/jmp  \*%eax/g
s/\*toxmm0 (reg rdi)/movsd (%rdi),%xmm0/g
s/\*fromxmm0 (Reg 1)/movsd  %xmm0,%rax/g
s/mov \[\[/mov $\[\[/g
s/cmp \[\[/cmp $\[\[/g
 
