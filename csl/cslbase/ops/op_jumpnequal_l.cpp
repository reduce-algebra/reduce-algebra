// jumpnequal_l.cpp

#if defined BYTECODE
            case OP_JUMPNEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNEQUAL_L:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNEQUAL_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNEQUAL_L:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpnequal_l.cpp
