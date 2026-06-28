#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void solve(int index, string digits, string &ds, vector<string>&ans, vector<string>& mapping) {

        if (index == digits.size()){
            ans.push_back(ds);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mapping[digit];

        for(char ch : letters){
            ds.push_back(ch);

            solve(index + 1, digits, ds, ans, mapping);

            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if (digits.empty()) return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string ds;

        solve(0, digits, ds, ans, mapping);

        return ans;
    }
};

// This is a very important line in this problem. Let’s break it properly and clearly.

// int digit = digits[index] - '0';
// string letters = mapping[digit];
// 1. digits[index] is a CHARACTER, not a number

// Example:

// digits = "23"

// So:

// index	value
// 0	'2'
// 1	'3'

// So:

// digits[0] = '2'   // character

// NOT integer 2.

// 2. Why subtract '0'?

// We do:

// int digit = digits[index] - '0';

// Because ASCII values:

// char	ASCII
// '0'	48
// '1'	49
// '2'	50
// '3'	51

// So:

// '2' - '0'
// = 50 - 48
// = 2

// Similarly:

// '3' - '0' = 3
// 👉 Meaning of this line:
// int digit = digits[index] - '0';

// ✔ converts character → integer

// Example:

// '2' → 2
// '3' → 3
// 3. Now mapping array

// We have:

// vector<string> mapping = {
//  "", "", "abc", "def",
//  "ghi", "jkl", "mno",
//  "pqrs", "tuv", "wxyz"
// };

// Index meaning:

// digit	letters
// 2	abc
// 3	def
// 4	ghi

// So:

// mapping[2] = "abc"
// mapping[3] = "def"
// 4. This line:
// string letters = mapping[digit];

// means:

// 👉 “get all characters that belong to this digit”

// Example:

// If:

// digits[index] = '2'

// Then:

// digit = 2
// letters = mapping[2] = "abc"
// 5. Full flow example

// Input:

// digits = "23"
// Step 1:
// digits[0] = '2'
// digit = '2' - '0' = 2
// letters = "abc"
// Step 2:
// digits[1] = '3'
// digit = '3' - '0' = 3
// letters = "def"
// 6. Simple intuition

// Think like this:

// digit character → convert to number → use as index → get letters

// Flow:

// '2' → 2 → mapping[2] → "abc"
// '3' → 3 → mapping[3] → "def"
// 7. One-line summary
// int digit = digits[index] - '0';

// 👉 converts char digit into integer

// string letters = mapping[digit];

// 👉 fetches corresponding letters from keypad mapping