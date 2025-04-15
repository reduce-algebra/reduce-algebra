// $Id$

#if defined BYTECODE
            case OP_JUMP_B:
                ppc++;
                short_jump_back(ppc, ppc-1, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMP_B:
                next = bytes[ppc++];
                jmp(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMP_B:
                unfinished("Unsupported architecture");

#endif

// end of jump_b.cpp


