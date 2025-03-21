// cdr.cpp

#if defined BYTECODE
            case OP_CDR:
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CDR:
                test(A_reg, TAG_BITS);
                jne(cdrError);
                mov(A_reg, ptr(A_reg, 8));
                break;

#elif defined __aarch64__

            case OP_CDR:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CDR:
                unfinished("Unsupported architecture");

#endif

// end of cdr.cpp
