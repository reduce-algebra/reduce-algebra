// op_storeloc1.cpp

#if defined BYTECODE
            case OP_STORELOC1:
                stack[-1] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_STORELOC1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC1:
                unfinished("Unsupported architecture");

#endif
