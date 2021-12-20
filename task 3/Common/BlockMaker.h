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
            BlockFactory::getInstance().RegisterMaker(key, this);
        }
        
        std::shared_ptr<Block> Create(std::vector<std::string> parameters) const override {
            return std::make_shared<T>(parameters);
        }
    };
}

#endif //FACTORY_BLOCKMAKER_H
