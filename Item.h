#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
    Item(const std::string &name, int quantity, double price);

    void print() const;
    void setQuantity(int amount);
    int getQuantity() const;
    double getPrice() const;
    std::string getName() const;

private:
    std::string name;
    int quantity;
    double price;
};

#endif