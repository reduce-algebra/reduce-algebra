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

#elif defined __x86_64__ || defined __aarch64__

            case OP_BUILTIN3:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_BUILTIN3:
                unfinished("Unsupported architecture");

#endif

// end of op_builtin3.cpp
