#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> V1, V2;
    int n, val;
    
    std::cout << "Enter the number of elements for V1: ";
    std::cin >> n;
    std::cout << "Enter the elements for V1: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        V1.push_back(val);
    }
    
    std::cout << "Enter the number of elements for V2: ";
    std::cin >> n;
    std::cout << "Enter the elements for V2: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        V2.push_back(val);
    }

    std::multiset<int> resultSet;
    
    for (int num : V1) {
        resultSet.insert(num);
    }
    
    for (int num : V2) {
        resultSet.insert(num);
    }
    
    std::vector<int> resultVector(resultSet.begin(), resultSet.end());
    
    std::sort(resultVector.begin(), resultVector.end(), std::greater<int>());
    
    std::cout << "Result: ";
    for (int num : resultVector) {
        std::cout << num << " ";
    }
    
    return 0;
}
