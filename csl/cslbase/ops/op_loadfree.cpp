// op_loadfree.cpp

#if defined BYTECODE
            case OP_LOADFREE:
//
// Load the value of a free (GLOBAL, SPECIAL, FLUID) variable
//
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, next_byte));
                continue;

#elif defined __x86_64__

            case OP_LOADFREE:
                next = bytes[ppc++];
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(litvec, 8*next+CELL-TAG_VECTOR));
                cc.mov(A_reg, ptr(A_reg,
                   offsetof(Symbol_Head, value)-TAG_SYMBOL));
                break;

#elif defined __aarch64__

            case OP_LOADFREE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADFREE:
                unfinished("Unsupported architecture");

#endif
