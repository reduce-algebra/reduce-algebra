// carloc4.cpp

#if defined BYTECODE
            case OP_CARLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CARLOC4:
                mov(B_reg, A_reg);
                loadloc(A_reg, 4);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CARLOC4:
                unfinished("Unsupported architecture");

#endif

// end of carloc4.cpp
