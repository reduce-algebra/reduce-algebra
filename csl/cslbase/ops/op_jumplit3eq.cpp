// jumplit3eq.cpp

#if defined BYTECODE
            case OP_JUMPLIT3EQ:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 3)) == A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPLIT3EQ:
                next = bytes[ppc++];
                loadlit(w, 3);
                cmp(A_reg, w);
                je(perInstruction[ppc+next]);
                break;
   
#elif defined __aarch64__

            case OP_JUMPLIT3EQ:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPLIT3EQ:
                unfinished("Unsupported architecture");

#endif

// end of op_jumplit3eq.cpp