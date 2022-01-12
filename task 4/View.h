#ifndef TICTACTOEMVC_VIEW_H
#define TICTACTOEMVC_VIEW_H

#include <memory>
#include "Model.h"
#include "Observer/Observer.h"

class View : public Observer {
    std::shared_ptr<Model> _model;
    
    char positionValue(const size_t &index);
    
    void handleEvent() override;

public:
    explicit View(std::shared_ptr<Model> &model);
    
    ~View();
};


#endif //TICTACTOEMVC_VIEW_H
