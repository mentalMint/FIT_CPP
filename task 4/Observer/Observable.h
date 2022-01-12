#ifndef TICTACTOEMVC_OBSERVER_OBSERVABLE_H_
#define TICTACTOEMVC_OBSERVER_OBSERVABLE_H_

#include <vector>
#include "Observer.h"

class Observable {
private:
    std::vector<class Observer*> observers;
public:
    void addObserver(Observer* observer);
    
    void removeObserver(Observer* observer);
    
    void notifyObservers();
};

#endif //TICTACTOEMVC_OBSERVER_OBSERVABLE_H_
