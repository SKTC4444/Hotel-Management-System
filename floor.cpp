#include "floor.h"
#include "guest.h"
#include "elevator.h"

Floor::Floor() {
    // Initialize the floor with a predefined number of rooms
    for (int i = 0; i < 10; ++i) {
        rooms.emplace_back(i);
    }
}

Floor::~Floor() {
    // Destructor implementation (if needed)
}

void Floor::addRoom(const Room& room) {
    rooms.push_back(room);
}

Room* Floor::getRoom(int roomNumber){
    // Assuming room numbers are sequential and start from 0
    if (roomNumber >= 0 && roomNumber < rooms.size()) {
        return &rooms[roomNumber];
    }
    return nullptr; // Room not found
}

void Floor::addGuestToRoom(Guest& guest, int roomNumber) {
    Room* room = getRoom(roomNumber);
    if (room) {
        room->setGuest(&guest); // Pass the address of the non-const Guest reference
    }
}

int Floor::getNumberOfRooms() const {
    return rooms.size();
}

bool Floor::hasAvailableRoom() const {
    for (const auto& room : rooms) {
        if (!room.isOccupied()) {
            return true; // Found an unoccupied room
        }
    }
    return false; // No unoccupied rooms on this floor
}

