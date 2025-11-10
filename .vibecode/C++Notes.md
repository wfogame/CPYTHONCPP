g++ main.cpp -fPIC -I/usr/include/qt -I/usr/include/qt/QtWidgets -lQt5Widgets -lQt5Gui -lQt5Core
To Compile succesfully to run.

Classes
Basic class structure - Variables, constructors, methods
Public/Private/Protected - Access control
Inheritance - Classes inheriting from other classes
Multiple constructors - Overloading
Destructors - Cleanup code
Const functions - Read-only methods
Static members - Shared across all objects
Getters/Setters - Safe access to private data
Operator overloading - Using +, ==, etc. on custom objects
Vectors/Arrays of objects - Storing multiple objects
Copy constructor - What happens when you copy an object
Friend functions - Exceptions to private access
Polymorphism/Virtual - Same function, different behavior

- **`std::vector<T>`** - dynamic array
- **`std::string`** - text/strings
- **`std::map<K, V>`** - sorted key-value pairs (dictionary)
- **`std::unordered_map<K, V>`** - hash table (faster dictionary)
- **`std::set<T>`** - sorted unique values
- **`std::unordered_set<T>`** - hash set (faster unique values)
- **`std::unique_ptr<T>`** - smart pointer (single ownership)
- **`std::shared_ptr<T>`** - smart pointer (shared ownership)
<T>  means type for example std::vector<int>
<K> means strings <V> means int or value
