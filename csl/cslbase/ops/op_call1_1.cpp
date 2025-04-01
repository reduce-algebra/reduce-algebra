// call1_1.cpp $Id$

#if defined BYTECODE
            case OP_CALL1_1:
                fname = 1;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_1:
                loadstatic(w, OJITshim1L);
                loadlit(w2, 1);
                loadfromsymbol(w1, w2, Ofunction1);
                JITcall(w, A_reg,
                        w1, w2, A_reg);
                JITerrorcheck();
                break; 

#else
            case OP_CALL1_1:
                unfinished("Unsupported architecture");

#endif

// end of call1_1.cpp
