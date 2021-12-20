#ifndef FACTORY_REGISTEREDBLOCK_H
#define FACTORY_REGISTEREDBLOCK_H

#include "Exception.h"

namespace Exceptions {
    class RegisteredBlock : public Exception {
    public:
        RegisteredBlock() : Exception("registered block") {
        }
        
        explicit RegisteredBlock(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}

#endif //FACTORY_REGISTEREDBLOCK_H
