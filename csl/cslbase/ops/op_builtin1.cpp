// builtin1.cpp $Id$

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

#elif defined __x86_64__ || defined __aarch64__

            case OP_BUILTIN1:
                next = bytes[ppc++];
                mov(w1, one_arg_functions[next]);
                JITcall(JITshim1L, A_reg,
                        w1, nilreg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_BUILTIN1:
                unfinished("Unsupported architecture");

#endif

// end of op_builtin1.cpp
