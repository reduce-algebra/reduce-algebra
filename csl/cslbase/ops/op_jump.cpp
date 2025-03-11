// op_jump.cpp

#if defined BYTECODE
            case OP_JUMP:
                ppc++;
                short_jump(ppc, ppc-1, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMP:
                next = bytes[ppc++];
                cc.jmp(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMP:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMP:
                unfinished("Unsupported architecture");

#endif

// end of op_jump.cpp
