#include <iomanip>

#include "menu.hpp"

void Menu::printMainManu() const {
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

void Menu::mainManu()
{
    short choice = -1;
    std::string message = "Welcom. Choose an option.";
    std::cout << "\n..:: University database ::..\n";

    while (choice != 0) {
        printPanel(message);
        printMainManu();
        std::cout << " > ";
        std::cin >> choice;
        switch (static_cast<Order>(choice)) {
        case Order::PrintAll: {
            message = menuPrintAll();

        } break;
        case Order::AddStudent: {
            menuAddStudent();

        } break;
        case Order::AddEmployee: {
            menuAddEmployee();

        } break;
        case Order::SortByPesel: {
            message = menuSortByPesel();

        } break;
        case Order::SortBySurname: {
            message = menuSortBySurname();

        } break;
        case Order::SortBySalary: {
            message = menuSortBySalary();

        } break;
        case Order::FindByPesel: {
            message = menuFindByPesel();

        } break;
        case Order::FindBySurname: {
            message = menuFindBySurname();

        } break;
        case Order::ChangeSalary: {
            message = menuChangeSalary();

        } break;
        case Order::RemovePerson: {
            message = menuRemovePerson();
        } break;
        case Order::SaveToFile: {
            message = menuSaveToFile();
        } break;
        case Order::ReadFromFile: {
            message = menuLoadFromFile();

        } break;
        }
    }
}

std::string Menu::menuPrintAll() {
    if (db_.getDB().empty()) {
        printHeader();
        std::cout << "\n\n\tdatabase is empty. \n";
        std::cout << "\t\tAdd person[2] or read from a file[12]";
    } else {
        db_.displayDB();
    }
    return "Choose an option";
}

void Menu::printHeader()
{
    separator();
    std::cout << std::left;
    std::cout << std::setw(typeColumnWidth)
              << "type:" << std::setw(firstNameColumnWidth)
              << "first name:" << std::setw(lastNameColumnWidth)
              << "last name:" << std::setw(addressColumnWidth)
              << "address:" << std::setw(peselColumnWidth)
              << "PESEL:" << std::setw(sexColumnWidth)
              << "sex:" << std::setw(indexNumberColumnWidth)
              << "index num.:" << std::setw(sexColumnWidth) << "salary:" << '\n';
    separator();
}

void Menu::menuAddEmployee()
{
    std::string name;
    std::string surname;
    std::string address;
    double salary;
    std::string pesel;
    std::string gender;

    std::cout << "Give your name:";
    std::cin >> name;
    std::cout << "Give your surname:";
    std::cin >> surname;
    std::cout << "Give your city: ";
    std::cin >> address;
    std::cout << "Give your pesel:";
    std::cin >> pesel;
    std::cout << "Give your gender (woman/ man): ";
    std::cin >> gender;
    std::cout << "Give your salar: ";
    std::cin >> salary;
    db_.addEmployee(name, surname, address, pesel, gender, salary);
}

std::string Menu::menuSortByPesel()
{
    system("clear");
    db_.sortByPesel();
    return "Data base has been sorted by pesel.";
}
