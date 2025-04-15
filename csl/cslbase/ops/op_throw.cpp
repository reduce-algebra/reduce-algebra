// $Id$

#if defined BYTECODE
            case OP_THROW:
                r1 = *stack--;       // The tag to throw to.
// Check if tag is one we will handle.
                for (r2 = catch_tags; r2!=nil; r2=cdr(r2))
                    if (r1 == car(r2)) break;
                if (r2==nil) return aerror1("throw: tag not found", r1);
                catch_tags = cdr(r2);
                exit_tag = r2;       // cdr() will go back in catch_tags
                exit_value = A_reg;
                exit_reason = UNWIND_THROW;
                THROW(LispThrow);

// I expect that calling functions with 0, 1, 2 or 3 arguments will
// be enormously important for Lisp, and so separate odes are provided
// for these cases.  The rand in each case selects the function to be
// called, which MUST be a symbol (loaded from the literal vector),
// and arguments are taken from A and B as necessary.  If several
// arguments are needed the first argument will be loaded first, and thus
// it is the LAST argument that end up in the A register.

#elif defined __x86_64__

            case OP_THROW:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_THROW:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_THROW:
                unfinished("Unsupported architecture");

#endif

// end of op_throw.cpp
