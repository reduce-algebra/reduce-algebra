// builtin0.cpp $Id$

#if defined BYTECODE
            case OP_BUILTIN0:
// At present this uses the "old" scheme for functions that do not take
// arguments that passes the integer 0 to tell them of the lack of args
// actually passed.
                f0 = no_arg_functions[next_byte];
                debug_record_int("BUILTIN0", previous_byte);
// BUILTIN0:  A=fn()
                {
                    if (no_arg_traceflags[previous_byte])
                        A_reg = traced_call0(basic_elt(litvec, 0), f0,
                                             make_undefined_symbol(no_arg_names[previous_byte]));
                    else A_reg = f0(nil);
                }
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_BUILTIN0:
                next = bytes[ppc++];
                loadstatic(w, OJITshim0L);
                mov(w1, no_arg_functions[next]);
                JITcall(w, A_reg,
                        w1, nilreg);
                JITerrorcheck();
                break;

#else
            case OP_BUILTIN0:
                unfinished("Unsupported architecture");

#endif

// end of op_builtin0.cpp
