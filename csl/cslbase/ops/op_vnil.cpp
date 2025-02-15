// op_vnil.cpp

#if defined BYTECODE
            case OP_VNIL:
                B_reg = A_reg;
                A_reg = nil;
                continue;

#elif defined __x86_64__

            case OP_VNIL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_VNIL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_VNIL:
                unfinished("Unsupported architecture");

#endif
