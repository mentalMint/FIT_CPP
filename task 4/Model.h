#ifndef TICTACTOEMVC_MODEL_H
#define TICTACTOEMVC_MODEL_H

#include <iostream>
#include <string>
#include "Observer/Observable.h"

enum GameState {
    X_TURN,
    O_TURN,
    X_WINNER,
    O_WINNER,
    DRAW
};

class Model : public Observable {
private:
    std::string _boardInfo = "000000000";
    
    size_t getTurnCount() const;
    
    GameState getTurn() const;

    bool checkChoice(const size_t &boardIndex) const;
    
    size_t getTotalTurns() const;
    
public:
    Model();
    
    ~Model();
    
    std::string getBoardInfo();
    
    bool makeTurn(const size_t &boardIndex);
    
    GameState getGameState() const;
};


#endif //TICTACTOEMVC_MODEL_H
