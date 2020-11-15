#include <iostream>
#include <string>

#define max 100

// class declarations
class Guest {
public:
    char guestName[100];
    char guestAddress[100];
    char guestPhone[12];
    char fromDate[20];
    char toDate[20];
    float paymentAdvance;
    int bookingID;
};

class Room {
public:
    char type{};
    char size{};
    char ac{};
    int roomNumber{};
    int rent{};
    int status{};

    class Guest guest{};

    static class Room addRoom(int);

    void searchRoom(int i) const;

    //void deleteRoom();

    static void displayRoom(Room tempRoom);
};

class Room rooms[max];

int count = 0;

// adding a new room
Room Room::addRoom(int roomNumber) {
    class Room room;
    room.roomNumber = roomNumber;
    std::cout << "\nType AC/Non-AC (A/N) : ";
    std::cin >> room.ac;
    std::cout << "\nType Confort (S/N) : ";
    std::cin >> room.type;
    std::cout << "Type Size (B/S) : ";
    std::cin >> room.size;
    room.status = 0;

    std::cout << "Room added successfully!";
    return room;
}

void Room::searchRoom(int i) const {
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (rooms[i].roomNumber == roomNumber) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        std::cout << "Room Details\n";
        if (rooms[i].status == 0) {
            std::cout << "Room is available";
        } else if (rooms[i].status == 1) {
            std::cout << "Room is reserved";
            displayRoom(rooms[i]);
        }
    } else {
        std::cout << "Room not found";
    }
}

void Room::displayRoom(Room tempRoom) {
    std::cout << "\nRoom Number: \t" << tempRoom.roomNumber;
    std::cout << "\nType AC/Non-AC (A/N): " << tempRoom.ac;
    std::cout << "\nType Comfort (S/N): " << tempRoom.type;
    std::cout << "\nType Size (B/S): " << tempRoom.size;
    std::cout << "\nRent: " << tempRoom.rent;
}

// hotelManagement
class HotelManagement : protected Room {
public:
    static void checkIn();

    static void getAvailableRoom();

    void searchCustomer(char *pname);

    static void checkOut(int roomNumber);

    static void guestSummaryReport();
};

// room reservation
void HotelManagement::checkIn() {
    int i, found = 0, roomNumber;

    class Room room;
    std::cout << "\nEnter a room number: ";
    std::cin >> roomNumber;
    for (i = 0; i < count; ++i) {
        if (rooms[i].roomNumber == roomNumber) {
            found = 1;
            break;
        }
        if (rooms[i].status == 1) {
            std::cout << "Room is already booked";
        } else {
            std::cout << "\nEnter booking id: ";
            std::cin >> rooms[i].guest.bookingID;

            std::cout << "\nEnter Customer Name (First Name): ";
            std::cin >> rooms[i].guest.guestName;

            std::cout << "\nEnter address: ";
            std::cin >> rooms[i].guest.guestAddress;

            std::cout << "\nEnter Phone: ";
            std::cin >> rooms[i].guest.guestPhone;

            std::cout << "\nEnter from date: ";
            std::cin >> rooms[i].guest.fromDate;

            std::cout << "\nEnter to date: ";
            std::cin >> rooms[i].guest.toDate;

            std::cout << "\nEnter advance payment: ";
            std::cin >> rooms[i].guest.paymentAdvance;

            rooms[i].status = 1;
            std::cout << "Customer Successfully Checked-in...";
        }
    }
}

void HotelManagement::getAvailableRoom() {
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (rooms[i].status == 0) {
            displayRoom(rooms[i]);
            std::cout << "Press enter for the next room";
            found = 1;
            getchar();
        }
    }
    if (found == 0) {
        std::cout << "All the rooms are reserved";
        getchar();
    }
}

void HotelManagement::searchCustomer(char *pname) {
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (rooms[i].status == 1 && strcmp(rooms[i].guest.guestName, pname) == 0) {
            std::cout << "\nCustomer Name: " << rooms[i].guest.guestName;
            std::cout << "\nRoom Number: " << rooms[i].roomNumber;

            std::cout << "\n\nPress Enter for next record";
            found = 1;
            getchar();
        }
    }
    if (found == 0) {
        std::cout << "\nPearson Not found";
        getchar();
    }
}

