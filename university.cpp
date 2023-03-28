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

Person* University::findByPesel(const std::string& pesel) {
    auto it = std::find_if(university_.cbegin(), university_.cend(), [&pesel](const std::unique_ptr<Person>& person) { return person->getPesel() == pesel; });

    if (it == university_.cbegin()) {
        return nullptr;
    }

    Person* person_ptr = it->get();
    
    return person_ptr;
}

Person* University::findBySurname(const std::string& surname) {
    auto it = std::find_if(university_.cbegin(), university_.cend(), [&surname](const std::unique_ptr<Person>& person) { return person->getSurname() == surname; });
    if (it == university_.cbegin()) {
        return nullptr;
    }
    Person* person_pr = it->get();

    return person_pr;
}

void University::sortByPesel() {
    std::sort(university_.cbegin(), university_.cend(), [](const std::unique_ptr<Person>& lhs, const std::unique_ptr<Person>& rhs) { return rhs->getPesel() < lhs->getPesel(); });
}

void University::sortBySurname() {
    std::sort(university_.cbegin(), university_.cend(), [](const std::unique_ptr<Person>& lhs, const std::unique_ptr<Person>& rhs) { return rhs->getSurname() < lhs->getSurname(); });
}

void University::ereaseByIndex(const size_t indexNumber, std::string message) {
    size_t i{0};
    for (const auto& el : university_) {
        if (auto s = dynamic_cast<Student*>(el.get())) {
            if (s->getIndexNumber() == indexNumber) {
                university_.erase(university_.begin() + i);
                message = "Remove succesfully";
                return;
            }
        }
        i++;
    }
    message = "No student with that index number in database!";
}

void University::addStudent() {
    university_.emplace_back(std::make_unique<Student>());
}

void University::addStudent(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel, Sex &sex, size_t indexNumber) {
    if (peselValidation(pesel)) {
        if (!findByPesel(pesel)) {
            university_.emplace_back(std::make_unique<Student>(name, surname, address, pesel, sex, indexNumber));
        }
    } else {
        std::cout << "Wrong pesel number!\n";
    }
}

void University::addEmployee() {
    university_.emplace_back(std::make_unique<Employee>());
}

void University::addEmployee(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel, Sex &sex, size_t salary) {
    if (peselValidation(pesel)) {
        if (!findByPesel(pesel)) {
            university_.emplace_back(std::make_unique<Employee>(name, surname, address, pesel, sex, salary));
        }
    } else {
        std::cout << "Wrong pesel number";
    }
}

