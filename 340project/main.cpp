#include <iostream>
#include <string>
#include "building.h"
#include "clerk.h"
#include "guest.h"
#include "elevator.h"

int main() {
    // Create the building with floors and rooms
    Building hotel;
    // Add floors and rooms to the hotel (assuming your Building class has methods for this)

    // Create an elevator and add it to the building
    Elevator elevator;
    // Add the elevator to the hotel (assuming your Building class has a method for this)

    // Create a clerk
    Clerk clerk("John Doe", &hotel);

    // Simulate interaction with a guest
    std::string guestName;
    std::cout << "Welcome to the hotel! Please enter your name: ";
    std::getline(std::cin, guestName);

    // Create a guest
    Guest guest(guestName);

    // Clerk checks in the guest and assigns a room
    clerk.checkInGuest(guest); // Assuming Clerk has this method
    clerk.assignRoomToGuest(guest); // Assuming Clerk has this method

    // Guest uses the elevator to go to their floor
    elevator.addPassenger(&guest); // Assuming Elevator has this method
    elevator.moveToFloor(guest.getFloorNumber()); // Assuming Guest has getFloorNumber method
    elevator.removePassenger(&guest); // Assuming Elevator has this method

    // Guest goes to their room
    // You can add logic here to simulate the guest going to their room

    return 0;
}