#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <memory>
#include <chrono>
#include <thread>
#include <limits>
#include "Item.h"
#include "Inventory.h"

int main()
{
    Inventory inv;

    bool usingProgram = true;
    int input = 0;
    std::cout << "Welcome to your inventory program. Please Wait....\n\n";

    while (usingProgram)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "||     Main Menu     ||\n"
                  << "1] Add an item \n"
                  << "2] Remove an item\n"
                  << "3] View Inventory\n"
                  << "4] Exit Program\n"
                  << "\n";

        std::cout << "What would you like to do? ";
        std::cin >> input;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Add an Item
        if (input == 1)
        {

            while (true)
            {
                std::cout << "\nAdd an item selected\n";
                // Input variable for adding items loop
                char reply = ' ';

                // Input Variables for Item
                std::string name = "";
                int amount = 0;
                double price = 0.00;

                // Input collection
                std::cout << "Enter Item name ";
                std::cin >> name;
                std::cout << "\nEnter amount ";
                std::cin >> amount;
                std::cout << "\nEnter price ";
                std::cin >> price;

                inv.addItem(Item(name, amount, price));
                std::cout << "\nItem added. \n";
                std::cout << "Add another item (Y/N)? ";
                std::cin >> reply;

                if (reply == 'N')
                {
                    break;
                }
            }
        }
        // End Add an Item

        // Remove an Item
        else if (input == 2)
        {
            std::cout << "";
        }
        // End add an Item

        // View Inventory
        else if (input == 3)
        {
            std::cout << "View Inventory Selected.\n";

            inv.viewInventory();
        }
        // End View Inventory

        // Leave Program
        else if (input == 4)
        {
            std::cout << "Leave Progam Selected.\n"
                      << "Thank you for using the program.\n";
            usingProgram = false;
        }
        // End leave program

        // Handle incorrect input
        else
        {
            std::cout << "\nNo valid input for menu. Please select a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Handle incorrect input

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nReturning to Main Menu....\n\n";
    }
}