// caar.cpp

#if defined BYTECODE
            case OP_CAAR:
            caar:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CAAR:
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                JITcarvalid(A_reg);
                loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CAAR:
                unfinished("Unsupported architecture");

#endif

// end of caar.cpp
