#include <iostream>
#include "Controller.h"

int main() {
    Controller game;
    try {
        game.runGame();
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
}
