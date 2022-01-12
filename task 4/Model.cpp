#include "Model.h"
#include "Exceptions/WrongGameState.h"


Model::Model() = default;

Model::~Model() = default;

size_t Model::getTurnCount() const {
    size_t turnCount = 0;
    for (char i : _boardInfo) {
        if (i != '0') {
            ++turnCount;
        }
    }
    return turnCount;
}

GameState Model::getTurn() const {
    if (getTurnCount() % 2 == 0) {
        return X_TURN;
    } else {
        return O_TURN;
    }
}

GameState Model::getGameState() const {
    for (size_t i = 0, k = 8; i <= 3 && k >= 5; i++, k--) {
        if (_boardInfo[4] == _boardInfo[i] && _boardInfo[i] == _boardInfo[k]) {
            if (_boardInfo[4] == 'x') {
                return X_WINNER;
            } else if (_boardInfo[4] == 'o') {
                return O_WINNER;
            }
        }
    }
    
    if (_boardInfo[2] == _boardInfo[1] && _boardInfo[1] == _boardInfo[0]) {
        if (_boardInfo[2] == 'x') {
            return X_WINNER;
        } else if (_boardInfo[2] == 'o') {
            return O_WINNER;
        }
    }
    if (_boardInfo[2] == _boardInfo[5] && _boardInfo[5] == _boardInfo[8]) {
        if (_boardInfo[2] == 'x') {
            return X_WINNER;
        } else if (_boardInfo[2] == 'o') {
            return O_WINNER;
        }
    }
    if (_boardInfo[6] == _boardInfo[3] && _boardInfo[3] == _boardInfo[0]) {
        if (_boardInfo[0] == 'x') {
            return X_WINNER;
        } else if (_boardInfo[0] == 'o') {
            return O_WINNER;
        }
    }
    if (_boardInfo[6] == _boardInfo[7] && _boardInfo[7] == _boardInfo[8]) {
        if (_boardInfo[6] == 'x') {
            return X_WINNER;
        } else if (_boardInfo[6] == 'o') {
            return O_WINNER;
        }
    }
    
    if (getTurnCount() >= getTotalTurns()) {
        return DRAW;
    }
    
    return getTurn();
}

std::string Model::getBoardInfo() {
    return _boardInfo;
}

bool Model::makeTurn(const size_t &boardIndex) {
    if (!checkChoice(boardIndex)) {
        return false;
    }
    
    if (getTurn() == X_TURN) {
        _boardInfo[boardIndex - 1] = 'x';
    } else if (getTurn() == O_TURN) {
        _boardInfo[boardIndex - 1] = 'o';
    } else {
        throw Exceptions::WrongGameState();
    }
    notifyObservers();
    return true;
}

size_t Model::getTotalTurns() const {
    return _boardInfo.size();
}

bool Model::checkChoice(const size_t &boardIndex) const {
    if (boardIndex > 0 && boardIndex < 10) {
        char check = _boardInfo[boardIndex - 1];
        if (check != 'X' && check != 'x' && check != 'O' && check != 'o') {
            return true;
        } else {
            std::cout << "\nSPACE ALREADY MARKED\nTry again:";
        }
    } else {
        std::cout << "\nINCORRECT SPACE\nTry again:";
    }
    return false;
}

