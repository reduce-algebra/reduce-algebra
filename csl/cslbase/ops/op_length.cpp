// $Id$

#if defined BYTECODE
            case OP_LENGTH:
                A_reg = Llength(nil, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LENGTH:
                mov(w1, Llength);
                JITcall(JITshim1L, A_reg,
                        w1, nilreg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_LENGTH:
                unfinished("Unsupported architecture");

#endif

// end of op_length.cpp
