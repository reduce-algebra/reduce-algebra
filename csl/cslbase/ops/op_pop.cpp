// op_pop.cpp

#if defined BYTECODE
            case OP_POP:
                B_reg = A_reg;
                A_reg = *stack--;
                continue;

#elif defined __x86_64__

            case OP_POP:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_POP:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_POP:
                unfinished("Unsupported architecture");

#endif
