// $Id$

#if defined BYTECODE
            case OP_UNCATCH:
                stack--;                // SPID_CATCH
                r1 = *stack--;          // catch_tags while this one active
                stack--;                // destination address if throw used
                catch_tags = cdr(r1);   // this tag no longer in use
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_UNCATCH:
                unfinished(__FILE__ " not yet implemented for x86_64");

#else
            case OP_UNCATCH:
                unfinished("Unsupported architecture");

#endif

// end of op_uncatch.cpp
