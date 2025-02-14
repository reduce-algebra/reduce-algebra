// op_eqcar.cpp

#if defined BYTECODE
            case OP_EQCAR:
                if (car_legal(B_reg) && A_reg == car(B_reg)) A_reg = lisp_true;
                else A_reg = nil;
                continue;

#elif defined __x86_64__

            case OP_EQCAR:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_EQCAR:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_EQCAR:
                unfinished("Unsupported architecture");

#endif
