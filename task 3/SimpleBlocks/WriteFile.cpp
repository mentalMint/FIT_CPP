#include "WriteFile.h"
#include <fstream>

namespace SimpleBlocks {
    static Common::BlockMaker<WriteFile> maker("writefile");
    
    std::list<std::string>
    WriteFile::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw Exception("insufficient arguments for writefile");
        } else if (args.size() > 1) {
            throw Exception("too much arguments for writefile");
        }
    
        std::fstream output(args[0]);
        for (const auto& word : text) {
            output << word;
            if (word != "\n") {
                output << " ";
            }
        }
        
        std::list<std::string> newText;
        return newText;
    }
    
    Common::BlockType WriteFile::getType() {
        return Common::BlockType::OUT;
    }
}