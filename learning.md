# C++ Concepts for a Scalable Command Architecture

This document explains the C++ concepts we'll use to change (refactor) our command processor. The goal is to make it more **scalable** (able to grow easily) and **maintainable** (easy to fix and update). We'll do this using a common recipe called the **Command Design Pattern**.

## 1. The Command Design Pattern

**What is it?** Think of it like ordering food at a restaurant.

*   **You** give a request ("I want a burger").
*   The **waiter** doesn't cook it. They write your request down on an **order ticket**.
*   That **order ticket** is the **Command Object**. It's a self-contained package that has all the information about your request.

In our game, when you type `add sword`, we're not going to handle it immediately. Instead, we're going to package that request up into an `AddCommand` object, just like writing it on an order ticket. This makes the request a "thing" that we can pass around and manage easily.

**How we use it:**
- We will create a blueprint, called an **interface** (or an **abstract base class**), that says "every command in our game must have an `execute` function."
- For each command (like "info", "add"), we will create a specific class that follows this blueprint.
- Our `process_command` function will no longer know the details of each command. It will only know how to take a command object and call its `execute` function.
- This separates the part of the code that receives the command (the **invoker**, our `process_command` function) from the object that the command acts upon (the **receiver**, our `Player` object). The invoker doesn't need to know the details, it just says "do it!".

**Benefits:**
- **Scalability:** Adding a new command just means creating a new command class. You don't have to modify the central `process_command` function.
- **Flexibility:** This pattern makes it much easier to add advanced features later, like a history of commands or an undo/redo system.

## 2. Polymorphism and Virtual Functions

**What is it?** **Polymorphism** (a fancy word for "many forms") is a C++ feature that lets us treat different objects in the same way, as long as they share a common blueprint (a **base class**). We do this using a special keyword: `virtual`.

**How we use it:**
- The `execute()` function in our `Command` blueprint will be declared as a **`virtual` function**. A virtual function is like a button on the blueprint that can have a different action for each final object.
- Our command map will store pointers to the `Command` blueprint type.
- When we call `command->execute()`, C++ figures out *while the program is running* (**at runtime**) which specific version of `execute()` to use (`InfoCommand`'s version or `AddCommand`'s version).
- This is powerful because our main loop doesn't have to know the details of any specific command; it just deals with the general `Command` blueprint.

## 3. Abstract Base Classes (ABCs)

**What is it?** An **Abstract Base Class** (or ABC) is a special kind of class that is meant only to be a blueprint. You cannot create an object directly from an ABC; you can only create objects from classes that *inherit* from it. A class becomes an ABC if it has at least one "**pure virtual function**" (a function that is declared but has no code inside the ABC).

**How we use it:**
- Our `Command` class is an ABC because of this line:
  ```cpp
  virtual void execute(...) = 0;
  ```
- The `= 0` at the end of the function declaration is what makes it a "pure virtual function". It's our way of saying, "This function *must* be implemented by any class that uses this blueprint." This is like a contract that guarantees all our command objects will know how to `execute`.

## 4. Smart Pointers (`std::unique_ptr`)

**What is it?** In C++, when you create objects on the fly, you are responsible for deleting them later to free up memory. Forgetting to do this causes a "**memory leak**". **Smart pointers** are helper objects that act like pointers but automatically handle the deletion for you.

**How we use it:**
- We will use `std::unique_ptr`. This type of smart pointer ensures that there is only ever *one* owner for a piece of memory. When the `unique_ptr` is destroyed (for example, when it goes out of scope), it automatically deletes the object it points to.
- Our new command map will store `std::unique_ptr<Command>`.
- This means the `command_map` now *owns* all the command objects. When our program ends and the map is destroyed, all the `unique_ptr`s inside it will automatically clean up the command objects, preventing any memory leaks. This is much safer than managing memory manually.
