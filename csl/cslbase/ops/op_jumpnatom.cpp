// jumpnatom.cpp

#if defined BYTECODE
            case OP_JUMPNATOM:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNATOM:
                next = bytes[ppc++];
                test(A_reg, TAG_BITS);
                je(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPNATOM:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNATOM:
                unfinished("Unsupported architecture");

#endif

// end of jumpnatom.cpp
