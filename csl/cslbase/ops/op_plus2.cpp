// $Id$

#if defined BYTECODE
            case OP_PLUS2:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(A_reg) + int_of_fixnum(B_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Plus::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = plus2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PLUS2:
                {   Label notFixnum = newLabel();
                    Label endPlus2 = newLabel();
// First test if both args are fixnums.
                    and3(w, A_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
                    and3(w, B_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
// The actual integer values are got by shifting (arithmetically) right
// by 4 bits to discard the tagging information that told me that I had
// a pair of fixnums.
                    sar(A_reg, 4);
                    sar(B_reg, 4);
                    add2(A_reg, B_reg);
// After adding the result could be too large for a fixnum. Call code that
// handles all that mess. In easy cases it will just shift left by 4 bits
// and add TAG_FIXNUM. In hard cases it needs to create a bignum.
                    mov(w1, JITint_from_ptrVal);
                    JITcall(JITshim1, A_reg,
                            w1, A_reg);
// Remember to check for failure!
                    JITerrorcheck();
                    jmp(endPlus2);

                bind(notFixnum);
                    mov(w1, plus2);
                    JITcall(JITshim2, A_reg,
                            w1, A_reg, B_reg);  
                    JITerrorcheck();
                bind(endPlus2);
                }
                break;

#else
            case OP_PLUS2:
                unfinished("Unsupported architecture");

#endif

// end of plus2.cpp


