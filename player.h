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

    // Function to display player's information
    void displayInfo() {
        cout << "Player Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Inventory: ";
        if (inventory.empty()) {
            cout << "Empty" << endl;
        } else {
            for (const auto& item : inventory) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

private:
    string name;
    int health;
    vector<string> inventory;
};

#endif // PLAYER_H
