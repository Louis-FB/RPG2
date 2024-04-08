#include <iostream>
#include <string>
#include <limits>


std::string getName();
void ignoreLine();

void welcome() {
    std::cout << "   _____             _____  _____   _____   ___  \n  / ____|_     _    |  __ \\|  __ \\ / ____| |__ \\ \n | |   _| |_ _| |_  | |__) | |__) | |  __     ) |\n | |  |_   _|_   _| |  _  /|  ___/| | |_ |   / / \n | |____|_|   |_|   | | \\ \\| |    | |__| |  / /_ \n  \\_____|           |_|  \\_\\_|     \\_____| |____|\n";
}

bool play();

int main()
{
    welcome();
    std::string name{ getName() };
    std::cout << "Welcome to C++ RPG 2, " << name;
}

bool play() {

}

void ignoreLine() { // Used to clear extra input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getName() { // Get name of user
    std::cout << "What is your name, adventurer? ";

    while (true) {
        
        std::string name{};
        std::getline(std::cin, name);

        if (!std::cin || name.empty()) {
            std::cout << "Try again\n";
            std::cin.clear();
            continue;
        }

        return name;
    }
}