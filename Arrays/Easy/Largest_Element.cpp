//nums = [3, 3, 6, 1]
//largest element is 6

#include <iostream>
#include<vector>
using namespace std;

int largestElement(vector<int>&nums) {
    int max = nums[0];

    for (int i = 0; i < nums.size(); i++){
        if (nums[i] > max){
            max = nums[i];
        }
    }
    return max;
}

int main() {
    vector<int> nums = {3, 3, 6, 1};

    int result = largestElement(nums);

    cout << "Largest element: " << result << endl;

    return 0;

}