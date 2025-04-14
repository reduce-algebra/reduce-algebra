// $Id$

#if defined BYTECODE
            case OP_CAARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                goto caar;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CAARLOC0:
                mov(B_reg, A_reg);
                loadloc(A_reg, 0);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CAARLOC0:
                unfinished("Unsupported architecture");

#endif

// end of caarloc.cpp
