#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : arr){
            if (price < minPrice){
                minPrice = price;
            }
            else {
                int profit = price - minPrice;
                if (profit > maxProfit){
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};

//T.C : loop runs once for each element
//S.C : use of few variables only