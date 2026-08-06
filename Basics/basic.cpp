// #include <iostream>

// int main() {

//     std :: cout << "Hello World" << "\n";
//     std :: cout << "How r u all ?" << std :: endl << "Hey wassup?"; 
//     return 0;
// }


#include<iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x  >> y;
    cout << "Value of x : " << x << "and y :" << y;
    return 0;
}


//instead of writing #include <...> for every library we can simply one time write

#include <bits/stdc++.h>

//this will include all libraries in C++ then there is no need to write #include<...> for everything

int main () {
    //int - 4 bytes
    int x  = 20;

    //long
    long q = 15;
    cin >> q;

    long long p = 150000000;

    //float, double
    float a = 5.6;
    float y = 5;
    cout << "Value of y: " << y;

    //string nd getline
    string str;
    getline(cin, str);
    cout << str;

    return 0;
}