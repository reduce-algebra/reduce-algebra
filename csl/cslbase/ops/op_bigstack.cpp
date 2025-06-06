// $Id$

#if defined BYTECODE
            case OP_BIGSTACK:               // LOADLOC, STORELOC, CLOSURE etc
                //
                // This code allows me to support functions that use up to
                // 2047-deep stack frames using LOADLEX and STORELEX, or
                // up to 4095 deep if just using LOADLOC and STORELOC. I hope
                // that such cases are very uncommon, but examples have been
                // shown to me where my previous limit of 256-item frames was
                // inadequate. The BIGSTACK opcode is followed by a byte that
                // contains a few bits selecting which operation is to be
                // performed, plus an extension to the address byte that follows.
                //
                w = next_byte;             // contains sub-opcode
                switch (w & 0xc0)
                {   case 0x00:                  // LOADLOC extended
                        B_reg = A_reg;
                        w = (w & 0x3f) << 8;
                        A_reg = stack[-static_cast<int>(w + next_byte)];
                        continue;
                    case 0x40:                  // STORELOC extended
                        w = (w & 0x3f) << 8;
                        stack[-static_cast<int>(w + next_byte)] = A_reg;
                        continue;
                    case 0x80:                  // CLOSURE extended
                        *++stack = B_reg; *++stack = A_reg;
                        w = ((w & 0x3f) << 8) + next_byte;
                        A_reg = encapsulate_sp(&stack[-2-static_cast<int>(w)]);
                        errexit();
                        B_reg = *stack--;
                        A_reg = list2star(cfunarg, B_reg, A_reg);
                        errexit();
                        B_reg = *stack--;
                        continue;
                    case 0xc0:                  // LOADLEX, STORELEX extended
                        n = next_byte;
                        k = next_byte;
                        n = (n << 4) | (k >> 4);
                        k = ((k & 0xf) << 8) | next_byte;
                        r1 = elt(stack[1-n], 0);
                        B_reg = A_reg;
                        n = w & 0x1f;
                        while (n != 0) r1 = (reinterpret_cast<LispObject *>(r1))[1], n--;
                        if ((w & 0x20) == 0) A_reg = (reinterpret_cast<LispObject *>(r1))[k];
                        else (reinterpret_cast<LispObject *>(r1))[k] = A_reg;
                        continue;
                }

#elif defined __x86_64__ || defined __aarch64__

            case OP_BIGSTACK:               // LOADLOC, STORELOC, CLOSURE etc

                next = bytes[ppc++];             // contains sub-opcode
                switch (next & 0xc0)
                {   case 0x00:                  // LOADLOC extended
                        mov(B_reg, A_reg);
                        next = ((next & 0x3f)<<8) | bytes[ppc++];
                        loadloc(A_reg, next);
                        break;
                    case 0x40:                  // STORELOC extended
                        next = ((next & 0x3f)<<8) | bytes[ppc++];
                        storeloc(A_reg, next);
                        break;
                    case 0x80:                  // CLOSURE extended
// I think that CLOSURE, LOADLEX and STORELEX would be feasible here,
// but they are not high on the priority list at present.
                        unfinished("CLOSURE not yet implemented in JIT");
                    case 0xc0:                  // LOADLEX, STORELEX extended
                        unfinished("LOADLEX/STORELEX not yet implemented in JIT");
                }
                break;

#else
            case OP_BIGSTACK:               // LOADLOC, STORELOC, CLOSURE etc
                unfinished("Unsupported architecture");

#endif

// end of op_bigstack.cpp
