// $Id$

#if defined BYTECODE
            case OP_FREERSTR:
                do_freerstr();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_FREERSTR:
                JITcall(do_freerstr, w);  // result of fn call not used
// freerstr() can not generate an exception so I do not need to check for
// one here, but it does alter the stack, so I need to update spreg.
                loadstatic(spreg, Ostack);
                break;

#else
            case OP_FREERSTR:
                unfinished("Unsupported architecture");

#endif

// end of op_freerstr.cpp
