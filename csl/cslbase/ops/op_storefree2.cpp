// storefree2.cpp

#if defined BYTECODE
            case OP_STOREFREE2:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   print_traceset(2, A_reg, litvec);
                    errexit();
                }
                qvalue(basic_elt(litvec, 2)) = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STOREFREE2:
                loadlit(w, 2);
                storetosymbol(A_reg, w, Ovalue);
                break;

#else
            case OP_STOREFREE2:
                unfinished("Unsupported architecture");

#endif

// end of storefree2.cpp
