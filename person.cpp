#include "person.hpp"


Person::Person(const std::string& name, const std::string& surname, const std::string& pesel, const std::string& address, const std::string& sex) 
    : name_(name)
    , surname_(name)
    , pesel_(pesel)
    , address_(address)
    , sex_(sex)
    {};

void Person::setName(const std::string& name)
{
    name_ = name;
}

void Person::setSurname(const std::string& surname)
{
    surname_ = surname;
}

void Person::setAddress(const std::string& address)
{
    address_ = address;
}

void Person::setPesel(const std::string& pesel)
{
    pesel_ = pesel;
}

void Person::setSex(const std::string& sex)
{
    sex_ = sex;
}

std::string Person::getName() const
{
    return name_;
}

std::string Person::getSurname() const
{
    return surname_;;
}

std::string Person::getAddress() const
{
    return address_;
}

std::string Person::getPesel() const
{
    return pesel_;
}

std::string Person::getSex() const
{
        return sex_;
}

void Person::display()
{
    std::cout << name_ << ", " << surname_ << ", " << address_ << ", " << pesel_
              << ", " << sex_ << '\n';
}