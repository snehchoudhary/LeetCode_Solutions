#include <iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:

    bool canWePlace(vector<int> &stalls, int dist, int cows){

        int countCows = 1;
        int last = stalls[0];

        for(int i = 1; i < stalls.size(); i++){

            if(stalls[i] - last >= dist){
                countCows++;
                last = stalls[i];
            }

            if(countCows >= cows)
                return true;
        }

        return false;
    }


    int aggressiveCows(vector<int> &nums, int k){

        sort(nums.begin(), nums.end());

        int low = 1;
        int high = nums[nums.size()-1] - nums[0];

        int ans = 0;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(canWePlace(nums, mid, k)){

                ans = mid;       // possible answer
                low = mid + 1;   // try bigger distance

            }
            else{

                high = mid - 1;

            }
        }

        return ans;
    }
};