// op_jumpnil_l.cpp

#if defined BYTECODE
            case OP_JUMPNIL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + ((w << 8) +
                                                   (reinterpret_cast<unsigned char *>(codevec))[xppc]);
                continue;

#elif defined __x86_64__

            case OP_JUMPNIL_L:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNIL_L:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPNIL_L:
                myabort("Unsupported architecture");

#endif
