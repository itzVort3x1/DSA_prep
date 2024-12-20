//------------------------------------
//      Best Time to Buy and Sell Stock 
//      Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//------------------------------------

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    int min_price = INT_MAX;
    int max_profit = 0;

    for(int price: prices){
        if(price < min_price){
            min_price = price;
        }

        int profit = price - min_price;

        if(profit > max_profit){
            max_profit = profit;
        }
    }

    cout << "The max profit is: " << max_profit << endl;

    return 0;
}