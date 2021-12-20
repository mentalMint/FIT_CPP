#include "Dump.h"
#include <fstream>
#include "../Exceptions/WrongNumberOfArguments.h"
#include "../Exceptions/FileOpeningFail.h"

namespace SimpleBlocks {
    static Common::BlockMaker<Dump> maker("dump");
    
    std::list<std::string>
    Dump::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw Exceptions::WrongNumberOfArguments("insufficient arguments for dump");
        } else if (args.size() > 1) {
            throw Exceptions::WrongNumberOfArguments("too much arguments for dump");
        }
        
        std::ofstream output(args[0], std::ofstream::trunc);
        if (!output) {
            throw Exceptions::FileOpeningFail("output file opening failed");
        }
        
        for (const auto& word : text) {
            output << word;
            if (word != "\n") {
                output << " ";
            }
        }
        
        return text;
    }
    
    Common::BlockType Dump::getType() {
        return Common::BlockType::INOUT;
    }
}