#include <iostream>
#include <string>
#include "building.h"
#include "clerk.h"
#include "guest.h"
#include "elevator.h"

void startScreen();
bool loginScreen();
void mainInterface();
Clerk clerkInstance("", nullptr);
Building hotel(5,20,20);


void startScreen(){
    std::cout << std::endl;
    std::cout << "Welcome to the Hotel Management System!" << std::endl;
    std::cout << "This program will simulate a hotel." << std::endl;
    std::cout << "The program will allow you to check in guests, assign rooms, and search for guests." << std::endl;
    std::cout << "The program will also simulate the guest using the elevator to go to their floor and enter their room." << std::endl;
    std::cout << "The program will also allow you to sort the guests alphabetically." << std::endl;
    std::cout << "The program will also allow you to vacate a room for a new guest." << std::endl;
    std::cout << "The program will also allow you to exit the program at any time." << std::endl;
    std::cout << "Please press enter to continue." << std::endl;
    std::cin.ignore();
}
bool loginScreen(){
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Sign-in" << std::endl;
    std::cout << "2. Exit" << std::endl;
    int userChoice;

    std::cin >> userChoice;
    switch (userChoice) {
        case 1: {
            std::cout << "Please enter your name: " << std::endl;
            std::string clerkName;
            std::cin >> clerkName;
            clerkInstance.setName(clerkName);
            clerkInstance.setAssignedBuilding(&hotel);
            std::cout << "Welcome " << clerkName << "!" << std::endl;
            //mainInterface();
            return true;
        }
        case 2:
            //exit
            std::cout << "Exiting the hotel management system." << std::endl;
            return false;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
            loginScreen();

    }
}

void mainInterface(){
    int userChoice;
    Elevator elevator;
    Guest guest("");
    while(userChoice != 6){
        std::cout << std::endl;
        std::cout << "Select an option:" << std::endl;
        std::cout << "1. Check-in a guest" << std::endl;
        std::cout << "2. Assign a room to a guest" << std::endl;
        std::cout << "3. Search for a guest" << std::endl;
        std::cout << "4. Sort guests alphabetically" << std::endl;
        std::cout << "5. Vacate a room for a new guest" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << std::endl;
        std::string guestName;
        std::cin >> userChoice;
        switch (userChoice) {
            case 1: {
                std::cout << "Please enter the name of the guest: " << std::endl;
                std::cin >> guestName;
                guest = Guest(guestName);
                if(hotel.isFull()){
                    std::cout << "The hotel is currently full. Please vacate a room before checking in: " << std::endl;
                    break;
                } else{
                    clerkInstance.checkInGuest(guest);
                    break;
                }
            }
            case 2:{
                std::cout << "Please enter the name of the guest: " << std::endl;
                std::cin >> guestName;
                LinkedList<Guest>& guestList = hotel.getGuestList();
                for (auto it = guestList.begin(); it != guestList.end(); ++it) {
                    Guest &currentGuest = *it;
                    if (currentGuest.getName() == guestName) {
                        currentGuest = guest;
                    }
                }
                if(hotel.isFull()){
                    std::cout << "The hotel is currently full. Please vacate a room before assigning a room: " << std::endl;
                    break;
                } else{
                    if(!guest.isCheckedIn()){
                        std::cout << guest.isCheckedIn() << std::endl;
                        std::cout << "Guest " << guestName << " has not been checked in. Please check in the guest before assigning a room: " << std::endl;
                        break;
                    }
                    std::cout << "Guest " << guestName << " has been assigned a room." << std::endl;
                    clerkInstance.assignRoomToGuest(guest);
                    // Simulate guest using the elevator to go to their floor
                    std::cout << "Guest " << guest.getName() << " enters the elevator." << std::endl;
                    elevator.addPassenger(&guest);
                    elevator.moveToFloor(guest.getFloorNumber());
                    std::cout << "Elevator reaches floor " << guest.getFloorNumber() << "." << std::endl;
                    elevator.removePassenger(&guest);

                    // Simulate guest entering their room
                    std::cout << "Guest " << guest.getName() << " exits the elevator and enters room " << guest.getRoomNumber() << std::endl;
                    break;
                }
            }
            case 3: {
                std::cout << "Please enter the name of the guest you wish to search for: " << std::endl;
                std::cin >> guestName;
                Guest guest(guestName);
                Guest* searchedGuest = hotel.searchGuestByName(guestName);
                if (searchedGuest) {
                    std::cout << "Found guest: " << searchedGuest->getName() << std::endl;
                    std::cout << "Floor " << searchedGuest->getFloorNumber() << std::endl;
                    std::cout << "Room Number:" << searchedGuest->getRoomNumber() << std::endl;
                } else {
                    std::cout << "Guest not found." << std::endl;
                }
                break;
            }
            case 4: {
                hotel.sortGuests();
                std::cout << "Guests sorted alphabetically." << std::endl;

                // Displaying sorted guest names with room numbers
                LinkedList<Guest> &guestList = hotel.getGuestList();
                std::cout << "Current guests in the hotel:" << std::endl;
                for (auto it = guestList.begin(); it != guestList.end(); ++it) {
                    Guest &currentGuest = *it;

                    if(currentGuest.getRoomNumber() == -1){
                        std::cout << currentGuest.getName() << " - no room assigned " << std::endl;
                    }
                    else{
                        std::cout << currentGuest.getName() << " - Room " << currentGuest.getRoomNumber() << std::endl;
                    }

                }
                break;
            }
            case 5:
                //vacate room
                hotel.vacateRoom();
                std::cout << "A room has been vacated." << std::endl;
                break;
            case 6:
                //exit
                std::cout << "Exiting the hotel management system." << std::endl;
                return;
                break;
        }
    }


}

int main() {
    startScreen();
    if (!loginScreen()){
        return 0;
    }
    mainInterface();

    /*
    // Create the building with floors and rooms
    //Building hotel;
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
    */
}