#ifndef FACTORY_IBLOCKMAKER_H
#define FACTORY_IBLOCKMAKER_H

#include <memory>
#include <vector>
#include <string>

namespace Common {
    class Block;
    
    class IBlockMaker {
    public:
        virtual std::shared_ptr<Block> Create(std::vector<std::string> parameters) const = 0;
        
        virtual ~IBlockMaker() {
        }
    };
}

#endif //FACTORY_IBLOCKMAKER_H
