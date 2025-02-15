// op_swop.cpp

#if defined BYTECODE
            case OP_SWOP:
                r1 = B_reg;
                B_reg = A_reg;
                A_reg = r1;
                continue;

#elif defined __x86_64__

            case OP_SWOP:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_SWOP:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SWOP:
                unfinished("Unsupported architecture");

#endif
