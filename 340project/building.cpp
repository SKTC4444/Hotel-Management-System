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

void Building::addElevator(const Elevator& elevator) {
    elevators.insert(elevator); // Assuming LinkedList has an insert method
}

void Building::addGuest(const Guest& guest) {
    guests.insert(guest); // Assuming LinkedList has an insert method
}

Guest* Building::searchGuestByName(const std::string& name) {
    // Iterate through the linked list of guests to find the guest by name
    for (auto& guest : guests) {
        if (guest.getName() == name) { // Assuming Guest has a getName method
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

// Implement other necessary methods...