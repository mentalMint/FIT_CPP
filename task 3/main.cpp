#include <string>
#include <iostream>
#include "WorkflowExecutor.h"
#include "Exceptions/Exception.h"

int main() {
    std::ifstream in("input.txt");
    WorkflowExecutor executor;
    try {
        executor.executeWorkflow(in);
    } catch (Exceptions::Exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
