// This is basically the "minimal example" that asmjit offers - save that
// I am adjusting it to cope with either x86_64 or aarch64. Well I am making
// other adjustments to cope with my file-layout and I have wrapped some
// comment lines so that they fit across 80-column windows a bit better.
// The license for this code will be as for the res of asmjit and the
// full details can be found in $reduce/libraries/asmjit where that they
// say is:

// Copyright (c) 2008-2024 The AsmJit Authors
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
// 


#include "asmjit/asmjit.h"
#ifdef __aarch64__
#include "asmjit/a64.h"
#endif // __aarch64__
#include <cstdio>


using namespace asmjit;

// Signature of the generated function.
typedef int (*Func)(void);

int main(int argc, char* argv[]) {
  // Runtime designed for JIT - it holds relocated functions and
  // controls their lifetime.
  JitRuntime rt;

  // Holds code and relocation information during code generation.
  CodeHolder code;

  // Code holder must be initialized before it can be used.
  // The simples way to initialize it is to use 'Environment' from
  // JIT runtime, which matches the target architecture,
  // operating system, ABI, and other important properties.
  code.init(rt.environment(), rt.cpuFeatures());

  // Emitters can emit code to CodeHolder - depending on the host let's
  // create 'x86::Assembler' or aarch64::Assemblet , which can emit
  // relevant code. The following lines also attaches the
  // assembler to CodeHolder, which calls 'code.attach(&a)' implicitly.

#ifdef __x86_64__
  x86::Assembler a(&code);

  // Use the x86::Assembler to emit some code to .text section in CodeHolder:
  a.mov(x86::eax, 33);  // Emits 'mov eax, 33' - moves 33 to 'eax' register.
  a.ret();              // Emits 'ret'        - returns from a function.
#elif defined __aarch64__
// Now for 64-bit ARM.
  a64::Assembler a(&code);
  a.mov(a64::x0, 33);   // Emits 'mov x0, #33'- moves 33 to result register.
  a.ret(a64::x30);      // Emits 'ret'        - returns from a function.
#else
#error At present only x86_64 and aarch64 are supported here.
#endif

  // 'Assembler' is no longer needed from here and can be destroyed or
  // explicitly detached via 'code.detach(&a)' - which detaches an
  // attached emitter from code holder.

  // Now add the generated code to JitRuntime via JitRuntime::add().
  // This function would copy the code from CodeHolder into memory with
  // executable permission and relocate it.
  Func fn;
  Error err = rt.add(&fn, &code);

  // It's always a good idea to handle errors, especially those returned
  // from the Runtime.
  if (err) {
    printf("AsmJit failed: %s\n", DebugUtils::errorAsString(err));
    return 1;
  }

  // CodeHolder is no longer needed from here and can be safely destroyed.
  // The runtime now holds the relocated function, which we have generated,
  // and controls its lifetime. The function will be freed with the runtime,
  // so it's necessary to keep the runtime around.
  //
  // You can use 'code.reset()' to free CodeHolder's content when necessary.

  // Execute the generated function and print the resulting value, which
  // it moves to the result register.
  int result = fn();
  printf("%d\n", result);

  // All classes use RAII, all resources will be released before `main()`
  // returns, the generated function can be, however, released explicitly
  // if you intend to reuse or keep the runtime alive, which you should
  // in a production-ready code.
  rt.release(fn);

  return 0;
}

// end of jitdemo.cpp
