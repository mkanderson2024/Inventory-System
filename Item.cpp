#include "Item.h"
#include <iostream>
#include <string>

Item::Item(const std::string &name, int quantity, double price)
    : name(name), quantity(quantity), price(price)
{
}

// Print function to print the inventory
void Item::print() const
{
    std::cout << name
              << " | Quantity: " << quantity
              << " |Price: $" << price << '\n';
}

// Set the item amount
void Item::setQuantity(int amount)
{
    this->quantity = amount;
}

// Get the quantity of the item
int Item::getQuantity() const
{
    return quantity;
}

// Get the price of the item
double Item::getPrice() const
{
    return price;
}

// Get the item's name
std::string Item::getName() const
{
    return name;
}