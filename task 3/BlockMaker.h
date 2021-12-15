#ifndef FACTORY_BLOCKMAKER_H
#define FACTORY_BLOCKMAKER_H

#include "IBlockMaker.h"
#include "BlockFactory.h"
#include "Sort.h"

namespace Common {
    template<typename T>
    class BlockMaker : public IBlockMaker {
    public:
        BlockMaker(const std::string &key) {
            getInstance().RegisterMaker(key, this);
        }
        
        Block* Create(std::vector<std::string> parameters) const override{
            return new T(parameters);
        }
    };
}

#endif //FACTORY_BLOCKMAKER_H
