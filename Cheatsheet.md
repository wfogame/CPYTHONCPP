# C/C++ Modules in Python Projects

## Python Calling C/C++
**Compile to shared libraries.** C++: wrap exports in `extern "C" { }` to disable name mangling. Compile: `g++ -shared -fPIC -o module.so module.cpp`. C: compile with `gcc -shared -fPIC -o module.so module.c`. 

**Create Python wrappers:** `import ctypes; _lib = ctypes.CDLL('./module.so'); def func(a, b): return _lib.func(a, b)`. 

**Import normally:** `import my_module; my_module.func(5, 3)`.

**Note:** Always use `.so` on Linux/Mac, `.dll` on Windows. The shared library name doesn't have to match the Python module name.

## C++ Calling C
C code compiles as-is in C++ (C is mostly a subset). If linking pre-compiled C libraries, declare them: `extern "C" { int c_function(int a); }` then call normally: `c_function(5)`.

## C Calling C++
Write C++ functions with `extern "C"` wrapper (only C-compatible functions in interface, but use full C++ internally). Compile to object file: `g++ -c cpp_module.cpp`. Link from C: `gcc main.c cpp_module.o -o main`. C can only call C-compatible C++ functions, not classes or templates directly.
