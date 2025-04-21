// $Id$

#if defined BYTECODE
            case OP_JUMPNEQUAL:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump(ppc, xppc, codevec);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNEQUAL:
                next = bytes[ppc++];
                mov(w1, Lequal);  // Either standard or common!
                JITcall(JITshim2L, w,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPNEQUAL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpnequal.cpp
