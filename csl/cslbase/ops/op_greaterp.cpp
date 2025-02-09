// op_greaterp.cpp

#if defined BYTECODE
            case OP_GREATERP:
#ifdef ARITHLIB
                w = Lessp::op(A_reg, B_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg > A_reg;
                else
                {   w = lessp2(A_reg, B_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

#elif defined __x86_64__

            case OP_GREATERP:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_GREATERP:
                myabort("This case not yet implemented for ARM");

#else
            case OP_GREATERP:
                myabort("Unsupported architecture");

#endif
