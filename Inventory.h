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

private:
    std::vector<Item> items;
};

#endif