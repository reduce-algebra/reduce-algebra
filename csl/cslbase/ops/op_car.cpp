// car.cpp $Id$

#if defined BYTECODE
            case OP_CAR:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CAR:
                JITcarvalid(A_reg);
                 loadreg(A_reg, A_reg, 0);
                break;

#else
            case OP_CAR:
                unfinished("Unsupported architecture");

#endif

// end of car.cpp
