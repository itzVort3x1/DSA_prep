#include<iostream>
#include<vector>
using namespace std;

enum class ProductType { DRINK, SNACK};

class Product {
    private:
        string name;
        string id;
        string price;
        ProductType type;
    public:
        Product(string name, string id, string price, ProductType type);
};

class Transaction {
    private:
        double amount;
        Product product;
    public:
        Transaction(double amount, Product product);

        int checkPrice(Product product);
};

class Inventory {
    private:
        int id;
        vector<vector<Product>> mapping; 
    public:
        Inventory(int id, Product product);
        Product* findProduct(int id);
};

class VendingMachine {
    private:
        double moneyAccepted;
        Product selectedProduct;
    public:
        VendingMachine(double moneyAccepted);

        void selectProduct(int productId);
        void dispenseProduct();
        void insertMoney(double amount);
        void createTransaction();
        void cancelTransaction();
};

int main() {

}