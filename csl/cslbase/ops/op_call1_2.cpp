// call1_2.cpp

#if defined BYTECODE
            case OP_CALL1_2:
                fname = 2;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_2:
                loadstatic(w, OJITshim1);
                loadlit(w2, 2);
                loadfromsymbol(w1, w2, Ofunction1);
                JITcall(w, A_reg,
                        w1, w2, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL1_2:
                unfinished("Unsupported architecture");

#endif

// end of call1_2.cpp
