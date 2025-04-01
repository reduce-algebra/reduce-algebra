// lose.cpp

#if defined BYTECODE
            case OP_LOSE:
                stack--;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOSE:
                sub2(spreg, 8);
                break;

#else
            case OP_LOSE:
                unfinished("Unsupported architecture");

#endif

// end of lose.cpp
