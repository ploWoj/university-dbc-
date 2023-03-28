#pragma once 

#include <array>
#include <memory>
#include <vector>

#include "employee.hpp"
#include "student.hpp"

using  DB =  std::vector<std::unique_ptr<Person>>;
constexpr const size_t peselSize = 11;
constexpr const size_t weightNumbers = 10;

class University {
public:
    University() = default;
    ~University() = default;

    const DB getDB() const;
    void displayDB();
    void addStudent(const std::string& name, const std::string& surname, const std::string& address, const std::string& pesel, Sex& sex, size_t indexNumber);
//     Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres, nr indeksu, PESEL, płeć
// Dodawanie nowych studentów
// Wyświetlanie całej bazy danych - zrobione
// Wyszukiwanie po nazwisku
// Wyszukiwanie po numerze PESEL
// Sortowanie po numerze PESEL
// Sortowanie po nazwisku
// Usuwanie po numerze indeksu


private:
    bool peselValidation(const std::string& pesel);
    DB university_; 
};