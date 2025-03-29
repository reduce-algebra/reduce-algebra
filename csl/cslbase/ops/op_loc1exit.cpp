// loc1exit.cpp

#if defined BYTECODE
            case OP_LOC1EXIT:
                A_reg = stack[-1];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif
//              return A_reg;
                return nil;


#elif defined __x86_64__ || defined __aarch64__

            case OP_LOC1EXIT:
                loadloc(A_reg, 1);
                jmp(returnA);
                break;

#else
            case OP_LOC1EXIT:
                unfinished("Unsupported architecture");

#endif

// end of op_loc1exit.cpp
