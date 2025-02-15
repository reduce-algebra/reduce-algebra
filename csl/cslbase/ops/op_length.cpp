// op_length.cpp

#if defined BYTECODE
            case OP_LENGTH:
                A_reg = Llength(nil, A_reg);
                errexit();
                continue;

//
// The following combinations feel a little odd, but ONE of them showed up
// very clearly in REDUCE tests, and adding the other few seems liable
// (on sentiment, not measurement!) to make reasonable sense.
//
#elif defined __x86_64__

            case OP_LENGTH:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LENGTH:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LENGTH:
                unfinished("Unsupported architecture");

#endif
