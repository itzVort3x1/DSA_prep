//------------------------------------
//      Sum of two arrays
//      Ex: INPUT: arr1={1,2,3,4} arr2={6}
//          OUTPUT: 1240
//          EXPLANATION: 1234
//                      +   6
//                      -----
//                       1240
//                      -----
//------------------------------------

#include<iostream>
#include<vector>

using namespace std;

vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;

    while(s<e){
        swap(v[s++], v[e--]);
    }
    return v;
}

void printArr(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<"The sum of the array is: "<<v[i];
    }
}

int main(){
    vector<int> arr1 = {1,2,3,4};
    vector<int> arr2 = {6};

    vector<int> ans;
    int i = arr1.size()-1;
    int j = arr2.size()-1;

    int carry = 0;
    while(i>=0 && j>=0){
        int val1 = arr1[i];
        int val2 = arr2[j];
        int sum = val1 + val2 + carry;
        ans.push_back(sum);
        carry = sum/10;
        sum = sum%10;
        i--;
        j--;
    }

    while(i>=0){
        int sum = arr1[i] + carry;
        ans.push_back(sum);
        carry = sum/10;
        sum = sum%10;
        i--;
    }

    while(j>=0){
        int sum = arr2[j] + carry;
        ans.push_back(sum);
        carry = sum/10;
        sum = sum%10;
        j--;
    }

    while(carry!=0){
        int sum = arr2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    printArr(reverse(ans));
}