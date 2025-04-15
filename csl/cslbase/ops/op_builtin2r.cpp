// $Id$

#if defined BYTECODE
            case OP_BUILTIN2R:
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2R", previous_byte);
// BUILTIN2R:   A=fn(A,B); NOTE arg order reversed
                if (two_arg_traceflags[previous_byte])
                    A_reg = traced_call2(basic_elt(litvec, 0), f2,
                                         make_undefined_symbol(two_arg_names[previous_byte]),
                                         A_reg, B_reg);
                else A_reg = f2(nil, A_reg, B_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__
            case OP_BUILTIN2R:
                next = bytes[ppc++];
                mov(w1, two_arg_functions[next]);
                JITcall(JITshim2L, A_reg,
                        w1, nilreg, A_reg, B_reg);
                JITerrorcheck();
                break;


#else
            case OP_BUILTIN2R:
                unfinished("Unsupported architecture");

#endif

// end of op_builtin2r.cpp
