// $Id$

#if defined BYTECODE
            case OP_ONEVALUE:
// ONEVALUE is here to support a prsed re-write of the multiple values
// handling scheme.
                exit_count = 1;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_ONEVALUE:
// Do I really support multiple values? I think not so here I just leave
// this as a no-ration.
                break;

#else
            case OP_ONEVALUE:
                unfinished("Unsupported architecture");

#endif

// end of onevalue.cpp
