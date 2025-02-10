// op_storeloc3.cpp

#if defined BYTECODE
            case OP_STORELOC3:
                stack[-3] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC3:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_STORELOC3:
                myabort("This case not yet implemented for ARM");

#else
            case OP_STORELOC3:
                myabort("Unsupported architecture");

#endif
