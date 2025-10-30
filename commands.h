#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

// Forward-declare the Player class so we don't have to include the full player.h here.
// This is a good practice to reduce dependencies between header files.
class Player;
using namespace std;
// This is the only function that main.cpp needs to know about.
// It takes the raw user input and a reference to the player.
void process_command(const string& input, Player& player);

#endif // COMMANDS_H
