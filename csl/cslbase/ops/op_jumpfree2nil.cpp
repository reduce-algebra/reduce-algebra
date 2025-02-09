// op_jumpfree2nil.cpp

#if defined BYTECODE
            case OP_JUMPFREE2NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPFREE2NIL:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPFREE2NIL:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPFREE2NIL:
                myabort("Unsupported architecture");

#endif
