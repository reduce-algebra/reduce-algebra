// $Id$

#if defined BYTECODE
            case OP_PUSHNILS:
                n = next_byte;
                for (k=0; k<n; k++) *++stack = nil;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PUSHNILS:
                next = bytes[ppc++];
                storereg_pre(nilreg, spreg, 8*next);
                for (int k=1; k<next; k++)
                    storeloc(nilreg, k);
                break;

#else
            case OP_PUSHNILS:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnils.cpp
