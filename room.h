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


    void vacate(); // Vacate the room
    bool isOccupied() const; // Check if the room is occupied
    int getRoomNumber() const; // Get the room number
    void setGuest(Guest* newGuest);
};

#endif // ROOM_H