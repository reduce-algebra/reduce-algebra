// op_jump.cpp

#if defined BYTECODE
            case OP_JUMP:
                ppc++;
                short_jump(ppc, ppc-1, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMP:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMP:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMP:
                myabort("Unsupported architecture");

#endif
