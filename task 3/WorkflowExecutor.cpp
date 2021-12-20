#include "WorkflowExecutor.h"
#include <memory>
#include "WorkflowParser.h"
#include "Common/Block.h"
#include "Exceptions/WrongWorkflowDescription.h"
#include "Exceptions/FileOpeningFail.h"

void printBlocks(const std::list<std::pair<std::string, std::vector<std::string>>> &blocks) {
    for (const auto &block : blocks) {
        std::cout << block.first;
        for (const auto &parameter : block.second) {
            std::cout << " " << parameter;
        }
        std::cout << std::endl;
    }
}

void checkBlocks(const std::list<std::pair<std::shared_ptr<Common::Block>, std::vector<std::string>>> &blockObjects) {
    Common::BlockType previousBlockObjectType = Common::BlockType::OUT;
    for (const auto &blockObject : blockObjects) {
        Common::BlockType blockObjectType = blockObject.first->getType();
        if (
                (previousBlockObjectType == Common::BlockType::OUT &&
                 blockObjectType != Common::BlockType::IN) ||
                (previousBlockObjectType != Common::BlockType::OUT &&
                 blockObjectType == Common::BlockType::IN)
                ) {
            throw Exceptions::WrongWorkflowDescription("wrong block consequence");
        }
        previousBlockObjectType = blockObjectType;
    }
}

void WorkflowExecutor::executeWorkflow(std::ifstream &in) {
    if (!in) {
        throw Exceptions::FileOpeningFail("workflow description file opening failed");
    }
    
    WorkflowParser parser;
    auto blocks = parser.getBlocks(in);
    printBlocks(blocks);
    
    std::list<std::pair<std::shared_ptr<Common::Block>, std::vector<std::string>>> blockObjects;
    for (const auto &block : blocks) {
        auto blockObject = Common::BlockFactory::getInstance().Create(block);
//            Common::Block* blockObject = Common::BlockFactory::getInstance().Create(block);
        blockObjects.emplace_back(blockObject, block.second);
    }
    checkBlocks(blockObjects);
    
    std::list<std::string> text;
    for (const auto &blockObject : blockObjects) {
            text = blockObject.first->execute(text, blockObject.second);
    }
}

