// op_loadloc.cpp

#if defined BYTECODE
            case OP_LOADLOC:
                B_reg = A_reg;
                A_reg = stack[-static_cast<int>(next_byte)];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLOC:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC:
                unfinished("Unsupported architecture");

#endif
