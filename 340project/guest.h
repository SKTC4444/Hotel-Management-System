#ifndef GUEST_H
#define GUEST_H

#include <string>
#include "person.h"

class Guest : public Person {
private:
    int roomNumber; // Room number assigned to the guest
    int floorNumber; // Floor number assigned to the guest

public:
    Guest(const std::string& name); // Constructor with guest's name

    void assignRoom(int roomNumber, int floorNumber); // Assign a room and floor to the guest
    int getRoomNumber() const; // Get the assigned room number
    int getFloorNumber() const; // Get the assigned floor number

    friend bool operator==(const Guest& lhs, const Guest& rhs); // Overload the == operator
};

// Overload the == operator
bool operator==(const Guest& lhs, const Guest& rhs);

#endif // GUEST_H