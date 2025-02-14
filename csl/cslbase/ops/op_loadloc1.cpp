// op_loadloc1.cpp

#if defined BYTECODE
            case OP_LOADLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLOC1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC1:
                unfinished("Unsupported architecture");

#endif
