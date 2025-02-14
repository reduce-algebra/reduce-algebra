// op_jump_l.cpp

#if defined BYTECODE
            case OP_JUMP_L:
                w = next_byte;
                ppc++;
                long_jump(w, ppc, ppc-1, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMP_L:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMP_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMP_L:
                unfinished("Unsupported architecture");

#endif
