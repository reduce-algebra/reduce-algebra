// op_carloc11.cpp

#if defined BYTECODE
            case OP_CARLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CARLOC11:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CARLOC11:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CARLOC11:
                myabort("Unsupported architecture");

#endif
