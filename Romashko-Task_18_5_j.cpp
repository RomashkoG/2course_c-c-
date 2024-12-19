#include <iostream>
#include <vector>

template <typename T>
class Масив {
public:
    std::vector<T> data;
    int size;

    Масив(std::vector<T> arr) : data(arr), size(arr.size()) {}

    void shellSort() {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i++) {
                T temp = data[i];
                int j;
                for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                    data[j] = data[j - gap];
                }
                data[j] = temp;
            }
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {12, 34, 54, 2, 3};
    Масив<int> масив(arr);

    std::cout << "Original array: ";
    масив.printArray();

    масив.shellSort();

    std::cout << "Sorted array: ";
    масив.printArray();

    return 0;
}
