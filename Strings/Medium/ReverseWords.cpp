#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
    
//     vector<string> words;
//     string word = "";

//     //step 1: extract words (ignore extra spaces)
//     for (int i = 0; i < s.length(); i++){
//         if (s[i] != ' '){
//             word+= s[i];
//         }
//         else if (!word.empty()) {
//             words.push_back(word);
//             word = "";
//         }
//     }
//     //add last word
//     if (!word.empty()) {
//         words.push_back(word);
//     }
//     //step 2: reverse word order
//     reverse (words.begin(), words.end());
//     //step 3: join with single space
//     string result = "";

//     for (int i =0; i < word.size(); i++){
//         result += words[i];
//         if ( i != words.size() - 1) {
//             result += " ";
//         }
//     }
//       return result;
//     }
  
// };

class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        vector<string> words;
        string word;

        // Extract words (automatically skips extra spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse words
        reverse(words.begin(), words.end());

        // Join words with single space
        string result = "";

        for (int i = 0; i < words.size(); i++) {

            result += words[i];

            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};