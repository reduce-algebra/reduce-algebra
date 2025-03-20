// car.cpp

#if defined BYTECODE
            case OP_CAR:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CAR:
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CAR:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAR:
                unfinished("Unsupported architecture");

#endif

// end of car.cpp
