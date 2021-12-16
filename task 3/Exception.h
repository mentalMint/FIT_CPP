#ifndef FACTORY_EXCEPTION_H
#define FACTORY_EXCEPTION_H

#include <string>

class Exception : private std::exception {
private:
    std::string _errorMessage = "";
public:
    Exception() = default;
    
    explicit Exception(std::string errorMessage) : _errorMessage(errorMessage) {
    }
    
    const char* what() const noexcept {
        return _errorMessage.c_str();
    }
};


#endif //FACTORY_EXCEPTION_H
