// builtin3.cpp

#if defined BYTECODE
            case OP_BUILTIN3:
                f3 = three_arg_functions[next_byte];
                debug_record_int("BUILTIN3", previous_byte);
// CALL3:   A=fn(p),B,A);
                r1 = *stack--;
                if (three_arg_traceflags[previous_byte])
                    A_reg = traced_call3(basic_elt(litvec, 0), f3,
                                         make_undefined_symbol(three_arg_names[previous_byte]),
                                         r1, B_reg, A_reg);
                else A_reg = f3(nil, r1, B_reg, A_reg);
                errexit();
                continue;

//
// Now here in a neat block I will have the cases that seem to occur most
// frequently, at least when I tested things running REDUCE. By collecting
// these together I h to (slightly) improve the cache locality behaviour
// for this code - maybe...
//
#elif defined __x86_64__

            case OP_BUILTIN3:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_BUILTIN3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_BUILTIN3:
                unfinished("Unsupported architecture");

#endif

// end of op_builtin3.cpp
