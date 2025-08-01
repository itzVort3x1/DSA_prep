#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Ingredient {
    private:
        string name;
        int quantity; // could be in ml or grams

    public:
        Ingredient(string name, int quantity);
        string getName() const;
        int getQuantity() const;
};

class Product {
    private:
        string name;
        int price;
        vector<Ingredient> ingredients;

    public:
        Product(string name, vector<Ingredient> ingredients);
        string getName() const;
        vector<Ingredient> getIngredients() const;
};

class ProductCatelog {
    private:
        unordered_map<string, Product> category;

    public:
        ProductCatelog() {};

        Product getProduct(string name) {};
        void addProduct(const Product& product);
        void removeProduct(const string& name);
        vector<string> listAllProducts() const;
};

class InventoryManager {
    private:
        unordered_map<string, Ingredient> quantities;

    public:
        bool isAvailable(Product product) {};
        void useIngredients(Product product);
        void refill(string ingredientName, int quantity);
        int getAvailableQuantity(string ingredientName) {};
};

class TransactionManager {
    private:
        int amountReceived;
    public:
        int getPrice(string name){};
        int acceptPayment(int amount) {};
        bool isPaymentSufficient(Product product) {};
        int calculateChange(Product product) {};
};

class CoffeeMachine {
    private:
        Product catalog;
        InventoryManager inventory;
        TransactionManager transaction;

    public:
        CoffeeMachine(Product catalog, InventoryManager inventory, TransactionManager transaction);

        void displayAvailableProducts() {};
        bool selectProduct(string productName) {};
        void insertMoney(int amount) {};
        bool dispenseProduct(string productName);
        void refillIngredient(string ingredientName, int quantity) {};
        void resetTransaction() {};
};

int main() {
    return 0;
}