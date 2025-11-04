# Game Plan: AI Game Master

This document outlines the design for a simple, turn-based C++ terminal game focused on strategic, AI-driven boss fights.

## High-Level Vision

The game is a 1v1 duel between a human player and an AI-controlled boss. The core of the project is the **AI Game Master**, an entity that controls the boss's actions and learns as it plays. The entire game will be presented through a clean, text-based command-line interface.

## Core Components & File Structure

The project will be built with a clean separation of concerns.

*   **`main.cpp`**: The entry point of the application. It will contain the primary CLI loop where the player can start a new game, see instructions, or exit.
*   **`game.h` / `game.cpp`**: This will contain the main `Game` class. It will manage the game state, the turn-based loop, check for win/loss conditions, and coordinate between the player and the AI.
*   **`player.h` / `player.cpp`**: A simple class defining the `Player`. It will manage player health and their available actions (e.g., Attack, Defend, Heal).
*   **`boss.h` / `boss.cpp`**: A simple class defining the `Boss`. It will manage the boss's health and the actions it can perform, which are chosen by the AI.
*   **`ai_gamemaster.h` / `ai_gamemaster.cpp`**: The "brain" of the game. This class will implement a simple Reinforcement Learning model (Q-Table) to make decisions for the boss.

## Gameplay Loop & AI Learning

The game proceeds in turns, following a simple Reinforcement Learning loop:

1.  **Observe State:** The `AI_GameMaster` looks at the current situation (e.g., Player HP, Boss HP).
2.  **AI Action:** Based on the state, the AI uses its Q-Table to choose the best action for the Boss (e.g., "Heavy Attack," "Shield," "Lifesteal").
3.  **Player Action:** The player is shown what the boss is doing and is prompted to choose their own action from a list.
4.  **Resolve Turn:** The game logic determines the outcome of the two actions (damage dealt, health restored, etc.).
5.  **Calculate Reward:** A reward or punishment (a numerical score) is calculated based on the outcome.
    *   **Positive Reward:** The player took damage.
    *   **Negative Reward:** The boss took damage.
    *   **Huge Positive Reward:** The player is defeated (AI wins).
    *   **Huge Negative Reward:** The boss is defeated (AI loses).
6.  **AI Learns:** The reward is sent back to the `AI_GameMaster`, which updates its Q-Table. This makes the AI slightly smarter for the next time it's in a similar situation.
7.  The loop repeats until one character is defeated.
8.  When a new game starts, the AI's Q-Table is reset, so it learns from scratch against the player in each new session.
