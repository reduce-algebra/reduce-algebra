s/old_heap/oldheap/g
s/.globl symval/.globl _symval\
 .globl symval\
_symval:/1
#clear 0x08000000 bit in symnam table
/^symval:/,/^symfnc:/s/4\*0x8000000/3\*0x8000000/
