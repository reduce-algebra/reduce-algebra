// op_pushnils.cpp

#if defined BYTECODE
            case OP_PUSHNILS:
                n = next_byte;
                for (k=0; k<n; k++) *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNILS:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PUSHNILS:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNILS:
                unfinished("Unsupported architecture");

#endif
