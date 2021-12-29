#ifndef TICTACTOEMVC_TICTACTOEMODEL_H
#define TICTACTOEMVC_TICTACTOEMODEL_H

#include <iostream>
#include <string>
#include <memory>
#include "Players/Player.h"
#include "Players/Human.h"
#include "Players/Computer.h"

enum GameState {
    NOT_OVER,
    X,
    O,
    DRAW
};

const bool PLAYER_1 = false;
const bool PLAYER_2 = true;

class TicTacToeModel {
private:
    std::string _boardInfo = "123456789";
    std::shared_ptr<Player> _player1;
    std::shared_ptr<Player> _player2;
    bool _turn = PLAYER_1;
    int _turnCounter = 1;
    int _totalTurns = 9;

public:
    TicTacToeModel();
    
    ~TicTacToeModel();
    
    void markBoard(const size_t &, const char &);
    
    void setPlayers(const int &humansTurn);
    
    char getMark(const int &) const;
    
    GameState getGameState() const;
    
    char positionValue(const size_t &);
    
    GameState getCurrentToken(const bool &player) const;
    
    int getTurnCounter() const;
    
    bool getTurn() const;
    
    void setTurnCounter(int);
    
    void setTurn(bool);
    
    size_t getChoice();
};


#endif //TICTACTOEMVC_TICTACTOEMODEL_H
