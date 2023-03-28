#include "student.hpp"

Student::Student(std::string name, std::string surname, std::string address, std::string pesel, Sex sex, size_t indexNumber)
    : Person(name, surname, address, pesel, sex),
        indexNumber_(indexNumber) {}

void Student::setIndexNumber(const size_t indexNumber) {
    indexNumber_ = indexNumber;
}

size_t Student::getIndexNumber() const {
    return indexNumber_;
}

void Student::display() {
    std::cout << "Student: " << Person::getName() << ", " << Person::getSurname() << ", " << Person::getAddress() << ", " <<
    Person::getPesel() << Person::getSex() << ", " << indexNumber_ << '\n';  
}