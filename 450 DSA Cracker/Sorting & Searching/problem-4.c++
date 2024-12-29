//------------------------------------
//      First and Last Occurrences
//      Link: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

void firstOcc(vector<int> arr, int x, vector<int> &result){
    int i = 0;
    int j = arr.size() -1;
    int mid = i + (j - i)/2;

    int res = -1;

    while(i <= j){
        if(arr[mid] == x){
            res = mid;
            j = mid - 1;
        }else if (arr[mid] < x){
            i = mid + 1;
        }else {
            j = mid - 1;
        }
        mid = i + (j -i)/2;
    }

    result.push_back(res);
    return;
}

void lastOcc(vector<int> arr, int x, vector<int> &result){
    int i = 0;
    int j = arr.size() -1;
    int mid = i + (j - i)/2;

    int res = -1;

    while(i <= j){
        if(arr[mid] == x){
            res = mid;
            i = mid + 1;
        }else if (arr[mid] > x){
            j = mid - 1;
        }else {
            i = mid + 1;
        }
        mid = i + (j -i)/2;
    }

    result.push_back(res);
    return;
}

int main() {
    vector<int> arr = {1,3,5,5,5,5,67,123,125};
    int x = 5;

    vector<int> result;

    firstOcc(arr, x, result);
    lastOcc(arr, x, result);

    for(int x:result){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}