// call0_2.cpp

#if defined BYTECODE
            case OP_CALL0_2:
                fname = 2;
                goto call0;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL0_2:
                loadstatic(w, OJITshim1L);
                loadlit(w2, 2);
// w2 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 0 args.
                loadfromsymbol(w1, w2, Ofunction0);
                JITcall(w, A_reg,
                        w1, w2);
                JITerrorcheck();
                break;

#else
            case OP_CALL0_2:
                unfinished("Unsupported architecture");

#endif

// call0_2.cpp

// end of op_call0_2.cpp
