#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//brute force
//TC : O(n^2)



//Idea

// Start from every index.

// For every starting index,

// go right until more than 2 fruit types appear.

// Keep track of the maximum length.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        int ans = 0;

        for(int i=0;i<n;i++){

            unordered_map<int,int> mp;

            for(int j=i;j<n;j++){

                mp[fruits[j]]++;

                if(mp.size()>2)
                    break;

                ans=max(ans,j-i+1);
            }
        }

        return ans;
    }
};


//better approach : sliding window
//TC : O(N)



// Algorithm

// For every right

// add fruit

// If map size > 2

// keep removing left

// until map size ≤ 2

// Update answer.

class Solution {
public:
    int totalFruits(vector<int>& fruits) {

        unordered_map<int,int> mp;

        int left=0;
        int ans=0;

        for(int right=0;right<fruits.size();right++){

            mp[fruits[right]]++;

            while(mp.size()>2){

                mp[fruits[left]]--;

                if(mp[fruits[left]]==0)
                    mp.erase(fruits[left]);

                left++;
            }

            ans=max(ans,right-left+1);
        }

        return ans;
    }
};
