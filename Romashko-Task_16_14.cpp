#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

class Address {
public:
    std::string City;
    std::string Street;
    int HouseNumber;
    int ApartmentNumber;

    Address(std::string city, std::string street, int houseNumber, int apartmentNumber)
        : City(city), Street(street), HouseNumber(houseNumber), ApartmentNumber(apartmentNumber) {}
};

class InternationalAddress : public Address {
public:
    std::string Country;
    std::string PostalCode;

    InternationalAddress(std::string city, std::string street, int houseNumber, int apartmentNumber, std::string country, std::string postalCode)
        : Address(city, street, houseNumber, apartmentNumber), Country(country), PostalCode(postalCode) {}
};

int main() {
    std::vector<InternationalAddress> addresses = {
        InternationalAddress("Kyiv", "Khreshchatyk", 1, 1, "Ukraine", "01001"),
        InternationalAddress("Kyiv", "Khreshchatyk", 2, 2, "Ukraine", "01001"),
        InternationalAddress("Lviv", "Svobody", 3, 3, "Ukraine", "79000"),
        InternationalAddress("Kyiv", "Khreshchatyk", 4, 4, "Ukraine", "01001")
    };

    std::map<std::string, int> cityCount;
    for (const auto& address : addresses) {
        cityCount[address.City]++;
    }

    auto mostPopularCity = std::max_element(cityCount.begin(), cityCount.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second < b.second;
        })->first;

    std::ofstream outFile("addresses_16_14.txt");
    for (const auto& address : addresses) {
        if (address.City == mostPopularCity) {
            outFile << address.City << ", " << address.Street << ", " << address.HouseNumber << ", " 
                    << address.ApartmentNumber << ", " << address.Country << ", " << address.PostalCode << std::endl;
        }
    }

    outFile.close();
    return 0;
}
