#include "guest.h"

Guest::Guest(const std::string& name) : Person(name), roomNumber(-1), floorNumber(-1) {
    // Constructor implementation
}

void Guest::assignRoom(int roomNum, int floorNum) {
    roomNumber = roomNum;
    floorNumber = floorNum;
}

int Guest::getRoomNumber() const {
    return roomNumber; // Return the assigned room number
}

int Guest::getFloorNumber() const {
    return floorNumber; // Return the assigned floor number
}

bool operator==(const Guest& lhs, const Guest& rhs) {
    // Define how two Guest objects are compared
    // For example, comparing based on name and room number
    return lhs.getName() == rhs.getName() && lhs.getRoomNumber() == rhs.getRoomNumber();
}

bool Guest::isCheckedIn() const {
    return checkIn;
}

void Guest::setCheckIn(bool checkIn) {
    Guest::checkIn = checkIn;
}
