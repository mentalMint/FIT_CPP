#ifndef TICTACTOEMVC_PLAYER_H
#define TICTACTOEMVC_PLAYER_H

#include <string>

class Player {
public:
    virtual ~Player() {
    }
    
    virtual size_t getChoice(const std::string& boardInfo) = 0;

};


#endif //TICTACTOEMVC_PLAYER_H
