#ifndef HASHTABLE_NOVALUE_H
#define HASHTABLE_NOVALUE_H

#include "Exception.h"

namespace Exceptions {
    class NoValue : public Exception {
    public:
        NoValue() : Exception("no value") {}
        
        explicit NoValue(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}


#endif //HASHTABLE_NOVALUE_H
