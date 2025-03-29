// storefree1.cpp

#if defined BYTECODE
            case OP_STOREFREE1:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   print_traceset(1, A_reg, litvec);
                    errexit();
                }
                qvalue(basic_elt(litvec, 1)) = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STOREFREE1:
                loadlit(w, 1);
                storetosymbol(A_reg, w, Ovalue);
                break;

#else
            case OP_STOREFREE1:
                unfinished("Unsupported architecture");

#endif

// end of storefree1.cpp
