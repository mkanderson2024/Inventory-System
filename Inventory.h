#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
#include <string>

class Inventory
{
public:
    // Declared functions
    void addItem(const Item &item);
    void removeItem(int index);
    void viewInventory() const;
    void removeAmount(int index);
    double calculateValue() const;

    // For saving and loading
    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);

private:
    std::vector<Item> items;
};

#endif