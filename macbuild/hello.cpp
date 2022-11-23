// This file is provided so that the build scripts try
//   g++ hello.cpp -arch x86_64 -arch arm64 -o hello
// as a way of testing if universal builds are supported on this
// Macintosh. If they are then the environment must have been set
// up with universal versions of all the various libraries etc that
// building CSL and Reduce depends on. On an older confihuration the
// compilation of this with the flags shown above will fail.

#include <iostream>

int main()
{
    std::cout << "Hello\n";
}

// end of hello.cpp
