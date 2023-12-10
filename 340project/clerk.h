//
// Created by Subhan Khan on 12/10/23.
//

#ifndef INC_340PROJECT_CLERK_H
#define INC_340PROJECT_CLERK_H

#include "person.h"
#include "guest.h"
#include "building.h"

class Clerk : public Person {
private:
    Building* assignedBuilding; // Pointer to the building where the clerk works

public:
    Clerk(const std::string& name, Building* building); // Constructor with clerk's name and assigned building
    ~Clerk(); // Destructor

    void checkInGuest(Guest& guest); // Check in a guest
    void assignRoomToGuest(Guest& guest); // Assign a room to a guest

    // Additional methods and attributes if necessary...
};

#endif // CLERK_H
