#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>

#ifndef TASK2_WORDCOUNT_H
#define TASK2_WORDCOUNT_H

class WordCount {
public:
    // Opens file with name $input and does some shit
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
