// $Id$

#if defined BYTECODE
            case OP_PROTECT:
// This is used to support UNWIND-PROTECT.
// This needs to save A_reg, all the multiple-result registers,
// and the exit_count. Also something to indicate that there had not been
// an error.
                stack--; r1 = *stack--; stack--;
                catch_tags = cdr(r1);
                car(r1) = r1; cdr(r1) = nil;
                A_reg = Lmv_list(nil, A_reg);
                *++stack = nil;
                *++stack = fixnum_of_int(UNWIND_NULL);
                *++stack = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PROTECT:
                unfinished(__FILE__ " not yet implemented for x86_64");

#else
            case OP_PROTECT:
                unfinished("Unsupported architecture");

#endif

// end of op_protect.cpp
