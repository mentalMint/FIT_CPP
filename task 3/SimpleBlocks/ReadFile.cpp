#include "ReadFile.h"
#include <fstream>

namespace SimpleBlocks {
    static Common::BlockMaker<ReadFile> maker("readfile");
    
    std::list<std::string> ReadFile::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw Exception("insufficient arguments for readfile");
        } else if (args.size() > 1) {
            throw Exception("too much arguments for readfile");
        }
        
        std::fstream input(args[0]);
        std::string line;
        std::list<std::string> newText;
        while (std::getline(input, line, '\n')) {
            std::string delimiter = " ";
            size_t delimiterPosition = line.find(delimiter);
            std::string token = "";
            while (line != "\0") {
                if (delimiterPosition != line.npos) {
                    token = line.substr(0, delimiterPosition);
                    line.erase(0, delimiterPosition + delimiter.length());
                    delimiterPosition = line.find(delimiter);
                } else {
                    token = line;
                    line = "\0";
                }
                newText.push_back(token);
            }
            newText.push_back("\n");
        }
        return newText;
    }
    
    Common::BlockType ReadFile::getType() {
        return Common::BlockType::IN;
    }
}