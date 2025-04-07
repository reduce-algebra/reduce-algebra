// call3.cpp $Id$

#if defined BYTECODE
            case OP_CALL3:
                fname = next_byte;
            call3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
// CALL3:   A=fn(p),B,A);
                r2 = *stack--;
                {   RECORD_CALL(list4(r1, r2, A_reg, B_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL3:
                next = bytes[ppc++];
                loadstatic(w, OJITshim3L);
                loadlit(w2, next);
// w2 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 3 args.
                loadfromsymbol(w1, w2, Ofunction3);
                loadreg_post(w3, spreg, -8);
// Here I call JITshim with arguments
//           entrypoint of Lisp function to be called (in w1)
//           name of function being called (as "env" parameter for it) in w2
//           the three honest arguments it needs (w3, B_reg and A_reg).
                JITcall(w, A_reg,
                        w1, w2, w3, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL3:
                unfinished("Unsupported architecture");

#endif

// end of op_call3.cpp
