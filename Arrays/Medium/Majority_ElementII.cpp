//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include<iostream>
#include<Vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        //step 1: find potential candidates
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0){
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0){
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        //step 2: verify counts
        count1 = count2 = 0;
        for (int num : nums){
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        //step 3: collect results
        vector <int> result;
        if (count1 > n/3) result.push_back(candidate1);
        if (count2 > n/3) result.push_back(candidate2);

        return result;
    }
};


//why using 2 candidates ? bcoz for n/3 we need there can be max of 2 such elements . e.g n = 6 so, n/3 = 2 need frequency > 2. 
//two elements can be [1, 1, ,1 ,2, 2, 2] both appear 3 times but 3 elements cannot exists: [1, ,1 ,2, ,2 ,3 ,3] : frequency of each = 2 , not greater than n/3. so, we keep 2 candidates


//why reset count 1 and count 2 = 0 ?
//because the first loop does not calculate the real frequency. It only finds possible candidates.The counts from the first loop are voting balances, not actual occurrences.