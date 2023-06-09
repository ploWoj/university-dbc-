#include <fstream>
#include <typeinfo>

#include "university.hpp"

#include <algorithm>
#include <cctype>

#include <utility>

const DB University::getDB() const
{
    return university_;
}

bool University(const std::string &pesel)
{
    if (pesel.size() != peselSize)
    {
        return false;
    }

    constexpr std::array<int, weightNumbers> weighsFactor{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    size_t checkSum{0};
    size_t number{0};

    for (size_t i = 0; i < weightNumbers; ++i)
    {
        if (!std::isdigit(pesel[i]))
        {
            return false;
        }

        number = pesel[i] - '0';
        checkSum = number * weighsFactor[i];
    }

    checkSum = checkSum % weightNumbers;

    if (checkSum != 0)
    {
        checkSum = weightNumbers - checkSum;
    }

    size_t lastNumber = pesel.back() - '0';

    return checkSum == lastNumber;
}

void University::displayDB()
{
    for (const auto &person : university_)
    {
        person->display();
    }
}

void University::addStudent(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel,const std::string &sex, size_t indexNumber)
{
    if (peselValidation(pesel))
    {
        university_.emplace_back(std::make_unique<Student>(name, surname, address, pesel, sex, indexNumber));
    }
    else
    {
        std::cout << "Wrong pesel!!!" << '\n';
    }
}

Person *University::findByPesel(const std::string &pesel)
{
    auto it = std::find_if(university_.cbegin(), university_.cend(), [&pesel](const std::unique_ptr<Person> &person)
                           { return person->getPesel() == pesel; });

    if (it == university_.cbegin())
    {
        return nullptr;
    }

    Person *person_ptr = it->get();

    return person_ptr;
}

Person *University::findBySurname(const std::string &surname)
{
    auto it = std::find_if(university_.cbegin(), university_.cend(), [&surname](const std::unique_ptr<Person> &person)
                           { return person->getSurname() == surname; });
    if (it == university_.cbegin())
    {
        return nullptr;
    }
    Person *person_pr = it->get();

    return person_pr;
}

void University::sortByPesel()
{
    std::sort(university_.cbegin(), university_.cend(), [](const std::unique_ptr<Person> &lhs, const std::unique_ptr<Person> &rhs)
              { return rhs->getPesel() < lhs->getPesel(); });
}

void University::sortBySurname()
{
    std::sort(university_.cbegin(), university_.cend(), [](const std::unique_ptr<Person> &lhs, const std::unique_ptr<Person> &rhs)
              { return rhs->getSurname() < lhs->getSurname(); });
}

void University::ereaseByIndex(const size_t indexNumber, std::string message)
{
    size_t i{0};
    for (const auto &el : university_)
    {
        if (auto s = dynamic_cast<Student *>(el.get()))
        {
            if (s->getIndexNumber() == indexNumber)
            {
                university_.erase(university_.begin() + i);
                message = "Remove succesfully";
                return;
            }
        }
        i++;
    }
    message = "No student with that index number in database!";
}


void University::addStudent(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel,const  std::string &sex, size_t indexNumber)
{
    if (peselValidation(pesel))
    {
        if (!findByPesel(pesel))
        {
            university_.emplace_back(std::make_unique<Student>(name, surname, address, pesel, sex, indexNumber));
        }
    }
    else
    {
        std::cout << "Wrong pesel number!\n";
    }
}

void University::addStudent()
{
    university_.emplace_back(std::make_unique<Student>());
}


void University::addEmployee(const std::string &name, const std::string &surname, const std::string &address, const std::string &pesel,const  std::string &sex, double salary)
{
    if (peselValidation(pesel))
    {
        if (!findByPesel(pesel))
        {
            university_.emplace_back(std::make_unique<Employee>(name, surname, address, pesel, sex, salary));
        }
    }
    else
    {
        std::cout << "Wrong pesel number";
    }
}

void University::addEmployee()
{
    university_.emplace_back(std::make_unique<Employee>());
}

void University::modifySalary(double salary,const std::string &pesel)
{
    auto person = findByPesel(pesel);
    if (!person)
    {
        std::cout << "Person with that person does not exists!\n";
        return;
    }
    if (Employee *e = dynamic_cast<Employee *>(person))
    {
        e->setSalary(salary);
    }
    else
    {
        std::cout << "ERROR! Student do not have salary!\n";
    }
}

std::optional<size_t> getSalaryIfIs(const std::unique_ptr<Person> &person)
{
    if (auto *employee = dynamic_cast<Employee *>(person.get()))
    {
        return employee->getSalary();
    }
    return std::nullopt;
}
void University::sortBySalary()
{
    std::sort(university_.cbegin(), university_.cend(),
              [](const std::unique_ptr<Person> &lhsPtr,
                 const std::unique_ptr<Person> &rhsPtr)
              {
                  return getSalaryIfIs(lhsPtr).value_or(0.0) > getSalaryIfIs(rhsPtr).value_or(0.0) || getSalaryIfIs(lhsPtr).value_or(0.0) == getSalaryIfIs(rhsPtr).value_or(0.0) && getSalaryIfIs(lhsPtr).value_or(0.0) < getSalaryIfIs(rhsPtr).value_or(0.0);
              });
}

void University::importDatabase(const std::string &fileName, bool &flag)
{
    std::fstream dataBase(fileName);
    std::string element;
    std::array<std::string, 7> rowLine{};
    if (dataBase.is_open())
    {
        while (dataBase.peek() != EOF)
        {
            for (size_t i = 0; i < rowLine.size(); ++i)
            {
                getline(dataBase, element, ',');
                rowLine[i] = element;
            }
            getline(dataBase, element, ',');
            rowLine[6] = element;
            if (rowLine[0] == "7Student")
            {
                addStudent(rowLine[1], rowLine[2], rowLine[3], rowLine[4], rowLine[5], std::stoi(rowLine[6]));
            }
            if (rowLine[0] == "8Employee")
            {
                addEmployee(rowLine[1], rowLine[2], rowLine[3], rowLine[4], rowLine[5], std::stod(rowLine[6]));
            }
        }
        dataBase.close();
        flag = true;
    }
    else
    {
        flag = false;
    }
}

void University::exportDatabase(const std::string &fileName, bool &flag)
{
    std::ofstream dataBase(fileName);
    dataBase.open(fileName);
    if (dataBase.is_open())
    {
        for (const auto &itPerson : university_)
        {
            dataBase << typeid(*itPerson).name() << itPerson->getName() << ", " << itPerson->getSurname() << ", " << itPerson->getAddress() << ", "
                     << itPerson->getPesel() << itPerson->getSex() << ",";
            if (auto itStudent = dynamic_cast<Student *>(itPerson.get()))
            {
                dataBase << itStudent->getIndexNumber() << '\n';
            }
            if (auto itEmployee = dynamic_cast<Employee *>(itPerson.get()))
            {
                dataBase << itEmployee->getSalary() << '\n';
            }
        }
        dataBase.close();
        flag = true;
    }
    else
    {
        flag = false;
    }
}