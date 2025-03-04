// op_jump_l.cpp

#if defined BYTECODE
            case OP_JUMP_L:
                w = next_byte;
                ppc++;
                long_jump(w, ppc, ppc-1, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMP_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cc.jmp(perInstruction[ppc+next-1]);
                break;

#elif defined __aarch64__

            case OP_JUMP_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMP_L:
                unfinished("Unsupported architecture");

#endif

// end of op_jump_l.cpp
