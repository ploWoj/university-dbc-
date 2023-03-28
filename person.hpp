#pragma once
#include <string>

enum class Sex
{
    Femel,
    Male,
    Other
};

class Person
{
    Person() = default;
    Person(std::string firstName, std::string secondName, std::string pesel, Address address, Sex sex);
    virtual ~Person() = default;

    // getters
    std::string getFirstName() const;
    std::string getSecondName() const;
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
    void setGender(const std::string&);
    virtual double setSalary() const = 0;
    virtual void display() = 0;
private:    
    std::string firstName_;
    std::string secondName_;
    std::string pesel_;
    std::string address_;
    Sex sex_;
};