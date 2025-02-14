// op_builtin2.cpp

#if defined BYTECODE
            case OP_BUILTIN2:
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2", previous_byte);
// BUILTIN2:   A=fn(B,A);
                if (two_arg_traceflags[previous_byte])
                    A_reg = traced_call2(basic_elt(litvec, 0), f2,
                                         make_undefined_symbol(two_arg_names[previous_byte]),
                                         B_reg, A_reg);
                A_reg = f2(nil, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_BUILTIN2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_BUILTIN2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_BUILTIN2:
                unfinished("Unsupported architecture");

#endif
