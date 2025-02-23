// op_loadlit.cpp

#if defined BYTECODE
            case OP_LOADLIT:
//
// Associated with each body of byte-codes there is a literal vector,
// and this opcode loads values from same.  The literal vector has a
// header word and is tagged as a Lisp vector.
//
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT:
                next = bytes[ppc++];
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(litvec, 8*next+8-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT:
                unfinished("Unsupported architecture");

#endif
