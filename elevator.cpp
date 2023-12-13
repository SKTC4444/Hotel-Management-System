#include "elevator.h"

Elevator::Elevator() : currentFloor(0) {
    // Constructor implementation
}

Elevator::~Elevator() {
    // Destructor implementation
}

void Elevator::addPassenger(Guest* guest) {
    passengers.push_back(guest); // Add the guest to the list of passengers
}

void Elevator::removePassenger(Guest* guest) {
    // Remove the guest from the list of passengers
    passengers.erase(std::remove(passengers.begin(), passengers.end(),
                                 guest), passengers.end());
}

void Elevator::moveToFloor(int floor) {
    currentFloor = floor; // Update the current floor of the elevator
}

bool operator==(const Elevator& lhs, const Elevator& rhs) {
    return lhs.currentFloor == rhs.currentFloor;
}