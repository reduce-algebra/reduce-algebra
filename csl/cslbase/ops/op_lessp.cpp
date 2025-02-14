// op_lessp.cpp

#if defined BYTECODE
            case OP_LESSP:
#ifdef ARITHLIB
                w = Lessp::op(B_reg, A_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg < A_reg;
                else
                {   w = lessp2(B_reg, A_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

#elif defined __x86_64__

            case OP_LESSP:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LESSP:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LESSP:
                unfinished("Unsupported architecture");

#endif
