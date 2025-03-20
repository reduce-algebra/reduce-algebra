// add1.cpp

#if defined BYTECODE
            case OP_ADD1:
                if (is_fixnum(A_reg) && A_reg != MOST_POSITIVE_FIXNUM)
                {   A_reg += 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Add1::A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(1));
#endif
                errexit();
                continue;

#elif defined __x86_64__

            case OP_ADD1:
                {   Label notFixnum = newLabel();
                    Label endAdd1 = newLabel();
                    mov(w, A_reg);
                    and_(w, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
                    mov(w, MOST_POSITIVE_FIXNUM);
                    cmp(A_reg, w);
                    jne(notFixnum);
                    add(A_reg, 0x10);
                    jmp(endAdd1);
                bind(notFixnum);
#ifdef ARITHLIB
                    mov(w, ptr(nilreg, JIToffset(OJITshim1)));
                    mov(w1, ptr(nilreg, JIToffset(OJITsub1));
                    JITcall(w, A_reg,
                           w1, A_reg);
#else // ARITHLIB
                    mov(w, ptr(nilreg, JIToffset(OJITshim2)));
                    mov(w1, ptr(nilreg, JIToffset(OJITplus2)));
                    mov(B_reg, fixnum_of_int(1));
                    JITcall(w, A_reg,
                           w1, A_reg, B_reg);  
#endif // ARITHLIB
                    cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                    jne(callFailed);
                bind(endAdd1);
                }
                break;


#elif defined __aarch64__

//            case OP_ADD1:
//                if (is_fixnum(A_reg) && A_reg != MOST_POSITIVE_FIXNUM) {
//                    A_reg += 0x10;  // adding 1 directly
//                } else {
//                    // in more complicated cases, using plus2 ???
//                    A_reg = plus2(A_reg, fixnum_of_int(1));
//                    errexit();
//                }
//                break; // use breaks for all endings for now 

#else
            case OP_ADD1:
                unfinished("Unsupported architecture");

#endif

// end of add1.cpp


