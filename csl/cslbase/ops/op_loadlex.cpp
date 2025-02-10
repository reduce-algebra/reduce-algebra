// op_loadlex.cpp

#if defined BYTECODE
            case OP_LOADLEX:
                r1 = elt(stack[1-static_cast<int>(next_byte)], 0);
                B_reg = A_reg;
                w = next_byte;             // Number of levels to chain
                while (w != 0) r1 = (reinterpret_cast<LispObject *>(r1))[1], w--;
                A_reg = (reinterpret_cast<LispObject *>(r1))[next_byte];
                continue;

#elif defined __x86_64__

            case OP_LOADLEX:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLEX:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADLEX:
                myabort("Unsupported architecture");

#endif
