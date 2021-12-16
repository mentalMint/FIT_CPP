#ifndef FACTORY_BLOCKMAKER_H
#define FACTORY_BLOCKMAKER_H

#include <iostream>
#include "BlockFactory.h"
#include "IBlockMaker.h"

namespace Common {
    template<typename T>
    class BlockMaker : public IBlockMaker {
    public:
        explicit BlockMaker(const std::string &key) {
            try {
                BlockFactory::getInstance().RegisterMaker(key, this);
            } catch (Exception &ex) {
                std::cerr << "Error : " << ex.what() << std::endl;
            }
        }
        
        Block* Create(std::vector<std::string> parameters) const override{
            return new T(parameters);
        }
    };
}

#endif //FACTORY_BLOCKMAKER_H
