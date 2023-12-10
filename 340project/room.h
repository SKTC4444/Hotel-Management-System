#ifndef INC_340PROJECT_ROOM_H
#define INC_340PROJECT_ROOM_H

#include "guest.h"  // Include the Guest class header

class Room {
private:
    int roomNumber;
    Guest* guest; // Pointer to a guest object

public:
    Room(int roomNumber); // Constructor with room number
    ~Room(); // Destructor

    void assignGuest(Guest* guest); // Assign a guest to the room
    void vacate(); // Vacate the room
    bool isOccupied() const; // Check if the room is occupied
    Guest* getGuest() const; // Get the guest in the room
    int getRoomNumber() const; // Get the room number
    void setGuest(Guest* newGuest);

    // Additional methods if necessary...
};

#endif // ROOM_H