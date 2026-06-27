#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//PRINT ALL SUBSEQUENCES WHOSE SUM = K

void printS(int index, vector<int>&ds, int s, int sum, int arr[], int n) {
    if (index == n){
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return ;
    }
    ds.push_back(arr[index]);
    s += arr[index];

    printS(index+1, ds, s, sum, arr, n);

    s-= arr[index];
    ds.pop_back();

    //not pick
    printS(index + 1, ds, s, sum, arr, n);
}



// Print any 1 subsequence

bool any1Subsquence(int index, vector<int>&ds, int s, int sum, int arr[], int n) {
    if (index == n){

        //condition satisfied
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        //condition not satisfied
        else return false;
    }
    ds.push_back(arr[index]);
    s += arr[index];

    if(any1Subsquence(index+1, ds, s, sum, arr, n) == true){
        return true;
    }

    s-= arr[index];
    ds.pop_back();

    //not pick
    if(any1Subsquence(index + 1, ds, s, sum, arr, n) == true)  return true; 

    return false;
}


//COUNT NUMBER OF SUBSEQUENCE

int countSubsequence(int index, int s, int sum, int arr[], int n) {
    if (index == n){

        //condition satisfied
        if (s == sum) return 1;
        //condition not satisfied
        else return 0;
    }
    
    s += arr[index];

    int left = countSubsequence(index + 1, s, sum, arr, n);


    s-= arr[index];
    

    //not pick
    int right = countSubsequence(index + 1, s, sum, arr, n);

    return left + right;
}

int main() {
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
     vector<int>ds;
     printS(0, ds, 0, sum, arr, n);
}