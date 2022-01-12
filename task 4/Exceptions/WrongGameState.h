#ifndef TICTACTOEMVC_WRONGGAMESTATE_H
#define TICTACTOEMVC_WRONGGAMESTATE_H

#include "Exception.h"

namespace Exceptions {
    class WrongGameState : public Exception {
    public:
        WrongGameState() : Exception("null pointer") {
        }
        
        explicit WrongGameState(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}


#endif //TICTACTOEMVC_WRONGGAMESTATE_H
