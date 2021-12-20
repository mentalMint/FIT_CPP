#ifndef FACTORY_WORKFLOWPARSER_H
#define FACTORY_WORKFLOWPARSER_H

#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>

class WorkflowParser {
public:
    std::list<std::pair<std::string, std::vector<std::string>>> getBlocks(std::ifstream &in);
};


#endif //FACTORY_WORKFLOWPARSER_H
