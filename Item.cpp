#include "Item.h"
#include <iostream>
#include <string>

Item::Item(const std::string &name, int quantity, double price)
    : name(name), quantity(quantity), price(price)
{
}