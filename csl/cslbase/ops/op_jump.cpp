// jump.cpp $Id$

#if defined BYTECODE
            case OP_JUMP:
                ppc++;
                short_jump(ppc, ppc-1, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMP:
                next = bytes[ppc++];
                jmp(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMP:
                unfinished("Unsupported architecture");

#endif

// end of jump.cpp
