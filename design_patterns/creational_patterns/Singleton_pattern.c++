// Ensures that a class has only one instance, and provide a global point of access to it.
// Use Case
// 1) Config Manager
// 2) Logger
// 3) Connection Pool
#include<iostream>
using namespace std;

class Singleton {
    private:
        static Singleton* instance;
        Singleton() { cout << "Instance crated\n"; }
    public:
        static Singleton* getInstance() {
            if(!instance){
                instance = new Singleton();
            }

            return instance;
        }

        void doSomething() {
            cout << "Singleton doing work\n";
        }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    s1->doSomething();

    cout << (s1 == s2 ? "Same instance\n" : "Different instances\n");
    return 0;
}