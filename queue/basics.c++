#include<iostream>
using namespace std;

class Queue {

     int* arr;
     int front;
     int rear;
     int size;

public:
    Queue() {
        // Implement the Constructor
          size = 100001;
          arr = new int[size];
          front = 0;
          rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(front == rear){
          cout << "Queue is empty" << endl;
        }else {
          cout << "Queue is not empty"<< endl;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size){
          cout << "Queue is full" << endl;
        }else {
          arr[rear] = data;
          rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(front == rear){
          cout << "Queue is empty" << endl;
        }else {
          int ans = arr[front];
          arr[front] = -1;
          front++;
          if(front == rear){
               front = 0;
               rear = 0;
          }
          cout << "The remove element is: " << ans <<endl;
        }
    }

    int front() {
        // Implement the front() function
        if(front == rear){
          cout << "The queue is empty" << endl;
        }else {
          return arr[front];
        }
    }
};