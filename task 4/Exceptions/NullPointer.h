#ifndef HASHTABLE_NULLPOINTER_H
#define HASHTABLE_NULLPOINTER_H

#include "Exception.h"

namespace Exceptions {
    class NullPointer : public Exception {
    public:
        NullPointer() : Exception("null pointer") {}
        
        explicit NullPointer(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}

#endif //HASHTABLE_NULLPOINTER_H
