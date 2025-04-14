// $Id$

#if defined BYTECODE
            case OP_JUMP_BL:
                w = next_byte;
                ppc++;
                long_jump_back(w, ppc, ppc-1, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMP_BL:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                jmp(perInstruction[ppc-next]);
                break;


#else
            case OP_JUMP_BL:
                unfinished("Unsupported architecture");

#endif

// end of jump_bl.cpp
