// op_flagp.cpp

#if defined BYTECODE
            case OP_FLAGP:                                  // A = flagp(B, A)
#ifdef COMMON
                A_reg = get(B_reg, A_reg, unset_var);
                if (A_reg == unset_var) A_reg = nil;
                else A_reg = lisp_true;
                errexit();
                continue;
#else
                A_reg = Lflagp(nil, B_reg, A_reg);
                errexit();
                continue;
#endif

#elif defined __x86_64__

            case OP_FLAGP:                                  // A = flagp(B, A)
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_FLAGP:                                  // A = flagp(B, A)
                myabort("This case not yet implemented for ARM");

#else
            case OP_FLAGP:                                  // A = flagp(B, A)
                myabort("Unsupported architecture");

#endif
