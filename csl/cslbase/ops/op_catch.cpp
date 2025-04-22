// $Id$

#if defined BYTECODE
            case OP_CATCH:
                w = static_cast<unsigned int>(ppc +
                                              (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                ppc++;
                goto catcher;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CATCH:
                unfinished(__FILE__ " not yet implemented for x86_64");

#else
            case OP_CATCH:
                unfinished("Unsupported architecture");

#endif

// end of op_catch.cpp
