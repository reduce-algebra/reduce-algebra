// op_cadr.cpp

#if defined BYTECODE
            case OP_CADR:
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CADR:
                cc.test(A_reg, TAG_BITS);
                cc.jne(cdrError);
                cc.mov(A_reg, ptr(A_reg, 8));
                cc.test(A_reg, TAG_BITS);
                cc.jne(carError);
                cc.mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CADR:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CADR:
                unfinished("Unsupported architecture");

#endif

// end of op_cadr.cpp
