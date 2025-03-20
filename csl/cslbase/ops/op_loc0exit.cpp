// loc0exit.cpp

#if defined BYTECODE
            case OP_LOC0EXIT:
// If I execute this ode then I will have followed a path that will have
// executed previous odes to restore fluids etc. entry_stack is where the
// stack needs to be so that arguments have been ped as necessary.
                A_reg = stack[0];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif

// Note that with my re-work of TRY/CATCH the "return" here just exits
// from the TRY block, and after that the value in the A register is returned.
//              return A_reg;
                return nil;


#elif defined __x86_64__

            case OP_LOC0EXIT:
                mov(A_reg, ptr(spreg));
                jmp(returnA);
                break;

#elif defined __aarch64__

            case OP_LOC0EXIT:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC0EXIT:
                unfinished("Unsupported architecture");

#endif

// end of op_loc0exit.cpp
