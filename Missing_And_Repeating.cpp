#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeatingNumber = 0, missingNumber = 0;

        long long sumN = n * (n + 1) / 2;
        long long sumNSquare = n * (n + 1) * (2 * n + 1) / 6;

        long long sum = 0, sumSquare = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            sumSquare += (long long)arr[i] * arr[i];
        }

        long long diff = sumN - sum;
        long long sumDiff = sumNSquare - sumSquare;

        long long sumOfNumbers = sumDiff / diff;

        missingNumber = (diff + sumOfNumbers) / 2;
        repeatingNumber = sumOfNumbers - missingNumber;

        return {repeatingNumber, missingNumber};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
