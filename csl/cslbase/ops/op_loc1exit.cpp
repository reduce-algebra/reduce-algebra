// op_loc1exit.cpp

#if defined BYTECODE
            case OP_LOC1EXIT:
                A_reg = stack[-1];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif
//              return A_reg;
                return nil;


#elif defined __x86_64__

            case OP_LOC1EXIT:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOC1EXIT:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC1EXIT:
                unfinished("Unsupported architecture");

#endif
