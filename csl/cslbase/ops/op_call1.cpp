// op_call1.cpp

#if defined BYTECODE
            case OP_CALL1:
                fname = next_byte;
            call1:  r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f1 = qfn1(r1);
// CALL1:   A=fn(A);
                {   RECORD_CALL(list2(r1, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                    else A_reg = f1(r1, A_reg);
                }
                errexit();
                continue;

#elif defined __x86_64__

            case OP_CALL1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CALL1:
                myabort("Unsupported architecture");

#endif
