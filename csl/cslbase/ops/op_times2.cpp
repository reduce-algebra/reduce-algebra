// op_times2.cpp

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

#elif defined __x86_64__

            case OP_TIMES2:
                cc.mov(w, ptr(nilreg, JIToffset(OJITshim2)));
#ifdef ARITHLIB
                cc.mov(w1, ptr(nilreg, JIToffset(OJITtimesop)));
#else // ARITHLIB
                cc.mov(w1, ptr(nilreg, JIToffset(OJITtimes2)));
#endif // ARITHLIB
                invoke(cc, nilreg, spreg, w, A_reg,
                       w1, B_reg, A_reg);
                cc.cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                cc.jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_TIMES2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_TIMES2:
                unfinished("Unsupported architecture");

#endif

// end of op_times2.cpp
