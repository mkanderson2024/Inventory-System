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
#include <cctype>

int main()
{
    Inventory inv;

    inv.loadFromFile("inventory.csv");

    bool usingProgram = true;
    int input = 0;
    std::cout << "\nWelcome to your inventory program. Please Wait....\n\n";

    while (usingProgram)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "||     Main Menu     ||\n\n"
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
            std::cout << "<<Add an item selected>>\n";
            while (true)
            {
                // Input variable for adding items loop
                char reply = ' ';

                // Input Variables for Item
                std::string name = "";
                int amount = 0;
                double price = 0.00;

                // Input collection
                std::cout << "\nEnter Item name: ";
                std::cin >> name;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter price: $";
                std::cin >> price;

                // Adds item to inventory class
                inv.addItem(Item(name, amount, price));

                // Continue option
                std::cout << "Add another item (Y/N)? ";
                std::cin >> reply;
                reply = std::tolower(reply);

                if (reply == 'n')
                {
                    break;
                }
            }
        }
        // End Add an Item

        // Remove an Item
        else if (input == 2)
        {
            std::cout << "<<Remove Item Selected>>\n\n";
            while (true)
            {
                int reply = -1;
                char answer = ' ';

                inv.viewInventory();

                std::cout << "\nEnter Index Number to remove Item.\n";
                std::cout << "Item to remove: ";
                std::cin >> reply;
                reply = reply - 1;

                inv.removeItem(reply);

                std::cout << "Remove more items (Y/N)? ";
                std::cin >> answer;
                answer = std::tolower(answer);

                if (answer == 'n')
                {
                    break;
                }
            }
        }
        // End add an Item

        // View Inventory
        else if (input == 3)
        {
            while (true)
            {
                char answer = ' ';

                std::cout << "<<View Inventory Selected>>\n\n";
                inv.viewInventory();

                std::cout << "\nSelect any key to return to Main Menu ";
                std::cin >> answer;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        // End View Inventory

        // Leave Program
        else if (input == 4)
        {
            std::cout << "<<Leave Progam Selected>>\n"
                      << "Thank you for using the program.\n";
            usingProgram = false;

            inv.saveToFile("inventory.csv");
            continue;
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