#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    // Base case
    if (start >= end)
        return;

    // Swap
    swap(arr[start], arr[end]);

    // Recursive call
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, 0, n - 1);

    // Print reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}