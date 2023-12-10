#include "person.h"

Person::Person(const std::string& name) : name(name) {
    // Constructor implementation
}

Person::~Person() {
    // Destructor implementation
}

std::string Person::getName() const {
    return name; // Return the person's name
}

// Implement other necessary common methods...