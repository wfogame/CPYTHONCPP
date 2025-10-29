#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Player {
public:
    // Constructor
    Player(const std::string& name) : name(name), health(100) {
        // Initialize inventory with a fixed size (e.g., 20 slots)
        inventory.reserve(20);
    }

    // Function to add an item to the inventory
    void addItem(const std::string& item) {
        if (inventory.size() < 20) {
            inventory.push_back(item);
            std::cout << item << " added to inventory." << std::endl;
        } else {
            std::cout << "Inventory is full." << std::endl;
        }
    }

    // Function to display player's information
    void displayInfo() {
        std::cout << "Player: " << name << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Inventory:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item << std::endl;
        }
    }

private:
    std::string name;
    int health;
    std::vector<std::string> inventory;
};

#endif // PLAYER_H