#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
public:
    void addItem(const Item &item);
    void removeItem(int index);
    void viewInventory() const;
    void removeAmount(int index);
    double calculateValue();

private:
    std::vector<Item> items;
};

#endif