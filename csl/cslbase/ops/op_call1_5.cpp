// call1_5.cpp $Id$

#if defined BYTECODE
            case OP_CALL1_5:
                fname = 5;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_5:
                loadlit(w2, 5);
                loadfromsymbol(w1, w2, Ofunction1);
                JITcall(JITshim1L, A_reg,
                        w1, w2, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL1_5:
                unfinished("Unsupported architecture");

#endif

// end of call1_5.cpp
