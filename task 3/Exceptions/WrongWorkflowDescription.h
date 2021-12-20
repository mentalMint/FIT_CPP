#ifndef FACTORY_WRONGWORKFLOWDESCRIPTION_H
#define FACTORY_WRONGWORKFLOWDESCRIPTION_H

#include "Exception.h"

namespace Exceptions {
    class WrongWorkflowDescription : public Exception {
    public:
        WrongWorkflowDescription() : Exception("wrong workflow description") {}
    
        explicit WrongWorkflowDescription(std::string errorMessage) : Exception(errorMessage) {
        }
    };
}


#endif //FACTORY_WRONGWORKFLOWDESCRIPTION_H
