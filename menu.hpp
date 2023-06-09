#pragma once

#include <iostream>

#include "university.hpp"

enum class Order
{
    PrintAll = 1,
    AddStudent,
    AddEmployee,
    SortByPesel,
    SortBySurname,
    SortBySalary,
    FindByPesel,
    FindBySurname,
    ChangeSalary,
    RemovePerson,
    SaveToFile,
    ReadFromFile,
};

constexpr const static uint8_t typeColumnWidth = 10;
constexpr const static uint8_t firstNameColumnWidth = 16;
constexpr const static uint8_t lastNameColumnWidth = 16;
constexpr const static uint8_t peselColumnWidth = 14;
constexpr const static uint8_t addressColumnWidth = 42;
constexpr const static uint8_t sexColumnWidth = 8;
constexpr const static uint8_t indexNumberColumnWidth = 12;
constexpr const static uint8_t salaryColumnWidth = 10;

constexpr const static size_t minSalary = 1500;
constexpr const static size_t maxSalary = 15000;

class Menu
{
public:
    Menu(University & db) : db_(db) {};

    void mainManu();
    void printMainManu() const;
    void printPanel(const std::string& message);
    void printHeader();
    void separator();
    void menuAddStudent();
    void menuAddEmployee();

    std::string menuPrintAll();
    std::string menuSortByPesel();
    std::string menuSortBySurname();
    std::string menuSaveToFile();
    std::string menuLoadFromFile();
    std::string menuSortBySalary();

    std::string menuFindByPesel();
    std::string menuFindBySurname();
    std::string menuChangeSalary();
    std::string menuRemovePerson();
   

private:
    University &db_;
    double validationSalary(double &);
    std::string validationPesele(std::string &);
};
