#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

int main() {
    std::ifstream inputFile("numbers_14_15.txt");
    if (!inputFile) {
        std::cerr << "File did not open!" << std::endl;
        return 1;
    }

    std::string number;
    while (inputFile >> number) {
        int num = std::stoi(number);
        std::bitset<32> binary(num);
        std::cout << number << " in binary: " << binary << std::endl;
    }

    inputFile.close();
    return 0;
}
