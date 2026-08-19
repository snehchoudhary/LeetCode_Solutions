#include <iostream>
using namespace std;

  int solveUsingRecursion(int n){
     //base case
        if(n==0 || n==1){
            return n;
        }
        //recursive relation
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }

    int main() {
        int n;
        cin >> n;
        cout << solveUsingRecursion(n);
        return 0;
    }