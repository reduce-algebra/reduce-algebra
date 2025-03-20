// storefree.cpp

#if defined BYTECODE
            case OP_STOREFREE:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   print_traceset(current_byte, A_reg, litvec);
                    errexit();
                }
                qvalue(basic_elt(litvec, next_byte)) =
                         A_reg;  // store into special var
                continue;

#elif defined __x86_64__

            case OP_STOREFREE:
                next = bytes[ppc++];
                mov(w, ptr(litvec, 8*next+CELL-TAG_VECTOR));
                mov(ptr(A_reg, offsetof(Symbol_Head, value)-TAG_SYMBOL),
                       A_reg);
                break;

#elif defined __aarch64__

            case OP_STOREFREE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STOREFREE:
                unfinished("Unsupported architecture");

#endif

// end of storefree.cpp
