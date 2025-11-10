# C/C++ Modules in Python Projects

## Compiling & Building

### Compiling a Multi-File C++ Project

To compile and link multiple source files into one executable:

```bash
# This command compiles both main.cpp and commands.cpp and links them into a single executable named 'mygame'
g++ main.cpp commands.cpp -o mygame
```

### Compiling for Python (Shared Library)

**C++:** Wrap exports in `extern "C" { }` to disable name mangling. 
```bash
g++ -shared -fPIC -o module.so module.cpp
```

**C:** 
```bash
gcc -shared -fPIC -o module.so module.c
```

## C++ Patterns

### Command Processor with `std::map`

A scalable way to handle commands using a map of function pointers.

```cpp
// 1. Define a function pointer type for your command handlers.
using CommandHandler = void (*)(Player&, std::stringstream&);

// 2. Create the map, associating command strings with function pointers.
static const std::map<std::string, CommandHandler> command_map = {
    { "info", &handle_info },
    { "add",  &handle_add  },
};

// 3. Find and call the function from the map.
std::string command; // e.g., "info"
std::stringstream args; // arguments for the command

auto it = command_map.find(command);
if (it != command_map.end()) {
    it->second(player, args); // Calls the associated function (e.g., handle_info)
}
```

## Python Calling C/C++

**Create Python wrappers:** 
```python
import ctypes
_lib = ctypes.CDLL('./module.so')
def func(a, b):
    return _lib.func(a, b)
```

**Import normally:** `import my_module; my_module.func(5, 3)`.

**Note:** Always use `.so` on Linux/Mac, `.dll` on Windows. The shared library name doesn't have to match the Python module name.

## C++ Calling C
C code compiles as-is in C++ (C is mostly a subset). If linking pre-compiled C libraries, declare them: `extern "C" { int c_function(int a); }` then call normally: `c_function(5)`.

## C Calling C++
Write C++ functions with `extern "C"` wrapper (only C-compatible functions in interface, but use full C++ internally). Compile to object file: `g++ -c cpp_module.cpp`. Link from C: `gcc main.c cpp_module.o -o main`. C can only call C-compatible C++ functions, not classes or templates directly.

## Pointers vs. References

Think of a **pointer** as the *address* of a variable. It's a separate variable that holds the memory location of another variable.

Think of a **reference** as an *alias* or a *nickname* for a variable. It's not a separate variable; it's just another name for an existing variable.

Here's a table to summarize the main differences:

| Feature | Pointer (`*`) | Reference (`&`) |
| :--- | :--- | :--- |
| **Can be null?** | Yes, a pointer can be a `nullptr`, meaning it doesn't point to anything. | No, a reference must always refer to a valid variable. |
| **Can be reassigned?**| Yes, you can change a pointer to point to a different variable. | No, once a reference is initialized, it cannot be changed to refer to another variable. |
| **How to use?** | You need to "dereference" it with a `*` to get the value. | You use it just like a regular variable. |
| **Initialization** | Can be declared without being initialized. | Must be initialized when it is declared. |

### Code Example

Let's look at a code example to make this clearer:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string original = "I am the original";

    // Pointer
    std::string* pointer = &original; // pointer holds the address of original
    std::cout << "Pointer says: " << *pointer << std::endl; // Use * to get the value

    // Reference
    std::string& reference = original; // reference is an alias for original
    std::cout << "Reference says: " << reference << std::endl;

    // Reassigning the pointer
    std::string another = "I am another string";
    pointer = &another; // This is allowed
    std::cout << "Pointer now says: " << *pointer << std::endl;

    // Trying to reassign the reference (this will change the original variable!)
    reference = another; // This does NOT make the reference refer to 'another'.
                         // It assigns the value of 'another' to 'original'.
    std::cout << "Original is now: " << original << std::endl;


    return 0;
}
```

### When to Use Which?

*   **Use references (`&`) when:**
    *   You want to pass a large object to a function without copying it (for efficiency). This is the most common use case, especially with `const` to prevent modification.
    *   You want to create an alias for a variable to make your code more readable.

*   **Use pointers (`*`) when:**
    *   You need to work with memory addresses directly.
    *   You need a variable that can optionally hold "nothing" (a `nullptr`).
    *   You need to create complex data structures like linked lists or trees.
