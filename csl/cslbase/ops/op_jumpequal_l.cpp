// jumpequal_l.cpp $Id$

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
                loadstatic(w, OJITshim2L);
                loadstatic(w1, OJITLequal);  // Either standard or common!
                JITcall(w, w,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                test(w, 0xff);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPEQUAL_L:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpequal_l.cpp
