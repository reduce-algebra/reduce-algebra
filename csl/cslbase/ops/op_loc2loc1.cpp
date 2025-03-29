// loc2loc1.cpp

#if defined BYTECODE
            case OP_LOC2LOC1:
                B_reg = stack[-2];
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC2LOC1:
                loadloc(B_reg, 2);
                loadloc(A_reg, 1);
                break;

#else
            case OP_LOC2LOC1:
                unfinished("Unsupported architecture");

#endif

// end of loc2loc1.cpp
