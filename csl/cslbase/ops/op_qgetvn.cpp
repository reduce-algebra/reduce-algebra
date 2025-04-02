// qgetvn.cpp $Id$

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
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_QGETVN:                         // A_reg = getv(A_reg, n)
                unfinished("Unsupported architecture");

#endif

// end of op_qgetvn.cpp
