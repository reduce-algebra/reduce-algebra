// op_jumpliteq.cpp

#if defined BYTECODE
            case OP_JUMPLITEQ:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(
                    basic_elt(litvec, w)) == A_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPLITEQ:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPLITEQ:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPLITEQ:
                myabort("Unsupported architecture");

#endif
