// op_list2.cpp

#if defined BYTECODE
            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                A_reg = list2(B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                unfinished("Unsupported architecture");

#endif
