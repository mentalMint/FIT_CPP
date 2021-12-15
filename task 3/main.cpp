#include <iostream>
#include <fstream>
#include <string>
#include "WorkflowExecutor.h"

int main() {
    std::fstream in("input.txt");
    WorkflowExecutor executor;
    executor.executeWorkflow(in);
    return 0;
}
