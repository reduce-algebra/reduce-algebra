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

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC2EXIT:
                loadloc(A_reg, 2);
                jmp(returnA);
                break;

#else
            case OP_LOC2EXIT:
                unfinished("Unsupported architecture");

#endif

// end of loc2exit.cpp
