// op_cdr.cpp

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
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CDR:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CDR:
                myabort("Unsupported architecture");

#endif
