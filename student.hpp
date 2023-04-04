#pragma once

#include "person.hpp"

class Student : public Person{
public:
    Student() = default;
    Student(const std::string& name,const std::string& surname,const std::string& address,const std::string& pesel,const std::string& sex, size_t indexNumber);
    ~Student() = default;

    void setIndexNumber(const size_t);

    size_t getIndexNumber() const;

    // Function override from class Person

    double getSalary() const override { return 0.0; }
    void display() override;

private:
    size_t indexNumber_;
};