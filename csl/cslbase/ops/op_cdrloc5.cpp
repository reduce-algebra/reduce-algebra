// cdrloc5.cpp

#if defined BYTECODE
            case OP_CDRLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else 
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CDRLOC5:
                mov(B_reg, A_reg);
                loadloc(A_reg, 5);
                JITcdrvalid(A_reg);
                loadreg(A_reg, A_reg, 8);
                break;

#else
            case OP_CDRLOC5:
                unfinished("Unsupported architecture");

#endif

// end of cdrloc5.cpp
