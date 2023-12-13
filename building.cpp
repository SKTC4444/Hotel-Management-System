#include "building.h"

Building::Building() {
    // Constructor implementation (if needed)
}

Building::~Building() {
    // Destructor implementation (if needed)
}

void Building::addFloor(const Floor& floor) {
    floors.push_back(floor);
}

/*void Building::addElevator(const Elevator& elevator) {
    elevators.insert(elevator);
}
*/
void Building::addGuest(const Guest& guest) {
    guests.insert(guest);
}

Guest* Building::searchGuestByName(const std::string& name) {
    // Iterate through the linked list of guests to find the guest by name using linear search
    for (Guest& guest : guests) {
        if (guest.getName() == name) {
            return &guest;
        }
    }
    return nullptr; // Return null if guest not found
}

void Building::sortGuests() {
    // Bubble sort implementation to sort guests in the linked list by name
    bool swapped;
    do {
        swapped = false;
        Node<Guest>* current = guests.getHead(); // Assuming LinkedList has a getHead method
        while (current != nullptr && current->next != nullptr) {
            if (current->data.getName() > current->next->data.getName()) { // Assuming Guest has a getName method
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

int Building::getNumberOfFloors() const {
    return floors.size();
}

Floor& Building::getFloor(int index) {
    return floors[index];
}

/*Elevator& Building::getElevator(int index) {
    return elevators.get(index);
}
*/

bool Building::isFull() const {
    for (std::vector<Floor>::const_iterator floorIt = floors.begin(); floorIt != floors.end(); ++floorIt) {
        const Floor& floor = *floorIt;
        if (floor.hasAvailableRoom()) {
            return false; // Found a floor with an unoccupied room
        }
    }
    return true; // No unoccupied rooms in the entire building
}

LinkedList<Guest>& Building::getGuestList() {
    return guests;
}

void Building::vacateRoom() {
    for (std::vector<Floor>::iterator floorIt = floors.begin(); floorIt != floors.end(); ++floorIt) {
        Floor& floor = *floorIt;
        for (int i = 0; i < floor.getNumberOfRooms(); ++i) {
            Room* room = floor.getRoom(i);
            if (room && room->isOccupied()) {
                room->vacate(); // Vacate the room
                return;
            }
        }
    }
}

Building::Building(const int &numFloors, const int& numRooms, const int &capacity) : numFloors(numFloors), numRooms(numRooms), capacity(capacity) {
    if(numFloors < 0 || capacity < 0){
        throw std::invalid_argument("Invalid argument");
    }
    for (int i = 0; i < numFloors; i++) {
        Floor floor;
        for (int j = 0; j < numRooms/numFloors; j++) {
            int roomNumber = (i * 100) + j + 100;
            floor.addRoom(Room(roomNumber));
        }
        this->addFloor(floor);
    }
}



