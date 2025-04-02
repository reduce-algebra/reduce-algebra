// lessp.cpp $Id$

#if defined BYTECODE
            case OP_LESSP:
#ifdef ARITHLIB
                w = Lessp::op(B_reg, A_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg < A_reg;
                else
                {   w = lessp2(B_reg, A_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

#elif defined __x86_64__ || defined __aarch64__

// This case is a LOT more stressful than the codes that merely
// shuffle stuff around on the stack! It is the first case I am
// implementing that can do a genuine function call. So we have four
// things of note here:
// (1) There is special case code that tests tag-bits and spots if the
//     two values being compared are both "fixnums", in which case the
//     comparison can be done directly - but the result must be returned
//     as either T or NIL. The variable lisp_true holds a reference to the
//     symbol T.
// (2) I have to wrirte and_ not and because and is a sort of reserved
//     word here so the asmjit standard name has to be mildly odd! The same
//     will apply to or/or_ and xor/xor_. Also int/int_  Beware! This is
//     because in C++ "and" can be used as an alternative to "&&" (and
//     "bitand" for "&") with "or" and "bitor" for "||" and "|" and xor
//     for "^". These exist to make it easier to write C++ on platforms
//     with less than complete character sets. But the names involved
//     match those of commonly-used odes. Ha ha.
// (3) The sub-function lessp2 has to be called via JITshim because
//     it might raise an exception - for instance if one or both of the
//     rands are not numeric. The value it returns is a "bool" not
//     a LispObject and JITshim will return a 64-bit result because I
//     and not terribly careful about types! So I mask out all but the
//     bottom byte to mend that. I should probably change things to be
//     more careful about my return types.
// (4) After calling JITshim I must test JITerrflag and go and do something
//     special in the failure case.
            case OP_LESSP:
                {   Label notFixnums = newLabel();
                    Label yes = newLabel();
                    Label no = newLabel();
                    Label endLessp = newLabel();
// Test if the low 4 bits of A_reg are 0x7 - ie if the value represents
// a Fixnum.
                    mov(w, A_reg);
                    and3(w, A_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnums);
// Similarly for B_reg.
                    and3(w, B_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnums);
// If both are fixnums I can compare easily.
                    cmp(B_reg, A_reg);
                    jnl(no);
// [I offset label-setting by 4 spaces to highlight it]
                bind(yes);
// Deliver T (lisp_true) here.
                    loadstatic(A_reg, Olisp_true);
                    jmp(endLessp);
                bind(notFixnums);
// Here one or other is not a Fixnum - call external function "lessp".
                    loadstatic(w, OJITshim2B);
                    loadstatic(w1, OJITlessp2);
// Args to "JITcall" are:
//      target  Register that contains the entrypoint of the function to call
//      result  Register to receive result of the call
//      a1, a2... Registers holding arguments to pass.
// If the target is one of the "shim" functions that the arguments it needs
// will be
//      entry   Entrypoint of function to be called
//      a1, a2..  Arguments for that.
// so here w is JITshim2B and w is a function of 2 arguments that returns
// a boolean value.
                    JITcall(w, A_reg,
                            w1, B_reg, A_reg);
// See if that reported failure. Test the low bytes of JITerrflag.
                    JITerrorcheck();
// If lessp() succeeded turn result from a bool to either T or NIL.
                    test(A_reg, 0xff);
                    jne(yes);
                bind(no);
                    mov(A_reg, nilreg);
// End of expansion of this ode!                  
                bind(endLessp);
                }
                break;

#else
            case OP_LESSP:
                unfinished("Unsupported architecture");

#endif

// end of lessp.cpp
