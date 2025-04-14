// $Id$

#if defined BYTECODE
            case OP_QGETVN:                         // A_reg = getv(A_reg, n)
//
// Note - this is an UNCHECKED vector access, and only applicable to simple
// vectors that hold general Lisp data.  The offset is passed in the
// byte stream.  It is expected that it will help with code that passes
// around vectors of guff and use (getv vvv 0) etc (aka svref) to
// grab stuff out.
//
                A_reg = *reinterpret_cast<LispObject *>(
                            reinterpret_cast<char *>(A_reg) + (CELL - TAG_VECTOR) + (CELL*
                                    (next_byte)));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_QGETVN:
                next = bytes[ppc++];
                mov(w1, Lgetv);
                mov(w2, fixnum_of_int(next));
                JITcall(JITshim2L, A_reg,
                        w1, nilreg, w2, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_QGETVN:                         // A_reg = getv(A_reg, n)
                unfinished("Unsupported architecture");

#endif

// end of op_qgetvn.cpp
