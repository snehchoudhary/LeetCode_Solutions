//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:

    vector<vector<int>>generate(int numRows){
    vector<vector<int>>pascal(numRows);

    //build triangle row by row
    for (int i = 0; i < numRows; i++){
        pascal[i].resize(i+1);                //assigning the size of pascal triangle
        pascal[i][0] = pascal[i][i] = 1;     //set first and last elements as 1

        for (int j = 1; j < i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];  //formula for sum of above 2 elements
        }
    }
    return pascal;
    }
};