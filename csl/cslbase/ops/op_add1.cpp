// add1.cpp

#if defined BYTECODE
            case OP_ADD1:
                if (is_fixnum(A_reg) && A_reg != MOST_POSITIVE_FIXNUM)
                {   A_reg += 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Add1::op(A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(1));
#endif
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_ADD1:
                {   Label notFixnum = newLabel();
                    Label endAdd1 = newLabel();
                    and3(w, A_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
                    mov(w, MOST_POSITIVE_FIXNUM);
                    cmp(A_reg, w);
                    jne(notFixnum);
                    add2(A_reg, 0x10);
                    jmp(endAdd1);
                bind(notFixnum);
                    loadstatic(w, OJITshim1);
                    loadstatic(w1, OJITplus2);
                    mov(B_reg, fixnum_of_int(1));
                    JITcall(w, A_reg,
                            w1, A_reg, B_reg);  
                    JITerrorcheck();
                bind(endAdd1);
                }
                break;

#else
            case OP_ADD1:
                unfinished("Unsupported architecture");

#endif

// end of add1.cpp


