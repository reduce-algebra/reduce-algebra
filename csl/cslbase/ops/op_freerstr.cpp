// op_freerstr.cpp

#if defined BYTECODE
            case OP_FREERSTR:
                do_freerstr();
                continue;

#elif defined __x86_64__

            case OP_FREERSTR:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_FREERSTR:
                myabort("This case not yet implemented for ARM");

#else
            case OP_FREERSTR:
                myabort("Unsupported architecture");

#endif
