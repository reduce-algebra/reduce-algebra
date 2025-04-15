// $Id$

#if defined BYTECODE
// This opcode takes 3 byte operands.
// The first gives access to the start of the current stack-frame
// The second is a count of how many frames to descend. I think that
// the concept was that each function needing to use lexicals it gets
// an additional implicit first argument. This only applies in cases
// where the function was an embedded lambda expression, since
// otherwise function specifications do not end up nested. This
// extra argument provides a chain to further enclosing stack frames.
// it used the value from encapsulate_sp() to make the pointer into
// the stack into something that can exist in the Lisp world.
// When the correct stack frame has been reached the third byte
// provides access to the desired variable. Note that the address
// used here counts up from the base of the stack-frame rather than
// the scheme used elsewhere that addresses things relative to the
// stack fringe.
            case OP_LOADLEX:
                r1 = elt(stack[1-static_cast<int>(next_byte)], 0);
                B_reg = A_reg;
                w = next_byte;             // Number of levels to chain
                while (w != 0)
                    r1 = (reinterpret_cast<LispObject *>(r1))[1], w--;
                A_reg = (reinterpret_cast<LispObject *>(r1))[next_byte];
                continue;

#elif defined __x86_64__ || defined __aarch64__

// The above logic should apply in JIT code as well as bytecoded stuff
// since the stack layout and content will be the same in each case.

            case OP_LOADLEX:
                unfinished(__FILE__ " not yet implemented for x86_64");

#else
            case OP_LOADLEX:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlex.cpp
