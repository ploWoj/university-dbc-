#include "university.hpp"

#include <cctype>

const DB University::getDB() const {
    return university_;
}

bool University(const std::string& pesel) {
    if (pesel.size() != peselSize) {
        return false;
    }

    constexpr std::array<int,weightNumbers> weighsFactor  { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };

    size_t checkSum{0};
    size_t number{0};

    for (size_t i = 0; i < weightNumbers; ++i) {
        if (!std::isdigit(pesel[i])) {
            return false;
        }

        number = pesel[i] - '0';
        checkSum = number * weighsFactor[i];
    }

    checkSum = checkSum % weightNumbers;

    if (checkSum != 0) {
        checkSum = weightNumbers - checkSum;
    }

    size_t lastNumber = pesel.back() - '0';

    return checkSum == lastNumber;
}



void University::displayDB() {
    for (const auto& person : university_) {
        person->display();
    }
}
