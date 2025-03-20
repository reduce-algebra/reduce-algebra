// nilexit.cpp

#if defined BYTECODE
            case OP_NILEXIT:
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif
                A_reg = nil;
                return nil;

#elif defined __x86_64__

            case OP_NILEXIT:
                mov(A_reg, nilreg);
                jmp(returnA);
                break;

#elif defined __aarch64__

            case OP_NILEXIT:
                mov(A_reg, nilreg);
                b(returnA);
                break;

#else
            case OP_NILEXIT:
                unfinished("Unsupported architecture");

#endif

// end of op_nilexit.cpp
