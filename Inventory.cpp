#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const Item &item)
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == item.getName())
        {
            items[i].setQuantity(items[i].getQuantity() + item.getQuantity());
            std::cout << "\nItem added to exsisting inventory item.\n";
            return;
        }
    }
    items.push_back(item);
    std::cout << "\nItem added. \n";
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
            std::cout << "\nItem removed\n";
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
    while (remove == 0)
    {
        int currentQauntity = items[index].getQuantity();
        int newQuantity = 0;

        std::cout << "Current quantity: " << currentQauntity << "\n";
        std::cout << "Amount to remove: ";
        std::cin >> remove;

        if (remove > 0 && remove <= currentQauntity)
        {
            newQuantity = currentQauntity - remove;
            items[index].setQuantity(newQuantity);
            std::cout << newQuantity << " removed";
        }

        else
        {
            std::cout << "\nInvalid entry. Please input a positive number less than current inventory amount.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            remove = 0;
        }
    }
}

double Inventory::calculateValue()
{
    double totalValue = 0;

    for (const auto &item : items)
    {
        totalValue += item.getQuantity() * item.getPrice();
    }

    std::cout << "Total inventory value: $" << totalValue << "\n";
}