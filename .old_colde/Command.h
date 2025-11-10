#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

// Forward declaration to tell Command.h that a Player class exists,
// without needing to include the full player.h file.
// This prevents circular dependencies.
class Player;

// This is our abstract base class, the "blueprint" for all commands.
class Command {
public:
    // A virtual destructor is important in a base class for proper cleanup.
    virtual ~Command() = default;

    // This is the pure virtual function that makes this class abstract.
    // It's the "contract" that all concrete commands must implement.
    // It takes a reference to the player to act upon, and the arguments
    // from the user's input.
    virtual void execute(Player& player, const std::vector<std::string>& args) = 0;
};

#endif // COMMAND_H
