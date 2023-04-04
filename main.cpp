#include "employee.hpp"
#include "menu.hpp"
#include "person.hpp"
#include "student.hpp"
#include "university.hpp"

int main() {
  University codersSchool;
  Menu menu(codersSchool);
  menu.mainManu();
  return 0;
}