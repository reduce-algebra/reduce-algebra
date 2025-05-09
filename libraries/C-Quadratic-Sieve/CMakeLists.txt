# This file aids in integrating the project with various development tools.
# It's not strictly necessary for creating the final executable.

# The "gcc" compiler can be replaced by "clang", it has been tested.

# manual DEVELOPMENT    compilation use    "gcc -Wall -pedantic -O0 -std=c99 main.c -o factor"
# manual PRODUCTION     compilation use    "gcc -Wall -pedantic -O2 -std=c99 main.c -o factor"

cmake_minimum_required(VERSION 3.0.0)

project(factor C)
add_executable(factor main.c)
target_compile_options(factor PRIVATE -Wall -pedantic -g -O2 -std=c99)
