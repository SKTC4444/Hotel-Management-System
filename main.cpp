#include <iostream>
#include <string>
#include "building.h"
#include "clerk.h"
#include "guest.h"
#include "elevator.h"

int main() {
    // Create the building with floors and rooms
    Building hotel;
    for (int i = 0; i < 5; i++) {  // 5 floors
        Floor floor;
        for (int j = 0; j < 10; j++) {  // 10 rooms per floor
            int roomNumber = (i * 100) + j + 100;
            floor.addRoom(Room(roomNumber));
        }
        hotel.addFloor(floor);
    }

    // Create an elevator and add it to the building
    Elevator elevator;
    hotel.addElevator(elevator);

    // Create a clerk
    Clerk clerk("John Doe", &hotel);

    while (true) {
        if (hotel.isFull()) {
            std::string response;
            do {
                std::cout << "The hotel is currently full. Would you like to continue? (yes/no): ";
                std::getline(std::cin, response);
                if (response == "EXIT") {
                    std::cout << "Exiting the hotel management system." << std::endl;
                    return 0; // Exit the program
                }
            } while (response != "yes" && response != "no");

            if (response == "no") {
                std::cout << "Exiting the hotel management system." << std::endl;
                break; // Exit the loop
            }

            // Logic to vacate a room for a new guest
            hotel.vacateRoom();
        }

        // Simulate interaction with a guest
        std::string guestName;
        std::cout << "Welcome to the hotel! Please enter your name (or type 'EXIT' to exit): ";
        std::getline(std::cin, guestName);

        // Check for exit condition
        if (guestName == "EXIT") {
            std::cout << "Exiting the hotel management system." << std::endl;
            break;
        }

        // Create a guest
        Guest guest(guestName);

        // Clerk checks in the guest and assigns a room
        clerk.checkInGuest(guest);
        clerk.assignRoomToGuest(guest);

        // Announce room assignment
        std::cout << "Guest " << guest.getName() << " has been assigned to room " << guest.getRoomNumber() << std::endl;

        // Performing linear search
        Guest* searchedGuest = hotel.searchGuestByName(guestName);
        if (searchedGuest) {
            std::cout << "Found guest: " << searchedGuest->getName() << std::endl;
        } else {
            std::cout << "Guest not found." << std::endl;
        }

        // Performing bubble sort
        hotel.sortGuests();
        std::cout << "Guests sorted alphabetically." << std::endl;

        // Displaying sorted guest names with room numbers
        LinkedList<Guest>& guestList = hotel.getGuestList();
        std::cout << "Current guests in the hotel:" << std::endl;
        for (auto it = guestList.begin(); it != guestList.end(); ++it) {
            Guest& currentGuest = *it;
            std::cout << currentGuest.getName() << " - Room " << currentGuest.getRoomNumber() << std::endl;
        }

        // Simulate guest using the elevator to go to their floor
        std::cout << "Guest " << guest.getName() << " enters the elevator." << std::endl;
        elevator.addPassenger(&guest);
        elevator.moveToFloor(guest.getFloorNumber());
        std::cout << "Elevator reaches floor " << guest.getFloorNumber() << "." << std::endl;
        elevator.removePassenger(&guest);

        // Simulate guest entering their room
        std::cout << "Guest " << guest.getName() << " exits the elevator and enters room " << guest.getRoomNumber() << std::endl;
    }

    std::cout << "Exiting the hotel management system." << std::endl;
    return 0;
}