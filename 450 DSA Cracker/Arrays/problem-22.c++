//------------------------------------
//      Majority Element II
//      Link: https://leetcode.com/problems/majority-element-ii/description/
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 2, 3};

    int n = nums.size();

    int count1 = 0;
    int count2 = 0;
    int cand1 = NULL;
    int cand2 = NULL;

    for(int num: nums){
        if(cand1 == num){
            count1++;
        }else if(cand2 == num){
            count2++;
        }else if(count1 == 0){
            cand1 = num;
            count1++;
        }else if(count2 == 0){
            cand2 = num;
            count2++;
        }else {
            count1 -= 1;
            count2 -= 1;
        }
    }

    count1 = 0;
    count2 = 0;

    for(int num: nums){
        if(num == cand1){
            count1++;
        }
        if(num == cand2){
            count2++;
        }
    }

    cout << "The majority elements are: ";

    if(count1 > n/3){
        cout << cand1;
    }

    if(count2 > n/3){
        cout << ", " << cand2;
    }

    cout << endl;
    return 0;
}