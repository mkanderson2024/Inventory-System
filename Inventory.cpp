#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

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
            std::cout << "\nItem removed\n\n";
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

    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout << i + 1 << "] ";
        items[i].print();
    }
    double totalValue = calculateValue();
    std::cout << "\nTotal inventory value: $" << totalValue << "\n";
}

void Inventory::removeAmount(int index)
{
    int remove = 0;
    while (remove == 0)
    {
        std::string name = items[index].getName();
        int currentQauntity = items[index].getQuantity();
        int newQuantity = 0;

        std::cout << "\nCurrent quantity of " << name << "\n: " << currentQauntity << "\n";
        std::cout << "Amount to remove: ";
        std::cin >> remove;

        if (remove > 0 && remove <= currentQauntity)
        {
            newQuantity = currentQauntity - remove;
            if (newQuantity == 0)
            {
                items.erase(items.begin() + index);
                std::cout << "\n"
                          << remove << " removed\n\n";
                break;
            }
            else
            {
                items[index].setQuantity(newQuantity);
                std::cout << "\n"
                          << remove << " removed\n\n";
            }
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

double Inventory::calculateValue() const
{
    double totalValue = 0;

    for (const auto &item : items)
    {
        totalValue += item.getQuantity() * item.getPrice();
    }

    return totalValue;
}

void Inventory::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Failed to open file for saving.\n";
        return;
    }

    for (const Item &item : items)
    {
        file << item.getName() << ","
             << item.getQuantity() << ","
             << item.getPrice() << "\n";
    }

    file.close();
}

void Inventory::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        std::cout << "No save file found. Booting with no file selected.\n";
    return;

    items.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string name;
        std::string quantityString;
        std::string priceString;

        std::getline(ss, name, ',');
        std::getline(ss, quantityString, ',');
        std::getline(ss, priceString, ',');

        Item item(
            name,
            std::stoi(quantityString),
            std::stod(priceString));

        items.push_back(item);
    }
    file.close();
}