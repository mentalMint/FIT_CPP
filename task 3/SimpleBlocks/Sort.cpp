#include "Sort.h"

namespace SimpleBlocks {
    static Common::BlockMaker<Sort> maker("sort");
    
    bool compareNoCase(const std::string &first, const std::string &second) {
        size_t i = 0;
        while ((i < first.length()) && (i < second.length())) {
            if (tolower(first[i]) < tolower(second[i])) {
                return true;
            } else if (tolower(first[i]) > tolower(second[i])) {
                return false;
            }
            ++i;
        }
        return (first.length() < second.length());
    }
    
    std::list<std::string> Sort::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (!args.empty()) {
            throw Exception("too much arguments for sort");
        }
        std::list<std::string> newText = text;
        newText.sort(compareNoCase);
        return newText;
    }
    
    Common::BlockType Sort::getType() {
        {
            return Common::BlockType::INOUT;
        }
    }
    
}
