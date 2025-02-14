// op_loadfree2.cpp

#if defined BYTECODE
            case OP_LOADFREE2:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 2));
                continue;

#elif defined __x86_64__

            case OP_LOADFREE2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADFREE2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADFREE2:
                unfinished("Unsupported architecture");

#endif
