#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int getMinDiff(vector<int>& arr, int n, int k) {
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Initialize result with the current difference
    int result = arr[n - 1] - arr[0];

    // Step 3: Consider the case where we increase the smallest and decrease the largest
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    for (int i = 1; i < n; i++) {
        // Minimum possible height after modification
        int min_height = min(smallest, arr[i] - k);
        // Maximum possible height after modification
        int max_height = max(largest, arr[i - 1] + k);

        // Skip if min_height becomes negative
        if (min_height < 0) continue;

        // Update the result if the new difference is smaller
        result = min(result, max_height - min_height);
    }

    return result;
}

int main() {
    // Example 1
    vector<int> arr1 = {2, 4, 8, 10};
    int k1 = 2;
    cout << "Minimum difference: " << getMinDiff(arr1, arr1.size(), k1) << endl;

    // // Example 2
    // vector<int> arr2 = {3, 9, 12, 16, 20};
    // int k2 = 3;
    // cout << "Minimum difference: " << getMinDiff(arr2, arr2.size(), k2) << endl;

    return 0;
}
