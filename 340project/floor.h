//
// Created by Subhan Khan on 12/10/23.
//

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

    // Additional methods if necessary...
};

#endif // FLOOR_H