#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

enum class ReservationStatus { CONFIRMED, CANCELLED };
enum class RoomType {SINGLE, DOUBLE, DELUX, SUITE};
enum class RoomStatus { AVAILABLE, BOOKED, OCCUPIED};

class IPayment {
    public:
        virtual void processPayment(double amount) {};
};

class CreditCardPayment: public IPayment {
    public:
        void processPayment(double amount);
};

class CashPayment: public IPayment {
    public:
        void processPayment(double amount);
};

class Guest {
    private:
        string id;
        string name;
        string email;
        string phoneNumber;
    public:
        Guest(string id, string name, string email, string phoneNumber) {};

        string getId();
        string getName();
        string getEmail();
        string getPhoneNumber();
};

class Room {
    private:
        string id;
        RoomType type;
        double price;
        RoomStatus status;
    public:
        Room(string id, RoomType type, double price) {};
        void book();
        void checkIn();
        void checkOut();
        string getId();
        RoomType getType();
        double getPrice();
        RoomStatus getStatus();
};

class Reservation {
    private:
        string id;
        Guest* guest;
        Room* room;
        string checkInDate;
        string checkOutDate;
        ReservationStatus reservationStatus;
    public:
        Reservation(string id, Guest guest, Room room, string checkInDate, string checkOutDate) {
            this->id = id;
            this->guest = &guest;
            this->room = &room;
            this->checkInDate = checkInDate;
            this->checkOutDate = checkOutDate;
            this->reservationStatus = ReservationStatus::CONFIRMED;
        }

        void cancel();
        Guest getGuest();
        Room getRoom();
        ReservationStatus getReservationStatus();
        void updateReservation(string checkInDate, string checkOutDate) {};
};

class HotelManagementSystem {
    private:
        HotelManagementSystem () {};
        static HotelManagementSystem* instance;
        unordered_map<string, Guest> guests;
        unordered_map<string, Room> rooms;
        unordered_map<string, Reservation> reservations;

    public:
        static HotelManagementSystem* getInstance() {
            if(instance == nullptr) {
                instance = new HotelManagementSystem();
            }
            return instance;
        }

        void addGuest(Guest guest) {};
        Guest getGuest(string guestId) {};
        void addRoom(Room room){};
        Room getRoom(string roomId){};

        Reservation bookRoom(Guest guest, Room room, string checkinDate, string checkoutDate) {};
        void cancelReservation(string reservationId);
};