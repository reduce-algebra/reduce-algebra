// catch_l.cpp $Id$

#if defined BYTECODE
            case OP_CATCH_L:
                w = next_byte;
                w = static_cast<unsigned int>(ppc + (w << 8) +
                                              (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                ppc++;
                goto catcher;

#elif defined __x86_64__

            case OP_CATCH_L:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CATCH_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CATCH_L:
                unfinished("Unsupported architecture");

#endif

// end of op_catch_l.cpp
