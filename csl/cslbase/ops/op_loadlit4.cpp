// op_loadlit4.cpp

#if defined BYTECODE
            case OP_LOADLIT4:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 4);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT4:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLIT4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT4:
                unfinished("Unsupported architecture");

#endif
