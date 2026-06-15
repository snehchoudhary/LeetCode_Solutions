#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //method 2: frequency count : Time complexity : 0(n)

        if (s.length() != t.length()){
            return false;
        }

        int count [26] = {0};

        for (char c: s){
            count[c - 'a']++;
        }
        for (char c: t) {
            count[c - 'a']--;
        }
        for (int i = 0; i< 26; i++){
            if (count [i] != 0){
                return false;
            }
        }
        return true;
    }
};