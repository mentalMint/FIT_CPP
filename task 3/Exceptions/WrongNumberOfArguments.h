#ifndef FACTORY_WRONGNUMBEROFARGUMENTS_H
#define FACTORY_WRONGNUMBEROFARGUMENTS_H

#include "Exception.h"

namespace Exceptions {
    class WrongNumberOfArguments : public Exception {
    public:
        WrongNumberOfArguments() : Exception("wrong number of arguments") {}
        
        explicit WrongNumberOfArguments(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}


#endif //FACTORY_WRONGNUMBEROFARGUMENTS_H
