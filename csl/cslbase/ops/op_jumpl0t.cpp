// op_jumpl0t.cpp

#if defined BYTECODE
            case OP_JUMPL0T:
                xppc = ppc;
                ppc++;
                if (stack[0] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL0T:
                next = bytes[ppc++];
                cc.mov(w, ptr(spreg));
                cc.cmp(w, nilreg);
                cc.jne(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPL0T:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL0T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl0.cpp
