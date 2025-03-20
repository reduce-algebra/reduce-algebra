// carloc8.cpp

#if defined BYTECODE
            case OP_CARLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CARLOC8:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg, -64));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CARLOC8:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CARLOC8:
                unfinished("Unsupported architecture");

#endif

// end of carloc8.cpp
