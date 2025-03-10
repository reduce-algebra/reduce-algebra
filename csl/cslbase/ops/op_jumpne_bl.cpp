// op_jumpne_bl.cpp

#if defined BYTECODE
            case OP_JUMPNE_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNE_BL:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cc.cmp(A_reg, B_reg);
                cc.jne(perInstruction[ppc-next]);
                break;

#elif defined __aarch64__

            case OP_JUMPNE_BL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNE_BL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpne_bl.cpp
