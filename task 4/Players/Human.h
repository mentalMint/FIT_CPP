#ifndef TICTACTOEMVC_HUMAN_H
#define TICTACTOEMVC_HUMAN_H

#include <limits>
#include "Player.h"

class Human : public Player {
private:
    char _token;
    int _term;
    
public:
    
    Human(int term = 1) : _term(term) {
        if (term == 1) {
            _token = 'x';
        } else {
            _token = 'o';
        }
    }
    
    size_t getChoice(std::string boardInfo) {
        while (true) {
            size_t spaceChoice;
            if (std::cin >> spaceChoice) {
                if (spaceChoice > 0 && spaceChoice < 10) {
                    char check = boardInfo[spaceChoice - 1]; //used to check if space has been marked
                    if (check != 'X' && check != 'x' && check != 'O' && check != 'o') {
                        return spaceChoice;
                    } else {
                        std::cout << "\nSPACE ALREADY MARKED\nTry again: ";
                    }
                } else {
                    std::cout << "\nINCORRECT SPACE\nTry again: ";
                }
            }
                //if the input type fails
            else {
                std::cout << "\nINCORRECT INPUT TYPE\nTry again: ";
                std::cin.clear(); //clears input fail state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
    char getToken() const override {
        return _token;
    }
    
    int getTerm() const override {
        return _term;
    }
    
    void setToken(char token) override {
        _token = token;
    }
    
    void setTerm(int term) override {
        _term = term;
    }
};


#endif //TICTACTOEMVC_HUMAN_H
