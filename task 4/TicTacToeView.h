#ifndef TICTACTOEMVC_TICTACTOEVIEW_H
#define TICTACTOEMVC_TICTACTOEVIEW_H

#include "TicTacToeModel.h"

class TicTacToeView {
    TicTacToeModel board1;
public:
    TicTacToeView();
    
    ~TicTacToeView();
    
    void drawBoard();
    
    void turn();
    
    void run();
};


#endif //TICTACTOEMVC_TICTACTOEVIEW_H
