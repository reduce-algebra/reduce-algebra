// call2_4.cpp

#if defined BYTECODE
            case OP_CALL2_4:
                fname = 4;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_4:
                loadstatic(w, OJITshim2);
                loadlit(w2, 4);
                loadfromsymbol(w1, w2, Ofunction2);
                JITcall(w, A_reg,
                        w1, w2, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL2_4:
                unfinished("Unsupported architecture");

#endif

// end of call2_4.cpp
