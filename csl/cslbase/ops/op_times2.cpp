// op_times2.cpp

#if defined BYTECODE
            case OP_TIMES2:
// I do not in-line even the integer case here, since overflow checking
// is a slight mess.
#ifdef ARITHLIB
                A_reg = Times::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = times2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_TIMES2:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_TIMES2:
                myabort("This case not yet implemented for ARM");

#else
            case OP_TIMES2:
                myabort("Unsupported architecture");

#endif
