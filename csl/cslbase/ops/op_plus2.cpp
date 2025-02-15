// op_plus2.cpp

#if defined BYTECODE
            case OP_PLUS2:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(A_reg) + int_of_fixnum(B_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Plus::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = plus2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_PLUS2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PLUS2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PLUS2:
                unfinished("Unsupported architecture");

#endif
