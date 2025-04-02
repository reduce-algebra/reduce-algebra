// length.cpp $Id$

#if defined BYTECODE
            case OP_LENGTH:
                A_reg = Llength(nil, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LENGTH:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_LENGTH:
                unfinished("Unsupported architecture");

#endif

// end of op_length.cpp
