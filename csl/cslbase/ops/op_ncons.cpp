// op_ncons.cpp

#if defined BYTECODE
            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
                {   A_reg = ncons(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
                unfinished("Unsupported architecture");

#endif
