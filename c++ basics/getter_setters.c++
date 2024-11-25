#include<iostream>
using namespace std;

class Stove {
    private:
        int temp = 0;

    public:
        Stove(int temp){
            settemp(temp);
        }
        int gettemp() {
            return temp;
        }

        void settemp(int val) {
            if(val < 0){
                this->temp = 0;
            }else if(val >= 10){
                this->temp = 10;
            }else {
                this->temp = val;
            }
        }
    
};

int main() {
    Stove stove(3);

    cout << "The temp is: " << stove.gettemp() << endl;

    return 0;
}