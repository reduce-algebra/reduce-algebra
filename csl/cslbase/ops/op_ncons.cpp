// ncons.cpp $Id$

#if defined BYTECODE
            case OP_NCONS:                   // A_reg = cons(A_reg, nil);
                {   A_reg = ncons(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_NCONS:
                loadstatic(w1, OJITncons);
                JITcall(JITshim1, A_reg,
                        w1, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_NCONS:                   // A_reg = cons(A_reg, nil);
                unfinished("Unsupported architecture");

#endif

// end of op_ncons.cpp
