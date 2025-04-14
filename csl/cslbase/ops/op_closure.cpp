// $Id$

#if defined BYTECODE
            case OP_CLOSURE:
                *++stack = B_reg; *++stack = A_reg;
// This will be the address where the first arg of this function lives on
// the stack.  It provides a hook for the called function to access lexical
// variables.
                w = next_byte;
                A_reg = encapsulate_sp(&stack[-2-static_cast<int>(w)]);
                errexit();
                B_reg = *stack--;
                A_reg = list2star(cfunarg, B_reg, A_reg);
                errexit();
                B_reg = *stack--;
                continue;

#elif defined __x86_64__ || defined __aarch64__

// I just need to copy the above logic.

            case OP_CLOSURE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#else
            case OP_CLOSURE:
                unfinished("Unsupported architecture");

#endif

// end of op_closure.cpp
