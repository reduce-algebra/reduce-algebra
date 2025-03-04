// op_jumpatom_bl.cpp

#if defined BYTECODE
            case OP_JUMPATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPATOM_BL:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cc.test(A_reg, 7);
                cc.jne(perInstruction[ppc-next-1]);
                break;

#elif defined __aarch64__

            case OP_JUMPATOM_BL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPATOM_BL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpatom_bl.cpp
