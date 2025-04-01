// jumpnequal_b.cpp

#if defined BYTECODE
            case OP_JUMPNEQUAL_B:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNEQUAL_B:
                unfinished(__FILE__ " not yet implemented for x86_64");

#else
            case OP_JUMPNEQUAL_B:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpnequal_b.cpp
