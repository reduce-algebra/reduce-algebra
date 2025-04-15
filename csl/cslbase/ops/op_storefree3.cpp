// $Id$

#if defined BYTECODE
            case OP_STOREFREE3:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   print_traceset(3, A_reg, litvec);
                    errexit();
                }
                qvalue(basic_elt(litvec, 3)) = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STOREFREE3:
                loadlit(w, 3);
                storetosymbol(A_reg, w, Ovalue);
                break;

#else
            case OP_STOREFREE3:
                unfinished("Unsupported architecture");

#endif// end of storefree3.cpp
