// call1.cpp

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
                next = bytes[ppc++];
                mov(w, ptr(nilreg, JIToffset(OJITshim2)));
                mov(w2, ptr(litvec, 8*next+CELL-TAG_VECTOR));
                mov(w1,
                       ptr(w2, offsetof(Symbol_Head, function1)-TAG_SYMBOL));
                JITcall(w, A_reg,
                       w, w1, w2, A_reg);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_CALL1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL1:
                unfinished("Unsupported architecture");

#endif

// end of call1.cpp
