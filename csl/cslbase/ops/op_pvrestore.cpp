// $Id$

#if defined BYTECODE
            case OP_PVRESTORE:
                do_pvrestore();
                continue;

#elif defined __x86_64__

            case OP_PVRESTORE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PVRESTORE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PVRESTORE:
                unfinished("Unsupported architecture");

#endif

// end of op_pvrestore.cpp
