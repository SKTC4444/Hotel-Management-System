#include "clerk.h"

Clerk::Clerk(const std::string& name, Building* building) : Person(name), assignedBuilding(building) {
    // Constructor implementation
}

Clerk::~Clerk() {
    // Destructor implementation
}

void Clerk::checkInGuest(Guest& guest) {
    // Check-in logic here
    // This might include adding the guest to the building's guest list, etc.
}

void Clerk::assignRoomToGuest(Guest& guest) {
    // Room assignment logic here
    // This could involve finding an available room and updating the guest's room information
}

// Implement other necessary methods...