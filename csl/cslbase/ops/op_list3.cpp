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
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_LIST3:                  // A_reg = list3(p), B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_list3.cpp
