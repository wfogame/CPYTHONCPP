#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

// Best practice: Avoid 'using namespace std;' in header files.
// Instead, qualify types with 'std::'

class Player {
public:
    // Constructor
    Player(const std::string& name);

    // Public Methods
    void addItem(const std::string& item);
    void displayInfo() const; // Marked as const because it doesn't modify the player object

    // Getters
    std::string getName() const;
    int getHealth() const;
    std::vector<std::string> getInventory() const;

private:
    std::string name;
    int health;
    std::vector<std::string> inventory;
    static const int MAX_INVENTORY_SIZE = 20; // Use a constant for max size
};

#endif // PLAYER_H
