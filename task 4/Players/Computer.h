#ifndef TICTACTOEMVC_COMPUTER_H
#define TICTACTOEMVC_COMPUTER_H

#include <limits>
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
#include "Player.h"


class Computer : public Player {
public:
    Computer() = default;
    
    size_t getChoice(const std::string& boardInfo) {
        std::vector<size_t> freeCells;
        for (size_t i = 0; i < boardInfo.size(); ++i) {
            if (boardInfo[i] == '0') {
                freeCells.emplace_back(i + 1);
            }
        }

        srand(time(nullptr));
        size_t choice = freeCells[rand() % freeCells.size()];
        using namespace std::this_thread;
        using namespace std::chrono_literals;
        using std::chrono::system_clock;
        sleep_until(system_clock::now() + 1s);
        std::cout << choice << std::endl;
        return choice;
    }

};


#endif //TICTACTOEMVC_COMPUTER_H
