#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Customer {
    private:
        string name;
        string contactInfo;
        string licenseNumber;
    public:
        Customer() {};
        Customer(string name, string contactInfo, string licenseNumber) {};
};

class IPaymentProcessor {
    public:
        virtual bool processPayment(double payment);
};

class CreditCardPaymentProcessor: public IPaymentProcessor {
    public:
        bool processPayment(double amount) override {};
};

class PayPalPaymentProcessor: public IPaymentProcessor {
    public:
        bool processPayment(double amount) override {};
};

class Reservation {
    private:
        string reservationId;
        Customer customer;
        Car car;
        double totalPrice;
    public:
        Reservation(string reservationId, Customer customer, Car car) {};

        Car getCar();
        double getTotalPrice();
        string getReservationId();
};

class Car {
    private:
        string make;
        string model;
        string licensePlate;
        double rentalPrice;
        bool isAvailable;
    public:
        Car() {};

        double getRentalPrice() {};
        string getLicensePlate() {};
        bool isAvailable() {};
        void setAvailability() {};
};

class CarRentalSystem {
    private:
        unordered_map<int, Customer> customers;
        unordered_map<int, Car> cars;
        unordered_map<int, Reservation> reservation;

    public:
        CarRentalSystem () {};

        void onBoardCustomer(Customer customer) {};
        void addCar(Car car);
        vector<Car> getAllCars() {};
};