#ifndef FACTORY_BLOCK_H
#define FACTORY_BLOCK_H

#include <string>
#include <list>
#include "BlockMaker.h"
#include "Exception.h"

namespace Common {
    enum class BlockType {
        IN,
        OUT,
        INOUT
    };
    
    class Block {
    public:
        virtual std::list<std::string>
        execute(const std::list<std::string> &text, const std::vector<std::string> &args) = 0;
        
        virtual BlockType getType() = 0;
        
        virtual ~Block() {
        };
    };
}

#endif //FACTORY_BLOCK_H
