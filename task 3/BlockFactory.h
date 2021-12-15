#ifndef FACTORY_BLOCKFACTORY_H
#define FACTORY_BLOCKFACTORY_H

#include <map>
#include "Block.h"
#include "ReadFile.h"
#include "Sort.h"
#include "IBlockMaker.h"

namespace Common {

    class BlockFactory {
        BlockFactory() = default;
    
    public:
        
        static BlockFactory &getInstance() {
            static BlockFactory factory;
            
            return factory;
        }
        
//        Block* getBlock(const std::string &blockName) {
//            if (blockName == "readfile") {
//                return new ReadFile();
//            } else if (blockName == "sort") {
//                return new Sort();
//            }
//
//            throw std::exception();
//        }
        
        void RegisterMaker(const std::string &key, IBlockMaker* maker) {
            if (_makers.find(key) != _makers.end()) {
                throw std::exception();
            }
            _makers[key] = maker;
        }
        
        Block* Create(std::pair<std::string, std::vector<std::string>> block) const {
            auto i = _makers.find(block.first);
            if (i == _makers.end()) {
                throw std::exception();
            }
            IBlockMaker* maker = i->second;
            return maker->Create(block.second);
        }
    
    private:
        std::map<std::string, IBlockMaker*> _makers;
        
    };
}

#endif //FACTORY_BLOCKFACTORY_H