void HotelManagement::checkOut(int roomNumber) {
    int found, days;
    float bill;
    for (int i = 0; i < count; ++i) {
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNumber) {
            found = 1;
            break;
        }
        if (found == 1) {
            std::cout << "\nEnter the number of days: \t";
            std::cin >> days;
            bill = days * rooms[i].rent;

            std::cout << "\n\t ==== CHECKOUT DETAILS: ====\n";
            std::cout << "\nCustomer Name: " << rooms[i].guest.guestName;
            std::cout << "\nRoom Number: " << rooms[i].roomNumber;
            std::cout << "\nAddress: " << rooms[i].guest.guestAddress;
            std::cout << "\nPhone: " << rooms[i].guest.guestPhone;
            std::cout << "\nTotal Amount: " << bill << " /";
            std::cout << "\nAdvance Paid: " << rooms[i].guest.paymentAdvance << " /";
            std::cout << "\n*** Totale: " << bill - rooms[i].guest.paymentAdvance << " /only";

            rooms[i].status = 0;
        }
    }
    getchar();
}

void HotelManagement::guestSummaryReport() {
    if (count == 0) {
        std::cout << "No guests in the hotel";
    }
    for (int i = 0; i < count; ++i) {
        if (rooms[i].status == 1) {
            std::cout << "\n Customer First Name: " << rooms[i].guest.guestName;
            std::cout << "\n Room Number: " << rooms[i].roomNumber;
            std::cout << "\n Address (city only): " << rooms[i].guest.guestAddress;
            std::cout << "\n Phone: " << rooms[i].guest.guestPhone;
            std::cout << "\n ------------------------------------";
        }
    }

}

void manageRooms() {
    class Room room;
    int opt, roomNumber, flag = 0;
    char choise;
    do {
        std::cout << "\n === MANAGE ROOMS ===\n";
        std::cout << "\n1. Add room";
        std::cout << "\n2. Search Room";
        std::cout << "\n3. Back to the main menu";
        std::cout << "\n\nEnter option: ";
        std::cin >> opt;

        switch (opt) {
            case 1:
                std::cout << "\nEnter room number: ";
                std::cin >> roomNumber;
                for (int i = 0; i < count; ++i) {
                    if (rooms[i].roomNumber == roomNumber) {
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    std::cout << "\nRoom number is present. Please enter an unique number.";
                    flag = 0;
                    getchar();
                } else {
                    rooms[count] = room.addRoom(roomNumber);
                    count++;
                }
                break;
            case 2:
                std::cout << "\nEnter the room number: ";
                std::cin >> roomNumber;
                room.searchRoom(roomNumber);
                break;
            case 3:
                break;
            default:
                std::cout << "Enter a correct option";
        }
    } while (opt != 3);
}

int main() {
    HotelManagement hotelManagement;
    int option, roomNumber;
    char ch;
    char clientName[100];
    do {
        std::cout << "==== LUXURY HOTEL ====\n";
        std::cout << "\n1) Manage rooms";
        std::cout << "\n2) Check-In rooms";
        std::cout << "\n3) Available rooms";
        std::cout << "\n4) Search customer";
        std::cout << "\n5) Check-Out room";
        std::cout << "\n6) Guest Summary Report";
        std::cout << "\n7) Exit";
        std::cout << "\nEnter Option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                manageRooms();
                break;
            case 2:
                if (count == 0) {
                    std::cout << "Rooms data are not available. \nPlease add a valid room code";
                    break;
                } else
                    hotelManagement.checkIn();
                break;
            case 3:
                if (count == 0) {
                    std::cout << "Rooms data are not available. \nPlease add a valid room code";
                    break;
                } else
                    hotelManagement.getAvailableRoom();
            case 4:
                if (count == 0) {
                    std::cout << "Rooms data are not available. \nPlease add a valid room code";
                    break;
                } else {
                    std::cout << "Enter the customer name: ";
                    std::cin >> clientName;
                    hotelManagement.searchCustomer(clientName);
                }
            case 5:
                if (count == 0) {
                    std::cout << "Rooms data are not available. \nPlease add a valid room code";
                    break;
                } else {
                    std::cout << "Enter the room number: ";
                    std::cin >> roomNumber;
                    hotelManagement.checkOut(roomNumber);
                    break;
                }
            case 6:
                hotelManagement.guestSummaryReport();
                break;
            case 7:
                std::cout << "Thank you for using this software!";
                break;
            default:
                std::cout << "Please enter a valid option";
        }
    } while (option != 7);
    return 0;
}
