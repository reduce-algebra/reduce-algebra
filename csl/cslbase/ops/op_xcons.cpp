// xcons.cpp

#if defined BYTECODE
            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                A_reg = cons(A_reg, B_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_XCONS:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_xcons.cpp
