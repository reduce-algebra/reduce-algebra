// op_cdrloc1.cpp

#if defined BYTECODE
            case OP_CDRLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CDRLOC1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CDRLOC1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CDRLOC1:
                unfinished("Unsupported architecture");

#endif
