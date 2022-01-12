#include "Controller.h"
#include <memory>
#include "Model.h"
#include "View.h"
#include "Players/Player.h"
#include "Players/Human.h"
#include "Players/Computer.h"
#include "Exceptions/NullPointer.h"

void Controller::runGame() {
    std::cout << "Would you like to be the 1'st or the 2'nd?\nType 1 or 2:";
    size_t humansTurn;
    do {
        while (!(std::cin >> humansTurn)) {
            std::cout << "INCORRECT INPUT TYPE\nTry again:";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (humansTurn != 1 && humansTurn != 2) {
            std::cout << "INCORRECT TURN NUMBER\n1 OR 2 WERE EXPECTED\nTry again:";
            std::cin >> humansTurn;
        }
    } while (humansTurn != 1 && humansTurn != 2);
    
    std::shared_ptr<Player> player1 = std::make_shared<Human>();
    if (player1 == nullptr) {
        throw Exceptions::NullPointer("player1 is nullptr");
    }
    std::shared_ptr<Player> player2 = std::make_shared<Computer>();
    if (player2 == nullptr) {
        throw Exceptions::NullPointer("player2 is nullptr");
    }
    
    if (humansTurn == 2) {
        std::swap(player1, player2);
    }

    std::shared_ptr<Model> model = std::make_shared<Model>();
    if (model == nullptr) {
        throw Exceptions::NullPointer("model is nullptr");
    }
    View view(model);
    model->notifyObservers();
    
    GameState gameState = model->getGameState();
    
    while (gameState == X_TURN || gameState == O_TURN) {
        std::string boardInfo = model->getBoardInfo();
        size_t choice;
        if (gameState == X_TURN) {
            std::cout << "The 1'st player's turn\nChoose space to mark:";
            do {
                choice = player1->getChoice(boardInfo);
            } while (!model->makeTurn(choice));
        } else {
            std::cout << "The 2'st player's turn\nChoose space to mark:";
            do {
                choice = player2->getChoice(boardInfo);
            } while (!model->makeTurn(choice));
        }
        gameState = model->getGameState();
    }
    
    if (gameState != DRAW) {
        std::cout << ((gameState == X_WINNER) ? "The 1'st player wins!\n"
                                              : "The 2'nd player wins!\n");
    } else {
        std::cout << "DRAW\n";
    }
}
