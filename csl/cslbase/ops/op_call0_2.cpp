// call0_2.cpp

#if defined BYTECODE
            case OP_CALL0_2:
                fname = 2;
                goto call0;

#elif defined __x86_64__

            case OP_CALL0_2:
                mov(w, ptr(nilreg, JIToffset(OJITshim1)));
                mov(w1, ptr(litvec, 16+CELL-TAG_VECTOR));
// w1 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 0 args.
                mov(w1,
                       ptr(w1, offsetof(Symbol_Head, function0)-TAG_SYMBOL));
                JITcall(w, A_reg,
                       w1);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_CALL0_2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL0_2:
                unfinished("Unsupported architecture");

#endif

// call0_2.cpp

// end of op_call0_2.cpp
