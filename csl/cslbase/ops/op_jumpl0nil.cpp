// op_jumpl0nil.cpp

#if defined BYTECODE
            case OP_JUMPL0NIL:
                xppc = ppc;
                ppc++;
                if (stack[0] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL0NIL:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL0NIL:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPL0NIL:
                myabort("Unsupported architecture");

#endif
