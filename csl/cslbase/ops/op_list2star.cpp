// op_list2star.cpp

#if defined BYTECODE
            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                // = pop() . (B . A)
                r1 = *stack--;
                A_reg = list2star(r1, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif
