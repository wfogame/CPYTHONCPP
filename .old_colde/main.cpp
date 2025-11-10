#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "commands.h"

int main() {
    using namespace std;

    Player player("Ayden");

    cout << "Welcome to the AI-powered terminal game!" << endl;
    cout << "Type 'help' for a list of commands." << endl;

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        // All the old if/else logic is now replaced by this single call
        process_command(input, player);
    }

    return 0;
}