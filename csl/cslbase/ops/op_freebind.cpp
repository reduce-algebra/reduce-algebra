// freebind.cpp $Id$

#if defined BYTECODE
            case OP_FREEBIND:
                do_freebind(basic_elt(litvec, next_byte));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_FREEBIND:
                next = bytes[ppc++];
                loadstatic(w, OJITfreebind);
                loadlit(w1, next);
                JITcall(w, w,
                        w1);
// freebind() can not generate an exception so I do not need to check for
// one here, but it does alter the stack, so I need to update spreg.
                loadstatic(spreg, Ostack);
                break;

#else
            case OP_FREEBIND:
                unfinished("Unsupported architecture");

#endif

// end of op_freebind.cpp
