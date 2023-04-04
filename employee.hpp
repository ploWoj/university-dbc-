#pragma once

#include "person.hpp"

class Employee : public Person {
public:
    Employee() = default;
    Employee(const std::string& name,const std::string& surname,const std::string& address,const std::string& pesel,const std::string& sex, double salary);
    ~Employee();

    void setSalary(const double);
    double getSalary() const override;

    void display() override;
private:
    double salary_;
};