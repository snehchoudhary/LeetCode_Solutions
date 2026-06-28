#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    bool dfs(int row, int col, int index,
             vector<vector<char>>& board,
             string& word,
             vector<vector<int>>& visited) {


        // word completely matched
        if(index == word.size())
            return true;


        int n = board.size();
        int m = board[0].size();


        // boundary check
        if(row < 0 || col < 0 || 
           row >= n || col >= m)
            return false;


        // already visited
        if(visited[row][col])
            return false;


        // character mismatch
        if(board[row][col] != word[index])
            return false;



        // choose this cell
        visited[row][col] = 1;



        // explore all 4 directions

        bool up = dfs(row-1, col, index+1,
                      board, word, visited);

        bool down = dfs(row+1, col, index+1,
                        board, word, visited);

        bool left = dfs(row, col-1, index+1,
                        board, word, visited);

        bool right = dfs(row, col+1, index+1,
                         board, word, visited);



        // backtrack
        visited[row][col] = 0;


        return up || down || left || right;

    }



    bool exist(vector<vector<char>>& board, string word) {


        int n = board.size();
        int m = board[0].size();


        vector<vector<int>> visited(n, vector<int>(m,0));



        // try every starting cell

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){


                if(dfs(i,j,0,board,word,visited))
                    return true;

            }

        }


        return false;
    }
};