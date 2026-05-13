#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const Item &item)
{
    items.push_back(item);
}

void Inventory::removeItem(int index)
{
    if (index >= 0 && index < items.size())
    {
        items.erase(items.begin() + index);
    }

    else
    {
        std::cout << "\nInvalid item selection\n";
    }
}

void Inventory::viewInventory() const
{
    if (items.empty())
    {
        std::cout << "\nInventory is currently empty.\n";
        return;
    }

    for (int i = 0; i < items.size(); i++)
    {
        std::cout << i << "] ";
        items[i].print();
    }
}