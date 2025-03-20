// acons.cpp

#if defined BYTECODE
            case OP_ACONS:                  // A_reg = acons(p), B_reg, A_reg);
                // = (p) . B) . A
                r1 = *stack--;
                A_reg = acons(r1, B_reg, A_reg);
                errexit();
                continue;

//
// For the next two odes the first argument to the current function
// must have been an environment pointer as set up with CLOSURE. I do
// not check that I have a closure object - perhaps I can excuse that by
// claiming that all creation and management of encapsulated closures
// will have been introduced by the compiler, which I prse to trust!
// (actually as of April 2002 I think there may be bugs I need to fix...)
// Note that this has STILL not been heavily tested!
#elif defined __x86_64__

            case OP_ACONS:                  // A_reg = acons(p), B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_ACONS:                  // A_reg = acons(p), B_reg, A_reg);
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_ACONS:                  // A_reg = acons(p), B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_acons.cpp
