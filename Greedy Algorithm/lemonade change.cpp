#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0; 
        int ten = 0;

        for (int i = 0; i < bills.size(); i++){
            if (bills[i] == 5) {
                five = five +1;
            }
            else if (bills[i] == 10){
                if (five > 0) {
                  five -= 1;
                  ten += 1;
                }
                else {
                    return false;
                }
            }
            else   // 20
            {
                if (ten > 0 && five > 0) {
                    ten = ten -1;
                    five = five -1;
                }
                //otherwise give 3 5s
                else if (five >= 3) {
                  five -= 3;
                }
                else 
                return false;
            }
        }
        return true;
    }
};