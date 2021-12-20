#ifndef FACTORY_EXCEPTION_H
#define FACTORY_EXCEPTION_H

#include <string>

namespace Exceptions {
    class Exception : public std::exception {
    private:
        std::string _errorMessage = "";
    public:
        Exception() = default;
        
        explicit Exception(std::string errorMessage) : _errorMessage(errorMessage) {
        }
        
        const char* what() const noexcept override {
            return _errorMessage.c_str();
        }
    };
}


#endif //FACTORY_EXCEPTION_H
