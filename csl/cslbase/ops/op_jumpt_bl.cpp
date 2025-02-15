// op_jumpt_bl.cpp

#if defined BYTECODE
            case OP_JUMPT_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil)
                {   ppc = ppc - ((w << 8) + (reinterpret_cast<unsigned char *>
                                             (codevec))[xppc]);
                    poll_jump_back(A_reg);
                }
                continue;

#elif defined __x86_64__

            case OP_JUMPT_BL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPT_BL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPT_BL:
                unfinished("Unsupported architecture");

#endif
