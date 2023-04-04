#include "employee.hpp"

Employee::Employee(const std::string& name,const std::string& surname,const std::string& address,const std::string& pesel,const std::string& sex, double salary) 
    : Person(name, surname, address, pesel, sex)
    , salary_(salary) {}

void Employee::setSalary(const double salary) {
    salary_ = salary;
}

double Employee::getSalary() const {
    return salary_;
}

void Employee::display() {
    std::cout << "Employee: " << Employee::getName() << ", " << Employee::getSurname() << ", " << Employee::getAddress() <<
            Employee::getPesel() << ", " << Employee::getSex() << ", " <<  salary_ << '\n';
}