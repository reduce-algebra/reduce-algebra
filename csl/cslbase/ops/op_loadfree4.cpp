// loadfree4.cpp

#if defined BYTECODE
            case OP_LOADFREE4:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 4));
                continue;

#elif defined __x86_64__

            case OP_LOADFREE4:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(litvec, 32+CELL-TAG_VECTOR));
                mov(A_reg, ptr(A_reg,
                   offsetof(Symbol_Head, value)-TAG_SYMBOL));
                break;

#elif defined __aarch64__

            case OP_LOADFREE4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADFREE4:
                unfinished("Unsupported architecture");

#endif

// end of op_loadfree4.cpp
