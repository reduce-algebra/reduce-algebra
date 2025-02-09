// op_cdar.cpp

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
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CDAR:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CDAR:
                myabort("Unsupported architecture");

#endif
