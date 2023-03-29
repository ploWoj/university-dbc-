#pragma once

#include "person.hpp"

class Student : public Person{
public:
    Student() = default;
    Student(std::string name, std::string surname, std::string address, std::string pesel, std::string sex, size_t indexNumber);
    ~Student() = default;

    void setIndexNumber(const size_t);

    size_t getIndexNumber() const;

    // Function override from class Person

    double getSalary() const override { return 0.0; }
    void display() override;

private:
    size_t indexNumber_;
};