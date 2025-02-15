// op_loses.cpp

#if defined BYTECODE
            case OP_LOSES:
                stack -= next_byte;
                continue;

#elif defined __x86_64__

            case OP_LOSES:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOSES:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOSES:
                unfinished("Unsupported architecture");

#endif
