// op_sub1.cpp

#if defined BYTECODE
            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != MOST_NEGATIVE_FIXNUM)
                {   A_reg -= 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Sub1::op(A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(-1));
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_SUB1:
                {   Label notFixnum = cc.newLabel();
                    Label endSub1 = cc.newLabel();
                    cc.mov(w, A_reg);
                    cc.and_(w, XTAG_BITS);
                    cc.cmp(w, TAG_FIXNUM);
                    cc.jne(notFixnum);
                    cc.cmp(A_reg, MOST_NEGATIVE_FIXNUM);
                    cc.jne(notFixnum);
                    cc.add(A_reg, -0x10);
                    cc.jmp(endSub1);
                cc.bind(notFixnum);
#ifdef ARITHLIB
                    cc.mov(w, ptr(nilreg, JIToffset(OJITshim1)));
                    cc.mov(w1, ptr(nilreg, JIToffset(OJITsub1op)));
                    invoke(cc, nilreg, spreg, w, A_reg,
                           w1, A_reg);
#else // ARITHLIB
                    cc.mov(w, ptr(nilreg, JIToffset(OJITshim2)));
                    cc.mov(w1, ptr(nilreg, JIToffset(OJITplus2)));
                    cc.mov(B_reg, fixnum_of_int(-1));
                    invoke(cc, nilreg, spreg, w, A_reg,
                           w1, A_reg, B_reg);  
#endif // ARITHLIB
                    cc.cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                    cc.jne(callFailed);
                cc.bind(endSub1);
                }
                break;

#elif defined __aarch64__

            case OP_SUB1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SUB1:
                unfinished("Unsupported architecture");

#endif
