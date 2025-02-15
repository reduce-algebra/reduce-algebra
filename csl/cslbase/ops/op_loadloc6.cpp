// op_loadloc6.cpp

#if defined BYTECODE
            case OP_LOADLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC6:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLOC6:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC6:
                unfinished("Unsupported architecture");

#endif
