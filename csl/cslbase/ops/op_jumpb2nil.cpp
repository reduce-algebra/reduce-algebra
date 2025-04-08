// jumpb2nil.cpp $Id$

#if defined BYTECODE
            case OP_JUMPB2NIL:
                f2 = two_arg_functions[next_byte];
                A_reg = f2(nil, B_reg, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPB2NIL:
                next = bytes[ppc++];
                loadstatic(w, OJITshim2L);
                mov(w1, two_arg_functions[next]);
                JITcall(w, w2,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                cmp(w2, nilreg);
                next = bytes[ppc++];
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPB2NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpb2nil.cpp
