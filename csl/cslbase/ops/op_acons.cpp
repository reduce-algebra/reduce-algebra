// $Id$

#if defined BYTECODE
            case OP_ACONS:                  // A_reg = acons(p, B_reg, A_reg);
                // = (p . B) . A
                r1 = *stack--;
                A_reg = acons(r1, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_ACONS:
                loadstatic(w1, OJITacons);
                loadreg_post(w2, spreg, -8);
                JITcall(JITshim3, A_reg,
                        w1, w2, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_ACONS:                  // A_reg = acons(p, B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_acons.cpp
