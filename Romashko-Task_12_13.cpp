#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double num;
    int k;

    std::cout << "Enter number num (-10000 <= num <= 10000): ";
    std::cin >> num;

    std::cout << "Enter number k (|k| < 10): ";
    std::cin >> k;

    double result = pow(num, k);

    std::cout << std::setprecision(20) << std::fixed;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
