//------------------------------------
//      Moving average in a data stream
//------------------------------------

#include<iostream>
#include<queue>
using namespace std;

class MovingAverage {
    private:
        queue<int> window;
        int maxSize;
        double sum;
    public:
        MovingAverage(int size) {
            this->maxSize = size;
            sum = 0;
        }

        double next(int val) {
            sum += val;

            window.push(val);

            if(window.size() > maxSize) {
                sum -= window.front();
                window.pop();
            }

            return (double)sum/window.size();
        }
};

int main() {
    MovingAverage* m = new MovingAverage(3);
    cout << m->next(1) << endl;
    cout << m->next(10) << endl;
    cout << m->next(3) << endl;
    cout << m->next(5) << endl;

    return 0;
}
