#include<iostream>
using namespace std;

int func(int n) {
    //base case
    if (n == 0) return 1;

    return n * func(n - 1);
}

int main () {
    int n;
    cin >> n;

    cout << func(n) << endl;
    return 0;
}