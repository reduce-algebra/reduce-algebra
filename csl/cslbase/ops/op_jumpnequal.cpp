// jumpnequal.cpp

#if defined BYTECODE
            case OP_JUMPNEQUAL:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump(ppc, xppc, codevec);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_JUMPNEQUAL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNEQUAL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNEQUAL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpnequal.cpp
