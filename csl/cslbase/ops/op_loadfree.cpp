// loadfree.cpp

#if defined BYTECODE
            case OP_LOADFREE:
//
// Load the value of a free (GLOBAL, SPECIAL, FLUID) variable
//
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, next_byte));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADFREE:
                next = bytes[ppc++];
                mov(B_reg, A_reg);
                loadlit(A_reg, next);
                loadfromsymbol(A_reg, A_reg, Ovalue);
                break;

#else
            case OP_LOADFREE:
                unfinished("Unsupported architecture");

#endif

// end of op_loadfree.cpp
