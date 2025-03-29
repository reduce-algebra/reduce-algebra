// loc1loc2.cpp

#if defined BYTECODE
            case OP_LOC1LOC2:
                B_reg = stack[-1];
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC1LOC2:
                loadloc(B_reg, 1);
                loadloc(A_reg, 2);
                break;

#else
            case OP_LOC1LOC2:
                unfinished("Unsupported architecture");

#endif

// end of loc1loc2.cpp
