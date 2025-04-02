// numberp.cpp $Id$

#if defined BYTECODE
            case OP_NUMBERP:                                // A = numberp(A)
                A_reg = Lispify_predicate(is_number(A_reg));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_NUMBERP:                                // A = numberp(A)
                {   Label numberpyes = newLabel();
                    Label endNumberp = newLabel();
                    and3(w, A_reg, TAG_BITS);
                    cmp(w, TAG_NUMBERS);
                    jge(numberpyes);
                    mov(A_reg, nilreg);
                    jmp(endNumberp);
                bind(numberpyes);
                    loadstatic(A_reg, Olisp_true);
                bind(endNumberp);
                }
                break;

#else
            case OP_NUMBERP:                                // A = numberp(A)
                unfinished("Unsupported architecture");

#endif

// end of op_numberp.cpp
