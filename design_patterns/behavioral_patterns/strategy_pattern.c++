// Define a family of algorithms, encapsulate each one, and make them interchangeable.
// Use Case
// 1) Sorting strategies
// 2) Payment methods
// 3) AI behaviors in games

#include <iostream>
#include <functional>
using namespace std;

class ShoppingCart {
    function<void(int)> paymentMethod;
    public:
        ShoppingCart(function<void(int)> method) {
            this->paymentMethod = method;
        }

        void checkout(int amount) {
            paymentMethod(amount);
        }
};

void payWithCreditCard(int amount) {
    cout << "Paid $" << amount << " using Credit Card.\n";
}

void payWithPayPal(int amount) {
    cout << "Paid $" << amount << " using PayPal.\n";
}

int main() {
    ShoppingCart cart1(payWithCreditCard);
    ShoppingCart cart2(payWithPayPal);

    cart1.checkout(100);
    cart2.checkout(200);

    return 0;
}
