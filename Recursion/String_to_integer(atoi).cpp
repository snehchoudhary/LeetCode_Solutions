# include<iostream>
#include<climits>
using namespace std;

//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

//The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//Return the integer as the final result.



//BRUTE FORCE APPROACH : in-built library stoi() which do all tasks assigned in problem by itself but this approach is not acceptable in interviews they ask to implement this manually

//BRUTE FORCE APPROACH     TC: O(n)       and     SC: O(1)

class Solution {
public:
    int myAtoi(string s) {

        try {

            int ans = stoi(s);

            return ans;

        }
        catch(out_of_range&) {


            int i = 0;


            // skip spaces
            while(i < s.size() && s[i]==' ')
                i++;


            // check sign after spaces
            if(i < s.size() && s[i]=='-')
                return INT_MIN;

            else
                return INT_MAX;
        }


        catch(...) {

            return 0;
        }
    }
};



//OPTIMAL APPROACH FOR INTERVIEW :
class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();


        // remove spaces
        while(i < n && s[i] == ' ')
            i++;


        int sign = 1;


        // sign check
        if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+'){
            i++;
        }


        long ans = 0;


        while(i < n && isdigit(s[i])){

            int digit = s[i]-'0';


            // overflow check BEFORE multiplying
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)){

                if(sign == 1)
                    return INT_MAX;

                else
                    return INT_MIN;
            }


            ans = ans*10 + digit;

            i++;
        }


        return ans*sign;
    }
};