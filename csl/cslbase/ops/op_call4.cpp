// op_call4.cpp

#if defined BYTECODE
            case OP_CALL4:
// All but the last two args have been pushed onto the stack already.
// The last two are in A and B.
                r2 = *stack--; r1 = *stack--;
                B_reg = list3star(r1, r2, B_reg, A_reg);
                errexit();
// Here the post-byte indicates the function to be called.
                A_reg = basic_elt(litvec,
                                  (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                ppc++;
                errexit();
                continue;

#elif defined __x86_64__

            case OP_CALL4:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL4:
                unfinished("Unsupported architecture");

#endif
