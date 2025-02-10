// default.cpp

#if defined BYTECODE
            default:
//
// Here I have an unrecognised opcode - the result of a compiler error
//
                err_printf("\nUnrecognized opcode byte %x\n",
                           (reinterpret_cast<unsigned char *>(codevec))[ppc-1]);
                return aerror("compiler failure");

#elif defined __x86_64__

            default:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            default:
                myabort("This case not yet implemented for ARM");

#else
            default:
                myabort("Unsupported architecture");

#endif
