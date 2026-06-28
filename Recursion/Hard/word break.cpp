#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    bool solve(int index, string &s, 
               unordered_set<string> &dict) {


        // reached end
        if(index == s.size())
            return true;



        // try every possible partition

        for(int i = index; i < s.size(); i++){


            // create substring
            string word = s.substr(index, i-index+1);



            // if word exists in dictionary
            if(dict.find(word) != dict.end()){


                // solve remaining string

                if(solve(i+1, s, dict))
                    return true;

            }

        }


        return false;
    }



    bool wordBreak(string s, vector<string>& wordDict) {


        unordered_set<string> dict;


        for(auto word : wordDict)
            dict.insert(word);



        return solve(0, s, dict);

    }
};