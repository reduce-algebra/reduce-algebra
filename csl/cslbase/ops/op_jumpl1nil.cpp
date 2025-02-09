// op_jumpl1nil.cpp

#if defined BYTECODE
            case OP_JUMPL1NIL:
                xppc = ppc;
                ppc++;
                if (stack[-1] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL1NIL:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL1NIL:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPL1NIL:
                myabort("Unsupported architecture");

#endif
