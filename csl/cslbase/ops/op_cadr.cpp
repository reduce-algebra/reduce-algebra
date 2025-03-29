// cadr.cpp

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

#elif defined __x86_64__ || defined __aarch64__

            case OP_CADR:
                JITcdrvalid(A_reg);
                loadreg(A_reg, A_reg, 8);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CADR:
                unfinished("Unsupported architecture");

#endif

// end of cadr.cpp
