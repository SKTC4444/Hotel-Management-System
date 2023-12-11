#ifndef INC_340PROJECT_FLOOR_H
#define INC_340PROJECT_FLOOR_H

#include <vector>
#include "room.h"

class Floor {
private:
    std::vector<Room> rooms; // Vector to store rooms on the floor

public:
    Floor(); // Constructor to initialize the floor with rooms
    ~Floor(); // Destructor

    void addRoom(const Room& room); // Add a room to the floor
    Room* getRoom(int roomNumber); // Get a room by its number
    void addGuestToRoom(Guest& guest, int roomNumber); // Add a guest to a specific room
    bool hasAvailableRoom() const;
    int getNumberOfRooms() const; // New method to get the number of rooms on the floor
};

#endif // FLOOR_H