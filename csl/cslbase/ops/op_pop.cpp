// $Id$

#if defined BYTECODE
            case OP_POP:
                B_reg = A_reg;
                A_reg = *stack--;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_POP:
                mov(B_reg, A_reg);
                loadreg_post(A_reg, spreg, -8);
                break;

#else
            case OP_POP:
                unfinished("Unsupported architecture");

#endif

// end of op_pop.cpp
