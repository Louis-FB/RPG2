#include <iostream>
#include <string>
#include <limits>
#include "Player.h"


std::string getName();
void ignoreLine();

void welcome() {
    //std::cout << "   _____             _____  _____   _____   ___  \n  / ____|_     _    |  __ \\|  __ \\ / ____| |__ \\ \n | |   _| |_ _| |_  | |__) | |__) | |  __     ) |\n | |  |_   _|_   _| |  _  /|  ___/| | |_ |   / / \n | |____|_|   |_|   | | \\ \\| |    | |__| |  / /_ \n  \\_____|           |_|  \\_\\_|     \\_____| |____|\n";
    std::cout << "C++ RPG\n";
}

bool play(std::string& name);
void turn(Player& p);

bool test() {
    return false;
}

int main()
{
    welcome();
    std::string name{ getName() };
    std::cout << "Welcome to C++ RPG 2, " << name << '\n';

    
    if (!play(name)) {
        std::cout << "You lost\n";
    }
    else {
        std::cout << "Congratulations, you won!\n";
    }
    
    

    //std::cout << "Thanks for playing\n";
}


bool play(std::string& name) {
    int rounds{ 0 };

    Player player{name};
    // instantiated user object
    while (player.getHP() > 0) // While user is alive
    {

        if (player.getLevel() >= 10) {
            return true;
        }
        ++rounds;
        // Get decision input here
        // Call turn with input
        turn(player);
        
        break; // testing
    }
    return false;
}

void turn(Player& p) {
    std::cout << "Playing round\n";
    // Map to navigate
    int map[3][3]{
        {0, 2, 0},
        {1, 8, 1},
        {0, 1, 0},
    };

    std::cout << "Player at " << map[p.getCoordX()][p.getCoordY()] << '\n';

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