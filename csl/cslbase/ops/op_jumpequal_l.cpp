// $Id$

#if defined BYTECODE
            case OP_JUMPEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPEQUAL_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                mov(w1, Lequal);  // Either standard or common!
                JITcall(JITshim2L, w,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPEQUAL_L:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpequal_l.cpp
