// cdrloc4.cpp

#if defined BYTECODE
            case OP_CDRLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else 
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CDRLOC4:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg, -32));
                test(A_reg, 7);
                jne(cdrError);
                mov(A_reg, ptr(A_reg, 8));
                break;

#elif defined __aarch64__

            case OP_CDRLOC4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CDRLOC4:
                unfinished("Unsupported architecture");

#endif

// end of op_cdrloc4.cpp
