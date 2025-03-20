// jumpb1t.cpp

#if defined BYTECODE
            case OP_JUMPB1T:
                f1 = one_arg_functions[next_byte];
                A_reg = f1(nil, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPB1T:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPB1T:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPB1T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpb1t.cpp
