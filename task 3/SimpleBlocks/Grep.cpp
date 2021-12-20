#include "Grep.h"
#include <list>
#include <algorithm>
#include "../Exceptions/WrongNumberOfArguments.h"

namespace SimpleBlocks {
    static Common::BlockMaker<Grep> maker("grep");
    
    std::list<std::string> Grep::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw Exceptions::WrongNumberOfArguments("insufficient arguments for grep");
        } else if (args.size() > 1) {
            throw Exceptions::WrongNumberOfArguments("too much arguments for grep");
        }
        
        std::list<std::string> newText = text;
        std::string word = args[0];
        std::string delimiter = "\n";
        auto delimiterPosition = std::find(newText.begin(), newText.end(), delimiter);
        auto previousDelimiterPosition = newText.begin();
        while (delimiterPosition != newText.end()) {
            auto wordPosition = std::find(previousDelimiterPosition, delimiterPosition, word);
            if (wordPosition == delimiterPosition) {
                previousDelimiterPosition = newText.erase(previousDelimiterPosition, std::next(delimiterPosition, 1));
            }
            else {
                previousDelimiterPosition = std::next(delimiterPosition, 1);
            }
            delimiterPosition = std::find(previousDelimiterPosition, newText.end(), delimiter);
        }
        return newText;
    }
    
    Common::BlockType Grep::getType() {
        return Common::BlockType::INOUT;
    }
}