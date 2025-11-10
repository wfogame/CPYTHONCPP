#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player {
public:
    // Constructor
    Player(const string& name) : name(name), health(100) {
        // Initialize inventory with a fixed size (e.g., 20 slots)
        inventory.reserve(20);
    }

    // Function to add an item to the inventory
    void addItem(const string& item) {
        if (inventory.size() < 20) {
            inventory.push_back(item);
            cout << item << " added to inventory." << endl;
        } else {
            cout << "Inventory is full." << endl;
        }
    }

    // Function to display player's information in a bordered window.
    void displayInfo() {
        // This function is a two-pass process.
        // 1. First Pass: We gather all the content and calculate the width of the box.
        // 2. Second Pass: We clear the screen and draw the box and its content.

        // -- STEP 1: GATHER CONTENT AND CALCULATE DIMENSIONS --

        vector<string> content;
        size_t maxWidth = 0;

        // Add player stats to the content list
        content.push_back("Name: " + name);
        content.push_back("Health: " + to_string(health));

        // Add a separator
        content.push_back("----------");
        content.push_back("Inventory:");

        // Add inventory items to the content list
        if (inventory.empty()) {
            content.push_back("(empty)");
        } else {
            for (const string& item : inventory) {
                content.push_back("- " + item);
            }
        }

        // Calculate the maximum width needed for the box
        for (const string& line : content) {
            if (line.length() > maxWidth) {
                maxWidth = line.length();
            }
        }

        // -- STEP 2: DRAW THE BOX AND ITS CONTENT --

        // Clear the screen and move cursor to top-left (ANSI escape codes)
        cout << "\033[2J\033[1;1H";

        // Draw the top border
        cout << "┌";
        for (size_t i = 0; i < maxWidth + 2; ++i) { // +2 for padding
            cout << "─";
        }
        cout << "┐" << endl;

        // Draw the content inside the box
        for (const string& line : content) {
            cout << "│ " << line;
            // Add padding spaces to make all lines the same width
            size_t padding = maxWidth - line.length();
            for (size_t i = 0; i < padding; ++i) {
                cout << " ";
            }
            cout << " │" << endl;
        }

        // Draw the bottom border
        cout << "└";
        for (size_t i = 0; i < maxWidth + 2; ++i) { // +2 for padding
            cout << "─";
        }
        cout << "┘" << endl;
    }

private:
    string name;
    int health;
    vector<string> inventory;
};

#endif // PLAYER_H
