s/main/psl_main/g
s/\*jumphugo %eax/jmp  \*%eax/g
s/mov \[\[/mov $\[\[/g
s/cmp \[\[/cmp $\[\[/g
s/cmp \$68/cmpq $68
 
