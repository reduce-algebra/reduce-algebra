// $Id$

#if defined BYTECODE
            case OP_LOADLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC8:
                mov(B_reg, A_reg);
                loadloc(A_reg, 8);
                break;

#else
            case OP_LOADLOC8:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc8.cpp
