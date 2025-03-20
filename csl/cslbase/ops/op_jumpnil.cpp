// jumpnil.cpp

#if defined BYTECODE
            case OP_JUMPNIL:
                xppc = ppc;
                ppc++;
// short_jump uses the next byte of the bytestream as an offset
// forward from the current instruction. short_jump_back is similar
// but the offset goes back rather than forward. long_jump and
// long_jump_back take two bytes from the codestream so they support
// a 16-bit positive or negative offset.
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNIL:
                next = bytes[ppc++];
                cmp(A_reg, nilreg);
                je(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPNIL:
                next = bytes[ppc++];
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNIL:
                unfinished("Unsupported architecture");

#endif

// end of jumpnil.cpp
