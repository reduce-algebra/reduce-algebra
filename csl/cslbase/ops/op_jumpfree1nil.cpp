// op_jumpfree1nil.cpp

#if defined BYTECODE
            case OP_JUMPFREE1NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 1)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPFREE1NIL:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPFREE1NIL:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPFREE1NIL:
                myabort("Unsupported architecture");

#endif
