#pragma once

#include "person.hpp"

class Employee : public Person {
public:
    Employee() = default;
    Employee(std::string name, std::string surname, std::string address, std::string pesel, Sex sex, double salary);
    ~Employee();
private:
    double salary_;
};