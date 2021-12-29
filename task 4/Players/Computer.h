#ifndef TICTACTOEMVC_COMPUTER_H
#define TICTACTOEMVC_COMPUTER_H

#include <limits>
#include <random>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
#include "Player.h"


class Computer : public Player {
private:
    char _token;
    int _term = 2;

public:
    
    Computer(int term = 1) : _term(term) {
        if (term == 1) {
            _token = 'x';
        } else {
            _token = 'o';
        }
    }
    
    size_t getChoice(std::string boardInfo) {
        std::vector<size_t> freeCells;
        for (char i : boardInfo) {
            if (i != 'x' && i != 'o') {
                freeCells.emplace_back((size_t) i - 49);
            }
        }

        srand(time(nullptr));
        size_t choice = freeCells[rand() % freeCells.size()];
        using namespace std::this_thread;     // sleep_for, sleep_until
        using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
        using std::chrono::system_clock;
        sleep_until(system_clock::now() + 1s);
        std::cout << choice << std::endl << " ";
        return choice;
    }
    
    char getToken() const
    override {
        return _token;
    }
    
    int getTerm() const
    override {
        return _term;
    }
    
    void setToken(char token)
    override {
        _token = token;
    }
    
    void setTerm(int term)
    override {
        _term = term;
    }
};


#endif //TICTACTOEMVC_COMPUTER_H
