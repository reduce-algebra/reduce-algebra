// $Id$

#if defined BYTECODE
            case OP_LOSES:
                stack -= next_byte;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOSES:
                next = bytes[ppc++];
                sub2(spreg, next);
                break;

#else
            case OP_LOSES:
                unfinished("Unsupported architecture");

#endif

// end of loses.red
