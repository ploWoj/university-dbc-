#include "student.hpp"

Student::Student(const std::string& name,const std::string& surname,const std::string& address,const std::string& pesel,const std::string& sex, size_t indexNumber)
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