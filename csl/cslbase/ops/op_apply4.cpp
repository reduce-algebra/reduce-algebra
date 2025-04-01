// apply4.cpp

#if defined BYTECODE
            case OP_APPLY4:
                r1 = *stack--;
                r3 = *stack--;
// The 4 arguments are now r3, r1, B_reg, A_reg in that order, and as with
// APPLY3 I do not wrap the final two arguments up in a list but instead pass
// them individually.
                r2 = *stack;
                if (is_symbol(r2))   // can imise this case, I guess
                {   A_reg = ncons(A_reg);    // Make 4th arg a list!
                    RECORD_CALL(list4star(r2, r3, r1, B_reg, A_reg));
                    errexit();
                    f4up = qfn4up(r2);
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call4up(basic_elt(litvec, 0), f4up, r2, r3, r1, B_reg,
                                               A_reg);
                    else A_reg = f4up(r2, r3, r1, B_reg, A_reg);
                    stack--;
                    errexit();
                    continue;
                }
                A_reg = list4(r3, r1, B_reg, A_reg);
                r2 = *stack--;
                errexit();
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

#ifdef COMMON
#define SL_OR_CL_EQUAL cl_equal
#else
#define SL_OR_CL_EQUAL equal
#endif

#elif defined __x86_64__ || defined __aarch64__

            case OP_APPLY4:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_APPLY4:
                unfinished("Unsupported architecture");

#endif

// end of op_apply4.cpp
