// get.cpp $Id$

#if defined BYTECODE
            case OP_GET:                                    // A = get(B, A)
                A_reg = get(B_reg, A_reg, nil);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_GET:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_GET:                                    // A = get(B, A)
                unfinished("Unsupported architecture");

#endif

// end of op_get.cpp
