// storefree1.cpp

#if defined BYTECODE
            case OP_STOREFREE1:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   print_traceset(1, A_reg, litvec);
                    errexit();
                }
                qvalue(basic_elt(litvec, 1)) = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STOREFREE1:
                mov(w, ptr(litvec, 8+CELL-TAG_VECTOR));
                mov(ptr(A_reg, offsetof(Symbol_Head, value)-TAG_SYMBOL),
                       A_reg);
                break;

#elif defined __aarch64__

            case OP_STOREFREE1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STOREFREE1:
                unfinished("Unsupported architecture");

#endif

// end of storefree1.cpp
