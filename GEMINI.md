# Project: C++/Python Terminal Game

## Goal
To learn C++ and AI concepts by building a terminal-based game.

## How the Program Fits Together

1.  `main.cpp` is the **starting point**. It contains the `main` function which runs the game loop.
2.  Inside the loop, it gets input from the user and passes it to the `process_command` function.
3.  To know about `process_command`, `main.cpp` includes the "blueprint" file, `commands.h`.
4.  `commands.cpp` contains the actual code for `process_command` and all the helper functions for individual commands (like `handle_info`, `handle_add`).
5.  The command functions use the `Player` object to do things. They know about the `Player` object because they include the `player.h` blueprint.

## File-by-File Breakdown

### Core Game Code
*   `main.cpp`: **Entrypoint & Game Loop.** Starts the game and runs the main loop.
*   `player.h`: **Player Blueprint.** Declares the `Player` class (defines what a Player is).
*   `commands.h`: **Commands Blueprint.** Declares the command processing system for the rest of the app.
*   `commands.cpp`: **Commands Logic.** Implements the logic for every chat command.

### Learning & Documentation
*   `GEMINI.md`: (This file) A quick summary of the project structure.
*   `Outline.md`: **Detailed Notebook.** Contains our deep-dive explanations of C++ topics.
*   `Cheatsheet.md`: **Quick Reference.** For C++ syntax and build commands.
*   `AI_Concepts.md`: **AI Theory.** An essay on Neural Networks and Gradient Descent.
*   `session_summary_...md`: **Session Logs.** A summary of what we do in each session.

### Compiled Output
*   `a.out`: The final, runnable game executable, created by linking `main.o` and `commands.o`.