#include "university.hpp"

const DB University::getDB() const {
    return university_;
}

void University::displayDB() {
    for (const auto& person : university_) {
        person->display();
    }
}
