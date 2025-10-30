// INSTRUCTIONS FOR THE USER (Ayden):
//
// Your goal is to fill in the logic for this file. I have laid out the structure for you.
// Follow the comments step-by-step. This will teach you how to use a std::map
// with function pointers to create a clean and scalable command processor.
//
// WHAT YOU NEED:
// 1. Includes: You need to include the headers for the tools you'll be using.
// 2. Command Handlers: You need to write the small functions that perform the action for each command.
// 3. The Command Map: You need to create the map and add your command functions to it.
// 4. The Lookup Logic: You need to find the command in the map and call the function.

// STEP 1: Include the necessary headers.
// We need iostream for cout, sstream for stringstream, map for std::map,
// and player.h to use the Player class.
#include "commands.h"
#include <iostream>
#include <sstream>
#include <map>
#include "player.h"
using namespace std;

// A function pointer type. This is the C++ syntax for a variable that "points" to a function.
// This specific type points to a function that returns void and takes a Player& and a stringstream&.
// void (*)(Player&, std::stringstream&);


// STEP 2: Implement the functions for each command.
// These are the functions that will do the actual work.

void handle_info(Player& player, stringstream& args) {
    // TODO: Call the player's displayInfo() method.
  player.displayInfo();

}

void handle_add(Player& player, stringstream& args) {
    // TODO:
    // 1. Create a string variable to hold the item.
    // 2. Extract the next word from the 'args' stringstream into your item variable (e.g., args >> item;).
    // 3. Check if the item string is not empty.
    // 4. If it's not empty, call player.addItem(item).
    // 5. If it is empty, print a usage message like "Usage: add <item>".
    string item;
    args >> item;
    if(!item.empty()){
      player.addItem(item);
    }else{
      cout << "Usage: add <item>" << endl;
    }
    
}

void handle_help(Player& player, stringstream& args) {
    // TODO: Print the list of available commands, just like you had in the old if/else if chain.
    cout << "Commands:" << endl;
    cout << "  info - display player information" << endl;
    cout << "  add <item> - add an item to your inventory" << endl;
    cout << "  help - display this help message" << endl;
    cout << "  exit - exit the game" << endl;
}


// This is the main function that gets called by main.cpp
void process_command(const string& input, Player& player) {

    // Create a stringstream from the user's input to easily extract words.
    stringstream ss(input);
    string command;
    ss >> command; // Extract the first word as the command.
    // STEP 3: Create the command map.
    // We declare it as 'static' so that it is only created ONCE, the very first time
    // this function is called. On all future calls, the map will already exist.
    // The map's key is a std::string (the command) and its value is our function pointer type.
    static const map<string, void(*)(Player&, stringstream&)> command_map = {
        // TODO: Fill the map with your commands.
        // The format is { "command_name", &function_name },
        // For example:
        // { "info", &handle_info },
        // Add entries for "add" and "help".
      { "add",&handle_add},
      {"info",&handle_info },
      {"help",&handle_help}
    };

    // STEP 4: Find and execute the command.
    auto it = command_map.find(command);

    if (it != command_map.end()) {
        // If we found the command in the map, call the associated function pointer.
        // it->second is the function pointer (e.g., &handle_info)
        it->second(player, ss);
    } else {
        // If the command was not in the map, print an error.
        cout << "Unknown command: " << command << endl;
    }
}
