#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;

            swap(arr[i], arr[j]);
        }
    }

    // Put pivot at its correct position
    i++;
    swap(arr[i], arr[high]);

    return i;
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {

        // Find pivot's correct position
        int pIndex = partition(arr, low, high);

        // Sort left side of pivot
        quickSort(arr, low, pIndex - 1);

        // Sort right side of pivot
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {

    int arr[] = {5, 2, 4, 1, 3};
    int n = 5;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}