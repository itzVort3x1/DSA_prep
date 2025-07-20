#include<iostream>
#include<string>
using namespace std;

class BreadBaker {
    public:
        void bakeBread(){
            cout << "Baking high-quality bread..." << endl;
        }
};

class InverntoryManager {
    public:
        void manageInventory () {
            cout << "Managing inventory..." << endl;
        }
};

class SupplyOrder {
    public:
        void orderSupplies() {
            cout << "Ordering supplies..." << endl;
        }
};

class CustomerService {
    public:
        void serveCustomer() {
            cout << "Serving customers..." << endl;
        }
};

class BakeryCleaner {
    public:
        void clearBakery() {
            cout << "Cleaning the bakery..." << endl;
        }
};

int main (){
    BreadBaker baker;
    InverntoryManager manager;
    SupplyOrder supplier;
    CustomerService customerService;
    BakeryCleaner cleaner;

    baker.bakeBread();

    manager.manageInventory();

    supplier.orderSupplies();

    customerService.serveCustomer();

    cleaner.clearBakery();

    return 0;
}