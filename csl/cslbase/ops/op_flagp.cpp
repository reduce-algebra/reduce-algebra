// flagp.cpp $Id$

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

#elif defined __x86_64__ || defined __aarch64__

            case OP_FLAGP:
                loadstatic(w, OJITshim2L);
                loadstatic(w1, OJITLflagp);
                JITcall(w, A_reg,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_FLAGP:                                  // A = flagp(B, A)
                unfinished("Unsupported architecture");

#endif

// end of op_flagp.cpp
