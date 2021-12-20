#ifndef FACTORY_WORKFLOWEXECUTOR_H
#define FACTORY_WORKFLOWEXECUTOR_H

#include <fstream>

class WorkflowExecutor {
public:
    void executeWorkflow(std::ifstream &in);
};


#endif //FACTORY_WORKFLOWEXECUTOR_H
