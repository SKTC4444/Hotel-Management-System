#ifndef INC_340PROJECT_BUILDING_H
#define INC_340PROJECT_BUILDING_H
#include <string>
#include <vector>
#include "floor.h"
#include "elevator.h"
#include "guest.h"
#include "linkedlist.h"

class Building {
private:
    std::vector<Floor> floors;
    LinkedList<Elevator> elevators;
    LinkedList<Guest> guests;
public:
    Building(); // Constructor
    Building(const int& numFloors, const int& numRooms, const int& capacity);
    ~Building(); // Destructor

    void addFloor(const Floor& floor);
    void addGuest(const Guest& guest);
    Guest* searchGuestByName(const std::string& name); // Linear search
    void sortGuests(); // Bubble sort

    int getNumberOfFloors() const;
    Floor& getFloor(int index);
    bool isFull() const;
    LinkedList<Guest>& getGuestList();
    void vacateRoom();
};

#endif // BUILDING_H