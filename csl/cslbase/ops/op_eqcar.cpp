// $Id$

#if defined BYTECODE
            case OP_EQCAR:
                if (car_legal(B_reg) && A_reg == car(B_reg)) A_reg = lisp_true;
                else A_reg = nil;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_EQCAR:
                {   Label noteqcar = newLabel();
                    Label doneeqcar = newLabel();
                    JITatomic(B_reg, noteqcar);
                    loadreg(w, B_reg, 0);
                    cmp(A_reg, w);
                    jne(noteqcar);
                    loadstatic(A_reg, Olisp_true);
                    jmp(doneeqcar);
                bind(noteqcar);
                    mov(A_reg, nilreg);
                bind(doneeqcar);
                }
                break;

#else
            case OP_EQCAR:
                unfinished("Unsupported architecture");

#endif

// end of op_eqcar.cpp
