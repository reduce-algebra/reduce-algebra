// call4.cpp $Id$

#if defined BYTECODE

// This case is used whenever I am calling a function with 4 or more
// arguments. In the bytecode scheme a call that started off as
//      (fff a1 a2 a3 a4 a5 a6)
// has been converted so that it is as if it had been
//      (fff a1 a2 a3 (list a4 a5 a6))
// so here a1 and a2 will be on the stack, a3 will be in B_reg and
// the list of arguments a4, a5 and a6 will be in A_reg.
//
// Looking back on this I do not understand why I go via apply() rather than
// just calling the thing in the function4up cell of the function!
            case OP_CALL4:
                r2 = *stack--; r1 = *stack--;
                B_reg = list3star(r1, r2, B_reg, A_reg);
                errexit();
// Here the post-byte indicates the function to be called.
                A_reg = basic_elt(litvec,
                                  (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                ppc++;
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL4:
                next = bytes[ppc++];
                loadstatic(w, OJITshim4L);
                loadlit(w2, next);
// w2 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 4+ args.
                loadfromsymbol(w1, w2, Ofunction4up);
                loadreg_post(w3, spreg, -8);
                loadreg_post(w4, spreg, -8);
// Here I call JITshim with arguments
//           entrypoint of Lisp function to be called (in w1)
//           name of function being called (as "env" parameter for it) in w2
//           the four honest arguments it needs (w4, w3, B_reg and A_reg).
                JITcall(w, A_reg,
                        w1, w2, w4, w3, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL4:
                unfinished("Unsupported architecture");

#endif

// end of op_call4.cpp

