#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include "Command.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <string>

// Command to display player info.
// It inherits from the Command blueprint.
class InfoCommand : public Command {
public:
    // This is the implementation of the 'execute' contract.
    void execute(Player& player, const std::vector<std::string>& args) override {
        player.displayInfo();
    }
};

// Command to add an item to the inventory.
class AddCommand : public Command {
public:
    void execute(Player& player, const std::vector<std::string>& args) override {
        // args[0] is the command itself ("add"), so the item is at args[1].
        if (args.size() > 1) {
            player.addItem(args[1]);
        } else {
            std::cout << "Usage: add <item>" << std::endl;
        }
    }
};

// Command to display help.
class HelpCommand : public Command {
public:
    void execute(Player& player, const std::vector<std::string>& args) override {
        std::cout << "Commands:" << std::endl;
        std::cout << "  info - display player information" << std::endl;
        std::cout << "  add <item> - add an item to your inventory" << std::endl;
        std::cout << "  help - display this help message" << std::endl;
        std::cout << "  exit - exit the game" << std::endl;
    }
};

#endif // CONCRETE_COMMANDS_H
