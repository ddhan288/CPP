#include <iostream>
#include <bits/stdc++.h>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices of elements in the current window
    vector<int> result; // stores the max for each window

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements from back of deque if they are smaller than current element
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add the current element index to the deque
        dq.push_back(i);

        // Start adding results when the first window is formed (i >= k - 1)
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum of each subarray of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
