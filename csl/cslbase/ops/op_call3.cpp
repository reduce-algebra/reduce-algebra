// op_call3.cpp

#if defined BYTECODE
            case OP_CALL3:
                fname = next_byte;
            call3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
// CALL3:   A=fn(pop(),B,A);
                r2 = *stack--;
                {   RECORD_CALL(list4(r1, r2, A_reg, B_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
                errexit();
                continue;

#elif defined __x86_64__

            case OP_CALL3:
                next = bytes[ppc++];
                cc.mov(w, ptr(nilreg, JIToffset(OJITshim4)));
                cc.mov(w1, ptr(litvec, 8*next+CELL-TAG_VECTOR));
// w1 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 3 args.
                cc.mov(w1,
                       ptr(w1, offsetof(Symbol_Head, function3)-TAG_SYMBOL));
                cc.mov(w2, ptr(spreg));
                cc.add(spreg, -8);
                invoke(cc, nilreg, spreg, w, A_reg,
                       w1, w2, B_reg, A_reg);
                cc.cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                cc.jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_CALL3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL3:
                unfinished("Unsupported architecture");

#endif
