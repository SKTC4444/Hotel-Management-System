#include "clerk.h"
#include <iostream>
Clerk::Clerk(const std::string& name, Building* building) : Person(name), assignedBuilding(building) {
    // Constructor implementation
}

Clerk::~Clerk() {
    // Destructor implementation
}

void Clerk::checkInGuest(Guest& guest) {
    assignedBuilding->addGuest(guest);
}

void Clerk::assignRoomToGuest(Guest& guest) {
    bool roomAssigned = false;
    for (int i = 0; i < assignedBuilding->getNumberOfFloors(); ++i) {
        Floor& floor = assignedBuilding->getFloor(i);
        for (int j = 0; j < floor.getNumberOfRooms(); ++j) {
            Room* room = floor.getRoom(j);
            if (room && !room->isOccupied()) {
                int roomNumber = (i + 1) * 100 + j;
                guest.assignRoom(roomNumber, i + 1);
                room->setGuest(&guest);
                roomAssigned = true;
                break;
            }
        }
        if (roomAssigned) break;
    }
    if (!roomAssigned) {
        std::cout << "No available rooms for guest " << guest.getName() << std::endl;
    } else {
        // Update guest in LinkedList
        Guest* guestInList = assignedBuilding->searchGuestByName(guest.getName());
        if (guestInList) {
            guestInList->assignRoom(guest.getRoomNumber(), guest.getFloorNumber());
        }
    }
}

// Implement other necessary methods...