// op_sub1.cpp

#if defined BYTECODE
            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != MOST_NEGATIVE_FIXNUM)
                {   A_reg -= 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Sub1::op(A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(-1));
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_SUB1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_SUB1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SUB1:
                unfinished("Unsupported architecture");

#endif
