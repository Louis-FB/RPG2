#include <iostream>
#include <string>
#include <limits>
#include "Player.h"
#include "Game.h"
#include "Map.h"
#include "Monster.h"
#include "Entity.h"
#include "Item.h"
#include "Random.h"

std::string getName();
void ignoreLine();
char getInput();
bool move(char direction, Player& p, Game& g);
void welcome();
bool play(std::string& name);
void turn(Player& p, Game& g);
void monsterRound(Player& p, Game& g, bool boss);
//void bossRound(Player& p, Game& g);
// void monsterRound(Entity& attacker, Entity& defender);
char getAction();
bool searchInventory(Player& p);
bool attack(int damage, Entity& defender);
void loot(Player& p, Monster& m);
void displayStats(Player& p, Monster& m);
void shopRoom(Player& p, Game& g);
void treasureRoom(Player& p, Game& g);

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
            //std::cout << "Move successful\n";
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
        std::cout << "You continue through the dark passageways\n";
        break;
    case Map::X:
        std::cout << "You come across the remains of a defeated monster\n";
        break;
    case Map::M:
        monsterRound(p, g, 0);
        break;
    case Map::B:
        monsterRound(p, g, 1);
        break;
    case Map::S:
        shopRoom(p, g);
        break;
    case Map::T:
        treasureRoom(p, g);
        break;
    default: // unknown
        std::cout << "Unknown room\n";
        break;
    }
    // Check user location for what to appear in room

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
            //std::cout << "You moved north\n";
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
            //std::cout << "You moved west\n";
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
            //std::cout << "You moved south\n";
            //std::cout << "South room: " << Map::map[g.getCoordY()][g.getCoordX()] << " Y: " << g.getCoordY() << " X: " << g.getCoordX() << '\n';
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

void monsterRound(Player& p, Game& g, bool boss = 0) {
    //std::cout << "Monster fight\n"; // test
        
    // generate monster
    Monster monster{ !boss ? MonsterNamespace::getRandomMonster() : dragon };
    //Monster monster{ MonsterNamespace::getRandomMonster() };
    if (!boss) {
        std::cout << "**Monster appeared**\n";
    }
    else {
        std::cout << "**Boss appeared**\n";
    }
    std::cout << "You encountered a " << monster.getName() << '\n';
    while (true) {      
        displayStats(p, monster);
        char action{ getAction() };

        // Flee
        if (action == 'f') {
            int success{Random::get(0, 1)}; // Make randomised
            if (success == 1) {
                std::cout << "You escaped\n";
                break;
            }
            else {
                std::cout << "You failed to escape\n";
            }
        }

        // Inventory
        if (action == 'i') {
            std::cout << "Opening inventory...\n";
            if (!searchInventory(p)) {
                continue;
            }
            std::cout << p.getEffect() << '\n';
            if (p.getEffect() == PotionNamespace::health) {
                std::cout << "You healed yourself with a health potion\n";
                p.removeEffect();
            }
            else if (p.getEffect() == PotionNamespace::invisibility) {
                std::cout << "You drank a potion of invisibility and slipped away unnoticed\n";
                p.removeEffect();
                break;
            }
        }

        // Attack
        if (action == 'a') {
            std::cout << "You attacked the " << monster.getName();
            int damage{ p.getEffect() == PotionNamespace::strength ? p.getAttack() + 10 : p.getAttack() };
            if (p.getEffect() != PotionNamespace::max_potions)
                p.removeEffect();

            if (attack(damage, monster)) {
                std::cout << " for " << damage << " damage\n";
            }
            else {
                std::cout << " and missed\n";
            }
        }
        
        if (!monster.checkAlive()) {
            std::cout << "You defeated the " << monster.getName() << '\n';
            loot(p, monster);
            Map::modifyMap(g.getCoordY(), g.getCoordX(), Map::X);
            if (boss)
                p.setVictory();
            break;
        }
        else {
            std::cout << "The " << monster.getName() << " attacked you ";
        }

        // If monster is still alive it attacks
        if (attack(monster.getAttack(), p)) {
            std::cout << " for " << monster.getAttack() << " damage\n";
        }
        else {
            std::cout << " and missed\n";
        }
        
        if (!p.checkAlive()) {
            break;
        }
        //break; // testing
    }// loop end
}

char getAction() {
    while (true) {
        std::cout << "Attack (a), Flee (f), Inventory (i)\n";
        char action{};
        std::cin >> action;

        if (action == 'a' || action == 'f' || action == 'i') {
            return action;
        }
    }
}

