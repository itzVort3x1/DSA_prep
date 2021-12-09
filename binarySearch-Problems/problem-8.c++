//------------------------------------
//      Book allocation problem
//      Ex: INPUT: arr = {10,20,30,40}, m=2
//          OUTPUT: 60
//          EXPLANATION: All possible way to allocate the ‘4’ books in ‘2’ number of students is -

//                      10 | 20, 30, 40 - sum of all the pages of books which allocated to student-1 is ‘10’, and student-2 is ‘20+ 30+ 40 = 90’ 
//                      so maximum is ‘max(10, 90)= 90’.

//                      10, 20 | 30, 40 - sum of all the pages of books which allocated to student-1 is ‘10+ 20 = 30’, and student-2 is ‘30+ 40 = 70’ 
//                      so maximum is ‘max(30, 70)= 70’.

//                      10, 20, 30 | 40 - sum of all the pages of books which allocated to student-1 is ‘10+ 20 +30 = 60’, and student-2 is ‘40’ 
//                      so maximum is ‘max(60, 40)= 60’.

//                      So possible maximum number of pages which allocated to a single student is { 90, 70, 60 }.
//                      But you have to return a minimum of this so return ‘min(90,70,60) =60’.
//------------------------------------

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum +=arr[i];
        }else {
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int main(){
    int arr[4] = {10,20,30,40};
    int s = 0;
    int sum = 0;

    for(int i = 0; i<4; i++){
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(isPossible(arr, 4, 2, mid)){
            ans = mid;
            s = mid - 1;
        }else {
            e = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    cout<<"The max page allocation is: "<<ans<<endl;

    return 0;
}