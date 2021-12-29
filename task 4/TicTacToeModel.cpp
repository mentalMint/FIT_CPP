#include "TicTacToeModel.h"

TicTacToeModel::TicTacToeModel() = default;

TicTacToeModel::~TicTacToeModel() = default;

void TicTacToeModel::markBoard(const size_t &boardIndex, const char &playerMark) {
    _boardInfo[boardIndex - 1] = playerMark;
}

GameState TicTacToeModel::getGameState() const{
    for (size_t i = 0, k = 8; i <= 3 && k >= 5; i++, k--) {
        if (_boardInfo[4] == _boardInfo[i] && _boardInfo[i] == _boardInfo[k]) {
            return _boardInfo[4] == 'x' ? X : O;
        }
    }
    
    if (_boardInfo[2] == _boardInfo[1] && _boardInfo[1] == _boardInfo[0]) {
        return _boardInfo[2] == 'x' ? X : O;
    }
    if (_boardInfo[2] == _boardInfo[5] && _boardInfo[5] == _boardInfo[8]) {
        return _boardInfo[2] == 'x' ? X : O;
    }
    if (_boardInfo[6] == _boardInfo[3] && _boardInfo[3] == _boardInfo[0]) {
        return _boardInfo[6] == 'x' ? X : O;
    }
    if (_boardInfo[6] == _boardInfo[7] && _boardInfo[7] == _boardInfo[8]) {
        return _boardInfo[6] == 'x' ? X : O;
    }
    
    if (_turnCounter > _totalTurns) {
        return DRAW;
    }
    
    return NOT_OVER;
}

void TicTacToeModel::setPlayers(const int &humansTurn) {
    if (humansTurn == 1) {
        _player1 = std::make_shared<Human>(1);
        _player2 = std::make_shared<Computer>(2);
    } else {
        _player1 = std::make_shared<Computer>(1);
        _player2 = std::make_shared<Human>(2);
    }
}

char TicTacToeModel::positionValue(const size_t &index) {
    return _boardInfo[index - 1];
}

char TicTacToeModel::getMark(const int &player) const {
    if (player == PLAYER_1) {
        return _player1->getToken();
    }
    
    return _player2->getToken();
}

GameState TicTacToeModel::getCurrentToken(const bool &player) const {
    if (player == PLAYER_1) {
        return X;
    } else {
        return O;
    }
}

int TicTacToeModel::getTurnCounter() const {
    return _turnCounter;
}

bool TicTacToeModel::getTurn() const {
    return _turn;
}

void TicTacToeModel::setTurn(bool turn) {
    _turn = turn;
}

void TicTacToeModel::setTurnCounter(int counter) {
    _turnCounter = counter;
}

size_t TicTacToeModel::getChoice() {
    if (_turn == PLAYER_1) {
        return _player1->getChoice(_boardInfo);
    } else {
        return _player2->getChoice(_boardInfo);
    }
}

