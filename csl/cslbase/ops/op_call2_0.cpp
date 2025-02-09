// op_call2_0.cpp

#if defined BYTECODE
            case OP_CALL2_0:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACED) != 0)
                {   fname = 0;
                    goto call2;
                }
                {   stack_restorer saver;
                    STACK_SANITY;
                    *++stack = B_reg; *++stack = A_reg;
                    RECORD_CALL(list3(basic_elt(litvec, 0), B_reg, A_reg));
                    if (reinterpret_cast<uintptr_t>(stack) >= stackLimit)
                        respond_to_stack_event();
                    A_reg = bytestream_interpret(CELL-TAG_VECTOR, basic_elt(litvec, 0),
                                                 stack-2);
                }
                errexit();
                continue;

#elif defined __x86_64__

            case OP_CALL2_0:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL2_0:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CALL2_0:
                myabort("Unsupported architecture");

#endif
