#include "WorkflowParser.h"
#include <map>
#include "Exceptions/WrongWorkflowDescription.h"

std::map<int, std::pair<std::string, std::vector<std::string>>> getBlocksDescription(std::ifstream &in) {
    std::map<int, std::pair<std::string, std::vector<std::string>>> blocksDescription;
    std::string line;
    
    std::getline(in, line);
    if (line != "desc") {
        std::cout << "line: " << line << std::endl;
        throw Exceptions::WrongWorkflowDescription("\"desc\" was expected");
    }
    
    while (std::getline(in, line) && line != "csed") {
        std::string delimiter = " ";
        size_t delimiterPosition = line.find(delimiter);
        int blockId = stoi(line.substr(0, delimiterPosition));
        line.erase(0, delimiterPosition + delimiter.length());
        delimiterPosition = line.find(delimiter);
        line.erase(0, delimiterPosition + delimiter.length());
        delimiterPosition = line.find(delimiter);
        std::string blockName;
        if (delimiterPosition != line.npos) {
            blockName = line.substr(0, delimiterPosition);
            line.erase(0, delimiterPosition + delimiter.length());
            delimiterPosition = line.find(delimiter);
        } else {
            blockName = line;
            line = "";
        }
        std::vector<std::string> blockParameters;
        while (!line.empty()) {
            std::string token;
            if (delimiterPosition != std::string::npos) {
                token = line.substr(0, delimiterPosition);
                line.erase(0, delimiterPosition + delimiter.length());
                delimiterPosition = line.find(delimiter);
            } else {
                token = line;
                line = "";
            }
            blockParameters.push_back(token);
        }
        
        std::pair<std::string, std::vector<std::string>> blockDescription(blockName, blockParameters);
        blocksDescription[blockId] = blockDescription;
    }
    if (line != "csed") {
        std::cout << "line: " << line << std::endl;
        throw Exceptions::WrongWorkflowDescription("\"csed\" was expected");
    }
    return blocksDescription;
}

std::list<std::pair<std::string, std::vector<std::string>>> getWorkflowDescription(
        std::ifstream &in,
        std::map<int, std::pair<std::string, std::vector<std::string>>> blocksDescription
) {
    std::list<std::pair<std::string, std::vector<std::string>>> workflowDescription;
    std::string line;
    std::getline(in, line);
    std::string delimiter = " -> ";
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
        workflowDescription.push_back(blocksDescription[std::stoi(token)]);
    }
    return workflowDescription;
}

std::list<std::pair<std::string, std::vector<std::string>>> WorkflowParser::getBlocks(std::ifstream &in) {
    std::map<int, std::pair<std::string, std::vector<std::string>>> blocksDescription;
    blocksDescription = getBlocksDescription(in);
    return getWorkflowDescription(in, blocksDescription);
}
