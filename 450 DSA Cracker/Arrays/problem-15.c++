//------------------------------------
//      Alternate Positive Negative
//      Link: https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {9,4,-2,-1,5,0,-5,-3,2};

    vector<int> positive;
    vector<int> negative;
    
    for(int num:arr){
        if(num < 0){
            negative.push_back(num);
        }else {
            positive.push_back(num);
        }
    }
    
    vector<int> temp;
    int i = 0;
    int j = 0;
    while(i < positive.size() && j < negative.size()){
        temp.push_back(positive[i++]);
        temp.push_back(negative[j++]);
    }
    
    while(i < positive.size()){
        temp.push_back(positive[i++]);
    }
    
    while(j < negative.size()){
        temp.push_back(negative[j++]);
    }

    cout << "The alternating array is: ";
    for(int num:temp){
        cout << num << ", ";
    }
    cout << endl;

    return 0;
        
}