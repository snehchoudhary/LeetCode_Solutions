#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted parts
void merge(int arr[], int low, int mid, int high) {

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Compare elements from both halves
    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If elements are remaining in left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If elements are remaining in right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Function to divide the array
void mergeSort(int arr[], int low, int high) {

    // Base case
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both sorted halves
    merge(arr, low, mid, high);
}

int main() {

    int arr[] = {5, 2, 4, 1, 3};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
