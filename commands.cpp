#include "commands.h"
#include "player.h"
#include "ConcreteCommands.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <memory>

void process_command(const std::string& input, Player& player) {
    // The command map now stores smart pointers to our Command objects.
    static std::map<std::string, std::unique_ptr<Command>> command_map;

    // This is a simple way to initialize the map only once.
    if (command_map.empty()) {
        command_map["info"] = std::make_unique<InfoCommand>();
        command_map["add"] = std::make_unique<AddCommand>();
        command_map["help"] = std::make_unique<HelpCommand>();
    }

    // Parse the input string into a command and its arguments.
    std::stringstream ss(input);
    std::vector<std::string> args;
    std::string temp;
    while (ss >> temp) {
        args.push_back(temp);
    }

    if (args.empty()) {
        return; // Nothing was entered.
    }

    std::string command_name = args[0];
    auto it = command_map.find(command_name);

    if (it != command_map.end()) {
        // We found the command. it->second is the std::unique_ptr<Command>.
        // We call execute() on the object it points to.
        // C++ uses polymorphism to call the correct derived class's version.
        it->second->execute(player, args);
    } else {
        std::cout << "Unknown command: " << command_name << std::endl;
    }
}
