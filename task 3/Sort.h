#ifndef FACTORY_SORT_H
#define FACTORY_SORT_H

#include "Block.h"
#include "BlockMaker.h"

namespace SimpleBlocks {
    class Sort : public Common::Block {
    private:
        std::vector<std::string> _parameters;
        
    public:
        Sort(std::vector<std::string> parameters) : _parameters(parameters) {};
        
        std::list<std::string>
        execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
        
        Common::BlockType getType() override;
    };

//    static BlockMaker <Sort> maker("sort");
}

#endif //FACTORY_SORT_H
