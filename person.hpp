#pragma once
#include <iostream>
#include <string>

// enum class Sex
// {
//     Femel,
//     Male,
//     Other
// };

class Person
{
public:
    Person() = default;
    Person(std::string name, std::string surname, std::string pesel, std::string address, std::string sex);
    virtual ~Person() = default;

    // getters
    std::string getName() const;
    std::string getSurname() const;
    std::string getPesel() const;
    std::string getAddress() const;
    std::string getSex() const;
    virtual double getSalary() const = 0;
    virtual void display() = 0;    

    // setters
    void setName(const std::string&);
    void setSurname(const std::string&);
    void setAddress(const std::string&);
    void setPesel(const std::string&);
    void setSex(const std::string&);
private:    
    std::string name_;
    std::string surname_;
    std::string pesel_;
    std::string address_;
    std::string sex_;
};