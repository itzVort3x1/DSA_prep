#include<iostream>

using namespace std;

int main(){
    int arr[10] = {23,122,41,67};

    /*
    cout << "address of first memory block is -> " <<arr<< endl;
    cout<<arr[0]<<endl;
    cout << "address of first memory block is -> " <<&arr[0]<< endl;

    cout<<"4th -> "<<*arr<<endl;
    cout<<"5th -> "<<*arr + 1<<endl;
    cout<<"6th -> "<<*(arr + 1)<<endl;
    cout<<"7th -> "<<*(arr) + 1<<endl;
    cout<<"8th -> "<<arr[2]<<endl;
    cout<<"9th -> "<<*(arr+2)<<endl;

    // arr[i] = *(arr+i)
    // i[arr] = *(i+arr)
    // both of the above representations of an array are correct and will not result in an error

    int i=3;
    cout<<i[arr]<<endl;

    int temp[10] = {1,2};
    cout<<sizeof(temp)<<endl;
    cout<<" 1st -> "<<sizeof(*temp)<<endl;
    cout<<" 2nd -> "<<sizeof(&temp)<<endl;

    int *ptr = &temp[10];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;
    */

    int a[20] = {1,2,3,4,5,6,7};
    cout<<"1st-> "<<&a[0]<<endl;
    cout<<"2nd-> "<<&a<<endl;
    cout<<"3RD-> "<<a<<endl;

    int *p = &a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;

    return 0;
}