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
        if (items[index].getQuantity() > 1)
        {
            removeAmount(index);
        }
        else
        {
            items.erase(items.begin() + index);
        }
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
        std::cout << i + 1 << "] ";
        items[i].print();
    }
}

void Inventory::removeAmount(int index)
{
    int remove = 0;
    int currentQauntity = items[index].getQuantity();
    int newQuantity = 0;

    std::cout << "Current quantity: " << currentQauntity << "\n";
    std::cout << "Amount to remove: ";
    std::cin >> remove;

    newQuantity = currentQauntity - remove;
    items[index].setQuantity(newQuantity);
}