bool searchInventory(Player& p) {
    using namespace PotionNamespace;

    if (p.getInventory().size() <= 0) {
        std::cout << "Inventory empty\n";
        return false;
    }

    std::cout << "0) exit\n";
    for (std::size_t i{ 0 }; i < p.getInventory().size(); ++i) {
        std::cout << i + 1 << ") " << potionName[p.getInventory()[i]] << '\n';
    }

    while (true) {
        int selection{};
        std::cin >> selection;
        if (selection == 0) {
            return false;
        }
        if (selection > 0 && selection <= p.getInventory().size()) {
            --selection;
            std::cout << "You drank " << PotionNamespace::potionName[p.getInventory()[selection]] << '\n';
            p.addEffect(p.getInventory()[selection]);
            return true;
        }
    }
}

bool attack(int damage, Entity& defender) {
    bool success{ true }; // randomise
    if (success) {
        defender.setHP(defender.getHP() - damage);
        return true;
    }
    else {
        return false;
    }
}

void loot(Player& p, Monster& m) {
    
    std::cout << "You found:\n";
    p.addGold(m.getGold());
    std::cout << " +" << m.getGold() << " gold\n";
    if (Random::get(1, 3) == 1) {
        PotionNamespace::Potions randomPotion{ static_cast<PotionNamespace::Potions>(Random::get(0, PotionNamespace::max_potions - 1)) };
        //PotionNamespace::Potions itemFound{ PotionNamespace::strength };
        p.addToInventory(randomPotion);
        std::cout << " +" << PotionNamespace::potionName[randomPotion] << '\n';
    }
    if(m.isBoss())
        std::cout << " +golden fleece\n";
    p.addXP(m.getXP());
    // xp
}

/*
void bossRound(Player& p, Game& g) {
    std::cout << "**Boss appeared**\n";
    Monster monster{ dragon };
}
*/

void shopRoom(Player& p, Game& g) {
    std::cout << "You come across a merchant selling his wares for gold\n";
    std::cout << "Do you want to buy anything? (y/n)\n";
    
    char option{};
    while (true) {
        char choice{};
        std::cin >> choice;
        if (choice == 'y' || choice == 'n') {
            option = choice;
            break;
        }
    }
    
    if (option == 'y') {
        std::cout << "0) exit\n";
        for (int i{ 0 }; i < PotionNamespace::max_potions; ++i) {
            std::cout << i + 1 << ") " << PotionNamespace::potionName[i] << " (" << PotionNamespace::potionCost[i] << " gold)\n";
        }
        while (true) {
            // get input
            int choice{};
            std::cin >> choice;
            if (choice == 0) {
                break;
            } // exit
            else if (choice > 0 && choice < PotionNamespace::max_potions) {
                --choice;
                if (p.getGold() - PotionNamespace::potionCost[choice] >= 0) {
                    p.removeGold(PotionNamespace::potionCost[choice]);
                    p.addToInventory(static_cast<PotionNamespace::Potions>(choice));
                    std::cout << "You bought a " << PotionNamespace::potionName[choice] << " for " << PotionNamespace::potionCost[choice] << " gold.\n";
                    break;
                }
                else {
                    std::cout << "You cannot afford that potion\n";
                    continue;
                }
            }

        }
    }
}

void treasureRoom(Player& p, Game& g) {
    std::cout << "You come across a room with a chest in the middle. \nDo you want to open it? (y/n)\n";
    char option{};
    while (true) {
        char choice{};
        std::cin >> choice;
        if (choice == 'y' || choice == 'n') {
            option = choice;
            break;
        }
    }

    if (option == 'y') {
        std::cout << "You opened the chest\n";
        bool success{false};
        if (Random::get(0, 1) == 1)
            success = true;

        if (success) {
            std::cout << "And found ";
            int gold{ Random::get(10, 30) };
            std::cout << gold << " gold\n";
        }
        else {
            std::cout << "And it exploded, damaging you for ";
            int damage{ Random::get(10, 30) };
            std::cout << damage << " health\n";
            p.setHP(p.getHP() - damage);
        }
    }
    else {
        std::cout << "You moved on\n";
    }
    Map::modifyMap(g.getCoordY(), g.getCoordX(), Map::C);
    // mark map
}

void displayStats(Player& p, Monster& m) {
    std::cout << p.getName() << '\n';
    std::cout << "HP: " << p.getHP() << '/' << p.getMaxHP() << "  ";
    std::cout << "ATK: " << p.getAttack() << "\n";

    std::cout << m.getName() << '\n';
    std::cout << "HP: " << m.getHP() << '/' << m.getMaxHP() << "  ";
    std::cout << "ATK: " << m.getAttack() << "\n\n";
}
