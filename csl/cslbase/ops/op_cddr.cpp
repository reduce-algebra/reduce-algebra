// cddr.cpp $Id$

#if defined BYTECODE
            case OP_CDDR:
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;


#elif defined __x86_64__ || defined __aarch64__

            case OP_CDDR:
                JITcdrvalid(A_reg);
                loadreg(A_reg, A_reg, 8);
                JITcdrvalid(A_reg);
                loadreg(A_reg, A_reg, 8);
                break;

#else
            case OP_CDDR:
                unfinished("Unsupported architecture");

#endif

// end of cddr.cpp