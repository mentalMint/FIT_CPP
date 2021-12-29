#include "TicTacToeView.h"

TicTacToeView::TicTacToeView() {
}


TicTacToeView::~TicTacToeView() {
}

void TicTacToeView::drawBoard() {
    std::cout << board1.positionValue(1) << " |" << " " << board1.positionValue(2) << " |" << " "
              << board1.positionValue(3) << "\n";
    std::cout << "___|___|___ \n";
    std::cout << " " << board1.positionValue(4) << " |" << " " << board1.positionValue(5) << " |" << " "
              << board1.positionValue(6) << "\n";
    std::cout << "___|___|___ \n";
    std::cout << " " << board1.positionValue(7) << " |" << " " << board1.positionValue(8) << " |" << " "
              << board1.positionValue(9) << "\n";
    std::cout << "   |   |   ";
}

void TicTacToeView::turn() {
    char mark;
    size_t choice;
    int turnCount = board1.getTurnCounter();
    if (board1.getTurn() == PLAYER_1) {
        mark = board1.getMark(PLAYER_1);
        turnCount++;
        std::cout << "\nThe 1'st player's turn\nChoose space to mark: ";
        choice = board1.getChoice();
    } else {
        mark = board1.getMark(PLAYER_2);
        turnCount++;
        std::cout << "\nThe 2'nd player's turn\nChoose space to mark: ";
        choice = board1.getChoice();
    }
    board1.markBoard(choice, mark);
    board1.setTurnCounter(turnCount);
    board1.setTurn(!board1.getTurn());
}

void TicTacToeView::run() {
    std::cout << "Would you like to be the 1'st or the 2'nd?\nType 1 or 2: ";
    int humansTurn;
    std::cin >> humansTurn;
    board1.setPlayers(humansTurn);
    
    GameState gameState = NOT_OVER;
    drawBoard();
    while (gameState == NOT_OVER) {
        turn();
        gameState = board1.getGameState();
        drawBoard();
    }
    if (gameState != DRAW) {
        std::cout << ((board1.getCurrentToken(PLAYER_1) == gameState) ? "\nThe 1'st player wins!" : "\nThe 2'nd player wins!");
    } else {
        std::cout << "\nDRAW";
    }
}