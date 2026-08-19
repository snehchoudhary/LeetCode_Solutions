#include<iostream>
using namespace std;

void func (int i, int N){
    //base case

    if (i > N) return;

    cout << i << endl;
    func ( i + 1, N);   // recursive call


}

int main () {
    int N;
    cin >> N;

    func(1, N);
    return 0;
}