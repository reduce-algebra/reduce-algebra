// pvbind.cpp

#if defined BYTECODE
            case OP_PVBIND:
                do_pvbind(A_reg, B_reg);
                continue;

#elif defined __x86_64__

            case OP_PVBIND:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PVBIND:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PVBIND:
                unfinished("Unsupported architecture");

#endif

// end of op_pvbind.cpp
