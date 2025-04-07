// default.cpp $Id$

#if defined BYTECODE
            default:
//
// Here I have an unrecognised ode - the result of a compiler error
//
                err_printf("\nUnrecognized ode byte %x\n",
                           (reinterpret_cast<unsigned char *>(codevec))[ppc-1]);
                return aerror("compiler failure");

#elif defined __x86_64__ || defined __aarch64__

            default:
                unfinished(__FILE__ " not yet implemented for x86_64/aarch64");

#else
            default:
                unfinished("Unsupported architecture");

#endif

// end of default.cpp
