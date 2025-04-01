// getv.cpp

#if defined BYTECODE
            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                A_reg = Lgetv(nil, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_GETV:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                unfinished("Unsupported architecture");

#endif

// end of op_getv.cpp
