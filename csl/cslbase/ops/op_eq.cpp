// eq.cpp

#if defined BYTECODE
            case OP_EQ:                                     // A = eq(B, A)
                if (A_reg == B_reg) A_reg = lisp_true;
                else A_reg = nil;
                continue;

#elif defined __x86_64__

            case OP_EQ:                                     // A = eq(B, A)
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_EQ:                                     // A = eq(B, A)
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_EQ:                                     // A = eq(B, A)
                unfinished("Unsupported architecture");

#endif

// end of op_eq.cpp
