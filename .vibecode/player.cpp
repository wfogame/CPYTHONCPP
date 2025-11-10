#include "player.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor implementation
Player::Player(const std::string& name) : name(name), health(100) {
    inventory.reserve(MAX_INVENTORY_SIZE);
}

// Add item to inventory
void Player::addItem(const std::string& item) {
    if (inventory.size() < MAX_INVENTORY_SIZE) {
        inventory.push_back(item);
        std::cout << item << " added to inventory." << std::endl;
    } else {
        std::cout << "Inventory is full." << std::endl;
    }
}

// Display player information
void Player::displayInfo() const {
    // Step 1: Gather content and calculate dimensions
    std::vector<std::string> content;
    size_t maxWidth = 0;

    content.push_back("Name: " + name);
    content.push_back("Health: " + std::to_string(health));
    content.push_back("----------");
    content.push_back("Inventory:");

    if (inventory.empty()) {
        content.push_back("(empty)");
    } else {
        for (const auto& item : inventory) {
            content.push_back("- " + item);
        }
    }

    for (const auto& line : content) {
        if (line.length() > maxWidth) {
            maxWidth = line.length();
        }
    }

    // Step 2: Draw the box and its content
    std::cout << "\033[2J\033[1;1H"; // Clear screen

    // Top border
    std::cout << "┌";
    for (size_t i = 0; i < maxWidth + 2; ++i) std::cout << "─";
    std::cout << "┐" << std::endl;

    // Content
    for (const auto& line : content) {
        std::cout << "│ " << line;
        size_t padding = maxWidth - line.length();
        for (size_t i = 0; i < padding; ++i) std::cout << " ";
        std::cout << " │" << std::endl;
    }

    // Bottom border
    std::cout << "└";
    for (size_t i = 0; i < maxWidth + 2; ++i) std::cout << "─";
    std::cout << "┘" << std::endl;
}

// Getter implementations
std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

std::vector<std::string> Player::getInventory() const {
    return inventory;
}
