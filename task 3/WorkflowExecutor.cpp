#include "WorkflowExecutor.h"
#include "WorkflowParser.h"
#include "Block.h"

void printBlocks(const std::list<std::pair<std::string, std::vector<std::string>>> &blocks) {
    for (const auto &block : blocks) {
        std::cout << block.first;
        for (const auto& parameter : block.second) {
            std::cout << " " << parameter;
        }
        std::cout << std::endl;
    }
}

void checkBlocks(std::list<std::pair<Common::Block*, std::vector<std::string>>> blockObjects) {
    Common::BlockType previousBlockObjectType = Common::BlockType::OUT;
    for (auto blockObject : blockObjects) {
        Common::BlockType blockObjectType = blockObject.first->getType();
        if (
                (previousBlockObjectType == Common::BlockType::OUT &&
                 blockObjectType != Common::BlockType::IN) ||
                (previousBlockObjectType != Common::BlockType::OUT &&
                 blockObjectType == Common::BlockType::IN)
                ) {
            throw Exception("wrong block consequence");
        }
        previousBlockObjectType = blockObjectType;
    }
}

void WorkflowExecutor::executeWorkflow(std::istream &in) {
    WorkflowParser parser;
    auto blocks = parser.getBlocks(in);
    printBlocks(blocks);
    
    std::list<std::pair<Common::Block*, std::vector<std::string>>> blockObjects;
    for (auto block : blocks) {
        try {
            Common::Block* blockObject = Common::BlockFactory::getInstance().Create(block);
            blockObjects.emplace_back(blockObject, block.second);
        } catch (Exception &ex) {
            std::cerr << "Error : " << ex.what() << std::endl;
        }
    }
    try {
        checkBlocks(blockObjects);
    } catch (Exception &ex) {
        std::cerr << "Error : " << ex.what() << std::endl;
    }
    
    std::list<std::string> text;
    for (auto blockObject : blockObjects) {
        try {
            text = blockObject.first->execute(text, blockObject.second);
        } catch (Exception &ex) {
            std::cerr << "Error : " << ex.what() << std::endl;
        }
    }
}
