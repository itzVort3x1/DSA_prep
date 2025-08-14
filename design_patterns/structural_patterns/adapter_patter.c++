#include <iostream>
#include <string>
using namespace std;

// Target interface (what client expects)
class Printer {
public:
    virtual void printText(const string& text) = 0;
    virtual ~Printer() {}
};

// Adaptee (old class with a different method name)
class LegacyPrinter {
public:
    void printOld(const string& msg) {
        cout << "Legacy Printer: " << msg << endl;
    }
};

// Adapter (makes LegacyPrinter work with Printer interface)
class PrinterAdapter : public Printer {
private:
    LegacyPrinter* legacy;
public:
    PrinterAdapter(LegacyPrinter* lp) : legacy(lp) {}

    void printText(const string& text) override {
        legacy->printOld(text); // Translate call
    }
};

// Client code
int main() {
    LegacyPrinter oldPrinter;
    Printer* printer = new PrinterAdapter(&oldPrinter);

    printer->printText("Hello from Adapter Pattern!");

    delete printer;
    return 0;
}
