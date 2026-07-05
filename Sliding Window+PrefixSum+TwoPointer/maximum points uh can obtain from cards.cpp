#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int leftSum = 0;

        // take all from left initially
        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int maxSum = leftSum;

        int rightSum = 0;
        int rightIndex = n - 1;

        for(int i = k - 1; i >= 0; i--) {

            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};