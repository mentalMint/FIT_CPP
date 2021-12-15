#include <vector>
#include "ReadFile.h"

namespace SimpleBlocks {
    static Common::BlockMaker<ReadFile> maker("readfile");
    
    std::list<std::string> ReadFile::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw std::exception();
        }
        
        //
        
        std::list<std::string> ne_text;
        return ne_text;
    }
    
    Common::BlockType ReadFile::getType() {
        {
            return Common::BlockType::IN;
        }
    }
}