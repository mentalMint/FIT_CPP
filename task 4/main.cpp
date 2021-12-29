#include <iostream>
#include "TicTacToeView.h"

void pause();

int main() {
    TicTacToeView game1;
    game1.run();
    pause();
}

void pause() {
    char end;
    std::cout << "\nPress any key followed by ENTER to continue...";
    std::cin >> end;
}