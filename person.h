//
// Created by Subhan Khan on 12/10/23.
//

#ifndef INC_340PROJECT_PERSON_H
#define INC_340PROJECT_PERSON_H

#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& name); // Constructor with the person's name
    virtual ~Person(); // Virtual destructor for proper cleanup in derived classes

    std::string getName() const; // Get the person's name

    // Additional common methods and attributes...
};

#endif // PERSON_H
