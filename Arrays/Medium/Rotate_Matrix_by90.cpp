//transpose of a matrix
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose
        for(int i=0; i<n; i++){
            for (int j=i; j<matrix[i].size(); j++){
                swap (matrix[i][j], matrix[j][i]);
            }
        }
        //2D matrix ki saari rows ko reverse kr do
        //no of rows n=0 to n-1
        for(int i=0; i<n; i++){
            //C++ utility for reverse
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};