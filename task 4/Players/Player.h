#ifndef TICTACTOEMVC_PLAYER_H
#define TICTACTOEMVC_PLAYER_H

#include <iostream>

//typedef struct Token {
//
//} Token;

class Player {
public:
    virtual ~Player() {
    }
    
    virtual size_t getChoice(std::string) = 0;
    
    virtual char getToken() const = 0;
    
    virtual int getTerm() const = 0;
    
    virtual void setToken(char) = 0;
    
    virtual void setTerm(int) = 0;
};


#endif //TICTACTOEMVC_PLAYER_H
