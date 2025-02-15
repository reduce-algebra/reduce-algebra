// op_getv.cpp

#if defined BYTECODE
            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                A_reg = Lgetv(nil, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                unfinished("Unsupported architecture");

#endif
