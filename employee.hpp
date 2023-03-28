#pragma once

#include "person.hpp"

class Employee : public Person {
public:
    Employee() = default;
    Employee(std::string name, std::string surname, std::string address, std::string pesel, Sex sex, double salary);
    ~Employee();

    void setSalary(const double);
    double getSalary() const override;

    void display() override;
private:
    double salary_;
};