#pragma once 

#include <memory>
#include <vector>

#include "employee.hpp"
#include "student.hpp"

using  DB =  std::vector<std::unique_ptr<Person>>;

class University {
public:
    University() = default;
    ~University() = default;

    const DB getDB() const;



private:
    DB university_; 
};