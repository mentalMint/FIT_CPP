#ifndef FACTORY_READFILE_H
#define FACTORY_READFILE_H

#include "Block.h"

namespace SimpleBlocks {
    class ReadFile : public Common::Block {
    private:
        std::vector<std::string> _parameters;
        
    public:
        explicit ReadFile(std::vector<std::string> parameters) : _parameters(parameters) {};
        
        std::list<std::string>
        execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
        
        Common::BlockType getType() override;
    };
}

#endif //FACTORY_READFILE_H
