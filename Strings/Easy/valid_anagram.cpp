//ANAGRAM : two strings are anagram if:
//          they contain same characters
//          with the same frequency
//          but possibly in different order.


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


//method 1: sorting  : TC - O(nlogn), SC- O(1)
class Solution {
public:

bool isAnagram(string s, string t){
    if(s.length() != t.length()){
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}
};