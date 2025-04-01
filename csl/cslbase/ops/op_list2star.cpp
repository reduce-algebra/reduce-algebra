// list2star.cpp $Id$

#if defined BYTECODE
            case OP_LIST2STAR:              // A_reg = list2!*(p), B_reg, A_reg);
                // = p) . (B . A)
                r1 = *stack--;
                A_reg = list2star(r1, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LIST2STAR:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_LIST2STAR:              // A_reg = list2!*(p), B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_list2star.cpp
