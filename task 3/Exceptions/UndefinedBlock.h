#ifndef FACTORY_UNDEFINEDBLOCK_H
#define FACTORY_UNDEFINEDBLOCK_H

#include "Exception.h"

namespace Exceptions {
    class UndefinedBlock : public Exception {
    public:
        UndefinedBlock() : Exception("undefined block") {}
    
        explicit UndefinedBlock(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}

#endif //FACTORY_UNDEFINEDBLOCK_H
