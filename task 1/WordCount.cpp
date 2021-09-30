#include "WordCount.h"

WordCount::WordCount(const char* input, const char* output) {
    input_file_ = input;
    output_file_ = output;
    this->ReadInputFile();
    this->WriteOutputFile();
}

void WordCount::ReadInputFile() {
    std::ifstream in;
    in.open(input_file_);
    if (!in) {
        printf("open input file error\n");
        abort();
    }
    
    std::string bar;
    while (!in.eof()) {
        getline(in, bar);
        this->SplitBar(bar);
    }
    
    in.close();
}

void WordCount::WriteOutputFile() {
    std::ofstream out;
    out.open(output_file_);
    if (!out) {
        printf("open output file error\n");
        abort();
    }
    
    std::list<std::pair<std::string, int>> word_list;
    for (auto const &iterator : word_dict_) {
        word_list.insert(word_list.end(), iterator);
    }
    word_list.sort([]
                           (const std::pair<std::string, int> &p1,
                            const std::pair<std::string, int> &p2) {
        return p1.second > p2.second;
    });
    
    for (auto const &iterator : word_list) {
        double frequency = ((double) iterator.second / (double) word_count_) * 100;
        out.precision(2);
        out << iterator.first << ',' << iterator.second << ',' << frequency << "%" << std::endl;
    }
    out.close();
}

void WordCount::SplitBar(std::string bar) {
    int i = 0;
    while (bar[i] != '\0') {
        while (bar[i] < 1 || (bar[i] > 9 && bar[i] < 'A') || (bar[i] > 'Z' && bar[i] < 'a') || bar[i] > 'z') {
            i++;
        }
        std::string word;
        while ((bar[i] >= 1 && bar[i] <= 9) || (bar[i] >= 'A' && bar[i] <= 'Z') ||
               (bar[i] >= 'a' && bar[i] <= 'z')) {
            if (bar[i] >= 'A' && bar[i] <= 'Z') {
                word.push_back((char) (bar[i] + 'a' - 'A'));
            } else {
                word.push_back(bar[i]);
            }
            i++;
        }
        if (word_dict_.find(word) == word_dict_.end()) {
            word_dict_.insert(std::pair<std::string, int>(word, 1));
        } else {
            word_dict_[word] += 1;
        }
        word_count_++;
    }
}
