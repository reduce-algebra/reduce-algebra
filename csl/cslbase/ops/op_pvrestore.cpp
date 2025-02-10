// op_pvrestore.cpp

#if defined BYTECODE
            case OP_PVRESTORE:
                do_pvrestore();
                continue;

#elif defined __x86_64__

            case OP_PVRESTORE:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PVRESTORE:
                myabort("This case not yet implemented for ARM");

#else
            case OP_PVRESTORE:
                myabort("Unsupported architecture");

#endif
