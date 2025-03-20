// call1_5.cpp

#if defined BYTECODE
            case OP_CALL1_5:
                fname = 5;
                goto call1;

#elif defined __x86_64__

            case OP_CALL1_5:
                mov(w, ptr(nilreg, JIToffset(OJITshim2)));
                mov(w2, ptr(litvec, 40+CELL-TAG_VECTOR));
                mov(w1,
                       ptr(w2, offsetof(Symbol_Head, function1)-TAG_SYMBOL));
                JITcall(w, A_reg,
                       w, w1, w2, A_reg);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;


#elif defined __aarch64__

            case OP_CALL1_5:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL1_5:
                unfinished("Unsupported architecture");

#endif

// end of call1_5.cpp
