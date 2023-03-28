#include "university.hpp"

#include <algorithm>
#include <cctype>

#include <utility>

const DB University::getDB() const
{
    return university_;
}

bool University(const std::string &pesel)
{
    if (pesel.size() != peselSize)
    {
        return false;
    }

    constexpr std::array<int, weightNumbers> weighsFactor{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    size_t checkSum{0};
    size_t number{0};

    for (size_t i = 0; i < weightNumbers; ++i)
    {
        if (!std::isdigit(pesel[i]))
        {
            return false;
        }

        number = pesel[i] - '0';
        checkSum = number * weighsFactor[i];
    }

    checkSum = checkSum % weightNumbers;

    if (checkSum != 0)
    {
        checkSum = weightNumbers - checkSum;
    }

    size_t lastNumber = pesel.back() - '0';

    return checkSum == lastNumber;
}

void University::displayDB()
{
    for (const auto &person : university_)
    {
        person->display();
    }
}

void University::addStudent(const std::string &name, const std::string &surname, const std::string &address, const std::string& pesel, Sex &sex, size_t indexNumber) {
    if (peselValidation(pesel)) {
        university_.emplace_back(std::make_unique<Student>(name, surname, address, pesel, sex, indexNumber));
    } else {
        std::cout << "Wrong pesel!!!" << '\n';
    }
}

// std::unique_ptr<Student> University::findByPesel(const std::string& pesel) {
//     auto find = std::find_if(university_.cbegin(), university_.cend(), [pesel](const std::unique_ptr<Student>& student) { return student->getPesel() == pesel; });

//     if (find == university_.cbegin()) {
//         return nullptr;
//     }

//     return std::move(find);
// }

std::optional<std::unique_ptr<Student>> findByPesel(const std::string& pesel) {
    std::optional<std::unique_ptr<Student>> ptr_out{};
    for (const auto& person : university) {
        if (person->getPesel() == pesel) {
            ptr_out = std::move(person);
            return ptr_out;
        } 
    }
    return ptr_out;
}
