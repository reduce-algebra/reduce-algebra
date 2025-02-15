// op_builtin1.cpp

#if defined BYTECODE
            case OP_BUILTIN1:
                f1 = one_arg_functions[next_byte];
                debug_record_int("BUILTIN1", previous_byte);
// BUILTIN1:   A=fn(A);
                if (one_arg_traceflags[previous_byte])
                    A_reg = traced_call1(basic_elt(litvec, 0), f1,
                                         make_undefined_symbol(one_arg_names[previous_byte]),
                                         A_reg);
                A_reg = f1(nil, A_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_BUILTIN1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_BUILTIN1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_BUILTIN1:
                unfinished("Unsupported architecture");

#endif
