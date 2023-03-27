#include "address.hpp"

Address::Address(std::string postCode, std::string city, std::string streetAndNumber) 
        : postalCode_(postCode)
        , city_(city)
        , streetAndNumber_(streetAndNumber)
        {};

std::string Address::getAddress() const {
    return city_ + ' ' + streetAndNumber_ + ' ' + postalCode_;
}

std::string Address::getCity() const {
    return city_
}

std::string Address::getPostalCode() const {
    return postalCode_;
}

std::string Address::getStreetAndNumber() const {
    return streetAndNumber_;
}

bool Address::operator==(const Address& other) const {
    return postalCode_ == other.postalCode_ && city_ == other.city_ && 
           streetAndNumber_ == other.streetAndNumber_;
}