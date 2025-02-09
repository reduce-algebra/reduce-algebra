// op_add1.cpp

#if defined BYTECODE
            case OP_ADD1:
                if (is_fixnum(A_reg) && A_reg != MOST_POSITIVE_FIXNUM)
                {   A_reg += 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Add1::op(A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(1));
#endif
                errexit();
                continue;

#elif defined __x86_64__

            case OP_ADD1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_ADD1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_ADD1:
                myabort("Unsupported architecture");

#endif
