// $Id$

#if defined BYTECODE
            case OP_CARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CARLOC2:
                mov(B_reg, A_reg);
                loadloc(A_reg, 2);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CARLOC2:
                unfinished("Unsupported architecture");

#endif

// end of carloc2.cpp
