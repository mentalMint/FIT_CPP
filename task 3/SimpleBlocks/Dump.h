#ifndef FACTORY_DUMP_H
#define FACTORY_DUMP_H

#include "../Common/Block.h"

namespace SimpleBlocks {
    class Dump : public Common::Block {
    private:
        std::vector<std::string> _parameters;
    
    public:
        explicit Dump(std::vector<std::string> parameters) : _parameters(parameters) {};
        
        std::list<std::string>
        execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
        
        Common::BlockType getType() override;
    };
}

#endif //FACTORY_DUMP_H
