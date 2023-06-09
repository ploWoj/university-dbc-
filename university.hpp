#pragma once

#include <array>
#include <memory>
#include <optional>
#include <vector>

#include "employee.hpp"
#include "student.hpp"

using DB = std::vector<std::unique_ptr<Person>>;
constexpr const size_t peselSize = 11;
constexpr const size_t weightNumbers = 10;

class University
{
public:
    University() = default;
    ~University() = default;

    const DB getDB() const;
    void displayDB();
    void addStudent(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel,const std::string &sex, size_t indexNumber);
    void addStudent();

    void addEmployee(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel,const std::string &sex, double salary);
    void addEmployee();
    Person *findBySurname(const std::string &surname);
    Person *findByPesel(const std::string &pesel);

    void modifySalary(double salary,const std::string &pesel);
    void sortByPesel();
    void sortBySurname();
    void ereaseByIndex(const size_t indexNumber, std::string message);
    void sortBySalary();

    // Save base to a file
    void importDatabase(const std::string &, bool &);
    // Load base from a file
    void exportDatabase(const std::string &, bool &);

    bool peselValidation(const std::string &pesel);
private:
    DB university_;
};