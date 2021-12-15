#include <vector>
#include "Sort.h"

namespace SimpleBlocks {
    static Common::BlockMaker<Sort> maker("sort");
    
    std::list<std::string> Sort::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw std::exception();
        }

//
        
        std::list<std::string> ne_text;
        return ne_text;
    }
    
    Common::BlockType Sort::getType() {
        {
            return Common::BlockType::INOUT;
        }
    }
    
}
