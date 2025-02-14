// op_call0_0.cpp

#if defined BYTECODE
            case OP_CALL0_0:      // Calling myself...
                fname = 0;
                goto call0;

#elif defined __x86_64__

            case OP_CALL0_0:      // Calling myself...
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL0_0:      // Calling myself...
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL0_0:      // Calling myself...
                unfinished("Unsupported architecture");

#endif
