// $Id$

#if defined BYTECODE
            case OP_CALL2_3:
                fname = 3;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_3:
                loadlit(w2, 3);
                loadfromsymbol(w1, w2, Ofunction2);
                JITcall(JITshim2L, A_reg,
                        w1, w2, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL2_3:
                unfinished("Unsupported architecture");

#endif

// end of call2_3.cpp
