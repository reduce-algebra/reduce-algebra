s/^main/_psl_main/
s/ main/ _psl_main/g
s/\*jumphugo %rax/jmp  \*%rax/g
s/mov \[\[/mov $\[\[/g
s/cmp \[\[/cmp $\[\[/g
s/cmp \$/cmpq \$/g
s/,@/@/g
s/lastbps/_lastbps/g
s/heaplowerbound/_heaplowerbound/g
s/heapupperbound/_heapupperbound/g
s/infbitlength/infbitlength/g
s/heaplast/_heaplast/g
s/old_heap/_oldheap/g
s/bpslowerbound/_bpslowerbound/g
s/cmp \$68023/cmpq $68023/g


 
