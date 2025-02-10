// op_cddr.cpp

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


//
// The ICASE opcode is followed by a byte (n say) that indicates the number
// of cases that follow, followed by n+1 double-byte label values.
// If these addresses are called L<dflt>, L<0>, L<1>, ... L<n-1> then if the
// A register contains an integer in the range 0 <= k < n then control is
// transferred to L<k>, while if the A register does not hold an integer or
// if its value is out of range then control goes to L<dflt>.
//
#elif defined __x86_64__

            case OP_CDDR:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CDDR:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CDDR:
                myabort("Unsupported architecture");

#endif
