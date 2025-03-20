// jumpfreet.cpp

#if defined BYTECODE
            case OP_JUMPFREET:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPFREET:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPFREET:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPFREET:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpfreet.cpp
