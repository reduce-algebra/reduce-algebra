// cdar.cpp

#if defined BYTECODE
            case OP_CDAR:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CDAR:
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                test(A_reg, TAG_BITS);
                jne(cdrError);
                mov(A_reg, ptr(A_reg, 8));
                break;

#elif defined __aarch64__

            case OP_CDAR:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CDAR:
                unfinished("Unsupported architecture");

#endif

// end of cdar.cpp
