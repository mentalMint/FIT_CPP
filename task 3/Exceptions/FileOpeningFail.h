#ifndef FACTORY_FILEOPENINGFAIL_H
#define FACTORY_FILEOPENINGFAIL_H

#include "Exception.h"

namespace Exceptions {
    class FileOpeningFail : public Exception {
    public:
        FileOpeningFail() : Exception("file opening fail") {
        }
        
        explicit FileOpeningFail(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}


#endif //FACTORY_FILEOPENINGFAIL_H
