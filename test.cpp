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