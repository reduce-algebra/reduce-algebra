// $Id$

#if defined BYTECODE
            case OP_LOADLIT:
//
// Associated with each body of byte-codes there is a literal vector,
// and this ode loads values from same.  The literal vector has a
// header word and is tagged as a Lisp vector.
//
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT:
                next = bytes[ppc++];
                mov(B_reg, A_reg);
                loadlit(A_reg, next);
                break;

#else
            case OP_LOADLIT:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit.cpp
