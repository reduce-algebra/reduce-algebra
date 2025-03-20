// loadloc.cpp

#if defined BYTECODE
            case OP_LOADLOC:
                B_reg = A_reg;
                A_reg = stack[-static_cast<int>(next_byte)];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC:
                next = bytes[ppc++];
                mov(B_reg, A_reg);
                loadloc(A_reg, next);
                break;

#else
            case OP_LOADLOC:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc.cpp
