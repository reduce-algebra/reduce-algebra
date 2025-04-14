// $Id$

#if defined BYTECODE
            case OP_LOADLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC4:
                mov(B_reg, A_reg);
                loadloc(A_reg, 4);
                break;

#else
            case OP_LOADLOC4:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc4.cpp