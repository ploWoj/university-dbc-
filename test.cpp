#include <sstream>
#include <string>

#include "employee.hpp"
#include "student.hpp"
#include "university.hpp"
#include "catch_amalgamated.hpp"

SCENARIO("Class Student should get and set properties", "[student]") {
  GIVEN(
      "Create object of Student class Student(Alex, Test, City, 56073561722, "
      "man, 666666)") {
    Student* testStudent =
        new Student("Alex", "Test", "City", "56073561722", "man", 666666);
    AND_GIVEN("create expected name Alex") {
      std::string expected = "Alex";
      WHEN("Student should return name Alex by getName() method") {
        REQUIRE(testStudent->getName() == expected);
      }
    }
    AND_GIVEN("create expected surname Test") {
      std::string expected = "Test";
      WHEN("Student should return surname Test by getSurname() method") {
        REQUIRE(testStudent->getSurname() == expected);
      }
    }
    AND_GIVEN("create expected address City") {
      std::string expected = "City";
      WHEN("Student should return address City by getAddress() method") {
        REQUIRE(testStudent->getAddress() == expected);
      }
    }
    AND_GIVEN("create expected index 666666") {
      size_t expected = 666666;
      WHEN("Student should return index 666666 by getIndex() method") {
        REQUIRE(testStudent->getIndexNumber() == expected);
      }
    }
    AND_GIVEN("create expected pesel 56073561722") {
      std::string expected = "56073561722";
      WHEN("Student should return pesel 56073561722 by getPesel() method") {
        REQUIRE(testStudent->getPesel() == expected);
      }
    }
    AND_GIVEN("create expected gender man") {
      std::string expected = "man";
      WHEN("Student should return gender man by getGender() method") {
        REQUIRE(testStudent->getSex() == expected);
      }
    }
    AND_GIVEN("create expected name Joe and set to student") {
      std::string expected = "Joe";
      testStudent->setName(expected);
      WHEN("Student should return name Joe by getName() method") {
        REQUIRE(testStudent->getName() == expected);
      }
    }
    AND_GIVEN("create expected surname Black and set to student") {
      std::string expected = "Black";
      testStudent->setSurname(expected);
      WHEN("Student should return surname Black by getSurname() method") {
        REQUIRE(testStudent->getSurname() == expected);
      }
    }
    AND_GIVEN("create expected address New York and set to student") {
      std::string expected = "New York";
      testStudent->setAddress(expected);
      WHEN("Student should return address  New York by getAddress() method") {
        REQUIRE(testStudent->getAddress() == expected);
      }
    }
    AND_GIVEN("create expected index 134546 and set to student") {
      size_t expected = 134546;
      testStudent->setIndexNumber(expected);
      WHEN("Student should return index 134546 by getIndex() method") {
        REQUIRE(testStudent->getIndexNumber() == expected);
      }
    }
    AND_GIVEN("create expected pesel 84091234651 and set to student") {
      std::string expected = "84091234651";
      testStudent->setPesel(expected);
      WHEN("Student should return pesel 84091234651 by getPesel() method") {
        REQUIRE(testStudent->getPesel() == expected);
      }
    }
    AND_GIVEN("create expected gender women and set to student") {
      std::string expected = "women";
      testStudent->setSex(expected);
      WHEN("Student should return gender women by getGender() method") {
        REQUIRE(testStudent->getSex() == expected);
      }
    }
  }
}
SCENARIO("Class Employee should get and set properties", "[employee]") {
  GIVEN(
      "Create object of Employee class Employe(Jonny, Cross, Moscov, "
      "56073561722, man, 6666.66)") {
    Employee* testEmployee =
        new Employee("Jonny", "Cross", "Moscov", "56073561722", "man", 6666.66);
    AND_GIVEN("create expected name Jonny") {
      std::string expected = "Jonny";
      WHEN("Employee should return name Jonny by getName() method") {
        REQUIRE(testEmployee->getName() == expected);
      }
    }
    AND_GIVEN("create expected surname Cross") {
      std::string expected = "Cross";
      WHEN("Employee should return surname Cross by getSurname() method") {
        REQUIRE(testEmployee->getSurname() == expected);
      }
    }
    AND_GIVEN("create expected address Moscov") {
      std::string expected = "Moscov";
      WHEN("Employee should return address Moscov by getAddress() method") {
        REQUIRE(testEmployee->getAddress() == expected);
      }
    }
    AND_GIVEN("create expected salary 6666.66") {
      double expected = 6666.66;
      WHEN("Employee should return salary 6666.66 by getSalary() method") {
        REQUIRE(testEmployee->getSalary() == expected);
      }
    }
    AND_GIVEN("create expected pesel 56073561722") {
      std::string expected = "56073561722";
      WHEN("Employee should return pesel 56073561722 by getPesel() method") {
        REQUIRE(testEmployee->getSex() == expected);
      }
    }
    AND_GIVEN("create expected gender man") {
      std::string expected = "man";
      WHEN("Employee should return gender man by getGender() method") {
        REQUIRE(testEmployee->getSex() == expected);
      }
    }
    AND_GIVEN("create expected name Joe and set to employee") {
      std::string expected = "Joe";
      testEmployee->setName(expected);
      WHEN("Employee should return name Joe by getName() method") {
        REQUIRE(testEmployee->getName() == expected);
      }
    }
    AND_GIVEN("create expected surname Black and set to employee") {
      std::string expected = "Black";
      testEmployee->setSurname(expected);
      WHEN("Employee should return surname Black by getSurname() method") {
        REQUIRE(testEmployee->getSurname() == expected);
      }
    }
    AND_GIVEN("create expected address New York and set to employee") {
      std::string expected = "New York";
      testEmployee->setAddress(expected);
      WHEN("Employee should return address  New York by getAddress() method") {
        REQUIRE(testEmployee->getAddress() == expected);
      }
    }
    AND_GIVEN("create expected salary 55.55 and set to employee") {
      double expected = 55.55;
      testEmployee->setSalary(expected);
      WHEN("Employee should return salary 55.55 by getSalary()) method") {
        REQUIRE(testEmployee->getSalary() == expected);
      }
    }
    AND_GIVEN("create expected pesel 84091234651 and set to employee") {
      std::string expected = "84091234651";
      testEmployee->setPesel(expected);
      WHEN("Employee should return pesel 84091234651 by getPesel() method") {
        REQUIRE(testEmployee->getPesel() == expected);
      }
    }
    AND_GIVEN("create expected gender women and set to employee") {
      std::string expected = "women";
      testEmployee->setSex(expected);
      WHEN("Employee should return gender women by getGender() method") {
        REQUIRE(testEmployee->getSex() == expected);
      }
    }
  }
}