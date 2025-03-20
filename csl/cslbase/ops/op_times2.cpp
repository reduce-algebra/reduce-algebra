// times2.cpp

#if defined BYTECODE
            case OP_TIMES2:
// I do not in-line even the integer case here, since overflow checking
// is a slight mess.
#ifdef ARITHLIB
                A_reg = Times::B_reg, A_reg);
#else // ARITHLIB
                A_reg = times2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_TIMES2:
                mov(w, ptr(nilreg, JIToffset(OJITshim2)));
#ifdef ARITHLIB
                mov(w1, ptr(nilreg, JIToffset(OJITtimes));
#else // ARITHLIB
                mov(w1, ptr(nilreg, JIToffset(OJITtimes2)));
#endif // ARITHLIB
                JITcall(w, A_reg,
                       w1, B_reg, A_reg);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_TIMES2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_TIMES2:
                unfinished("Unsupported architecture");

#endif

// end of times2.cpp
