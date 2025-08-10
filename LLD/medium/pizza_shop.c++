#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <sstream>
using namespace std;

// ---------- enums ----------
enum class Size { Small, Medium, Large };
enum class Topping { Cheese, Pepperoni, Mushrooms, Onions, Olives, Jalapenos, Chicken, Bacon };
enum class ExtraType { Side, Drink, Dessert };

// ---------- tiny helpers ----------
static string sizeToStr(Size s) {
    if (s == Size::Small) return "Small";
    if (s == Size::Medium) return "Medium";
    return "Large";
}
static string toppingToStr(Topping t) {
    switch (t) {
        case Topping::Cheese:    return "Cheese";
        case Topping::Pepperoni: return "Pepperoni";
        case Topping::Mushrooms: return "Mushrooms";
        case Topping::Onions:    return "Onions";
        case Topping::Olives:    return "Olives";
        case Topping::Jalapenos: return "Jalapenos";
        case Topping::Chicken:   return "Chicken";
        case Topping::Bacon:     return "Bacon";
    }
    return "";
}
static string money(int cents) {
    ostringstream os;
    os << (cents / 100) << "." << setw(2) << setfill('0') << (cents % 100);
    return os.str();
}

// ---------- simple value objects ----------
class Pizza {
    Size size_;
    vector<Topping> toppings_;
    int qty_;
public:
    Pizza(Size size, vector<Topping> toppings, int qty = 1)
        : size_(size), toppings_(std::move(toppings)), qty_(qty) {}

    Size size() const { return size_; }
    const vector<Topping>& toppings() const { return toppings_; }
    int qty() const { return qty_; }
};

class ExtraItem {
    ExtraType type_;
    string name_;
    int qty_;
public:
    ExtraItem(ExtraType type, string name, int qty = 1)
        : type_(type), name_(std::move(name)), qty_(qty) {}

    ExtraType type() const { return type_; }
    const string& name() const { return name_; }
    int qty() const { return qty_; }
};

// ---------- Catalog (source of truth for pricing) ----------
class Catalog {
    // prices are in cents
    unordered_map<Size, int> basePizzaPrice_ = {
        {Size::Small, 899}, {Size::Medium, 1199}, {Size::Large, 1499}
    };
    unordered_map<Topping, int> toppingPrice_ = {
        {Topping::Cheese,100},{Topping::Pepperoni,150},{Topping::Mushrooms,100},
        {Topping::Onions,75},{Topping::Olives,100},{Topping::Jalapenos,75},
        {Topping::Chicken,200},{Topping::Bacon,200}
    };
    unordered_map<string, int> sidePrice_ = {
        {"Garlic Bread",399},{"Fries",299}
    };
    unordered_map<string, int> drinkPrice_ = {
        {"Cola 500ml",199},{"Water 500ml",149}
    };
    unordered_map<string, int> dessertPrice_ = {
        {"Brownie",349},{"Ice Cream Cup",299}
    };
public:
    int priceOfPizza(const Pizza& p) const {
        int price = basePizzaPrice_.at(p.size());
        for (auto t : p.toppings()) price += toppingPrice_.at(t);
        return price; // per pizza
    }

    int priceOfExtra(const ExtraItem& e) const {
        if (e.type() == ExtraType::Side) {
            auto it = sidePrice_.find(e.name());
            return it == sidePrice_.end() ? 0 : it->second;
        }
        if (e.type() == ExtraType::Drink) {
            auto it = drinkPrice_.find(e.name());
            return it == drinkPrice_.end() ? 0 : it->second;
        }
        auto it = dessertPrice_.find(e.name());
        return it == dessertPrice_.end() ? 0 : it->second;
    }
};

// ---------- Order ----------
class Order {
    const Catalog& catalog_;
    vector<Pizza> pizzas_;
    vector<ExtraItem> extras_;
public:
    explicit Order(const Catalog& c) : catalog_(c) {}

    void addPizza(Size size, const vector<Topping>& tops, int qty = 1) {
        pizzas_.emplace_back(size, tops, qty);
    }
    void addExtra(ExtraType type, const string& name, int qty = 1) {
        extras_.emplace_back(type, name, qty);
    }

    int totalCents() const {
        int sum = 0;
        for (const auto& p : pizzas_)  sum += catalog_.priceOfPizza(p) * p.qty();
        for (const auto& e : extras_)  sum += catalog_.priceOfExtra(e) * e.qty();
        return sum;
    }

    void printReceipt() const {
        cout << "==== PIZZA SHOP RECEIPT ====\n";
        for (const auto& p : pizzas_) {
            cout << p.qty() << " x " << sizeToStr(p.size()) << " Pizza";
            const auto& tops = p.toppings();
            if (!tops.empty()) {
                cout << " [";
                for (size_t i = 0; i < tops.size(); ++i) {
                    cout << toppingToStr(tops[i]);
                    if (i + 1 < tops.size()) cout << ", ";
                }
                cout << "]";
            }
            int unit = catalog_.priceOfPizza(p);
            cout << " @ $" << money(unit) << " = $" << money(unit * p.qty()) << "\n";
        }
        for (const auto& e : extras_) {
            string label = (e.type() == ExtraType::Side) ? "Side" :
                           (e.type() == ExtraType::Drink) ? "Drink" : "Dessert";
            int unit = catalog_.priceOfExtra(e);
            cout << e.qty() << " x " << label << ": " << e.name()
                 << " @ $" << money(unit) << " = $" << money(unit * e.qty()) << "\n";
        }
        cout << "----------------------------\n";
        cout << "TOTAL: $" << money(totalCents()) << "\n";
        cout << "============================\n";
    }
};

// ---------- demo ----------
int main() {
    Catalog catalog;

    Order order(catalog);
    order.addPizza(Size::Medium, {Topping::Cheese, Topping::Pepperoni, Topping::Mushrooms}, 2);
    order.addPizza(Size::Large,  {Topping::Cheese, Topping::Chicken, Topping::Onions});
    order.addExtra(ExtraType::Side,   "Garlic Bread");
    order.addExtra(ExtraType::Drink,  "Cola 500ml", 2);
    order.addExtra(ExtraType::Dessert,"Brownie");

    order.printReceipt();
    return 0;
}
