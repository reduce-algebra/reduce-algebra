// call1_4.cpp $Id$

#if defined BYTECODE
            case OP_CALL1_4:
                fname = 4;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_4:
                loadstatic(w, OJITshim1L);
                loadlit(w2, 4);
                loadfromsymbol(w1, w2, Ofunction1);
                JITcall(w, A_reg,
                        w1, w2, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL1_4:
                unfinished("Unsupported architecture");

#endif

// end of call1_4.cpp
