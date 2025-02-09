// op_numberp.cpp

#if defined BYTECODE
            case OP_NUMBERP:                                // A = numberp(A)
                A_reg = Lispify_predicate(is_number(A_reg));
                continue;

#elif defined __x86_64__

            case OP_NUMBERP:                                // A = numberp(A)
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_NUMBERP:                                // A = numberp(A)
                myabort("This case not yet implemented for ARM");

#else
            case OP_NUMBERP:                                // A = numberp(A)
                myabort("Unsupported architecture");

#endif
