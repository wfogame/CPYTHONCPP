# Project: C++/Python Command-Line Story Game

## Goal
To learn C++ by building a narrative-driven command-line game with a focus on creating a visually rich terminal user interface for the inventory and player status screens.

## Core Technical Task
Refactor the `player.displayInfo()` method to draw a bordered window inside the terminal using ANSI escape codes and Unicode box-drawing characters.

## How the Program Fits Together

1.  `main.cpp` is the **starting point**. It contains the `main` function and the main game loop.
2.  The game loop waits for user input using `getline`.
3.  The input is passed to the `process_command` function, which is declared in `commands.h`.
4.  `commands.cpp` contains the implementation for `process_command`, including the `command_map` that associates command strings with the functions that handle them.
5.  The `info` command will now trigger the new, graphical `displayInfo` method from the `Player` class.

## File-by-File Breakdown

### Core Game Code
*   `main.cpp`: **Entrypoint & Game Loop.**
*   `player.h`: **Player Blueprint.** Declares the `Player` class. We will be heavily modifying the `displayInfo` method here.
*   `commands.h`: **Commands Blueprint.** Declares the command processing system.
*   `commands.cpp`: **Commands Logic.** Implements the logic for each command.

### Learning & Documentation
*   `GEMINI.md`: (This file) A quick summary of the project structure.
*   `Outline.md`: **Detailed Notebook.** Contains our deep-dive explanations of C++ topics.
*   `Cheatsheet.md`: **Quick Reference.** For C++ syntax and build commands.
