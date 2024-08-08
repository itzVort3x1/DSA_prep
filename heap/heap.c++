#include<iostream>
using namespace std;

class Heap {
     public:
          int *arr;
          int capacity;
          int size;

          Heap(int capacity) {
               size = 0;
               this->arr = new int[capacity];
               this->size = 0;
               this->capacity = capacity;
          }

          void insert(int val) {
               if(size == capacity){
                    cout << "Heap overflow" << endl;
                    return;
               }
               size++;
               int index = size;
               arr[index] = val;

               // take the val to its correct postition
               while(index > 1){
                    int parentIndex = index/2;
                    if(arr[index] > arr[parentIndex]){
                         swap(arr[index], arr[parentIndex]);
                         index = parentIndex;
                    }else {
                         break;
                    }
               }
          }

          void printHeap(){
               for(int i = 1; i<=size; i++){
                    cout << arr[i] << " ";
               }
          }
};

int main() {
     Heap h(20);
     h.insert(10);
     h.insert(20);
     h.insert(5);
     h.insert(11);
     h.insert(6);

     cout << "Printing the content of heap: " << endl;
     h.printHeap();

     return 0;
}