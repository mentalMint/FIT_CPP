#ifndef TICTACTOEMVC_HUMAN_H
#define TICTACTOEMVC_HUMAN_H

#include <limits>
#include <iostream>
#include "Player.h"

class Human : public Player {
public:
    Human() = default;
    
    size_t getChoice(const std::string &boardInfo) {
        while (true) {
            size_t spaceChoice;
            if (std::cin >> spaceChoice) {
                return spaceChoice;
            } else {
                std::cout << "\nINCORRECT INPUT TYPE\nTry again: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
};


#endif //TICTACTOEMVC_HUMAN_H
