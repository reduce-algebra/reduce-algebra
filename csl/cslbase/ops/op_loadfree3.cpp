// op_loadfree3.cpp

#if defined BYTECODE
            case OP_LOADFREE3:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 3));
                continue;

#elif defined __x86_64__

            case OP_LOADFREE3:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADFREE3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADFREE3:
                unfinished("Unsupported architecture");

#endif
