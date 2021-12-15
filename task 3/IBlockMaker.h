#ifndef FACTORY_IBLOCKMAKER_H
#define FACTORY_IBLOCKMAKER_H

namespace Common {
    class Block;
    
    class IBlockMaker {
    public:
        virtual Block* Create(std::vector<std::string> parameters) const = 0;
        
        virtual ~IBlockMaker() {
        }
    };
}

#endif //FACTORY_IBLOCKMAKER_H
