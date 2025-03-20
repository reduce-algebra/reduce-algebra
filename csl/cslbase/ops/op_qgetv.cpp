// qgetv.cpp

#if defined BYTECODE
            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
//
// Note - this is an UNCHECKED vector access, used when carcheck(nil) has
// been selected because the user prefers speed to security.  This is in
// here because the Reduce factoriser test uses getv VERY heavily indeed
// and both use of a special ode here and removal of the checking make
// noticable differences to performance.
//
                A_reg = *reinterpret_cast<LispObject *>(
                            reinterpret_cast<char *>(B_reg) +
                            (CELL - TAG_VECTOR) +
                            (CELL*int_of_fixnum(A_reg)));
                continue;

#elif defined __x86_64__

            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
                unfinished("Unsupported architecture");

#endif

// end of op_qgetv.cpp
