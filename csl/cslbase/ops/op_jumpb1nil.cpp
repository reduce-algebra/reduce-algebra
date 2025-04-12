// jumpb1nil.cpp $Id$

#if defined BYTECODE
            case OP_JUMPB1NIL:
                f1 = one_arg_functions[next_byte];
                A_reg = f1(nil, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPB1NIL:
                next = bytes[ppc++];
                mov(w1, one_arg_functions[next]);
                JITcall(JITshim1L, w2,
                        w1, nilreg, A_reg);
                JITerrorcheck();
                cmp(w2, nilreg);
                next = bytes[ppc++];
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPB1NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpb1nil.cpp
