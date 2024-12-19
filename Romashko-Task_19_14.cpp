#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

void readFileAndDisplay(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file");
    }

    std::vector<int> numbers;
    std::string line;
    while (std::getline(file, line)) {
        try {
            numbers.push_back(std::stoi(line));
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid data in file: " << line << std::endl;
            continue;
        }
    }

    std::cout << "Numbers in original order:" << std::endl;
    for (const int &num : numbers) {
        std::cout << num << std::endl;
    }
}

int main() {
    try {
        readFileAndDisplay("numbers_19_14.txt");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
