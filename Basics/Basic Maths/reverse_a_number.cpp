// if a no has trolling zeros, then its reverse will not include them. for eg reverse if 10400 will be 401 isntead of 00401

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int revNum = 0;

    while (n > 0) {
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    cout << revNum;
}

