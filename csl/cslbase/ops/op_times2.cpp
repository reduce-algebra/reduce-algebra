// times2.cpp

#if defined BYTECODE
            case OP_TIMES2:
// I do not in-line even the integer case here, since overflow checking
// is a slight mess.
#ifdef ARITHLIB
                A_reg = Times::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = times2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_TIMES2:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_TIMES2:
                unfinished("Unsupported architecture");

#endif

// end of times2.cpp
