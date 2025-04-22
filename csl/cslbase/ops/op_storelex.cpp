// $Id$

#if defined BYTECODE
            case OP_STORELEX:
                r1 = elt(stack[1-static_cast<int>(next_byte)], 0);
                w = next_byte;             // Number of levels to chain
                while (w != 0) r1 = (reinterpret_cast<LispObject *>(r1))[1], w--;
                (reinterpret_cast<LispObject *>(r1))[next_byte] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

// As with LOADLEX this is easier than one might have feared.

            case OP_STORELEX:
                unfinished(__FILE__ " not yet implemented for JIT");

#else
            case OP_STORELEX:
                unfinished("Unsupported architecture");

#endif

// end of op_storelex.cpp
