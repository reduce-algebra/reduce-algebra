// op_pushnil.cpp

#if defined BYTECODE
            case OP_PUSHNIL:
                *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNIL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PUSHNIL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNIL:
                unfinished("Unsupported architecture");

#endif
