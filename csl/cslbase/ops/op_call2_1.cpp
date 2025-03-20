// call2_1.cpp

#if defined BYTECODE
            case OP_CALL2_1:
                fname = 1;
                goto call2;

#elif defined __x86_64__

            case OP_CALL2_1:
                loadstatic(w, OJITshim2);
                loadlit(w2, 1);
                loadfromsymbol(w1, w2, Ofunction2);
                JITcall(w, A_reg,
                       w1, w2, B_reg, A_reg);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_CALL2_1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL2_1:
                unfinished("Unsupported architecture");

#endif

// end of call2_1.cpp
