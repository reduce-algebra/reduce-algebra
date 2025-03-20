// plus2.cpp

#if defined BYTECODE
            case OP_PLUS2:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(A_reg) + int_of_fixnum(B_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Plus::B_reg, A_reg);
#else // ARITHLIB
                A_reg = plus2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_PLUS2:
                {   Label notFixnum = newLabel();
                    Label endPlus2 = newLabel();
// First test if both args are fixnums.
                    mov(w, A_reg);
                    and_(w, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
                    mov(w, B_reg);
                    and_(w, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
// The actual integer values are got by shifting (arithmetically) right
// by 4 bits to discard the tagging information that told me that I had
// a pair of fixnums.
                    sar(A_reg, 4);
                    sar(B_reg, 4);
                    add(A_reg, B_reg);
// After adding the result could be too large for a fixnum. Call code that
// handles all that mess. In easy cases it will just shift left by 4 bits
// and add TAG_FIXNUM. In hard cases it needs to create a bignum.
                    mov(w, ptr(nilreg, JIToffset(OJITshim1)));
                    mov(w1, ptr(nilreg, JIToffset(OJITmake_int_from_ptr)));
                    JITcall(w, A_reg,
                            w1, A_reg);
// Remember to check for failure!
                    cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                    jne(callFailed);
                    jmp(endPlus2);
                bind(notFixnum);
#ifdef ARITHLIB
                    loadstatic(w, OJITshim2));
                    loadlit(w1, OJITplus2);
                    JITcall(w, A_reg,
                            w1, A_reg, B_reg);
#else // ARITHLIB
                    loadstatic(w, OJITshim2);
                    loadstatic(w1, OJITplus2);
                    JITcall(w, A_reg,
                            w1, A_reg, B_reg);  
#endif // ARITHLIB
                    cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                    jne(callFailed);
                bind(endPlus2);
                }
                break;


#elif defined __aarch64__

            case OP_PLUS2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PLUS2:
                unfinished("Unsupported architecture");

#endif

// end of plus2.cpp


