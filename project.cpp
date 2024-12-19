#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

struct Product {
    string name;
    float price;
    string country;
    unsigned int inStore : 1;
    unsigned int euStandard : 1;
    unsigned int productOfMonth : 1;
};

// void inputProduct(Product& product) {
//     cout << "Enter product name: ";
//     getline(cin, product.name);

//     cout << "Enter product price: ";
//     cin >> product.price;

//     cout << "Enter country of origin: ";
//     cin.ignore();
//     getline(cin, product.country);

//     cout << "Is the product in store? (1 for Yes, 0 for No): ";
//     cin >> product.inStore;

//     cout << "Does the product meet EU standards? (1 for Yes, 0 for No): ";
//     cin >> product.euStandard;

//     cout << "Is the product of the month? (1 for Yes, 0 for No): ";
//     cin >> product.productOfMonth;

//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
// }

void printProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        cout << "Name: " << product.name << ", Price: " << product.price
             << ", Country: " << product.country << ", In Store: " << product.inStore
             << ", EU Standard: " << product.euStandard
             << ", Product of the Month: " << product.productOfMonth << endl;
    }
}

void printNonEUProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        if (!product.euStandard) {
            cout << "Name: " << product.name << ", Price: " << product.price
                 << ", Country: " << product.country << endl;
        }
    }
}

bool isOdd(unsigned int number) {
    return number & 1;
}

bool isMultipleOfEight(unsigned int number) {
    return (number & 7) == 0;
}

struct DateTime {
    unsigned int day : 5;    // Дні: 0-31 (потрібно 5 біт)
    unsigned int month : 4;  // Місяці: 0-12 (потрібно 4 біт)
    unsigned int year : 12;  // Роки: 0-4095 (потрібно 12 біт)
    unsigned int hour : 5;   // Години: 0-23 (потрібно 5 біт)
    unsigned int minute : 6; // Хвилини: 0-59 (потрібно 6 біт)
    unsigned int second : 6; // Секунди: 0-59 (потрібно 6 біт)
};

int main() {
    vector<Product> products = {
        {"Product1", 10.0, "Ukraine", 1, 0, 1},
        {"Product2", 20.0, "Germany", 1, 1, 0},
        {"Product3", 15.0, "USA", 0, 0, 0},
        {"Product4", 25.0, "France", 1, 1, 1},
        {"Product5", 30.0, "Italy", 0, 1, 0}
    };

    printProducts(products);

    cout << "\nProducts not conforming to EU standards:" << endl;
    printNonEUProducts(products);

    unsigned int number1 = 7;
    cout << "\nNumber " << number1 << " is " << (isOdd(number1) ? "odd." : "even.") << endl;

    unsigned int number2 = 16;
    cout << "Number " << number2 << " is " << (isMultipleOfEight(number2) ? "a multiple of 8." : "not a multiple of 8.") << endl;

    DateTime dateTime = {15, 8, 2023, 14, 30, 45};
    cout << "\nDate and Time: " << dateTime.day << "/" << dateTime.month << "/" << dateTime.year
         << " " << dateTime.hour << ":" << dateTime.minute << ":" << dateTime.second << endl;

    return 0;
}