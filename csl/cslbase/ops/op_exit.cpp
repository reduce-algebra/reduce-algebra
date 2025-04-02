// exit.cpp $Id$

#if defined BYTECODE
            case OP_EXIT:
//
// Here I assume that exit_count has been set up already. Note also that
// there is no need to do any LOSE rations just before an EXIT since the
// stack gets reset automatically here.
//
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif
// This SAYS "return nil" but that is in fact exiting from a lambda-
// expression associated with a TRY/CATCH and after the TRY block is
// completed the value that will actually be returned to the caller is
// whatever is in A_reg.
//              return A_reg;
                return nil;

#elif defined __x86_64__

            case OP_EXIT:
                jmp(returnA);
                break;

#elif defined __aarch64__

            case OP_EXIT:
                b(returnA);
                break;

#else
            case OP_EXIT:
                unfinished("Unsupported architecture");

#endif

// end of exit.cpp
