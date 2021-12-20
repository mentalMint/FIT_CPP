#ifndef FACTORY_GREP_H
#define FACTORY_GREP_H

#include "../Common/Block.h"

namespace SimpleBlocks {
    class Grep : public Common::Block {
    private:
        std::vector<std::string> _parameters;
    
    public:
        explicit Grep(std::vector<std::string> parameters) : _parameters(parameters) {};
        
        std::list<std::string>
        execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
        
        Common::BlockType getType() override;
    };
}


#endif //FACTORY_GREP_H
