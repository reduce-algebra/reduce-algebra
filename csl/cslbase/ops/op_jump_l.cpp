// jump_l.cpp

#if defined BYTECODE
            case OP_JUMP_L:
                w = next_byte;
                ppc++;
                long_jump(w, ppc, ppc-1, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMP_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                jmp(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMP_L:
                unfinished("Unsupported architecture");

#endif

// end of jump_l.cpp
