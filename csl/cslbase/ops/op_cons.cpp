// cons.cpp

#if defined BYTECODE
            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
                A_reg = cons(B_reg, A_reg);
                errexit();
                continue;

//
// FASTGET n
//     0 <= n < 64       (GET A_reg prrty_n)
//    64 <= n < 128      (GET A_reg prrty_n B_reg)
//   128 <= n < 192      (FLAGP A_reg prrty_n)
//   192 <= n < 256      not used at present.
//
#elif defined __x86_64__

            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_cons.cpp
