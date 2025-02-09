// op_storefree3.cpp

#if defined BYTECODE
            case OP_STOREFREE3:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   print_traceset(3, A_reg, litvec);
                    errexit();
                }
                qvalue(basic_elt(litvec, 3)) = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STOREFREE3:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_STOREFREE3:
                myabort("This case not yet implemented for ARM");

#else
            case OP_STOREFREE3:
                myabort("Unsupported architecture");

#endif
