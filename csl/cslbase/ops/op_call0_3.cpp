// call0_3.cpp $Id$

#if defined BYTECODE
            case OP_CALL0_3:
                fname = 3;
                goto call0;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL0_3:
                loadlit(w2, 3);
// w2 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 0 args.
                loadfromsymbol(w1, w2, Ofunction0);
                JITcall(JITshim1L, A_reg,
                        w1, w2);
                JITerrorcheck();
                break;

#else
            case OP_CALL0_3:
                unfinished("Unsupported architecture");

#endif

// end of call0_3.cpp
