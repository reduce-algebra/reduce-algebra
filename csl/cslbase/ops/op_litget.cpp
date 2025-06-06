// $Id$

#if defined BYTECODE
            case OP_LITGET:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                A_reg = get(B_reg, A_reg, nil);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LITGET:
                next = bytes[ppc++];
                mov(w1, get);
                mov(B_reg, A_reg);
                loadlit(A_reg, next);
                JITcall(JITshim3, A_reg,
                        w1, B_reg, A_reg, nilreg);
                JITerrorcheck();
                break;

#else
            case OP_LITGET:
                unfinished("Unsupported architecture");

#endif

// end of op_litget.cpp
