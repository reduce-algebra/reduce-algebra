// op_list3.cpp

#if defined BYTECODE
            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                // = pop() . (B . (A . nil))
                r1 = *stack--;
                A_reg = list3(r1, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif
