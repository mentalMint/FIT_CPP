#include "View.h"

View::View(std::shared_ptr<Model> &model) {
    this->_model = model;
    _model->addObserver(this);
}

char View::positionValue(const size_t &index) {
    char mark = _model->getBoardInfo()[index - 1];
    return mark == '0' ? (char) index + 48 : mark;
}

void View::handleEvent() {
    std::cout << " " << positionValue(1) << " |" << " " << positionValue(2) << " |" << " "
              << positionValue(3) << "\n";
    std::cout << "___|___|___ \n";
    std::cout << " " << positionValue(4) << " |" << " " << positionValue(5) << " |" << " "
              << positionValue(6) << "\n";
    std::cout << "___|___|___ \n";
    std::cout << " " << positionValue(7) << " |" << " " << positionValue(8) << " |" << " "
              << positionValue(9) << "\n";
    std::cout << "   |   |   \n";
}

View::~View() = default;
