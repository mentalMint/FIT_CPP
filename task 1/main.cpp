#include "WordCount.h"
#include <iostream>

#define WRONG_INPUT_MSG "use: program.exe input_file_name.txt output_file_name.csv"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("%sorted_by_frequency\n", WRONG_INPUT_MSG);
        return EXIT_FAILURE;
    }
    const char* input_file = argv[1];
    const char* output_file = argv[2];
    
    WordCount wordCount(input_file, output_file);
    return 0;
}
