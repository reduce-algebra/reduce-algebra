 PUBLIC argumentblock
 ALIGN 4
argumentblock  DB  64 DUP (0)
 PUBLIC tokenbuffer
 ALIGN 4
tokenbuffer  DB  20004 DUP (0)
 PUBLIC bndstk
 ALIGN 4
bndstk  DB  8004 DUP (0)
 PUBLIC catchstack
 ALIGN 4
catchstack  DB  6404 DUP (0)
 PUBLIC hashtable
 ALIGN 4
hashtable  DB  36028 DUP (0)
 PUBLIC onewordbuffer
 ALIGN 4
onewordbuffer  DB  8 DUP (0)
 PUBLIC saveargc
 ALIGN 4
saveargc  DB  8 DUP (0)
 PUBLIC saveargv
 ALIGN 4
saveargv  DB  8 DUP (0)
 PUBLIC datebuffer
 ALIGN 4
datebuffer  DB  8 DUP (0)
