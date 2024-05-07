#pragma once

namespace Map {
    const int ROW{ 11 };
    const int COL{ 11 };

    enum mapSymbols {
        blank,
        corridor,
        monsterUndefeated,
        monsterDefeated,
        merchant,
        treasure,
        boss,
        maxSize,
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
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
        {blank, blank, blank, blank, blank, blank, blank, blank, blank, blank, blank},
    };

    void markMap(int x, int y, int symbol) {
        blankMap[x][y] = static_cast<mapSymbols>(symbol);
    }

    void drawMap() {
        // nested for loop draw square where element is 1, otherwise blank.
        
        for (int i{ 0 }; i < ROW; ++i) {
            /*
            if (i % 2 == 0) {
                std::cout << '\u3009';
            }
            else {
                std::cout << '\u3008';
            }
            */
            std::cout << '|';
            for (int j{ 0 }; j < COL; ++j) {
             
                switch (blankMap[i][j]) {
                case blank:
                    std::cout << ' ';
                    break;
                case corridor:
                    std::cout << 'X';
                    break;
                case monsterUndefeated:
                    std::cout << 'M';
                    break;
                case monsterDefeated:
                    std::cout << 'X';
                    break;
                case merchant:
                    std::cout << 'S';
                    break;
                case treasure:
                    std::cout << 'T';
                    break;
                case boss:
                    std::cout << 'B';
                    break;
                default:
                    std::cout << '?';
                    break;
                }
            }
            std::cout << "|\n";
        }
      
        //std::cout << '\n';
    }
}