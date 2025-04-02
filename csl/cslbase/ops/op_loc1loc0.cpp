// loc1loc0.cpp $Id$

#if defined BYTECODE
            case OP_LOC1LOC0:
                B_reg = stack[-1];
                A_reg = stack[-0];
                continue;

#elif defined __x86_64__ || defined __aarch64__
            case OP_LOC1LOC0:
                loadloc(B_reg, 1);
                loadloc(A_reg, 0);
                break;

#else
            case OP_LOC1LOC0:
                unfinished("Unsupported architecture");

#endif

// end of loc1log0.cpp