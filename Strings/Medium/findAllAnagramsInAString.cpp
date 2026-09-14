#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

vector<int> findAnagrams(string s, string p){
vector<int>ans;

int n = s.size();
int k = p.size();

 //if p is longer than s -> impossible
        if (k > n) return ans;

        //frequency arrays
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        //step 1: fill freq of P
        for (char c : p) {
            freqP[c - 'a']++;
        }
        
        //step 2: build first window in s
        for (int i = 0; i < k; i++){
            freqS[s[i] - 'a']++;
        }
          //step3: check first window
        if (freqP == freqS){
            ans.push_back(0);
        }
        
        //step 4: slide the window
        for (int i = k; i < n; i++){
            //add new char
            freqS[s[i] - 'a']++;
            freqS[s[i - k] - 'a']--;

            //chck if window matches
            if(freqP == freqS){
                ans.push_back( i - k + 1);
            }
        }
        return ans;
}

};