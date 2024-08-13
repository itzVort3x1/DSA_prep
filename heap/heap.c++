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

          int deleteFromHeap(){
               int answer = arr[1];
               // replace
               arr[1] = arr[size];
               // delete last element
               size--;

               int index = 1;
               while(index < size) {
                    int leftIndex = 2*index;
                    int rightIndex = 2*index + 1;

                    //find out 
                    int largestKaIndex = index;
                    if(leftIndex <= size && arr[largestKaIndex]< arr[leftIndex]){
                         largestKaIndex = leftIndex;
                    }
                    if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]){
                         largestKaIndex = rightIndex;
                    }

                    if(index == largestKaIndex){
                         break;
                    }else {
                         swap(arr[index], arr[largestKaIndex]);
                         index = largestKaIndex;
                    }
               }
               return answer;
          }
};

void heapify(int *arr, int n, int index){
     int leftIndex = 2*index;
     int rightIndex = 2*index + 1;
     int largestKaIndex = index;

     if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
          largestKaIndex = leftIndex;
     }

     if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
          largestKaIndex = rightIndex;
     }

     if(index != largestKaIndex){
          swap(arr[index], arr[largestKaIndex]);
          index = largestKaIndex;
          heapify(arr, n, index);
     }
}

int main() {
     Heap h(20);
     h.insert(10);
     h.insert(20);
     h.insert(5);
     h.insert(11);
     h.insert(6);

     cout << "Printing the content of heap: " << endl;
     h.printHeap();
     cout << endl;
     int ans = h.deleteFromHeap();
     cout << "Answer: " << ans << endl;

     cout << "Printing the content of heap: " << endl;
     h.printHeap();

     return 0;
}