// $Id$

#if defined BYTECODE
            case OP_UNPROTECT:
// This must restore all the results (including exit_count). If the
// PROTECT had been done by an unwinding then exit_reason and exit_tag
// must also be restored, and the unwind condition must be re-instated.
                A_reg = *stack--; B_reg = *stack--; exit_tag = *stack--;
                exit_reason = int_of_fixnum(B_reg);
// Here I have multiple values to restore.
                exit_count = 0;
                B_reg = A_reg;
                A_reg = nil;
                if (consp(B_reg))
                {   A_reg = car(B_reg);
                    B_reg = cdr(B_reg);
                    exit_count++;
                    while (consp(B_reg))
                    {   (&mv_1)[exit_count++] = car(B_reg);
                        B_reg = cdr(B_reg);
                    }
                }
                exit_value = A_reg;
// Here after performing the unwind-protect code I must restore a throw
// action that was the same sort as the one that caused me to arrive. I
// think that will involve switching on exit_reason and trying to re-create
// the correct state. In native C++ situations I would be able to go just
// "throw;" without an rand except that in this code I am now outside
// the block that was the signal handler.
                switch (exit_reason)
                {   case UNWIND_NULL:      continue;
                    case UNWIND_GO:        THROW(LispGo);
                    case UNWIND_RETURN:    THROW(LispReturnFrom);
                    case UNWIND_THROW:     THROW(LispThrow);
                    case UNWIND_RESTART:   THROW(LispRestart);
                    case UNWIND_RESOURCE:  THROW(LispResource);
                    case UNWIND_ERROR:     THROW(LispSimpleError);
                    case UNWIND_FNAME:     THROW(LispSimpleError);
                    case UNWIND_UNWIND:    THROW(LispSimpleError);
                    default:               THROW(LispSimpleError);
                }

#elif defined __x86_64__

            case OP_UNPROTECT:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_UNPROTECT:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_UNPROTECT:
                unfinished("Unsupported architecture");

#endif

// end of op_unprotect.cpp
