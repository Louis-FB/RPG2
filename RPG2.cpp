#include <iostream>
#include <string>
#include <limits>
#include "Player.h"
#include "Game.h"
#include "Map.h"
#include "Monster.h"

std::string getName();
void ignoreLine();
char getInput();
bool move(char direction, Player& p, Game& g);
void welcome();
bool play(std::string& name);
void turn(Player& p, Game& g);
void monsterRound(Player& p, Game& g);
char getAction();

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
    
    std::cout << "Thanks for playing\n";
}

void welcome() {
    //std::cout << "   _____             _____  _____   _____   ___  \n  / ____|_     _    |  __ \\|  __ \\ / ____| |__ \\ \n | |   _| |_ _| |_  | |__) | |__) | |  __     ) |\n | |  |_   _|_   _| |  _  /|  ___/| | |_ |   / / \n | |____|_|   |_|   | | \\ \\| |    | |__| |  / /_ \n  \\_____|           |_|  \\_\\_|     \\_____| |____|\n";
    //std::cout << "You wake up in a dark dungeon\n";
    std::cout << "C++ RPG 2\n";
}


bool play(std::string& name) {
    //int rounds{ 0 };

    Player player{name};
    Game game{};
    // instantiated user object
    while (player.checkAlive()) // While user is alive
    {
        if (player.hasWon()) // replace with bool has won function
            return true;
    
        game.incrementRounds();
        std::cout << "Round " << game.getRounds() << '\n';
        Map::drawMap(game);
        turn(player, game);
        
        
        
        //break; // testing
    }
    return false;
}

void turn(Player& p, Game& g) {
    // Map to navigate

    while (true) {
        char action{ getInput() };

        if (move(action, p, g)){ // If move successful, continue.
            std::cout << "Move successful\n";
            break;
        }
        else {
            std::cout << "Move failed\n";
        }
    }

    Map::mapSymbols currentRoomType{ Map::map[g.getCoordY()][g.getCoordX()] };
    //Map::markMap(g.getCoordY(), g.getCoordX());

    switch (currentRoomType) {
    case Map::C: // corridor
        std::cout << "You continue through the dark corridor\n";
        break;
    case Map::X:
        std::cout << "You come across the remains of a defeated monster\n";
        break;
    case Map::M:
        monsterRound(p, g);
        // fight
        break;
    default: // unknown
        std::cout << "Unknown room\n";
        break;
    }
    // Check user location for what to appear in room



    //std::cout << "Player at " << map[p.getCoordX()][p.getCoordY()] << '\n';

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

char getInput() {
    while (true) {
        
        std::cout << "North (w), West (a), South (s), East (d)\n";
        char input{};
        std::cin >> input;

        if (input == 'w' || input == 'a' || input == 's' || input == 'd')
            return input;
   
        std::cout << "Failed input\n";
        std::cin.clear();
    }
}

bool move(char direction, Player& p, Game& g) { // bounds checking and check if way is blocked? // count elements?
    int room{};
    Map::markMap(g.getCoordY(), g.getCoordX());

    switch (direction) {
    case 'w': // Move 'north'
        if (g.getCoordY() - 1 >= 0) { // Check array bounds 'up'
            room = Map::map[g.getCoordY() - 1][g.getCoordX()];
            if (room == Map::W) { // If room is unavailable
                break;
            }
            // Update user position and return true
            g.changeLocation(g.getCoordY() - 1, g.getCoordX());
            std::cout << "You moved north\n";
            return true;
        }
        break;
    case 'a': // Move 'west'
        if (g.getCoordX() - 1 >= 0) { // Check array bounds left
            room = Map::map[g.getCoordY()][g.getCoordX() - 1];
            if (room == Map::W) { // If room is unavailable
                break;
            }
            g.changeLocation(g.getCoordY(), g.getCoordX() - 1);
            std::cout << "You moved west\n";
            return true;
        }
        break; 
    case 's': // move 'south'
        if (g.getCoordY() + 1 < Map::ROW) {
            room = Map::map[g.getCoordY() + 1][g.getCoordX()];
            if (room == Map::W) { // If room is unavailable
                break;
            }
            // Update user position and return true
            g.changeLocation(g.getCoordY() + 1, g.getCoordX());
            std::cout << "You moved south\n";
            std::cout << "South room: " << Map::map[g.getCoordY()][g.getCoordX()] << " Y: " << g.getCoordY() << " X: " << g.getCoordX() << '\n';
            return true;
        }
        break;
    case 'd': // move 'east'
        if (g.getCoordX() + 1 < Map::COL) {
            room = Map::map[g.getCoordY()][g.getCoordX() + 1];
            if (room == Map::W) { 
                break;
            }
            g.changeLocation(g.getCoordY(), g.getCoordX() + 1);
            std::cout << "You moved east\n";
            return true;
        }
        break;
}
    std::cout << "The way is blocked\n";
    return false;
}

void monsterRound(Player& p, Game& g) {
    std::cout << "Monster fight\n"; // test
        
    // generate monster
    Monster monster{ getRandomMonster() };
    //Monster monster{ MonsterNamespace::goblin };
    std::cout << "You encountered a " << monster.getName() << '\n';
    while (true) {
        
        // player action
        //
        // switch statement for action
        //attack(p, monster)
        char action{ getAction() };

        // monster attack

        // if monster dead, replace map coordinate with defeated monster
        
        if (!monster.checkAlive()) {
            std::cout << "You defeated the " << monster.getName() << '\n';
            Map::modifyMap(g.getCoordY(), g.getCoordX(), Map::X);
            break;
        }
        break; // testing
    }// loop end
}

char getAction() {
    return 'a';
}