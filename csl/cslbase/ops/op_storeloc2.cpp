// op_storeloc2.cpp

#if defined BYTECODE
            case OP_STORELOC2:
                stack[-2] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC2:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_STORELOC2:
                myabort("This case not yet implemented for ARM");

#else
            case OP_STORELOC2:
                myabort("Unsupported architecture");

#endif
