#include <iomanip>

#include "menu.hpp"

void Menu::printMainMenu() const {
    uint8_t itemSize = 23;
    std::cout << std::left << std::setfill(' ');
    std::cout << std::setw(itemSize) << "[ 1] Print DB" << std::setw(itemSize) 
              << "[ 4] Sort by Pesel" << std::setw(itemSize)
              << "[ 7] Find by PEsel" << std::setw(itemSize)
              << "[10] Remove Person" << std::setw(itemSize)
              << '\n'
              << std::setw(itemSize) << "[ 2] Add Student" << std::setw(itemSize)
              << "[ 5] Sort by surname" << std::setw(itemSize)
              << "[ 8] Find surname" << std::setw(itemSize)
              << "[11] Save to file" << std::setw(itemSize)
              <<  std::setw(itemSize) << "[ 3] Add Employee" << std::setw(itemSize)
              << "[ 6] Sort by salary" << std::setw(itemSize)
              << "[ 9] Change salary" << std::setw(itemSize)
              << "[12] Read from file" << '\n';
}

void Menu::separator()
{
    std::cout << std::right << std ::setfill('-')
              << std::setw(typeColumnWidth + firstNameColumnWidth + lastNameColumnWidth + peselColumnWidth + addressColumnWidth + sexColumnWidth + indexNumberColumnWidth + salaryColumnWidth)
              << '\n';
    std::cout << std ::setfill(' ');
}

void Menu::printPanel(const std::string& message) {
    separator();
    std::cout << "Database size: " << db_.getDB().size() 
              << " | message: " << message << '\n';
    separator();
}