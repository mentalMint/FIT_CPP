#include "ReadFile.h"
#include <fstream>
#include "../Exceptions/WrongNumberOfArguments.h"
#include "../Exceptions/FileOpeningFail.h"

namespace SimpleBlocks {
    static Common::BlockMaker<ReadFile> maker("readfile");
    
    std::list<std::string> ReadFile::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw Exceptions::WrongNumberOfArguments("insufficient arguments for readfile");
        } else if (args.size() > 1) {
            throw Exceptions::WrongNumberOfArguments("too much arguments for readfile");
        }
        
        std::fstream input(args[0]);
        if (!input) {
            throw Exceptions::FileOpeningFail("input file opening failed");
        }
        
        std::string line;
        std::list<std::string> newText;
        while (std::getline(input, line)) {
            std::string delimiter = " ";
            size_t delimiterPosition = line.find(delimiter);
            std::string token;
            while (!line.empty()) {
                if (delimiterPosition != std::string::npos) {
                    token = line.substr(0, delimiterPosition);
                    line.erase(0, delimiterPosition + delimiter.length());
                    delimiterPosition = line.find(delimiter);
                } else {
                    token = line;
                    line = "";
                }
                newText.push_back(token);
            }
            newText.emplace_back("\n");
        }
        return newText;
    }
    
    Common::BlockType ReadFile::getType() {
        return Common::BlockType::IN;
    }
}