#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Pizza {
    private:
        string size;
        vector<string> toppings;
        bool extraCheese = false;
        bool takeaway = false;

    public:
        void setSize(const string &s) {
            size = s;
        }

        void addTopping(const string &topping) {
            toppings.push_back(topping);
        }

        void setExtraCheese(bool ec) {
            extraCheese = ec;
        }

        void setTakeAway(bool t) {
            takeaway = t;
        }

        void showPizza() const {
            cout << "Pizza size: " << size << "\nToppings: ";
            for (const auto& t : toppings) cout << t << " ";
            cout << "\nExtra cheese: " << (extraCheese ? "Yes" : "No");
            cout << "\nTakeaway: " << (takeaway ? "Yes" : "No") << "\n";
        }
};

class PizzaBuilder {
    private:
        Pizza pizza;
    public:
        PizzaBuilder& size(const string s) {
            pizza.setSize(s);
            return *this;
        }

        PizzaBuilder addTopping(string topping) {
            pizza.addTopping(topping);
            return *this;
        }

        PizzaBuilder& extraCheese(bool ec) {
            pizza.setExtraCheese(ec);
            return *this;
        }

        PizzaBuilder& takeaway(bool t) {
            pizza.setTakeAway(t);
            return *this;
        }
        Pizza build() {
            return pizza; // returns the finished pizza
        }
};

int main() {
    Pizza myPizza = PizzaBuilder().size("Large").addTopping("Cheese").addTopping("Pepperoni").extraCheese(true).takeaway(false).build();

    myPizza.showPizza();
    return 0;
}