#include <iostream>
#include <fstream>
#include <map>
#include <list>

#ifndef TASK2_WORDCOUNT_H
#define TASK2_WORDCOUNT_H

class WordCount {
public:
    //  Opens file with name $input, counts frequencies of words in the file,
    //  then writes result into file with name $output in CSV format
    WordCount(const char* input, const char* output);

private:
    const char* input_file_;
    const char* output_file_;
    
    int word_count_ = 0;
    std::map<std::string, int> word_dict_;
    
    void ReadInputFile();
    
    void WriteOutputFile();
    
    void SplitBar(std::string bar);
};

#endif //TASK2_WORDCOUNT_H
