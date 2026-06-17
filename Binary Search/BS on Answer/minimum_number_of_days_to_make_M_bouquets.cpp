#include <iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;     // consecutive flowers
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                count++;

                // k flowers completed
                if(count == k) {
                    bouquets++;
                    count = 0; // reset after making bouquet
                }
            }
            else {
                count = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        long long total = 1LL * m * k;

        // impossible case
        if(total > bloomDay.size())
            return -1;


        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1; // try minimum days
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};