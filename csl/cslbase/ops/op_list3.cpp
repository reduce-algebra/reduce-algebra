// list3.cpp $Id$

#if defined BYTECODE
            case OP_LIST3:                  // A_reg = list3(p), B_reg, A_reg);
                // = p) . (B . (A . nil))
                r1 = *stack--;
                A_reg = list3(r1, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LIST3:
                mov(w1, list3);
                loadreg_post(w2, spreg, -8);
                JITcall(JITshim3, A_reg,
                        w1, w2, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_LIST3:                  // A_reg = list3(p), B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_list3.cpp
