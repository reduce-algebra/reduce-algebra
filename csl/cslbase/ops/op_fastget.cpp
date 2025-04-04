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

#elif defined __x86_64__ || defined __aarch64__

            case OP_FASTGET:
                {   next = bytes[ppc];
                    Label fastgetsymbol = newLabel();
                    Label fastgetend = newLabel();
                    Label fastgetnil = newLabel();
                    Label fastgetB = newLabel();
                    and3(w, A_reg, TAG_BITS);
                    cmp(w, TAG_SYMBOL);
                    je(fastgetsymbol);
                bind(fastgetnil);
                    mov(A_reg, nilreg);
                    jmp(fastgetend);
                bind(fastgetB);
                    mov(A_reg, B_reg);
                    jmp(fastgetend);
                bind(fastgetsymbol);
                    loadfromsymbol(w, A_reg, Ofastgets);
                    cmp(w, nilreg);
                    if (next & 0x40) je(fastgetB);
                    else je(fastgetnil);
                    loadreg(A_reg, w, 8*(next&0x3f)+CELL-TAG_VECTOR);
                    cmp(A_reg, SPID_NOPROP);
                    if (next & 0x40) je(fastgetB);
                    else je(fastgetnil);
                    if (next & 0x80) loadstatic(A_reg, Olisp_true);
                bind(fastgetend);
                }
                break;

#else
            case OP_FASTGET:
                unfinished("Unsupported architecture");

#endif

// end of op_fastget.cpp
