// $Id$

#if defined BYTECODE
            case OP_LOADLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC0:
                mov(B_reg, A_reg);
                loadloc(A_reg, 0);
                break;

#else
            case OP_LOADLOC0:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc0.cpp
