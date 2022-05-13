 
s/\*jumphugo %eax/jmp  \*%eax/g
s/mov ((/movl $\(\(/g
s/mov /movl /g
s/cmp ((/cmp $\(\(/g
s/inc /incl /g
s/cmp /cmpl /g
s/\\//g
