#include <iostream>
#include <stdexcept>
#include <cmath>

class ThreeByteInteger {
private:
    int value;
    static const int MAX = (1 << 23) - 1; // 2^23 - 1
    static const int MIN = -(1 << 23);    // -2^23

public:
    ThreeByteInteger(int v = 0) : value(v) {
        if (v > MAX || v < MIN) {
            throw std::out_of_range("Value out of three-byte range");
        }
    }

    void setValue(int v) {
        if (v > MAX || v < MIN) {
            throw std::out_of_range("Value out of three-byte range");
        }
        value = v;
    }

    int getValue() const {
        return value;
    }

    ThreeByteInteger operator+(const ThreeByteInteger& other) const {
        int result = value + other.value;
        if (result > MAX || result < MIN) {
            throw std::overflow_error("Addition overflow");
        }
        return ThreeByteInteger(result);
    }

    ThreeByteInteger operator-(const ThreeByteInteger& other) const {
        int result = value - other.value;
        if (result > MAX || result < MIN) {
            throw std::overflow_error("Subtraction overflow");
        }
        return ThreeByteInteger(result);
    }

    ThreeByteInteger operator*(const ThreeByteInteger& other) const {
        long long result = static_cast<long long>(value) * other.value;
        if (result > MAX || result < MIN) {
            throw std::overflow_error("Multiplication overflow");
        }
        return ThreeByteInteger(static_cast<int>(result));
    }

    ThreeByteInteger operator/(const ThreeByteInteger& other) const {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return ThreeByteInteger(value / other.value);
    }

    friend std::ostream& operator<<(std::ostream& os, const ThreeByteInteger& obj) {
        os << obj.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ThreeByteInteger& obj) {
        int temp;
        is >> temp;
        obj.setValue(temp);
        return is;
    }
};

int main() {
    try {
        ThreeByteInteger a(1 << 20);
        ThreeByteInteger b(2);
        ThreeByteInteger c = a + b;
        std::cout << "Sum: " << c << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
