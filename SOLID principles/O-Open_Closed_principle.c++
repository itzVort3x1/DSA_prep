#include<iostream>
#include<string>
using namespace std;

class PaymentProcessor {
    public:
        virtual void processPayment(double amout) = 0;
};

class CreditCardPaymentProcessor: public PaymentProcessor {
    public:
        void processPayment(double amount) override {
            cout << "Processing credit card payment of $: " << amount << endl;
        }
};

class PayPalPaymentProcess: public PaymentProcessor {
    public:
        void processPayment(double amount) override {
            cout << "Processing paypal payment of $: " << amount << endl;
        }
};

void processPayment(PaymentProcessor* processor, double amount){
    processor->processPayment(amount);
}

int main() {
    CreditCardPaymentProcessor creditCardProcessor;
    PayPalPaymentProcess payPalProcessor;

    processPayment(&creditCardProcessor, 100.00);
    processPayment(&payPalProcessor, 150.00);
}