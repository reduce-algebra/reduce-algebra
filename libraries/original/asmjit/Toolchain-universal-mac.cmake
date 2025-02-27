# the name of the target operating system
SET(CMAKE_SYSTEM_NAME MacUniversal)

# which compilers to use for C and C++
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_C_FLAGS "-arch x86_64 -arch arm64")
SET(CMAKE_CXX_FLAGS "-arch x86_64 -arch arm64")

