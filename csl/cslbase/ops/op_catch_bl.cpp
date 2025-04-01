// catch_bl.cpp $Id$

#if defined BYTECODE
            case OP_CATCH_BL:
                w = next_byte;
                w = static_cast<unsigned int>(ppc - ((w << 8) +
                                                     (reinterpret_cast<unsigned char *>(codevec))[ppc]));
                ppc++;
            catcher:
                *++stack = fixnum_of_int(w+1);
                *++stack = catch_tags = cons(A_reg, catch_tags);
                *++stack = SPID_CATCH;
                continue;

#elif defined __x86_64__

            case OP_CATCH_BL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CATCH_BL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CATCH_BL:
                unfinished("Unsupported architecture");

#endif

// end of op_catch_bl.cpp
