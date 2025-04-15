// $Id$

#if defined BYTECODE
            case OP_LOC0LOC1:
                B_reg = stack[-0];
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC0LOC1:
                loadloc(B_reg, 0);
                loadloc(A_reg, 1);
                break;

#else
            case OP_LOC0LOC1:
                unfinished("Unsupported architecture");

#endif

// end of loc0loc1.cpp