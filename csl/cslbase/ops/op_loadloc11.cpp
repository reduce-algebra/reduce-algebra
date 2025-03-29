// loadloc11.cpp

#if defined BYTECODE
            case OP_LOADLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC11:
                mov(B_reg, A_reg);
                loadloc(A_reg, 11);
                break;

#else
            case OP_LOADLOC11:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc11.cpp
