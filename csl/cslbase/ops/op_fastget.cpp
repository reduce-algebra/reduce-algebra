// fastget.cpp $Id$

#if defined BYTECODE
            case OP_FASTGET:
                w = next_byte;
#ifdef RECORD_GET
                n = 0;
#endif
                if (symbolp(A_reg))
                {   r1 = qfastgets(A_reg);
                    if (r1 == nil)
                    {   if (w & 0x40) A_reg = B_reg;
                        else A_reg = nil;
                    }
                    else
                    {   A_reg = basic_elt(r1, w & 0x3f);
                        if (A_reg == SPID_NOPROP)
                        {   if (w & 0x40) A_reg = B_reg;
                            else A_reg = nil;
#ifdef RECORD_GET
                            n = 1;
#endif
                        }
                        else if (w & 0x80) A_reg = lisp_true;
                    }
                }
                else A_reg = nil;
#ifdef RECORD_GET
                record_get(basic_elt(fastget_names, w & 0x7f), n);
#endif
                continue;

#elif defined __x86_64__

            case OP_FASTGET:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_FASTGET:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_FASTGET:
                unfinished("Unsupported architecture");

#endif

// end of op_fastget.cpp
