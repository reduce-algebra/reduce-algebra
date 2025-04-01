// freebind.cpp $Id$

#if defined BYTECODE
            case OP_FREEBIND:
                do_freebind(basic_elt(litvec, next_byte));
                continue;

#elif defined __x86_64__

            case OP_FREEBIND:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_FREEBIND:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_FREEBIND:
                unfinished("Unsupported architecture");

#endif

// end of op_freebind.cpp
