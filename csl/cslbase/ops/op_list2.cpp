// list2.cpp $Id$

#if defined BYTECODE
            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                A_reg = list2(B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LIST2:
                loadstatic(w, OJITshim2);
                loadstatic(w1, OJITlist2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                unfinished("Unsupported architecture");

#endif

// end of op_list2.cpp
