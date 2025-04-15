// $Id$

#if defined BYTECODE
            case OP_LOADLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC2:
                mov(B_reg, A_reg);
                loadloc(A_reg, 2);
                break;

#else
            case OP_LOADLOC2:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc2.cpp
