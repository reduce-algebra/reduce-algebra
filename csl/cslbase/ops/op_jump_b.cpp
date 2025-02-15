// op_jump_b.cpp

#if defined BYTECODE
            case OP_JUMP_B:
                ppc++;
                short_jump_back(ppc, ppc-1, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMP_B:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMP_B:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMP_B:
                unfinished("Unsupported architecture");

#endif
