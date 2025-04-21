// $Id$

#if defined BYTECODE
            case OP_BIGCALL:
//
// This provides for calls (and a few other rations!) where the literal
// to be referenced is beyond position 256 in the literal vector. The
// encoding is that BIGCALL is followed by two bytes. The half of the
// first of these is a sub code, while the remaining 12 bits provide
// support for literal vectors with up to 4096 elements. At present I
// will just not support code bigger than that. Note that if I were feeling
// keen here I could easily arrange that the 12-bit offset here started at
// 256 and went on upwards. But for simplicity in a first version I will
// leave a bit of redundancy.
//
                w = next_byte;
                fname = next_byte + ((w & 0xf) << 8);
                switch (w >> 4)
                {   case 0: goto call0;
                    case 1: goto call1;
                    case 2: goto call2;
                    case 3: goto call3;
                    case 4:
// Here I write out a variant on the CALL4 code.
                        {   LispObject a3 = *stack--;
                            LispObject a4 = *stack--;
                            B_reg = list3star(a4, a3, B_reg, A_reg);
                        }
                        errexit();
                        A_reg = basic_elt(litvec, fname);
                        A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                        errexit();
                        ppc++;
                        continue;

                    case 5: goto call2r;
// sub-odes 6 and 7 are use for LOADFREE and STOREFREE - this is a bit
// odd but fits the required that operations fit tightly into the code map.
                    case 6:
                        B_reg = A_reg;
                        A_reg = qvalue(basic_elt(litvec, fname));
                        continue;
                    case 7:
                        if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                        {   print_traceset(fname, A_reg, litvec);
                            errexit();
                        }
                        qvalue(basic_elt(litvec, fname)) = A_reg;  // store into special var
                        continue;
// Now tailcalls.
                    case 8: goto jcall0;
                    case 9: goto jcall1;
                    case 10:goto jcall2;
                    case 11:goto jcall3;
                    case 12:goto jcall4;
// Codes 13 and 14 do FREEBIND and LITGET, which completes the list of
// byte operations that access big literals.
                    case 13:do_freebind(basic_elt(litvec, fname));
                        continue;
                    case 14:B_reg = A_reg;
                        A_reg = basic_elt(litvec, fname);
                        A_reg = get(B_reg, A_reg, nil);
                        continue;
// Code 15 is LOADLIT with a long offset, which may be used as an alternative
// to the LOADLIT/QGETVN mechanism that I otherwise support.
                    case 15:B_reg = A_reg;
                        A_reg = basic_elt(litvec, fname);
                        continue;
                }

#elif defined __x86_64__ || defined __aarch64__

            case OP_BIGCALL:
                {   next = bytes[ppc++];
                    int fname = bytes[ppc++] + ((next & 0xf) << 8);
                    switch (next >> 4)
                    {
                default:
                case 0: // call 0 args
                    unfinished(__FILE__ " not yet implemented bigcall call0");
                    break;
                case 1: // call 1 arg
                    unfinished(__FILE__ " not yet implemented bigcall call1");
                    break;
                case 2: // call 2 args
                    unfinished(__FILE__ " not yet implemented bigcall call2");
                    break;
                case 3: // call 3 args
                    unfinished(__FILE__ " not yet implemented bigcall call3");
                    break;
                case 4: // call 4 args
                    unfinished(__FILE__ " not yet implemented bigcall call4");
                    break;
                case 5: // call 2 args, arg order reversed
                    unfinished(__FILE__ " not yet implemented bigcall call2r");
                    break;
                case 6: // loadfree
                    unfinished(__FILE__ " not yet implemented bigcall loadfree");
                    break;
                case 7: // storefree
                    unfinished(__FILE__ " not yet implemented bigcall storefree");
                    break;
                case 8: // tail call 0 args
                    unfinished(__FILE__ " not yet implemented bigcall jcall0");
                    break;
                case 9: // tail call 1 arg
                    unfinished(__FILE__ " not yet implemented bigcall jcall1");
                    break;
                case 10:// tail call 2 args
                    unfinished(__FILE__ " not yet implemented bigcall jcall2");
                    break;
                case 11:// tail call 3 args
                    unfinished(__FILE__ " not yet implemented bigcall jcall3");
                    break;
                case 12:// tail call 4 args
                    unfinished(__FILE__ " not yet implemented bigcall jcall4");
                    break;
                case 13:// freebind
                    unfinished(__FILE__ " not yet implemented bigcall freebind");
                    break;
                case 14:// litget
                    unfinished(__FILE__ " not yet implemented bigcall litget");
                    break;
                case 15:// loadlit
                    unfinished(__FILE__ " not yet implemented bigcall loadlit");
                    break;
                    }
                }
                break;
#else
            case OP_BIGCALL:
                unfinished("Unsupported architecture");

#endif

// end of op_bigcall.cpp
