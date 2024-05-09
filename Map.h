#pragma once

namespace Map {
    const int ROW{ 11 };
    const int COL{ 11 };

    enum mapSymbols {
        C, // corridor
        X, // defeated monster
        M, // undefeated monster
        S, // shop
        T, // treasure
        B, // boss
        W, // wall
        maxSize,
    };

    mapSymbols map[ROW][COL]{
        {C, C, W, C, C, C, C, W, W, C, C},
        {W, C, C, C, W, W, C, C, W, C, W},
        {C, C, W, W, C, C, W, C, C, C, W},
        {C, W, C, W, M, W, C, C, W, C, W},
        {C, C, C, W, C, C, W, C, C, C, C},
        {W, C, C, C, C, C, C, C, C, T, B},
        {C, C, W, C, W, C, W, W, W, C, C},
        {C, W, W, C, C, C, C, W, C, C, W},
        {C, C, C, W, W, W, B, W, C, W, C},
        {W, W, C, C, C, W, M, C, C, C, C},
        {W, C, C, W, C, C, T, W, C, W, W},
    };

    int blankMap[ROW][COL]{ // Guide of discovered locations 1 = discovered, 0 = undiscovered
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    void markMap(int y, int x) { // y swap with x??
        blankMap[y][x] = 1;
    }

    void modifyMap(int y, int x, mapSymbols symbol) {
        map[y][x] = symbol;
    }

    void drawMap(Game& g) {
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
            std::cout << "| ";
            for (int j{ 0 }; j < COL; ++j) {
                
                if (i == g.getCoordY() && j == g.getCoordX()) {
                    std::cout << "^ ";
                    continue;
                }

                if (blankMap[i][j] == 0) { // If undiscovered element, print blank and skip
                    std::cout << "  ";
                    continue;
                }
                    

                switch (map[i][j]) {
                case C: // corridor
                    std::cout << "# ";
                    break;
                case M: // monster
                    std::cout << "M ";
                    break;
                case X: // defeated monster
                    std::cout << "X ";
                    break;
                case S: // shop
                    std::cout << "S ";
                    break;
                case T: // treasure
                    std::cout << "T ";
                    break;
                case B: // boss
                    std::cout << "B ";
                    break;
                case W: // wall
                    std::cout << "  ";
                    break;
                default:
                    std::cout << "? ";
                    break;
                }
            }
            std::cout << "|\n";
        }
      
        //std::cout << '\n';
    }
}