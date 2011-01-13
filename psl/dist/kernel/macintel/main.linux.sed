s/main/_psl_main/g
s/\*jumphugo %eax/jmp  \*%eax/g
s/mov \[\[/movl $\(\(/g
s/mov /movl /g
s/mov %cx/movw %cx/g
s/inc /incl /g
s/cmp \[\[/cmp $\(\(/g
s/cmp /cmpl /g
s/\[/\(/g
s/\]/\)/g
s/\\//g
s/ os:/ /g
s/L0/MZL0/g
s/HASHTABLE/_HASHTABLE/g
s/symval/_symval/
s$^/$//$


