#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>

std::vector<std::string> tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string word;
    while (ss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return std::ispunct(c); }), word.end());
        tokens.push_back(word);
    }
    return tokens;
}

int main() {
    std::ifstream file("text_13_24.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sentence = buffer.str();
    file.close();

    std::vector<std::string> words = tokenize(sentence);
    int totalCharacters = 0;

    for (const std::string& word : words) {
        totalCharacters += word.size();
    }

    std::cout << "Characters in each word and percentage of total characters:" << std::endl;
    for (const std::string& word : words) {
        double percentage = (double)word.size() / totalCharacters * 100;
        std::cout << "Word: " << word << ", Number of characters: " << word.size() << ", Percentage: " << percentage << "%" << std::endl;
    }

    std::cout << "Total number of characters in the sentence: " << totalCharacters << std::endl;

    return 0;
}
