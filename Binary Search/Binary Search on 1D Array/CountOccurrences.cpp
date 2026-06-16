#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        // Your code goes here
         int start = 0, end = arr.size()-1;
        int first = -1, last = -1;

        // first occurrence
        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

         // target not found
         if(first == -1)
           return 0;


        start = 0;
        end = arr.size()-1;

        // last occurrence
        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] == target){
                last = mid;
                start = mid + 1;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return last - first + 1;
    }
};