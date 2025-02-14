// op_onevalue.cpp

#if defined BYTECODE
            case OP_ONEVALUE:
// ONEVALUE is here to support a proposed re-write of the multiple values
// handling scheme.
                exit_count = 1;
                continue;

#elif defined __x86_64__

            case OP_ONEVALUE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_ONEVALUE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_ONEVALUE:
                unfinished("Unsupported architecture");

#endif
