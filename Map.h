#pragma once

namespace Map {
    const int ROW{ 11 };
    const int COL{ 11 };

    enum mapSymbols {
        blank,
        corridor,
        monsterDefeated,
        monsterUndefeated,
        merchant,
        treasure
    };

    const int map[ROW][COL]{
        {1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
        {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    };

    mapSymbols blankMap[ROW][COL]{ // Draw 1 where user goes
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, corridor, blank, blank, blank, corridor, blank, corridor, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {corridor, blank, blank, blank, corridor, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, corridor, blank, blank, blank, blank, blank, blank, blank, corridor},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, corridor, blank, blank, blank, blank, blank, blank, blank, corridor},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {corridor, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, corridor, corridor, blank, blank, blank, blank, blank, blank, blank},
    };

    void markMap(int x, int y, int symbol) {
        blankMap[x][y] = static_cast<mapSymbols>(symbol);
    }

    void drawMap() {
        // nested for loop draw square where element is 1, otherwise blank.
        
        for (int i{ 0 }; i < ROW; ++i) {
            std::cout << "|";
            for (int j{ 0 }; j < COL; ++j) {
             
                if (blankMap[i][j] == blank) {
                    std::cout << ' ';
                }
                else {
                    std::cout << 'X';
                }
            }
            std::cout << "|\n";
        }
      
        //std::cout << '\n';
    }
}