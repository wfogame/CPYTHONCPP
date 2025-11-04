# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## High-Level Overview

This project is a command-line story game written in C++. The primary goal is to learn C++ by building a narrative-driven game with a focus on creating a visually rich terminal user interface for the inventory and player status screens.

## Code Architecture

The application is structured into three main parts:

*   **`main.cpp`**: This is the entry point of the program. It contains the main game loop, which reads user input and passes it to the command processor.
*   **`player.h`**: This file defines the `Player` class. It manages the player's name, health, and inventory. A key feature is the `displayInfo()` method, which will be developed to create a rich graphical interface in the terminal, potentially using a tool like Kitty's `icat` to display images instead of relying on simple ANSI escape codes.
*   **`commands.cpp` and `commands.h`**: These files implement a command processing system. It uses a `std::map` to associate command strings (e.g., "info", "add", "help") with function pointers to the corresponding command handlers. This creates a clean and scalable way to add new commands.

## Common Commands

### Building the Game

There appear to be two ways to build the project. The first was found in `C++Notes.md` and seems to be for a Qt application.

```bash
g++ main.cpp -fPIC -I/usr/include/qt -I/usr/include/qt/QtWidgets -lQt5Widgets -lQt5Gui -lQt5Core
```

However, a more standard command for this type of application would be:

```bash
g++ main.cpp commands.cpp -o mygame
```
- Neural networks with bias and weight will be implmented for the decision making mechanics.
