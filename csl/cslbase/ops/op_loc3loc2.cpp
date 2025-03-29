// loc3loc2.cpp

#if defined BYTECODE
            case OP_LOC3LOC2:
                B_reg = stack[-3];
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC3LOC2:
                loadloc(B_reg, 3);
                loadloc(A_reg, 2);
                break;

#else
            case OP_LOC3LOC2:
                unfinished("Unsupported architecture");

#endif

// end of loc3loc2.cpp
