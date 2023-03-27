#include "person.hpp"

Person::Person(PersonType type, std::string firstName, std::string secondName, std::string pesel, Address address, Sex sex)
    : type_(type), firstName_(firstName), secondName_(secondName), pesel_(pesel), address_(address), sex_(sex){};

PersonType Person::getPersonType() const
{
    return type_;
}
std::string Person::getFirstName() const
{
    return firstName_;
}
std::string Person::getSecondName() const
{
    return secondName_;
}
std::string Person::getPesel() const
{
    return pesel_;
}
std::string Person::getAddress() const {
    return address_.getAddress();
}
std::string Person::getPostalCode() const {
    return address_.getPostalCode();
}
std::string Person::getCity() const {
    return address_.getCity();
}
std::string Person::getStreetAndNumber() const {
    return address_.getStreetAndNumber();
}

const Address& Person::getAddress() {
    return address_;
} 