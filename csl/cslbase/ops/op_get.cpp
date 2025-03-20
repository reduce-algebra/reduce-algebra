// get.cpp

#if defined BYTECODE
            case OP_GET:                                    // A = get(B, A)
                A_reg = get(B_reg, A_reg, nil);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_GET:                                    // A = get(B, A)
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_GET:                                    // A = get(B, A)
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_GET:                                    // A = get(B, A)
                unfinished("Unsupported architecture");

#endif

// end of op_get.cpp
