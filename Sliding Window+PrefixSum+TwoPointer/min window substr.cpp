#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

//brute force approach : TC O(n^3)

class Solution {
public:
    
    bool isValid(string &sub, string &t) {
        
        vector<int> freq(128, 0);

        // count characters in sub
        for(char c : sub)
            freq[c]++;

        // check if t is satisfied
        for(char c : t) {
            freq[c]--;
            if(freq[c] < 0)
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        int n = s.size();
        string ans = "";
        int minLen = INT_MAX;

        for(int i = 0; i < n; i++) {

            string sub = "";

            for(int j = i; j < n; j++) {

                sub += s[j];

                if(isValid(sub, t)) {

                    if(j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        ans = sub;
                    }
                }
            }
        }

        return ans;
    }
};

//optimal approach :
class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int>freq(128, 0);

       //store freq of t
        for (char c : t)
           freq[c]++;

           int left = 0;
           int right = 0;
           int matched = 0;
           int startIndex = 0;
           int minLen = INT_MAX;

           //include right character
           while (right <s.size()){
            if (freq[s[right]] > 0)
              matched++;

              freq[s[right]]--;
              right++;


              //shrink window
              while (matched == t.size()){
                //update answer
                if (right - left < minLen){
                    minLen = right - left;
                    startIndex = left;
                }
                freq[s[left]]++;

                if (freq[s[left]] > 0)
                  matched--;

                  left++;
              }
           }
           if (minLen == INT_MAX)
            return "";

            return s.substr(startIndex, minLen);
    }
};