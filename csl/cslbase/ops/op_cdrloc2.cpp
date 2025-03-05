// op_cdrloc2.cpp

#if defined BYTECODE
            case OP_CDRLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else 
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CDRLOC2:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -16));
                cc.test(A_reg, TAG_BITS);
                cc.jne(cdrError);
                cc.mov(A_reg, ptr(A_reg, 8));
                break;

#elif defined __aarch64__

            case OP_CDRLOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CDRLOC2:
                unfinished("Unsupported architecture");

#endif

// end of op_cdrloc2.cpp
