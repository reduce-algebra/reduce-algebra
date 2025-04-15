// $Id$

#if defined BYTECODE
            case OP_LOC2LOC3:
                B_reg = stack[-2];
                A_reg = stack[-3];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC2LOC3:
                loadloc(B_reg, 2);
                loadloc(A_reg, 3);
                break;

#else
            case OP_LOC2LOC3:
                unfinished("Unsupported architecture");

#endif

// end of loc2loc3.cpp
