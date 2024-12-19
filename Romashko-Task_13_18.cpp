#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <unordered_set>

bool hasDoubleConsonant(const std::string& word) {
    std::unordered_set<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
                                           'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (consonants.count(tolower(word[i])) && word[i] == word[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream file("text_13_18.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open the file." << std::endl;
        return 1;
    }

    std::string word;
    int totalWords = 0;
    int doubleConsonantWords = 0;
    while (file >> word) {
        std::stringstream cleanedWord;
        for (char ch : word) {
            if (isalpha(ch)) {
                cleanedWord << ch;
            }
        }
        std::string cleaned = cleanedWord.str();
        if (!cleaned.empty()) {
            ++totalWords;
            if (hasDoubleConsonant(cleaned)) {
                ++doubleConsonantWords;
            }
        }
    }

    file.close();

    std::cout << "Total words: " << totalWords << std::endl;
    std::cout << "Words with double consonants: " << doubleConsonantWords << std::endl;
    if (totalWords > 0) {
        double percentage = (double(doubleConsonantWords) / totalWords) * 100;
        std::cout << "Percentage of words with double consonants: " << percentage << "%" << std::endl;
    } else {
        std::cout << "No words found in the text." << std::endl;
    }

    return 0;
}