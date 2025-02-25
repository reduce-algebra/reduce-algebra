// op_carloc1.cpp

#if defined BYTECODE
            case OP_CARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CARLOC1:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -8));
                cc.test(A_reg, 7);
                cc.jne(carError);
                cc.mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CARLOC1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CARLOC1:
                unfinished("Unsupported architecture");

#endif
