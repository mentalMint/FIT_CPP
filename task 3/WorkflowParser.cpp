#include "WorkflowParser.h"
#include <map>

std::map<int, std::pair<std::string, std::vector<std::string>>> getBlocksDescription(std::istream &in) {
    std::map<int, std::pair<std::string, std::vector<std::string>>> blocksDescription;
    std::string line;
    std::getline(in, line, '\n');
    if (line != "desc") {
        throw std::exception();
    }
    
    while (std::getline(in, line, '\n') && line != "csed") {
        int blockId;
        std::string delimiter = " ";
        size_t delimiterPosition = line.find(delimiter);
        std::string blockName = line.substr(0, delimiterPosition);
        line.erase(0, delimiterPosition + delimiter.length());
        delimiterPosition = line.find(delimiter);
        line.erase(0, delimiterPosition + delimiter.length());
        delimiterPosition = line.find(delimiter);
        std::string token = "";
        std::vector<std::string> blockParameters;
        while (line != "\0") {
            if (delimiterPosition != line.npos) {
                token = line.substr(0, delimiterPosition);
                line.erase(0, delimiterPosition + delimiter.length());
                delimiterPosition = line.find(delimiter);
            } else {
                token = line;
                line = "\0";
            }
            blockParameters.push_back(token);
        }
        
        std::pair<std::string, std::vector<std::string>> blockDescription(blockName, blockParameters);
        blocksDescription[blockId] = blockDescription;
    }
    return blocksDescription;
}

std::list<std::pair<std::string, std::vector<std::string>>> getWorkflowDescription(
        std::istream &in,
        std::map<int, std::pair<std::string, std::vector<std::string>>> blocksDescription
) {
    std::list<std::pair<std::string, std::vector<std::string>>> workflowDescription;
    std::string line;
    std::getline(in, line);
    std::string delimiter = " -> ";
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
        workflowDescription.push_back(blocksDescription[std::stoi(token)]);
    }
    return workflowDescription;
}

std::list<std::pair<std::string, std::vector<std::string>>> WorkflowParser::getBlocks(std::istream &in) {
    std::map<int, std::pair<std::string, std::vector<std::string>>> blocksDescription;
    blocksDescription = getBlocksDescription(in);
    return getWorkflowDescription(in, blocksDescription);
}
