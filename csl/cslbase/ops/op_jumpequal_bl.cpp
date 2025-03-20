// jumpequal_bl.cpp

#if defined BYTECODE
            case OP_JUMPEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPEQUAL_BL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPEQUAL_BL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPEQUAL_BL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpequal_bl.cpp
