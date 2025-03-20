// loc2exit.cpp

#if defined BYTECODE
            case OP_LOC2EXIT:
                A_reg = stack[-2];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif
//              return A_reg;
                return nil;

#elif defined __x86_64__

            case OP_LOC2EXIT:
                mov(A_reg, ptr(spreg, -16));
                jmp(returnA);
                break;

#elif defined __aarch64__

            case OP_LOC2EXIT:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC2EXIT:
                unfinished("Unsupported architecture");

#endif

// end of loc2exit.cpp
