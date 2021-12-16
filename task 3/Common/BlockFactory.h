#ifndef FACTORY_BLOCKFACTORY_H
#define FACTORY_BLOCKFACTORY_H

#include <map>
#include "Block.h"
#include "IBlockMaker.h"
#include "Exception.h"

namespace Common {
    class BlockFactory {
    public:
        BlockFactory() = default;
        
        static BlockFactory &getInstance() {
            static BlockFactory factory;
            return factory;
        }
        
        void RegisterMaker(const std::string &key, IBlockMaker* maker) {
            if (_makers.find(key) != _makers.end()) {
                throw Exception("trying to register registered block");
            }
            _makers[key] = maker;
        }
        
        Block* Create(std::pair<std::string, std::vector<std::string>> block) const {
            auto i = _makers.find(block.first);
            if (i == _makers.end()) {
                throw Exception("undefined block");
            }
            IBlockMaker* maker = i->second;
            return maker->Create(block.second);
        }
    
    private:
        std::map<std::string, IBlockMaker*> _makers;
    };
}

#endif //FACTORY_BLOCKFACTORY_H
