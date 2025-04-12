// jumpb2t.cpp $Id$

#if defined BYTECODE
            case OP_JUMPB2T:
                f2 = two_arg_functions[next_byte];
                A_reg = f2(nil, B_reg, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPB2T:
                next = bytes[ppc++];
                mov(w1, two_arg_functions[next]);
                JITcall(JITshim2L, w,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                cmp(w, nilreg);
                next = bytes[ppc++];
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPB2T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpb2t.cpp
