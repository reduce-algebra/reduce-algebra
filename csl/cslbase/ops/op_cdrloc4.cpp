// op_cdrloc4.cpp

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
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CDRLOC4:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CDRLOC4:
                myabort("Unsupported architecture");

#endif
