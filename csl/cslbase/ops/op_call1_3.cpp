// call1_3.cpp

#if defined BYTECODE
            case OP_CALL1_3:
                fname = 3;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_3:
                loadstatic(w, OJITshim1L);
                loadlit(w2, 3);
                loadfromsymbol(w1, w2, Ofunction1);
                JITcall(w, A_reg,
                        w1, w2, A_reg);
                JITerrorcheck();
                break;

#elif defined __aarch64__

            case OP_CALL1_3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL1_3:
                unfinished("Unsupported architecture");

#endif

// end of call1_3.cpp
