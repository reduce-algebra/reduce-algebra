 
s/main/_psl_main/g
s/\*jumphugo %eax/jmp  \*%eax/g
s/mov %cx/movw %cx/g
s/inc /incl /g
s/cmp \[\[/cmp $\(\(/g
s/cmp /cmpl /g
s/L0/MZL0/g
s/HASHTABLE/_HASHTABLE/g
