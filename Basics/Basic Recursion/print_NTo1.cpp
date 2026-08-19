#include<iostream>
using namespace std;

void func (int n, int i){
    //base case
    if (n < i) return;

    cout << n << endl;
    func(n - 1, i);
}

int main () {
    int n;
    cin >> n;

    func(n, 1);
    return 0;
}