#include "room.h"

Room::Room(int roomNumber) : roomNumber(roomNumber), guest(nullptr) {
    // Constructor implementation
}

Room::~Room() {
    // Destructor implementation
}

void Room::vacate() {
    guest = nullptr; // Vacate the room
}

bool Room::isOccupied() const {
    return guest != nullptr; // Check if the room is occupied
}

/*Guest* Room::getGuest() const {
    return guest; // Return the guest in the room
}
*/
int Room::getRoomNumber() const {
    return roomNumber; // Return the room number
}

void Room::setGuest(Guest* newGuest) {
    guest = newGuest; // Assign the new guest to the room
}

