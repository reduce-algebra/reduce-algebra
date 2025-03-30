// call2_1.cpp

#if defined BYTECODE
            case OP_CALL2_1:
                fname = 1;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_1:
                loadstatic(w, OJITshim2L);
                loadlit(w2, 1);
                loadfromsymbol(w1, w2, Ofunction2);
                JITcall(w, A_reg,
                        w1, w2, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL2_1:
                unfinished("Unsupported architecture");

#endif

// end of call2_1.cpp
