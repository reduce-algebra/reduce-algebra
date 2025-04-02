// icase.cpp $Id$

#if defined BYTECODE
            case OP_ICASE:
                w = next_byte;
                if (is_fixnum(A_reg) &&
                    (n = int_of_fixnum(A_reg)) >= 0 &&
                    n < static_cast<int>(w)) ppc += 2*n + 2;
                w = next_byte;
//
// I support backwards jumps here by setting their top bit. At present I do not
// poll for interrupts on a backwards case-branch. And the encoding used means
// that case branches can not reach quite as far as regular jumps.
//
                if (w & 0x80) ppc = ppc - (((w & 0x7f) << 8) +
                                               (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                else ppc = ppc + (w << 8) + (reinterpret_cast<unsigned char *>
                                                 (codevec))[ppc];
                continue;

#elif defined __x86_64__

            case OP_ICASE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_ICASE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_ICASE:
                unfinished("Unsupported architecture");

#endif

// end of op_icase.cpp
