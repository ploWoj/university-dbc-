#include "employee.hpp"

Employee::Employee(std::string name, std::string surname, std::string address, std::string pesel, std::string sex, double salary) 
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