#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int minCost(int k, vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, INT_MAX);  // dp[i] will store the minimum cost to reach stone i
    dp[0] = 0;  // cost to reach the first stone is 0

    // Loop over each stone
    for (int i = 0; i < n; i++) {
        // Try to jump to stones in range (i+1 to i+k)
        for (int j = 1; j <= k && (i + j) < n; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(arr[i] - arr[i + j]));
        }
    }

    // Return the minimum cost to reach the last stone
    return dp[n - 1];
}

int main() {
    int k1 = 3;
    vector<int> arr1 = {10, 30, 40, 50, 20};
    cout << "Minimum cost for arr1: " << minCost(k1, arr1) << endl; // Output: 30

    int k2 = 1;
    vector<int> arr2 = {10, 20, 10};
    cout << "Minimum cost for arr2: " << minCost(k2, arr2) << endl; // Output: 20

    return 0;
}
