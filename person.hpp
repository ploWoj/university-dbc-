#pragma once
#include <string>

#include "address.hpp"

enum class Sex
{
    Femel,
    Male,
    Other
};

enum class PersonType
{
    Student,
    Employee
};

class Person
{

    Person(PersonType type, std::string firstName, std::string secondName, std::string pesel, Address address, Sex sex);

    virtual ~Person();

    // getters

    PersonType getPersonType() const;
    std::string getFirstName() const;
    std::string getSecondName() const;
    std::string getPesel() const;
    std::string getAddress() const;
    std::string getPostalCode() const;
    std::string getCity() const;
    std::string getStreetAndNumber() const;

    Sex getSex() const;
    virtual size_t getSalary() const = 0;
    virtual size_t getIndexNumber() const = 0;
    virtual void setSalary(const size_t &newSalary) = 0;

    const Address &getAddress();

public:
    PersonType type_;
    std::string firstName_;
    std::string secondName_;
    std::string pesel_;
    Address address_;
    Sex sex_;
};