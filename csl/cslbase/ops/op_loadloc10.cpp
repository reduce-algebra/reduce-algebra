// $Id$

#if defined BYTECODE
            case OP_LOADLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC10:
                mov(B_reg, A_reg);
                loadloc(A_reg, 10);
                break;

#else
            case OP_LOADLOC10:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc10.cpp
