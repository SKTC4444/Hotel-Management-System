#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "guest.h"

class Elevator {
private:
    int currentFloor;
    std::vector<Guest*> passengers; // List of passengers in the elevator

public:
    Elevator(); // Constructor
    ~Elevator(); // Destructor

    void addPassenger(Guest* guest); // Add a passenger to the elevator
    void removePassenger(Guest* guest); // Remove a passenger from the elevator
    void moveToFloor(int floor); // Move the elevator to a specific floor

    // Overload the == operator for comparisons
    friend bool operator==(const Elevator& lhs, const Elevator& rhs);
};

// Overload the == operator
bool operator==(const Elevator& lhs, const Elevator& rhs);

#endif // ELEVATOR_H