// carloc1.cpp $Id$

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

#elif defined __x86_64__ || defined __aarch64__

            case OP_CARLOC1:
                mov(B_reg, A_reg);
                loadloc(A_reg, 1);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CARLOC1:
                unfinished("Unsupported architecture");

#endif

// end of carloc1.cpp
