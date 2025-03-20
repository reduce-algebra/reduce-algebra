// pushnils.cpp

#if defined BYTECODE
            case OP_PUSHNILS:
                n = next_byte;
                for (k=0; k<n; k++) *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNILS:
                next = bytes[ppc++];
                for (int k=0; k<next; k++)
                {   add(spreg, 8);
                    storeloc(nilreg, 0);
                }
                break;

#elif defined __aarch64__

            case OP_PUSHNILS:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNILS:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnils.cpp
